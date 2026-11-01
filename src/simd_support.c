/**
 * @file simd_support.c
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Runtime CPU feature detection for the optional SIMD paths.
 *
 * Compiled without any ISA extensions so it is safe on any CPU and safe to run
 * at any point after load. AVX2 detection also checks OS support (OSXSAVE and
 * XCR0), so an AUTO build never calls AVX2 code on an OS that does not save the
 * extended state.
 */

#include "private/simd.h"

#if defined(TINYUC_SIMD_AVX2) || defined(TINYUC_SIMD_SSSE3)

int tinyuc_simd_tier_cached = -1;

#if defined(_MSC_VER)

#include <immintrin.h>
#include <intrin.h>

static int tinyuc_detect_hw(void)
{
    int regs[4];
    __cpuid(regs, 0);
    const int max_leaf = regs[0];

    __cpuid(regs, 1);
    const int ecx = regs[2];
    const int osxsave = (ecx >> 27) & 1;
    const int avx = (ecx >> 28) & 1;

    int tier = (ecx & (1 << 9)) ? TINYUC_SIMD_TIER_SSSE3 : TINYUC_SIMD_TIER_NONE;

    // AVX2 requires the OS to save YMM state (OSXSAVE + XCR0.SSE|AVX).
    if (avx && osxsave && max_leaf >= 7)
    {
        const unsigned long long xcr0 = _xgetbv(0);
        if ((xcr0 & 0x6) == 0x6)
        {
            __cpuidex(regs, 7, 0);
            if (regs[1] & (1 << 5)) // CPUID.7.0:EBX.AVX2
                tier = TINYUC_SIMD_TIER_AVX2;
        }
    }
    return tier;
}

#elif defined(__GNUC__) || defined(__clang__)

static int tinyuc_detect_hw(void)
{
    __builtin_cpu_init();
    if (__builtin_cpu_supports("avx2"))
        return TINYUC_SIMD_TIER_AVX2;
    if (__builtin_cpu_supports("ssse3"))
        return TINYUC_SIMD_TIER_SSSE3;
    return TINYUC_SIMD_TIER_NONE;
}

#else

static int tinyuc_detect_hw(void)
{
    return TINYUC_SIMD_TIER_NONE;
}

#endif

int tinyuc_simd_detect(void)
{
    int tier = tinyuc_detect_hw();

#if defined(TINYUC_SIMD_AVX2) && defined(TINYUC_SIMD_SSSE3)
    // Both tiers compiled: use whatever the CPU supports.
#elif defined(TINYUC_SIMD_AVX2)
    // Only the 32-byte kernel is compiled; it needs AVX2.
    if (tier < TINYUC_SIMD_TIER_AVX2)
        tier = TINYUC_SIMD_TIER_NONE;
#elif defined(TINYUC_SIMD_SSSE3)
    // Only the 16-byte kernel is compiled; it needs SSSE3.
    if (tier > TINYUC_SIMD_TIER_SSSE3)
        tier = TINYUC_SIMD_TIER_SSSE3;
#else
    tier = TINYUC_SIMD_TIER_NONE;
#endif

    tinyuc_simd_tier_cached = tier;
    return tier;
}

#endif // TINYUC_SIMD_AVX2 || TINYUC_SIMD_SSSE3
