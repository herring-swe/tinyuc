/**
 * @file simd_avx2.c
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief AVX2 UTF-8 validation and counting.
 *
 * The validator is a 32-byte adaptation of the SIMD "lookup" algorithm by
 * Keiser and Lemire (as used by simdjson): a nibble lookup classifies each byte
 * pair against the UTF-8 transition rules and a second check verifies the
 * length of multibyte sequences. Only the bulk (full 32-byte blocks) is handled
 * here; the caller scalar-validates the tail so that cross-block state and
 * truncated trailing sequences are handled by the existing code.
 *
 * This translation unit is compiled with AVX2 enabled; it must only be called
 * when tinyuc_simd_tier() reports TINYUC_SIMD_TIER_AVX2 or higher.
 */

#include "private/simd.h"

#include <stdint.h>
#include <string.h>

#if defined(_MSC_VER)
#include <intrin.h>
#endif

#include "private/utf8_lookup_tables.h"

#include <immintrin.h>

static inline __m256i broadcast_table(const uint8_t* table)
{
    return _mm256_broadcastsi128_si256(_mm_loadu_si128((const __m128i*)table));
}

static inline __m256i high_nibbles(__m256i v)
{
    return _mm256_and_si256(_mm256_srli_epi16(v, 4), _mm256_set1_epi8(0x0F));
}

static inline unsigned popcount32(unsigned value)
{
#if defined(_MSC_VER)
    return (unsigned)__popcnt(value);
#else
    return (unsigned)__builtin_popcount(value);
#endif
}

/**
 * @brief Classify the current byte against the previous byte (special cases).
 * Returns a mask of possible error flags; zero means no error detected here.
 */
static inline __m256i check_special_cases(__m256i input,
                                          __m256i prev1,
                                          __m256i t1h,
                                          __m256i t1l,
                                          __m256i t2h)
{
    const __m256i low_mask = _mm256_set1_epi8(0x0F);
    const __m256i byte1_high = _mm256_shuffle_epi8(t1h, high_nibbles(prev1));
    const __m256i byte1_low = _mm256_shuffle_epi8(t1l, _mm256_and_si256(prev1, low_mask));
    const __m256i byte2_high = _mm256_shuffle_epi8(t2h, high_nibbles(input));
    return _mm256_and_si256(_mm256_and_si256(byte1_high, byte1_low), byte2_high);
}

/**
 * @brief Verify that the current byte is a continuation where a 3- or 4-byte
 * lead two or three bytes back requires one.
 */
static inline __m256i check_multibyte_lengths(__m256i prev2, __m256i prev3, __m256i sc)
{
    const __m256i is_third = _mm256_subs_epu8(prev2, _mm256_set1_epi8(0x60));  // 0xE0 - 0x80
    const __m256i is_fourth = _mm256_subs_epu8(prev3, _mm256_set1_epi8(0x70)); // 0xF0 - 0x80
    const __m256i must23 = _mm256_or_si256(is_third, is_fourth);
    const __m256i must23_80 = _mm256_and_si256(must23, _mm256_set1_epi8((char)-128));
    return _mm256_xor_si256(must23_80, sc);
}

/// Run the two checks for one 32-byte block and accumulate any error flags.
static inline __m256i check_block(__m256i input,
                                  __m256i prev1,
                                  __m256i prev2,
                                  __m256i prev3,
                                  __m256i t1h,
                                  __m256i t1l,
                                  __m256i t2h)
{
    const __m256i sc = check_special_cases(input, prev1, t1h, t1l, t2h);
    return check_multibyte_lengths(prev2, prev3, sc);
}

int tinyuc_utf8_avx2_prefix(const unsigned char* buf, size_t len, size_t* tail_start)
{
    const __m256i t1h = broadcast_table(tinyuc_utf8_tbl_byte1_high);
    const __m256i t1l = broadcast_table(tinyuc_utf8_tbl_byte1_low);
    const __m256i t2h = broadcast_table(tinyuc_utf8_tbl_byte2_high);

    // Leave at least one byte for the scalar tail so buf[n] is always readable.
    const size_t limit = len - 1;
    __m256i error = _mm256_setzero_si256();
    size_t i = 0;

    // First block: the bytes before the buffer behave like ASCII NUL, which
    // imposes no constraint on a leading codepoint.
    {
        uint8_t window[32 + 3];
        memset(window, 0, 3);
        memcpy(window + 3, buf, 32);
        const __m256i input = _mm256_loadu_si256((const __m256i*)buf);
        const __m256i prev1 = _mm256_loadu_si256((const __m256i*)(window + 2));
        const __m256i prev2 = _mm256_loadu_si256((const __m256i*)(window + 1));
        const __m256i prev3 = _mm256_loadu_si256((const __m256i*)(window + 0));
        error = check_block(input, prev1, prev2, prev3, t1h, t1l, t2h);
        i = 32;
    }

    for (; i + 32 <= limit; i += 32)
    {
        const __m256i input = _mm256_loadu_si256((const __m256i*)(buf + i));
        const __m256i prev1 = _mm256_loadu_si256((const __m256i*)(buf + i - 1));
        const __m256i prev2 = _mm256_loadu_si256((const __m256i*)(buf + i - 2));
        const __m256i prev3 = _mm256_loadu_si256((const __m256i*)(buf + i - 3));
        error = _mm256_or_si256(error, check_block(input, prev1, prev2, prev3, t1h, t1l, t2h));
    }

    // Error flags live in arbitrary bits of each byte, so test the whole vector
    // for any set bit rather than only the least-significant bit of each byte.
    if (!_mm256_testz_si256(error, error))
        return 0;

    // The SIMD region ends at i (a multiple of 32, <= len - 1). Move back to the
    // start of the codepoint that straddles i so the scalar tail begins on a
    // boundary and revalidates that codepoint from scratch.
    size_t start = i;
    while (start > 0 && (buf[start] & 0xC0u) == 0x80u)
        start--;
    *tail_start = start;
    return 1;
}

size_t tinyuc_utf8_count_avx2(const char* str, size_t len)
{
    const unsigned char* buf = (const unsigned char*)str;
    const __m256i mask_c0 = _mm256_set1_epi8((char)-64);
    const __m256i mask_80 = _mm256_set1_epi8((char)-128);

    size_t count = 0;
    size_t i = 0;
    for (; i + 32 <= len; i += 32)
    {
        const __m256i block = _mm256_loadu_si256((const __m256i*)(buf + i));
        const __m256i is_cont = _mm256_cmpeq_epi8(_mm256_and_si256(block, mask_c0), mask_80);
        const unsigned cont = (unsigned)_mm256_movemask_epi8(is_cont);
        count += 32u - (size_t)popcount32(cont);
    }
    for (; i < len; i++)
    {
        if ((buf[i] & 0xC0u) != 0x80u)
            count++;
    }
    return count;
}
