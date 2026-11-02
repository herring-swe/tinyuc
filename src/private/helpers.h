/**
 * @file helpers.h
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Simple internal helper functions.
 */

#include <tinyuc/export.h>

#include <stdarg.h>
#include <stddef.h>

#define TINYUC_UNUSED(var) ((void)(var))

#if defined(_MSC_VER)
#define TINYUC_FORCE_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#define TINYUC_FORCE_INLINE __attribute__((always_inline)) inline
#else
#define TINYUC_FORCE_INLINE inline
#endif

#ifdef NDEBUG
#define TINYUC_ASSERT(expr, msg)
#else
#define TINYUC_ASSERT(expr, msg) \
    if (!(expr))                 \
    {                            \
        tinyuc_error(msg);       \
    }
#endif

#ifdef _WIN32
#define strdup _strdup
#endif

TINYUC_API int tinyuc_error(const char* msg);

TINYUC_API int tinyuc_stricomp(const char* a, const char* b);

TINYUC_API int tinyuc_vsnprintf(char* buffer, size_t count, const char* fmt, va_list vlist);

TINYUC_API int tinyuc_asprintf(char** restrict pstr, const char* restrict fmt, ...);

TINYUC_API int tinyuc_vasprintf(char** restrict pstr, const char* restrict fmt, va_list vlist);