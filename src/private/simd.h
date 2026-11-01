/**
 * @file simd.h
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Internal declarations for the optional SIMD-accelerated UTF-8 paths.
 *
 * A build may compile one or more ISA tiers. @ref tinyuc_simd_tier() reports
 * the highest tier that both the CPU supports and the build provides; it is a
 * cached load plus a branch after the first call. Callers must fall back to the
 * portable implementation when it returns TINYUC_SIMD_TIER_NONE.
 */

#ifndef TINYUC_PRIVATE_SIMD_H
#define TINYUC_PRIVATE_SIMD_H

#include <stddef.h>

#if defined(TINYUC_SIMD_AVX2) || defined(TINYUC_SIMD_SSSE3)

#define TINYUC_SIMD_TIER_NONE 0
#define TINYUC_SIMD_TIER_SSSE3 1
#define TINYUC_SIMD_TIER_AVX2 2

/// Cached result of @ref tinyuc_simd_detect(); -1 until first use.
extern int tinyuc_simd_tier_cached;

/**
 * @brief Detect the best compiled-and-supported tier. Called at most once.
 */
int tinyuc_simd_detect(void);

/**
 * @brief Best usable SIMD tier, cached after the first call.
 */
static inline int tinyuc_simd_tier(void)
{
    int tier = tinyuc_simd_tier_cached;
    if (tier < 0)
        tier = tinyuc_simd_detect();
    return tier;
}

#endif // TINYUC_SIMD_AVX2 || TINYUC_SIMD_SSSE3

#if defined(TINYUC_SIMD_AVX2)

/**
 * @brief Validate the leading part of a buffer with AVX2.
 *
 * Validates up to the last complete 32-byte block and reports where the caller
 * should resume scalar validation. Never reads past @p buf + @p len.
 *
 * @param buf buffer to validate (must not be NULL)
 * @param len length in bytes; the caller must ensure len >= 64
 * @param tail_start receives a byte offset at or before the end of the
 *        SIMD-validated region where scalar validation can restart
 * @return 1 if the SIMD-validated region is valid, 0 if an error was found
 */
int tinyuc_utf8_avx2_prefix(const unsigned char* buf, size_t len, size_t* tail_start);

/**
 * @brief Count codepoints in a valid UTF-8 buffer with AVX2.
 */
size_t tinyuc_utf8_count_avx2(const char* str, size_t len);

#endif // TINYUC_SIMD_AVX2

#if defined(TINYUC_SIMD_SSSE3)

/**
 * @brief Validate the leading part of a buffer with a 16-byte SSSE3 kernel.
 *
 * Same contract as @ref tinyuc_utf8_avx2_prefix(); the caller must ensure
 * len >= 48.
 */
int tinyuc_utf8_ssse3_prefix(const unsigned char* buf, size_t len, size_t* tail_start);

/**
 * @brief Count codepoints in a valid UTF-8 buffer with a 16-byte SSSE3 kernel.
 */
size_t tinyuc_utf8_count_ssse3(const char* str, size_t len);

#endif // TINYUC_SIMD_SSSE3

#endif // TINYUC_PRIVATE_SIMD_H
