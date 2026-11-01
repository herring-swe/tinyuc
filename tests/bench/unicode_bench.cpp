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

#include "unicode_bench.h"

#include "tinyuc/unicode.h"

#include "microbench.h"
#include "private/utf8_iter.h"
#include "ucd_corpus.h"

#ifdef TINYUC_BENCH_UTF8PROC
#include <utf8proc.h>
#endif

#ifdef TINYUC_BENCH_ICU
#if defined(_WIN32)
// The in-box Windows ICU only ships the merged C header.
#include <icu.h>
#else
#include <unicode/unorm2.h>
#include <unicode/ustring.h>
#endif
#endif

#include <array>
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#ifdef __INTELLISENSE__
#ifndef NORM_TEST_FILE
#define NORM_TEST_FILE "dummy"
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

void normalize_quick()
{
    normalize_corpus(tinyuc_normalize);
}

void normalize_without_quickpath()
{
    normalize_corpus(tinyuc_normalize_full);
}

#ifdef TINYUC_BENCH_UTF8PROC
/// Map a TINYUC normalization form to the equivalent utf8proc option flags.
unsigned int utf8proc_options(enum tinyuc_norm_form form)
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

void normalize_corpus_utf8proc()
{
    normalize_corpus_with([](const std::string& source, enum tinyuc_norm_form form) -> std::size_t {
        utf8proc_uint8_t* dest = nullptr;
        const utf8proc_ssize_t result =
            utf8proc_map(reinterpret_cast<const utf8proc_uint8_t*>(source.data()),
                         static_cast<utf8proc_ssize_t>(source.size()),
                         &dest,
                         utf8proc_options(form));
        std::size_t size = 0;
        if (result >= 0)
            size = static_cast<std::size_t>(result);
        utf8proc_free(dest);
        return size;
    });
}
#endif // TINYUC_BENCH_UTF8PROC

#ifdef TINYUC_BENCH_ICU
/// Resolve (and cache) the ICU normalizer for a TINYUC normalization form.
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

/// Convert UTF-8 to UTF-16 using the ICU size-first pattern: the first call
/// only asks for the required length. Leaves a NUL terminator in `dest`.
bool icu_utf8_to_utf16(const std::string& source, int32_t& utf16_len, std::vector<UChar>& dest)
{
    const int32_t src_len = static_cast<int32_t>(source.size());
    UErrorCode status = U_ZERO_ERROR;
    u_strFromUTF8(nullptr, 0, &utf16_len, source.data(), src_len, &status);
    if (utf16_len < 0)
        return false;

    dest.resize(static_cast<std::size_t>(utf16_len) + 1);
    status = U_ZERO_ERROR;
    u_strFromUTF8(dest.data(), utf16_len + 1, &utf16_len, source.data(), src_len, &status);
    return U_SUCCESS(status);
}

void normalize_corpus_icu()
{
    normalize_corpus_with([](const std::string& source, enum tinyuc_norm_form form) -> std::size_t {
        const UNormalizer2* const normalizer = icu_normalizer_for(form);
        if (normalizer == nullptr)
            return 0;

        std::vector<UChar> utf16;
        int32_t utf16_len = 0;
        if (!icu_utf8_to_utf16(source, utf16_len, utf16))
            return 0;

        UErrorCode status = U_ZERO_ERROR;
        const int32_t norm_len =
            unorm2_normalize(normalizer, utf16.data(), utf16_len, nullptr, 0, &status);
        if (norm_len < 0)
            return 0;

        std::vector<UChar> normalized(static_cast<std::size_t>(norm_len) + 1);
        status = U_ZERO_ERROR;
        unorm2_normalize(normalizer,
                         utf16.data(),
                         utf16_len,
                         normalized.data(),
                         norm_len + 1,
                         &status);
        if (U_FAILURE(status))
            return 0;

        int32_t utf8_len = 0;
        status = U_ZERO_ERROR;
        u_strToUTF8(nullptr, 0, &utf8_len, normalized.data(), norm_len, &status);
        return utf8_len > 0 ? static_cast<std::size_t>(utf8_len) : 0;
    });
}
#endif // TINYUC_BENCH_ICU

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

/// Count codepoints in both buffers with one decoder implementation.
template <typename Count>
std::uint64_t count_both(Count count)
{
    return static_cast<std::uint64_t>(count(ascii_buffer().data(), ascii_buffer().size())) +
           static_cast<std::uint64_t>(count(corpus_buffer().data(), corpus_buffer().size()));
}

void decode_pass()
{
    g_iter_sink += decode_sum(ascii_buffer(), tinyuc_utf8_decode);
    g_iter_sink += decode_sum(corpus_buffer(), tinyuc_utf8_decode);
}

void count_pass()
{
    g_iter_sink += count_both(tinyuc_utf8_count);
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

/// Validate both buffers through the library (SIMD when built with TINYUC_SIMD).
void validate_lib_pass()
{
    g_iter_sink +=
        (tinyuc_validate(ascii_buffer().data(), ascii_buffer().size(), nullptr) == TINYUC_OK);
    g_iter_sink +=
        (tinyuc_validate(corpus_buffer().data(), corpus_buffer().size(), nullptr) == TINYUC_OK);
}

/// Validate both buffers with the portable reference above.
void validate_scalar_pass()
{
    g_iter_sink += scalar_validate(ascii_buffer().data(), ascii_buffer().size());
    g_iter_sink += scalar_validate(corpus_buffer().data(), corpus_buffer().size());
}

/// Count both buffers through the library (SIMD when built with TINYUC_SIMD).
void count_lib_pass()
{
    g_iter_sink += (std::uint64_t)tinyuc_num_cp(ascii_buffer().data(), ascii_buffer().size());
    g_iter_sink += (std::uint64_t)tinyuc_num_cp(corpus_buffer().data(), corpus_buffer().size());
}

} // namespace

void register_unicode_benchmarks(tinyuc::microbench::benchmark& bench)
{
    tinyuc::microbench::suite& suite = bench.add_suite(
        "unicode",
        "Unicode normalization over the official UCD NormalizationTest corpus. A call normalizes "
        "the whole corpus, so compare per-corpus time; characters per second is not meaningful.");

    tinyuc::microbench::test& quick =
        suite.add_test("normalization",
                       "Convert every corpus entry from every source form into NFD, NFC, NFKD and "
                       "NFKC using the quick check fast path",
                       normalize_quick);
    suite.add_test("normalization-without-quickpath",
                   "Same conversions with the quick check disabled, always running the full "
                   "decomposition/composition algorithm",
                   normalize_without_quickpath);

    quick.add_ref("normalization-without-quickpath", tinyuc::microbench::expectation::faster);

#ifdef TINYUC_BENCH_UTF8PROC
    suite.add_test("normalization-utf8proc",
                   "Same conversions using utf8proc (utf8proc_map over the whole corpus)",
                   normalize_corpus_utf8proc);
    quick.add_ref("normalization-utf8proc", tinyuc::microbench::expectation::none);
#endif

#ifdef TINYUC_BENCH_ICU
    suite.add_test("normalization-icu",
                   "Same conversions using ICU (UTF-8 to UTF-16, normalize, back to UTF-8)",
                   normalize_corpus_icu);
    quick.add_ref("normalization-icu", tinyuc::microbench::expectation::none);
#endif

    tinyuc::microbench::suite& iter = bench.add_suite(
        "utf8-decoder",
        "UTF-8 decoder and counter. Each call scans an ASCII-heavy ~1 MiB buffer and the "
        "concatenated UCD corpus.");

    iter.add_test("decode", "Branch-chain decoder: sum codepoints", decode_pass);
    iter.add_test("count", "Scalar count over the same buffers", count_pass);

    tinyuc::microbench::suite& simd = bench.add_suite(
        "utf8-simd",
        "SIMD-accelerated UTF-8 paths (controlled by -DTINYUC_SIMD, default AUTO). The library "
        "rows use the best tier the CPU supports; the scalar rows are independent references. "
        "Each call scans the same ASCII-heavy ~1 MiB buffer and concatenated corpus.");

    tinyuc::microbench::test& validate_lib =
        simd.add_test("validate-lib", "tinyuc_validate over both buffers", validate_lib_pass);
    simd.add_test("validate-scalar",
                  "Portable reference validator over the same buffers",
                  validate_scalar_pass);
    validate_lib.add_ref("validate-scalar", tinyuc::microbench::expectation::none);

    tinyuc::microbench::test& count_lib =
        simd.add_test("count-lib", "tinyuc_num_cp over both buffers", count_lib_pass);
    simd.add_test("count-scalar", "Portable scalar count over the same buffers", count_pass);
    count_lib.add_ref("count-scalar", tinyuc::microbench::expectation::none);
}
