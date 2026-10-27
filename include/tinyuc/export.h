/**
 * @file export.h
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief API definitions for tinyuc library
 */

#ifndef TINYUC_EXPORT_H
#define TINYUC_EXPORT_H

// clang-format off
#ifdef __cplusplus
    #ifdef _MSC_VER
        #define TINYUC_RESTRICT __restrict
    #else
        #define TINYUC_RESTRICT __restrict__
    #endif
#else
    #define TINYUC_RESTRICT restrict
#endif

#ifdef _MSC_VER
    #define TINYUC_DEPRECATED __declspec(deprecated)
#elif defined(__GNUC__) || defined(__clang__)
    #define TINYUC_DEPRECATED __attribute__((deprecated))
#else
    #define TINYUC_DEPRECATED
#endif

#ifdef __cplusplus
    #define TINYUC_EXTERN_C extern "C"
    #define TINYUC_NORETURN [[noreturn]]
#else
    #define TINYUC_EXTERN_C
    #if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
        #define TINYUC_NORETURN [[noreturn]]
    #elif defined(_MSC_VER)
        #define TINYUC_NORETURN _Noreturn
    #elif defined(__GNUC__) || defined(__clang__)
        #define TINYUC_NORETURN __attribute__((noreturn))
    #else
        #error "Unsupported compiler"
    #endif
#endif

#ifdef TINYUC_STATIC_LIB
    #define TINYUC_EXPORT
#else
    #ifdef _WIN32
        #ifdef TINYUC_BUILD_LIB
            #define TINYUC_EXPORT __declspec(dllexport)
        #else
            #define TINYUC_EXPORT __declspec(dllimport)
        #endif
    #else
        #define TINYUC_EXPORT __attribute__((visibility("default")))
    #endif
#endif
// clang-format on

#define TINYUC_API TINYUC_EXTERN_C TINYUC_EXPORT
#define TINYUC_API_NORETURN TINYUC_EXTERN_C TINYUC_NORETURN TINYUC_EXPORT

#endif // TINYUC_EXPORT_H
