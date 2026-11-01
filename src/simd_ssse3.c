/**
 * @file simd_ssse3.c
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief 16-byte SIMD UTF-8 validation and counting (SSSE3 baseline).
 *
 * The same Keiser-Lemire "lookup" algorithm as the AVX2 kernel, but on
 * 16-byte vectors. This is the lower, more widely available SIMD tier: it needs
 * only SSSE3 (PSHUFB), which every x86-64 CPU since ~2006 provides. Counting
 * deliberately avoids POPCNT (SSE4.2) so the tier runs on the full SSSE3
 * baseline.
 *
 * This translation unit must only be called when tinyuc_simd_tier() reports
 * TINYUC_SIMD_TIER_SSSE3 or higher.
 */

#include "private/simd.h"
#include "private/utf8_lookup_tables.h"

#include <stdint.h>
#include <string.h>
#include <tmmintrin.h>

static inline __m128i high_nibbles(__m128i v)
{
    return _mm_and_si128(_mm_srli_epi16(v, 4), _mm_set1_epi8(0x0F));
}

/// Sum the bytes of @p v (SSE2 PSADBW); each byte is 0x00 or 0xFF.
static inline unsigned sum_bytes(__m128i v)
{
    const __m128i sums = _mm_sad_epu8(v, _mm_setzero_si128());
    const uint64_t lo = (uint64_t)_mm_cvtsi128_si64(sums);
    const uint64_t hi = (uint64_t)_mm_cvtsi128_si64(_mm_srli_si128(sums, 8));
    return (unsigned)((lo + hi) / 255u);
}

static inline __m128i check_special_cases(__m128i input,
                                          __m128i prev1,
                                          __m128i t1h,
                                          __m128i t1l,
                                          __m128i t2h)
{
    const __m128i low_mask = _mm_set1_epi8(0x0F);
    const __m128i byte1_high = _mm_shuffle_epi8(t1h, high_nibbles(prev1));
    const __m128i byte1_low = _mm_shuffle_epi8(t1l, _mm_and_si128(prev1, low_mask));
    const __m128i byte2_high = _mm_shuffle_epi8(t2h, high_nibbles(input));
    return _mm_and_si128(_mm_and_si128(byte1_high, byte1_low), byte2_high);
}

static inline __m128i check_multibyte_lengths(__m128i prev2, __m128i prev3, __m128i sc)
{
    const __m128i is_third = _mm_subs_epu8(prev2, _mm_set1_epi8(0x60));  // 0xE0 - 0x80
    const __m128i is_fourth = _mm_subs_epu8(prev3, _mm_set1_epi8(0x70)); // 0xF0 - 0x80
    const __m128i must23 = _mm_or_si128(is_third, is_fourth);
    const __m128i must23_80 = _mm_and_si128(must23, _mm_set1_epi8((char)-128));
    return _mm_xor_si128(must23_80, sc);
}

static inline __m128i check_block(__m128i input,
                                  __m128i prev1,
                                  __m128i prev2,
                                  __m128i prev3,
                                  __m128i t1h,
                                  __m128i t1l,
                                  __m128i t2h)
{
    const __m128i sc = check_special_cases(input, prev1, t1h, t1l, t2h);
    return check_multibyte_lengths(prev2, prev3, sc);
}

/// True if every byte of @p v is zero (SSE2, no SSE4.1 ptest).
static inline int all_zero(__m128i v)
{
    return _mm_movemask_epi8(_mm_cmpeq_epi8(v, _mm_setzero_si128())) == 0xFFFF;
}

int tinyuc_utf8_ssse3_prefix(const unsigned char* buf, size_t len, size_t* tail_start)
{
    const __m128i t1h = _mm_loadu_si128((const __m128i*)tinyuc_utf8_tbl_byte1_high);
    const __m128i t1l = _mm_loadu_si128((const __m128i*)tinyuc_utf8_tbl_byte1_low);
    const __m128i t2h = _mm_loadu_si128((const __m128i*)tinyuc_utf8_tbl_byte2_high);

    // Leave at least one byte for the scalar tail so buf[n] is always readable.
    const size_t limit = len - 1;
    __m128i error = _mm_setzero_si128();
    size_t i = 0;

    // First block: bytes before the buffer behave like ASCII NUL.
    {
        uint8_t window[16 + 3];
        memset(window, 0, 3);
        memcpy(window + 3, buf, 16);
        const __m128i input = _mm_loadu_si128((const __m128i*)buf);
        const __m128i prev1 = _mm_loadu_si128((const __m128i*)(window + 2));
        const __m128i prev2 = _mm_loadu_si128((const __m128i*)(window + 1));
        const __m128i prev3 = _mm_loadu_si128((const __m128i*)(window + 0));
        error = check_block(input, prev1, prev2, prev3, t1h, t1l, t2h);
        i = 16;
    }

    for (; i + 16 <= limit; i += 16)
    {
        const __m128i input = _mm_loadu_si128((const __m128i*)(buf + i));
        const __m128i prev1 = _mm_loadu_si128((const __m128i*)(buf + i - 1));
        const __m128i prev2 = _mm_loadu_si128((const __m128i*)(buf + i - 2));
        const __m128i prev3 = _mm_loadu_si128((const __m128i*)(buf + i - 3));
        error = _mm_or_si128(error, check_block(input, prev1, prev2, prev3, t1h, t1l, t2h));
    }

    if (!all_zero(error))
        return 0;

    // Move back to a codepoint boundary so the scalar tail can restart cleanly.
    size_t start = i;
    while (start > 0 && (buf[start] & 0xC0u) == 0x80u)
        start--;
    *tail_start = start;
    return 1;
}

size_t tinyuc_utf8_count_ssse3(const char* str, size_t len)
{
    const unsigned char* buf = (const unsigned char*)str;
    const __m128i mask_c0 = _mm_set1_epi8((char)-64);
    const __m128i mask_80 = _mm_set1_epi8((char)-128);

    size_t count = 0;
    size_t i = 0;
    for (; i + 16 <= len; i += 16)
    {
        const __m128i block = _mm_loadu_si128((const __m128i*)(buf + i));
        const __m128i is_cont = _mm_cmpeq_epi8(_mm_and_si128(block, mask_c0), mask_80);
        count += 16u - (size_t)sum_bytes(is_cont);
    }
    for (; i < len; i++)
    {
        if ((buf[i] & 0xC0u) != 0x80u)
            count++;
    }
    return count;
}
