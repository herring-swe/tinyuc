/**
 * @file unicode.cpp
 *
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief unicode tests
 */

#include <tinyuc/unicode.h>

#include "ucd_corpus.h"

#include <doctest.h>

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifdef __INTELLISENSE__
#define NORM_TEST_FILE "dummy"
#define GRAPHEME_TEST_FILE "dummy"
#endif

typedef tinyuc_result (
    *mapping_func)(const char* str, size_t size, char** ostr, size_t* osize, char** errmsg);

static inline bool check_with_null(const char* input, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (input[i] == '\0')
            return true;
    }
    return false;
}

static void print_null(const char* input, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (input[i] == '\0')
            printf("\\0");
        else
            printf("%c", input[i]);
    }
    printf("\n");
}

static inline void test_basics(const char* input, size_t len, size_t num_cp, size_t num_chars)
{
    bool with_null = check_with_null(input, len);

    if (with_null)
        print_null(input, len);
    else
        printf("%s\n", input);
    if (!with_null)
        CHECK(len == strlen(input));
    REQUIRE(tinyuc_validate(input, len, nullptr) == TINYUC_OK);
    CHECK(tinyuc_num_cp(input, len) == num_cp);
    if (!with_null)
        CHECK(tinyuc_num_cp(input, TINYUC_NPOS) == num_cp);
    CHECK(tinyuc_num_char(input, len) == num_chars);
}

static inline void test_grapheme(const char* input, size_t len, size_t num_cp, size_t num_chars)
{
    bool with_null = check_with_null(input, len);

    if (with_null)
        print_null(input, len);
    else
        printf("%s\n", input);
    if (!with_null)
        CHECK(len == strlen(input));
    REQUIRE(tinyuc_validate(input, len, nullptr) == TINYUC_OK);
    CHECK(tinyuc_num_cp(input, len) == num_cp);
    CHECK(tinyuc_num_char(input, len) == num_chars);
    if (!with_null)
        CHECK(tinyuc_num_cp(input, TINYUC_NPOS) == num_cp);
}

static inline void test_mapping(const char* input,
                                const char* lower,
                                const char* upper,
                                const char* title,
                                const char* casefold)
{
    size_t len;
    enum tinyuc_result ucres;
    char* errmsg = nullptr;
    char* ostr = nullptr;
    size_t osize = 0;

    const char* strings[5] = {input, lower, upper, title, casefold};
    mapping_func func[5] = {nullptr,
                            tinyuc_to_lower,
                            tinyuc_to_upper,
                            tinyuc_to_title,
                            tinyuc_casefold};

    for (int i = 0; i < 5; i++)
    {
        len = strlen(strings[i]);
        REQUIRE(tinyuc_validate(strings[i], len, nullptr) == TINYUC_OK);
        REQUIRE(len == strlen(strings[i]));

        if (func[i] == nullptr)
            continue;

        ucres = func[i](strings[0], len, &ostr, &osize, &errmsg);
        CHECK(ucres == TINYUC_OK);
        CHECK(errmsg == nullptr);
        CHECK(ostr != nullptr);
        if (ostr)
        {
            CHECK(osize == strlen(strings[i]));
            CHECK(std::string(strings[i]) == std::string(ostr));
            free(ostr);
            ostr = nullptr;
            osize = 0;
        }
        if (errmsg)
        {
            free(errmsg);
            errmsg = nullptr;
        }
    }
}

static inline void test_norm(const char* input, const char* correct, tinyuc_norm_form type)
{
    char* errmsg = nullptr;
    char* ostr = nullptr;
    size_t osize = 0;
    enum tinyuc_result ucres = tinyuc_normalize(input, strlen(input), type, &ostr, &osize, &errmsg);
    std::string type_str(tinyuc_norm_form_to_str(type));

    CAPTURE(type_str);

    CHECK(ucres == TINYUC_OK);
    CHECK(errmsg == nullptr);

    std::stringstream ss_inp("");
    const unsigned char* inp_iter = reinterpret_cast<const unsigned char*>(input);
    uint32_t cp;
    while ((cp = tinyuc_iter_utf8(&inp_iter)))
    {
        int width = 4;
        if (cp > 0xFFFF)
            width = 6;
        ss_inp << std::setw(width) << std::setfill('0') << std::hex << cp << " ";
    }

    if (std::string(ostr) != std::string(correct))
    {
        const unsigned char* iter_res = reinterpret_cast<const unsigned char*>(ostr);
        const unsigned char* iter_cor = reinterpret_cast<const unsigned char*>(correct);
        uint32_t cp_res = 1;
        uint32_t cp_cor = 1;
        std::stringstream ss_res("");
        std::stringstream ss_cor("");

        do
        {
            int width = 4;
            if (cp_res > 0xFFFF || cp_cor > 0xFFFF)
                width = 6;
            if (cp_res)
                cp_res = tinyuc_iter_utf8(&iter_res);
            if (cp_cor)
                cp_cor = tinyuc_iter_utf8(&iter_cor);

            if (cp_res)
            {
                if (cp_cor && cp_res != cp_cor)
                    ss_res << "!!>";
                ss_res << std::setw(width) << std::setfill('0') << std::hex << cp_res << " ";
            }
            if (cp_cor)
            {
                if (cp_res && cp_res != cp_cor)
                    ss_cor << "!!>";
                ss_cor << std::setw(width) << std::setfill('0') << std::hex << cp_cor << " ";
            }
        } while (cp_res && cp_cor);

        std::string cps_res = ss_res.str();
        std::string cps_cor = ss_cor.str();
        CAPTURE(ss_inp.str());
        CAPTURE(cps_res);
        CAPTURE(cps_cor);
        REQUIRE(std::string(ostr) == std::string(correct));
    }
    free(ostr);
    free(errmsg);
}

static inline void test_norm_hex(const char* input, const char* hex_correct, tinyuc_norm_form type)
{
    const std::string correct = ucd_hex_to_utf8(hex_correct);
    test_norm(input, correct.c_str(), type);
}

TEST_SUITE_BEGIN("unicode");

TEST_CASE("unicode - basics")
{
    test_basics("", 0, 0, 0);
    test_basics("A", 1, 1, 1);
    test_basics("é", 2, 1, 1);       // 'é' as a single codepoint (e.g., U+00E9)
    test_basics("e\u0301", 3, 2, 1); // 'e' + combining acute accent (U+0301)
    test_basics("Hello", 5, 5, 5);
    test_basics("Héllø", 7, 5, 5);            // 'é' and 'ø' as single codepoints
    test_basics("Ž̌", 5, 3, 1);                // 'Z' + two combining carons (U+030C)
    test_basics("🌍", 4, 1, 1);               // Emoji (single codepoint)
    test_basics("a̐̀", 5, 3, 1);                // 'a' + two combining marks
    test_basics("日本語", 9, 3, 3);           // CJK ideographs (3 codepoints, 3 chars)
    test_basics("A\u0300\u0316", 5, 3, 1);    // 'A' + combining grave + combining inverted breve
    test_basics("\xF0\x9F\x98\x80", 4, 1, 1); // Grinning face emoji (U+1F600)
    test_basics("A\u0301B\u0302", 6, 4, 2);   // 'A' + acute, 'B' + circumflex
    test_basics("a\0b\0c", 5, 5, 5);          // String with embedded nulls
}

TEST_CASE("unicode - grapheme")
{
    test_grapheme("👨‍👩‍👧‍👦", 25, 7, 1); // Family emoji (ZWJ sequences)
    test_grapheme("🏳️‍🌈", 14, 4, 1);            // Gaydar flag (ZWJ + emoji)
    // Will not fail due to combining marks
    test_basics("©\uFE0F", 5, 2, 1);        // '©' + emoji variation selector
    test_basics("#\u20E3", 4, 2, 1);        // '#' + Combining Enclosing Keycap
    test_grapheme("👩‍💻", 11, 3, 1); // Woman technologist (ZWJ sequence)
    test_grapheme("🇺🇸", 8, 2, 1);           // US flag (regional indicator symbols)
    test_grapheme("🇺🇸🇫", 12, 3, 2);         // RI RI RI: first pair joins, third does not
    test_grapheme("👨🏽", 8, 2, 1);         // Man + medium skin tone modifier
    test_grapheme("\xF0\x9F\x91\xA8\xE2\x80\x8D\xF0\x9F\x91\xA9\xE2\x80\x8D\xF0\x9F\x91\xA6",
                  18,
                  5,
                  1);

    // Control characters
    test_grapheme("a\r\nb", 4, 4, 3); // CRLF is a single cluster

    // Indic conjunct: KA + VIRAMA (Linker) + SSA
    test_grapheme("\xE0\xA4\x95\xE0\xA5\x8D\xE0\xA4\xB7", 9, 3, 1);
}

TEST_CASE("unicode - mapping")
{
    test_mapping("Hello World!", "hello world!", "HELLO WORLD!", "Hello World!", "hello world!");
    test_mapping("Héllö Wörld!", "héllö wörld!", "HÉLLÖ WÖRLD!", "Héllö Wörld!", "héllö wörld!");
    test_mapping("straße", "straße", "STRAßE", "Straße", "strasse");

    test_mapping("O'Reilly", "o'reilly", "O'REILLY", "O'reilly", "o'reilly");
    test_mapping("Over-achiever",
                 "over-achiever",
                 "OVER-ACHIEVER",
                 "Over-achiever",
                 "over-achiever");
    test_mapping("Simply \"The Best\"",
                 "simply \"the best\"",
                 "SIMPLY \"THE BEST\"",
                 "Simply \"The Best\"",
                 "simply \"the best\"");
}

TEST_CASE("unicode - normalization")
{
    test_norm("Héllö Wörld!", "Héllö Wörld!", TINYUC_NORM_NFD);
    test_norm("Héllö Wörld!", "Héllö Wörld!", TINYUC_NORM_NFC);

    test_norm(
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏṐṑṒṓ"
        "ṔṕṖṗṘṙṚṛṜṝṞṟṠṡṢṣṤṥṦṧṨṩṪṫṬṭṮṯṰṱṲṳṴṵṶṷṸṹṺṻṼṽṾṿ",
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏṐṑṒṓ"
        "ṔṕṖṗṘṙṚṛṜṝṞṟṠṡṢṣṤṥṦṧṨṩṪṫṬṭṮṯṰṱṲṳṴṵṶṷṸṹṺṻṼṽṾṿ",
        TINYUC_NORM_NFD);
    test_norm_hex(
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏ",
        "41 325 61 325 42 307 62 307 42 323 62 323 42 331 62 331 43 327 301 63 327 301 44 307 64 "
        "307 44 323 64 323 44 331 64 331 44 327 64 327 44 32d 64 32d 45 304 300 65 304 300 45 "
        "304 301 65 304 301 45 32d 65 32d 45 330 65 330 45 327 306 65 327 306 46 307 66 307 47 "
        "304 67 304 48 307 68 307 48 323 68 323 48 308 68 308 48 327 68 327 48 32e 68 32e 49 "
        "330 69 330 49 308 301 69 308 301 4b 301 6b 301 4b 323 6b 323 4b 331 6b 331 4c 323 6c "
        "323 4c 323 304 6c 323 304 4c 331 6c 331 4c 32d 6c 32d 4d 301 6d 301 4d 307 6d 307 4d "
        "323 6d 323 4e 307 6e 307 4e 323 6e 323 4e 331 6e 331 4e 32d 6e 32d 4f 303 301 6f 303 "
        "301 4f 303 308 6f 303 308",
        TINYUC_NORM_NFKD);
    test_norm_hex(
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏ",
        "1e00 1e01 1e02 1e03 1e04 1e05 1e06 1e07 1e08 1e09 1e0a 1e0b 1e0c 1e0d 1e0e 1e0f 1e10 1e11 "
        "1e12 1e13 1e14 1e15 1e16 1e17 1e18 1e19 1e1a 1e1b 1e1c 1e1d 1e1e 1e1f 1e20 1e21 1e22 1e23 "
        "1e24 1e25 1e26 1e27 1e28 1e29 1e2a 1e2b 1e2c 1e2d 1e2e 1e2f 1e30 1e31 1e32 1e33 1e34 1e35 "
        "1e36 1e37 1e38 1e39 1e3a 1e3b 1e3c 1e3d 1e3e 1e3f 1e40 1e41 1e42 1e43 1e44 1e45 1e46 1e47 "
        "1e48 1e49 1e4a 1e4b 1e4c 1e4d 1e4e 1e4f",
        TINYUC_NORM_NFC);

    test_norm(
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏṐṑṒṓ"
        "ṔṕṖṗṘṙṚṛṜṝṞṟṠṡṢṣṤṥṦṧṨṩṪṫṬṭṮṯṰṱṲṳṴṵṶṷṸṹṺṻṼṽṾṿ",
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏṐṑṒṓ"
        "ṔṕṖṗṘṙṚṛṜṝṞṟṠṡṢṣṤṥṦṧṨṩṪṫṬṭṮṯṰṱṲṳṴṵṶṷṸṹṺṻṼṽṾṿ",
        TINYUC_NORM_NFD);
    test_norm(
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏṐṑṒṓ"
        "ṔṕṖṗṘṙṚṛṜṝṞṟṠṡṢṣṤṥṦṧṨṩṪṫṬṭṮṯṰṱṲṳṴṵṶṷṸṹṺṻṼṽṾṿ",
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏṐṑṒṓ"
        "ṔṕṖṗṘṙṚṛṜṝṞṟṠṡṢṣṤṥṦṧṨṩṪṫṬṭṮṯṰṱṲṳṴṵṶṷṸṹṺṻṼṽṾṿ",
        TINYUC_NORM_NFKD);
    test_norm(
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏṐṑṒṓ"
        "ṔṕṖṗṘṙṚṛṜṝṞṟṠṡṢṣṤṥṦṧṨṩṪṫṬṭṮṯṰṱṲṳṴṵṶṷṸṹṺṻṼṽṾṿ",
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏṐṑṒṓ"
        "ṔṕṖṗṘṙṚṛṜṝṞṟṠṡṢṣṤṥṦṧṨṩṪṫṬṭṮṯṰṱṲṳṴṵṶṷṸṹṺṻṼṽṾṿ",
        TINYUC_NORM_NFC);
    test_norm(
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏṐṑṒṓ"
        "ṔṕṖṗṘṙṚṛṜṝṞṟṠṡṢṣṤṥṦṧṨṩṪṫṬṭṮṯṰṱṲṳṴṵṶṷṸṹṺṻṼṽṾṿ",
        "ḀḁḂḃḄḅḆḇḈḉḊḋḌḍḎḏḐḑḒḓḔḕḖḗḘḙḚḛḜḝḞḟḠḡḢḣḤḥḦḧḨḩḪḫḬḭḮḯḰḱḲḳḴḵḶḷḸḹḺḻḼḽḾḿṀṁṂṃṄṅṆṇṈṉṊṋṌṍṎṏṐṑṒṓ"
        "ṔṕṖṗṘṙṚṛṜṝṞṟṠṡṢṣṤṥṦṧṨṩṪṫṬṭṮṯṰṱṲṳṴṵṶṷṸṹṺṻṼṽṾṿ",
        TINYUC_NORM_NFKC);

    // Hangul + Latin tests
    test_norm("가각 Héllö", "가각 Héllö", TINYUC_NORM_NFD);
    test_norm("가각 Héllö", "가각 Héllö", TINYUC_NORM_NFC);

    // Hangul + Latin + Combining Marks + Ligatures
    test_norm("갛é각Åﬁ가́̀Ź̌한글LigaturesﬃﬄﬅℵἄΩﬂῴ",
              "갛é각Åﬁ가́̀Ź̌한글LigaturesﬃﬄﬅℵἄΩﬂῴ",
              TINYUC_NORM_NFD);
    test_norm("갛é각Åﬁ가́̀Ź̌한글LigaturesﬃﬄﬅℵἄΩﬂῴ",
              "갛é각Åﬁ가́̀Ź̌한글LigaturesﬃﬄﬅℵἄΩﬂῴ",
              TINYUC_NORM_NFC);
    test_norm("갛é각Åﬁ가́̀Ź̌한글LigaturesﬃﬄﬅℵἄΩﬂῴ",
              "갛é각Åfi가́̀Ź̌한글LigaturesffifflstאἄΩflῴ",
              TINYUC_NORM_NFKC);
    test_norm("갛é각Åﬁ가́̀Ź̌한글LigaturesﬃﬄﬅℵἄΩﬂῴ",
              "갛é각Åfi가́̀Ź̌한글LigaturesffifflstאἄΩflῴ",
              TINYUC_NORM_NFKD);

    // Regression: a canonical segment (starter + non-starters) has no upper bound
    // and must not overflow the internal reorder window (previously a fixed 18).
    {
        std::string marks;
        for (int i = 0; i < 19; ++i)
            marks += "\xCC\x80"; // U+0300, ccc 230

        // NFC routes a bare combining run through the full algorithm (NFC_QC=Maybe).
        test_norm(marks.c_str(), marks.c_str(), TINYUC_NORM_NFC);

        // NFD with a decomposable starter forces the full path too:
        // U+00C0 -> 'A' + U+0300, then 19 more marks => 21 codepoint segment.
        std::string input = "\xC3\x80" + marks;
        std::string expected = "A";
        for (int i = 0; i < 20; ++i)
            expected += "\xCC\x80";
        test_norm(input.c_str(), expected.c_str(), TINYUC_NORM_NFD);

        // Canonical reordering across the window growth boundary:
        // 'a' + 30x U+0300 (ccc 230) + U+0316 (ccc 220) -> 'a' + U+0316 + 30x U+0300
        std::string order = "a";
        for (int i = 0; i < 30; ++i)
            order += "\xCC\x80"; // U+0300, ccc 230
        order += "\xCC\x96";     // U+0316, ccc 220
        std::string reordered = "a\xCC\x96";
        for (int i = 0; i < 30; ++i)
            reordered += "\xCC\x80";
        test_norm(order.c_str(), reordered.c_str(), TINYUC_NORM_NFD);
    }
}

TEST_CASE("unicode - official normalization test")
{
    std::vector<ucd_norm_case> tests;
    REQUIRE(ucd_load_normalization_tests(NORM_TEST_FILE, tests));

    std::string form;
    for (const auto& test : tests)
    {
        CAPTURE(test.test_no);
        CAPTURE(test.line_no);
        CAPTURE(test.part_name);
        CAPTURE(test.comment);
        CAPTURE(form);

        // NFD
        form = "NFD = toNFD(INPUT)";
        test_norm(test.input.c_str(), test.nfd.c_str(), TINYUC_NORM_NFD);
        form = "NFD = toNFD(NFC)";
        test_norm(test.nfc.c_str(), test.nfd.c_str(), TINYUC_NORM_NFD);
        form = "NFD = toNFD(NFD)";
        test_norm(test.nfd.c_str(), test.nfd.c_str(), TINYUC_NORM_NFD);
        form = "NFKD = toNFD(NFKC)";
        test_norm(test.nfkc.c_str(), test.nfkd.c_str(), TINYUC_NORM_NFD);
        form = "NFKD = toNFD(NFKD)";
        test_norm(test.nfkd.c_str(), test.nfkd.c_str(), TINYUC_NORM_NFD);

        // NFC
        form = "NFC = toNFC(INPUT)";
        test_norm(test.input.c_str(), test.nfc.c_str(), TINYUC_NORM_NFC);
        form = "NFC = toNFC(NFC)";
        test_norm(test.nfc.c_str(), test.nfc.c_str(), TINYUC_NORM_NFC);
        form = "NFC = toNFC(NFD)";
        test_norm(test.nfd.c_str(), test.nfc.c_str(), TINYUC_NORM_NFC);
        form = "NFKC = toNFC(NFKC)";
        test_norm(test.nfkc.c_str(), test.nfkc.c_str(), TINYUC_NORM_NFC);
        form = "NFKC = toNFC(NFKD)";
        test_norm(test.nfkd.c_str(), test.nfkc.c_str(), TINYUC_NORM_NFC);

        // NFKD
        form = "NFKD = toNFKD(INPUT)";
        test_norm(test.input.c_str(), test.nfkd.c_str(), TINYUC_NORM_NFKD);
        form = "NFKD = toNFKD(NFC)";
        test_norm(test.nfc.c_str(), test.nfkd.c_str(), TINYUC_NORM_NFKD);
        form = "NFKD = toNFKD(NFD)";
        test_norm(test.nfd.c_str(), test.nfkd.c_str(), TINYUC_NORM_NFKD);
        form = "NFKD = toNFKD(NFKC)";
        test_norm(test.nfkc.c_str(), test.nfkd.c_str(), TINYUC_NORM_NFKD);
        form = "NFKD = toNFKD(NFKD)";
        test_norm(test.nfkd.c_str(), test.nfkd.c_str(), TINYUC_NORM_NFKD);

        // NFKC
        form = "NFKC = toNFKC(INPUT)";
        test_norm(test.input.c_str(), test.nfkc.c_str(), TINYUC_NORM_NFKC);
        form = "NFKC = toNFKC(NFC)";
        test_norm(test.nfc.c_str(), test.nfkc.c_str(), TINYUC_NORM_NFKC);
        form = "NFKC = toNFKC(NFD)";
        test_norm(test.nfd.c_str(), test.nfkc.c_str(), TINYUC_NORM_NFKC);
        form = "NFKC = toNFKC(NFKC)";
        test_norm(test.nfkc.c_str(), test.nfkc.c_str(), TINYUC_NORM_NFKC);
        form = "NFKC = toNFKC(NFKD)";
        test_norm(test.nfkd.c_str(), test.nfkc.c_str(), TINYUC_NORM_NFKC);
    }

    std::cout << "Number of tests definitions: " << tests.size() << std::endl;
    std::cout << "Number of normalizations run: " << tests.size() * 20 << std::endl;
}

struct ucd_grapheme_test
{
    int line_no;
    int test_no;
    std::string input;
    std::vector<size_t> boundaries;
};

static void read_ucd_grapheme_tests(std::vector<ucd_grapheme_test>& tests)
{
    std::string line;
    std::ifstream ifs(GRAPHEME_TEST_FILE, std::ios::in);
    REQUIRE(ifs.is_open());

    int line_no = 0;
    int test_no = 0;

    while (std::getline(ifs, line))
    {
        line_no++;
        if (line.empty() || line.at(0) == '#')
            continue;

        size_t comment = line.find('#');
        if (comment != std::string::npos)
            line = line.substr(0, comment);

        std::istringstream ss(line);
        std::string token;

        ucd_grapheme_test data;
        data.line_no = line_no;
        data.test_no = ++test_no;

        size_t offset = 0;
        bool break_next = false;

        while (ss >> token)
        {
            if (token == "\xC3\xB7") // ÷ (U+00F7)
            {
                break_next = true;
            }
            else if (token == "\xC3\x97") // × (U+00D7)
            {
                break_next = false;
            }
            else
            {
                unsigned long cp = std::stoul(token, nullptr, 16);
                char buf[4];
                int n = tinyuc_encode_codepoint(reinterpret_cast<uint8_t*>(buf),
                                                static_cast<uint32_t>(cp));
                REQUIRE(n > 0);
                if (break_next && offset > 0)
                    data.boundaries.push_back(offset);
                data.input.append(buf, static_cast<size_t>(n));
                offset += static_cast<size_t>(n);
                break_next = false;
            }
        }

        if (!data.input.empty())
            tests.push_back(data);
    }
}

TEST_CASE("unicode - official grapheme break test")
{
    std::vector<ucd_grapheme_test> tests;
    read_ucd_grapheme_tests(tests);

    for (const auto& test : tests)
    {
        CAPTURE(test.test_no);
        CAPTURE(test.line_no);

        const char* str = test.input.data();
        size_t len = test.input.size();

        REQUIRE(tinyuc_validate(str, len, nullptr) == TINYUC_OK);

        std::vector<size_t> got;
        size_t pos = 0;
        size_t next;
        while ((next = tinyuc_next_char(str, len, pos)) != TINYUC_NPOS)
        {
            got.push_back(next);
            pos = next;
        }
        CHECK(got == test.boundaries);

        // One more cluster than interior boundaries
        CHECK(tinyuc_num_char(str, len) == test.boundaries.size() + 1);

        // char_index(n) returns the boundary ending the n-th cluster
        for (size_t i = 0; i < test.boundaries.size(); i++)
            CHECK(tinyuc_char_index(str, len, i + 1) == test.boundaries[i]);
        CHECK(tinyuc_char_index(str, len, test.boundaries.size() + 1) == len);
    }

    std::cout << "Number of grapheme break tests: " << tests.size() << std::endl;
}

TEST_CASE("unicode - validation")
{
    SUBCASE("valid strings")
    {
        const char* valid[] = {
            "",
            "A",
            "Hello, world",
            "H\xC3\xA9llo",             // é
            "\xE6\x97\xA5\xE6\x9C\xAC", // 日本
            "\xF0\x9F\x98\x80",         // 😀
        };
        for (const char* s : valid)
        {
            CHECK(tinyuc_validate(s, strlen(s), nullptr) == TINYUC_OK);
            CHECK(tinyuc_validate(s, TINYUC_NPOS, nullptr) == TINYUC_OK);
        }

        // Embedded null with explicit length
        CHECK(tinyuc_validate("a\0b", 3, nullptr) == TINYUC_OK);
    }

    SUBCASE("invalid strings")
    {
        struct bad_case
        {
            const char* label;
            const char* str;
            size_t len;
        };
        const bad_case cases[] = {
            {"overlong 2-byte", "\xC0\x80", 2},
            {"overlong 3-byte", "\xE0\x80\x80", 3},
            {"overlong 4-byte", "\xF0\x80\x80\x80", 4},
            {"surrogate", "\xED\xA0\x80", 3},
            {"out of range", "\xF4\x90\x80\x80", 4},
            {"stray continuation", "\x80", 1},
            {"invalid lead byte", "\xFF", 1},
            {"truncated 2-byte", "\xC3", 1},
            {"truncated 3-byte", "\xE2\x82", 2},
            {"truncated 4-byte", "\xF0\x9F\x98", 3},
            {"valid prefix then bad", "ab\xFF", 3},
        };

        for (const auto& c : cases)
        {
            CAPTURE(c.label);
            char* errmsg = nullptr;
            CHECK(tinyuc_validate(c.str, c.len, &errmsg) == TINYUC_INVALID_UTF8);
            REQUIRE(errmsg != nullptr);
            free(errmsg);
            errmsg = nullptr;
        }
    }
}

TEST_CASE("unicode - codepoint encoding")
{
    SUBCASE("encode boundaries")
    {
        struct enc_case
        {
            uint32_t cp;
            int len;
        };
        const enc_case cases[] = {
            {0x0000, 1},
            {0x007F, 1},
            {0x0080, 2},
            {0x07FF, 2},
            {0x0800, 3},
            {0xFFFF, 3},
            {0x10000, 4},
            {0x10FFFF, 4},
        };

        for (const auto& c : cases)
        {
            CAPTURE(c.cp);
            uint8_t buf[4] = {0};
            int len = tinyuc_encode_codepoint(buf, c.cp);
            CHECK(len == c.len);
            // Query length without writing must match
            CHECK(tinyuc_encode_codepoint(nullptr, c.cp) == c.len);

            // Round-trip through the iterator
            const unsigned char* iter = buf;
            CHECK(tinyuc_iter_utf8(&iter) == c.cp);
            CHECK(iter == buf + c.len);
        }
    }

    SUBCASE("encode invalid codepoint")
    {
        uint8_t buf[4] = {0};
        CHECK(tinyuc_encode_codepoint(buf, 0x110000) == -1);
        CHECK(tinyuc_encode_codepoint(nullptr, 0x110000) == -1);
        // Surrogates are not valid Unicode scalar values
        CHECK(tinyuc_encode_codepoint(buf, 0xD800) == -1);
        CHECK(tinyuc_encode_codepoint(buf, 0xDFFF) == -1);
    }

    SUBCASE("encode codepoints into buffer")
    {
        const uint32_t cps[] = {0x41, 0xE9, 0x1F600}; // A, é, 😀
        char buf[16] = {0};
        size_t len = 0;
        size_t npcp = 0;
        char* errmsg = nullptr;
        REQUIRE(tinyuc_encode_codepoints_buf(cps, 3, buf, 16, &len, &npcp, &errmsg) == TINYUC_OK);
        CHECK(errmsg == nullptr);
        CHECK(len == 7);
        CHECK(npcp == 3);
        CHECK(memcmp(buf, "A\xC3\xA9\xF0\x9F\x98\x80", 7) == 0);
    }

    SUBCASE("encode codepoints invalid")
    {
        const uint32_t bad[] = {0x41, 0x110000};
        char buf[16] = {0};
        size_t len = 0;
        size_t npcp = 0;
        char* errmsg = nullptr;
        CHECK(tinyuc_encode_codepoints_buf(bad, 2, buf, 16, &len, &npcp, &errmsg) ==
              TINYUC_INVALID_CODEPOINT);
        CHECK(errmsg != nullptr);
        CHECK(len == 1);
        CHECK(npcp == 1);
        CHECK(memcmp(buf, "A", 1) == 0);
        free(errmsg);
    }

    SUBCASE("iterator decodes multi-byte")
    {
        const unsigned char* iter =
            reinterpret_cast<const unsigned char*>("A\xC3\xA9\xF0\x9F\x98\x80");
        CHECK(tinyuc_iter_utf8(&iter) == 0x41);
        CHECK(tinyuc_iter_utf8(&iter) == 0xE9);
        CHECK(tinyuc_iter_utf8(&iter) == 0x1F600);
        CHECK(tinyuc_iter_utf8(&iter) == 0x00); // Null terminator terminates the walk
    }
}

TEST_CASE("unicode - counts")
{
    // Null input is tolerated and yields zero
    CHECK(tinyuc_num_cp(nullptr, 0) == 0);
    CHECK(tinyuc_num_char(nullptr, 0) == 0);

    const char* str = "e\u0301\xF0\x9F\x98\x80"; // é (combining) + 😀
    size_t len = strlen(str);
    CHECK(tinyuc_num_cp(str, len) == 3); // e, U+0301, U+1F600
    CHECK(tinyuc_num_cp(str, TINYUC_NPOS) == 3);
    CHECK(tinyuc_num_char(str, len) == 2); // one grapheme + emoji
    CHECK(tinyuc_num_char(str, TINYUC_NPOS) == 2);

    // Embedded null with explicit length is counted
    CHECK(tinyuc_num_cp("a\0b", 3) == 3);
    CHECK(tinyuc_num_char("a\0b", 3) == 3);

    // Regression: a buffer of exactly `len` bytes without a null terminator
    // must not be read past the end.
    {
        const char* src = "a\xF0\x9F\x98\x80"; // 5 bytes
        const size_t n = 5;
        char* buf = (char*)malloc(n);
        REQUIRE(buf != nullptr);
        memcpy(buf, src, n);
        CHECK(tinyuc_num_cp(buf, n) == 2);
        CHECK(tinyuc_num_char(buf, n) == 2);
        free(buf);
    }
}

TEST_CASE("unicode - character indexing")
{
    SUBCASE("tinyuc_char_index")
    {
        const char* str = "abcd";
        size_t len = 4;
        CHECK(tinyuc_char_index(str, len, 1) == 1);
        CHECK(tinyuc_char_index(str, len, 2) == 2);
        CHECK(tinyuc_char_index(str, len, 4) == 4);
        // Index 0 and out-of-range return the end of the string
        CHECK(tinyuc_char_index(str, len, 0) == len);
        CHECK(tinyuc_char_index(str, len, 99) == len);
        // Null string returns len (which is 0 here)
        CHECK(tinyuc_char_index(nullptr, 0, 1) == 0);
    }

    SUBCASE("tinyuc_next_char")
    {
        const char* str = "abcd";
        size_t len = 4;
        // Returns the boundary starting the *next* cluster
        CHECK(tinyuc_next_char(str, len, 0) == 1);
        CHECK(tinyuc_next_char(str, len, 1) == 2);
        CHECK(tinyuc_next_char(str, len, 2) == 3);
        // The final cluster has no following boundary
        CHECK(tinyuc_next_char(str, len, 3) == TINYUC_NPOS);
        CHECK(tinyuc_next_char(str, len, 4) == TINYUC_NPOS);
        CHECK(tinyuc_next_char(str, len, TINYUC_NPOS) == TINYUC_NPOS);
    }

    SUBCASE("char_index and next_char agree on graphemes")
    {
        const char* str = "e\u0301x\xF0\x9F\x98\x80"; // é, x, 😀
        size_t len = strlen(str);
        CHECK(tinyuc_num_char(str, len) == 3);
        CHECK(tinyuc_char_index(str, len, 1) == 3);
        CHECK(tinyuc_next_char(str, len, 0) == 3);
        CHECK(tinyuc_next_char(str, len, 3) == 4);
        CHECK(tinyuc_char_index(str, len, 3) == len);
        // No following boundary for the last cluster
        CHECK(tinyuc_next_char(str, len, 4) == TINYUC_NPOS);
        CHECK(tinyuc_next_char(str, len, len) == TINYUC_NPOS);
    }
}

TEST_CASE("unicode - case-insensitive comparison")
{
    CHECK(tinyuc_icomp("Hello", 5, "hello", 5) == 0);
    CHECK(tinyuc_icomp("ABC", 3, "abd", 3) < 0);
    CHECK(tinyuc_icomp("abd", 3, "ABC", 3) > 0);
    CHECK(tinyuc_icomp("ab", 2, "abc", 3) < 0);
    CHECK(tinyuc_icomp("abc", 3, "ab", 2) > 0);
    CHECK(tinyuc_icomp("H\xC3\xA9llo", 6, "h\xC3\xA9LLO", 6) == 0);
    CHECK(tinyuc_icomp("", 0, "", 0) == 0);

    // Codepoints that fold into several codepoints must still compare equal
    // 'ß' (U+00DF) folds to "ss"
    CHECK(tinyuc_icomp("stra\xC3\x9F"
                       "e",
                       7,
                       "STRASSE",
                       7) == 0);
    CHECK(tinyuc_icomp("stra\xC3\x9F"
                       "e",
                       7,
                       "strasse",
                       7) == 0);
    // 'İ' (U+0130) folds to 'i' + U+0307
    CHECK(tinyuc_icomp("\xC4\xB0", 2, "i\xCC\x87", 3) == 0);

    // Expansion ordering: "ß" folds to "ss", so it sorts after "s"
    CHECK(tinyuc_icomp("s", 1, "\xC3\x9F", 2) < 0);
    CHECK(tinyuc_icomp("\xC3\x9F", 2, "s", 1) > 0);
}

TEST_CASE("unicode - normalization forms")
{
    SUBCASE("enum to and from string")
    {
        CHECK(std::string(tinyuc_norm_form_to_str(TINYUC_NORM_NFC)) == "NFC");
        CHECK(std::string(tinyuc_norm_form_to_str(TINYUC_NORM_NFD)) == "NFD");
        CHECK(std::string(tinyuc_norm_form_to_str(TINYUC_NORM_NFKC)) == "NFKC");
        CHECK(std::string(tinyuc_norm_form_to_str(TINYUC_NORM_NFKD)) == "NFKD");
        CHECK(std::string(tinyuc_norm_form_to_str(TINYUC_NORM_INVALID)) == "");

        CHECK(tinyuc_norm_form_from_str("NFC") == TINYUC_NORM_NFC);
        CHECK(tinyuc_norm_form_from_str("nfd") == TINYUC_NORM_NFD);
        CHECK(tinyuc_norm_form_from_str("NfKc") == TINYUC_NORM_NFKC);
        CHECK(tinyuc_norm_form_from_str("NFKD") == TINYUC_NORM_NFKD);
        CHECK(tinyuc_norm_form_from_str("bogus") == TINYUC_NORM_INVALID);
        CHECK(tinyuc_norm_form_from_str("") == TINYUC_NORM_INVALID);
    }

    SUBCASE("normalize with TINYUC_NPOS length")
    {
        char* ostr = nullptr;
        size_t olen = 0;
        char* errmsg = nullptr;
        tinyuc_result res =
            tinyuc_normalize("He\u0301llo", TINYUC_NPOS, TINYUC_NORM_NFC, &ostr, &olen, &errmsg);
        REQUIRE(res == TINYUC_OK);
        REQUIRE(ostr != nullptr);
        REQUIRE(errmsg == nullptr);
        CHECK(std::string(ostr) == "H\xC3\xA9llo");
        CHECK(olen == 6);
        free(ostr);
        free(errmsg);
    }
}

TEST_CASE("unicode - mapping with explicit length")
{
    // Explicit length allows multiple null characters through the mapping.
    char* ostr = nullptr;
    size_t olen = 0;
    char* errmsg = nullptr;
    tinyuc_result res = tinyuc_to_upper("a\0b", 3, &ostr, &olen, &errmsg);
    REQUIRE(res == TINYUC_OK);
    REQUIRE(ostr != nullptr);
    REQUIRE(errmsg == nullptr);
    CHECK(olen == 3);
    CHECK(ostr[0] == 'A');
    CHECK(ostr[1] == '\0');
    CHECK(ostr[2] == 'B');
    free(ostr);
    free(errmsg);
}

TEST_SUITE_END();
