/**
 * @file ucd_corpus.h
 *
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Shared loader for the official UCD NormalizationTest corpus.
 *
 * Used by both the unit tests and the benchmarks so the text-to-UTF-8 parsing
 * lives in one place.
 */

#ifndef TINYUC_TESTS_UCD_CORPUS_H
#define TINYUC_TESTS_UCD_CORPUS_H

#include <string>
#include <vector>

/**
 * @brief One NormalizationTest.txt entry.
 *
 * The five source forms are decoded to UTF-8. Metadata (line number, test
 * number, part name and trailing comment) is kept for test diagnostics.
 */
struct ucd_norm_case
{
    int line_no = 0;
    int test_no = 0;
    std::string part_name;
    std::string input;
    std::string nfc;
    std::string nfd;
    std::string nfkc;
    std::string nfkd;
    std::string comment;
};

/**
 * @brief Decode whitespace separated hex code points (e.g. "41 325 61") to UTF-8.
 */
std::string ucd_hex_to_utf8(const char* hex);

/**
 * @brief Load and decode the UCD NormalizationTest corpus.
 *
 * Malformed data lines are skipped. Comment and part header lines are parsed
 * but never emitted as test cases.
 *
 * @param path path to NormalizationTest.txt
 * @param tests receives the parsed cases; cleared first
 * @return false if the file could not be opened
 */
bool ucd_load_normalization_tests(const char* path, std::vector<ucd_norm_case>& tests);

/**
 * @brief Load the UCD GraphemeBreakTest corpus as one UTF-8 buffer.
 *
 * Test cases are separated by a newline, which forces a cluster boundary and
 * prevents adjacent cases from merging. Comment and part header lines are
 * ignored.
 *
 * @param path path to GraphemeBreakTest.txt
 * @param buffer receives the decoded corpus; cleared first
 * @return false if the file could not be opened
 */
bool ucd_load_grapheme_buffer(const char* path, std::string& buffer);

#ifdef TINYUC_BENCH_TEXT_DIR
/**
 * @brief One language benchmark text file.
 */
struct ucd_language_text
{
    std::string file;
    std::string name;
    std::string text;
};

/**
 * @brief Load the language benchmark texts from data/benchmark.zip.
 *
 * The files are extracted by CMake into TINYUC_BENCH_TEXT_DIR. Text is read
 * as-is so LF line endings and the original UTF-8 encoding are preserved.
 */
const std::vector<ucd_language_text>& ucd_language_texts();
#endif

#endif // TINYUC_TESTS_UCD_CORPUS_H
