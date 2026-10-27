/**
 * @file diag.h
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Cross-compiler diagnostic macros
 *
 * Supports GCC, Clang and MSVC.
 */

#ifndef TINYUC_DIAG_H
#define TINYUC_DIAG_H

#if defined(__clang__)
#define TINYUC_DO_PRAGMA(x) _Pragma(#x)
#define TINYUC_PRAGMA_CLANG_DIAG(x) TINYUC_DO_PRAGMA(clang diagnostic x)
#define TINYUC_DIAG_PUSH() TINYUC_PRAGMA_CLANG_DIAG(push)
#define TINYUC_DIAG_POP() TINYUC_PRAGMA_CLANG_DIAG(pop)
#define TINYUC_DIAG_IGN(w) TINYUC_PRAGMA_CLANG_DIAG(ignored w)
#define TINYUC_DIAG_CLANG_IGN(w) TINYUC_DIAG_IGN(w)
#define TINYUC_DIAG_IGN_CAST_ALIGN() TINYUC_DIAG_IGN("-Wcast-align")
#define TINYUC_DIAG_IGN_CAST_QUAL() TINYUC_DIAG_IGN("-Wcast-qual")
#define TINYUC_DIAG_IGN_DBL_PROM() TINYUC_DIAG_IGN("-Wdouble-promotion")
#define TINYUC_DIAG_IGN_FORMAT_NONLITERAL() TINYUC_DIAG_IGN("-Wformat-nonliteral")
#define TINYUC_DIAG_IGN_IMPL_INT_FLOAT() TINYUC_DIAG_IGN("-Wimplicit-int-float-conversion")
#define TINYUC_DIAG_IGN_PADDED() TINYUC_DIAG_IGN("-Wpadded")
#define TINYUC_DIAG_IGN_UNREACHABLE_CODE() TINYUC_DIAG_IGN("-Wunreachable-code")
#define TINYUC_DIAG_IGN_UNSAFE_BUFFER_USAGE() TINYUC_DIAG_IGN("-Wunsafe-buffer-usage")
#define TINYUC_DIAG_IGN_UNUSED_FUNCTION() TINYUC_DIAG_IGN("-Wunused-function")
#define TINYUC_DIAG_IGN_UNUSED_VALUE() TINYUC_DIAG_IGN("-Wunused-value")
#if defined(__clang_major__) && __clang_major__ >= 21
#define TINYUC_DIAG_IGN_NRVO() TINYUC_DIAG_IGN("-Wnrvo")
#endif
#elif defined(__GNUC__)
#define TINYUC_DO_PRAGMA(x) _Pragma(#x)
#define TINYUC_PRAGMA_GCC_DIAG(x) TINYUC_DO_PRAGMA(GCC diagnostic x)
#define TINYUC_DIAG_PUSH() TINYUC_PRAGMA_GCC_DIAG(push)
#define TINYUC_DIAG_POP() TINYUC_PRAGMA_GCC_DIAG(pop)
#define TINYUC_DIAG_IGN(w) TINYUC_PRAGMA_GCC_DIAG(ignored w)
#define TINYUC_DIAG_GCC_IGN(w) TINYUC_DIAG_IGN(w)
#define TINYUC_DIAG_IGN_CAST_ALIGN() TINYUC_DIAG_IGN("-Wcast-align")
#define TINYUC_DIAG_IGN_CAST_QUAL() TINYUC_DIAG_IGN("-Wcast-qual")
#define TINYUC_DIAG_IGN_FORMAT_NONLITERAL() TINYUC_DIAG_IGN("-Wformat-nonliteral")
#define TINYUC_DIAG_IGN_PADDED() TINYUC_DIAG_IGN("-Wpadded")
#define TINYUC_DIAG_IGN_UNUSED_FUNCTION() TINYUC_DIAG_IGN("-Wunused-function")
#define TINYUC_DIAG_IGN_UNUSED_VALUE() TINYUC_DIAG_IGN("-Wunused-value")
#if defined(__GNUC__) && __GNUC__ >= 14
#define TINYUC_DIAG_IGN_NRVO() TINYUC_DIAG_IGN("-Wnrvo")
#endif
#elif defined(_MSC_VER)
#define TINYUC_DIAG_PUSH() __pragma(warning(push))
#define TINYUC_DIAG_POP() __pragma(warning(pop))
#define TINYUC_DIAG_IGN(w) __pragma(warning(disable : w))
#define TINYUC_DIAG_MSVC_IGN(w) __pragma(warning(disable : w))
#define TINYUC_DIAG_IGN_PADDED() __pragma(warning(disable : 4820))
#define TINYUC_DIAG_IGN_UNUSED_FUNCTION() __pragma(warning(disable : 4505))
#else
// Unsupported compiler
#define TINYUC_DIAG_PUSH()
#define TINYUC_DIAG_POP()
#define TINYUC_DIAG_IGN(w)
#define TINYUC_DIAG_IGN_PADDED()
#endif

#ifndef TINYUC_DIAG_CLANG_IGN
#define TINYUC_DIAG_CLANG_IGN(w)
#endif
#ifndef TINYUC_DIAG_GCC_IGN
#define TINYUC_DIAG_GCC_IGN(w)
#endif
#ifndef TINYUC_DIAG_MSVC_IGN
#define TINYUC_DIAG_MSVC_IGN(w)
#endif

#ifndef TINYUC_DIAG_IGN_CAST_ALIGN
#define TINYUC_DIAG_IGN_CAST_ALIGN()
#endif

#ifndef TINYUC_DIAG_IGN_CAST_QUAL
#define TINYUC_DIAG_IGN_CAST_QUAL()
#endif

#ifndef TINYUC_DIAG_IGN_DBL_PROM
#define TINYUC_DIAG_IGN_DBL_PROM()
#endif

#ifndef TINYUC_DIAG_IGN_FORMAT_NONLITERAL
#define TINYUC_DIAG_IGN_FORMAT_NONLITERAL()
#endif

#ifndef TINYUC_DIAG_IGN_IMPL_INT_FLOAT
#define TINYUC_DIAG_IGN_IMPL_INT_FLOAT()
#endif

#ifndef TINYUC_DIAG_IGN_NRVO
#define TINYUC_DIAG_IGN_NRVO()
#endif

#ifndef TINYUC_DIAG_IGN_UNREACHABLE_CODE
#define TINYUC_DIAG_IGN_UNREACHABLE_CODE()
#endif

#ifndef TINYUC_DIAG_IGN_UNSAFE_BUFFER_USAGE
#define TINYUC_DIAG_IGN_UNSAFE_BUFFER_USAGE()
#endif

#ifndef TINYUC_DIAG_IGN_UNUSED_VALUE
#define TINYUC_DIAG_IGN_UNUSED_VALUE()
#endif

#endif // TINYUC_DIAG_H
