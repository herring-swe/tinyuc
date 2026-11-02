/**
 * @file compare.cpp
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Benchmarks comparing TinyUC against external Unicode libraries.
 */

#include "tinyuc/unicode.h"

#include "ucd_corpus.h"

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
#include <utf8proc.h>
#endif

#ifdef TINYUC_COMPARE_HAS_ICU
#include <unicode/ubrk.h>
#include <unicode/uchar.h>
#include <unicode/unorm2.h>
#include <unicode/ustring.h>
#include <unicode/utf16.h>
#include <unicode/uversion.h>
#endif

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#ifdef __INTELLISENSE__
#ifndef NORM_TEST_FILE
#define NORM_TEST_FILE "dummy"
#endif
#ifndef GRAPHEME_TEST_FILE
#define GRAPHEME_TEST_FILE "dummy"
#endif
#endif

namespace {

volatile std::uint64_t g_sink = 0;

struct text_case
{
    std::string file;
    std::string name;
    std::string text;
#ifdef TINYUC_COMPARE_HAS_ICU
    std::vector<UChar> utf16;
    int32_t utf16_len = 0;
    mutable std::vector<UChar> scratch;
#endif
};

const std::vector<ucd_norm_case>& corpus()
{
    static const std::vector<ucd_norm_case> tests = [] {
        std::vector<ucd_norm_case> loaded;
        ucd_load_normalization_tests(NORM_TEST_FILE, loaded);
        return loaded;
    }();
    return tests;
}

const std::string& grapheme_buffer()
{
    static const std::string buffer = [] {
        std::string loaded;
        ucd_load_grapheme_buffer(GRAPHEME_TEST_FILE, loaded);
        return loaded;
    }();
    return buffer;
}

template <typename Convert>
void for_each_source(Convert convert)
{
    static const enum tinyuc_norm_form forms[4] = {TINYUC_NORM_NFD,
                                                   TINYUC_NORM_NFC,
                                                   TINYUC_NORM_NFKD,
                                                   TINYUC_NORM_NFKC};

    std::uint64_t sink = 0;
    for (const ucd_norm_case& test : corpus())
    {
        const std::string* sources[5] = {&test.input, &test.nfc, &test.nfd, &test.nfkc, &test.nfkd};
        for (const std::string* source : sources)
        {
            for (const enum tinyuc_norm_form form : forms)
                sink += static_cast<std::uint64_t>(convert(*source, form));
        }
    }
    g_sink = g_sink + sink;
}

using norm_func =
    tinyuc_result (*)(const char*, size_t, enum tinyuc_norm_form, char**, size_t*, char**);

void normalize_tinyuc(norm_func fn)
{
    for_each_source([fn](const std::string& source, enum tinyuc_norm_form form) -> std::size_t {
        char* result = nullptr;
        std::size_t result_len = 0;
        if (fn(source.data(), source.size(), form, &result, &result_len, nullptr) != TINYUC_OK)
            result_len = 0;
        free(result);
        return result_len;
    });
}

void casefold_tinyuc()
{
    std::uint64_t sink = 0;
    for (const ucd_norm_case& test : corpus())
    {
        const std::string* sources[5] = {&test.input, &test.nfc, &test.nfd, &test.nfkc, &test.nfkd};
        for (const std::string* source : sources)
        {
            char* result = nullptr;
            std::size_t result_len = 0;
            if (tinyuc_casefold(source->data(), source->size(), &result, &result_len, nullptr) ==
                TINYUC_OK)
                sink += result_len;
            free(result);
        }
    }
    g_sink = g_sink + sink;
}

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
unsigned int utf8proc_norm_options(enum tinyuc_norm_form form)
{
    switch (form)
    {
    case TINYUC_NORM_NFD:
        return UTF8PROC_STABLE | UTF8PROC_DECOMPOSE;
    case TINYUC_NORM_NFC:
        return UTF8PROC_STABLE | UTF8PROC_COMPOSE;
    case TINYUC_NORM_NFKD:
        return UTF8PROC_STABLE | UTF8PROC_DECOMPOSE | UTF8PROC_COMPAT;
    case TINYUC_NORM_NFKC:
        return UTF8PROC_STABLE | UTF8PROC_COMPOSE | UTF8PROC_COMPAT;
    default:
        return UTF8PROC_STABLE;
    }
}

void normalize_utf8proc()
{
    for_each_source([](const std::string& source, enum tinyuc_norm_form form) -> std::size_t {
        utf8proc_uint8_t* dest = nullptr;
        const utf8proc_ssize_t result =
            utf8proc_map(reinterpret_cast<const utf8proc_uint8_t*>(source.data()),
                         static_cast<utf8proc_ssize_t>(source.size()),
                         &dest,
                         utf8proc_norm_options(form));
        const std::size_t size = result >= 0 ? static_cast<std::size_t>(result) : 0;
        utf8proc_free(dest);
        return size;
    });
}

void casefold_utf8proc()
{
    std::uint64_t sink = 0;
    for (const ucd_norm_case& test : corpus())
    {
        const std::string* sources[5] = {&test.input, &test.nfc, &test.nfd, &test.nfkc, &test.nfkd};
        for (const std::string* source : sources)
        {
            utf8proc_uint8_t* dest = nullptr;
            const utf8proc_ssize_t result =
                utf8proc_map(reinterpret_cast<const utf8proc_uint8_t*>(source->data()),
                             static_cast<utf8proc_ssize_t>(source->size()),
                             &dest,
                             UTF8PROC_CASEFOLD);
            if (result >= 0)
                sink += static_cast<std::uint64_t>(result);
            utf8proc_free(dest);
        }
    }
    g_sink = g_sink + sink;
}
#endif // TINYUC_COMPARE_HAS_UTF8PROC

#ifdef TINYUC_COMPARE_HAS_ICU
const UNormalizer2* icu_normalizer_for(enum tinyuc_norm_form form)
{
    static const std::array<const UNormalizer2*, 4> instances = [] {
        UErrorCode status = U_ZERO_ERROR;
        return std::array<const UNormalizer2*, 4>{
            unorm2_getNFDInstance(&status),
            unorm2_getNFCInstance(&status),
            unorm2_getNFKDInstance(&status),
            unorm2_getNFKCInstance(&status),
        };
    }();

    switch (form)
    {
    case TINYUC_NORM_NFD:
        return instances[0];
    case TINYUC_NORM_NFC:
        return instances[1];
    case TINYUC_NORM_NFKD:
        return instances[2];
    case TINYUC_NORM_NFKC:
        return instances[3];
    default:
        return nullptr;
    }
}

bool icu_utf8_to_utf16(const std::string& source, std::vector<UChar>& dest, int32_t& dest_len)
{
    UErrorCode status = U_ZERO_ERROR;
    u_strFromUTF8(nullptr,
                  0,
                  &dest_len,
                  source.data(),
                  static_cast<int32_t>(source.size()),
                  &status);
    if (dest_len < 0)
        return false;

    dest.resize(static_cast<std::size_t>(dest_len) + 1);
    status = U_ZERO_ERROR;
    u_strFromUTF8(dest.data(),
                  dest_len + 1,
                  &dest_len,
                  source.data(),
                  static_cast<int32_t>(source.size()),
                  &status);
    return U_SUCCESS(status);
}

std::size_t icu_utf16_to_utf8_len(const std::vector<UChar>& source, int32_t source_len)
{
    UErrorCode status = U_ZERO_ERROR;
    int32_t length = 0;
    u_strToUTF8(nullptr, 0, &length, source.data(), source_len, &status);
    return length > 0 ? static_cast<std::size_t>(length) : 0;
}

struct icu_text
{
    std::vector<UChar> data;
    int32_t length = 0;
};

struct icu_corpus
{
    std::vector<icu_text> texts;
    std::size_t max_length = 0;
};

const icu_corpus& icu_utf16_corpus()
{
    static const icu_corpus cached = [] {
        icu_corpus data;
        for (const ucd_norm_case& test : corpus())
        {
            const std::string* sources[5] = {&test.input,
                                             &test.nfc,
                                             &test.nfd,
                                             &test.nfkc,
                                             &test.nfkd};
            for (const std::string* source : sources)
            {
                icu_text text;
                if (!icu_utf8_to_utf16(*source, text.data, text.length))
                    continue;

                data.max_length = std::max(data.max_length, static_cast<std::size_t>(text.length));
                data.texts.push_back(std::move(text));
            }
        }
        return data;
    }();
    return cached;
}

const icu_text& icu_utf16_grapheme()
{
    static const icu_text cached = [] {
        icu_text text;
        icu_utf8_to_utf16(grapheme_buffer(), text.data, text.length);
        return text;
    }();
    return cached;
}

void normalize_icu_utf16()
{
    static const enum tinyuc_norm_form forms[4] = {TINYUC_NORM_NFD,
                                                   TINYUC_NORM_NFC,
                                                   TINYUC_NORM_NFKD,
                                                   TINYUC_NORM_NFKC};

    const icu_corpus& text_corpus = icu_utf16_corpus();
    static std::vector<UChar> scratch(text_corpus.max_length * 32 + 64);

    std::uint64_t sink = 0;
    for (const icu_text& text : text_corpus.texts)
    {
        for (const enum tinyuc_norm_form form : forms)
        {
            const UNormalizer2* normalizer = icu_normalizer_for(form);
            if (normalizer == nullptr)
                continue;

            UErrorCode status = U_ZERO_ERROR;
            const int32_t normalized_len = unorm2_normalize(normalizer,
                                                            text.data.data(),
                                                            text.length,
                                                            scratch.data(),
                                                            static_cast<int32_t>(scratch.size()),
                                                            &status);
            if (U_SUCCESS(status))
                sink += static_cast<std::uint64_t>(normalized_len);
        }
    }
    g_sink = g_sink + sink;
}

void casefold_icu_utf16()
{
    const icu_corpus& text_corpus = icu_utf16_corpus();
    static std::vector<UChar> scratch(text_corpus.max_length * 32 + 64);

    std::uint64_t sink = 0;
    for (const icu_text& text : text_corpus.texts)
    {
        UErrorCode status = U_ZERO_ERROR;
        const int32_t folded_len = u_strFoldCase(scratch.data(),
                                                 static_cast<int32_t>(scratch.size()),
                                                 text.data.data(),
                                                 text.length,
                                                 U_FOLD_CASE_DEFAULT,
                                                 &status);
        if (U_SUCCESS(status))
            sink += static_cast<std::uint64_t>(folded_len);
    }
    g_sink = g_sink + sink;
}

void grapheme_icu_utf16()
{
    const icu_text& text = icu_utf16_grapheme();

    UErrorCode status = U_ZERO_ERROR;
    UBreakIterator* iterator =
        ubrk_open(UBRK_CHARACTER, nullptr, text.data.data(), text.length, &status);
    if (U_FAILURE(status) || iterator == nullptr)
    {
        if (iterator != nullptr)
            ubrk_close(iterator);
        return;
    }

    std::uint64_t count = 0;
    ubrk_first(iterator);
    while (ubrk_next(iterator) != UBRK_DONE)
        ++count;

    ubrk_close(iterator);
    g_sink += count;
}

void normalize_icu()
{
    for_each_source([](const std::string& source, enum tinyuc_norm_form form) -> std::size_t {
        const UNormalizer2* normalizer = icu_normalizer_for(form);
        if (normalizer == nullptr)
            return 0;

        std::vector<UChar> utf16;
        int32_t utf16_len = 0;
        if (!icu_utf8_to_utf16(source, utf16, utf16_len))
            return 0;

        UErrorCode status = U_ZERO_ERROR;
        const int32_t normalized_len =
            unorm2_normalize(normalizer, utf16.data(), utf16_len, nullptr, 0, &status);
        if (normalized_len < 0)
            return 0;

        std::vector<UChar> normalized(static_cast<std::size_t>(normalized_len) + 1);
        status = U_ZERO_ERROR;
        unorm2_normalize(normalizer,
                         utf16.data(),
                         utf16_len,
                         normalized.data(),
                         normalized_len + 1,
                         &status);
        if (U_FAILURE(status))
            return 0;

        return icu_utf16_to_utf8_len(normalized, normalized_len);
    });
}

void casefold_icu()
{
    std::uint64_t sink = 0;
    for (const ucd_norm_case& test : corpus())
    {
        const std::string* sources[5] = {&test.input, &test.nfc, &test.nfd, &test.nfkc, &test.nfkd};
        for (const std::string* source : sources)
        {
            std::vector<UChar> utf16;
            int32_t utf16_len = 0;
            if (!icu_utf8_to_utf16(*source, utf16, utf16_len))
                continue;

            UErrorCode status = U_ZERO_ERROR;
            const int32_t folded_len =
                u_strFoldCase(nullptr, 0, utf16.data(), utf16_len, U_FOLD_CASE_DEFAULT, &status);
            if (folded_len < 0)
                continue;

            std::vector<UChar> folded(static_cast<std::size_t>(folded_len) + 1);
            status = U_ZERO_ERROR;
            u_strFoldCase(folded.data(),
                          folded_len + 1,
                          utf16.data(),
                          utf16_len,
                          U_FOLD_CASE_DEFAULT,
                          &status);
            if (U_FAILURE(status))
                continue;

            sink += static_cast<std::uint64_t>(icu_utf16_to_utf8_len(folded, folded_len));
        }
    }
    g_sink = g_sink + sink;
}
#endif // TINYUC_COMPARE_HAS_ICU

void grapheme_tinyuc()
{
    const std::string& text = grapheme_buffer();
    g_sink += static_cast<std::uint64_t>(tinyuc_num_char(text.data(), text.size()));
}

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
void grapheme_utf8proc()
{
    const std::string& text = grapheme_buffer();
    const utf8proc_uint8_t* data = reinterpret_cast<const utf8proc_uint8_t*>(text.data());

    std::uint64_t count = 0;
    std::size_t offset = 0;
    utf8proc_int32_t previous = 0;
    utf8proc_int32_t state = 0;
    bool first = true;

    while (offset < text.size())
    {
        utf8proc_int32_t codepoint = 0;
        const utf8proc_ssize_t length =
            utf8proc_iterate(data + offset,
                             static_cast<utf8proc_ssize_t>(text.size() - offset),
                             &codepoint);
        if (length < 0)
            break;

        if (first)
        {
            count = 1;
            first = false;
        }
        else if (utf8proc_grapheme_break_stateful(previous, codepoint, &state))
        {
            ++count;
            state = 0;
        }

        previous = codepoint;
        offset += static_cast<std::size_t>(length);
    }

    g_sink += count;
}
#endif // TINYUC_COMPARE_HAS_UTF8PROC

#ifdef TINYUC_COMPARE_HAS_ICU
void grapheme_icu()
{
    const std::string& text = grapheme_buffer();

    std::vector<UChar> utf16;
    int32_t utf16_len = 0;
    if (!icu_utf8_to_utf16(text, utf16, utf16_len))
        return;

    UErrorCode status = U_ZERO_ERROR;
    UBreakIterator* iterator = ubrk_open(UBRK_CHARACTER, nullptr, utf16.data(), utf16_len, &status);
    if (U_FAILURE(status) || iterator == nullptr)
    {
        if (iterator != nullptr)
            ubrk_close(iterator);
        return;
    }

    std::uint64_t count = 0;
    ubrk_first(iterator);
    while (ubrk_next(iterator) != UBRK_DONE)
        ++count;

    ubrk_close(iterator);
    g_sink += count;
}
#endif // TINYUC_COMPARE_HAS_ICU

const std::vector<text_case>& language_corpus()
{
    static const std::vector<text_case> cached = [] {
        std::vector<text_case> loaded;
        for (const ucd_language_text& base : ucd_language_texts())
        {
            text_case text;
            text.file = base.file;
            text.name = base.name;
            text.text = base.text;

#ifdef TINYUC_COMPARE_HAS_ICU
            icu_utf8_to_utf16(text.text, text.utf16, text.utf16_len);
            text.scratch.resize(static_cast<std::size_t>(text.utf16_len) * 32 + 64);
#endif

            loaded.push_back(std::move(text));
        }
        return loaded;
    }();
    return cached;
}

const text_case& text_case_for(const char* file)
{
    for (const text_case& text : language_corpus())
    {
        if (text.file == file)
            return text;
    }

    throw std::runtime_error(std::string("missing benchmark text: ") + file);
}

void normalize_text_tinyuc(const std::string& text, norm_func fn)
{
    static const enum tinyuc_norm_form forms[4] = {TINYUC_NORM_NFD,
                                                   TINYUC_NORM_NFC,
                                                   TINYUC_NORM_NFKD,
                                                   TINYUC_NORM_NFKC};

    std::uint64_t sink = 0;
    for (const enum tinyuc_norm_form form : forms)
    {
        char* result = nullptr;
        std::size_t result_len = 0;
        if (fn(text.data(), text.size(), form, &result, &result_len, nullptr) == TINYUC_OK)
            sink += result_len;
        free(result);
    }
    g_sink = g_sink + sink;
}

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
void normalize_text_utf8proc(const std::string& text)
{
    static const enum tinyuc_norm_form forms[4] = {TINYUC_NORM_NFD,
                                                   TINYUC_NORM_NFC,
                                                   TINYUC_NORM_NFKD,
                                                   TINYUC_NORM_NFKC};

    std::uint64_t sink = 0;
    for (const enum tinyuc_norm_form form : forms)
    {
        utf8proc_uint8_t* dest = nullptr;
        const utf8proc_ssize_t result =
            utf8proc_map(reinterpret_cast<const utf8proc_uint8_t*>(text.data()),
                         static_cast<utf8proc_ssize_t>(text.size()),
                         &dest,
                         utf8proc_norm_options(form));
        if (result >= 0)
            sink += static_cast<std::uint64_t>(result);
        utf8proc_free(dest);
    }
    g_sink = g_sink + sink;
}
#endif // TINYUC_COMPARE_HAS_UTF8PROC

#ifdef TINYUC_COMPARE_HAS_ICU
void normalize_text_icu_utf8(const std::string& text)
{
    static const enum tinyuc_norm_form forms[4] = {TINYUC_NORM_NFD,
                                                   TINYUC_NORM_NFC,
                                                   TINYUC_NORM_NFKD,
                                                   TINYUC_NORM_NFKC};

    std::uint64_t sink = 0;
    for (const enum tinyuc_norm_form form : forms)
    {
        const UNormalizer2* normalizer = icu_normalizer_for(form);
        if (normalizer == nullptr)
            continue;

        std::vector<UChar> utf16;
        int32_t utf16_len = 0;
        if (!icu_utf8_to_utf16(text, utf16, utf16_len))
            continue;

        UErrorCode status = U_ZERO_ERROR;
        const int32_t normalized_len =
            unorm2_normalize(normalizer, utf16.data(), utf16_len, nullptr, 0, &status);
        if (normalized_len < 0)
            continue;

        std::vector<UChar> normalized(static_cast<std::size_t>(normalized_len) + 1);
        status = U_ZERO_ERROR;
        unorm2_normalize(normalizer,
                         utf16.data(),
                         utf16_len,
                         normalized.data(),
                         normalized_len + 1,
                         &status);
        if (U_FAILURE(status))
            continue;

        sink += static_cast<std::uint64_t>(icu_utf16_to_utf8_len(normalized, normalized_len));
    }
    g_sink = g_sink + sink;
}

void normalize_text_icu_utf16(const text_case& text)
{
    static const enum tinyuc_norm_form forms[4] = {TINYUC_NORM_NFD,
                                                   TINYUC_NORM_NFC,
                                                   TINYUC_NORM_NFKD,
                                                   TINYUC_NORM_NFKC};

    std::uint64_t sink = 0;
    for (const enum tinyuc_norm_form form : forms)
    {
        const UNormalizer2* normalizer = icu_normalizer_for(form);
        if (normalizer == nullptr)
            continue;

        UErrorCode status = U_ZERO_ERROR;
        const int32_t normalized_len = unorm2_normalize(normalizer,
                                                        text.utf16.data(),
                                                        text.utf16_len,
                                                        text.scratch.data(),
                                                        static_cast<int32_t>(text.scratch.size()),
                                                        &status);
        if (U_SUCCESS(status))
            sink += static_cast<std::uint64_t>(normalized_len);
    }
    g_sink = g_sink + sink;
}
#endif // TINYUC_COMPARE_HAS_ICU

void casefold_text_tinyuc(const std::string& text)
{
    char* result = nullptr;
    std::size_t result_len = 0;
    if (tinyuc_casefold(text.data(), text.size(), &result, &result_len, nullptr) == TINYUC_OK)
        g_sink += result_len;
    free(result);
}

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
void casefold_text_utf8proc(const std::string& text)
{
    utf8proc_uint8_t* dest = nullptr;
    const utf8proc_ssize_t result =
        utf8proc_map(reinterpret_cast<const utf8proc_uint8_t*>(text.data()),
                     static_cast<utf8proc_ssize_t>(text.size()),
                     &dest,
                     UTF8PROC_CASEFOLD);
    if (result >= 0)
        g_sink += static_cast<std::uint64_t>(result);
    utf8proc_free(dest);
}
#endif // TINYUC_COMPARE_HAS_UTF8PROC

#ifdef TINYUC_COMPARE_HAS_ICU
void casefold_text_icu_utf8(const std::string& text)
{
    std::vector<UChar> utf16;
    int32_t utf16_len = 0;
    if (!icu_utf8_to_utf16(text, utf16, utf16_len))
        return;

    UErrorCode status = U_ZERO_ERROR;
    const int32_t folded_len =
        u_strFoldCase(nullptr, 0, utf16.data(), utf16_len, U_FOLD_CASE_DEFAULT, &status);
    if (folded_len < 0)
        return;

    std::vector<UChar> folded(static_cast<std::size_t>(folded_len) + 1);
    status = U_ZERO_ERROR;
    u_strFoldCase(folded.data(),
                  folded_len + 1,
                  utf16.data(),
                  utf16_len,
                  U_FOLD_CASE_DEFAULT,
                  &status);
    if (U_SUCCESS(status))
        g_sink += static_cast<std::uint64_t>(icu_utf16_to_utf8_len(folded, folded_len));
}

void casefold_text_icu_utf16(const text_case& text)
{
    UErrorCode status = U_ZERO_ERROR;
    const int32_t folded_len = u_strFoldCase(text.scratch.data(),
                                             static_cast<int32_t>(text.scratch.size()),
                                             text.utf16.data(),
                                             text.utf16_len,
                                             U_FOLD_CASE_DEFAULT,
                                             &status);
    if (U_SUCCESS(status))
        g_sink += static_cast<std::uint64_t>(folded_len);
}
#endif // TINYUC_COMPARE_HAS_ICU

void grapheme_text_tinyuc(const std::string& text)
{
    g_sink += static_cast<std::uint64_t>(tinyuc_num_char(text.data(), text.size()));
}

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
void grapheme_text_utf8proc(const std::string& text)
{
    const utf8proc_uint8_t* data = reinterpret_cast<const utf8proc_uint8_t*>(text.data());

    std::uint64_t count = 0;
    std::size_t offset = 0;
    utf8proc_int32_t previous = 0;
    utf8proc_int32_t state = 0;
    bool first = true;

    while (offset < text.size())
    {
        utf8proc_int32_t codepoint = 0;
        const utf8proc_ssize_t length =
            utf8proc_iterate(data + offset,
                             static_cast<utf8proc_ssize_t>(text.size() - offset),
                             &codepoint);
        if (length < 0)
            break;

        if (first)
        {
            count = 1;
            first = false;
        }
        else if (utf8proc_grapheme_break_stateful(previous, codepoint, &state))
        {
            ++count;
            state = 0;
        }

        previous = codepoint;
        offset += static_cast<std::size_t>(length);
    }

    g_sink += count;
}
#endif // TINYUC_COMPARE_HAS_UTF8PROC

#ifdef TINYUC_COMPARE_HAS_ICU
void grapheme_text_icu_utf8(const std::string& text)
{
    std::vector<UChar> utf16;
    int32_t utf16_len = 0;
    if (!icu_utf8_to_utf16(text, utf16, utf16_len))
        return;

    UErrorCode status = U_ZERO_ERROR;
    UBreakIterator* iterator = ubrk_open(UBRK_CHARACTER, nullptr, utf16.data(), utf16_len, &status);
    if (U_FAILURE(status) || iterator == nullptr)
    {
        if (iterator != nullptr)
            ubrk_close(iterator);
        return;
    }

    std::uint64_t count = 0;
    ubrk_first(iterator);
    while (ubrk_next(iterator) != UBRK_DONE)
        ++count;

    ubrk_close(iterator);
    g_sink += count;
}

void grapheme_text_icu_utf16(const text_case& text)
{
    UErrorCode status = U_ZERO_ERROR;
    UBreakIterator* iterator =
        ubrk_open(UBRK_CHARACTER, nullptr, text.utf16.data(), text.utf16_len, &status);
    if (U_FAILURE(status) || iterator == nullptr)
    {
        if (iterator != nullptr)
            ubrk_close(iterator);
        return;
    }

    std::uint64_t count = 0;
    ubrk_first(iterator);
    while (ubrk_next(iterator) != UBRK_DONE)
        ++count;

    ubrk_close(iterator);
    g_sink += count;
}
#endif // TINYUC_COMPARE_HAS_ICU

void validate_text_tinyuc(const std::string& text)
{
    g_sink += tinyuc_validate(text.data(), text.size(), nullptr) == TINYUC_OK ? 1 : 0;
}

void count_text_tinyuc(const std::string& text)
{
    g_sink += static_cast<std::uint64_t>(tinyuc_num_cp(text.data(), text.size()));
}

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
void validate_text_utf8proc(const std::string& text)
{
    const utf8proc_uint8_t* data = reinterpret_cast<const utf8proc_uint8_t*>(text.data());
    std::size_t offset = 0;
    bool valid = true;

    while (offset < text.size())
    {
        utf8proc_int32_t codepoint = 0;
        const utf8proc_ssize_t length =
            utf8proc_iterate(data + offset,
                             static_cast<utf8proc_ssize_t>(text.size() - offset),
                             &codepoint);
        if (length < 0)
        {
            valid = false;
            break;
        }
        offset += static_cast<std::size_t>(length);
    }

    g_sink += valid ? 1 : 0;
}

void count_text_utf8proc(const std::string& text)
{
    const utf8proc_uint8_t* data = reinterpret_cast<const utf8proc_uint8_t*>(text.data());
    std::size_t offset = 0;
    std::uint64_t count = 0;

    while (offset < text.size())
    {
        utf8proc_int32_t codepoint = 0;
        const utf8proc_ssize_t length =
            utf8proc_iterate(data + offset,
                             static_cast<utf8proc_ssize_t>(text.size() - offset),
                             &codepoint);
        if (length < 0)
            break;
        ++count;
        offset += static_cast<std::size_t>(length);
    }

    g_sink += count;
}
#endif // TINYUC_COMPARE_HAS_UTF8PROC

#ifdef TINYUC_COMPARE_HAS_ICU
std::uint64_t count_utf16_codepoints(const UChar* data, int32_t length)
{
    std::uint64_t count = 0;
    for (int32_t offset = 0; offset < length;)
    {
        UChar32 codepoint = 0;
        U16_NEXT(data, offset, length, codepoint);
        ++count;
    }
    return count;
}

void validate_text_icu_utf8(const std::string& text)
{
    UErrorCode status = U_ZERO_ERROR;
    int32_t length = 0;
    u_strFromUTF8(nullptr, 0, &length, text.data(), static_cast<int32_t>(text.size()), &status);
    g_sink += (status == U_ZERO_ERROR || status == U_BUFFER_OVERFLOW_ERROR) ? 1 : 0;
}

void count_text_icu_utf8(const text_case& text)
{
    UErrorCode status = U_ZERO_ERROR;
    int32_t needed = 0;
    u_strFromUTF8(nullptr,
                  0,
                  &needed,
                  text.text.data(),
                  static_cast<int32_t>(text.text.size()),
                  &status);
    if (status != U_ZERO_ERROR && status != U_BUFFER_OVERFLOW_ERROR)
        return;

    status = U_ZERO_ERROR;
    int32_t length = 0;
    u_strFromUTF8(text.scratch.data(),
                  static_cast<int32_t>(text.scratch.size()),
                  &length,
                  text.text.data(),
                  static_cast<int32_t>(text.text.size()),
                  &status);
    if (U_SUCCESS(status))
        g_sink += count_utf16_codepoints(text.scratch.data(), length);
}

void count_text_icu_utf16(const text_case& text)
{
    g_sink += count_utf16_codepoints(text.utf16.data(), text.utf16_len);
}
#endif // TINYUC_COMPARE_HAS_ICU

} // namespace

TEST_CASE("normalization", "[compare][normalization]")
{
    BENCHMARK("tinyuc")
    {
        normalize_tinyuc(tinyuc_normalize);
    };

    BENCHMARK("tinyuc-full")
    {
        normalize_tinyuc(tinyuc_normalize_full);
    };

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
    BENCHMARK("utf8proc")
    {
        normalize_utf8proc();
    };
#endif

#ifdef TINYUC_COMPARE_HAS_ICU
    BENCHMARK("icu-utf8")
    {
        normalize_icu();
    };

    BENCHMARK("icu-utf16")
    {
        normalize_icu_utf16();
    };
#endif
}

TEST_CASE("casefold", "[compare][casefold]")
{
    BENCHMARK("tinyuc")
    {
        casefold_tinyuc();
    };

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
    BENCHMARK("utf8proc")
    {
        casefold_utf8proc();
    };
#endif

#ifdef TINYUC_COMPARE_HAS_ICU
    BENCHMARK("icu-utf8")
    {
        casefold_icu();
    };

    BENCHMARK("icu-utf16")
    {
        casefold_icu_utf16();
    };
#endif
}

TEST_CASE("grapheme", "[compare][grapheme]")
{
    BENCHMARK("tinyuc")
    {
        grapheme_tinyuc();
    };

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
    BENCHMARK("utf8proc")
    {
        grapheme_utf8proc();
    };
#endif

#ifdef TINYUC_COMPARE_HAS_ICU
    BENCHMARK("icu-utf8")
    {
        grapheme_icu();
    };

    BENCHMARK("icu-utf16")
    {
        grapheme_icu_utf16();
    };
#endif
}

#ifdef TINYUC_COMPARE_HAS_UTF8PROC
#define TINYUC_COMPARE_TEXT_UTF8PROC_NORMALIZE(text) \
    BENCHMARK("utf8proc")                            \
    {                                                \
        normalize_text_utf8proc((text).text);        \
    };
#define TINYUC_COMPARE_TEXT_UTF8PROC_CASEFOLD(text) \
    BENCHMARK("utf8proc")                           \
    {                                               \
        casefold_text_utf8proc((text).text);        \
    };
#define TINYUC_COMPARE_TEXT_UTF8PROC_GRAPHEME(text) \
    BENCHMARK("utf8proc")                           \
    {                                               \
        grapheme_text_utf8proc((text).text);        \
    };
#define TINYUC_COMPARE_TEXT_UTF8PROC_VALIDATE(text) \
    BENCHMARK("utf8proc")                           \
    {                                               \
        validate_text_utf8proc((text).text);        \
    };
#define TINYUC_COMPARE_TEXT_UTF8PROC_COUNT(text) \
    BENCHMARK("utf8proc")                        \
    {                                            \
        count_text_utf8proc((text).text);        \
    };
#else
#define TINYUC_COMPARE_TEXT_UTF8PROC_NORMALIZE(text)
#define TINYUC_COMPARE_TEXT_UTF8PROC_CASEFOLD(text)
#define TINYUC_COMPARE_TEXT_UTF8PROC_GRAPHEME(text)
#define TINYUC_COMPARE_TEXT_UTF8PROC_VALIDATE(text)
#define TINYUC_COMPARE_TEXT_UTF8PROC_COUNT(text)
#endif

#ifdef TINYUC_COMPARE_HAS_ICU
#define TINYUC_COMPARE_TEXT_ICU_NORMALIZE(text) \
    BENCHMARK("icu-utf8")                       \
    {                                           \
        normalize_text_icu_utf8((text).text);   \
    };                                          \
    BENCHMARK("icu-utf16")                      \
    {                                           \
        normalize_text_icu_utf16((text));       \
    };
#define TINYUC_COMPARE_TEXT_ICU_CASEFOLD(text) \
    BENCHMARK("icu-utf8")                      \
    {                                          \
        casefold_text_icu_utf8((text).text);   \
    };                                         \
    BENCHMARK("icu-utf16")                     \
    {                                          \
        casefold_text_icu_utf16((text));       \
    };
#define TINYUC_COMPARE_TEXT_ICU_GRAPHEME(text) \
    BENCHMARK("icu-utf8")                      \
    {                                          \
        grapheme_text_icu_utf8((text).text);   \
    };                                         \
    BENCHMARK("icu-utf16")                     \
    {                                          \
        grapheme_text_icu_utf16((text));       \
    };
#define TINYUC_COMPARE_TEXT_ICU_VALIDATE(text) \
    BENCHMARK("icu-utf8")                      \
    {                                          \
        validate_text_icu_utf8((text).text);   \
    };
#define TINYUC_COMPARE_TEXT_ICU_COUNT(text) \
    BENCHMARK("icu-utf8")                   \
    {                                       \
        count_text_icu_utf8((text));        \
    };                                      \
    BENCHMARK("icu-utf16")                  \
    {                                       \
        count_text_icu_utf16((text));       \
    };
#else
#define TINYUC_COMPARE_TEXT_ICU_NORMALIZE(text)
#define TINYUC_COMPARE_TEXT_ICU_CASEFOLD(text)
#define TINYUC_COMPARE_TEXT_ICU_GRAPHEME(text)
#define TINYUC_COMPARE_TEXT_ICU_VALIDATE(text)
#define TINYUC_COMPARE_TEXT_ICU_COUNT(text)
#endif

#define TINYUC_COMPARE_TEXT_SUITE(NAME, FILE)                            \
    TEST_CASE("normalization - " NAME, "[compare][text][normalization]") \
    {                                                                    \
        const text_case& text = text_case_for(FILE);                     \
        BENCHMARK("tinyuc")                                              \
        {                                                                \
            normalize_text_tinyuc(text.text, tinyuc_normalize);          \
        };                                                               \
        BENCHMARK("tinyuc-full")                                         \
        {                                                                \
            normalize_text_tinyuc(text.text, tinyuc_normalize_full);     \
        };                                                               \
        TINYUC_COMPARE_TEXT_UTF8PROC_NORMALIZE(text)                     \
        TINYUC_COMPARE_TEXT_ICU_NORMALIZE(text)                          \
    }                                                                    \
    TEST_CASE("casefold - " NAME, "[compare][text][casefold]")           \
    {                                                                    \
        const text_case& text = text_case_for(FILE);                     \
        BENCHMARK("tinyuc")                                              \
        {                                                                \
            casefold_text_tinyuc(text.text);                             \
        };                                                               \
        TINYUC_COMPARE_TEXT_UTF8PROC_CASEFOLD(text)                      \
        TINYUC_COMPARE_TEXT_ICU_CASEFOLD(text)                           \
    }                                                                    \
    TEST_CASE("grapheme - " NAME, "[compare][text][grapheme]")           \
    {                                                                    \
        const text_case& text = text_case_for(FILE);                     \
        BENCHMARK("tinyuc")                                              \
        {                                                                \
            grapheme_text_tinyuc(text.text);                             \
        };                                                               \
        TINYUC_COMPARE_TEXT_UTF8PROC_GRAPHEME(text)                      \
        TINYUC_COMPARE_TEXT_ICU_GRAPHEME(text)                           \
    }                                                                    \
    TEST_CASE("validate - " NAME, "[compare][text][validate]")           \
    {                                                                    \
        const text_case& text = text_case_for(FILE);                     \
        BENCHMARK("tinyuc")                                              \
        {                                                                \
            validate_text_tinyuc(text.text);                             \
        };                                                               \
        TINYUC_COMPARE_TEXT_UTF8PROC_VALIDATE(text)                      \
        TINYUC_COMPARE_TEXT_ICU_VALIDATE(text)                           \
    }                                                                    \
    TEST_CASE("count - " NAME, "[compare][text][count]")                 \
    {                                                                    \
        const text_case& text = text_case_for(FILE);                     \
        BENCHMARK("tinyuc")                                              \
        {                                                                \
            count_text_tinyuc(text.text);                                \
        };                                                               \
        TINYUC_COMPARE_TEXT_UTF8PROC_COUNT(text)                         \
        TINYUC_COMPARE_TEXT_ICU_COUNT(text)                              \
    }

TINYUC_COMPARE_TEXT_SUITE("german", "Deutsch_.txt")
TINYUC_COMPARE_TEXT_SUITE("japanese", "Japanese_.txt")
TINYUC_COMPARE_TEXT_SUITE("korean", "Korean_.txt")
TINYUC_COMPARE_TEXT_SUITE("vietnamese", "Vietnamese_.txt")
