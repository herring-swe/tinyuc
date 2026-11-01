/**
 * @file utf8_iter.h
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Scalar UTF-8 decoding helpers shared by the library and the
 * benchmarks.
 *
 * All helpers here require well-formed UTF-8 and never read past the codepoint
 * they return, matching @ref tinyuc_iter_utf8() semantics.
 */

#ifndef TINYUC_PRIVATE_UTF8_ITER_H
#define TINYUC_PRIVATE_UTF8_ITER_H

#include <stddef.h>
#include <stdint.h>

static inline uint32_t tinyuc_utf8_fetch2(const unsigned char* bytes)
{
    return ((bytes[0] & 0x1Fu) << 6) //
           | (bytes[1] & 0x3Fu);
}

static inline uint32_t tinyuc_utf8_fetch3(const unsigned char* bytes)
{
    return ((bytes[0] & 0x0Fu) << 12)  //
           | ((bytes[1] & 0x3Fu) << 6) //
           | (bytes[2] & 0x3Fu);
}

static inline uint32_t tinyuc_utf8_fetch4(const unsigned char* bytes)
{
    return ((bytes[0] & 0x07u) << 18)   //
           | ((bytes[1] & 0x3Fu) << 12) //
           | ((bytes[2] & 0x3Fu) << 6)  //
           | (bytes[3] & 0x3Fu);
}

/**
 * @brief Decode one codepoint: branch chain on the lead byte class.
 *
 * This is the fastest of the scalar decoders measured (see Benchmarks.md,
 * "Alternative algorithms explored"), so it is the only one the library uses.
 */
static inline uint32_t tinyuc_utf8_decode(const unsigned char** iter)
{
    const unsigned char* bytes = *iter;
    uint32_t cp;
    if (bytes[0] < 0x80u)
    {
        cp = bytes[0];
        *iter = bytes + 1;
    }
    else if ((bytes[0] & 0xE0u) == 0xC0u)
    {
        cp = tinyuc_utf8_fetch2(bytes);
        *iter = bytes + 2;
    }
    else if ((bytes[0] & 0xF0u) == 0xE0u)
    {
        cp = tinyuc_utf8_fetch3(bytes);
        *iter = bytes + 3;
    }
    else // 4-byte sequence
    {
        cp = tinyuc_utf8_fetch4(bytes);
        *iter = bytes + 4;
    }
    return cp;
}

/**
 * @brief Count codepoints in a validated buffer.
 *
 * This is the scalar fallback used when no SIMD counter is available. It
 * returns TINYUC_NPOS (SIZE_MAX - 1) on a truncated trailing sequence, matching
 * the failure mode of the public @ref tinyuc_num_cp().
 */
static inline size_t tinyuc_utf8_count(const char* str, size_t len)
{
    const unsigned char* iter = (const unsigned char*)str;
    const unsigned char* last = iter + len;
    size_t count = 0;
    while (iter < last)
    {
        tinyuc_utf8_decode(&iter);
        if (iter > last)
            return SIZE_MAX - 1;
        count++;
    }
    return count;
}

#endif // TINYUC_PRIVATE_UTF8_ITER_H
