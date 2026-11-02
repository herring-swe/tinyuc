/**
 * @file unicode_bench.cpp
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Benchmarks for unicode normalization with and without the quick check
 * fast path, over the official UCD NormalizationTest corpus. When
 * TINYUC_BENCH_COMPARE is enabled the same workload is also run through utf8proc
 * and ICU for comparison.
 */

#include "tinyuc/unicode.h"

#include "private/utf8_iter.h"
#include "ucd_corpus.h"

#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/catch_test_macros.hpp>

#include <cstddef>
#include <cstdint>
#include <string>
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

volatile std::uint64_t g_norm_sink = 0;

/// Load and decode the official NormalizationTest corpus once.
const std::vector<ucd_norm_case>& corpus()
{
    static const std::vector<ucd_norm_case> tests = [] {
        std::vector<ucd_norm_case> loaded;
        ucd_load_normalization_tests(NORM_TEST_FILE, loaded);
        return loaded;
    }();
    return tests;
}

/// Decoded GraphemeBreakTest corpus, with a newline between test cases.
const std::string& grapheme_buffer()
{
    static const std::string buffer = [] {
        std::string loaded;
        ucd_load_grapheme_buffer(GRAPHEME_TEST_FILE, loaded);
        return loaded;
    }();
    return buffer;
}

/// Run every corpus entry from every source form through all four
/// normalization forms, mirroring the official normalization test. `convert`
/// performs one conversion and returns the number of result bytes, which is
/// folded into a shared sink so the work cannot be optimized away.
template <typename Convert>
void normalize_corpus_with(Convert convert)
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
    g_norm_sink = g_norm_sink + sink;
}

using norm_func =
    tinyuc_result (*)(const char*, size_t, enum tinyuc_norm_form, char**, size_t*, char**);

void normalize_corpus(norm_func fn)
{
    normalize_corpus_with(
        [fn](const std::string& source, enum tinyuc_norm_form form) -> std::size_t {
            char* norm_str = nullptr;
            size_t norm_len = 0;
            const enum tinyuc_result result =
                fn(source.c_str(), source.size(), form, &norm_str, &norm_len, nullptr);
            if (result != TINYUC_OK)
                norm_len = 0;
            free(norm_str);
            return norm_len;
        });
}

/* -------------------------------------------------------------------------- */
/*                            UTF-8 iterator A/B                              */
/* -------------------------------------------------------------------------- */

volatile std::uint64_t g_iter_sink = 0;

/// ~1 MiB of ASCII-heavy text, the common case for real-world input.
const std::string& ascii_buffer()
{
    static const std::string data = [] {
        static const char unit[] = "The quick brown fox jumps over the lazy dog. 0123456789\n";
        std::string text;
        text.reserve(1u << 20);
        while (text.size() < (1u << 20))
            text += unit;
        return text;
    }();
    return data;
}

/// All five source forms of every corpus entry concatenated (non-ASCII heavy).
const std::string& corpus_buffer()
{
    static const std::string data = [] {
        std::string text;
        for (const ucd_norm_case& test : corpus())
        {
            text += test.input;
            text += test.nfc;
            text += test.nfd;
            text += test.nfkc;
            text += test.nfkd;
        }
        return text;
    }();
    return data;
}

/// Sum every codepoint via a decoder so the work cannot be optimized away.
template <typename Decode>
std::uint64_t decode_sum(const std::string& text, Decode decode)
{
    const unsigned char* iter = reinterpret_cast<const unsigned char*>(text.data());
    const unsigned char* const last = iter + text.size();
    std::uint64_t sum = 0;
    while (iter < last)
        sum += decode(&iter);
    return sum;
}

/* -------------------------------------------------------------------------- */
/*                              SIMD validation                               */
/* -------------------------------------------------------------------------- */

/// Scalar reference validator (independent of the library implementation).
bool scalar_validate(const char* text, size_t len)
{
    const unsigned char* b = reinterpret_cast<const unsigned char*>(text);
    size_t i = 0;
    while (i < len)
    {
        unsigned c = b[i];
        if (c < 0x80)
        {
            i++;
        }
        else if ((c & 0xE0u) == 0xC0u)
        {
            if (i + 1 >= len || (b[i + 1] & 0xC0u) != 0x80u)
                return false;
            i += 2;
        }
        else if ((c & 0xF0u) == 0xE0u)
        {
            if (i + 2 >= len || (b[i + 1] & 0xC0u) != 0x80u || (b[i + 2] & 0xC0u) != 0x80u)
                return false;
            i += 3;
        }
        else if ((c & 0xF8u) == 0xF0u)
        {
            if (i + 3 >= len || (b[i + 1] & 0xC0u) != 0x80u || (b[i + 2] & 0xC0u) != 0x80u ||
                (b[i + 3] & 0xC0u) != 0x80u)
                return false;
            i += 4;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void normalize_language_text(const std::string& text, norm_func fn)
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
    g_norm_sink = g_norm_sink + sink;
}

void casefold_language_text(const std::string& text)
{
    char* result = nullptr;
    std::size_t result_len = 0;
    if (tinyuc_casefold(text.data(), text.size(), &result, &result_len, nullptr) == TINYUC_OK)
        g_norm_sink += result_len;
    free(result);
}

void grapheme_language_text(const std::string& text)
{
    g_iter_sink += static_cast<std::uint64_t>(tinyuc_num_char(text.data(), text.size()));
}

void validate_language_text(const std::string& text)
{
    g_iter_sink += tinyuc_validate(text.data(), text.size(), nullptr) == TINYUC_OK ? 1 : 0;
}

void count_language_text(const std::string& text)
{
    g_iter_sink += static_cast<std::uint64_t>(tinyuc_num_cp(text.data(), text.size()));
}

#ifdef TINYUC_BENCH_TEXT_DIR
const ucd_language_text& language_text(const char* file)
{
    for (const ucd_language_text& text : ucd_language_texts())
    {
        if (text.file == file)
            return text;
    }

    static const ucd_language_text empty;
    return empty;
}
#endif

} // namespace

TEST_CASE("normalization", "[benchmark][unicode][normalization]")
{
    BENCHMARK("normalization")
    {
        normalize_corpus(tinyuc_normalize);
    };

    BENCHMARK("normalization-without-quickpath")
    {
        normalize_corpus(tinyuc_normalize_full);
    };
}

TEST_CASE("grapheme", "[benchmark][unicode][grapheme]")
{
    BENCHMARK("count")
    {
        g_iter_sink += static_cast<std::uint64_t>(
            tinyuc_num_char(grapheme_buffer().data(), grapheme_buffer().size()));
    };

    BENCHMARK("iterate")
    {
        const std::string& text = grapheme_buffer();
        std::size_t offset = 0;
        std::size_t count = 0;
        while (offset < text.size())
        {
            offset = tinyuc_next_char(text.data(), text.size(), offset);
            if (offset == TINYUC_NPOS)
                break;
            ++count;
        }
        g_iter_sink += static_cast<std::uint64_t>(count);
    };
}

TEST_CASE("utf8-simd", "[benchmark][unicode][utf8-simd]")
{
    /// Validate both buffers through the library (SIMD when built with TINYUC_SIMD).
    BENCHMARK("validate-lib")
    {
        g_iter_sink +=
            (tinyuc_validate(ascii_buffer().data(), ascii_buffer().size(), nullptr) == TINYUC_OK);
        g_iter_sink +=
            (tinyuc_validate(corpus_buffer().data(), corpus_buffer().size(), nullptr) == TINYUC_OK);
    };

    /// Validate both buffers with the portable reference above.
    BENCHMARK("validate-scalar")
    {
        g_iter_sink += scalar_validate(ascii_buffer().data(), ascii_buffer().size());
        g_iter_sink += scalar_validate(corpus_buffer().data(), corpus_buffer().size());
    };

    /// Count both buffers through the library (SIMD when built with TINYUC_SIMD).
    BENCHMARK("count-lib")
    {
        g_iter_sink += (std::uint64_t)tinyuc_num_cp(ascii_buffer().data(), ascii_buffer().size());
        g_iter_sink += (std::uint64_t)tinyuc_num_cp(corpus_buffer().data(), corpus_buffer().size());
    };

    BENCHMARK("count-scalar")
    {
        g_iter_sink +=
            (std::uint64_t)tinyuc_utf8_count(ascii_buffer().data(), ascii_buffer().size());
        g_iter_sink +=
            (std::uint64_t)tinyuc_utf8_count(corpus_buffer().data(), corpus_buffer().size());
    };
}

#ifdef TINYUC_BENCH_TEXT_DIR
#define TINYUC_LANGUAGE_BENCHMARK(NAME, FILE)                                         \
    TEST_CASE("normalization - " NAME, "[benchmark][large][" NAME "][normalization]") \
    {                                                                                 \
        const ucd_language_text& text = language_text(FILE);                          \
        BENCHMARK("normalization")                                                    \
        {                                                                             \
            normalize_language_text(text.text, tinyuc_normalize);                     \
        };                                                                            \
        BENCHMARK("normalization-without-quickpath")                                  \
        {                                                                             \
            normalize_language_text(text.text, tinyuc_normalize_full);                \
        };                                                                            \
    }                                                                                 \
    TEST_CASE("casefold - " NAME, "[benchmark][large][" NAME "][casefold]")           \
    {                                                                                 \
        const ucd_language_text& text = language_text(FILE);                          \
        BENCHMARK("casefold")                                                         \
        {                                                                             \
            casefold_language_text(text.text);                                        \
        };                                                                            \
    }                                                                                 \
    TEST_CASE("grapheme - " NAME, "[benchmark][large][" NAME "][grapheme]")           \
    {                                                                                 \
        const ucd_language_text& text = language_text(FILE);                          \
        BENCHMARK("count")                                                            \
        {                                                                             \
            grapheme_language_text(text.text);                                        \
        };                                                                            \
    }                                                                                 \
    TEST_CASE("validate - " NAME, "[benchmark][large][" NAME "][validate]")           \
    {                                                                                 \
        const ucd_language_text& text = language_text(FILE);                          \
        BENCHMARK("validate")                                                         \
        {                                                                             \
            validate_language_text(text.text);                                        \
        };                                                                            \
    }                                                                                 \
    TEST_CASE("count - " NAME, "[benchmark][large][" NAME "][count]")                 \
    {                                                                                 \
        const ucd_language_text& text = language_text(FILE);                          \
        BENCHMARK("count")                                                            \
        {                                                                             \
            count_language_text(text.text);                                           \
        };                                                                            \
    }

TINYUC_LANGUAGE_BENCHMARK("german", "Deutsch_.txt")
TINYUC_LANGUAGE_BENCHMARK("japanese", "Japanese_.txt")
TINYUC_LANGUAGE_BENCHMARK("korean", "Korean_.txt")
TINYUC_LANGUAGE_BENCHMARK("vietnamese", "Vietnamese_.txt")
#endif // TINYUC_BENCH_TEXT_DIR
