/*
 * WARNING: This file is auto-generated. Do not edit.
 * This file is part of the TinyUC project
 * SPDX-FileCopyrightText: 2026 Åke Svedin <ake@svedin.org>
 * SPDX-License-Identifier: MIT
 * SPDX-FileCopyrightText: © 1991-2025 Unicode, Inc.
 * SPDX-License-Identifier: Unicode-DFS-2016
 *
 * This file includes data derived from the Unicode Character Database.
 * For the full license, see https://www.unicode.org/license.txt.
 */

#ifndef TINYUC_DATA_UNICODE_TABLE_H
#define TINYUC_DATA_UNICODE_TABLE_H

#include "unicode_defines.h"

#include <stdint.h>

/**
 * Property flags
 */
#define TINYUCD_PROP_DEFAULT 0x0  // No special flags
#define TINYUCD_PROP_COMPEXCL 0x1 // Excluded from composition
#define TINYUCD_PROP_COMPMAYBE \
    0x2                         // Can compose with a preceding starter (NFC/NFKC quick check maybe)
#define TINYUCD_PROP_NFKCNO 0x4 // Not in NFKC form, i.e. NFKC(cp) != cp

// Main property table
typedef struct
{
    uint8_t flags : 3;     // Property flags (max 3 flags)
    uint8_t category : 5;  // General category (max 31)
    uint8_t ccc;           // Canonical combining class
    uint8_t gcb : 5;       // Grapheme cluster break (max 31)
    uint8_t incb : 2;      // Indic conjunct break (max 3)
    uint8_t extpict : 1;   // Extended_Pictographic
    uint16_t mapping_idx;  // Index of mapping table + 1
    uint16_t decomp_idx;   // Index of decomposition table + 1
    uint16_t combiner_idx; // Index of combiner table + 1

} tinyucd_prop;

static const tinyucd_prop s_tinyucd_prop_table[TINYUCD_NUM_PROPERTIES] = {
    {0, TINYUCD_GC_CN, 0, 0, 0, 0, 0, 0, 0},        // Default properties, no assigned codepoints
    {0, TINYUCD_GC_CC, 0, 3, 0, 0, 0, 0, 0},        // 63 codepoints in range [0x0000, 0x009F]
    {0, TINYUCD_GC_CC, 0, 2, 0, 0, 0, 0, 0},        // 0x000A
    {0, TINYUCD_GC_CC, 0, 1, 0, 0, 0, 0, 0},        // 0x000D
    {0, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 0, 0},        // 2 codepoints in range [0x0020, 0x1680]
    {0, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 0, 0},        // 579 codepoints in range [0x0021, 0x01E95F]
    {0, TINYUCD_GC_SC, 0, 0, 0, 0, 0, 0, 0},        // 56 codepoints in range [0x0024, 0x01ECB0]
    {0, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 0, 0},        // 58 codepoints in range [0x0028, 0xFD3F]
    {0, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 0, 0},        // 56 codepoints in range [0x0029, 0xFD3E]
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 0},        // 826 codepoints in range [0x002B, 0x01F8D8]
    {0, TINYUCD_GC_PD, 0, 0, 0, 0, 0, 0, 0},        // 20 codepoints in range [0x002D, 0x010EAD]
    {0, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 0, 0},        // 690 codepoints in range [0x0030, 0x01E959]
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 1},        // '<'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 2},        // '='
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 3},        // '>'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1, 0, 4},        // 'A'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2, 0, 5},        // 'B'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 3, 0, 6},        // 'C'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 4, 0, 7},        // 'D'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 5, 0, 8},        // 'E'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 6, 0, 9},        // 'F'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 7, 0, 10},       // 'G'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 8, 0, 11},       // 'H'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 9, 0, 12},       // 'I'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 10, 0, 13},      // 'J'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 11, 0, 14},      // 'K'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 12, 0, 15},      // 'L'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 13, 0, 16},      // 'M'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 14, 0, 17},      // 'N'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 15, 0, 18},      // 'O'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 16, 0, 19},      // 'P'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 17, 0, 0},       // 'Q'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 18, 0, 20},      // 'R'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 19, 0, 21},      // 'S'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 20, 0, 22},      // 'T'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 21, 0, 23},      // 'U'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 22, 0, 24},      // 'V'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 23, 0, 25},      // 'W'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 24, 0, 26},      // 'X'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 25, 0, 27},      // 'Y'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 26, 0, 28},      // 'Z'
    {0, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 0, 0},        // 88 codepoints in range [0x005E, 0xFBC2]
    {0, TINYUCD_GC_PC, 0, 0, 0, 0, 0, 0, 0},        // 4 codepoints in range [0x005F, 0x2054]
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 27, 0, 29},      // 'a'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 28, 0, 30},      // 'b'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 29, 0, 31},      // 'c'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 30, 0, 32},      // 'd'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 31, 0, 33},      // 'e'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 32, 0, 34},      // 'f'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 33, 0, 35},      // 'g'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 34, 0, 36},      // 'h'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 35, 0, 37},      // 'i'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 36, 0, 38},      // 'j'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 37, 0, 39},      // 'k'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 38, 0, 40},      // 'l'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 39, 0, 41},      // 'm'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 40, 0, 42},      // 'n'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 41, 0, 43},      // 'o'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 42, 0, 44},      // 'p'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 43, 0, 0},       // 'q'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 44, 0, 45},      // 'r'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 45, 0, 46},      // 's'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 46, 0, 47},      // 't'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 47, 0, 48},      // 'u'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 48, 0, 49},      // 'v'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 49, 0, 50},      // 'w'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 50, 0, 51},      // 'x'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 51, 0, 52},      // 'y'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 52, 0, 53},      // 'z'
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1, 0},        // 0x00A0
    {0, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 0, 0},        // 5140 codepoints in range [0x00A6, 0x01FBFA]
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 2, 54},       // 0x00A8
    {0, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 0, 0},        // 1364 codepoints in range [0x00A9, 0x01FAF8]
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3, 0},        // 0x00AA
    {0, TINYUCD_GC_PI, 0, 0, 0, 0, 0, 0, 0},        // 12 codepoints in range [0x00AB, 0x2E20]
    {0, TINYUCD_GC_CF, 0, 3, 0, 0, 0, 0, 0},        // 59 codepoints in range [0x00AD, 0x0E0001]
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 4, 0},        // 0x00AF
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5, 0},        // '²'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 6, 0},        // '³'
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 7, 0},        // 0x00B4
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 53, 8, 0},       // 'µ'
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 9, 0},        // 0x00B8
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 10, 0},       // '¹'
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 11, 0},       // 0x00BA
    {0, TINYUCD_GC_PF, 0, 0, 0, 0, 0, 0, 0},        // 10 codepoints in range [0x00BB, 0x2E21]
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 12, 0},       // '¼'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 13, 0},       // '½'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 14, 0},       // '¾'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 54, 15, 0},      // 'À'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 55, 16, 0},      // 'Á'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 56, 17, 55},     // 'Â'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 57, 18, 0},      // 'Ã'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 58, 19, 56},     // 'Ä'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 59, 20, 57},     // 'Å'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 60, 0, 58},      // 'Æ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 61, 21, 59},     // 'Ç'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 62, 22, 0},      // 'È'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 63, 23, 0},      // 'É'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 64, 24, 60},     // 'Ê'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 65, 25, 0},      // 'Ë'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 66, 26, 0},      // 'Ì'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 67, 27, 0},      // 'Í'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 68, 28, 0},      // 'Î'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 69, 29, 61},     // 'Ï'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 70, 0, 0},       // 'Ð'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 71, 30, 0},      // 'Ñ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 72, 31, 0},      // 'Ò'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 73, 32, 0},      // 'Ó'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 74, 33, 62},     // 'Ô'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 75, 34, 63},     // 'Õ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 76, 35, 64},     // 'Ö'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 77, 0, 65},      // 'Ø'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 78, 36, 0},      // 'Ù'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 79, 37, 0},      // 'Ú'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 80, 38, 0},      // 'Û'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 81, 39, 66},     // 'Ü'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 82, 40, 0},      // 'Ý'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 83, 0, 0},       // 'Þ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 84, 0, 0},       // 'ß'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 85, 41, 0},      // 'à'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 86, 42, 0},      // 'á'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 87, 43, 67},     // 'â'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 88, 44, 0},      // 'ã'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 89, 45, 68},     // 'ä'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 90, 46, 69},     // 'å'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 91, 0, 70},      // 'æ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 92, 47, 71},     // 'ç'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 93, 48, 0},      // 'è'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 94, 49, 0},      // 'é'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 95, 50, 72},     // 'ê'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 96, 51, 0},      // 'ë'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 97, 52, 0},      // 'ì'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 98, 53, 0},      // 'í'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 99, 54, 0},      // 'î'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 100, 55, 73},    // 'ï'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 101, 0, 0},      // 'ð'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 102, 56, 0},     // 'ñ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 103, 57, 0},     // 'ò'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 104, 58, 0},     // 'ó'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 105, 59, 74},    // 'ô'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 106, 60, 75},    // 'õ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 107, 61, 76},    // 'ö'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 108, 0, 77},     // 'ø'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 109, 62, 0},     // 'ù'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 110, 63, 0},     // 'ú'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 111, 64, 0},     // 'û'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 112, 65, 78},    // 'ü'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 113, 66, 0},     // 'ý'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 114, 0, 0},      // 'þ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 115, 67, 0},     // 'ÿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 116, 68, 0},     // 'Ā'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 117, 69, 0},     // 'ā'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 118, 70, 79},    // 'Ă'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 119, 71, 80},    // 'ă'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 120, 72, 0},     // 'Ą'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 121, 73, 0},     // 'ą'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 122, 74, 0},     // 'Ć'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 123, 75, 0},     // 'ć'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 124, 76, 0},     // 'Ĉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 125, 77, 0},     // 'ĉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 126, 78, 0},     // 'Ċ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 127, 79, 0},     // 'ċ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 128, 80, 0},     // 'Č'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 129, 81, 0},     // 'č'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 130, 82, 0},     // 'Ď'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 131, 83, 0},     // 'ď'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 132, 0, 0},      // 'Đ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 133, 0, 0},      // 'đ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 134, 84, 81},    // 'Ē'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 135, 85, 82},    // 'ē'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 136, 86, 0},     // 'Ĕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 137, 87, 0},     // 'ĕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 138, 88, 0},     // 'Ė'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 139, 89, 0},     // 'ė'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 140, 90, 0},     // 'Ę'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 141, 91, 0},     // 'ę'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 142, 92, 0},     // 'Ě'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 143, 93, 0},     // 'ě'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 144, 94, 0},     // 'Ĝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 145, 95, 0},     // 'ĝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 146, 96, 0},     // 'Ğ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 147, 97, 0},     // 'ğ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 148, 98, 0},     // 'Ġ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 149, 99, 0},     // 'ġ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 150, 100, 0},    // 'Ģ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 151, 101, 0},    // 'ģ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 152, 102, 0},    // 'Ĥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 153, 103, 0},    // 'ĥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 154, 0, 0},      // 'Ħ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 155, 0, 0},      // 'ħ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 156, 104, 0},    // 'Ĩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 157, 105, 0},    // 'ĩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 158, 106, 0},    // 'Ī'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 159, 107, 0},    // 'ī'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 160, 108, 0},    // 'Ĭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 161, 109, 0},    // 'ĭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 162, 110, 0},    // 'Į'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 163, 111, 0},    // 'į'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 164, 112, 0},    // 'İ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 165, 0, 0},      // 'ı'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 166, 113, 0},    // 'Ĳ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 167, 114, 0},    // 'ĳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 168, 115, 0},    // 'Ĵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 169, 116, 0},    // 'ĵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 170, 117, 0},    // 'Ķ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 171, 118, 0},    // 'ķ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 0, 0},        // 272 codepoints in range [0x0138, 0x01DF2A]
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 172, 119, 0},    // 'Ĺ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 173, 120, 0},    // 'ĺ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 174, 121, 0},    // 'Ļ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 175, 122, 0},    // 'ļ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 176, 123, 0},    // 'Ľ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 177, 124, 0},    // 'ľ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 178, 125, 0},    // 'Ŀ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 179, 126, 0},    // 'ŀ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 180, 0, 0},      // 'Ł'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 181, 0, 0},      // 'ł'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 182, 127, 0},    // 'Ń'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 183, 128, 0},    // 'ń'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 184, 129, 0},    // 'Ņ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 185, 130, 0},    // 'ņ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 186, 131, 0},    // 'Ň'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 187, 132, 0},    // 'ň'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 188, 133, 0},    // 'ŉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 189, 0, 0},      // 'Ŋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 190, 0, 0},      // 'ŋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 191, 134, 83},   // 'Ō'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 192, 135, 84},   // 'ō'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 193, 136, 0},    // 'Ŏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 194, 137, 0},    // 'ŏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 195, 138, 0},    // 'Ő'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 196, 139, 0},    // 'ő'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 197, 0, 0},      // 'Œ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 198, 0, 0},      // 'œ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 199, 140, 0},    // 'Ŕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 200, 141, 0},    // 'ŕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 201, 142, 0},    // 'Ŗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 202, 143, 0},    // 'ŗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 203, 144, 0},    // 'Ř'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 204, 145, 0},    // 'ř'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 205, 146, 85},   // 'Ś'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 206, 147, 86},   // 'ś'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 207, 148, 0},    // 'Ŝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 208, 149, 0},    // 'ŝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 209, 150, 0},    // 'Ş'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 210, 151, 0},    // 'ş'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 211, 152, 87},   // 'Š'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 212, 153, 88},   // 'š'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 213, 154, 0},    // 'Ţ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 214, 155, 0},    // 'ţ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 215, 156, 0},    // 'Ť'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 216, 157, 0},    // 'ť'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 217, 0, 0},      // 'Ŧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 218, 0, 0},      // 'ŧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 219, 158, 89},   // 'Ũ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 220, 159, 90},   // 'ũ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 221, 160, 91},   // 'Ū'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 222, 161, 92},   // 'ū'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 223, 162, 0},    // 'Ŭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 224, 163, 0},    // 'ŭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 225, 164, 0},    // 'Ů'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 226, 165, 0},    // 'ů'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 227, 166, 0},    // 'Ű'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 228, 167, 0},    // 'ű'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 229, 168, 0},    // 'Ų'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 230, 169, 0},    // 'ų'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 231, 170, 0},    // 'Ŵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 232, 171, 0},    // 'ŵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 233, 172, 0},    // 'Ŷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 234, 173, 0},    // 'ŷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 235, 174, 0},    // 'Ÿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 236, 175, 0},    // 'Ź'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 237, 176, 0},    // 'ź'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 238, 177, 0},    // 'Ż'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 239, 178, 0},    // 'ż'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 240, 179, 0},    // 'Ž'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 241, 180, 0},    // 'ž'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 242, 181, 93},   // 'ſ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 243, 0, 0},      // 'ƀ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 244, 0, 0},      // 'Ɓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 245, 0, 0},      // 'Ƃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 246, 0, 0},      // 'ƃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 247, 0, 0},      // 'Ƅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 248, 0, 0},      // 'ƅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 249, 0, 0},      // 'Ɔ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 250, 0, 0},      // 'Ƈ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 251, 0, 0},      // 'ƈ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 252, 0, 0},      // 'Ɖ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 253, 0, 0},      // 'Ɗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 254, 0, 0},      // 'Ƌ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 255, 0, 0},      // 'ƌ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 256, 0, 0},      // 'Ǝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 257, 0, 0},      // 'Ə'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 258, 0, 0},      // 'Ɛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 259, 0, 0},      // 'Ƒ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 260, 0, 0},      // 'ƒ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 261, 0, 0},      // 'Ɠ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 262, 0, 0},      // 'Ɣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 263, 0, 0},      // 'ƕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 264, 0, 0},      // 'Ɩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 265, 0, 0},      // 'Ɨ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 266, 0, 0},      // 'Ƙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 267, 0, 0},      // 'ƙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 268, 0, 0},      // 'ƚ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 269, 0, 0},      // 'ƛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 270, 0, 0},      // 'Ɯ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 271, 0, 0},      // 'Ɲ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 272, 0, 0},      // 'ƞ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 273, 0, 0},      // 'Ɵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 274, 182, 94},   // 'Ơ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 275, 183, 95},   // 'ơ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 276, 0, 0},      // 'Ƣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 277, 0, 0},      // 'ƣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 278, 0, 0},      // 'Ƥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 279, 0, 0},      // 'ƥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 280, 0, 0},      // 'Ʀ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 281, 0, 0},      // 'Ƨ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 282, 0, 0},      // 'ƨ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 283, 0, 0},      // 'Ʃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 284, 0, 0},      // 'Ƭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 285, 0, 0},      // 'ƭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 286, 0, 0},      // 'Ʈ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 287, 184, 96},   // 'Ư'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 288, 185, 97},   // 'ư'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 289, 0, 0},      // 'Ʊ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 290, 0, 0},      // 'Ʋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 291, 0, 0},      // 'Ƴ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 292, 0, 0},      // 'ƴ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 293, 0, 0},      // 'Ƶ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 294, 0, 0},      // 'ƶ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 295, 0, 98},     // 'Ʒ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 296, 0, 0},      // 'Ƹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 297, 0, 0},      // 'ƹ'
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 0},        // 126319 codepoints in range [0x01BB, 0x033479]
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 298, 0, 0},      // 'Ƽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 299, 0, 0},      // 'ƽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 300, 0, 0},      // 'ƿ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 301, 186, 0},    // 'Ǆ'
    {4, TINYUCD_GC_LT, 0, 0, 0, 0, 302, 187, 0},    // 'ǅ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 303, 188, 0},    // 'ǆ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 304, 189, 0},    // 'Ǉ'
    {4, TINYUCD_GC_LT, 0, 0, 0, 0, 305, 190, 0},    // 'ǈ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 306, 191, 0},    // 'ǉ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 307, 192, 0},    // 'Ǌ'
    {4, TINYUCD_GC_LT, 0, 0, 0, 0, 308, 193, 0},    // 'ǋ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 309, 194, 0},    // 'ǌ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 310, 195, 0},    // 'Ǎ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 311, 196, 0},    // 'ǎ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 312, 197, 0},    // 'Ǐ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 313, 198, 0},    // 'ǐ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 314, 199, 0},    // 'Ǒ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 315, 200, 0},    // 'ǒ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 316, 201, 0},    // 'Ǔ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 317, 202, 0},    // 'ǔ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 318, 203, 0},    // 'Ǖ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 319, 204, 0},    // 'ǖ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 320, 205, 0},    // 'Ǘ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 321, 206, 0},    // 'ǘ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 322, 207, 0},    // 'Ǚ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 323, 208, 0},    // 'ǚ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 324, 209, 0},    // 'Ǜ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 325, 210, 0},    // 'ǜ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 326, 0, 0},      // 'ǝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 327, 211, 0},    // 'Ǟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 328, 212, 0},    // 'ǟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 329, 213, 0},    // 'Ǡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 330, 214, 0},    // 'ǡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 331, 215, 0},    // 'Ǣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 332, 216, 0},    // 'ǣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 333, 0, 0},      // 'Ǥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 334, 0, 0},      // 'ǥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 335, 217, 0},    // 'Ǧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 336, 218, 0},    // 'ǧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 337, 219, 0},    // 'Ǩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 338, 220, 0},    // 'ǩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 339, 221, 99},   // 'Ǫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 340, 222, 100},  // 'ǫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 341, 223, 0},    // 'Ǭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 342, 224, 0},    // 'ǭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 343, 225, 0},    // 'Ǯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 344, 226, 0},    // 'ǯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 345, 227, 0},    // 'ǰ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 346, 228, 0},    // 'Ǳ'
    {4, TINYUCD_GC_LT, 0, 0, 0, 0, 347, 229, 0},    // 'ǲ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 348, 230, 0},    // 'ǳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 349, 231, 0},    // 'Ǵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 350, 232, 0},    // 'ǵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 351, 0, 0},      // 'Ƕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 352, 0, 0},      // 'Ƿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 353, 233, 0},    // 'Ǹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 354, 234, 0},    // 'ǹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 355, 235, 0},    // 'Ǻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 356, 236, 0},    // 'ǻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 357, 237, 0},    // 'Ǽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 358, 238, 0},    // 'ǽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 359, 239, 0},    // 'Ǿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 360, 240, 0},    // 'ǿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 361, 241, 0},    // 'Ȁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 362, 242, 0},    // 'ȁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 363, 243, 0},    // 'Ȃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 364, 244, 0},    // 'ȃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 365, 245, 0},    // 'Ȅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 366, 246, 0},    // 'ȅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 367, 247, 0},    // 'Ȇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 368, 248, 0},    // 'ȇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 369, 249, 0},    // 'Ȉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 370, 250, 0},    // 'ȉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 371, 251, 0},    // 'Ȋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 372, 252, 0},    // 'ȋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 373, 253, 0},    // 'Ȍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 374, 254, 0},    // 'ȍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 375, 255, 0},    // 'Ȏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 376, 256, 0},    // 'ȏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 377, 257, 0},    // 'Ȑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 378, 258, 0},    // 'ȑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 379, 259, 0},    // 'Ȓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 380, 260, 0},    // 'ȓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 381, 261, 0},    // 'Ȕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 382, 262, 0},    // 'ȕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 383, 263, 0},    // 'Ȗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 384, 264, 0},    // 'ȗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 385, 265, 0},    // 'Ș'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 386, 266, 0},    // 'ș'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 387, 267, 0},    // 'Ț'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 388, 268, 0},    // 'ț'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 389, 0, 0},      // 'Ȝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 390, 0, 0},      // 'ȝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 391, 269, 0},    // 'Ȟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 392, 270, 0},    // 'ȟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 393, 0, 0},      // 'Ƞ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 394, 0, 0},      // 'Ȣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 395, 0, 0},      // 'ȣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 396, 0, 0},      // 'Ȥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 397, 0, 0},      // 'ȥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 398, 271, 101},  // 'Ȧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 399, 272, 102},  // 'ȧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 400, 273, 103},  // 'Ȩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 401, 274, 104},  // 'ȩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 402, 275, 0},    // 'Ȫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 403, 276, 0},    // 'ȫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 404, 277, 0},    // 'Ȭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 405, 278, 0},    // 'ȭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 406, 279, 105},  // 'Ȯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 407, 280, 106},  // 'ȯ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 408, 281, 0},    // 'Ȱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 409, 282, 0},    // 'ȱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 410, 283, 0},    // 'Ȳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 411, 284, 0},    // 'ȳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 412, 0, 0},      // 'Ⱥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 413, 0, 0},      // 'Ȼ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 414, 0, 0},      // 'ȼ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 415, 0, 0},      // 'Ƚ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 416, 0, 0},      // 'Ⱦ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 417, 0, 0},      // 'ȿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 418, 0, 0},      // 'ɀ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 419, 0, 0},      // 'Ɂ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 420, 0, 0},      // 'ɂ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 421, 0, 0},      // 'Ƀ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 422, 0, 0},      // 'Ʉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 423, 0, 0},      // 'Ʌ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 424, 0, 0},      // 'Ɇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 425, 0, 0},      // 'ɇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 426, 0, 0},      // 'Ɉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 427, 0, 0},      // 'ɉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 428, 0, 0},      // 'Ɋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 429, 0, 0},      // 'ɋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 430, 0, 0},      // 'Ɍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 431, 0, 0},      // 'ɍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 432, 0, 0},      // 'Ɏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 433, 0, 0},      // 'ɏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 434, 0, 0},      // 'ɐ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 435, 0, 0},      // 'ɑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 436, 0, 0},      // 'ɒ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 437, 0, 0},      // 'ɓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 438, 0, 0},      // 'ɔ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 439, 0, 0},      // 'ɖ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 440, 0, 0},      // 'ɗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 441, 0, 0},      // 'ə'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 442, 0, 0},      // 'ɛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 443, 0, 0},      // 'ɜ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 444, 0, 0},      // 'ɠ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 445, 0, 0},      // 'ɡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 446, 0, 0},      // 'ɣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 447, 0, 0},      // 'ɤ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 448, 0, 0},      // 'ɥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 449, 0, 0},      // 'ɦ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 450, 0, 0},      // 'ɨ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 451, 0, 0},      // 'ɩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 452, 0, 0},      // 'ɪ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 453, 0, 0},      // 'ɫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 454, 0, 0},      // 'ɬ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 455, 0, 0},      // 'ɯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 456, 0, 0},      // 'ɱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 457, 0, 0},      // 'ɲ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 458, 0, 0},      // 'ɵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 459, 0, 0},      // 'ɽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 460, 0, 0},      // 'ʀ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 461, 0, 0},      // 'ʂ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 462, 0, 0},      // 'ʃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 463, 0, 0},      // 'ʇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 464, 0, 0},      // 'ʈ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 465, 0, 0},      // 'ʉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 466, 0, 0},      // 'ʊ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 467, 0, 0},      // 'ʋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 468, 0, 0},      // 'ʌ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 469, 0, 107},    // 'ʒ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 470, 0, 0},      // 'ʝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 471, 0, 0},      // 'ʞ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 285, 0},      // 'ʰ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 286, 0},      // 'ʱ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 287, 0},      // 'ʲ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 288, 0},      // 'ʳ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 289, 0},      // 'ʴ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 290, 0},      // 'ʵ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 291, 0},      // 'ʶ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 292, 0},      // 'ʷ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 293, 0},      // 'ʸ'
    {0, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 0, 0},        // 138 codepoints in range [0x02B9, 0x01E94B]
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 294, 0},      // 0x02D8
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 295, 0},      // 0x02D9
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 296, 0},      // 0x02DA
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 297, 0},      // 0x02DB
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 298, 0},      // 0x02DC
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 299, 0},      // 0x02DD
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 300, 0},      // 'ˠ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 301, 0},      // 'ˡ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 302, 0},      // 'ˢ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 303, 0},      // 'ˣ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 304, 0},      // 'ˤ'
    {2, TINYUCD_GC_MN, 230, 4, 2, 0, 0, 0, 0},      // 19 codepoints in range [0x0300, 0x0654]
    {0, TINYUCD_GC_MN, 230, 4, 2, 0, 0, 0, 0},      // 523 codepoints in range [0x0305, 0x01E949]
    {0, TINYUCD_GC_MN, 232, 4, 2, 0, 0, 0, 0},      // 7 codepoints in range [0x0315, 0x01E4ED]
    {0, TINYUCD_GC_MN, 220, 4, 2, 0, 0, 0, 0},      // 177 codepoints in range [0x0316, 0x01E8D6]
    {2, TINYUCD_GC_MN, 216, 4, 2, 0, 0, 0, 0},      // 0x031B
    {0, TINYUCD_GC_MN, 202, 4, 2, 0, 0, 0, 0},      // 3 codepoints in range [0x0321, 0x1DD0]
    {2, TINYUCD_GC_MN, 220, 4, 2, 0, 0, 0, 0},      // 9 codepoints in range [0x0323, 0x0655]
    {2, TINYUCD_GC_MN, 202, 4, 2, 0, 0, 0, 0},      // 2 codepoints in range [0x0327, 0x0328]
    {0, TINYUCD_GC_MN, 1, 4, 2, 0, 0, 0, 0},        // 31 codepoints in range [0x0334, 0x01D169]
    {2, TINYUCD_GC_MN, 1, 4, 2, 0, 0, 0, 0},        // 0x0338
    {5, TINYUCD_GC_MN, 230, 4, 2, 0, 0, 305, 0},    // 0x0340
    {5, TINYUCD_GC_MN, 230, 4, 2, 0, 0, 306, 0},    // 0x0341
    {5, TINYUCD_GC_MN, 230, 4, 2, 0, 0, 307, 0},    // 0x0343
    {5, TINYUCD_GC_MN, 230, 4, 2, 0, 0, 308, 0},    // 0x0344
    {2, TINYUCD_GC_MN, 240, 4, 2, 0, 472, 0, 0},    // 0x0345
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 0},        // 1077 codepoints in range [0x034F, 0x0E01EF]
    {0, TINYUCD_GC_MN, 233, 4, 2, 0, 0, 0, 0},      // 4 codepoints in range [0x035C, 0x1DFC]
    {0, TINYUCD_GC_MN, 234, 4, 2, 0, 0, 0, 0},      // 6 codepoints in range [0x035D, 0x1DCD]
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 473, 0, 0},      // 'Ͱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 474, 0, 0},      // 'ͱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 475, 0, 0},      // 'Ͳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 476, 0, 0},      // 'ͳ'
    {5, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 309, 0},      // 'ʹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 477, 0, 0},      // 'Ͷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 478, 0, 0},      // 'ͷ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 310, 0},      // 'ͺ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 479, 0, 0},      // 'ͻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 480, 0, 0},      // 'ͼ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 481, 0, 0},      // 'ͽ'
    {5, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 311, 0},      // 0x037E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 482, 0, 0},      // 'Ϳ'
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 312, 0},      // 0x0384
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 313, 0},      // 0x0385
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 483, 314, 0},    // 'Ά'
    {5, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 315, 0},      // 0x0387
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 484, 316, 0},    // 'Έ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 485, 317, 0},    // 'Ή'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 486, 318, 0},    // 'Ί'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 487, 319, 0},    // 'Ό'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 488, 320, 0},    // 'Ύ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 489, 321, 0},    // 'Ώ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 490, 322, 0},    // 'ΐ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 491, 0, 108},    // 'Α'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 492, 0, 0},      // 'Β'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 493, 0, 0},      // 'Γ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 494, 0, 0},      // 'Δ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 495, 0, 109},    // 'Ε'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 496, 0, 0},      // 'Ζ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 497, 0, 110},    // 'Η'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 498, 0, 0},      // 'Θ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 499, 0, 111},    // 'Ι'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 500, 0, 0},      // 'Κ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 501, 0, 0},      // 'Λ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 502, 0, 0},      // 'Μ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 503, 0, 0},      // 'Ν'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 504, 0, 0},      // 'Ξ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 505, 0, 112},    // 'Ο'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 506, 0, 0},      // 'Π'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 507, 0, 113},    // 'Ρ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 508, 0, 0},      // 'Σ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 509, 0, 0},      // 'Τ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 510, 0, 114},    // 'Υ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 511, 0, 0},      // 'Φ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 512, 0, 0},      // 'Χ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 513, 0, 0},      // 'Ψ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 514, 0, 115},    // 'Ω'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 515, 323, 0},    // 'Ϊ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 516, 324, 0},    // 'Ϋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 517, 325, 116},  // 'ά'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 518, 326, 0},    // 'έ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 519, 327, 117},  // 'ή'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 520, 328, 0},    // 'ί'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 521, 329, 0},    // 'ΰ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 522, 0, 118},    // 'α'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 523, 0, 0},      // 'β'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 524, 0, 0},      // 'γ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 525, 0, 0},      // 'δ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 526, 0, 119},    // 'ε'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 527, 0, 0},      // 'ζ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 528, 0, 120},    // 'η'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 529, 0, 0},      // 'θ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 530, 0, 121},    // 'ι'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 531, 0, 0},      // 'κ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 532, 0, 0},      // 'λ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 533, 0, 0},      // 'μ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 534, 0, 0},      // 'ν'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 535, 0, 0},      // 'ξ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 536, 0, 122},    // 'ο'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 537, 0, 0},      // 'π'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 538, 0, 123},    // 'ρ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 539, 0, 0},      // 'ς'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 540, 0, 0},      // 'σ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 541, 0, 0},      // 'τ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 542, 0, 124},    // 'υ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 543, 0, 0},      // 'φ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 544, 0, 0},      // 'χ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 545, 0, 0},      // 'ψ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 546, 0, 125},    // 'ω'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 547, 330, 126},  // 'ϊ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 548, 331, 127},  // 'ϋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 549, 332, 0},    // 'ό'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 550, 333, 0},    // 'ύ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 551, 334, 128},  // 'ώ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 552, 0, 0},      // 'Ϗ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 553, 335, 0},    // 'ϐ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 554, 336, 0},    // 'ϑ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 337, 129},    // 'ϒ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 338, 0},      // 'ϓ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 339, 0},      // 'ϔ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 555, 340, 0},    // 'ϕ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 556, 341, 0},    // 'ϖ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 557, 0, 0},      // 'ϗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 558, 0, 0},      // 'Ϙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 559, 0, 0},      // 'ϙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 560, 0, 0},      // 'Ϛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 561, 0, 0},      // 'ϛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 562, 0, 0},      // 'Ϝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 563, 0, 0},      // 'ϝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 564, 0, 0},      // 'Ϟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 565, 0, 0},      // 'ϟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 566, 0, 0},      // 'Ϡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 567, 0, 0},      // 'ϡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 568, 0, 0},      // 'Ϣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 569, 0, 0},      // 'ϣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 570, 0, 0},      // 'Ϥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 571, 0, 0},      // 'ϥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 572, 0, 0},      // 'Ϧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 573, 0, 0},      // 'ϧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 574, 0, 0},      // 'Ϩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 575, 0, 0},      // 'ϩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 576, 0, 0},      // 'Ϫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 577, 0, 0},      // 'ϫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 578, 0, 0},      // 'Ϭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 579, 0, 0},      // 'ϭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 580, 0, 0},      // 'Ϯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 581, 0, 0},      // 'ϯ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 582, 342, 0},    // 'ϰ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 583, 343, 0},    // 'ϱ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 584, 344, 0},    // 'ϲ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 585, 0, 0},      // 'ϳ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 586, 345, 0},    // 'ϴ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 587, 346, 0},    // 'ϵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 588, 0, 0},      // 'Ϸ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 589, 0, 0},      // 'ϸ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 590, 347, 0},    // 'Ϲ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 591, 0, 0},      // 'Ϻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 592, 0, 0},      // 'ϻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 593, 0, 0},      // 'Ͻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 594, 0, 0},      // 'Ͼ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 595, 0, 0},      // 'Ͽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 596, 348, 0},    // 'Ѐ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 597, 349, 0},    // 'Ё'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 598, 0, 0},      // 'Ђ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 599, 350, 0},    // 'Ѓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 600, 0, 0},      // 'Є'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 601, 0, 0},      // 'Ѕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 602, 0, 130},    // 'І'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 603, 351, 0},    // 'Ї'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 604, 0, 0},      // 'Ј'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 605, 0, 0},      // 'Љ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 606, 0, 0},      // 'Њ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 607, 0, 0},      // 'Ћ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 608, 352, 0},    // 'Ќ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 609, 353, 0},    // 'Ѝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 610, 354, 0},    // 'Ў'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 611, 0, 0},      // 'Џ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 612, 0, 131},    // 'А'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 613, 0, 0},      // 'Б'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 614, 0, 0},      // 'В'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 615, 0, 132},    // 'Г'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 616, 0, 0},      // 'Д'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 617, 0, 133},    // 'Е'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 618, 0, 134},    // 'Ж'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 619, 0, 135},    // 'З'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 620, 0, 136},    // 'И'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 621, 355, 0},    // 'Й'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 622, 0, 137},    // 'К'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 623, 0, 0},      // 'Л'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 624, 0, 0},      // 'М'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 625, 0, 0},      // 'Н'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 626, 0, 138},    // 'О'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 627, 0, 0},      // 'П'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 628, 0, 0},      // 'Р'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 629, 0, 0},      // 'С'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 630, 0, 0},      // 'Т'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 631, 0, 139},    // 'У'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 632, 0, 0},      // 'Ф'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 633, 0, 0},      // 'Х'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 634, 0, 0},      // 'Ц'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 635, 0, 140},    // 'Ч'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 636, 0, 0},      // 'Ш'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 637, 0, 0},      // 'Щ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 638, 0, 0},      // 'Ъ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 639, 0, 141},    // 'Ы'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 640, 0, 0},      // 'Ь'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 641, 0, 142},    // 'Э'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 642, 0, 0},      // 'Ю'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 643, 0, 0},      // 'Я'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 644, 0, 143},    // 'а'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 645, 0, 0},      // 'б'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 646, 0, 0},      // 'в'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 647, 0, 144},    // 'г'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 648, 0, 0},      // 'д'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 649, 0, 145},    // 'е'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 650, 0, 146},    // 'ж'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 651, 0, 147},    // 'з'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 652, 0, 148},    // 'и'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 653, 356, 0},    // 'й'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 654, 0, 149},    // 'к'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 655, 0, 0},      // 'л'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 656, 0, 0},      // 'м'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 657, 0, 0},      // 'н'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 658, 0, 150},    // 'о'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 659, 0, 0},      // 'п'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 660, 0, 0},      // 'р'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 661, 0, 0},      // 'с'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 662, 0, 0},      // 'т'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 663, 0, 151},    // 'у'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 664, 0, 0},      // 'ф'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 665, 0, 0},      // 'х'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 666, 0, 0},      // 'ц'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 667, 0, 152},    // 'ч'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 668, 0, 0},      // 'ш'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 669, 0, 0},      // 'щ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 670, 0, 0},      // 'ъ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 671, 0, 153},    // 'ы'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 672, 0, 0},      // 'ь'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 673, 0, 154},    // 'э'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 674, 0, 0},      // 'ю'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 675, 0, 0},      // 'я'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 676, 357, 0},    // 'ѐ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 677, 358, 0},    // 'ё'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 678, 0, 0},      // 'ђ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 679, 359, 0},    // 'ѓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 680, 0, 0},      // 'є'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 681, 0, 0},      // 'ѕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 682, 0, 155},    // 'і'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 683, 360, 0},    // 'ї'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 684, 0, 0},      // 'ј'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 685, 0, 0},      // 'љ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 686, 0, 0},      // 'њ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 687, 0, 0},      // 'ћ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 688, 361, 0},    // 'ќ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 689, 362, 0},    // 'ѝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 690, 363, 0},    // 'ў'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 691, 0, 0},      // 'џ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 692, 0, 0},      // 'Ѡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 693, 0, 0},      // 'ѡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 694, 0, 0},      // 'Ѣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 695, 0, 0},      // 'ѣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 696, 0, 0},      // 'Ѥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 697, 0, 0},      // 'ѥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 698, 0, 0},      // 'Ѧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 699, 0, 0},      // 'ѧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 700, 0, 0},      // 'Ѩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 701, 0, 0},      // 'ѩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 702, 0, 0},      // 'Ѫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 703, 0, 0},      // 'ѫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 704, 0, 0},      // 'Ѭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 705, 0, 0},      // 'ѭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 706, 0, 0},      // 'Ѯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 707, 0, 0},      // 'ѯ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 708, 0, 0},      // 'Ѱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 709, 0, 0},      // 'ѱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 710, 0, 0},      // 'Ѳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 711, 0, 0},      // 'ѳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 712, 0, 156},    // 'Ѵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 713, 0, 157},    // 'ѵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 714, 364, 0},    // 'Ѷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 715, 365, 0},    // 'ѷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 716, 0, 0},      // 'Ѹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 717, 0, 0},      // 'ѹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 718, 0, 0},      // 'Ѻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 719, 0, 0},      // 'ѻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 720, 0, 0},      // 'Ѽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 721, 0, 0},      // 'ѽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 722, 0, 0},      // 'Ѿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 723, 0, 0},      // 'ѿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 724, 0, 0},      // 'Ҁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 725, 0, 0},      // 'ҁ'
    {0, TINYUCD_GC_ME, 0, 4, 2, 0, 0, 0, 0},        // 13 codepoints in range [0x0488, 0xA672]
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 726, 0, 0},      // 'Ҋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 727, 0, 0},      // 'ҋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 728, 0, 0},      // 'Ҍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 729, 0, 0},      // 'ҍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 730, 0, 0},      // 'Ҏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 731, 0, 0},      // 'ҏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 732, 0, 0},      // 'Ґ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 733, 0, 0},      // 'ґ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 734, 0, 0},      // 'Ғ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 735, 0, 0},      // 'ғ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 736, 0, 0},      // 'Ҕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 737, 0, 0},      // 'ҕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 738, 0, 0},      // 'Җ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 739, 0, 0},      // 'җ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 740, 0, 0},      // 'Ҙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 741, 0, 0},      // 'ҙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 742, 0, 0},      // 'Қ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 743, 0, 0},      // 'қ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 744, 0, 0},      // 'Ҝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 745, 0, 0},      // 'ҝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 746, 0, 0},      // 'Ҟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 747, 0, 0},      // 'ҟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 748, 0, 0},      // 'Ҡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 749, 0, 0},      // 'ҡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 750, 0, 0},      // 'Ң'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 751, 0, 0},      // 'ң'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 752, 0, 0},      // 'Ҥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 753, 0, 0},      // 'ҥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 754, 0, 0},      // 'Ҧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 755, 0, 0},      // 'ҧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 756, 0, 0},      // 'Ҩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 757, 0, 0},      // 'ҩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 758, 0, 0},      // 'Ҫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 759, 0, 0},      // 'ҫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 760, 0, 0},      // 'Ҭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 761, 0, 0},      // 'ҭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 762, 0, 0},      // 'Ү'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 763, 0, 0},      // 'ү'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 764, 0, 0},      // 'Ұ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 765, 0, 0},      // 'ұ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 766, 0, 0},      // 'Ҳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 767, 0, 0},      // 'ҳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 768, 0, 0},      // 'Ҵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 769, 0, 0},      // 'ҵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 770, 0, 0},      // 'Ҷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 771, 0, 0},      // 'ҷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 772, 0, 0},      // 'Ҹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 773, 0, 0},      // 'ҹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 774, 0, 0},      // 'Һ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 775, 0, 0},      // 'һ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 776, 0, 0},      // 'Ҽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 777, 0, 0},      // 'ҽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 778, 0, 0},      // 'Ҿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 779, 0, 0},      // 'ҿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 780, 0, 0},      // 'Ӏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 781, 366, 0},    // 'Ӂ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 782, 367, 0},    // 'ӂ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 783, 0, 0},      // 'Ӄ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 784, 0, 0},      // 'ӄ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 785, 0, 0},      // 'Ӆ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 786, 0, 0},      // 'ӆ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 787, 0, 0},      // 'Ӈ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 788, 0, 0},      // 'ӈ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 789, 0, 0},      // 'Ӊ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 790, 0, 0},      // 'ӊ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 791, 0, 0},      // 'Ӌ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 792, 0, 0},      // 'ӌ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 793, 0, 0},      // 'Ӎ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 794, 0, 0},      // 'ӎ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 795, 0, 0},      // 'ӏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 796, 368, 0},    // 'Ӑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 797, 369, 0},    // 'ӑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 798, 370, 0},    // 'Ӓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 799, 371, 0},    // 'ӓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 800, 0, 0},      // 'Ӕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 801, 0, 0},      // 'ӕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 802, 372, 0},    // 'Ӗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 803, 373, 0},    // 'ӗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 804, 0, 158},    // 'Ә'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 805, 0, 159},    // 'ә'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 806, 374, 0},    // 'Ӛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 807, 375, 0},    // 'ӛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 808, 376, 0},    // 'Ӝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 809, 377, 0},    // 'ӝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 810, 378, 0},    // 'Ӟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 811, 379, 0},    // 'ӟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 812, 0, 0},      // 'Ӡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 813, 0, 0},      // 'ӡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 814, 380, 0},    // 'Ӣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 815, 381, 0},    // 'ӣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 816, 382, 0},    // 'Ӥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 817, 383, 0},    // 'ӥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 818, 384, 0},    // 'Ӧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 819, 385, 0},    // 'ӧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 820, 0, 160},    // 'Ө'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 821, 0, 161},    // 'ө'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 822, 386, 0},    // 'Ӫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 823, 387, 0},    // 'ӫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 824, 388, 0},    // 'Ӭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 825, 389, 0},    // 'ӭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 826, 390, 0},    // 'Ӯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 827, 391, 0},    // 'ӯ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 828, 392, 0},    // 'Ӱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 829, 393, 0},    // 'ӱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 830, 394, 0},    // 'Ӳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 831, 395, 0},    // 'ӳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 832, 396, 0},    // 'Ӵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 833, 397, 0},    // 'ӵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 834, 0, 0},      // 'Ӷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 835, 0, 0},      // 'ӷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 836, 398, 0},    // 'Ӹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 837, 399, 0},    // 'ӹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 838, 0, 0},      // 'Ӻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 839, 0, 0},      // 'ӻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 840, 0, 0},      // 'Ӽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 841, 0, 0},      // 'ӽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 842, 0, 0},      // 'Ӿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 843, 0, 0},      // 'ӿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 844, 0, 0},      // 'Ԁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 845, 0, 0},      // 'ԁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 846, 0, 0},      // 'Ԃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 847, 0, 0},      // 'ԃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 848, 0, 0},      // 'Ԅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 849, 0, 0},      // 'ԅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 850, 0, 0},      // 'Ԇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 851, 0, 0},      // 'ԇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 852, 0, 0},      // 'Ԉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 853, 0, 0},      // 'ԉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 854, 0, 0},      // 'Ԋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 855, 0, 0},      // 'ԋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 856, 0, 0},      // 'Ԍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 857, 0, 0},      // 'ԍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 858, 0, 0},      // 'Ԏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 859, 0, 0},      // 'ԏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 860, 0, 0},      // 'Ԑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 861, 0, 0},      // 'ԑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 862, 0, 0},      // 'Ԓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 863, 0, 0},      // 'ԓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 864, 0, 0},      // 'Ԕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 865, 0, 0},      // 'ԕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 866, 0, 0},      // 'Ԗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 867, 0, 0},      // 'ԗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 868, 0, 0},      // 'Ԙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 869, 0, 0},      // 'ԙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 870, 0, 0},      // 'Ԛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 871, 0, 0},      // 'ԛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 872, 0, 0},      // 'Ԝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 873, 0, 0},      // 'ԝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 874, 0, 0},      // 'Ԟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 875, 0, 0},      // 'ԟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 876, 0, 0},      // 'Ԡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 877, 0, 0},      // 'ԡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 878, 0, 0},      // 'Ԣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 879, 0, 0},      // 'ԣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 880, 0, 0},      // 'Ԥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 881, 0, 0},      // 'ԥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 882, 0, 0},      // 'Ԧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 883, 0, 0},      // 'ԧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 884, 0, 0},      // 'Ԩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 885, 0, 0},      // 'ԩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 886, 0, 0},      // 'Ԫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 887, 0, 0},      // 'ԫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 888, 0, 0},      // 'Ԭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 889, 0, 0},      // 'ԭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 890, 0, 0},      // 'Ԯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 891, 0, 0},      // 'ԯ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 892, 0, 0},      // 'Ա'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 893, 0, 0},      // 'Բ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 894, 0, 0},      // 'Գ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 895, 0, 0},      // 'Դ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 896, 0, 0},      // 'Ե'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 897, 0, 0},      // 'Զ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 898, 0, 0},      // 'Է'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 899, 0, 0},      // 'Ը'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 900, 0, 0},      // 'Թ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 901, 0, 0},      // 'Ժ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 902, 0, 0},      // 'Ի'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 903, 0, 0},      // 'Լ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 904, 0, 0},      // 'Խ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 905, 0, 0},      // 'Ծ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 906, 0, 0},      // 'Կ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 907, 0, 0},      // 'Հ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 908, 0, 0},      // 'Ձ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 909, 0, 0},      // 'Ղ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 910, 0, 0},      // 'Ճ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 911, 0, 0},      // 'Մ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 912, 0, 0},      // 'Յ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 913, 0, 0},      // 'Ն'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 914, 0, 0},      // 'Շ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 915, 0, 0},      // 'Ո'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 916, 0, 0},      // 'Չ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 917, 0, 0},      // 'Պ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 918, 0, 0},      // 'Ջ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 919, 0, 0},      // 'Ռ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 920, 0, 0},      // 'Ս'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 921, 0, 0},      // 'Վ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 922, 0, 0},      // 'Տ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 923, 0, 0},      // 'Ր'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 924, 0, 0},      // 'Ց'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 925, 0, 0},      // 'Ւ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 926, 0, 0},      // 'Փ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 927, 0, 0},      // 'Ք'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 928, 0, 0},      // 'Օ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 929, 0, 0},      // 'Ֆ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 930, 0, 0},      // 'ա'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 931, 0, 0},      // 'բ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 932, 0, 0},      // 'գ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 933, 0, 0},      // 'դ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 934, 0, 0},      // 'ե'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 935, 0, 0},      // 'զ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 936, 0, 0},      // 'է'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 937, 0, 0},      // 'ը'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 938, 0, 0},      // 'թ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 939, 0, 0},      // 'ժ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 940, 0, 0},      // 'ի'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 941, 0, 0},      // 'լ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 942, 0, 0},      // 'խ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 943, 0, 0},      // 'ծ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 944, 0, 0},      // 'կ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 945, 0, 0},      // 'հ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 946, 0, 0},      // 'ձ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 947, 0, 0},      // 'ղ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 948, 0, 0},      // 'ճ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 949, 0, 0},      // 'մ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 950, 0, 0},      // 'յ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 951, 0, 0},      // 'ն'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 952, 0, 0},      // 'շ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 953, 0, 0},      // 'ո'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 954, 0, 0},      // 'չ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 955, 0, 0},      // 'պ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 956, 0, 0},      // 'ջ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 957, 0, 0},      // 'ռ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 958, 0, 0},      // 'ս'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 959, 0, 0},      // 'վ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 960, 0, 0},      // 'տ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 961, 0, 0},      // 'ր'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 962, 0, 0},      // 'ց'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 963, 0, 0},      // 'ւ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 964, 0, 0},      // 'փ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 965, 0, 0},      // 'ք'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 966, 0, 0},      // 'օ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 967, 0, 0},      // 'ֆ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 968, 400, 0},    // 'և'
    {0, TINYUCD_GC_MN, 222, 4, 2, 0, 0, 0, 0},      // 4 codepoints in range [0x059A, 0x302D]
    {0, TINYUCD_GC_MN, 228, 4, 2, 0, 0, 0, 0},      // 5 codepoints in range [0x05AE, 0x302B]
    {0, TINYUCD_GC_MN, 10, 4, 2, 0, 0, 0, 0},       // 0x05B0
    {0, TINYUCD_GC_MN, 11, 4, 2, 0, 0, 0, 0},       // 0x05B1
    {0, TINYUCD_GC_MN, 12, 4, 2, 0, 0, 0, 0},       // 0x05B2
    {0, TINYUCD_GC_MN, 13, 4, 2, 0, 0, 0, 0},       // 0x05B3
    {0, TINYUCD_GC_MN, 14, 4, 2, 0, 0, 0, 0},       // 0x05B4
    {0, TINYUCD_GC_MN, 15, 4, 2, 0, 0, 0, 0},       // 0x05B5
    {0, TINYUCD_GC_MN, 16, 4, 2, 0, 0, 0, 0},       // 0x05B6
    {0, TINYUCD_GC_MN, 17, 4, 2, 0, 0, 0, 0},       // 0x05B7
    {0, TINYUCD_GC_MN, 18, 4, 2, 0, 0, 0, 0},       // 2 codepoints in range [0x05B8, 0x05C7]
    {0, TINYUCD_GC_MN, 19, 4, 2, 0, 0, 0, 0},       // 2 codepoints in range [0x05B9, 0x05BA]
    {0, TINYUCD_GC_MN, 20, 4, 2, 0, 0, 0, 0},       // 0x05BB
    {0, TINYUCD_GC_MN, 21, 4, 2, 0, 0, 0, 0},       // 0x05BC
    {0, TINYUCD_GC_MN, 22, 4, 2, 0, 0, 0, 0},       // 0x05BD
    {0, TINYUCD_GC_MN, 23, 4, 2, 0, 0, 0, 0},       // 0x05BF
    {0, TINYUCD_GC_MN, 24, 4, 2, 0, 0, 0, 0},       // 0x05C1
    {0, TINYUCD_GC_MN, 25, 4, 2, 0, 0, 0, 0},       // 0x05C2
    {0, TINYUCD_GC_CF, 0, 7, 0, 0, 0, 0, 0},        // 13 codepoints in range [0x0600, 0x0110CD]
    {0, TINYUCD_GC_MN, 30, 4, 2, 0, 0, 0, 0},       // 2 codepoints in range [0x0618, 0x064E]
    {0, TINYUCD_GC_MN, 31, 4, 2, 0, 0, 0, 0},       // 2 codepoints in range [0x0619, 0x064F]
    {0, TINYUCD_GC_MN, 32, 4, 2, 0, 0, 0, 0},       // 2 codepoints in range [0x061A, 0x0650]
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 401, 0},      // 0x0622
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 402, 0},      // 0x0623
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 403, 0},      // 0x0624
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 404, 0},      // 0x0625
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 405, 0},      // 0x0626
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 162},      // 0x0627
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 163},      // 0x0648
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 164},      // 0x064A
    {0, TINYUCD_GC_MN, 27, 4, 2, 0, 0, 0, 0},       // 2 codepoints in range [0x064B, 0x08F0]
    {0, TINYUCD_GC_MN, 28, 4, 2, 0, 0, 0, 0},       // 2 codepoints in range [0x064C, 0x08F1]
    {0, TINYUCD_GC_MN, 29, 4, 2, 0, 0, 0, 0},       // 2 codepoints in range [0x064D, 0x08F2]
    {0, TINYUCD_GC_MN, 33, 4, 2, 0, 0, 0, 0},       // 0x0651
    {0, TINYUCD_GC_MN, 34, 4, 2, 0, 0, 0, 0},       // 0x0652
    {0, TINYUCD_GC_MN, 35, 4, 2, 0, 0, 0, 0},       // 0x0670
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 406, 0},      // 0x0675
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 407, 0},      // 0x0676
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 408, 0},      // 0x0677
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 409, 0},      // 0x0678
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 410, 0},      // 0x06C0
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 165},      // 0x06C1
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 411, 0},      // 0x06C2
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 166},      // 0x06D2
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 412, 0},      // 0x06D3
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 167},      // 0x06D5
    {0, TINYUCD_GC_MN, 36, 4, 2, 0, 0, 0, 0},       // 0x0711
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 0},        // 340 codepoints in range [0x0903, 0x016F87]
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 0, 0},        // 880 codepoints in range [0x0915, 0x011F33]
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 0, 168},      // 0x0928
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 413, 0},      // 0x0929
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 0, 169},      // 0x0930
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 414, 0},      // 0x0931
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 0, 170},      // 0x0933
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 415, 0},      // 0x0934
    {2, TINYUCD_GC_MN, 7, 4, 2, 0, 0, 0, 0},        // 2 codepoints in range [0x093C, 0x0110BA]
    {0, TINYUCD_GC_MN, 9, 4, 3, 0, 0, 0, 0},        // 18 codepoints in range [0x094D, 0x011F42]
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 416, 0},      // 0x0958
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 417, 0},      // 0x0959
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 418, 0},      // 0x095A
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 419, 0},      // 0x095B
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 420, 0},      // 0x095C
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 421, 0},      // 0x095D
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 422, 0},      // 0x095E
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 423, 0},      // 0x095F
    {0, TINYUCD_GC_MN, 7, 4, 2, 0, 0, 0, 0},        // 25 codepoints in range [0x09BC, 0x01E94A]
    {2, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 0, 0},        // 22 codepoints in range [0x09BE, 0x011930]
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 171},      // 0x09C7
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 424, 0},      // 0x09CB
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 425, 0},      // 0x09CC
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 426, 0},      // 0x09DC
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 427, 0},      // 0x09DD
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 428, 0},      // 0x09DF
    {0, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 0, 0},        // 749 codepoints in range [0x09F4, 0x01F10C]
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 429, 0},      // 0x0A33
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 430, 0},      // 0x0A36
    {0, TINYUCD_GC_MN, 9, 4, 2, 0, 0, 0, 0},        // 35 codepoints in range [0x0A4D, 0x01612F]
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 431, 0},      // 0x0A59
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 432, 0},      // 0x0A5A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 433, 0},      // 0x0A5B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 434, 0},      // 0x0A5E
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 172},      // 0x0B47
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 435, 0},      // 0x0B48
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 436, 0},      // 0x0B4B
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 437, 0},      // 0x0B4C
    {2, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 0},        // 7 codepoints in range [0x0B56, 0x016120]
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 438, 0},      // 0x0B5C
    {5, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 439, 0},      // 0x0B5D
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 173},      // 0x0B92
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 440, 0},      // 0x0B94
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 174},      // 0x0BC6
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 175},      // 0x0BC7
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 441, 0},      // 0x0BCA
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 442, 0},      // 0x0BCB
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 443, 0},      // 0x0BCC
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 176},      // 0x0C46
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 444, 0},      // 0x0C48
    {0, TINYUCD_GC_MN, 84, 4, 2, 0, 0, 0, 0},       // 0x0C55
    {2, TINYUCD_GC_MN, 91, 4, 2, 0, 0, 0, 0},       // 0x0C56
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 177},      // 0x0CBF
    {0, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 445, 0},      // 0x0CC0
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 178},      // 0x0CC6
    {0, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 446, 0},      // 0x0CC7
    {0, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 447, 0},      // 0x0CC8
    {0, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 448, 179},    // 0x0CCA
    {0, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 449, 0},      // 0x0CCB
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 180},      // 0x0D46
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 181},      // 0x0D47
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 450, 0},      // 0x0D4A
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 451, 0},      // 0x0D4B
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 452, 0},      // 0x0D4C
    {0, TINYUCD_GC_LO, 0, 7, 0, 0, 0, 0, 0},        // 14 codepoints in range [0x0D4E, 0x011F02]
    {2, TINYUCD_GC_MN, 9, 4, 2, 0, 0, 0, 0},        // 0x0DCA
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 182},      // 0x0DD9
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 453, 0},      // 0x0DDA
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 454, 183},    // 0x0DDC
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 455, 0},      // 0x0DDD
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 456, 0},      // 0x0DDE
    {4, TINYUCD_GC_LO, 0, 8, 0, 0, 0, 457, 0},      // 0x0E33
    {0, TINYUCD_GC_MN, 103, 4, 2, 0, 0, 0, 0},      // 2 codepoints in range [0x0E38, 0x0E39]
    {0, TINYUCD_GC_MN, 107, 4, 2, 0, 0, 0, 0},      // 4 codepoints in range [0x0E48, 0x0E4B]
    {4, TINYUCD_GC_LO, 0, 8, 0, 0, 0, 458, 0},      // 0x0EB3
    {0, TINYUCD_GC_MN, 118, 4, 2, 0, 0, 0, 0},      // 2 codepoints in range [0x0EB8, 0x0EB9]
    {0, TINYUCD_GC_MN, 122, 4, 2, 0, 0, 0, 0},      // 4 codepoints in range [0x0EC8, 0x0ECB]
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 459, 0},      // 0x0EDC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 460, 0},      // 0x0EDD
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 461, 0},      // 0x0F0C
    {0, TINYUCD_GC_MN, 216, 4, 2, 0, 0, 0, 0},      // 0x0F39
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 462, 0},      // 0x0F43
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 463, 0},      // 0x0F4D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 464, 0},      // 0x0F52
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 465, 0},      // 0x0F57
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 466, 0},      // 0x0F5C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 467, 0},      // 0x0F69
    {0, TINYUCD_GC_MN, 129, 4, 2, 0, 0, 0, 0},      // 0x0F71
    {0, TINYUCD_GC_MN, 130, 4, 2, 0, 0, 0, 0},      // 6 codepoints in range [0x0F72, 0x0F80]
    {5, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 468, 0},      // 0x0F73
    {0, TINYUCD_GC_MN, 132, 4, 2, 0, 0, 0, 0},      // 0x0F74
    {5, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 469, 0},      // 0x0F75
    {5, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 470, 0},      // 0x0F76
    {4, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 471, 0},      // 0x0F77
    {5, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 472, 0},      // 0x0F78
    {4, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 473, 0},      // 0x0F79
    {5, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 474, 0},      // 0x0F81
    {5, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 475, 0},      // 0x0F93
    {5, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 476, 0},      // 0x0F9D
    {5, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 477, 0},      // 0x0FA2
    {5, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 478, 0},      // 0x0FA7
    {5, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 479, 0},      // 0x0FAC
    {5, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 480, 0},      // 0x0FB9
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 0, 184},      // 0x1025
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 481, 0},      // 0x1026
    {0, TINYUCD_GC_MC, 0, 0, 0, 0, 0, 0, 0},        // 31 codepoints in range [0x102B, 0x011721]
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 969, 0, 0},      // 'Ⴀ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 970, 0, 0},      // 'Ⴁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 971, 0, 0},      // 'Ⴂ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 972, 0, 0},      // 'Ⴃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 973, 0, 0},      // 'Ⴄ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 974, 0, 0},      // 'Ⴅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 975, 0, 0},      // 'Ⴆ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 976, 0, 0},      // 'Ⴇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 977, 0, 0},      // 'Ⴈ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 978, 0, 0},      // 'Ⴉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 979, 0, 0},      // 'Ⴊ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 980, 0, 0},      // 'Ⴋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 981, 0, 0},      // 'Ⴌ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 982, 0, 0},      // 'Ⴍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 983, 0, 0},      // 'Ⴎ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 984, 0, 0},      // 'Ⴏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 985, 0, 0},      // 'Ⴐ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 986, 0, 0},      // 'Ⴑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 987, 0, 0},      // 'Ⴒ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 988, 0, 0},      // 'Ⴓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 989, 0, 0},      // 'Ⴔ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 990, 0, 0},      // 'Ⴕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 991, 0, 0},      // 'Ⴖ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 992, 0, 0},      // 'Ⴗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 993, 0, 0},      // 'Ⴘ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 994, 0, 0},      // 'Ⴙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 995, 0, 0},      // 'Ⴚ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 996, 0, 0},      // 'Ⴛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 997, 0, 0},      // 'Ⴜ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 998, 0, 0},      // 'Ⴝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 999, 0, 0},      // 'Ⴞ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1000, 0, 0},     // 'Ⴟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1001, 0, 0},     // 'Ⴠ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1002, 0, 0},     // 'Ⴡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1003, 0, 0},     // 'Ⴢ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1004, 0, 0},     // 'Ⴣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1005, 0, 0},     // 'Ⴤ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1006, 0, 0},     // 'Ⴥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1007, 0, 0},     // 'Ⴧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1008, 0, 0},     // 'Ⴭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1009, 0, 0},     // 'ა'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1010, 0, 0},     // 'ბ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1011, 0, 0},     // 'გ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1012, 0, 0},     // 'დ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1013, 0, 0},     // 'ე'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1014, 0, 0},     // 'ვ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1015, 0, 0},     // 'ზ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1016, 0, 0},     // 'თ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1017, 0, 0},     // 'ი'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1018, 0, 0},     // 'კ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1019, 0, 0},     // 'ლ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1020, 0, 0},     // 'მ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1021, 0, 0},     // 'ნ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1022, 0, 0},     // 'ო'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1023, 0, 0},     // 'პ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1024, 0, 0},     // 'ჟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1025, 0, 0},     // 'რ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1026, 0, 0},     // 'ს'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1027, 0, 0},     // 'ტ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1028, 0, 0},     // 'უ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1029, 0, 0},     // 'ფ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1030, 0, 0},     // 'ქ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1031, 0, 0},     // 'ღ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1032, 0, 0},     // 'ყ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1033, 0, 0},     // 'შ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1034, 0, 0},     // 'ჩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1035, 0, 0},     // 'ც'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1036, 0, 0},     // 'ძ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1037, 0, 0},     // 'წ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1038, 0, 0},     // 'ჭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1039, 0, 0},     // 'ხ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1040, 0, 0},     // 'ჯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1041, 0, 0},     // 'ჰ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1042, 0, 0},     // 'ჱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1043, 0, 0},     // 'ჲ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1044, 0, 0},     // 'ჳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1045, 0, 0},     // 'ჴ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1046, 0, 0},     // 'ჵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1047, 0, 0},     // 'ჶ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1048, 0, 0},     // 'ჷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1049, 0, 0},     // 'ჸ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1050, 0, 0},     // 'ჹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1051, 0, 0},     // 'ჺ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 482, 0},      // 'ჼ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1052, 0, 0},     // 'ჽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1053, 0, 0},     // 'ჾ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1054, 0, 0},     // 'ჿ'
    {0, TINYUCD_GC_LO, 0, 9, 0, 0, 0, 0, 0},        // 125 codepoints in range [0x1100, 0xA97C]
    {0, TINYUCD_GC_LO, 0, 10, 0, 0, 0, 0, 0},       // 95 codepoints in range [0x1160, 0xD7C6]
    {0, TINYUCD_GC_LO, 0, 11, 0, 0, 0, 0, 0},       // 137 codepoints in range [0x11A8, 0xD7FB]
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1055, 0, 0},     // 'Ꭰ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1056, 0, 0},     // 'Ꭱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1057, 0, 0},     // 'Ꭲ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1058, 0, 0},     // 'Ꭳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1059, 0, 0},     // 'Ꭴ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1060, 0, 0},     // 'Ꭵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1061, 0, 0},     // 'Ꭶ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1062, 0, 0},     // 'Ꭷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1063, 0, 0},     // 'Ꭸ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1064, 0, 0},     // 'Ꭹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1065, 0, 0},     // 'Ꭺ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1066, 0, 0},     // 'Ꭻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1067, 0, 0},     // 'Ꭼ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1068, 0, 0},     // 'Ꭽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1069, 0, 0},     // 'Ꭾ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1070, 0, 0},     // 'Ꭿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1071, 0, 0},     // 'Ꮀ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1072, 0, 0},     // 'Ꮁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1073, 0, 0},     // 'Ꮂ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1074, 0, 0},     // 'Ꮃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1075, 0, 0},     // 'Ꮄ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1076, 0, 0},     // 'Ꮅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1077, 0, 0},     // 'Ꮆ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1078, 0, 0},     // 'Ꮇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1079, 0, 0},     // 'Ꮈ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1080, 0, 0},     // 'Ꮉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1081, 0, 0},     // 'Ꮊ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1082, 0, 0},     // 'Ꮋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1083, 0, 0},     // 'Ꮌ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1084, 0, 0},     // 'Ꮍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1085, 0, 0},     // 'Ꮎ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1086, 0, 0},     // 'Ꮏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1087, 0, 0},     // 'Ꮐ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1088, 0, 0},     // 'Ꮑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1089, 0, 0},     // 'Ꮒ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1090, 0, 0},     // 'Ꮓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1091, 0, 0},     // 'Ꮔ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1092, 0, 0},     // 'Ꮕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1093, 0, 0},     // 'Ꮖ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1094, 0, 0},     // 'Ꮗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1095, 0, 0},     // 'Ꮘ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1096, 0, 0},     // 'Ꮙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1097, 0, 0},     // 'Ꮚ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1098, 0, 0},     // 'Ꮛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1099, 0, 0},     // 'Ꮜ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1100, 0, 0},     // 'Ꮝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1101, 0, 0},     // 'Ꮞ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1102, 0, 0},     // 'Ꮟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1103, 0, 0},     // 'Ꮠ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1104, 0, 0},     // 'Ꮡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1105, 0, 0},     // 'Ꮢ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1106, 0, 0},     // 'Ꮣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1107, 0, 0},     // 'Ꮤ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1108, 0, 0},     // 'Ꮥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1109, 0, 0},     // 'Ꮦ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1110, 0, 0},     // 'Ꮧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1111, 0, 0},     // 'Ꮨ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1112, 0, 0},     // 'Ꮩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1113, 0, 0},     // 'Ꮪ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1114, 0, 0},     // 'Ꮫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1115, 0, 0},     // 'Ꮬ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1116, 0, 0},     // 'Ꮭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1117, 0, 0},     // 'Ꮮ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1118, 0, 0},     // 'Ꮯ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1119, 0, 0},     // 'Ꮰ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1120, 0, 0},     // 'Ꮱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1121, 0, 0},     // 'Ꮲ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1122, 0, 0},     // 'Ꮳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1123, 0, 0},     // 'Ꮴ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1124, 0, 0},     // 'Ꮵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1125, 0, 0},     // 'Ꮶ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1126, 0, 0},     // 'Ꮷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1127, 0, 0},     // 'Ꮸ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1128, 0, 0},     // 'Ꮹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1129, 0, 0},     // 'Ꮺ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1130, 0, 0},     // 'Ꮻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1131, 0, 0},     // 'Ꮼ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1132, 0, 0},     // 'Ꮽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1133, 0, 0},     // 'Ꮾ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1134, 0, 0},     // 'Ꮿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1135, 0, 0},     // 'Ᏸ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1136, 0, 0},     // 'Ᏹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1137, 0, 0},     // 'Ᏺ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1138, 0, 0},     // 'Ᏻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1139, 0, 0},     // 'Ᏼ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1140, 0, 0},     // 'Ᏽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1141, 0, 0},     // 'ᏸ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1142, 0, 0},     // 'ᏹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1143, 0, 0},     // 'ᏺ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1144, 0, 0},     // 'ᏻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1145, 0, 0},     // 'ᏼ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1146, 0, 0},     // 'ᏽ'
    {0, TINYUCD_GC_NL, 0, 0, 0, 0, 0, 0, 0},        // 204 codepoints in range [0x16EE, 0x016FF6]
    {0, TINYUCD_GC_MC, 9, 4, 2, 0, 0, 0, 0},        // 13 codepoints in range [0x1715, 0x011F41]
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 185},      // 0x1B05
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 483, 0},      // 0x1B06
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 186},      // 0x1B07
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 484, 0},      // 0x1B08
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 187},      // 0x1B09
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 485, 0},      // 0x1B0A
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 0, 188},      // 0x1B0B
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 486, 0},      // 0x1B0C
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 189},      // 0x1B0D
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 487, 0},      // 0x1B0E
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 190},      // 0x1B11
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 488, 0},      // 0x1B12
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 191},      // 0x1B3A
    {0, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 489, 0},      // 0x1B3B
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 192},      // 0x1B3C
    {0, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 490, 0},      // 0x1B3D
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 193},      // 0x1B3E
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 194},      // 0x1B3F
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 491, 0},      // 0x1B40
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 492, 0},      // 0x1B41
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 195},      // 0x1B42
    {0, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 493, 0},      // 0x1B43
    {0, TINYUCD_GC_MC, 9, 4, 3, 0, 0, 0, 0},        // 2 codepoints in range [0x1B44, 0xA9C0]
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1147, 0, 0},     // 'ᲀ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1148, 0, 0},     // 'ᲁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1149, 0, 0},     // 'ᲂ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1150, 0, 0},     // 'ᲃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1151, 0, 0},     // 'ᲄ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1152, 0, 0},     // 'ᲅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1153, 0, 0},     // 'ᲆ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1154, 0, 0},     // 'ᲇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1155, 0, 0},     // 'ᲈ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1156, 0, 0},     // 'Ᲊ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1157, 0, 0},     // 'ᲊ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1158, 0, 0},     // 'Ა'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1159, 0, 0},     // 'Ბ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1160, 0, 0},     // 'Გ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1161, 0, 0},     // 'Დ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1162, 0, 0},     // 'Ე'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1163, 0, 0},     // 'Ვ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1164, 0, 0},     // 'Ზ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1165, 0, 0},     // 'Თ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1166, 0, 0},     // 'Ი'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1167, 0, 0},     // 'Კ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1168, 0, 0},     // 'Ლ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1169, 0, 0},     // 'Მ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1170, 0, 0},     // 'Ნ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1171, 0, 0},     // 'Ო'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1172, 0, 0},     // 'Პ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1173, 0, 0},     // 'Ჟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1174, 0, 0},     // 'Რ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1175, 0, 0},     // 'Ს'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1176, 0, 0},     // 'Ტ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1177, 0, 0},     // 'Უ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1178, 0, 0},     // 'Ფ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1179, 0, 0},     // 'Ქ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1180, 0, 0},     // 'Ღ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1181, 0, 0},     // 'Ყ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1182, 0, 0},     // 'Შ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1183, 0, 0},     // 'Ჩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1184, 0, 0},     // 'Ც'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1185, 0, 0},     // 'Ძ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1186, 0, 0},     // 'Წ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1187, 0, 0},     // 'Ჭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1188, 0, 0},     // 'Ხ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1189, 0, 0},     // 'Ჯ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1190, 0, 0},     // 'Ჰ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1191, 0, 0},     // 'Ჱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1192, 0, 0},     // 'Ჲ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1193, 0, 0},     // 'Ჳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1194, 0, 0},     // 'Ჴ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1195, 0, 0},     // 'Ჵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1196, 0, 0},     // 'Ჶ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1197, 0, 0},     // 'Ჷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1198, 0, 0},     // 'Ჸ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1199, 0, 0},     // 'Ჹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1200, 0, 0},     // 'Ჺ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1201, 0, 0},     // 'Ჽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1202, 0, 0},     // 'Ჾ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1203, 0, 0},     // 'Ჿ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 494, 0},      // 'ᴬ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 495, 0},      // 'ᴭ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 496, 0},      // 'ᴮ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 497, 0},      // 'ᴰ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 498, 0},      // 'ᴱ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 499, 0},      // 'ᴲ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 500, 0},      // 'ᴳ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 501, 0},      // 'ᴴ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 502, 0},      // 'ᴵ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 503, 0},      // 'ᴶ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 504, 0},      // 'ᴷ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 505, 0},      // 'ᴸ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 506, 0},      // 'ᴹ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 507, 0},      // 'ᴺ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 508, 0},      // 'ᴼ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 509, 0},      // 'ᴽ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 510, 0},      // 'ᴾ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 511, 0},      // 'ᴿ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 512, 0},      // 'ᵀ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 513, 0},      // 'ᵁ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 514, 0},      // 'ᵂ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 515, 0},      // 'ᵃ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 516, 0},      // 'ᵄ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 517, 0},      // 'ᵅ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 518, 0},      // 'ᵆ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 519, 0},      // 'ᵇ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 520, 0},      // 'ᵈ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 521, 0},      // 'ᵉ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 522, 0},      // 'ᵊ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 523, 0},      // 'ᵋ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 524, 0},      // 'ᵌ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 525, 0},      // 'ᵍ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 526, 0},      // 'ᵏ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 527, 0},      // 'ᵐ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 528, 0},      // 'ᵑ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 529, 0},      // 'ᵒ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 530, 0},      // 'ᵓ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 531, 0},      // 'ᵔ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 532, 0},      // 'ᵕ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 533, 0},      // 'ᵖ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 534, 0},      // 'ᵗ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 535, 0},      // 'ᵘ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 536, 0},      // 'ᵙ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 537, 0},      // 'ᵚ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 538, 0},      // 'ᵛ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 539, 0},      // 'ᵜ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 540, 0},      // 'ᵝ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 541, 0},      // 'ᵞ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 542, 0},      // 'ᵟ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 543, 0},      // 'ᵠ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 544, 0},      // 'ᵡ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 545, 0},      // 'ᵢ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 546, 0},      // 'ᵣ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 547, 0},      // 'ᵤ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 548, 0},      // 'ᵥ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 549, 0},      // 'ᵦ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 550, 0},      // 'ᵧ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 551, 0},      // 'ᵨ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 552, 0},      // 'ᵩ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 553, 0},      // 'ᵪ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 554, 0},      // 'ᵸ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1204, 0, 0},     // 'ᵹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1205, 0, 0},     // 'ᵽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1206, 0, 0},     // 'ᶎ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 555, 0},      // 'ᶛ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 556, 0},      // 'ᶜ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 557, 0},      // 'ᶝ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 558, 0},      // 'ᶞ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 559, 0},      // 'ᶟ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 560, 0},      // 'ᶠ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 561, 0},      // 'ᶡ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 562, 0},      // 'ᶢ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 563, 0},      // 'ᶣ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 564, 0},      // 'ᶤ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 565, 0},      // 'ᶥ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 566, 0},      // 'ᶦ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 567, 0},      // 'ᶧ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 568, 0},      // 'ᶨ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 569, 0},      // 'ᶩ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 570, 0},      // 'ᶪ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 571, 0},      // 'ᶫ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 572, 0},      // 'ᶬ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 573, 0},      // 'ᶭ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 574, 0},      // 'ᶮ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 575, 0},      // 'ᶯ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 576, 0},      // 'ᶰ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 577, 0},      // 'ᶱ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 578, 0},      // 'ᶲ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 579, 0},      // 'ᶳ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 580, 0},      // 'ᶴ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 581, 0},      // 'ᶵ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 582, 0},      // 'ᶶ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 583, 0},      // 'ᶷ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 584, 0},      // 'ᶸ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 585, 0},      // 'ᶹ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 586, 0},      // 'ᶺ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 587, 0},      // 'ᶻ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 588, 0},      // 'ᶼ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 589, 0},      // 'ᶽ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 590, 0},      // 'ᶾ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 591, 0},      // 'ᶿ'
    {0, TINYUCD_GC_MN, 214, 4, 2, 0, 0, 0, 0},      // 0x1DCE
    {0, TINYUCD_GC_MN, 218, 4, 2, 0, 0, 0, 0},      // 2 codepoints in range [0x1DFA, 0x302A]
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1207, 592, 0},   // 'Ḁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1208, 593, 0},   // 'ḁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1209, 594, 0},   // 'Ḃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1210, 595, 0},   // 'ḃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1211, 596, 0},   // 'Ḅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1212, 597, 0},   // 'ḅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1213, 598, 0},   // 'Ḇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1214, 599, 0},   // 'ḇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1215, 600, 0},   // 'Ḉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1216, 601, 0},   // 'ḉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1217, 602, 0},   // 'Ḋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1218, 603, 0},   // 'ḋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1219, 604, 0},   // 'Ḍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1220, 605, 0},   // 'ḍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1221, 606, 0},   // 'Ḏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1222, 607, 0},   // 'ḏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1223, 608, 0},   // 'Ḑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1224, 609, 0},   // 'ḑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1225, 610, 0},   // 'Ḓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1226, 611, 0},   // 'ḓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1227, 612, 0},   // 'Ḕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1228, 613, 0},   // 'ḕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1229, 614, 0},   // 'Ḗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1230, 615, 0},   // 'ḗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1231, 616, 0},   // 'Ḙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1232, 617, 0},   // 'ḙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1233, 618, 0},   // 'Ḛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1234, 619, 0},   // 'ḛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1235, 620, 0},   // 'Ḝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1236, 621, 0},   // 'ḝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1237, 622, 0},   // 'Ḟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1238, 623, 0},   // 'ḟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1239, 624, 0},   // 'Ḡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1240, 625, 0},   // 'ḡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1241, 626, 0},   // 'Ḣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1242, 627, 0},   // 'ḣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1243, 628, 0},   // 'Ḥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1244, 629, 0},   // 'ḥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1245, 630, 0},   // 'Ḧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1246, 631, 0},   // 'ḧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1247, 632, 0},   // 'Ḩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1248, 633, 0},   // 'ḩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1249, 634, 0},   // 'Ḫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1250, 635, 0},   // 'ḫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1251, 636, 0},   // 'Ḭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1252, 637, 0},   // 'ḭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1253, 638, 0},   // 'Ḯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1254, 639, 0},   // 'ḯ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1255, 640, 0},   // 'Ḱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1256, 641, 0},   // 'ḱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1257, 642, 0},   // 'Ḳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1258, 643, 0},   // 'ḳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1259, 644, 0},   // 'Ḵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1260, 645, 0},   // 'ḵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1261, 646, 196}, // 'Ḷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1262, 647, 197}, // 'ḷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1263, 648, 0},   // 'Ḹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1264, 649, 0},   // 'ḹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1265, 650, 0},   // 'Ḻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1266, 651, 0},   // 'ḻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1267, 652, 0},   // 'Ḽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1268, 653, 0},   // 'ḽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1269, 654, 0},   // 'Ḿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1270, 655, 0},   // 'ḿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1271, 656, 0},   // 'Ṁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1272, 657, 0},   // 'ṁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1273, 658, 0},   // 'Ṃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1274, 659, 0},   // 'ṃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1275, 660, 0},   // 'Ṅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1276, 661, 0},   // 'ṅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1277, 662, 0},   // 'Ṇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1278, 663, 0},   // 'ṇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1279, 664, 0},   // 'Ṉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1280, 665, 0},   // 'ṉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1281, 666, 0},   // 'Ṋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1282, 667, 0},   // 'ṋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1283, 668, 0},   // 'Ṍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1284, 669, 0},   // 'ṍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1285, 670, 0},   // 'Ṏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1286, 671, 0},   // 'ṏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1287, 672, 0},   // 'Ṑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1288, 673, 0},   // 'ṑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1289, 674, 0},   // 'Ṓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1290, 675, 0},   // 'ṓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1291, 676, 0},   // 'Ṕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1292, 677, 0},   // 'ṕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1293, 678, 0},   // 'Ṗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1294, 679, 0},   // 'ṗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1295, 680, 0},   // 'Ṙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1296, 681, 0},   // 'ṙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1297, 682, 198}, // 'Ṛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1298, 683, 199}, // 'ṛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1299, 684, 0},   // 'Ṝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1300, 685, 0},   // 'ṝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1301, 686, 0},   // 'Ṟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1302, 687, 0},   // 'ṟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1303, 688, 0},   // 'Ṡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1304, 689, 0},   // 'ṡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1305, 690, 200}, // 'Ṣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1306, 691, 201}, // 'ṣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1307, 692, 0},   // 'Ṥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1308, 693, 0},   // 'ṥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1309, 694, 0},   // 'Ṧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1310, 695, 0},   // 'ṧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1311, 696, 0},   // 'Ṩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1312, 697, 0},   // 'ṩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1313, 698, 0},   // 'Ṫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1314, 699, 0},   // 'ṫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1315, 700, 0},   // 'Ṭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1316, 701, 0},   // 'ṭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1317, 702, 0},   // 'Ṯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1318, 703, 0},   // 'ṯ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1319, 704, 0},   // 'Ṱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1320, 705, 0},   // 'ṱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1321, 706, 0},   // 'Ṳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1322, 707, 0},   // 'ṳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1323, 708, 0},   // 'Ṵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1324, 709, 0},   // 'ṵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1325, 710, 0},   // 'Ṷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1326, 711, 0},   // 'ṷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1327, 712, 0},   // 'Ṹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1328, 713, 0},   // 'ṹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1329, 714, 0},   // 'Ṻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1330, 715, 0},   // 'ṻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1331, 716, 0},   // 'Ṽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1332, 717, 0},   // 'ṽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1333, 718, 0},   // 'Ṿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1334, 719, 0},   // 'ṿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1335, 720, 0},   // 'Ẁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1336, 721, 0},   // 'ẁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1337, 722, 0},   // 'Ẃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1338, 723, 0},   // 'ẃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1339, 724, 0},   // 'Ẅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1340, 725, 0},   // 'ẅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1341, 726, 0},   // 'Ẇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1342, 727, 0},   // 'ẇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1343, 728, 0},   // 'Ẉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1344, 729, 0},   // 'ẉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1345, 730, 0},   // 'Ẋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1346, 731, 0},   // 'ẋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1347, 732, 0},   // 'Ẍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1348, 733, 0},   // 'ẍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1349, 734, 0},   // 'Ẏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1350, 735, 0},   // 'ẏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1351, 736, 0},   // 'Ẑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1352, 737, 0},   // 'ẑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1353, 738, 0},   // 'Ẓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1354, 739, 0},   // 'ẓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1355, 740, 0},   // 'Ẕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1356, 741, 0},   // 'ẕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1357, 742, 0},   // 'ẖ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1358, 743, 0},   // 'ẗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1359, 744, 0},   // 'ẘ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1360, 745, 0},   // 'ẙ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 1361, 746, 0},   // 'ẚ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 1362, 747, 0},   // 'ẛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1363, 0, 0},     // 'ẞ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1364, 748, 202}, // 'Ạ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1365, 749, 203}, // 'ạ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1366, 750, 0},   // 'Ả'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1367, 751, 0},   // 'ả'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1368, 752, 0},   // 'Ấ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1369, 753, 0},   // 'ấ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1370, 754, 0},   // 'Ầ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1371, 755, 0},   // 'ầ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1372, 756, 0},   // 'Ẩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1373, 757, 0},   // 'ẩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1374, 758, 0},   // 'Ẫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1375, 759, 0},   // 'ẫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1376, 760, 0},   // 'Ậ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1377, 761, 0},   // 'ậ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1378, 762, 0},   // 'Ắ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1379, 763, 0},   // 'ắ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1380, 764, 0},   // 'Ằ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1381, 765, 0},   // 'ằ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1382, 766, 0},   // 'Ẳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1383, 767, 0},   // 'ẳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1384, 768, 0},   // 'Ẵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1385, 769, 0},   // 'ẵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1386, 770, 0},   // 'Ặ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1387, 771, 0},   // 'ặ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1388, 772, 204}, // 'Ẹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1389, 773, 205}, // 'ẹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1390, 774, 0},   // 'Ẻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1391, 775, 0},   // 'ẻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1392, 776, 0},   // 'Ẽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1393, 777, 0},   // 'ẽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1394, 778, 0},   // 'Ế'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1395, 779, 0},   // 'ế'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1396, 780, 0},   // 'Ề'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1397, 781, 0},   // 'ề'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1398, 782, 0},   // 'Ể'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1399, 783, 0},   // 'ể'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1400, 784, 0},   // 'Ễ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1401, 785, 0},   // 'ễ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1402, 786, 0},   // 'Ệ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1403, 787, 0},   // 'ệ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1404, 788, 0},   // 'Ỉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1405, 789, 0},   // 'ỉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1406, 790, 0},   // 'Ị'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1407, 791, 0},   // 'ị'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1408, 792, 206}, // 'Ọ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1409, 793, 207}, // 'ọ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1410, 794, 0},   // 'Ỏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1411, 795, 0},   // 'ỏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1412, 796, 0},   // 'Ố'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1413, 797, 0},   // 'ố'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1414, 798, 0},   // 'Ồ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1415, 799, 0},   // 'ồ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1416, 800, 0},   // 'Ổ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1417, 801, 0},   // 'ổ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1418, 802, 0},   // 'Ỗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1419, 803, 0},   // 'ỗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1420, 804, 0},   // 'Ộ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1421, 805, 0},   // 'ộ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1422, 806, 0},   // 'Ớ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1423, 807, 0},   // 'ớ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1424, 808, 0},   // 'Ờ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1425, 809, 0},   // 'ờ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1426, 810, 0},   // 'Ở'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1427, 811, 0},   // 'ở'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1428, 812, 0},   // 'Ỡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1429, 813, 0},   // 'ỡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1430, 814, 0},   // 'Ợ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1431, 815, 0},   // 'ợ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1432, 816, 0},   // 'Ụ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1433, 817, 0},   // 'ụ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1434, 818, 0},   // 'Ủ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1435, 819, 0},   // 'ủ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1436, 820, 0},   // 'Ứ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1437, 821, 0},   // 'ứ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1438, 822, 0},   // 'Ừ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1439, 823, 0},   // 'ừ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1440, 824, 0},   // 'Ử'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1441, 825, 0},   // 'ử'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1442, 826, 0},   // 'Ữ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1443, 827, 0},   // 'ữ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1444, 828, 0},   // 'Ự'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1445, 829, 0},   // 'ự'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1446, 830, 0},   // 'Ỳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1447, 831, 0},   // 'ỳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1448, 832, 0},   // 'Ỵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1449, 833, 0},   // 'ỵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1450, 834, 0},   // 'Ỷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1451, 835, 0},   // 'ỷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1452, 836, 0},   // 'Ỹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1453, 837, 0},   // 'ỹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1454, 0, 0},     // 'Ỻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1455, 0, 0},     // 'ỻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1456, 0, 0},     // 'Ỽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1457, 0, 0},     // 'ỽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1458, 0, 0},     // 'Ỿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1459, 0, 0},     // 'ỿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1460, 838, 208}, // 'ἀ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1461, 839, 209}, // 'ἁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1462, 840, 210}, // 'ἂ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1463, 841, 211}, // 'ἃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1464, 842, 212}, // 'ἄ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1465, 843, 213}, // 'ἅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1466, 844, 214}, // 'ἆ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1467, 845, 215}, // 'ἇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1468, 846, 216}, // 'Ἀ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1469, 847, 217}, // 'Ἁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1470, 848, 218}, // 'Ἂ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1471, 849, 219}, // 'Ἃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1472, 850, 220}, // 'Ἄ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1473, 851, 221}, // 'Ἅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1474, 852, 222}, // 'Ἆ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1475, 853, 223}, // 'Ἇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1476, 854, 224}, // 'ἐ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1477, 855, 225}, // 'ἑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1478, 856, 0},   // 'ἒ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1479, 857, 0},   // 'ἓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1480, 858, 0},   // 'ἔ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1481, 859, 0},   // 'ἕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1482, 860, 226}, // 'Ἐ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1483, 861, 227}, // 'Ἑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1484, 862, 0},   // 'Ἒ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1485, 863, 0},   // 'Ἓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1486, 864, 0},   // 'Ἔ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1487, 865, 0},   // 'Ἕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1488, 866, 228}, // 'ἠ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1489, 867, 229}, // 'ἡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1490, 868, 230}, // 'ἢ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1491, 869, 231}, // 'ἣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1492, 870, 232}, // 'ἤ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1493, 871, 233}, // 'ἥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1494, 872, 234}, // 'ἦ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1495, 873, 235}, // 'ἧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1496, 874, 236}, // 'Ἠ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1497, 875, 237}, // 'Ἡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1498, 876, 238}, // 'Ἢ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1499, 877, 239}, // 'Ἣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1500, 878, 240}, // 'Ἤ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1501, 879, 241}, // 'Ἥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1502, 880, 242}, // 'Ἦ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1503, 881, 243}, // 'Ἧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1504, 882, 244}, // 'ἰ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1505, 883, 245}, // 'ἱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1506, 884, 0},   // 'ἲ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1507, 885, 0},   // 'ἳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1508, 886, 0},   // 'ἴ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1509, 887, 0},   // 'ἵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1510, 888, 0},   // 'ἶ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1511, 889, 0},   // 'ἷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1512, 890, 246}, // 'Ἰ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1513, 891, 247}, // 'Ἱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1514, 892, 0},   // 'Ἲ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1515, 893, 0},   // 'Ἳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1516, 894, 0},   // 'Ἴ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1517, 895, 0},   // 'Ἵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1518, 896, 0},   // 'Ἶ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1519, 897, 0},   // 'Ἷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1520, 898, 248}, // 'ὀ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1521, 899, 249}, // 'ὁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1522, 900, 0},   // 'ὂ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1523, 901, 0},   // 'ὃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1524, 902, 0},   // 'ὄ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1525, 903, 0},   // 'ὅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1526, 904, 250}, // 'Ὀ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1527, 905, 251}, // 'Ὁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1528, 906, 0},   // 'Ὂ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1529, 907, 0},   // 'Ὃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1530, 908, 0},   // 'Ὄ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1531, 909, 0},   // 'Ὅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1532, 910, 252}, // 'ὐ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1533, 911, 253}, // 'ὑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1534, 912, 0},   // 'ὒ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1535, 913, 0},   // 'ὓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1536, 914, 0},   // 'ὔ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1537, 915, 0},   // 'ὕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1538, 916, 0},   // 'ὖ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1539, 917, 0},   // 'ὗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1540, 918, 254}, // 'Ὑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1541, 919, 0},   // 'Ὓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1542, 920, 0},   // 'Ὕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1543, 921, 0},   // 'Ὗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1544, 922, 255}, // 'ὠ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1545, 923, 256}, // 'ὡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1546, 924, 257}, // 'ὢ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1547, 925, 258}, // 'ὣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1548, 926, 259}, // 'ὤ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1549, 927, 260}, // 'ὥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1550, 928, 261}, // 'ὦ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1551, 929, 262}, // 'ὧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1552, 930, 263}, // 'Ὠ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1553, 931, 264}, // 'Ὡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1554, 932, 265}, // 'Ὢ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1555, 933, 266}, // 'Ὣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1556, 934, 267}, // 'Ὤ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1557, 935, 268}, // 'Ὥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1558, 936, 269}, // 'Ὦ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1559, 937, 270}, // 'Ὧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1560, 938, 271}, // 'ὰ'
    {5, TINYUCD_GC_LL, 0, 0, 0, 0, 1561, 939, 0},   // 'ά'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1562, 940, 0},   // 'ὲ'
    {5, TINYUCD_GC_LL, 0, 0, 0, 0, 1563, 941, 0},   // 'έ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1564, 942, 272}, // 'ὴ'
    {5, TINYUCD_GC_LL, 0, 0, 0, 0, 1565, 943, 0},   // 'ή'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1566, 944, 0},   // 'ὶ'
    {5, TINYUCD_GC_LL, 0, 0, 0, 0, 1567, 945, 0},   // 'ί'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1568, 946, 0},   // 'ὸ'
    {5, TINYUCD_GC_LL, 0, 0, 0, 0, 1569, 947, 0},   // 'ό'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1570, 948, 0},   // 'ὺ'
    {5, TINYUCD_GC_LL, 0, 0, 0, 0, 1571, 949, 0},   // 'ύ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1572, 950, 273}, // 'ὼ'
    {5, TINYUCD_GC_LL, 0, 0, 0, 0, 1573, 951, 0},   // 'ώ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1574, 952, 0},   // 'ᾀ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1575, 953, 0},   // 'ᾁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1576, 954, 0},   // 'ᾂ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1577, 955, 0},   // 'ᾃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1578, 956, 0},   // 'ᾄ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1579, 957, 0},   // 'ᾅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1580, 958, 0},   // 'ᾆ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1581, 959, 0},   // 'ᾇ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1582, 960, 0},   // 'ᾈ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1583, 961, 0},   // 'ᾉ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1584, 962, 0},   // 'ᾊ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1585, 963, 0},   // 'ᾋ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1586, 964, 0},   // 'ᾌ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1587, 965, 0},   // 'ᾍ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1588, 966, 0},   // 'ᾎ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1589, 967, 0},   // 'ᾏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1590, 968, 0},   // 'ᾐ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1591, 969, 0},   // 'ᾑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1592, 970, 0},   // 'ᾒ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1593, 971, 0},   // 'ᾓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1594, 972, 0},   // 'ᾔ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1595, 973, 0},   // 'ᾕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1596, 974, 0},   // 'ᾖ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1597, 975, 0},   // 'ᾗ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1598, 976, 0},   // 'ᾘ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1599, 977, 0},   // 'ᾙ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1600, 978, 0},   // 'ᾚ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1601, 979, 0},   // 'ᾛ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1602, 980, 0},   // 'ᾜ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1603, 981, 0},   // 'ᾝ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1604, 982, 0},   // 'ᾞ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1605, 983, 0},   // 'ᾟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1606, 984, 0},   // 'ᾠ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1607, 985, 0},   // 'ᾡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1608, 986, 0},   // 'ᾢ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1609, 987, 0},   // 'ᾣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1610, 988, 0},   // 'ᾤ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1611, 989, 0},   // 'ᾥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1612, 990, 0},   // 'ᾦ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1613, 991, 0},   // 'ᾧ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1614, 992, 0},   // 'ᾨ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1615, 993, 0},   // 'ᾩ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1616, 994, 0},   // 'ᾪ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1617, 995, 0},   // 'ᾫ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1618, 996, 0},   // 'ᾬ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1619, 997, 0},   // 'ᾭ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1620, 998, 0},   // 'ᾮ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1621, 999, 0},   // 'ᾯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1622, 1000, 0},  // 'ᾰ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1623, 1001, 0},  // 'ᾱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1624, 1002, 0},  // 'ᾲ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1625, 1003, 0},  // 'ᾳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1626, 1004, 0},  // 'ᾴ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1627, 1005, 274}, // 'ᾶ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1628, 1006, 0},   // 'ᾷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1629, 1007, 0},   // 'Ᾰ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1630, 1008, 0},   // 'Ᾱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1631, 1009, 0},   // 'Ὰ'
    {5, TINYUCD_GC_LU, 0, 0, 0, 0, 1632, 1010, 0},   // 'Ά'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1633, 1011, 0},   // 'ᾼ'
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1012, 0},      // 0x1FBD
    {5, TINYUCD_GC_LL, 0, 0, 0, 0, 1634, 1013, 0},   // 'ι'
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1014, 275},    // 0x1FBF
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1015, 0},      // 0x1FC0
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1016, 0},      // 0x1FC1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1635, 1017, 0},   // 'ῂ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1636, 1018, 0},   // 'ῃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1637, 1019, 0},   // 'ῄ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1638, 1020, 276}, // 'ῆ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1639, 1021, 0},   // 'ῇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1640, 1022, 0},   // 'Ὲ'
    {5, TINYUCD_GC_LU, 0, 0, 0, 0, 1641, 1023, 0},   // 'Έ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1642, 1024, 0},   // 'Ὴ'
    {5, TINYUCD_GC_LU, 0, 0, 0, 0, 1643, 1025, 0},   // 'Ή'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1644, 1026, 0},   // 'ῌ'
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1027, 0},      // 0x1FCD
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1028, 0},      // 0x1FCE
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1029, 0},      // 0x1FCF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1645, 1030, 0},   // 'ῐ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1646, 1031, 0},   // 'ῑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1647, 1032, 0},   // 'ῒ'
    {5, TINYUCD_GC_LL, 0, 0, 0, 0, 1648, 1033, 0},   // 'ΐ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1649, 1034, 0},   // 'ῖ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1650, 1035, 0},   // 'ῗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1651, 1036, 0},   // 'Ῐ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1652, 1037, 0},   // 'Ῑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1653, 1038, 0},   // 'Ὶ'
    {5, TINYUCD_GC_LU, 0, 0, 0, 0, 1654, 1039, 0},   // 'Ί'
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1040, 0},      // 0x1FDD
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1041, 0},      // 0x1FDE
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1042, 0},      // 0x1FDF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1655, 1043, 0},   // 'ῠ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1656, 1044, 0},   // 'ῡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1657, 1045, 0},   // 'ῢ'
    {5, TINYUCD_GC_LL, 0, 0, 0, 0, 1658, 1046, 0},   // 'ΰ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1659, 1047, 0},   // 'ῤ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1660, 1048, 0},   // 'ῥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1661, 1049, 0},   // 'ῦ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1662, 1050, 0},   // 'ῧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1663, 1051, 0},   // 'Ῠ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1664, 1052, 0},   // 'Ῡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1665, 1053, 0},   // 'Ὺ'
    {5, TINYUCD_GC_LU, 0, 0, 0, 0, 1666, 1054, 0},   // 'Ύ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1667, 1055, 0},   // 'Ῥ'
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1056, 0},      // 0x1FED
    {5, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1057, 0},      // 0x1FEE
    {5, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1058, 0},      // 0x1FEF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1668, 1059, 0},   // 'ῲ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1669, 1060, 0},   // 'ῳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1670, 1061, 0},   // 'ῴ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1671, 1062, 277}, // 'ῶ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1672, 1063, 0},   // 'ῷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1673, 1064, 0},   // 'Ὸ'
    {5, TINYUCD_GC_LU, 0, 0, 0, 0, 1674, 1065, 0},   // 'Ό'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1675, 1066, 0},   // 'Ὼ'
    {5, TINYUCD_GC_LU, 0, 0, 0, 0, 1676, 1067, 0},   // 'Ώ'
    {0, TINYUCD_GC_LT, 0, 0, 0, 0, 1677, 1068, 0},   // 'ῼ'
    {5, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1069, 0},      // 0x1FFD
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1070, 278},    // 0x1FFE
    {5, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1071, 0},      // 0x2000
    {5, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1072, 0},      // 0x2001
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1073, 0},      // 0x2002
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1074, 0},      // 0x2003
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1075, 0},      // 0x2004
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1076, 0},      // 0x2005
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1077, 0},      // 0x2006
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1078, 0},      // 0x2007
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1079, 0},      // 0x2008
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1080, 0},      // 0x2009
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1081, 0},      // 0x200A
    {0, TINYUCD_GC_CF, 0, 4, 0, 0, 0, 0, 0},         // 0x200C
    {0, TINYUCD_GC_CF, 0, 5, 2, 0, 0, 0, 0},         // 0x200D
    {4, TINYUCD_GC_PD, 0, 0, 0, 0, 0, 1082, 0},      // 0x2011
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1083, 0},      // 0x2017
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1084, 0},      // 0x2024
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1085, 0},      // 0x2025
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1086, 0},      // 0x2026
    {0, TINYUCD_GC_ZL, 0, 3, 0, 0, 0, 0, 0},         // 0x2028
    {0, TINYUCD_GC_ZP, 0, 3, 0, 0, 0, 0, 0},         // 0x2029
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1087, 0},      // 0x202F
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1088, 0},      // 0x2033
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1089, 0},      // 0x2034
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1090, 0},      // 0x2036
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1091, 0},      // 0x2037
    {4, TINYUCD_GC_PO, 0, 0, 0, 1, 0, 1092, 0},      // 0x203C
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1093, 0},      // 0x203E
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1094, 0},      // 0x2047
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1095, 0},      // 0x2048
    {4, TINYUCD_GC_PO, 0, 0, 0, 1, 0, 1096, 0},      // 0x2049
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 1097, 0},      // 0x2057
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1098, 0},      // 0x205F
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1099, 0},      // '⁰'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1100, 0},      // 'ⁱ'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1101, 0},      // '⁴'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1102, 0},      // '⁵'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1103, 0},      // '⁶'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1104, 0},      // '⁷'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1105, 0},      // '⁸'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1106, 0},      // '⁹'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1107, 0},      // '⁺'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1108, 0},      // '⁻'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1109, 0},      // '⁼'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 1110, 0},      // '⁽'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 1111, 0},      // '⁾'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1112, 0},      // 'ⁿ'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1113, 0},      // '₀'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1114, 0},      // '₁'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1115, 0},      // '₂'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1116, 0},      // '₃'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1117, 0},      // '₄'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1118, 0},      // '₅'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1119, 0},      // '₆'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1120, 0},      // '₇'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1121, 0},      // '₈'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1122, 0},      // '₉'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1123, 0},      // '₊'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1124, 0},      // '₋'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1125, 0},      // '₌'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 1126, 0},      // '₍'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 1127, 0},      // '₎'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1128, 0},      // 'ₐ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1129, 0},      // 'ₑ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1130, 0},      // 'ₒ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1131, 0},      // 'ₓ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1132, 0},      // 'ₔ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1133, 0},      // 'ₕ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1134, 0},      // 'ₖ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1135, 0},      // 'ₗ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1136, 0},      // 'ₘ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1137, 0},      // 'ₙ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1138, 0},      // 'ₚ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1139, 0},      // 'ₛ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1140, 0},      // 'ₜ'
    {4, TINYUCD_GC_SC, 0, 0, 0, 0, 0, 1141, 0},      // 0x20A8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1142, 0},      // 0x2100
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1143, 0},      // 0x2101
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1144, 0},      // 'ℂ'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1145, 0},      // 0x2103
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1146, 0},      // 0x2105
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1147, 0},      // 0x2106
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1148, 0},      // 'ℇ'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1149, 0},      // 0x2109
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1150, 0},      // 'ℊ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1151, 0},      // 'ℋ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1152, 0},      // 'ℌ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1153, 0},      // 'ℍ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1154, 0},      // 'ℎ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1155, 0},      // 'ℏ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1156, 0},      // 'ℐ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1157, 0},      // 'ℑ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1158, 0},      // 'ℒ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1159, 0},      // 'ℓ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1160, 0},      // 'ℕ'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1161, 0},      // 0x2116
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1162, 0},      // 'ℙ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1163, 0},      // 'ℚ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1164, 0},      // 'ℛ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1165, 0},      // 'ℜ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1166, 0},      // 'ℝ'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1167, 0},      // 0x2120
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1168, 0},      // 0x2121
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 1169, 0},      // 0x2122
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1170, 0},      // 'ℤ'
    {5, TINYUCD_GC_LU, 0, 0, 0, 0, 1678, 1171, 0},   // 'Ω'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1172, 0},      // 'ℨ'
    {5, TINYUCD_GC_LU, 0, 0, 0, 0, 1679, 1173, 0},   // 'K'
    {5, TINYUCD_GC_LU, 0, 0, 0, 0, 1680, 1174, 0},   // 'Å'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1175, 0},      // 'ℬ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1176, 0},      // 'ℭ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1177, 0},      // 'ℯ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1178, 0},      // 'ℰ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1179, 0},      // 'ℱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1681, 0, 0},      // 'Ⅎ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1180, 0},      // 'ℳ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1181, 0},      // 'ℴ'
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1182, 0},      // 0x2135
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1183, 0},      // 0x2136
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1184, 0},      // 0x2137
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1185, 0},      // 0x2138
    {4, TINYUCD_GC_LL, 0, 0, 0, 1, 0, 1186, 0},      // 'ℹ'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1187, 0},      // 0x213B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1188, 0},      // 'ℼ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1189, 0},      // 'ℽ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1190, 0},      // 'ℾ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1191, 0},      // 'ℿ'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1192, 0},      // '⅀'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 1193, 0},      // 'ⅅ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1194, 0},      // 'ⅆ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1195, 0},      // 'ⅇ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1196, 0},      // 'ⅈ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 1197, 0},      // 'ⅉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1682, 0, 0},      // 'ⅎ'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1198, 0},      // '⅐'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1199, 0},      // '⅑'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1200, 0},      // '⅒'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1201, 0},      // '⅓'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1202, 0},      // '⅔'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1203, 0},      // '⅕'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1204, 0},      // '⅖'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1205, 0},      // '⅗'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1206, 0},      // '⅘'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1207, 0},      // '⅙'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1208, 0},      // '⅚'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1209, 0},      // '⅛'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1210, 0},      // '⅜'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1211, 0},      // '⅝'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1212, 0},      // '⅞'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1213, 0},      // '⅟'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1683, 1214, 0},   // 'Ⅰ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1684, 1215, 0},   // 'Ⅱ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1685, 1216, 0},   // 'Ⅲ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1686, 1217, 0},   // 'Ⅳ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1687, 1218, 0},   // 'Ⅴ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1688, 1219, 0},   // 'Ⅵ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1689, 1220, 0},   // 'Ⅶ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1690, 1221, 0},   // 'Ⅷ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1691, 1222, 0},   // 'Ⅸ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1692, 1223, 0},   // 'Ⅹ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1693, 1224, 0},   // 'Ⅺ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1694, 1225, 0},   // 'Ⅻ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1695, 1226, 0},   // 'Ⅼ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1696, 1227, 0},   // 'Ⅽ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1697, 1228, 0},   // 'Ⅾ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1698, 1229, 0},   // 'Ⅿ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1699, 1230, 0},   // 'ⅰ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1700, 1231, 0},   // 'ⅱ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1701, 1232, 0},   // 'ⅲ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1702, 1233, 0},   // 'ⅳ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1703, 1234, 0},   // 'ⅴ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1704, 1235, 0},   // 'ⅵ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1705, 1236, 0},   // 'ⅶ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1706, 1237, 0},   // 'ⅷ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1707, 1238, 0},   // 'ⅸ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1708, 1239, 0},   // 'ⅹ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1709, 1240, 0},   // 'ⅺ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1710, 1241, 0},   // 'ⅻ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1711, 1242, 0},   // 'ⅼ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1712, 1243, 0},   // 'ⅽ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1713, 1244, 0},   // 'ⅾ'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 1714, 1245, 0},   // 'ⅿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1715, 0, 0},      // 'Ↄ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1716, 0, 0},      // 'ↄ'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1246, 0},      // '↉'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 279},       // '←'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 280},       // '→'
    {0, TINYUCD_GC_SM, 0, 0, 0, 1, 0, 0, 281},       // '↔'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1247, 0},      // '↚'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1248, 0},      // '↛'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1249, 0},      // '↮'
    {0, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1250, 0},      // 0x21CD
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1251, 0},      // '⇎'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1252, 0},      // '⇏'
    {0, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 0, 282},       // 0x21D0
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 283},       // '⇒'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 284},       // '⇔'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 285},       // '∃'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1253, 0},      // '∄'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 286},       // '∈'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1254, 0},      // '∉'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 287},       // '∋'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1255, 0},      // '∌'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 288},       // '∣'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1256, 0},      // '∤'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 289},       // '∥'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1257, 0},      // '∦'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1258, 0},      // '∬'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1259, 0},      // '∭'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1260, 0},      // '∯'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1261, 0},      // '∰'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 290},       // '∼'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1262, 0},      // '≁'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 291},       // '≃'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1263, 0},      // '≄'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 292},       // '≅'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1264, 0},      // '≇'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 293},       // '≈'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1265, 0},      // '≉'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 294},       // '≍'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1266, 0},      // '≠'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 295},       // '≡'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1267, 0},      // '≢'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 296},       // '≤'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 297},       // '≥'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1268, 0},      // '≭'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1269, 0},      // '≮'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1270, 0},      // '≯'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1271, 0},      // '≰'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1272, 0},      // '≱'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 298},       // '≲'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 299},       // '≳'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1273, 0},      // '≴'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1274, 0},      // '≵'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 300},       // '≶'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 301},       // '≷'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1275, 0},      // '≸'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1276, 0},      // '≹'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 302},       // '≺'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 303},       // '≻'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 304},       // '≼'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 305},       // '≽'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1277, 0},      // '⊀'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1278, 0},      // '⊁'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 306},       // '⊂'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 307},       // '⊃'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1279, 0},      // '⊄'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1280, 0},      // '⊅'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 308},       // '⊆'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 309},       // '⊇'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1281, 0},      // '⊈'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1282, 0},      // '⊉'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 310},       // '⊑'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 311},       // '⊒'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 312},       // '⊢'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 313},       // '⊨'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 314},       // '⊩'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 315},       // '⊫'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1283, 0},      // '⊬'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1284, 0},      // '⊭'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1285, 0},      // '⊮'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1286, 0},      // '⊯'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 316},       // '⊲'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 317},       // '⊳'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 318},       // '⊴'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 0, 319},       // '⊵'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1287, 0},      // '⋠'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1288, 0},      // '⋡'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1289, 0},      // '⋢'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1290, 0},      // '⋣'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1291, 0},      // '⋪'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1292, 0},      // '⋫'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1293, 0},      // '⋬'
    {0, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1294, 0},      // '⋭'
    {5, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 1295, 0},      // '〈'
    {5, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 1296, 0},      // '〉'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1297, 0},      // '①'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1298, 0},      // '②'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1299, 0},      // '③'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1300, 0},      // '④'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1301, 0},      // '⑤'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1302, 0},      // '⑥'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1303, 0},      // '⑦'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1304, 0},      // '⑧'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1305, 0},      // '⑨'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1306, 0},      // '⑩'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1307, 0},      // '⑪'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1308, 0},      // '⑫'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1309, 0},      // '⑬'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1310, 0},      // '⑭'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1311, 0},      // '⑮'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1312, 0},      // '⑯'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1313, 0},      // '⑰'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1314, 0},      // '⑱'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1315, 0},      // '⑲'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1316, 0},      // '⑳'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1317, 0},      // '⑴'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1318, 0},      // '⑵'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1319, 0},      // '⑶'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1320, 0},      // '⑷'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1321, 0},      // '⑸'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1322, 0},      // '⑹'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1323, 0},      // '⑺'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1324, 0},      // '⑻'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1325, 0},      // '⑼'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1326, 0},      // '⑽'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1327, 0},      // '⑾'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1328, 0},      // '⑿'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1329, 0},      // '⒀'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1330, 0},      // '⒁'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1331, 0},      // '⒂'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1332, 0},      // '⒃'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1333, 0},      // '⒄'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1334, 0},      // '⒅'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1335, 0},      // '⒆'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1336, 0},      // '⒇'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1337, 0},      // '⒈'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1338, 0},      // '⒉'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1339, 0},      // '⒊'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1340, 0},      // '⒋'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1341, 0},      // '⒌'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1342, 0},      // '⒍'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1343, 0},      // '⒎'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1344, 0},      // '⒏'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1345, 0},      // '⒐'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1346, 0},      // '⒑'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1347, 0},      // '⒒'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1348, 0},      // '⒓'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1349, 0},      // '⒔'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1350, 0},      // '⒕'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1351, 0},      // '⒖'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1352, 0},      // '⒗'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1353, 0},      // '⒘'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1354, 0},      // '⒙'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1355, 0},      // '⒚'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1356, 0},      // '⒛'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1357, 0},      // 0x249C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1358, 0},      // 0x249D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1359, 0},      // 0x249E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1360, 0},      // 0x249F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1361, 0},      // 0x24A0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1362, 0},      // 0x24A1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1363, 0},      // 0x24A2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1364, 0},      // 0x24A3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1365, 0},      // 0x24A4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1366, 0},      // 0x24A5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1367, 0},      // 0x24A6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1368, 0},      // 0x24A7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1369, 0},      // 0x24A8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1370, 0},      // 0x24A9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1371, 0},      // 0x24AA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1372, 0},      // 0x24AB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1373, 0},      // 0x24AC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1374, 0},      // 0x24AD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1375, 0},      // 0x24AE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1376, 0},      // 0x24AF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1377, 0},      // 0x24B0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1378, 0},      // 0x24B1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1379, 0},      // 0x24B2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1380, 0},      // 0x24B3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1381, 0},      // 0x24B4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1382, 0},      // 0x24B5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1717, 1383, 0},   // 0x24B6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1718, 1384, 0},   // 0x24B7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1719, 1385, 0},   // 0x24B8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1720, 1386, 0},   // 0x24B9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1721, 1387, 0},   // 0x24BA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1722, 1388, 0},   // 0x24BB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1723, 1389, 0},   // 0x24BC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1724, 1390, 0},   // 0x24BD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1725, 1391, 0},   // 0x24BE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1726, 1392, 0},   // 0x24BF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1727, 1393, 0},   // 0x24C0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1728, 1394, 0},   // 0x24C1
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 1729, 1395, 0},   // 0x24C2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1730, 1396, 0},   // 0x24C3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1731, 1397, 0},   // 0x24C4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1732, 1398, 0},   // 0x24C5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1733, 1399, 0},   // 0x24C6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1734, 1400, 0},   // 0x24C7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1735, 1401, 0},   // 0x24C8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1736, 1402, 0},   // 0x24C9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1737, 1403, 0},   // 0x24CA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1738, 1404, 0},   // 0x24CB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1739, 1405, 0},   // 0x24CC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1740, 1406, 0},   // 0x24CD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1741, 1407, 0},   // 0x24CE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1742, 1408, 0},   // 0x24CF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1743, 1409, 0},   // 0x24D0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1744, 1410, 0},   // 0x24D1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1745, 1411, 0},   // 0x24D2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1746, 1412, 0},   // 0x24D3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1747, 1413, 0},   // 0x24D4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1748, 1414, 0},   // 0x24D5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1749, 1415, 0},   // 0x24D6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1750, 1416, 0},   // 0x24D7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1751, 1417, 0},   // 0x24D8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1752, 1418, 0},   // 0x24D9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1753, 1419, 0},   // 0x24DA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1754, 1420, 0},   // 0x24DB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1755, 1421, 0},   // 0x24DC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1756, 1422, 0},   // 0x24DD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1757, 1423, 0},   // 0x24DE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1758, 1424, 0},   // 0x24DF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1759, 1425, 0},   // 0x24E0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1760, 1426, 0},   // 0x24E1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1761, 1427, 0},   // 0x24E2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1762, 1428, 0},   // 0x24E3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1763, 1429, 0},   // 0x24E4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1764, 1430, 0},   // 0x24E5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1765, 1431, 0},   // 0x24E6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1766, 1432, 0},   // 0x24E7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1767, 1433, 0},   // 0x24E8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 1768, 1434, 0},   // 0x24E9
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1435, 0},      // '⓪'
    {0, TINYUCD_GC_SM, 0, 0, 0, 1, 0, 0, 0},         // 6 codepoints in range [0x25FB, 0x2935]
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1436, 0},      // '⨌'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1437, 0},      // '⩴'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1438, 0},      // '⩵'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1439, 0},      // '⩶'
    {5, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 1440, 0},      // '⫝̸'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1769, 0, 0},      // 'Ⰰ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1770, 0, 0},      // 'Ⰱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1771, 0, 0},      // 'Ⰲ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1772, 0, 0},      // 'Ⰳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1773, 0, 0},      // 'Ⰴ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1774, 0, 0},      // 'Ⰵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1775, 0, 0},      // 'Ⰶ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1776, 0, 0},      // 'Ⰷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1777, 0, 0},      // 'Ⰸ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1778, 0, 0},      // 'Ⰹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1779, 0, 0},      // 'Ⰺ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1780, 0, 0},      // 'Ⰻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1781, 0, 0},      // 'Ⰼ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1782, 0, 0},      // 'Ⰽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1783, 0, 0},      // 'Ⰾ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1784, 0, 0},      // 'Ⰿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1785, 0, 0},      // 'Ⱀ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1786, 0, 0},      // 'Ⱁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1787, 0, 0},      // 'Ⱂ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1788, 0, 0},      // 'Ⱃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1789, 0, 0},      // 'Ⱄ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1790, 0, 0},      // 'Ⱅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1791, 0, 0},      // 'Ⱆ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1792, 0, 0},      // 'Ⱇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1793, 0, 0},      // 'Ⱈ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1794, 0, 0},      // 'Ⱉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1795, 0, 0},      // 'Ⱊ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1796, 0, 0},      // 'Ⱋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1797, 0, 0},      // 'Ⱌ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1798, 0, 0},      // 'Ⱍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1799, 0, 0},      // 'Ⱎ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1800, 0, 0},      // 'Ⱏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1801, 0, 0},      // 'Ⱐ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1802, 0, 0},      // 'Ⱑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1803, 0, 0},      // 'Ⱒ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1804, 0, 0},      // 'Ⱓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1805, 0, 0},      // 'Ⱔ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1806, 0, 0},      // 'Ⱕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1807, 0, 0},      // 'Ⱖ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1808, 0, 0},      // 'Ⱗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1809, 0, 0},      // 'Ⱘ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1810, 0, 0},      // 'Ⱙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1811, 0, 0},      // 'Ⱚ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1812, 0, 0},      // 'Ⱛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1813, 0, 0},      // 'Ⱜ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1814, 0, 0},      // 'Ⱝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1815, 0, 0},      // 'Ⱞ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1816, 0, 0},      // 'Ⱟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1817, 0, 0},      // 'ⰰ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1818, 0, 0},      // 'ⰱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1819, 0, 0},      // 'ⰲ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1820, 0, 0},      // 'ⰳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1821, 0, 0},      // 'ⰴ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1822, 0, 0},      // 'ⰵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1823, 0, 0},      // 'ⰶ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1824, 0, 0},      // 'ⰷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1825, 0, 0},      // 'ⰸ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1826, 0, 0},      // 'ⰹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1827, 0, 0},      // 'ⰺ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1828, 0, 0},      // 'ⰻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1829, 0, 0},      // 'ⰼ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1830, 0, 0},      // 'ⰽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1831, 0, 0},      // 'ⰾ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1832, 0, 0},      // 'ⰿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1833, 0, 0},      // 'ⱀ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1834, 0, 0},      // 'ⱁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1835, 0, 0},      // 'ⱂ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1836, 0, 0},      // 'ⱃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1837, 0, 0},      // 'ⱄ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1838, 0, 0},      // 'ⱅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1839, 0, 0},      // 'ⱆ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1840, 0, 0},      // 'ⱇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1841, 0, 0},      // 'ⱈ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1842, 0, 0},      // 'ⱉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1843, 0, 0},      // 'ⱊ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1844, 0, 0},      // 'ⱋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1845, 0, 0},      // 'ⱌ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1846, 0, 0},      // 'ⱍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1847, 0, 0},      // 'ⱎ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1848, 0, 0},      // 'ⱏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1849, 0, 0},      // 'ⱐ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1850, 0, 0},      // 'ⱑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1851, 0, 0},      // 'ⱒ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1852, 0, 0},      // 'ⱓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1853, 0, 0},      // 'ⱔ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1854, 0, 0},      // 'ⱕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1855, 0, 0},      // 'ⱖ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1856, 0, 0},      // 'ⱗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1857, 0, 0},      // 'ⱘ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1858, 0, 0},      // 'ⱙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1859, 0, 0},      // 'ⱚ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1860, 0, 0},      // 'ⱛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1861, 0, 0},      // 'ⱜ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1862, 0, 0},      // 'ⱝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1863, 0, 0},      // 'ⱞ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1864, 0, 0},      // 'ⱟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1865, 0, 0},      // 'Ⱡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1866, 0, 0},      // 'ⱡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1867, 0, 0},      // 'Ɫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1868, 0, 0},      // 'Ᵽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1869, 0, 0},      // 'Ɽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1870, 0, 0},      // 'ⱥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1871, 0, 0},      // 'ⱦ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1872, 0, 0},      // 'Ⱨ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1873, 0, 0},      // 'ⱨ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1874, 0, 0},      // 'Ⱪ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1875, 0, 0},      // 'ⱪ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1876, 0, 0},      // 'Ⱬ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1877, 0, 0},      // 'ⱬ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1878, 0, 0},      // 'Ɑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1879, 0, 0},      // 'Ɱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1880, 0, 0},      // 'Ɐ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1881, 0, 0},      // 'Ɒ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1882, 0, 0},      // 'Ⱳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1883, 0, 0},      // 'ⱳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1884, 0, 0},      // 'Ⱶ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1885, 0, 0},      // 'ⱶ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1441, 0},      // 'ⱼ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1442, 0},      // 'ⱽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1886, 0, 0},      // 'Ȿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1887, 0, 0},      // 'Ɀ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1888, 0, 0},      // 'Ⲁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1889, 0, 0},      // 'ⲁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1890, 0, 0},      // 'Ⲃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1891, 0, 0},      // 'ⲃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1892, 0, 0},      // 'Ⲅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1893, 0, 0},      // 'ⲅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1894, 0, 0},      // 'Ⲇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1895, 0, 0},      // 'ⲇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1896, 0, 0},      // 'Ⲉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1897, 0, 0},      // 'ⲉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1898, 0, 0},      // 'Ⲋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1899, 0, 0},      // 'ⲋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1900, 0, 0},      // 'Ⲍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1901, 0, 0},      // 'ⲍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1902, 0, 0},      // 'Ⲏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1903, 0, 0},      // 'ⲏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1904, 0, 0},      // 'Ⲑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1905, 0, 0},      // 'ⲑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1906, 0, 0},      // 'Ⲓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1907, 0, 0},      // 'ⲓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1908, 0, 0},      // 'Ⲕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1909, 0, 0},      // 'ⲕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1910, 0, 0},      // 'Ⲗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1911, 0, 0},      // 'ⲗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1912, 0, 0},      // 'Ⲙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1913, 0, 0},      // 'ⲙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1914, 0, 0},      // 'Ⲛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1915, 0, 0},      // 'ⲛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1916, 0, 0},      // 'Ⲝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1917, 0, 0},      // 'ⲝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1918, 0, 0},      // 'Ⲟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1919, 0, 0},      // 'ⲟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1920, 0, 0},      // 'Ⲡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1921, 0, 0},      // 'ⲡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1922, 0, 0},      // 'Ⲣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1923, 0, 0},      // 'ⲣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1924, 0, 0},      // 'Ⲥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1925, 0, 0},      // 'ⲥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1926, 0, 0},      // 'Ⲧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1927, 0, 0},      // 'ⲧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1928, 0, 0},      // 'Ⲩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1929, 0, 0},      // 'ⲩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1930, 0, 0},      // 'Ⲫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1931, 0, 0},      // 'ⲫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1932, 0, 0},      // 'Ⲭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1933, 0, 0},      // 'ⲭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1934, 0, 0},      // 'Ⲯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1935, 0, 0},      // 'ⲯ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1936, 0, 0},      // 'Ⲱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1937, 0, 0},      // 'ⲱ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1938, 0, 0},      // 'Ⲳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1939, 0, 0},      // 'ⲳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1940, 0, 0},      // 'Ⲵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1941, 0, 0},      // 'ⲵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1942, 0, 0},      // 'Ⲷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1943, 0, 0},      // 'ⲷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1944, 0, 0},      // 'Ⲹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1945, 0, 0},      // 'ⲹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1946, 0, 0},      // 'Ⲻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1947, 0, 0},      // 'ⲻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1948, 0, 0},      // 'Ⲽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1949, 0, 0},      // 'ⲽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1950, 0, 0},      // 'Ⲿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1951, 0, 0},      // 'ⲿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1952, 0, 0},      // 'Ⳁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1953, 0, 0},      // 'ⳁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1954, 0, 0},      // 'Ⳃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1955, 0, 0},      // 'ⳃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1956, 0, 0},      // 'Ⳅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1957, 0, 0},      // 'ⳅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1958, 0, 0},      // 'Ⳇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1959, 0, 0},      // 'ⳇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1960, 0, 0},      // 'Ⳉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1961, 0, 0},      // 'ⳉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1962, 0, 0},      // 'Ⳋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1963, 0, 0},      // 'ⳋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1964, 0, 0},      // 'Ⳍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1965, 0, 0},      // 'ⳍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1966, 0, 0},      // 'Ⳏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1967, 0, 0},      // 'ⳏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1968, 0, 0},      // 'Ⳑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1969, 0, 0},      // 'ⳑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1970, 0, 0},      // 'Ⳓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1971, 0, 0},      // 'ⳓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1972, 0, 0},      // 'Ⳕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1973, 0, 0},      // 'ⳕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1974, 0, 0},      // 'Ⳗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1975, 0, 0},      // 'ⳗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1976, 0, 0},      // 'Ⳙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1977, 0, 0},      // 'ⳙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1978, 0, 0},      // 'Ⳛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1979, 0, 0},      // 'ⳛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1980, 0, 0},      // 'Ⳝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1981, 0, 0},      // 'ⳝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1982, 0, 0},      // 'Ⳟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1983, 0, 0},      // 'ⳟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1984, 0, 0},      // 'Ⳡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1985, 0, 0},      // 'ⳡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1986, 0, 0},      // 'Ⳣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1987, 0, 0},      // 'ⳣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1988, 0, 0},      // 'Ⳬ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1989, 0, 0},      // 'ⳬ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1990, 0, 0},      // 'Ⳮ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1991, 0, 0},      // 'ⳮ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 1992, 0, 0},      // 'Ⳳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1993, 0, 0},      // 'ⳳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1994, 0, 0},      // 'ⴀ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1995, 0, 0},      // 'ⴁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1996, 0, 0},      // 'ⴂ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1997, 0, 0},      // 'ⴃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1998, 0, 0},      // 'ⴄ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 1999, 0, 0},      // 'ⴅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2000, 0, 0},      // 'ⴆ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2001, 0, 0},      // 'ⴇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2002, 0, 0},      // 'ⴈ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2003, 0, 0},      // 'ⴉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2004, 0, 0},      // 'ⴊ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2005, 0, 0},      // 'ⴋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2006, 0, 0},      // 'ⴌ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2007, 0, 0},      // 'ⴍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2008, 0, 0},      // 'ⴎ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2009, 0, 0},      // 'ⴏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2010, 0, 0},      // 'ⴐ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2011, 0, 0},      // 'ⴑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2012, 0, 0},      // 'ⴒ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2013, 0, 0},      // 'ⴓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2014, 0, 0},      // 'ⴔ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2015, 0, 0},      // 'ⴕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2016, 0, 0},      // 'ⴖ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2017, 0, 0},      // 'ⴗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2018, 0, 0},      // 'ⴘ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2019, 0, 0},      // 'ⴙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2020, 0, 0},      // 'ⴚ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2021, 0, 0},      // 'ⴛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2022, 0, 0},      // 'ⴜ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2023, 0, 0},      // 'ⴝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2024, 0, 0},      // 'ⴞ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2025, 0, 0},      // 'ⴟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2026, 0, 0},      // 'ⴠ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2027, 0, 0},      // 'ⴡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2028, 0, 0},      // 'ⴢ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2029, 0, 0},      // 'ⴣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2030, 0, 0},      // 'ⴤ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2031, 0, 0},      // 'ⴥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2032, 0, 0},      // 'ⴧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2033, 0, 0},      // 'ⴭ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1443, 0},      // 'ⵯ'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1444, 0},      // 0x2E9F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1445, 0},      // 0x2EF3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1446, 0},      // 0x2F00
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1447, 0},      // 0x2F01
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1448, 0},      // 0x2F02
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1449, 0},      // 0x2F03
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1450, 0},      // 0x2F04
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1451, 0},      // 0x2F05
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1452, 0},      // 0x2F06
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1453, 0},      // 0x2F07
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1454, 0},      // 0x2F08
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1455, 0},      // 0x2F09
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1456, 0},      // 0x2F0A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1457, 0},      // 0x2F0B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1458, 0},      // 0x2F0C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1459, 0},      // 0x2F0D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1460, 0},      // 0x2F0E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1461, 0},      // 0x2F0F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1462, 0},      // 0x2F10
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1463, 0},      // 0x2F11
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1464, 0},      // 0x2F12
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1465, 0},      // 0x2F13
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1466, 0},      // 0x2F14
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1467, 0},      // 0x2F15
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1468, 0},      // 0x2F16
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1469, 0},      // 0x2F17
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1470, 0},      // 0x2F18
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1471, 0},      // 0x2F19
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1472, 0},      // 0x2F1A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1473, 0},      // 0x2F1B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1474, 0},      // 0x2F1C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1475, 0},      // 0x2F1D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1476, 0},      // 0x2F1E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1477, 0},      // 0x2F1F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1478, 0},      // 0x2F20
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1479, 0},      // 0x2F21
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1480, 0},      // 0x2F22
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1481, 0},      // 0x2F23
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1482, 0},      // 0x2F24
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1483, 0},      // 0x2F25
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1484, 0},      // 0x2F26
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1485, 0},      // 0x2F27
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1486, 0},      // 0x2F28
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1487, 0},      // 0x2F29
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1488, 0},      // 0x2F2A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1489, 0},      // 0x2F2B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1490, 0},      // 0x2F2C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1491, 0},      // 0x2F2D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1492, 0},      // 0x2F2E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1493, 0},      // 0x2F2F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1494, 0},      // 0x2F30
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1495, 0},      // 0x2F31
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1496, 0},      // 0x2F32
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1497, 0},      // 0x2F33
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1498, 0},      // 0x2F34
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1499, 0},      // 0x2F35
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1500, 0},      // 0x2F36
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1501, 0},      // 0x2F37
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1502, 0},      // 0x2F38
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1503, 0},      // 0x2F39
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1504, 0},      // 0x2F3A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1505, 0},      // 0x2F3B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1506, 0},      // 0x2F3C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1507, 0},      // 0x2F3D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1508, 0},      // 0x2F3E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1509, 0},      // 0x2F3F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1510, 0},      // 0x2F40
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1511, 0},      // 0x2F41
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1512, 0},      // 0x2F42
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1513, 0},      // 0x2F43
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1514, 0},      // 0x2F44
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1515, 0},      // 0x2F45
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1516, 0},      // 0x2F46
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1517, 0},      // 0x2F47
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1518, 0},      // 0x2F48
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1519, 0},      // 0x2F49
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1520, 0},      // 0x2F4A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1521, 0},      // 0x2F4B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1522, 0},      // 0x2F4C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1523, 0},      // 0x2F4D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1524, 0},      // 0x2F4E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1525, 0},      // 0x2F4F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1526, 0},      // 0x2F50
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1527, 0},      // 0x2F51
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1528, 0},      // 0x2F52
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1529, 0},      // 0x2F53
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1530, 0},      // 0x2F54
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1531, 0},      // 0x2F55
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1532, 0},      // 0x2F56
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1533, 0},      // 0x2F57
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1534, 0},      // 0x2F58
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1535, 0},      // 0x2F59
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1536, 0},      // 0x2F5A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1537, 0},      // 0x2F5B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1538, 0},      // 0x2F5C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1539, 0},      // 0x2F5D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1540, 0},      // 0x2F5E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1541, 0},      // 0x2F5F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1542, 0},      // 0x2F60
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1543, 0},      // 0x2F61
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1544, 0},      // 0x2F62
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1545, 0},      // 0x2F63
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1546, 0},      // 0x2F64
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1547, 0},      // 0x2F65
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1548, 0},      // 0x2F66
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1549, 0},      // 0x2F67
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1550, 0},      // 0x2F68
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1551, 0},      // 0x2F69
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1552, 0},      // 0x2F6A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1553, 0},      // 0x2F6B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1554, 0},      // 0x2F6C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1555, 0},      // 0x2F6D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1556, 0},      // 0x2F6E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1557, 0},      // 0x2F6F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1558, 0},      // 0x2F70
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1559, 0},      // 0x2F71
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1560, 0},      // 0x2F72
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1561, 0},      // 0x2F73
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1562, 0},      // 0x2F74
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1563, 0},      // 0x2F75
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1564, 0},      // 0x2F76
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1565, 0},      // 0x2F77
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1566, 0},      // 0x2F78
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1567, 0},      // 0x2F79
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1568, 0},      // 0x2F7A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1569, 0},      // 0x2F7B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1570, 0},      // 0x2F7C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1571, 0},      // 0x2F7D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1572, 0},      // 0x2F7E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1573, 0},      // 0x2F7F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1574, 0},      // 0x2F80
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1575, 0},      // 0x2F81
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1576, 0},      // 0x2F82
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1577, 0},      // 0x2F83
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1578, 0},      // 0x2F84
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1579, 0},      // 0x2F85
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1580, 0},      // 0x2F86
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1581, 0},      // 0x2F87
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1582, 0},      // 0x2F88
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1583, 0},      // 0x2F89
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1584, 0},      // 0x2F8A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1585, 0},      // 0x2F8B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1586, 0},      // 0x2F8C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1587, 0},      // 0x2F8D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1588, 0},      // 0x2F8E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1589, 0},      // 0x2F8F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1590, 0},      // 0x2F90
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1591, 0},      // 0x2F91
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1592, 0},      // 0x2F92
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1593, 0},      // 0x2F93
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1594, 0},      // 0x2F94
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1595, 0},      // 0x2F95
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1596, 0},      // 0x2F96
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1597, 0},      // 0x2F97
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1598, 0},      // 0x2F98
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1599, 0},      // 0x2F99
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1600, 0},      // 0x2F9A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1601, 0},      // 0x2F9B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1602, 0},      // 0x2F9C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1603, 0},      // 0x2F9D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1604, 0},      // 0x2F9E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1605, 0},      // 0x2F9F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1606, 0},      // 0x2FA0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1607, 0},      // 0x2FA1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1608, 0},      // 0x2FA2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1609, 0},      // 0x2FA3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1610, 0},      // 0x2FA4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1611, 0},      // 0x2FA5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1612, 0},      // 0x2FA6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1613, 0},      // 0x2FA7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1614, 0},      // 0x2FA8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1615, 0},      // 0x2FA9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1616, 0},      // 0x2FAA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1617, 0},      // 0x2FAB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1618, 0},      // 0x2FAC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1619, 0},      // 0x2FAD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1620, 0},      // 0x2FAE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1621, 0},      // 0x2FAF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1622, 0},      // 0x2FB0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1623, 0},      // 0x2FB1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1624, 0},      // 0x2FB2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1625, 0},      // 0x2FB3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1626, 0},      // 0x2FB4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1627, 0},      // 0x2FB5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1628, 0},      // 0x2FB6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1629, 0},      // 0x2FB7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1630, 0},      // 0x2FB8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1631, 0},      // 0x2FB9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1632, 0},      // 0x2FBA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1633, 0},      // 0x2FBB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1634, 0},      // 0x2FBC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1635, 0},      // 0x2FBD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1636, 0},      // 0x2FBE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1637, 0},      // 0x2FBF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1638, 0},      // 0x2FC0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1639, 0},      // 0x2FC1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1640, 0},      // 0x2FC2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1641, 0},      // 0x2FC3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1642, 0},      // 0x2FC4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1643, 0},      // 0x2FC5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1644, 0},      // 0x2FC6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1645, 0},      // 0x2FC7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1646, 0},      // 0x2FC8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1647, 0},      // 0x2FC9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1648, 0},      // 0x2FCA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1649, 0},      // 0x2FCB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1650, 0},      // 0x2FCC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1651, 0},      // 0x2FCD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1652, 0},      // 0x2FCE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1653, 0},      // 0x2FCF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1654, 0},      // 0x2FD0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1655, 0},      // 0x2FD1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1656, 0},      // 0x2FD2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1657, 0},      // 0x2FD3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1658, 0},      // 0x2FD4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1659, 0},      // 0x2FD5
    {4, TINYUCD_GC_ZS, 0, 0, 0, 0, 0, 1660, 0},      // 0x3000
    {0, TINYUCD_GC_MC, 224, 4, 2, 0, 0, 0, 0},       // 2 codepoints in range [0x302E, 0x302F]
    {0, TINYUCD_GC_PD, 0, 0, 0, 1, 0, 0, 0},         // 0x3030
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1661, 0},      // 0x3036
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 0, 1662, 0},      // '〸'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 0, 1663, 0},      // '〹'
    {4, TINYUCD_GC_NL, 0, 0, 0, 0, 0, 1664, 0},      // '〺'
    {0, TINYUCD_GC_PO, 0, 0, 0, 1, 0, 0, 0},         // 0x303D
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 320},       // 0x3046
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 321},       // 0x304B
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1665, 0},      // 0x304C
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 322},       // 0x304D
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1666, 0},      // 0x304E
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 323},       // 0x304F
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1667, 0},      // 0x3050
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 324},       // 0x3051
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1668, 0},      // 0x3052
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 325},       // 0x3053
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1669, 0},      // 0x3054
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 326},       // 0x3055
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1670, 0},      // 0x3056
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 327},       // 0x3057
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1671, 0},      // 0x3058
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 328},       // 0x3059
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1672, 0},      // 0x305A
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 329},       // 0x305B
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1673, 0},      // 0x305C
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 330},       // 0x305D
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1674, 0},      // 0x305E
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 331},       // 0x305F
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1675, 0},      // 0x3060
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 332},       // 0x3061
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1676, 0},      // 0x3062
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 333},       // 0x3064
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1677, 0},      // 0x3065
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 334},       // 0x3066
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1678, 0},      // 0x3067
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 335},       // 0x3068
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1679, 0},      // 0x3069
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 336},       // 0x306F
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1680, 0},      // 0x3070
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1681, 0},      // 0x3071
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 337},       // 0x3072
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1682, 0},      // 0x3073
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1683, 0},      // 0x3074
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 338},       // 0x3075
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1684, 0},      // 0x3076
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1685, 0},      // 0x3077
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 339},       // 0x3078
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1686, 0},      // 0x3079
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1687, 0},      // 0x307A
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 340},       // 0x307B
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1688, 0},      // 0x307C
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1689, 0},      // 0x307D
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1690, 0},      // 0x3094
    {2, TINYUCD_GC_MN, 8, 4, 2, 0, 0, 0, 0},         // 2 codepoints in range [0x3099, 0x309A]
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1691, 0},      // 0x309B
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 1692, 0},      // 0x309C
    {0, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 0, 341},       // 'ゝ'
    {0, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1693, 0},      // 'ゞ'
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1694, 0},      // 0x309F
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 342},       // 0x30A6
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 343},       // 0x30AB
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1695, 0},      // 0x30AC
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 344},       // 0x30AD
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1696, 0},      // 0x30AE
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 345},       // 0x30AF
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1697, 0},      // 0x30B0
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 346},       // 0x30B1
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1698, 0},      // 0x30B2
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 347},       // 0x30B3
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1699, 0},      // 0x30B4
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 348},       // 0x30B5
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1700, 0},      // 0x30B6
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 349},       // 0x30B7
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1701, 0},      // 0x30B8
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 350},       // 0x30B9
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1702, 0},      // 0x30BA
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 351},       // 0x30BB
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1703, 0},      // 0x30BC
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 352},       // 0x30BD
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1704, 0},      // 0x30BE
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 353},       // 0x30BF
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1705, 0},      // 0x30C0
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 354},       // 0x30C1
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1706, 0},      // 0x30C2
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 355},       // 0x30C4
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1707, 0},      // 0x30C5
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 356},       // 0x30C6
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1708, 0},      // 0x30C7
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 357},       // 0x30C8
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1709, 0},      // 0x30C9
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 358},       // 0x30CF
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1710, 0},      // 0x30D0
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1711, 0},      // 0x30D1
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 359},       // 0x30D2
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1712, 0},      // 0x30D3
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1713, 0},      // 0x30D4
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 360},       // 0x30D5
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1714, 0},      // 0x30D6
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1715, 0},      // 0x30D7
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 361},       // 0x30D8
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1716, 0},      // 0x30D9
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1717, 0},      // 0x30DA
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 362},       // 0x30DB
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1718, 0},      // 0x30DC
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1719, 0},      // 0x30DD
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 363},       // 0x30EF
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 364},       // 0x30F0
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 365},       // 0x30F1
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 366},       // 0x30F2
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1720, 0},      // 0x30F4
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1721, 0},      // 0x30F7
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1722, 0},      // 0x30F8
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1723, 0},      // 0x30F9
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1724, 0},      // 0x30FA
    {0, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 0, 367},       // 'ヽ'
    {0, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 1725, 0},      // 'ヾ'
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1726, 0},      // 0x30FF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1727, 0},      // 0x3131
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1728, 0},      // 0x3132
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1729, 0},      // 0x3133
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1730, 0},      // 0x3134
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1731, 0},      // 0x3135
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1732, 0},      // 0x3136
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1733, 0},      // 0x3137
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1734, 0},      // 0x3138
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1735, 0},      // 0x3139
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1736, 0},      // 0x313A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1737, 0},      // 0x313B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1738, 0},      // 0x313C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1739, 0},      // 0x313D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1740, 0},      // 0x313E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1741, 0},      // 0x313F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1742, 0},      // 0x3140
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1743, 0},      // 0x3141
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1744, 0},      // 0x3142
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1745, 0},      // 0x3143
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1746, 0},      // 0x3144
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1747, 0},      // 0x3145
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1748, 0},      // 0x3146
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1749, 0},      // 0x3147
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1750, 0},      // 0x3148
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1751, 0},      // 0x3149
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1752, 0},      // 0x314A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1753, 0},      // 0x314B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1754, 0},      // 0x314C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1755, 0},      // 0x314D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1756, 0},      // 0x314E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1757, 0},      // 0x314F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1758, 0},      // 0x3150
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1759, 0},      // 0x3151
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1760, 0},      // 0x3152
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1761, 0},      // 0x3153
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1762, 0},      // 0x3154
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1763, 0},      // 0x3155
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1764, 0},      // 0x3156
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1765, 0},      // 0x3157
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1766, 0},      // 0x3158
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1767, 0},      // 0x3159
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1768, 0},      // 0x315A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1769, 0},      // 0x315B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1770, 0},      // 0x315C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1771, 0},      // 0x315D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1772, 0},      // 0x315E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1773, 0},      // 0x315F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1774, 0},      // 0x3160
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1775, 0},      // 0x3161
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1776, 0},      // 0x3162
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1777, 0},      // 0x3163
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1778, 0},      // 0x3164
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1779, 0},      // 0x3165
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1780, 0},      // 0x3166
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1781, 0},      // 0x3167
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1782, 0},      // 0x3168
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1783, 0},      // 0x3169
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1784, 0},      // 0x316A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1785, 0},      // 0x316B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1786, 0},      // 0x316C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1787, 0},      // 0x316D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1788, 0},      // 0x316E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1789, 0},      // 0x316F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1790, 0},      // 0x3170
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1791, 0},      // 0x3171
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1792, 0},      // 0x3172
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1793, 0},      // 0x3173
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1794, 0},      // 0x3174
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1795, 0},      // 0x3175
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1796, 0},      // 0x3176
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1797, 0},      // 0x3177
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1798, 0},      // 0x3178
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1799, 0},      // 0x3179
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1800, 0},      // 0x317A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1801, 0},      // 0x317B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1802, 0},      // 0x317C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1803, 0},      // 0x317D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1804, 0},      // 0x317E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1805, 0},      // 0x317F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1806, 0},      // 0x3180
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1807, 0},      // 0x3181
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1808, 0},      // 0x3182
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1809, 0},      // 0x3183
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1810, 0},      // 0x3184
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1811, 0},      // 0x3185
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1812, 0},      // 0x3186
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1813, 0},      // 0x3187
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1814, 0},      // 0x3188
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1815, 0},      // 0x3189
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1816, 0},      // 0x318A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1817, 0},      // 0x318B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1818, 0},      // 0x318C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1819, 0},      // 0x318D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 1820, 0},      // 0x318E
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1821, 0},      // '㆒'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1822, 0},      // '㆓'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1823, 0},      // '㆔'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1824, 0},      // '㆕'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1825, 0},      // 0x3196
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1826, 0},      // 0x3197
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1827, 0},      // 0x3198
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1828, 0},      // 0x3199
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1829, 0},      // 0x319A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1830, 0},      // 0x319B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1831, 0},      // 0x319C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1832, 0},      // 0x319D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1833, 0},      // 0x319E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1834, 0},      // 0x319F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1835, 0},      // 0x3200
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1836, 0},      // 0x3201
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1837, 0},      // 0x3202
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1838, 0},      // 0x3203
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1839, 0},      // 0x3204
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1840, 0},      // 0x3205
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1841, 0},      // 0x3206
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1842, 0},      // 0x3207
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1843, 0},      // 0x3208
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1844, 0},      // 0x3209
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1845, 0},      // 0x320A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1846, 0},      // 0x320B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1847, 0},      // 0x320C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1848, 0},      // 0x320D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1849, 0},      // 0x320E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1850, 0},      // 0x320F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1851, 0},      // 0x3210
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1852, 0},      // 0x3211
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1853, 0},      // 0x3212
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1854, 0},      // 0x3213
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1855, 0},      // 0x3214
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1856, 0},      // 0x3215
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1857, 0},      // 0x3216
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1858, 0},      // 0x3217
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1859, 0},      // 0x3218
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1860, 0},      // 0x3219
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1861, 0},      // 0x321A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1862, 0},      // 0x321B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1863, 0},      // 0x321C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1864, 0},      // 0x321D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1865, 0},      // 0x321E
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1866, 0},      // '㈠'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1867, 0},      // '㈡'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1868, 0},      // '㈢'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1869, 0},      // '㈣'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1870, 0},      // '㈤'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1871, 0},      // '㈥'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1872, 0},      // '㈦'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1873, 0},      // '㈧'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1874, 0},      // '㈨'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1875, 0},      // '㈩'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1876, 0},      // 0x322A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1877, 0},      // 0x322B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1878, 0},      // 0x322C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1879, 0},      // 0x322D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1880, 0},      // 0x322E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1881, 0},      // 0x322F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1882, 0},      // 0x3230
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1883, 0},      // 0x3231
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1884, 0},      // 0x3232
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1885, 0},      // 0x3233
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1886, 0},      // 0x3234
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1887, 0},      // 0x3235
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1888, 0},      // 0x3236
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1889, 0},      // 0x3237
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1890, 0},      // 0x3238
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1891, 0},      // 0x3239
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1892, 0},      // 0x323A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1893, 0},      // 0x323B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1894, 0},      // 0x323C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1895, 0},      // 0x323D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1896, 0},      // 0x323E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1897, 0},      // 0x323F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1898, 0},      // 0x3240
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1899, 0},      // 0x3241
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1900, 0},      // 0x3242
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1901, 0},      // 0x3243
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1902, 0},      // 0x3244
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1903, 0},      // 0x3245
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1904, 0},      // 0x3246
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1905, 0},      // 0x3247
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1906, 0},      // 0x3250
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1907, 0},      // '㉑'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1908, 0},      // '㉒'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1909, 0},      // '㉓'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1910, 0},      // '㉔'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1911, 0},      // '㉕'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1912, 0},      // '㉖'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1913, 0},      // '㉗'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1914, 0},      // '㉘'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1915, 0},      // '㉙'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1916, 0},      // '㉚'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1917, 0},      // '㉛'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1918, 0},      // '㉜'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1919, 0},      // '㉝'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1920, 0},      // '㉞'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1921, 0},      // '㉟'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1922, 0},      // 0x3260
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1923, 0},      // 0x3261
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1924, 0},      // 0x3262
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1925, 0},      // 0x3263
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1926, 0},      // 0x3264
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1927, 0},      // 0x3265
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1928, 0},      // 0x3266
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1929, 0},      // 0x3267
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1930, 0},      // 0x3268
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1931, 0},      // 0x3269
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1932, 0},      // 0x326A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1933, 0},      // 0x326B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1934, 0},      // 0x326C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1935, 0},      // 0x326D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1936, 0},      // 0x326E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1937, 0},      // 0x326F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1938, 0},      // 0x3270
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1939, 0},      // 0x3271
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1940, 0},      // 0x3272
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1941, 0},      // 0x3273
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1942, 0},      // 0x3274
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1943, 0},      // 0x3275
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1944, 0},      // 0x3276
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1945, 0},      // 0x3277
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1946, 0},      // 0x3278
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1947, 0},      // 0x3279
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1948, 0},      // 0x327A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1949, 0},      // 0x327B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1950, 0},      // 0x327C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1951, 0},      // 0x327D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1952, 0},      // 0x327E
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1953, 0},      // '㊀'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1954, 0},      // '㊁'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1955, 0},      // '㊂'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1956, 0},      // '㊃'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1957, 0},      // '㊄'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1958, 0},      // '㊅'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1959, 0},      // '㊆'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1960, 0},      // '㊇'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1961, 0},      // '㊈'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 1962, 0},      // '㊉'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1963, 0},      // 0x328A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1964, 0},      // 0x328B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1965, 0},      // 0x328C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1966, 0},      // 0x328D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1967, 0},      // 0x328E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1968, 0},      // 0x328F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1969, 0},      // 0x3290
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1970, 0},      // 0x3291
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1971, 0},      // 0x3292
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1972, 0},      // 0x3293
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1973, 0},      // 0x3294
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1974, 0},      // 0x3295
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1975, 0},      // 0x3296
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 1976, 0},      // 0x3297
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1977, 0},      // 0x3298
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 1978, 0},      // 0x3299
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1979, 0},      // 0x329A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1980, 0},      // 0x329B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1981, 0},      // 0x329C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1982, 0},      // 0x329D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1983, 0},      // 0x329E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1984, 0},      // 0x329F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1985, 0},      // 0x32A0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1986, 0},      // 0x32A1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1987, 0},      // 0x32A2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1988, 0},      // 0x32A3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1989, 0},      // 0x32A4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1990, 0},      // 0x32A5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1991, 0},      // 0x32A6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1992, 0},      // 0x32A7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1993, 0},      // 0x32A8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1994, 0},      // 0x32A9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1995, 0},      // 0x32AA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1996, 0},      // 0x32AB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1997, 0},      // 0x32AC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1998, 0},      // 0x32AD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 1999, 0},      // 0x32AE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2000, 0},      // 0x32AF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2001, 0},      // 0x32B0
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2002, 0},      // '㊱'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2003, 0},      // '㊲'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2004, 0},      // '㊳'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2005, 0},      // '㊴'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2006, 0},      // '㊵'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2007, 0},      // '㊶'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2008, 0},      // '㊷'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2009, 0},      // '㊸'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2010, 0},      // '㊹'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2011, 0},      // '㊺'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2012, 0},      // '㊻'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2013, 0},      // '㊼'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2014, 0},      // '㊽'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2015, 0},      // '㊾'
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 2016, 0},      // '㊿'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2017, 0},      // 0x32C0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2018, 0},      // 0x32C1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2019, 0},      // 0x32C2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2020, 0},      // 0x32C3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2021, 0},      // 0x32C4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2022, 0},      // 0x32C5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2023, 0},      // 0x32C6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2024, 0},      // 0x32C7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2025, 0},      // 0x32C8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2026, 0},      // 0x32C9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2027, 0},      // 0x32CA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2028, 0},      // 0x32CB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2029, 0},      // 0x32CC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2030, 0},      // 0x32CD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2031, 0},      // 0x32CE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2032, 0},      // 0x32CF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2033, 0},      // 0x32D0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2034, 0},      // 0x32D1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2035, 0},      // 0x32D2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2036, 0},      // 0x32D3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2037, 0},      // 0x32D4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2038, 0},      // 0x32D5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2039, 0},      // 0x32D6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2040, 0},      // 0x32D7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2041, 0},      // 0x32D8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2042, 0},      // 0x32D9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2043, 0},      // 0x32DA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2044, 0},      // 0x32DB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2045, 0},      // 0x32DC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2046, 0},      // 0x32DD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2047, 0},      // 0x32DE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2048, 0},      // 0x32DF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2049, 0},      // 0x32E0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2050, 0},      // 0x32E1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2051, 0},      // 0x32E2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2052, 0},      // 0x32E3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2053, 0},      // 0x32E4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2054, 0},      // 0x32E5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2055, 0},      // 0x32E6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2056, 0},      // 0x32E7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2057, 0},      // 0x32E8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2058, 0},      // 0x32E9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2059, 0},      // 0x32EA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2060, 0},      // 0x32EB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2061, 0},      // 0x32EC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2062, 0},      // 0x32ED
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2063, 0},      // 0x32EE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2064, 0},      // 0x32EF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2065, 0},      // 0x32F0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2066, 0},      // 0x32F1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2067, 0},      // 0x32F2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2068, 0},      // 0x32F3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2069, 0},      // 0x32F4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2070, 0},      // 0x32F5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2071, 0},      // 0x32F6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2072, 0},      // 0x32F7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2073, 0},      // 0x32F8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2074, 0},      // 0x32F9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2075, 0},      // 0x32FA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2076, 0},      // 0x32FB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2077, 0},      // 0x32FC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2078, 0},      // 0x32FD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2079, 0},      // 0x32FE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2080, 0},      // 0x32FF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2081, 0},      // 0x3300
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2082, 0},      // 0x3301
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2083, 0},      // 0x3302
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2084, 0},      // 0x3303
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2085, 0},      // 0x3304
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2086, 0},      // 0x3305
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2087, 0},      // 0x3306
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2088, 0},      // 0x3307
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2089, 0},      // 0x3308
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2090, 0},      // 0x3309
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2091, 0},      // 0x330A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2092, 0},      // 0x330B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2093, 0},      // 0x330C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2094, 0},      // 0x330D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2095, 0},      // 0x330E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2096, 0},      // 0x330F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2097, 0},      // 0x3310
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2098, 0},      // 0x3311
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2099, 0},      // 0x3312
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2100, 0},      // 0x3313
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2101, 0},      // 0x3314
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2102, 0},      // 0x3315
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2103, 0},      // 0x3316
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2104, 0},      // 0x3317
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2105, 0},      // 0x3318
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2106, 0},      // 0x3319
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2107, 0},      // 0x331A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2108, 0},      // 0x331B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2109, 0},      // 0x331C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2110, 0},      // 0x331D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2111, 0},      // 0x331E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2112, 0},      // 0x331F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2113, 0},      // 0x3320
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2114, 0},      // 0x3321
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2115, 0},      // 0x3322
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2116, 0},      // 0x3323
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2117, 0},      // 0x3324
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2118, 0},      // 0x3325
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2119, 0},      // 0x3326
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2120, 0},      // 0x3327
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2121, 0},      // 0x3328
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2122, 0},      // 0x3329
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2123, 0},      // 0x332A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2124, 0},      // 0x332B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2125, 0},      // 0x332C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2126, 0},      // 0x332D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2127, 0},      // 0x332E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2128, 0},      // 0x332F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2129, 0},      // 0x3330
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2130, 0},      // 0x3331
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2131, 0},      // 0x3332
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2132, 0},      // 0x3333
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2133, 0},      // 0x3334
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2134, 0},      // 0x3335
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2135, 0},      // 0x3336
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2136, 0},      // 0x3337
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2137, 0},      // 0x3338
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2138, 0},      // 0x3339
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2139, 0},      // 0x333A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2140, 0},      // 0x333B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2141, 0},      // 0x333C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2142, 0},      // 0x333D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2143, 0},      // 0x333E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2144, 0},      // 0x333F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2145, 0},      // 0x3340
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2146, 0},      // 0x3341
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2147, 0},      // 0x3342
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2148, 0},      // 0x3343
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2149, 0},      // 0x3344
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2150, 0},      // 0x3345
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2151, 0},      // 0x3346
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2152, 0},      // 0x3347
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2153, 0},      // 0x3348
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2154, 0},      // 0x3349
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2155, 0},      // 0x334A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2156, 0},      // 0x334B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2157, 0},      // 0x334C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2158, 0},      // 0x334D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2159, 0},      // 0x334E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2160, 0},      // 0x334F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2161, 0},      // 0x3350
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2162, 0},      // 0x3351
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2163, 0},      // 0x3352
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2164, 0},      // 0x3353
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2165, 0},      // 0x3354
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2166, 0},      // 0x3355
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2167, 0},      // 0x3356
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2168, 0},      // 0x3357
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2169, 0},      // 0x3358
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2170, 0},      // 0x3359
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2171, 0},      // 0x335A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2172, 0},      // 0x335B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2173, 0},      // 0x335C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2174, 0},      // 0x335D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2175, 0},      // 0x335E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2176, 0},      // 0x335F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2177, 0},      // 0x3360
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2178, 0},      // 0x3361
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2179, 0},      // 0x3362
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2180, 0},      // 0x3363
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2181, 0},      // 0x3364
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2182, 0},      // 0x3365
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2183, 0},      // 0x3366
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2184, 0},      // 0x3367
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2185, 0},      // 0x3368
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2186, 0},      // 0x3369
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2187, 0},      // 0x336A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2188, 0},      // 0x336B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2189, 0},      // 0x336C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2190, 0},      // 0x336D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2191, 0},      // 0x336E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2192, 0},      // 0x336F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2193, 0},      // 0x3370
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2194, 0},      // 0x3371
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2195, 0},      // 0x3372
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2196, 0},      // 0x3373
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2197, 0},      // 0x3374
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2198, 0},      // 0x3375
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2199, 0},      // 0x3376
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2200, 0},      // 0x3377
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2201, 0},      // 0x3378
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2202, 0},      // 0x3379
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2203, 0},      // 0x337A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2204, 0},      // 0x337B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2205, 0},      // 0x337C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2206, 0},      // 0x337D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2207, 0},      // 0x337E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2208, 0},      // 0x337F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2209, 0},      // 0x3380
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2210, 0},      // 0x3381
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2211, 0},      // 0x3382
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2212, 0},      // 0x3383
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2213, 0},      // 0x3384
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2214, 0},      // 0x3385
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2215, 0},      // 0x3386
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2216, 0},      // 0x3387
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2217, 0},      // 0x3388
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2218, 0},      // 0x3389
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2219, 0},      // 0x338A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2220, 0},      // 0x338B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2221, 0},      // 0x338C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2222, 0},      // 0x338D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2223, 0},      // 0x338E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2224, 0},      // 0x338F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2225, 0},      // 0x3390
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2226, 0},      // 0x3391
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2227, 0},      // 0x3392
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2228, 0},      // 0x3393
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2229, 0},      // 0x3394
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2230, 0},      // 0x3395
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2231, 0},      // 0x3396
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2232, 0},      // 0x3397
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2233, 0},      // 0x3398
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2234, 0},      // 0x3399
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2235, 0},      // 0x339A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2236, 0},      // 0x339B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2237, 0},      // 0x339C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2238, 0},      // 0x339D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2239, 0},      // 0x339E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2240, 0},      // 0x339F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2241, 0},      // 0x33A0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2242, 0},      // 0x33A1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2243, 0},      // 0x33A2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2244, 0},      // 0x33A3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2245, 0},      // 0x33A4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2246, 0},      // 0x33A5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2247, 0},      // 0x33A6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2248, 0},      // 0x33A7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2249, 0},      // 0x33A8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2250, 0},      // 0x33A9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2251, 0},      // 0x33AA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2252, 0},      // 0x33AB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2253, 0},      // 0x33AC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2254, 0},      // 0x33AD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2255, 0},      // 0x33AE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2256, 0},      // 0x33AF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2257, 0},      // 0x33B0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2258, 0},      // 0x33B1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2259, 0},      // 0x33B2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2260, 0},      // 0x33B3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2261, 0},      // 0x33B4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2262, 0},      // 0x33B5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2263, 0},      // 0x33B6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2264, 0},      // 0x33B7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2265, 0},      // 0x33B8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2266, 0},      // 0x33B9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2267, 0},      // 0x33BA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2268, 0},      // 0x33BB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2269, 0},      // 0x33BC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2270, 0},      // 0x33BD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2271, 0},      // 0x33BE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2272, 0},      // 0x33BF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2273, 0},      // 0x33C0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2274, 0},      // 0x33C1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2275, 0},      // 0x33C2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2276, 0},      // 0x33C3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2277, 0},      // 0x33C4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2278, 0},      // 0x33C5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2279, 0},      // 0x33C6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2280, 0},      // 0x33C7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2281, 0},      // 0x33C8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2282, 0},      // 0x33C9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2283, 0},      // 0x33CA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2284, 0},      // 0x33CB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2285, 0},      // 0x33CC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2286, 0},      // 0x33CD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2287, 0},      // 0x33CE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2288, 0},      // 0x33CF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2289, 0},      // 0x33D0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2290, 0},      // 0x33D1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2291, 0},      // 0x33D2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2292, 0},      // 0x33D3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2293, 0},      // 0x33D4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2294, 0},      // 0x33D5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2295, 0},      // 0x33D6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2296, 0},      // 0x33D7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2297, 0},      // 0x33D8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2298, 0},      // 0x33D9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2299, 0},      // 0x33DA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2300, 0},      // 0x33DB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2301, 0},      // 0x33DC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2302, 0},      // 0x33DD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2303, 0},      // 0x33DE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2304, 0},      // 0x33DF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2305, 0},      // 0x33E0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2306, 0},      // 0x33E1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2307, 0},      // 0x33E2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2308, 0},      // 0x33E3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2309, 0},      // 0x33E4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2310, 0},      // 0x33E5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2311, 0},      // 0x33E6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2312, 0},      // 0x33E7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2313, 0},      // 0x33E8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2314, 0},      // 0x33E9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2315, 0},      // 0x33EA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2316, 0},      // 0x33EB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2317, 0},      // 0x33EC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2318, 0},      // 0x33ED
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2319, 0},      // 0x33EE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2320, 0},      // 0x33EF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2321, 0},      // 0x33F0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2322, 0},      // 0x33F1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2323, 0},      // 0x33F2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2324, 0},      // 0x33F3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2325, 0},      // 0x33F4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2326, 0},      // 0x33F5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2327, 0},      // 0x33F6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2328, 0},      // 0x33F7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2329, 0},      // 0x33F8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2330, 0},      // 0x33F9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2331, 0},      // 0x33FA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2332, 0},      // 0x33FB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2333, 0},      // 0x33FC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2334, 0},      // 0x33FD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2335, 0},      // 0x33FE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 2336, 0},      // 0x33FF
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2034, 0, 0},      // 'Ꙁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2035, 0, 0},      // 'ꙁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2036, 0, 0},      // 'Ꙃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2037, 0, 0},      // 'ꙃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2038, 0, 0},      // 'Ꙅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2039, 0, 0},      // 'ꙅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2040, 0, 0},      // 'Ꙇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2041, 0, 0},      // 'ꙇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2042, 0, 0},      // 'Ꙉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2043, 0, 0},      // 'ꙉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2044, 0, 0},      // 'Ꙋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2045, 0, 0},      // 'ꙋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2046, 0, 0},      // 'Ꙍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2047, 0, 0},      // 'ꙍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2048, 0, 0},      // 'Ꙏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2049, 0, 0},      // 'ꙏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2050, 0, 0},      // 'Ꙑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2051, 0, 0},      // 'ꙑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2052, 0, 0},      // 'Ꙓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2053, 0, 0},      // 'ꙓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2054, 0, 0},      // 'Ꙕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2055, 0, 0},      // 'ꙕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2056, 0, 0},      // 'Ꙗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2057, 0, 0},      // 'ꙗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2058, 0, 0},      // 'Ꙙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2059, 0, 0},      // 'ꙙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2060, 0, 0},      // 'Ꙛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2061, 0, 0},      // 'ꙛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2062, 0, 0},      // 'Ꙝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2063, 0, 0},      // 'ꙝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2064, 0, 0},      // 'Ꙟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2065, 0, 0},      // 'ꙟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2066, 0, 0},      // 'Ꙡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2067, 0, 0},      // 'ꙡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2068, 0, 0},      // 'Ꙣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2069, 0, 0},      // 'ꙣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2070, 0, 0},      // 'Ꙥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2071, 0, 0},      // 'ꙥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2072, 0, 0},      // 'Ꙧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2073, 0, 0},      // 'ꙧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2074, 0, 0},      // 'Ꙩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2075, 0, 0},      // 'ꙩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2076, 0, 0},      // 'Ꙫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2077, 0, 0},      // 'ꙫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2078, 0, 0},      // 'Ꙭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2079, 0, 0},      // 'ꙭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2080, 0, 0},      // 'Ꚁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2081, 0, 0},      // 'ꚁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2082, 0, 0},      // 'Ꚃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2083, 0, 0},      // 'ꚃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2084, 0, 0},      // 'Ꚅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2085, 0, 0},      // 'ꚅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2086, 0, 0},      // 'Ꚇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2087, 0, 0},      // 'ꚇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2088, 0, 0},      // 'Ꚉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2089, 0, 0},      // 'ꚉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2090, 0, 0},      // 'Ꚋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2091, 0, 0},      // 'ꚋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2092, 0, 0},      // 'Ꚍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2093, 0, 0},      // 'ꚍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2094, 0, 0},      // 'Ꚏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2095, 0, 0},      // 'ꚏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2096, 0, 0},      // 'Ꚑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2097, 0, 0},      // 'ꚑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2098, 0, 0},      // 'Ꚓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2099, 0, 0},      // 'ꚓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2100, 0, 0},      // 'Ꚕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2101, 0, 0},      // 'ꚕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2102, 0, 0},      // 'Ꚗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2103, 0, 0},      // 'ꚗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2104, 0, 0},      // 'Ꚙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2105, 0, 0},      // 'ꚙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2106, 0, 0},      // 'Ꚛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2107, 0, 0},      // 'ꚛ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2337, 0},      // 'ꚜ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2338, 0},      // 'ꚝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2108, 0, 0},      // 'Ꜣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2109, 0, 0},      // 'ꜣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2110, 0, 0},      // 'Ꜥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2111, 0, 0},      // 'ꜥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2112, 0, 0},      // 'Ꜧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2113, 0, 0},      // 'ꜧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2114, 0, 0},      // 'Ꜩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2115, 0, 0},      // 'ꜩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2116, 0, 0},      // 'Ꜫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2117, 0, 0},      // 'ꜫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2118, 0, 0},      // 'Ꜭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2119, 0, 0},      // 'ꜭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2120, 0, 0},      // 'Ꜯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2121, 0, 0},      // 'ꜯ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2122, 0, 0},      // 'Ꜳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2123, 0, 0},      // 'ꜳ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2124, 0, 0},      // 'Ꜵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2125, 0, 0},      // 'ꜵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2126, 0, 0},      // 'Ꜷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2127, 0, 0},      // 'ꜷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2128, 0, 0},      // 'Ꜹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2129, 0, 0},      // 'ꜹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2130, 0, 0},      // 'Ꜻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2131, 0, 0},      // 'ꜻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2132, 0, 0},      // 'Ꜽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2133, 0, 0},      // 'ꜽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2134, 0, 0},      // 'Ꜿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2135, 0, 0},      // 'ꜿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2136, 0, 0},      // 'Ꝁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2137, 0, 0},      // 'ꝁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2138, 0, 0},      // 'Ꝃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2139, 0, 0},      // 'ꝃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2140, 0, 0},      // 'Ꝅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2141, 0, 0},      // 'ꝅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2142, 0, 0},      // 'Ꝇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2143, 0, 0},      // 'ꝇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2144, 0, 0},      // 'Ꝉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2145, 0, 0},      // 'ꝉ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2146, 0, 0},      // 'Ꝋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2147, 0, 0},      // 'ꝋ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2148, 0, 0},      // 'Ꝍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2149, 0, 0},      // 'ꝍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2150, 0, 0},      // 'Ꝏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2151, 0, 0},      // 'ꝏ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2152, 0, 0},      // 'Ꝑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2153, 0, 0},      // 'ꝑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2154, 0, 0},      // 'Ꝓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2155, 0, 0},      // 'ꝓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2156, 0, 0},      // 'Ꝕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2157, 0, 0},      // 'ꝕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2158, 0, 0},      // 'Ꝗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2159, 0, 0},      // 'ꝗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2160, 0, 0},      // 'Ꝙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2161, 0, 0},      // 'ꝙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2162, 0, 0},      // 'Ꝛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2163, 0, 0},      // 'ꝛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2164, 0, 0},      // 'Ꝝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2165, 0, 0},      // 'ꝝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2166, 0, 0},      // 'Ꝟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2167, 0, 0},      // 'ꝟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2168, 0, 0},      // 'Ꝡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2169, 0, 0},      // 'ꝡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2170, 0, 0},      // 'Ꝣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2171, 0, 0},      // 'ꝣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2172, 0, 0},      // 'Ꝥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2173, 0, 0},      // 'ꝥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2174, 0, 0},      // 'Ꝧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2175, 0, 0},      // 'ꝧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2176, 0, 0},      // 'Ꝩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2177, 0, 0},      // 'ꝩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2178, 0, 0},      // 'Ꝫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2179, 0, 0},      // 'ꝫ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2180, 0, 0},      // 'Ꝭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2181, 0, 0},      // 'ꝭ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2182, 0, 0},      // 'Ꝯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2183, 0, 0},      // 'ꝯ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2339, 0},      // 'ꝰ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2184, 0, 0},      // 'Ꝺ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2185, 0, 0},      // 'ꝺ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2186, 0, 0},      // 'Ꝼ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2187, 0, 0},      // 'ꝼ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2188, 0, 0},      // 'Ᵹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2189, 0, 0},      // 'Ꝿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2190, 0, 0},      // 'ꝿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2191, 0, 0},      // 'Ꞁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2192, 0, 0},      // 'ꞁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2193, 0, 0},      // 'Ꞃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2194, 0, 0},      // 'ꞃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2195, 0, 0},      // 'Ꞅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2196, 0, 0},      // 'ꞅ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2197, 0, 0},      // 'Ꞇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2198, 0, 0},      // 'ꞇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2199, 0, 0},      // 'Ꞌ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2200, 0, 0},      // 'ꞌ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2201, 0, 0},      // 'Ɥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2202, 0, 0},      // 'Ꞑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2203, 0, 0},      // 'ꞑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2204, 0, 0},      // 'Ꞓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2205, 0, 0},      // 'ꞓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2206, 0, 0},      // 'ꞔ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2207, 0, 0},      // 'Ꞗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2208, 0, 0},      // 'ꞗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2209, 0, 0},      // 'Ꞙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2210, 0, 0},      // 'ꞙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2211, 0, 0},      // 'Ꞛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2212, 0, 0},      // 'ꞛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2213, 0, 0},      // 'Ꞝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2214, 0, 0},      // 'ꞝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2215, 0, 0},      // 'Ꞟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2216, 0, 0},      // 'ꞟ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2217, 0, 0},      // 'Ꞡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2218, 0, 0},      // 'ꞡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2219, 0, 0},      // 'Ꞣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2220, 0, 0},      // 'ꞣ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2221, 0, 0},      // 'Ꞥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2222, 0, 0},      // 'ꞥ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2223, 0, 0},      // 'Ꞧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2224, 0, 0},      // 'ꞧ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2225, 0, 0},      // 'Ꞩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2226, 0, 0},      // 'ꞩ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2227, 0, 0},      // 'Ɦ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2228, 0, 0},      // 'Ɜ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2229, 0, 0},      // 'Ɡ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2230, 0, 0},      // 'Ɬ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2231, 0, 0},      // 'Ɪ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2232, 0, 0},      // 'Ʞ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2233, 0, 0},      // 'Ʇ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2234, 0, 0},      // 'Ʝ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2235, 0, 0},      // 'Ꭓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2236, 0, 0},      // 'Ꞵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2237, 0, 0},      // 'ꞵ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2238, 0, 0},      // 'Ꞷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2239, 0, 0},      // 'ꞷ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2240, 0, 0},      // 'Ꞹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2241, 0, 0},      // 'ꞹ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2242, 0, 0},      // 'Ꞻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2243, 0, 0},      // 'ꞻ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2244, 0, 0},      // 'Ꞽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2245, 0, 0},      // 'ꞽ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2246, 0, 0},      // 'Ꞿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2247, 0, 0},      // 'ꞿ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2248, 0, 0},      // 'Ꟁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2249, 0, 0},      // 'ꟁ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2250, 0, 0},      // 'Ꟃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2251, 0, 0},      // 'ꟃ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2252, 0, 0},      // 'Ꞔ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2253, 0, 0},      // 'Ʂ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2254, 0, 0},      // 'Ᶎ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2255, 0, 0},      // 'Ꟈ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2256, 0, 0},      // 'ꟈ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2257, 0, 0},      // 'Ꟊ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2258, 0, 0},      // 'ꟊ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2259, 0, 0},      // 'Ɤ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2260, 0, 0},      // 'Ꟍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2261, 0, 0},      // 'ꟍ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2262, 0, 0},      // '꟎'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2263, 0, 0},      // '꟏'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2264, 0, 0},      // 'Ꟑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2265, 0, 0},      // 'ꟑ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2266, 0, 0},      // '꟒'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2267, 0, 0},      // 'ꟓ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2268, 0, 0},      // '꟔'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2269, 0, 0},      // 'ꟕ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2270, 0, 0},      // 'Ꟗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2271, 0, 0},      // 'ꟗ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2272, 0, 0},      // 'Ꟙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2273, 0, 0},      // 'ꟙ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2274, 0, 0},      // 'Ꟛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2275, 0, 0},      // 'ꟛ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2276, 0, 0},      // 'Ƛ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2340, 0},      // '꟱'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2341, 0},      // 'ꟲ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2342, 0},      // 'ꟳ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2343, 0},      // 'ꟴ'
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2277, 0, 0},      // 'Ꟶ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2278, 0, 0},      // 'ꟶ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2344, 0},      // 'ꟸ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2345, 0},      // 'ꟹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2279, 0, 0},      // 'ꭓ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2346, 0},      // 'ꭜ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2347, 0},      // 'ꭝ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2348, 0},      // 'ꭞ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2349, 0},      // 'ꭟ'
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 2350, 0},      // 'ꭩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2280, 0, 0},      // 'ꭰ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2281, 0, 0},      // 'ꭱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2282, 0, 0},      // 'ꭲ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2283, 0, 0},      // 'ꭳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2284, 0, 0},      // 'ꭴ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2285, 0, 0},      // 'ꭵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2286, 0, 0},      // 'ꭶ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2287, 0, 0},      // 'ꭷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2288, 0, 0},      // 'ꭸ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2289, 0, 0},      // 'ꭹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2290, 0, 0},      // 'ꭺ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2291, 0, 0},      // 'ꭻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2292, 0, 0},      // 'ꭼ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2293, 0, 0},      // 'ꭽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2294, 0, 0},      // 'ꭾ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2295, 0, 0},      // 'ꭿ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2296, 0, 0},      // 'ꮀ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2297, 0, 0},      // 'ꮁ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2298, 0, 0},      // 'ꮂ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2299, 0, 0},      // 'ꮃ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2300, 0, 0},      // 'ꮄ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2301, 0, 0},      // 'ꮅ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2302, 0, 0},      // 'ꮆ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2303, 0, 0},      // 'ꮇ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2304, 0, 0},      // 'ꮈ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2305, 0, 0},      // 'ꮉ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2306, 0, 0},      // 'ꮊ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2307, 0, 0},      // 'ꮋ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2308, 0, 0},      // 'ꮌ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2309, 0, 0},      // 'ꮍ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2310, 0, 0},      // 'ꮎ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2311, 0, 0},      // 'ꮏ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2312, 0, 0},      // 'ꮐ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2313, 0, 0},      // 'ꮑ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2314, 0, 0},      // 'ꮒ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2315, 0, 0},      // 'ꮓ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2316, 0, 0},      // 'ꮔ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2317, 0, 0},      // 'ꮕ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2318, 0, 0},      // 'ꮖ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2319, 0, 0},      // 'ꮗ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2320, 0, 0},      // 'ꮘ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2321, 0, 0},      // 'ꮙ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2322, 0, 0},      // 'ꮚ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2323, 0, 0},      // 'ꮛ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2324, 0, 0},      // 'ꮜ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2325, 0, 0},      // 'ꮝ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2326, 0, 0},      // 'ꮞ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2327, 0, 0},      // 'ꮟ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2328, 0, 0},      // 'ꮠ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2329, 0, 0},      // 'ꮡ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2330, 0, 0},      // 'ꮢ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2331, 0, 0},      // 'ꮣ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2332, 0, 0},      // 'ꮤ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2333, 0, 0},      // 'ꮥ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2334, 0, 0},      // 'ꮦ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2335, 0, 0},      // 'ꮧ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2336, 0, 0},      // 'ꮨ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2337, 0, 0},      // 'ꮩ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2338, 0, 0},      // 'ꮪ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2339, 0, 0},      // 'ꮫ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2340, 0, 0},      // 'ꮬ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2341, 0, 0},      // 'ꮭ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2342, 0, 0},      // 'ꮮ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2343, 0, 0},      // 'ꮯ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2344, 0, 0},      // 'ꮰ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2345, 0, 0},      // 'ꮱ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2346, 0, 0},      // 'ꮲ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2347, 0, 0},      // 'ꮳ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2348, 0, 0},      // 'ꮴ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2349, 0, 0},      // 'ꮵ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2350, 0, 0},      // 'ꮶ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2351, 0, 0},      // 'ꮷ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2352, 0, 0},      // 'ꮸ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2353, 0, 0},      // 'ꮹ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2354, 0, 0},      // 'ꮺ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2355, 0, 0},      // 'ꮻ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2356, 0, 0},      // 'ꮼ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2357, 0, 0},      // 'ꮽ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2358, 0, 0},      // 'ꮾ'
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2359, 0, 0},      // 'ꮿ'
    {0, TINYUCD_GC_LO, 0, 12, 0, 0, 0, 0, 0},        // 399 codepoints in range [0xAC00, 0xD788]
    {0, TINYUCD_GC_LO, 0, 13, 0, 0, 0, 0, 0},        // 10773 codepoints in range [0xAC01, 0xD7A3]
    {0, TINYUCD_GC_CS, 0, 0, 0, 0, 0, 0, 0},         // 2048 codepoints in range [0xD800, 0xDFFF]
    {0, TINYUCD_GC_CO, 0, 0, 0, 0, 0, 0, 0},       // 137468 codepoints in range [0xE000, 0x10FFFD]
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2351, 0},    // 0xF900
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2352, 0},    // 0xF901
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2353, 0},    // 0xF902
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2354, 0},    // 0xF903
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2355, 0},    // 0xF904
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2356, 0},    // 0xF905
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2357, 0},    // 0xF906
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2358, 0},    // 0xF907
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2359, 0},    // 0xF908
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2360, 0},    // 0xF909
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2361, 0},    // 0xF90A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2362, 0},    // 0xF90B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2363, 0},    // 0xF90C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2364, 0},    // 0xF90D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2365, 0},    // 0xF90E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2366, 0},    // 0xF90F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2367, 0},    // 0xF910
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2368, 0},    // 0xF911
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2369, 0},    // 0xF912
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2370, 0},    // 0xF913
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2371, 0},    // 0xF914
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2372, 0},    // 0xF915
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2373, 0},    // 0xF916
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2374, 0},    // 0xF917
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2375, 0},    // 0xF918
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2376, 0},    // 0xF919
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2377, 0},    // 0xF91A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2378, 0},    // 0xF91B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2379, 0},    // 0xF91C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2380, 0},    // 0xF91D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2381, 0},    // 0xF91E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2382, 0},    // 0xF91F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2383, 0},    // 0xF920
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2384, 0},    // 0xF921
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2385, 0},    // 0xF922
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2386, 0},    // 0xF923
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2387, 0},    // 0xF924
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2388, 0},    // 0xF925
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2389, 0},    // 0xF926
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2390, 0},    // 0xF927
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2391, 0},    // 0xF928
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2392, 0},    // 0xF929
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2393, 0},    // 0xF92A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2394, 0},    // 0xF92B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2395, 0},    // 0xF92C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2396, 0},    // 0xF92D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2397, 0},    // 0xF92E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2398, 0},    // 0xF92F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2399, 0},    // 0xF930
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2400, 0},    // 0xF931
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2401, 0},    // 0xF932
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2402, 0},    // 0xF933
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2403, 0},    // 0xF934
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2404, 0},    // 0xF935
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2405, 0},    // 0xF936
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2406, 0},    // 0xF937
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2407, 0},    // 0xF938
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2408, 0},    // 0xF939
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2409, 0},    // 0xF93A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2410, 0},    // 0xF93B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2411, 0},    // 0xF93C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2412, 0},    // 0xF93D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2413, 0},    // 0xF93E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2414, 0},    // 0xF93F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2415, 0},    // 0xF940
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2416, 0},    // 0xF941
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2417, 0},    // 0xF942
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2418, 0},    // 0xF943
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2419, 0},    // 0xF944
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2420, 0},    // 0xF945
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2421, 0},    // 0xF946
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2422, 0},    // 0xF947
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2423, 0},    // 0xF948
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2424, 0},    // 0xF949
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2425, 0},    // 0xF94A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2426, 0},    // 0xF94B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2427, 0},    // 0xF94C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2428, 0},    // 0xF94D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2429, 0},    // 0xF94E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2430, 0},    // 0xF94F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2431, 0},    // 0xF950
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2432, 0},    // 0xF951
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2433, 0},    // 0xF952
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2434, 0},    // 0xF953
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2435, 0},    // 0xF954
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2436, 0},    // 0xF955
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2437, 0},    // 0xF956
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2438, 0},    // 0xF957
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2439, 0},    // 0xF958
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2440, 0},    // 0xF959
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2441, 0},    // 0xF95A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2442, 0},    // 0xF95B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2443, 0},    // 0xF95C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2444, 0},    // 0xF95D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2445, 0},    // 0xF95E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2446, 0},    // 0xF95F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2447, 0},    // 0xF960
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2448, 0},    // 0xF961
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2449, 0},    // 0xF962
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2450, 0},    // 0xF963
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2451, 0},    // 0xF964
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2452, 0},    // 0xF965
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2453, 0},    // 0xF966
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2454, 0},    // 0xF967
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2455, 0},    // 0xF968
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2456, 0},    // 0xF969
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2457, 0},    // 0xF96A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2458, 0},    // 0xF96B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2459, 0},    // 0xF96C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2460, 0},    // 0xF96D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2461, 0},    // 0xF96E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2462, 0},    // 0xF96F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2463, 0},    // 0xF970
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2464, 0},    // 0xF971
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2465, 0},    // 0xF972
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2466, 0},    // 0xF973
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2467, 0},    // 0xF974
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2468, 0},    // 0xF975
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2469, 0},    // 0xF976
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2470, 0},    // 0xF977
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2471, 0},    // 0xF978
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2472, 0},    // 0xF979
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2473, 0},    // 0xF97A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2474, 0},    // 0xF97B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2475, 0},    // 0xF97C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2476, 0},    // 0xF97D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2477, 0},    // 0xF97E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2478, 0},    // 0xF97F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2479, 0},    // 0xF980
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2480, 0},    // 0xF981
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2481, 0},    // 0xF982
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2482, 0},    // 0xF983
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2483, 0},    // 0xF984
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2484, 0},    // 0xF985
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2485, 0},    // 0xF986
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2486, 0},    // 0xF987
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2487, 0},    // 0xF988
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2488, 0},    // 0xF989
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2489, 0},    // 0xF98A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2490, 0},    // 0xF98B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2491, 0},    // 0xF98C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2492, 0},    // 0xF98D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2493, 0},    // 0xF98E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2494, 0},    // 0xF98F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2495, 0},    // 0xF990
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2496, 0},    // 0xF991
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2497, 0},    // 0xF992
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2498, 0},    // 0xF993
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2499, 0},    // 0xF994
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2500, 0},    // 0xF995
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2501, 0},    // 0xF996
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2502, 0},    // 0xF997
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2503, 0},    // 0xF998
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2504, 0},    // 0xF999
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2505, 0},    // 0xF99A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2506, 0},    // 0xF99B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2507, 0},    // 0xF99C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2508, 0},    // 0xF99D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2509, 0},    // 0xF99E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2510, 0},    // 0xF99F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2511, 0},    // 0xF9A0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2512, 0},    // 0xF9A1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2513, 0},    // 0xF9A2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2514, 0},    // 0xF9A3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2515, 0},    // 0xF9A4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2516, 0},    // 0xF9A5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2517, 0},    // 0xF9A6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2518, 0},    // 0xF9A7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2519, 0},    // 0xF9A8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2520, 0},    // 0xF9A9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2521, 0},    // 0xF9AA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2522, 0},    // 0xF9AB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2523, 0},    // 0xF9AC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2524, 0},    // 0xF9AD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2525, 0},    // 0xF9AE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2526, 0},    // 0xF9AF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2527, 0},    // 0xF9B0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2528, 0},    // 0xF9B1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2529, 0},    // 0xF9B2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2530, 0},    // 0xF9B3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2531, 0},    // 0xF9B4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2532, 0},    // 0xF9B5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2533, 0},    // 0xF9B6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2534, 0},    // 0xF9B7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2535, 0},    // 0xF9B8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2536, 0},    // 0xF9B9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2537, 0},    // 0xF9BA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2538, 0},    // 0xF9BB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2539, 0},    // 0xF9BC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2540, 0},    // 0xF9BD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2541, 0},    // 0xF9BE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2542, 0},    // 0xF9BF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2543, 0},    // 0xF9C0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2544, 0},    // 0xF9C1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2545, 0},    // 0xF9C2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2546, 0},    // 0xF9C3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2547, 0},    // 0xF9C4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2548, 0},    // 0xF9C5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2549, 0},    // 0xF9C6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2550, 0},    // 0xF9C7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2551, 0},    // 0xF9C8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2552, 0},    // 0xF9C9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2553, 0},    // 0xF9CA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2554, 0},    // 0xF9CB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2555, 0},    // 0xF9CC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2556, 0},    // 0xF9CD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2557, 0},    // 0xF9CE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2558, 0},    // 0xF9CF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2559, 0},    // 0xF9D0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2560, 0},    // 0xF9D1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2561, 0},    // 0xF9D2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2562, 0},    // 0xF9D3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2563, 0},    // 0xF9D4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2564, 0},    // 0xF9D5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2565, 0},    // 0xF9D6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2566, 0},    // 0xF9D7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2567, 0},    // 0xF9D8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2568, 0},    // 0xF9D9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2569, 0},    // 0xF9DA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2570, 0},    // 0xF9DB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2571, 0},    // 0xF9DC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2572, 0},    // 0xF9DD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2573, 0},    // 0xF9DE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2574, 0},    // 0xF9DF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2575, 0},    // 0xF9E0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2576, 0},    // 0xF9E1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2577, 0},    // 0xF9E2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2578, 0},    // 0xF9E3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2579, 0},    // 0xF9E4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2580, 0},    // 0xF9E5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2581, 0},    // 0xF9E6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2582, 0},    // 0xF9E7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2583, 0},    // 0xF9E8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2584, 0},    // 0xF9E9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2585, 0},    // 0xF9EA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2586, 0},    // 0xF9EB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2587, 0},    // 0xF9EC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2588, 0},    // 0xF9ED
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2589, 0},    // 0xF9EE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2590, 0},    // 0xF9EF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2591, 0},    // 0xF9F0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2592, 0},    // 0xF9F1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2593, 0},    // 0xF9F2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2594, 0},    // 0xF9F3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2595, 0},    // 0xF9F4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2596, 0},    // 0xF9F5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2597, 0},    // 0xF9F6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2598, 0},    // 0xF9F7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2599, 0},    // 0xF9F8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2600, 0},    // 0xF9F9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2601, 0},    // 0xF9FA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2602, 0},    // 0xF9FB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2603, 0},    // 0xF9FC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2604, 0},    // 0xF9FD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2605, 0},    // 0xF9FE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2606, 0},    // 0xF9FF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2607, 0},    // 0xFA00
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2608, 0},    // 0xFA01
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2609, 0},    // 0xFA02
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2610, 0},    // 0xFA03
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2611, 0},    // 0xFA04
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2612, 0},    // 0xFA05
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2613, 0},    // 0xFA06
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2614, 0},    // 0xFA07
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2615, 0},    // 0xFA08
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2616, 0},    // 0xFA09
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2617, 0},    // 0xFA0A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2618, 0},    // 0xFA0B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2619, 0},    // 0xFA0C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2620, 0},    // 0xFA0D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2621, 0},    // 0xFA10
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2622, 0},    // 0xFA12
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2623, 0},    // 0xFA15
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2624, 0},    // 0xFA16
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2625, 0},    // 0xFA17
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2626, 0},    // 0xFA18
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2627, 0},    // 0xFA19
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2628, 0},    // 0xFA1A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2629, 0},    // 0xFA1B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2630, 0},    // 0xFA1C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2631, 0},    // 0xFA1D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2632, 0},    // 0xFA1E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2633, 0},    // 0xFA20
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2634, 0},    // 0xFA22
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2635, 0},    // 0xFA25
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2636, 0},    // 0xFA26
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2637, 0},    // 0xFA2A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2638, 0},    // 0xFA2B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2639, 0},    // 0xFA2C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2640, 0},    // 0xFA2D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2641, 0},    // 0xFA2E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2642, 0},    // 0xFA2F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2643, 0},    // 0xFA30
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2644, 0},    // 0xFA31
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2645, 0},    // 0xFA32
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2646, 0},    // 0xFA33
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2647, 0},    // 0xFA34
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2648, 0},    // 0xFA35
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2649, 0},    // 0xFA36
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2650, 0},    // 0xFA37
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2651, 0},    // 0xFA38
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2652, 0},    // 0xFA39
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2653, 0},    // 0xFA3A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2654, 0},    // 0xFA3B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2655, 0},    // 0xFA3C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2656, 0},    // 0xFA3D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2657, 0},    // 0xFA3E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2658, 0},    // 0xFA3F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2659, 0},    // 0xFA40
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2660, 0},    // 0xFA41
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2661, 0},    // 0xFA42
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2662, 0},    // 0xFA43
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2663, 0},    // 0xFA44
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2664, 0},    // 0xFA45
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2665, 0},    // 0xFA46
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2666, 0},    // 0xFA47
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2667, 0},    // 0xFA48
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2668, 0},    // 0xFA49
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2669, 0},    // 0xFA4A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2670, 0},    // 0xFA4B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2671, 0},    // 0xFA4C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2672, 0},    // 0xFA4D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2673, 0},    // 0xFA4E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2674, 0},    // 0xFA4F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2675, 0},    // 0xFA50
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2676, 0},    // 0xFA51
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2677, 0},    // 0xFA52
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2678, 0},    // 0xFA53
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2679, 0},    // 0xFA54
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2680, 0},    // 0xFA55
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2681, 0},    // 0xFA56
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2682, 0},    // 0xFA57
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2683, 0},    // 0xFA58
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2684, 0},    // 0xFA59
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2685, 0},    // 0xFA5A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2686, 0},    // 0xFA5B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2687, 0},    // 0xFA5C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2688, 0},    // 0xFA5D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2689, 0},    // 0xFA5E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2690, 0},    // 0xFA5F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2691, 0},    // 0xFA60
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2692, 0},    // 0xFA61
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2693, 0},    // 0xFA62
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2694, 0},    // 0xFA63
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2695, 0},    // 0xFA64
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2696, 0},    // 0xFA65
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2697, 0},    // 0xFA66
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2698, 0},    // 0xFA67
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2699, 0},    // 0xFA68
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2700, 0},    // 0xFA69
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2701, 0},    // 0xFA6A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2702, 0},    // 0xFA6B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2703, 0},    // 0xFA6C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2704, 0},    // 0xFA6D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2705, 0},    // 0xFA70
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2706, 0},    // 0xFA71
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2707, 0},    // 0xFA72
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2708, 0},    // 0xFA73
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2709, 0},    // 0xFA74
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2710, 0},    // 0xFA75
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2711, 0},    // 0xFA76
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2712, 0},    // 0xFA77
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2713, 0},    // 0xFA78
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2714, 0},    // 0xFA79
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2715, 0},    // 0xFA7A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2716, 0},    // 0xFA7B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2717, 0},    // 0xFA7C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2718, 0},    // 0xFA7D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2719, 0},    // 0xFA7E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2720, 0},    // 0xFA7F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2721, 0},    // 0xFA80
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2722, 0},    // 0xFA81
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2723, 0},    // 0xFA82
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2724, 0},    // 0xFA83
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2725, 0},    // 0xFA84
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2726, 0},    // 0xFA85
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2727, 0},    // 0xFA86
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2728, 0},    // 0xFA87
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2729, 0},    // 0xFA88
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2730, 0},    // 0xFA89
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2731, 0},    // 0xFA8A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2732, 0},    // 0xFA8B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2733, 0},    // 0xFA8C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2734, 0},    // 0xFA8D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2735, 0},    // 0xFA8E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2736, 0},    // 0xFA8F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2737, 0},    // 0xFA90
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2738, 0},    // 0xFA91
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2739, 0},    // 0xFA92
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2740, 0},    // 0xFA93
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2741, 0},    // 0xFA94
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2742, 0},    // 0xFA95
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2743, 0},    // 0xFA96
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2744, 0},    // 0xFA97
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2745, 0},    // 0xFA98
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2746, 0},    // 0xFA99
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2747, 0},    // 0xFA9A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2748, 0},    // 0xFA9B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2749, 0},    // 0xFA9C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2750, 0},    // 0xFA9D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2751, 0},    // 0xFA9E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2752, 0},    // 0xFA9F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2753, 0},    // 0xFAA0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2754, 0},    // 0xFAA1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2755, 0},    // 0xFAA2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2756, 0},    // 0xFAA3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2757, 0},    // 0xFAA4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2758, 0},    // 0xFAA5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2759, 0},    // 0xFAA6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2760, 0},    // 0xFAA7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2761, 0},    // 0xFAA8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2762, 0},    // 0xFAA9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2763, 0},    // 0xFAAA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2764, 0},    // 0xFAAB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2765, 0},    // 0xFAAC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2766, 0},    // 0xFAAD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2767, 0},    // 0xFAAE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2768, 0},    // 0xFAAF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2769, 0},    // 0xFAB0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2770, 0},    // 0xFAB1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2771, 0},    // 0xFAB2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2772, 0},    // 0xFAB3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2773, 0},    // 0xFAB4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2774, 0},    // 0xFAB5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2775, 0},    // 0xFAB6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2776, 0},    // 0xFAB7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2777, 0},    // 0xFAB8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2778, 0},    // 0xFAB9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2779, 0},    // 0xFABA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2780, 0},    // 0xFABB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2781, 0},    // 0xFABC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2782, 0},    // 0xFABD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2783, 0},    // 0xFABE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2784, 0},    // 0xFABF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2785, 0},    // 0xFAC0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2786, 0},    // 0xFAC1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2787, 0},    // 0xFAC2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2788, 0},    // 0xFAC3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2789, 0},    // 0xFAC4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2790, 0},    // 0xFAC5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2791, 0},    // 0xFAC6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2792, 0},    // 0xFAC7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2793, 0},    // 0xFAC8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2794, 0},    // 0xFAC9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2795, 0},    // 0xFACA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2796, 0},    // 0xFACB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2797, 0},    // 0xFACC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2798, 0},    // 0xFACD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2799, 0},    // 0xFACE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2800, 0},    // 0xFACF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2801, 0},    // 0xFAD0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2802, 0},    // 0xFAD1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2803, 0},    // 0xFAD2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2804, 0},    // 0xFAD3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2805, 0},    // 0xFAD4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2806, 0},    // 0xFAD5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2807, 0},    // 0xFAD6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2808, 0},    // 0xFAD7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2809, 0},    // 0xFAD8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2810, 0},    // 0xFAD9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2360, 2811, 0}, // 'ﬀ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2361, 2812, 0}, // 'ﬁ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2362, 2813, 0}, // 'ﬂ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2363, 2814, 0}, // 'ﬃ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2364, 2815, 0}, // 'ﬄ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2365, 2816, 0}, // 'ﬅ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2366, 2817, 0}, // 'ﬆ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2367, 2818, 0}, // 'ﬓ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2368, 2819, 0}, // 'ﬔ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2369, 2820, 0}, // 'ﬕ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2370, 2821, 0}, // 'ﬖ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2371, 2822, 0}, // 'ﬗ'
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2823, 0},    // 0xFB1D
    {0, TINYUCD_GC_MN, 26, 4, 2, 0, 0, 0, 0},      // 0xFB1E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2824, 0},    // 0xFB1F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2825, 0},    // 0xFB20
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2826, 0},    // 0xFB21
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2827, 0},    // 0xFB22
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2828, 0},    // 0xFB23
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2829, 0},    // 0xFB24
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2830, 0},    // 0xFB25
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2831, 0},    // 0xFB26
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2832, 0},    // 0xFB27
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2833, 0},    // 0xFB28
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 2834, 0},    // '﬩'
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2835, 0},    // 0xFB2A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2836, 0},    // 0xFB2B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2837, 0},    // 0xFB2C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2838, 0},    // 0xFB2D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2839, 0},    // 0xFB2E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2840, 0},    // 0xFB2F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2841, 0},    // 0xFB30
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2842, 0},    // 0xFB31
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2843, 0},    // 0xFB32
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2844, 0},    // 0xFB33
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2845, 0},    // 0xFB34
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2846, 0},    // 0xFB35
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2847, 0},    // 0xFB36
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2848, 0},    // 0xFB38
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2849, 0},    // 0xFB39
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2850, 0},    // 0xFB3A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2851, 0},    // 0xFB3B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2852, 0},    // 0xFB3C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2853, 0},    // 0xFB3E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2854, 0},    // 0xFB40
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2855, 0},    // 0xFB41
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2856, 0},    // 0xFB43
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2857, 0},    // 0xFB44
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2858, 0},    // 0xFB46
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2859, 0},    // 0xFB47
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2860, 0},    // 0xFB48
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2861, 0},    // 0xFB49
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2862, 0},    // 0xFB4A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2863, 0},    // 0xFB4B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2864, 0},    // 0xFB4C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2865, 0},    // 0xFB4D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2866, 0},    // 0xFB4E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2867, 0},    // 0xFB4F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2868, 0},    // 0xFB50
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2869, 0},    // 0xFB51
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2870, 0},    // 0xFB52
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2871, 0},    // 0xFB53
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2872, 0},    // 0xFB54
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2873, 0},    // 0xFB55
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2874, 0},    // 0xFB56
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2875, 0},    // 0xFB57
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2876, 0},    // 0xFB58
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2877, 0},    // 0xFB59
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2878, 0},    // 0xFB5A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2879, 0},    // 0xFB5B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2880, 0},    // 0xFB5C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2881, 0},    // 0xFB5D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2882, 0},    // 0xFB5E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2883, 0},    // 0xFB5F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2884, 0},    // 0xFB60
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2885, 0},    // 0xFB61
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2886, 0},    // 0xFB62
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2887, 0},    // 0xFB63
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2888, 0},    // 0xFB64
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2889, 0},    // 0xFB65
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2890, 0},    // 0xFB66
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2891, 0},    // 0xFB67
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2892, 0},    // 0xFB68
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2893, 0},    // 0xFB69
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2894, 0},    // 0xFB6A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2895, 0},    // 0xFB6B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2896, 0},    // 0xFB6C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2897, 0},    // 0xFB6D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2898, 0},    // 0xFB6E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2899, 0},    // 0xFB6F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2900, 0},    // 0xFB70
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2901, 0},    // 0xFB71
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2902, 0},    // 0xFB72
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2903, 0},    // 0xFB73
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2904, 0},    // 0xFB74
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2905, 0},    // 0xFB75
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2906, 0},    // 0xFB76
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2907, 0},    // 0xFB77
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2908, 0},    // 0xFB78
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2909, 0},    // 0xFB79
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2910, 0},    // 0xFB7A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2911, 0},    // 0xFB7B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2912, 0},    // 0xFB7C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2913, 0},    // 0xFB7D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2914, 0},    // 0xFB7E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2915, 0},    // 0xFB7F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2916, 0},    // 0xFB80
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2917, 0},    // 0xFB81
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2918, 0},    // 0xFB82
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2919, 0},    // 0xFB83
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2920, 0},    // 0xFB84
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2921, 0},    // 0xFB85
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2922, 0},    // 0xFB86
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2923, 0},    // 0xFB87
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2924, 0},    // 0xFB88
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2925, 0},    // 0xFB89
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2926, 0},    // 0xFB8A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2927, 0},    // 0xFB8B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2928, 0},    // 0xFB8C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2929, 0},    // 0xFB8D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2930, 0},    // 0xFB8E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2931, 0},    // 0xFB8F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2932, 0},    // 0xFB90
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2933, 0},    // 0xFB91
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2934, 0},    // 0xFB92
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2935, 0},    // 0xFB93
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2936, 0},    // 0xFB94
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2937, 0},    // 0xFB95
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2938, 0},    // 0xFB96
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2939, 0},    // 0xFB97
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2940, 0},    // 0xFB98
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2941, 0},    // 0xFB99
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2942, 0},    // 0xFB9A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2943, 0},    // 0xFB9B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2944, 0},    // 0xFB9C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2945, 0},    // 0xFB9D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2946, 0},    // 0xFB9E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2947, 0},    // 0xFB9F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2948, 0},    // 0xFBA0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2949, 0},    // 0xFBA1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2950, 0},    // 0xFBA2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2951, 0},    // 0xFBA3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2952, 0},    // 0xFBA4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2953, 0},    // 0xFBA5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2954, 0},    // 0xFBA6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2955, 0},    // 0xFBA7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2956, 0},    // 0xFBA8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2957, 0},    // 0xFBA9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2958, 0},    // 0xFBAA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2959, 0},    // 0xFBAB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2960, 0},    // 0xFBAC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2961, 0},    // 0xFBAD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2962, 0},    // 0xFBAE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2963, 0},    // 0xFBAF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2964, 0},    // 0xFBB0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2965, 0},    // 0xFBB1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2966, 0},    // 0xFBD3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2967, 0},    // 0xFBD4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2968, 0},    // 0xFBD5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2969, 0},    // 0xFBD6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2970, 0},    // 0xFBD7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2971, 0},    // 0xFBD8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2972, 0},    // 0xFBD9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2973, 0},    // 0xFBDA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2974, 0},    // 0xFBDB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2975, 0},    // 0xFBDC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2976, 0},    // 0xFBDD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2977, 0},    // 0xFBDE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2978, 0},    // 0xFBDF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2979, 0},    // 0xFBE0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2980, 0},    // 0xFBE1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2981, 0},    // 0xFBE2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2982, 0},    // 0xFBE3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2983, 0},    // 0xFBE4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2984, 0},    // 0xFBE5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2985, 0},    // 0xFBE6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2986, 0},    // 0xFBE7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2987, 0},    // 0xFBE8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2988, 0},    // 0xFBE9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2989, 0},    // 0xFBEA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2990, 0},    // 0xFBEB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2991, 0},    // 0xFBEC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2992, 0},    // 0xFBED
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2993, 0},    // 0xFBEE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2994, 0},    // 0xFBEF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2995, 0},    // 0xFBF0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2996, 0},    // 0xFBF1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2997, 0},    // 0xFBF2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2998, 0},    // 0xFBF3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 2999, 0},    // 0xFBF4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3000, 0},    // 0xFBF5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3001, 0},    // 0xFBF6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3002, 0},    // 0xFBF7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3003, 0},    // 0xFBF8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3004, 0},    // 0xFBF9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3005, 0},    // 0xFBFA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3006, 0},    // 0xFBFB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3007, 0},    // 0xFBFC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3008, 0},    // 0xFBFD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3009, 0},    // 0xFBFE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3010, 0},    // 0xFBFF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3011, 0},    // 0xFC00
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3012, 0},    // 0xFC01
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3013, 0},    // 0xFC02
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3014, 0},    // 0xFC03
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3015, 0},    // 0xFC04
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3016, 0},    // 0xFC05
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3017, 0},    // 0xFC06
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3018, 0},    // 0xFC07
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3019, 0},    // 0xFC08
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3020, 0},    // 0xFC09
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3021, 0},    // 0xFC0A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3022, 0},    // 0xFC0B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3023, 0},    // 0xFC0C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3024, 0},    // 0xFC0D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3025, 0},    // 0xFC0E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3026, 0},    // 0xFC0F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3027, 0},    // 0xFC10
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3028, 0},    // 0xFC11
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3029, 0},    // 0xFC12
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3030, 0},    // 0xFC13
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3031, 0},    // 0xFC14
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3032, 0},    // 0xFC15
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3033, 0},    // 0xFC16
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3034, 0},    // 0xFC17
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3035, 0},    // 0xFC18
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3036, 0},    // 0xFC19
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3037, 0},    // 0xFC1A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3038, 0},    // 0xFC1B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3039, 0},    // 0xFC1C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3040, 0},    // 0xFC1D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3041, 0},    // 0xFC1E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3042, 0},    // 0xFC1F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3043, 0},    // 0xFC20
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3044, 0},    // 0xFC21
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3045, 0},    // 0xFC22
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3046, 0},    // 0xFC23
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3047, 0},    // 0xFC24
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3048, 0},    // 0xFC25
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3049, 0},    // 0xFC26
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3050, 0},    // 0xFC27
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3051, 0},    // 0xFC28
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3052, 0},    // 0xFC29
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3053, 0},    // 0xFC2A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3054, 0},    // 0xFC2B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3055, 0},    // 0xFC2C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3056, 0},    // 0xFC2D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3057, 0},    // 0xFC2E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3058, 0},    // 0xFC2F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3059, 0},    // 0xFC30
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3060, 0},    // 0xFC31
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3061, 0},    // 0xFC32
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3062, 0},    // 0xFC33
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3063, 0},    // 0xFC34
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3064, 0},    // 0xFC35
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3065, 0},    // 0xFC36
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3066, 0},    // 0xFC37
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3067, 0},    // 0xFC38
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3068, 0},    // 0xFC39
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3069, 0},    // 0xFC3A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3070, 0},    // 0xFC3B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3071, 0},    // 0xFC3C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3072, 0},    // 0xFC3D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3073, 0},    // 0xFC3E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3074, 0},    // 0xFC3F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3075, 0},    // 0xFC40
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3076, 0},    // 0xFC41
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3077, 0},    // 0xFC42
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3078, 0},    // 0xFC43
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3079, 0},    // 0xFC44
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3080, 0},    // 0xFC45
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3081, 0},    // 0xFC46
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3082, 0},    // 0xFC47
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3083, 0},    // 0xFC48
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3084, 0},    // 0xFC49
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3085, 0},    // 0xFC4A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3086, 0},    // 0xFC4B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3087, 0},    // 0xFC4C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3088, 0},    // 0xFC4D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3089, 0},    // 0xFC4E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3090, 0},    // 0xFC4F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3091, 0},    // 0xFC50
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3092, 0},    // 0xFC51
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3093, 0},    // 0xFC52
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3094, 0},    // 0xFC53
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3095, 0},    // 0xFC54
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3096, 0},    // 0xFC55
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3097, 0},    // 0xFC56
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3098, 0},    // 0xFC57
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3099, 0},    // 0xFC58
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3100, 0},    // 0xFC59
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3101, 0},    // 0xFC5A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3102, 0},    // 0xFC5B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3103, 0},    // 0xFC5C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3104, 0},    // 0xFC5D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3105, 0},    // 0xFC5E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3106, 0},    // 0xFC5F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3107, 0},    // 0xFC60
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3108, 0},    // 0xFC61
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3109, 0},    // 0xFC62
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3110, 0},    // 0xFC63
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3111, 0},    // 0xFC64
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3112, 0},    // 0xFC65
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3113, 0},    // 0xFC66
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3114, 0},    // 0xFC67
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3115, 0},    // 0xFC68
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3116, 0},    // 0xFC69
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3117, 0},    // 0xFC6A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3118, 0},    // 0xFC6B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3119, 0},    // 0xFC6C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3120, 0},    // 0xFC6D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3121, 0},    // 0xFC6E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3122, 0},    // 0xFC6F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3123, 0},    // 0xFC70
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3124, 0},    // 0xFC71
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3125, 0},    // 0xFC72
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3126, 0},    // 0xFC73
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3127, 0},    // 0xFC74
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3128, 0},    // 0xFC75
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3129, 0},    // 0xFC76
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3130, 0},    // 0xFC77
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3131, 0},    // 0xFC78
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3132, 0},    // 0xFC79
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3133, 0},    // 0xFC7A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3134, 0},    // 0xFC7B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3135, 0},    // 0xFC7C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3136, 0},    // 0xFC7D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3137, 0},    // 0xFC7E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3138, 0},    // 0xFC7F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3139, 0},    // 0xFC80
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3140, 0},    // 0xFC81
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3141, 0},    // 0xFC82
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3142, 0},    // 0xFC83
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3143, 0},    // 0xFC84
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3144, 0},    // 0xFC85
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3145, 0},    // 0xFC86
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3146, 0},    // 0xFC87
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3147, 0},    // 0xFC88
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3148, 0},    // 0xFC89
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3149, 0},    // 0xFC8A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3150, 0},    // 0xFC8B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3151, 0},    // 0xFC8C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3152, 0},    // 0xFC8D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3153, 0},    // 0xFC8E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3154, 0},    // 0xFC8F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3155, 0},    // 0xFC90
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3156, 0},    // 0xFC91
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3157, 0},    // 0xFC92
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3158, 0},    // 0xFC93
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3159, 0},    // 0xFC94
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3160, 0},    // 0xFC95
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3161, 0},    // 0xFC96
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3162, 0},    // 0xFC97
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3163, 0},    // 0xFC98
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3164, 0},    // 0xFC99
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3165, 0},    // 0xFC9A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3166, 0},    // 0xFC9B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3167, 0},    // 0xFC9C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3168, 0},    // 0xFC9D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3169, 0},    // 0xFC9E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3170, 0},    // 0xFC9F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3171, 0},    // 0xFCA0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3172, 0},    // 0xFCA1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3173, 0},    // 0xFCA2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3174, 0},    // 0xFCA3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3175, 0},    // 0xFCA4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3176, 0},    // 0xFCA5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3177, 0},    // 0xFCA6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3178, 0},    // 0xFCA7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3179, 0},    // 0xFCA8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3180, 0},    // 0xFCA9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3181, 0},    // 0xFCAA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3182, 0},    // 0xFCAB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3183, 0},    // 0xFCAC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3184, 0},    // 0xFCAD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3185, 0},    // 0xFCAE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3186, 0},    // 0xFCAF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3187, 0},    // 0xFCB0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3188, 0},    // 0xFCB1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3189, 0},    // 0xFCB2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3190, 0},    // 0xFCB3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3191, 0},    // 0xFCB4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3192, 0},    // 0xFCB5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3193, 0},    // 0xFCB6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3194, 0},    // 0xFCB7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3195, 0},    // 0xFCB8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3196, 0},    // 0xFCB9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3197, 0},    // 0xFCBA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3198, 0},    // 0xFCBB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3199, 0},    // 0xFCBC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3200, 0},    // 0xFCBD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3201, 0},    // 0xFCBE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3202, 0},    // 0xFCBF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3203, 0},    // 0xFCC0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3204, 0},    // 0xFCC1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3205, 0},    // 0xFCC2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3206, 0},    // 0xFCC3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3207, 0},    // 0xFCC4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3208, 0},    // 0xFCC5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3209, 0},    // 0xFCC6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3210, 0},    // 0xFCC7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3211, 0},    // 0xFCC8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3212, 0},    // 0xFCC9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3213, 0},    // 0xFCCA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3214, 0},    // 0xFCCB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3215, 0},    // 0xFCCC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3216, 0},    // 0xFCCD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3217, 0},    // 0xFCCE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3218, 0},    // 0xFCCF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3219, 0},    // 0xFCD0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3220, 0},    // 0xFCD1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3221, 0},    // 0xFCD2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3222, 0},    // 0xFCD3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3223, 0},    // 0xFCD4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3224, 0},    // 0xFCD5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3225, 0},    // 0xFCD6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3226, 0},    // 0xFCD7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3227, 0},    // 0xFCD8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3228, 0},    // 0xFCD9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3229, 0},    // 0xFCDA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3230, 0},    // 0xFCDB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3231, 0},    // 0xFCDC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3232, 0},    // 0xFCDD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3233, 0},    // 0xFCDE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3234, 0},    // 0xFCDF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3235, 0},    // 0xFCE0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3236, 0},    // 0xFCE1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3237, 0},    // 0xFCE2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3238, 0},    // 0xFCE3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3239, 0},    // 0xFCE4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3240, 0},    // 0xFCE5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3241, 0},    // 0xFCE6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3242, 0},    // 0xFCE7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3243, 0},    // 0xFCE8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3244, 0},    // 0xFCE9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3245, 0},    // 0xFCEA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3246, 0},    // 0xFCEB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3247, 0},    // 0xFCEC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3248, 0},    // 0xFCED
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3249, 0},    // 0xFCEE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3250, 0},    // 0xFCEF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3251, 0},    // 0xFCF0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3252, 0},    // 0xFCF1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3253, 0},    // 0xFCF2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3254, 0},    // 0xFCF3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3255, 0},    // 0xFCF4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3256, 0},    // 0xFCF5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3257, 0},    // 0xFCF6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3258, 0},    // 0xFCF7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3259, 0},    // 0xFCF8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3260, 0},    // 0xFCF9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3261, 0},    // 0xFCFA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3262, 0},    // 0xFCFB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3263, 0},    // 0xFCFC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3264, 0},    // 0xFCFD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3265, 0},    // 0xFCFE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3266, 0},    // 0xFCFF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3267, 0},    // 0xFD00
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3268, 0},    // 0xFD01
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3269, 0},    // 0xFD02
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3270, 0},    // 0xFD03
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3271, 0},    // 0xFD04
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3272, 0},    // 0xFD05
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3273, 0},    // 0xFD06
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3274, 0},    // 0xFD07
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3275, 0},    // 0xFD08
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3276, 0},    // 0xFD09
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3277, 0},    // 0xFD0A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3278, 0},    // 0xFD0B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3279, 0},    // 0xFD0C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3280, 0},    // 0xFD0D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3281, 0},    // 0xFD0E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3282, 0},    // 0xFD0F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3283, 0},    // 0xFD10
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3284, 0},    // 0xFD11
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3285, 0},    // 0xFD12
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3286, 0},    // 0xFD13
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3287, 0},    // 0xFD14
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3288, 0},    // 0xFD15
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3289, 0},    // 0xFD16
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3290, 0},    // 0xFD17
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3291, 0},    // 0xFD18
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3292, 0},    // 0xFD19
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3293, 0},    // 0xFD1A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3294, 0},    // 0xFD1B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3295, 0},    // 0xFD1C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3296, 0},    // 0xFD1D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3297, 0},    // 0xFD1E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3298, 0},    // 0xFD1F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3299, 0},    // 0xFD20
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3300, 0},    // 0xFD21
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3301, 0},    // 0xFD22
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3302, 0},    // 0xFD23
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3303, 0},    // 0xFD24
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3304, 0},    // 0xFD25
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3305, 0},    // 0xFD26
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3306, 0},    // 0xFD27
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3307, 0},    // 0xFD28
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3308, 0},    // 0xFD29
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3309, 0},    // 0xFD2A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3310, 0},    // 0xFD2B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3311, 0},    // 0xFD2C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3312, 0},    // 0xFD2D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3313, 0},    // 0xFD2E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3314, 0},    // 0xFD2F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3315, 0},    // 0xFD30
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3316, 0},    // 0xFD31
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3317, 0},    // 0xFD32
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3318, 0},    // 0xFD33
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3319, 0},    // 0xFD34
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3320, 0},    // 0xFD35
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3321, 0},    // 0xFD36
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3322, 0},    // 0xFD37
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3323, 0},    // 0xFD38
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3324, 0},    // 0xFD39
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3325, 0},    // 0xFD3A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3326, 0},    // 0xFD3B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3327, 0},    // 0xFD3C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3328, 0},    // 0xFD3D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3329, 0},    // 0xFD50
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3330, 0},    // 0xFD51
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3331, 0},    // 0xFD52
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3332, 0},    // 0xFD53
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3333, 0},    // 0xFD54
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3334, 0},    // 0xFD55
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3335, 0},    // 0xFD56
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3336, 0},    // 0xFD57
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3337, 0},    // 0xFD58
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3338, 0},    // 0xFD59
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3339, 0},    // 0xFD5A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3340, 0},    // 0xFD5B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3341, 0},    // 0xFD5C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3342, 0},    // 0xFD5D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3343, 0},    // 0xFD5E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3344, 0},    // 0xFD5F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3345, 0},    // 0xFD60
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3346, 0},    // 0xFD61
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3347, 0},    // 0xFD62
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3348, 0},    // 0xFD63
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3349, 0},    // 0xFD64
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3350, 0},    // 0xFD65
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3351, 0},    // 0xFD66
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3352, 0},    // 0xFD67
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3353, 0},    // 0xFD68
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3354, 0},    // 0xFD69
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3355, 0},    // 0xFD6A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3356, 0},    // 0xFD6B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3357, 0},    // 0xFD6C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3358, 0},    // 0xFD6D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3359, 0},    // 0xFD6E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3360, 0},    // 0xFD6F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3361, 0},    // 0xFD70
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3362, 0},    // 0xFD71
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3363, 0},    // 0xFD72
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3364, 0},    // 0xFD73
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3365, 0},    // 0xFD74
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3366, 0},    // 0xFD75
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3367, 0},    // 0xFD76
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3368, 0},    // 0xFD77
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3369, 0},    // 0xFD78
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3370, 0},    // 0xFD79
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3371, 0},    // 0xFD7A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3372, 0},    // 0xFD7B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3373, 0},    // 0xFD7C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3374, 0},    // 0xFD7D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3375, 0},    // 0xFD7E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3376, 0},    // 0xFD7F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3377, 0},    // 0xFD80
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3378, 0},    // 0xFD81
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3379, 0},    // 0xFD82
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3380, 0},    // 0xFD83
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3381, 0},    // 0xFD84
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3382, 0},    // 0xFD85
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3383, 0},    // 0xFD86
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3384, 0},    // 0xFD87
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3385, 0},    // 0xFD88
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3386, 0},    // 0xFD89
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3387, 0},    // 0xFD8A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3388, 0},    // 0xFD8B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3389, 0},    // 0xFD8C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3390, 0},    // 0xFD8D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3391, 0},    // 0xFD8E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3392, 0},    // 0xFD8F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3393, 0},    // 0xFD92
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3394, 0},    // 0xFD93
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3395, 0},    // 0xFD94
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3396, 0},    // 0xFD95
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3397, 0},    // 0xFD96
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3398, 0},    // 0xFD97
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3399, 0},    // 0xFD98
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3400, 0},    // 0xFD99
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3401, 0},    // 0xFD9A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3402, 0},    // 0xFD9B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3403, 0},    // 0xFD9C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3404, 0},    // 0xFD9D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3405, 0},    // 0xFD9E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3406, 0},    // 0xFD9F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3407, 0},    // 0xFDA0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3408, 0},    // 0xFDA1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3409, 0},    // 0xFDA2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3410, 0},    // 0xFDA3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3411, 0},    // 0xFDA4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3412, 0},    // 0xFDA5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3413, 0},    // 0xFDA6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3414, 0},    // 0xFDA7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3415, 0},    // 0xFDA8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3416, 0},    // 0xFDA9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3417, 0},    // 0xFDAA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3418, 0},    // 0xFDAB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3419, 0},    // 0xFDAC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3420, 0},    // 0xFDAD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3421, 0},    // 0xFDAE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3422, 0},    // 0xFDAF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3423, 0},    // 0xFDB0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3424, 0},    // 0xFDB1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3425, 0},    // 0xFDB2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3426, 0},    // 0xFDB3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3427, 0},    // 0xFDB4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3428, 0},    // 0xFDB5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3429, 0},    // 0xFDB6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3430, 0},    // 0xFDB7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3431, 0},    // 0xFDB8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3432, 0},    // 0xFDB9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3433, 0},    // 0xFDBA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3434, 0},    // 0xFDBB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3435, 0},    // 0xFDBC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3436, 0},    // 0xFDBD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3437, 0},    // 0xFDBE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3438, 0},    // 0xFDBF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3439, 0},    // 0xFDC0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3440, 0},    // 0xFDC1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3441, 0},    // 0xFDC2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3442, 0},    // 0xFDC3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3443, 0},    // 0xFDC4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3444, 0},    // 0xFDC5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3445, 0},    // 0xFDC6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3446, 0},    // 0xFDC7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3447, 0},    // 0xFDF0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3448, 0},    // 0xFDF1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3449, 0},    // 0xFDF2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3450, 0},    // 0xFDF3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3451, 0},    // 0xFDF4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3452, 0},    // 0xFDF5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3453, 0},    // 0xFDF6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3454, 0},    // 0xFDF7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3455, 0},    // 0xFDF8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3456, 0},    // 0xFDF9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3457, 0},    // 0xFDFA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3458, 0},    // 0xFDFB
    {4, TINYUCD_GC_SC, 0, 0, 0, 0, 0, 3459, 0},    // 0xFDFC
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3460, 0},    // 0xFE10
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3461, 0},    // 0xFE11
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3462, 0},    // 0xFE12
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3463, 0},    // 0xFE13
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3464, 0},    // 0xFE14
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3465, 0},    // 0xFE15
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3466, 0},    // 0xFE16
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3467, 0},    // '︗'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3468, 0},    // '︘'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3469, 0},    // 0xFE19
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3470, 0},    // 0xFE30
    {4, TINYUCD_GC_PD, 0, 0, 0, 0, 0, 3471, 0},    // 0xFE31
    {4, TINYUCD_GC_PD, 0, 0, 0, 0, 0, 3472, 0},    // 0xFE32
    {4, TINYUCD_GC_PC, 0, 0, 0, 0, 0, 3473, 0},    // '︳'
    {4, TINYUCD_GC_PC, 0, 0, 0, 0, 0, 3474, 0},    // '︴'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3475, 0},    // '︵'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3476, 0},    // '︶'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3477, 0},    // '︷'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3478, 0},    // '︸'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3479, 0},    // '︹'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3480, 0},    // '︺'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3481, 0},    // '︻'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3482, 0},    // '︼'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3483, 0},    // '︽'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3484, 0},    // '︾'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3485, 0},    // '︿'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3486, 0},    // '﹀'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3487, 0},    // '﹁'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3488, 0},    // '﹂'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3489, 0},    // '﹃'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3490, 0},    // '﹄'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3491, 0},    // '﹇'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3492, 0},    // '﹈'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3493, 0},    // 0xFE49
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3494, 0},    // 0xFE4A
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3495, 0},    // 0xFE4B
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3496, 0},    // 0xFE4C
    {4, TINYUCD_GC_PC, 0, 0, 0, 0, 0, 3497, 0},    // '﹍'
    {4, TINYUCD_GC_PC, 0, 0, 0, 0, 0, 3498, 0},    // '﹎'
    {4, TINYUCD_GC_PC, 0, 0, 0, 0, 0, 3499, 0},    // '﹏'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3500, 0},    // 0xFE50
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3501, 0},    // 0xFE51
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3502, 0},    // 0xFE52
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3503, 0},    // 0xFE54
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3504, 0},    // 0xFE55
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3505, 0},    // 0xFE56
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3506, 0},    // 0xFE57
    {4, TINYUCD_GC_PD, 0, 0, 0, 0, 0, 3507, 0},    // 0xFE58
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3508, 0},    // '﹙'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3509, 0},    // '﹚'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3510, 0},    // '﹛'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3511, 0},    // '﹜'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3512, 0},    // '﹝'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3513, 0},    // '﹞'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3514, 0},    // 0xFE5F
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3515, 0},    // 0xFE60
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3516, 0},    // 0xFE61
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3517, 0},    // '﹢'
    {4, TINYUCD_GC_PD, 0, 0, 0, 0, 0, 3518, 0},    // 0xFE63
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3519, 0},    // '﹤'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3520, 0},    // '﹥'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3521, 0},    // '﹦'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3522, 0},    // 0xFE68
    {4, TINYUCD_GC_SC, 0, 0, 0, 0, 0, 3523, 0},    // 0xFE69
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3524, 0},    // 0xFE6A
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3525, 0},    // 0xFE6B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3526, 0},    // 0xFE70
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3527, 0},    // 0xFE71
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3528, 0},    // 0xFE72
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3529, 0},    // 0xFE74
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3530, 0},    // 0xFE76
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3531, 0},    // 0xFE77
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3532, 0},    // 0xFE78
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3533, 0},    // 0xFE79
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3534, 0},    // 0xFE7A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3535, 0},    // 0xFE7B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3536, 0},    // 0xFE7C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3537, 0},    // 0xFE7D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3538, 0},    // 0xFE7E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3539, 0},    // 0xFE7F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3540, 0},    // 0xFE80
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3541, 0},    // 0xFE81
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3542, 0},    // 0xFE82
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3543, 0},    // 0xFE83
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3544, 0},    // 0xFE84
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3545, 0},    // 0xFE85
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3546, 0},    // 0xFE86
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3547, 0},    // 0xFE87
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3548, 0},    // 0xFE88
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3549, 0},    // 0xFE89
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3550, 0},    // 0xFE8A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3551, 0},    // 0xFE8B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3552, 0},    // 0xFE8C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3553, 0},    // 0xFE8D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3554, 0},    // 0xFE8E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3555, 0},    // 0xFE8F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3556, 0},    // 0xFE90
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3557, 0},    // 0xFE91
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3558, 0},    // 0xFE92
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3559, 0},    // 0xFE93
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3560, 0},    // 0xFE94
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3561, 0},    // 0xFE95
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3562, 0},    // 0xFE96
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3563, 0},    // 0xFE97
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3564, 0},    // 0xFE98
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3565, 0},    // 0xFE99
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3566, 0},    // 0xFE9A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3567, 0},    // 0xFE9B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3568, 0},    // 0xFE9C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3569, 0},    // 0xFE9D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3570, 0},    // 0xFE9E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3571, 0},    // 0xFE9F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3572, 0},    // 0xFEA0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3573, 0},    // 0xFEA1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3574, 0},    // 0xFEA2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3575, 0},    // 0xFEA3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3576, 0},    // 0xFEA4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3577, 0},    // 0xFEA5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3578, 0},    // 0xFEA6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3579, 0},    // 0xFEA7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3580, 0},    // 0xFEA8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3581, 0},    // 0xFEA9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3582, 0},    // 0xFEAA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3583, 0},    // 0xFEAB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3584, 0},    // 0xFEAC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3585, 0},    // 0xFEAD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3586, 0},    // 0xFEAE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3587, 0},    // 0xFEAF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3588, 0},    // 0xFEB0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3589, 0},    // 0xFEB1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3590, 0},    // 0xFEB2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3591, 0},    // 0xFEB3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3592, 0},    // 0xFEB4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3593, 0},    // 0xFEB5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3594, 0},    // 0xFEB6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3595, 0},    // 0xFEB7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3596, 0},    // 0xFEB8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3597, 0},    // 0xFEB9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3598, 0},    // 0xFEBA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3599, 0},    // 0xFEBB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3600, 0},    // 0xFEBC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3601, 0},    // 0xFEBD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3602, 0},    // 0xFEBE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3603, 0},    // 0xFEBF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3604, 0},    // 0xFEC0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3605, 0},    // 0xFEC1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3606, 0},    // 0xFEC2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3607, 0},    // 0xFEC3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3608, 0},    // 0xFEC4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3609, 0},    // 0xFEC5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3610, 0},    // 0xFEC6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3611, 0},    // 0xFEC7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3612, 0},    // 0xFEC8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3613, 0},    // 0xFEC9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3614, 0},    // 0xFECA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3615, 0},    // 0xFECB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3616, 0},    // 0xFECC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3617, 0},    // 0xFECD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3618, 0},    // 0xFECE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3619, 0},    // 0xFECF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3620, 0},    // 0xFED0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3621, 0},    // 0xFED1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3622, 0},    // 0xFED2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3623, 0},    // 0xFED3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3624, 0},    // 0xFED4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3625, 0},    // 0xFED5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3626, 0},    // 0xFED6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3627, 0},    // 0xFED7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3628, 0},    // 0xFED8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3629, 0},    // 0xFED9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3630, 0},    // 0xFEDA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3631, 0},    // 0xFEDB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3632, 0},    // 0xFEDC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3633, 0},    // 0xFEDD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3634, 0},    // 0xFEDE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3635, 0},    // 0xFEDF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3636, 0},    // 0xFEE0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3637, 0},    // 0xFEE1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3638, 0},    // 0xFEE2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3639, 0},    // 0xFEE3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3640, 0},    // 0xFEE4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3641, 0},    // 0xFEE5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3642, 0},    // 0xFEE6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3643, 0},    // 0xFEE7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3644, 0},    // 0xFEE8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3645, 0},    // 0xFEE9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3646, 0},    // 0xFEEA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3647, 0},    // 0xFEEB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3648, 0},    // 0xFEEC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3649, 0},    // 0xFEED
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3650, 0},    // 0xFEEE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3651, 0},    // 0xFEEF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3652, 0},    // 0xFEF0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3653, 0},    // 0xFEF1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3654, 0},    // 0xFEF2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3655, 0},    // 0xFEF3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3656, 0},    // 0xFEF4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3657, 0},    // 0xFEF5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3658, 0},    // 0xFEF6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3659, 0},    // 0xFEF7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3660, 0},    // 0xFEF8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3661, 0},    // 0xFEF9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3662, 0},    // 0xFEFA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3663, 0},    // 0xFEFB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3664, 0},    // 0xFEFC
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3665, 0},    // 0xFF01
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3666, 0},    // 0xFF02
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3667, 0},    // 0xFF03
    {4, TINYUCD_GC_SC, 0, 0, 0, 0, 0, 3668, 0},    // 0xFF04
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3669, 0},    // 0xFF05
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3670, 0},    // 0xFF06
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3671, 0},    // 0xFF07
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3672, 0},    // '（'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3673, 0},    // '）'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3674, 0},    // 0xFF0A
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3675, 0},    // '＋'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3676, 0},    // 0xFF0C
    {4, TINYUCD_GC_PD, 0, 0, 0, 0, 0, 3677, 0},    // 0xFF0D
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3678, 0},    // 0xFF0E
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3679, 0},    // 0xFF0F
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 3680, 0},    // '０'
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 3681, 0},    // '１'
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 3682, 0},    // '２'
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 3683, 0},    // '３'
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 3684, 0},    // '４'
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 3685, 0},    // '５'
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 3686, 0},    // '６'
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 3687, 0},    // '７'
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 3688, 0},    // '８'
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 3689, 0},    // '９'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3690, 0},    // 0xFF1A
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3691, 0},    // 0xFF1B
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3692, 0},    // '＜'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3693, 0},    // '＝'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3694, 0},    // '＞'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3695, 0},    // 0xFF1F
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3696, 0},    // 0xFF20
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2372, 3697, 0}, // 'Ａ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2373, 3698, 0}, // 'Ｂ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2374, 3699, 0}, // 'Ｃ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2375, 3700, 0}, // 'Ｄ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2376, 3701, 0}, // 'Ｅ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2377, 3702, 0}, // 'Ｆ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2378, 3703, 0}, // 'Ｇ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2379, 3704, 0}, // 'Ｈ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2380, 3705, 0}, // 'Ｉ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2381, 3706, 0}, // 'Ｊ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2382, 3707, 0}, // 'Ｋ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2383, 3708, 0}, // 'Ｌ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2384, 3709, 0}, // 'Ｍ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2385, 3710, 0}, // 'Ｎ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2386, 3711, 0}, // 'Ｏ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2387, 3712, 0}, // 'Ｐ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2388, 3713, 0}, // 'Ｑ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2389, 3714, 0}, // 'Ｒ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2390, 3715, 0}, // 'Ｓ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2391, 3716, 0}, // 'Ｔ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2392, 3717, 0}, // 'Ｕ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2393, 3718, 0}, // 'Ｖ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2394, 3719, 0}, // 'Ｗ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2395, 3720, 0}, // 'Ｘ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2396, 3721, 0}, // 'Ｙ'
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 2397, 3722, 0}, // 'Ｚ'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3723, 0},    // '［'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3724, 0},    // 0xFF3C
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3725, 0},    // '］'
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 3726, 0},    // 0xFF3E
    {4, TINYUCD_GC_PC, 0, 0, 0, 0, 0, 3727, 0},    // '＿'
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 3728, 0},    // 0xFF40
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2398, 3729, 0}, // 'ａ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2399, 3730, 0}, // 'ｂ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2400, 3731, 0}, // 'ｃ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2401, 3732, 0}, // 'ｄ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2402, 3733, 0}, // 'ｅ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2403, 3734, 0}, // 'ｆ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2404, 3735, 0}, // 'ｇ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2405, 3736, 0}, // 'ｈ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2406, 3737, 0}, // 'ｉ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2407, 3738, 0}, // 'ｊ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2408, 3739, 0}, // 'ｋ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2409, 3740, 0}, // 'ｌ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2410, 3741, 0}, // 'ｍ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2411, 3742, 0}, // 'ｎ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2412, 3743, 0}, // 'ｏ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2413, 3744, 0}, // 'ｐ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2414, 3745, 0}, // 'ｑ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2415, 3746, 0}, // 'ｒ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2416, 3747, 0}, // 'ｓ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2417, 3748, 0}, // 'ｔ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2418, 3749, 0}, // 'ｕ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2419, 3750, 0}, // 'ｖ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2420, 3751, 0}, // 'ｗ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2421, 3752, 0}, // 'ｘ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2422, 3753, 0}, // 'ｙ'
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 2423, 3754, 0}, // 'ｚ'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3755, 0},    // '｛'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3756, 0},    // '｜'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3757, 0},    // '｝'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3758, 0},    // '～'
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3759, 0},    // '｟'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3760, 0},    // '｠'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3761, 0},    // 0xFF61
    {4, TINYUCD_GC_PS, 0, 0, 0, 0, 0, 3762, 0},    // '｢'
    {4, TINYUCD_GC_PE, 0, 0, 0, 0, 0, 3763, 0},    // '｣'
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3764, 0},    // 0xFF64
    {4, TINYUCD_GC_PO, 0, 0, 0, 0, 0, 3765, 0},    // 0xFF65
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3766, 0},    // 0xFF66
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3767, 0},    // 0xFF67
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3768, 0},    // 0xFF68
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3769, 0},    // 0xFF69
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3770, 0},    // 0xFF6A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3771, 0},    // 0xFF6B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3772, 0},    // 0xFF6C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3773, 0},    // 0xFF6D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3774, 0},    // 0xFF6E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3775, 0},    // 0xFF6F
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3776, 0},    // 'ｰ'
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3777, 0},    // 0xFF71
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3778, 0},    // 0xFF72
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3779, 0},    // 0xFF73
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3780, 0},    // 0xFF74
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3781, 0},    // 0xFF75
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3782, 0},    // 0xFF76
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3783, 0},    // 0xFF77
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3784, 0},    // 0xFF78
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3785, 0},    // 0xFF79
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3786, 0},    // 0xFF7A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3787, 0},    // 0xFF7B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3788, 0},    // 0xFF7C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3789, 0},    // 0xFF7D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3790, 0},    // 0xFF7E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3791, 0},    // 0xFF7F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3792, 0},    // 0xFF80
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3793, 0},    // 0xFF81
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3794, 0},    // 0xFF82
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3795, 0},    // 0xFF83
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3796, 0},    // 0xFF84
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3797, 0},    // 0xFF85
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3798, 0},    // 0xFF86
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3799, 0},    // 0xFF87
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3800, 0},    // 0xFF88
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3801, 0},    // 0xFF89
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3802, 0},    // 0xFF8A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3803, 0},    // 0xFF8B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3804, 0},    // 0xFF8C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3805, 0},    // 0xFF8D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3806, 0},    // 0xFF8E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3807, 0},    // 0xFF8F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3808, 0},    // 0xFF90
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3809, 0},    // 0xFF91
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3810, 0},    // 0xFF92
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3811, 0},    // 0xFF93
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3812, 0},    // 0xFF94
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3813, 0},    // 0xFF95
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3814, 0},    // 0xFF96
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3815, 0},    // 0xFF97
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3816, 0},    // 0xFF98
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3817, 0},    // 0xFF99
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3818, 0},    // 0xFF9A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3819, 0},    // 0xFF9B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3820, 0},    // 0xFF9C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3821, 0},    // 0xFF9D
    {4, TINYUCD_GC_LM, 0, 4, 2, 0, 0, 3822, 0},    // 'ﾞ'
    {4, TINYUCD_GC_LM, 0, 4, 2, 0, 0, 3823, 0},    // 'ﾟ'
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3824, 0},    // 0xFFA0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3825, 0},    // 0xFFA1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3826, 0},    // 0xFFA2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3827, 0},    // 0xFFA3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3828, 0},    // 0xFFA4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3829, 0},    // 0xFFA5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3830, 0},    // 0xFFA6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3831, 0},    // 0xFFA7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3832, 0},    // 0xFFA8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3833, 0},    // 0xFFA9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3834, 0},    // 0xFFAA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3835, 0},    // 0xFFAB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3836, 0},    // 0xFFAC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3837, 0},    // 0xFFAD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3838, 0},    // 0xFFAE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3839, 0},    // 0xFFAF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3840, 0},    // 0xFFB0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3841, 0},    // 0xFFB1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3842, 0},    // 0xFFB2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3843, 0},    // 0xFFB3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3844, 0},    // 0xFFB4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3845, 0},    // 0xFFB5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3846, 0},    // 0xFFB6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3847, 0},    // 0xFFB7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3848, 0},    // 0xFFB8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3849, 0},    // 0xFFB9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3850, 0},    // 0xFFBA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3851, 0},    // 0xFFBB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3852, 0},    // 0xFFBC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3853, 0},    // 0xFFBD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3854, 0},    // 0xFFBE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3855, 0},    // 0xFFC2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3856, 0},    // 0xFFC3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3857, 0},    // 0xFFC4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3858, 0},    // 0xFFC5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3859, 0},    // 0xFFC6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3860, 0},    // 0xFFC7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3861, 0},    // 0xFFCA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3862, 0},    // 0xFFCB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3863, 0},    // 0xFFCC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3864, 0},    // 0xFFCD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3865, 0},    // 0xFFCE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3866, 0},    // 0xFFCF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3867, 0},    // 0xFFD2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3868, 0},    // 0xFFD3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3869, 0},    // 0xFFD4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3870, 0},    // 0xFFD5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3871, 0},    // 0xFFD6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3872, 0},    // 0xFFD7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3873, 0},    // 0xFFDA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3874, 0},    // 0xFFDB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3875, 0},    // 0xFFDC
    {4, TINYUCD_GC_SC, 0, 0, 0, 0, 0, 3876, 0},    // 0xFFE0
    {4, TINYUCD_GC_SC, 0, 0, 0, 0, 0, 3877, 0},    // 0xFFE1
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3878, 0},    // '￢'
    {4, TINYUCD_GC_SK, 0, 0, 0, 0, 0, 3879, 0},    // 0xFFE3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3880, 0},    // 0xFFE4
    {4, TINYUCD_GC_SC, 0, 0, 0, 0, 0, 3881, 0},    // 0xFFE5
    {4, TINYUCD_GC_SC, 0, 0, 0, 0, 0, 3882, 0},    // 0xFFE6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3883, 0},    // 0xFFE8
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3884, 0},    // '￩'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3885, 0},    // '￪'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3886, 0},    // '￫'
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 3887, 0},    // '￬'
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3888, 0},    // 0xFFED
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3889, 0},    // 0xFFEE
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2424, 0, 0},    // 0x010400
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2425, 0, 0},    // 0x010401
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2426, 0, 0},    // 0x010402
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2427, 0, 0},    // 0x010403
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2428, 0, 0},    // 0x010404
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2429, 0, 0},    // 0x010405
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2430, 0, 0},    // 0x010406
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2431, 0, 0},    // 0x010407
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2432, 0, 0},    // 0x010408
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2433, 0, 0},    // 0x010409
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2434, 0, 0},    // 0x01040A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2435, 0, 0},    // 0x01040B
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2436, 0, 0},    // 0x01040C
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2437, 0, 0},    // 0x01040D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2438, 0, 0},    // 0x01040E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2439, 0, 0},    // 0x01040F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2440, 0, 0},    // 0x010410
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2441, 0, 0},    // 0x010411
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2442, 0, 0},    // 0x010412
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2443, 0, 0},    // 0x010413
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2444, 0, 0},    // 0x010414
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2445, 0, 0},    // 0x010415
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2446, 0, 0},    // 0x010416
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2447, 0, 0},    // 0x010417
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2448, 0, 0},    // 0x010418
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2449, 0, 0},    // 0x010419
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2450, 0, 0},    // 0x01041A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2451, 0, 0},    // 0x01041B
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2452, 0, 0},    // 0x01041C
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2453, 0, 0},    // 0x01041D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2454, 0, 0},    // 0x01041E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2455, 0, 0},    // 0x01041F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2456, 0, 0},    // 0x010420
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2457, 0, 0},    // 0x010421
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2458, 0, 0},    // 0x010422
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2459, 0, 0},    // 0x010423
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2460, 0, 0},    // 0x010424
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2461, 0, 0},    // 0x010425
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2462, 0, 0},    // 0x010426
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2463, 0, 0},    // 0x010427
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2464, 0, 0},    // 0x010428
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2465, 0, 0},    // 0x010429
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2466, 0, 0},    // 0x01042A
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2467, 0, 0},    // 0x01042B
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2468, 0, 0},    // 0x01042C
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2469, 0, 0},    // 0x01042D
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2470, 0, 0},    // 0x01042E
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2471, 0, 0},    // 0x01042F
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2472, 0, 0},    // 0x010430
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2473, 0, 0},    // 0x010431
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2474, 0, 0},    // 0x010432
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2475, 0, 0},    // 0x010433
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2476, 0, 0},    // 0x010434
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2477, 0, 0},    // 0x010435
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2478, 0, 0},    // 0x010436
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2479, 0, 0},    // 0x010437
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2480, 0, 0},    // 0x010438
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2481, 0, 0},    // 0x010439
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2482, 0, 0},    // 0x01043A
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2483, 0, 0},    // 0x01043B
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2484, 0, 0},    // 0x01043C
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2485, 0, 0},    // 0x01043D
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2486, 0, 0},    // 0x01043E
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2487, 0, 0},    // 0x01043F
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2488, 0, 0},    // 0x010440
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2489, 0, 0},    // 0x010441
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2490, 0, 0},    // 0x010442
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2491, 0, 0},    // 0x010443
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2492, 0, 0},    // 0x010444
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2493, 0, 0},    // 0x010445
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2494, 0, 0},    // 0x010446
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2495, 0, 0},    // 0x010447
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2496, 0, 0},    // 0x010448
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2497, 0, 0},    // 0x010449
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2498, 0, 0},    // 0x01044A
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2499, 0, 0},    // 0x01044B
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2500, 0, 0},    // 0x01044C
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2501, 0, 0},    // 0x01044D
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2502, 0, 0},    // 0x01044E
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2503, 0, 0},    // 0x01044F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2504, 0, 0},    // 0x0104B0
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2505, 0, 0},    // 0x0104B1
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2506, 0, 0},    // 0x0104B2
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2507, 0, 0},    // 0x0104B3
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2508, 0, 0},    // 0x0104B4
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2509, 0, 0},    // 0x0104B5
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2510, 0, 0},    // 0x0104B6
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2511, 0, 0},    // 0x0104B7
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2512, 0, 0},    // 0x0104B8
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2513, 0, 0},    // 0x0104B9
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2514, 0, 0},    // 0x0104BA
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2515, 0, 0},    // 0x0104BB
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2516, 0, 0},    // 0x0104BC
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2517, 0, 0},    // 0x0104BD
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2518, 0, 0},    // 0x0104BE
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2519, 0, 0},    // 0x0104BF
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2520, 0, 0},    // 0x0104C0
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2521, 0, 0},    // 0x0104C1
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2522, 0, 0},    // 0x0104C2
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2523, 0, 0},    // 0x0104C3
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2524, 0, 0},    // 0x0104C4
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2525, 0, 0},    // 0x0104C5
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2526, 0, 0},    // 0x0104C6
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2527, 0, 0},    // 0x0104C7
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2528, 0, 0},    // 0x0104C8
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2529, 0, 0},    // 0x0104C9
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2530, 0, 0},    // 0x0104CA
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2531, 0, 0},    // 0x0104CB
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2532, 0, 0},    // 0x0104CC
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2533, 0, 0},    // 0x0104CD
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2534, 0, 0},    // 0x0104CE
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2535, 0, 0},    // 0x0104CF
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2536, 0, 0},    // 0x0104D0
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2537, 0, 0},    // 0x0104D1
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2538, 0, 0},    // 0x0104D2
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2539, 0, 0},    // 0x0104D3
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2540, 0, 0},    // 0x0104D8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2541, 0, 0},    // 0x0104D9
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2542, 0, 0},    // 0x0104DA
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2543, 0, 0},    // 0x0104DB
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2544, 0, 0},    // 0x0104DC
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2545, 0, 0},    // 0x0104DD
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2546, 0, 0},    // 0x0104DE
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2547, 0, 0},    // 0x0104DF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2548, 0, 0},    // 0x0104E0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2549, 0, 0},    // 0x0104E1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2550, 0, 0},    // 0x0104E2
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2551, 0, 0},    // 0x0104E3
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2552, 0, 0},    // 0x0104E4
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2553, 0, 0},    // 0x0104E5
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2554, 0, 0},    // 0x0104E6
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2555, 0, 0},    // 0x0104E7
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2556, 0, 0},    // 0x0104E8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2557, 0, 0},    // 0x0104E9
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2558, 0, 0},    // 0x0104EA
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2559, 0, 0},    // 0x0104EB
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2560, 0, 0},    // 0x0104EC
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2561, 0, 0},    // 0x0104ED
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2562, 0, 0},    // 0x0104EE
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2563, 0, 0},    // 0x0104EF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2564, 0, 0},    // 0x0104F0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2565, 0, 0},    // 0x0104F1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2566, 0, 0},    // 0x0104F2
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2567, 0, 0},    // 0x0104F3
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2568, 0, 0},    // 0x0104F4
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2569, 0, 0},    // 0x0104F5
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2570, 0, 0},    // 0x0104F6
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2571, 0, 0},    // 0x0104F7
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2572, 0, 0},    // 0x0104F8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2573, 0, 0},    // 0x0104F9
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2574, 0, 0},    // 0x0104FA
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2575, 0, 0},    // 0x0104FB
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2576, 0, 0},    // 0x010570
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2577, 0, 0},    // 0x010571
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2578, 0, 0},    // 0x010572
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2579, 0, 0},    // 0x010573
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2580, 0, 0},    // 0x010574
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2581, 0, 0},    // 0x010575
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2582, 0, 0},    // 0x010576
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2583, 0, 0},    // 0x010577
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2584, 0, 0},    // 0x010578
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2585, 0, 0},    // 0x010579
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2586, 0, 0},    // 0x01057A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2587, 0, 0},    // 0x01057C
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2588, 0, 0},    // 0x01057D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2589, 0, 0},    // 0x01057E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2590, 0, 0},    // 0x01057F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2591, 0, 0},    // 0x010580
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2592, 0, 0},    // 0x010581
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2593, 0, 0},    // 0x010582
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2594, 0, 0},    // 0x010583
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2595, 0, 0},    // 0x010584
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2596, 0, 0},    // 0x010585
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2597, 0, 0},    // 0x010586
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2598, 0, 0},    // 0x010587
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2599, 0, 0},    // 0x010588
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2600, 0, 0},    // 0x010589
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2601, 0, 0},    // 0x01058A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2602, 0, 0},    // 0x01058C
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2603, 0, 0},    // 0x01058D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2604, 0, 0},    // 0x01058E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2605, 0, 0},    // 0x01058F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2606, 0, 0},    // 0x010590
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2607, 0, 0},    // 0x010591
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2608, 0, 0},    // 0x010592
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2609, 0, 0},    // 0x010594
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2610, 0, 0},    // 0x010595
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2611, 0, 0},    // 0x010597
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2612, 0, 0},    // 0x010598
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2613, 0, 0},    // 0x010599
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2614, 0, 0},    // 0x01059A
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2615, 0, 0},    // 0x01059B
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2616, 0, 0},    // 0x01059C
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2617, 0, 0},    // 0x01059D
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2618, 0, 0},    // 0x01059E
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2619, 0, 0},    // 0x01059F
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2620, 0, 0},    // 0x0105A0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2621, 0, 0},    // 0x0105A1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2622, 0, 0},    // 0x0105A3
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2623, 0, 0},    // 0x0105A4
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2624, 0, 0},    // 0x0105A5
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2625, 0, 0},    // 0x0105A6
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2626, 0, 0},    // 0x0105A7
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2627, 0, 0},    // 0x0105A8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2628, 0, 0},    // 0x0105A9
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2629, 0, 0},    // 0x0105AA
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2630, 0, 0},    // 0x0105AB
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2631, 0, 0},    // 0x0105AC
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2632, 0, 0},    // 0x0105AD
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2633, 0, 0},    // 0x0105AE
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2634, 0, 0},    // 0x0105AF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2635, 0, 0},    // 0x0105B0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2636, 0, 0},    // 0x0105B1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2637, 0, 0},    // 0x0105B3
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2638, 0, 0},    // 0x0105B4
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2639, 0, 0},    // 0x0105B5
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2640, 0, 0},    // 0x0105B6
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2641, 0, 0},    // 0x0105B7
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2642, 0, 0},    // 0x0105B8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2643, 0, 0},    // 0x0105B9
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2644, 0, 0},    // 0x0105BB
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2645, 0, 0},    // 0x0105BC
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3890, 0},    // 0x0105C9
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 368},     // 0x0105D2
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 369},     // 0x0105DA
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3891, 0},    // 0x0105E4
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3892, 0},    // 0x010781
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3893, 0},    // 0x010782
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3894, 0},    // 0x010783
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3895, 0},    // 0x010784
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3896, 0},    // 0x010785
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3897, 0},    // 0x010787
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3898, 0},    // 0x010788
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3899, 0},    // 0x010789
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3900, 0},    // 0x01078A
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3901, 0},    // 0x01078B
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3902, 0},    // 0x01078C
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3903, 0},    // 0x01078D
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3904, 0},    // 0x01078E
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3905, 0},    // 0x01078F
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3906, 0},    // 0x010790
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3907, 0},    // 0x010791
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3908, 0},    // 0x010792
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3909, 0},    // 0x010793
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3910, 0},    // 0x010794
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3911, 0},    // 0x010795
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3912, 0},    // 0x010796
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3913, 0},    // 0x010797
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3914, 0},    // 0x010798
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3915, 0},    // 0x010799
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3916, 0},    // 0x01079A
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3917, 0},    // 0x01079B
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3918, 0},    // 0x01079C
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3919, 0},    // 0x01079D
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3920, 0},    // 0x01079E
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3921, 0},    // 0x01079F
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3922, 0},    // 0x0107A0
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3923, 0},    // 0x0107A1
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3924, 0},    // 0x0107A2
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3925, 0},    // 0x0107A3
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3926, 0},    // 0x0107A4
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3927, 0},    // 0x0107A5
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3928, 0},    // 0x0107A6
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3929, 0},    // 0x0107A7
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3930, 0},    // 0x0107A8
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3931, 0},    // 0x0107A9
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3932, 0},    // 0x0107AA
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3933, 0},    // 0x0107AB
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3934, 0},    // 0x0107AC
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3935, 0},    // 0x0107AD
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3936, 0},    // 0x0107AE
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3937, 0},    // 0x0107AF
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3938, 0},    // 0x0107B0
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3939, 0},    // 0x0107B2
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3940, 0},    // 0x0107B3
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3941, 0},    // 0x0107B4
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3942, 0},    // 0x0107B5
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3943, 0},    // 0x0107B6
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3944, 0},    // 0x0107B7
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3945, 0},    // 0x0107B8
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3946, 0},    // 0x0107B9
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 3947, 0},    // 0x0107BA
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2646, 0, 0},    // 0x010C80
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2647, 0, 0},    // 0x010C81
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2648, 0, 0},    // 0x010C82
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2649, 0, 0},    // 0x010C83
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2650, 0, 0},    // 0x010C84
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2651, 0, 0},    // 0x010C85
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2652, 0, 0},    // 0x010C86
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2653, 0, 0},    // 0x010C87
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2654, 0, 0},    // 0x010C88
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2655, 0, 0},    // 0x010C89
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2656, 0, 0},    // 0x010C8A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2657, 0, 0},    // 0x010C8B
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2658, 0, 0},    // 0x010C8C
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2659, 0, 0},    // 0x010C8D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2660, 0, 0},    // 0x010C8E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2661, 0, 0},    // 0x010C8F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2662, 0, 0},    // 0x010C90
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2663, 0, 0},    // 0x010C91
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2664, 0, 0},    // 0x010C92
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2665, 0, 0},    // 0x010C93
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2666, 0, 0},    // 0x010C94
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2667, 0, 0},    // 0x010C95
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2668, 0, 0},    // 0x010C96
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2669, 0, 0},    // 0x010C97
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2670, 0, 0},    // 0x010C98
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2671, 0, 0},    // 0x010C99
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2672, 0, 0},    // 0x010C9A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2673, 0, 0},    // 0x010C9B
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2674, 0, 0},    // 0x010C9C
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2675, 0, 0},    // 0x010C9D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2676, 0, 0},    // 0x010C9E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2677, 0, 0},    // 0x010C9F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2678, 0, 0},    // 0x010CA0
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2679, 0, 0},    // 0x010CA1
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2680, 0, 0},    // 0x010CA2
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2681, 0, 0},    // 0x010CA3
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2682, 0, 0},    // 0x010CA4
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2683, 0, 0},    // 0x010CA5
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2684, 0, 0},    // 0x010CA6
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2685, 0, 0},    // 0x010CA7
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2686, 0, 0},    // 0x010CA8
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2687, 0, 0},    // 0x010CA9
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2688, 0, 0},    // 0x010CAA
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2689, 0, 0},    // 0x010CAB
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2690, 0, 0},    // 0x010CAC
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2691, 0, 0},    // 0x010CAD
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2692, 0, 0},    // 0x010CAE
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2693, 0, 0},    // 0x010CAF
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2694, 0, 0},    // 0x010CB0
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2695, 0, 0},    // 0x010CB1
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2696, 0, 0},    // 0x010CB2
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2697, 0, 0},    // 0x010CC0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2698, 0, 0},    // 0x010CC1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2699, 0, 0},    // 0x010CC2
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2700, 0, 0},    // 0x010CC3
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2701, 0, 0},    // 0x010CC4
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2702, 0, 0},    // 0x010CC5
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2703, 0, 0},    // 0x010CC6
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2704, 0, 0},    // 0x010CC7
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2705, 0, 0},    // 0x010CC8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2706, 0, 0},    // 0x010CC9
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2707, 0, 0},    // 0x010CCA
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2708, 0, 0},    // 0x010CCB
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2709, 0, 0},    // 0x010CCC
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2710, 0, 0},    // 0x010CCD
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2711, 0, 0},    // 0x010CCE
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2712, 0, 0},    // 0x010CCF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2713, 0, 0},    // 0x010CD0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2714, 0, 0},    // 0x010CD1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2715, 0, 0},    // 0x010CD2
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2716, 0, 0},    // 0x010CD3
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2717, 0, 0},    // 0x010CD4
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2718, 0, 0},    // 0x010CD5
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2719, 0, 0},    // 0x010CD6
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2720, 0, 0},    // 0x010CD7
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2721, 0, 0},    // 0x010CD8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2722, 0, 0},    // 0x010CD9
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2723, 0, 0},    // 0x010CDA
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2724, 0, 0},    // 0x010CDB
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2725, 0, 0},    // 0x010CDC
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2726, 0, 0},    // 0x010CDD
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2727, 0, 0},    // 0x010CDE
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2728, 0, 0},    // 0x010CDF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2729, 0, 0},    // 0x010CE0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2730, 0, 0},    // 0x010CE1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2731, 0, 0},    // 0x010CE2
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2732, 0, 0},    // 0x010CE3
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2733, 0, 0},    // 0x010CE4
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2734, 0, 0},    // 0x010CE5
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2735, 0, 0},    // 0x010CE6
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2736, 0, 0},    // 0x010CE7
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2737, 0, 0},    // 0x010CE8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2738, 0, 0},    // 0x010CE9
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2739, 0, 0},    // 0x010CEA
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2740, 0, 0},    // 0x010CEB
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2741, 0, 0},    // 0x010CEC
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2742, 0, 0},    // 0x010CED
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2743, 0, 0},    // 0x010CEE
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2744, 0, 0},    // 0x010CEF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2745, 0, 0},    // 0x010CF0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2746, 0, 0},    // 0x010CF1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2747, 0, 0},    // 0x010CF2
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2748, 0, 0},    // 0x010D50
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2749, 0, 0},    // 0x010D51
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2750, 0, 0},    // 0x010D52
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2751, 0, 0},    // 0x010D53
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2752, 0, 0},    // 0x010D54
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2753, 0, 0},    // 0x010D55
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2754, 0, 0},    // 0x010D56
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2755, 0, 0},    // 0x010D57
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2756, 0, 0},    // 0x010D58
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2757, 0, 0},    // 0x010D59
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2758, 0, 0},    // 0x010D5A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2759, 0, 0},    // 0x010D5B
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2760, 0, 0},    // 0x010D5C
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2761, 0, 0},    // 0x010D5D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2762, 0, 0},    // 0x010D5E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2763, 0, 0},    // 0x010D5F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2764, 0, 0},    // 0x010D60
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2765, 0, 0},    // 0x010D61
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2766, 0, 0},    // 0x010D62
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2767, 0, 0},    // 0x010D63
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2768, 0, 0},    // 0x010D64
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2769, 0, 0},    // 0x010D65
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2770, 0, 0},    // 0x010D70
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2771, 0, 0},    // 0x010D71
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2772, 0, 0},    // 0x010D72
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2773, 0, 0},    // 0x010D73
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2774, 0, 0},    // 0x010D74
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2775, 0, 0},    // 0x010D75
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2776, 0, 0},    // 0x010D76
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2777, 0, 0},    // 0x010D77
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2778, 0, 0},    // 0x010D78
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2779, 0, 0},    // 0x010D79
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2780, 0, 0},    // 0x010D7A
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2781, 0, 0},    // 0x010D7B
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2782, 0, 0},    // 0x010D7C
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2783, 0, 0},    // 0x010D7D
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2784, 0, 0},    // 0x010D7E
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2785, 0, 0},    // 0x010D7F
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2786, 0, 0},    // 0x010D80
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2787, 0, 0},    // 0x010D81
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2788, 0, 0},    // 0x010D82
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2789, 0, 0},    // 0x010D83
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2790, 0, 0},    // 0x010D84
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2791, 0, 0},    // 0x010D85
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 370},     // 0x011099
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3948, 0},    // 0x01109A
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 371},     // 0x01109B
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3949, 0},    // 0x01109C
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 0, 372},     // 0x0110A5
    {0, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 3950, 0},    // 0x0110AB
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 3951, 0},    // 0x01112E
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 3952, 0},    // 0x01112F
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 373},     // 0x011131
    {0, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 374},     // 0x011132
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 375},     // 0x011347
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 3953, 0},    // 0x01134B
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 3954, 0},    // 0x01134C
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 0, 376},     // 0x011382
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 3955, 0},    // 0x011383
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 0, 377},     // 0x011384
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 3956, 0},    // 0x011385
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 0, 378},     // 0x01138B
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 3957, 0},    // 0x01138E
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 0, 379},     // 0x011390
    {0, TINYUCD_GC_LO, 0, 0, 1, 0, 0, 3958, 0},    // 0x011391
    {2, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 0, 380},     // 0x0113C2
    {2, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 3959, 0},    // 0x0113C5
    {2, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 3960, 0},    // 0x0113C7
    {2, TINYUCD_GC_MC, 0, 4, 2, 0, 0, 3961, 0},    // 0x0113C8
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 381},     // 0x0114B9
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 3962, 0},    // 0x0114BB
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 3963, 0},    // 0x0114BC
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 3964, 0},    // 0x0114BE
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 382},     // 0x0115B8
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 383},     // 0x0115B9
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 3965, 0},    // 0x0115BA
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 3966, 0},    // 0x0115BB
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2792, 0, 0},    // 0x0118A0
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2793, 0, 0},    // 0x0118A1
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2794, 0, 0},    // 0x0118A2
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2795, 0, 0},    // 0x0118A3
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2796, 0, 0},    // 0x0118A4
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2797, 0, 0},    // 0x0118A5
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2798, 0, 0},    // 0x0118A6
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2799, 0, 0},    // 0x0118A7
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2800, 0, 0},    // 0x0118A8
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2801, 0, 0},    // 0x0118A9
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2802, 0, 0},    // 0x0118AA
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2803, 0, 0},    // 0x0118AB
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2804, 0, 0},    // 0x0118AC
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2805, 0, 0},    // 0x0118AD
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2806, 0, 0},    // 0x0118AE
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2807, 0, 0},    // 0x0118AF
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2808, 0, 0},    // 0x0118B0
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2809, 0, 0},    // 0x0118B1
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2810, 0, 0},    // 0x0118B2
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2811, 0, 0},    // 0x0118B3
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2812, 0, 0},    // 0x0118B4
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2813, 0, 0},    // 0x0118B5
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2814, 0, 0},    // 0x0118B6
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2815, 0, 0},    // 0x0118B7
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2816, 0, 0},    // 0x0118B8
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2817, 0, 0},    // 0x0118B9
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2818, 0, 0},    // 0x0118BA
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2819, 0, 0},    // 0x0118BB
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2820, 0, 0},    // 0x0118BC
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2821, 0, 0},    // 0x0118BD
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2822, 0, 0},    // 0x0118BE
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2823, 0, 0},    // 0x0118BF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2824, 0, 0},    // 0x0118C0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2825, 0, 0},    // 0x0118C1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2826, 0, 0},    // 0x0118C2
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2827, 0, 0},    // 0x0118C3
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2828, 0, 0},    // 0x0118C4
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2829, 0, 0},    // 0x0118C5
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2830, 0, 0},    // 0x0118C6
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2831, 0, 0},    // 0x0118C7
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2832, 0, 0},    // 0x0118C8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2833, 0, 0},    // 0x0118C9
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2834, 0, 0},    // 0x0118CA
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2835, 0, 0},    // 0x0118CB
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2836, 0, 0},    // 0x0118CC
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2837, 0, 0},    // 0x0118CD
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2838, 0, 0},    // 0x0118CE
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2839, 0, 0},    // 0x0118CF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2840, 0, 0},    // 0x0118D0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2841, 0, 0},    // 0x0118D1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2842, 0, 0},    // 0x0118D2
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2843, 0, 0},    // 0x0118D3
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2844, 0, 0},    // 0x0118D4
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2845, 0, 0},    // 0x0118D5
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2846, 0, 0},    // 0x0118D6
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2847, 0, 0},    // 0x0118D7
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2848, 0, 0},    // 0x0118D8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2849, 0, 0},    // 0x0118D9
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2850, 0, 0},    // 0x0118DA
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2851, 0, 0},    // 0x0118DB
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2852, 0, 0},    // 0x0118DC
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2853, 0, 0},    // 0x0118DD
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2854, 0, 0},    // 0x0118DE
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2855, 0, 0},    // 0x0118DF
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 0, 384},     // 0x011935
    {0, TINYUCD_GC_MC, 0, 8, 0, 0, 0, 3967, 0},    // 0x011938
    {2, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 385},     // 0x01611E
    {2, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 3968, 386},  // 0x016121
    {2, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 3969, 387},  // 0x016122
    {2, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 3970, 0},    // 0x016123
    {2, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 3971, 0},    // 0x016124
    {2, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 3972, 0},    // 0x016125
    {2, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 3973, 0},    // 0x016126
    {2, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 3974, 0},    // 0x016127
    {2, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 3975, 0},    // 0x016128
    {2, TINYUCD_GC_MN, 0, 4, 2, 0, 0, 0, 388},     // 0x016129
    {0, TINYUCD_GC_LO, 0, 10, 0, 0, 0, 0, 389},    // 0x016D63
    {2, TINYUCD_GC_LO, 0, 10, 0, 0, 0, 0, 390},    // 0x016D67
    {2, TINYUCD_GC_LO, 0, 10, 0, 0, 0, 3976, 0},   // 0x016D68
    {0, TINYUCD_GC_LO, 0, 10, 0, 0, 0, 3977, 391}, // 0x016D69
    {0, TINYUCD_GC_LO, 0, 10, 0, 0, 0, 3978, 0},   // 0x016D6A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2856, 0, 0},    // 0x016E40
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2857, 0, 0},    // 0x016E41
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2858, 0, 0},    // 0x016E42
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2859, 0, 0},    // 0x016E43
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2860, 0, 0},    // 0x016E44
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2861, 0, 0},    // 0x016E45
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2862, 0, 0},    // 0x016E46
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2863, 0, 0},    // 0x016E47
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2864, 0, 0},    // 0x016E48
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2865, 0, 0},    // 0x016E49
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2866, 0, 0},    // 0x016E4A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2867, 0, 0},    // 0x016E4B
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2868, 0, 0},    // 0x016E4C
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2869, 0, 0},    // 0x016E4D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2870, 0, 0},    // 0x016E4E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2871, 0, 0},    // 0x016E4F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2872, 0, 0},    // 0x016E50
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2873, 0, 0},    // 0x016E51
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2874, 0, 0},    // 0x016E52
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2875, 0, 0},    // 0x016E53
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2876, 0, 0},    // 0x016E54
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2877, 0, 0},    // 0x016E55
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2878, 0, 0},    // 0x016E56
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2879, 0, 0},    // 0x016E57
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2880, 0, 0},    // 0x016E58
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2881, 0, 0},    // 0x016E59
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2882, 0, 0},    // 0x016E5A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2883, 0, 0},    // 0x016E5B
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2884, 0, 0},    // 0x016E5C
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2885, 0, 0},    // 0x016E5D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2886, 0, 0},    // 0x016E5E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2887, 0, 0},    // 0x016E5F
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2888, 0, 0},    // 0x016E60
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2889, 0, 0},    // 0x016E61
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2890, 0, 0},    // 0x016E62
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2891, 0, 0},    // 0x016E63
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2892, 0, 0},    // 0x016E64
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2893, 0, 0},    // 0x016E65
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2894, 0, 0},    // 0x016E66
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2895, 0, 0},    // 0x016E67
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2896, 0, 0},    // 0x016E68
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2897, 0, 0},    // 0x016E69
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2898, 0, 0},    // 0x016E6A
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2899, 0, 0},    // 0x016E6B
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2900, 0, 0},    // 0x016E6C
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2901, 0, 0},    // 0x016E6D
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2902, 0, 0},    // 0x016E6E
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2903, 0, 0},    // 0x016E6F
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2904, 0, 0},    // 0x016E70
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2905, 0, 0},    // 0x016E71
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2906, 0, 0},    // 0x016E72
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2907, 0, 0},    // 0x016E73
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2908, 0, 0},    // 0x016E74
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2909, 0, 0},    // 0x016E75
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2910, 0, 0},    // 0x016E76
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2911, 0, 0},    // 0x016E77
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2912, 0, 0},    // 0x016E78
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2913, 0, 0},    // 0x016E79
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2914, 0, 0},    // 0x016E7A
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2915, 0, 0},    // 0x016E7B
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2916, 0, 0},    // 0x016E7C
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2917, 0, 0},    // 0x016E7D
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2918, 0, 0},    // 0x016E7E
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2919, 0, 0},    // 0x016E7F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2920, 0, 0},    // 0x016EA0
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2921, 0, 0},    // 0x016EA1
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2922, 0, 0},    // 0x016EA2
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2923, 0, 0},    // 0x016EA3
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2924, 0, 0},    // 0x016EA4
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2925, 0, 0},    // 0x016EA5
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2926, 0, 0},    // 0x016EA6
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2927, 0, 0},    // 0x016EA7
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2928, 0, 0},    // 0x016EA8
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2929, 0, 0},    // 0x016EA9
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2930, 0, 0},    // 0x016EAA
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2931, 0, 0},    // 0x016EAB
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2932, 0, 0},    // 0x016EAC
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2933, 0, 0},    // 0x016EAD
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2934, 0, 0},    // 0x016EAE
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2935, 0, 0},    // 0x016EAF
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2936, 0, 0},    // 0x016EB0
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2937, 0, 0},    // 0x016EB1
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2938, 0, 0},    // 0x016EB2
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2939, 0, 0},    // 0x016EB3
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2940, 0, 0},    // 0x016EB4
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2941, 0, 0},    // 0x016EB5
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2942, 0, 0},    // 0x016EB6
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2943, 0, 0},    // 0x016EB7
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2944, 0, 0},    // 0x016EB8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2945, 0, 0},    // 0x016EBB
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2946, 0, 0},    // 0x016EBC
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2947, 0, 0},    // 0x016EBD
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2948, 0, 0},    // 0x016EBE
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2949, 0, 0},    // 0x016EBF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2950, 0, 0},    // 0x016EC0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2951, 0, 0},    // 0x016EC1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2952, 0, 0},    // 0x016EC2
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2953, 0, 0},    // 0x016EC3
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2954, 0, 0},    // 0x016EC4
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2955, 0, 0},    // 0x016EC5
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2956, 0, 0},    // 0x016EC6
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2957, 0, 0},    // 0x016EC7
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2958, 0, 0},    // 0x016EC8
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2959, 0, 0},    // 0x016EC9
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2960, 0, 0},    // 0x016ECA
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2961, 0, 0},    // 0x016ECB
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2962, 0, 0},    // 0x016ECC
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2963, 0, 0},    // 0x016ECD
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2964, 0, 0},    // 0x016ECE
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2965, 0, 0},    // 0x016ECF
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2966, 0, 0},    // 0x016ED0
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2967, 0, 0},    // 0x016ED1
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2968, 0, 0},    // 0x016ED2
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 2969, 0, 0},    // 0x016ED3
    {0, TINYUCD_GC_MC, 6, 4, 2, 0, 0, 0, 0},       // 2 codepoints in range [0x016FF0, 0x016FF1]
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3979, 0},    // 0x01CCD6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3980, 0},    // 0x01CCD7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3981, 0},    // 0x01CCD8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3982, 0},    // 0x01CCD9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3983, 0},    // 0x01CCDA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3984, 0},    // 0x01CCDB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3985, 0},    // 0x01CCDC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3986, 0},    // 0x01CCDD
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3987, 0},    // 0x01CCDE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3988, 0},    // 0x01CCDF
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3989, 0},    // 0x01CCE0
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3990, 0},    // 0x01CCE1
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3991, 0},    // 0x01CCE2
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3992, 0},    // 0x01CCE3
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3993, 0},    // 0x01CCE4
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3994, 0},    // 0x01CCE5
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3995, 0},    // 0x01CCE6
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3996, 0},    // 0x01CCE7
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3997, 0},    // 0x01CCE8
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3998, 0},    // 0x01CCE9
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 3999, 0},    // 0x01CCEA
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4000, 0},    // 0x01CCEB
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4001, 0},    // 0x01CCEC
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4002, 0},    // 0x01CCED
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4003, 0},    // 0x01CCEE
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4004, 0},    // 0x01CCEF
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4005, 0},    // 0x01CCF0
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4006, 0},    // 0x01CCF1
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4007, 0},    // 0x01CCF2
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4008, 0},    // 0x01CCF3
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4009, 0},    // 0x01CCF4
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4010, 0},    // 0x01CCF5
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4011, 0},    // 0x01CCF6
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4012, 0},    // 0x01CCF7
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4013, 0},    // 0x01CCF8
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4014, 0},    // 0x01CCF9
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4015, 0},    // 0x01D15E
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4016, 0},    // 0x01D15F
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4017, 0},    // 0x01D160
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4018, 0},    // 0x01D161
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4019, 0},    // 0x01D162
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4020, 0},    // 0x01D163
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4021, 0},    // 0x01D164
    {0, TINYUCD_GC_MC, 216, 4, 2, 0, 0, 0, 0},     // 7 codepoints in range [0x01D165, 0x01D172]
    {0, TINYUCD_GC_MC, 226, 4, 2, 0, 0, 0, 0},     // 0x01D16D
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4022, 0},    // 0x01D1BB
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4023, 0},    // 0x01D1BC
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4024, 0},    // 0x01D1BD
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4025, 0},    // 0x01D1BE
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4026, 0},    // 0x01D1BF
    {5, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 4027, 0},    // 0x01D1C0
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4028, 0},    // 0x01D400
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4029, 0},    // 0x01D401
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4030, 0},    // 0x01D402
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4031, 0},    // 0x01D403
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4032, 0},    // 0x01D404
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4033, 0},    // 0x01D405
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4034, 0},    // 0x01D406
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4035, 0},    // 0x01D407
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4036, 0},    // 0x01D408
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4037, 0},    // 0x01D409
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4038, 0},    // 0x01D40A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4039, 0},    // 0x01D40B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4040, 0},    // 0x01D40C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4041, 0},    // 0x01D40D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4042, 0},    // 0x01D40E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4043, 0},    // 0x01D40F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4044, 0},    // 0x01D410
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4045, 0},    // 0x01D411
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4046, 0},    // 0x01D412
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4047, 0},    // 0x01D413
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4048, 0},    // 0x01D414
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4049, 0},    // 0x01D415
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4050, 0},    // 0x01D416
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4051, 0},    // 0x01D417
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4052, 0},    // 0x01D418
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4053, 0},    // 0x01D419
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4054, 0},    // 0x01D41A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4055, 0},    // 0x01D41B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4056, 0},    // 0x01D41C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4057, 0},    // 0x01D41D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4058, 0},    // 0x01D41E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4059, 0},    // 0x01D41F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4060, 0},    // 0x01D420
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4061, 0},    // 0x01D421
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4062, 0},    // 0x01D422
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4063, 0},    // 0x01D423
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4064, 0},    // 0x01D424
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4065, 0},    // 0x01D425
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4066, 0},    // 0x01D426
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4067, 0},    // 0x01D427
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4068, 0},    // 0x01D428
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4069, 0},    // 0x01D429
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4070, 0},    // 0x01D42A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4071, 0},    // 0x01D42B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4072, 0},    // 0x01D42C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4073, 0},    // 0x01D42D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4074, 0},    // 0x01D42E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4075, 0},    // 0x01D42F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4076, 0},    // 0x01D430
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4077, 0},    // 0x01D431
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4078, 0},    // 0x01D432
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4079, 0},    // 0x01D433
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4080, 0},    // 0x01D434
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4081, 0},    // 0x01D435
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4082, 0},    // 0x01D436
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4083, 0},    // 0x01D437
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4084, 0},    // 0x01D438
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4085, 0},    // 0x01D439
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4086, 0},    // 0x01D43A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4087, 0},    // 0x01D43B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4088, 0},    // 0x01D43C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4089, 0},    // 0x01D43D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4090, 0},    // 0x01D43E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4091, 0},    // 0x01D43F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4092, 0},    // 0x01D440
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4093, 0},    // 0x01D441
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4094, 0},    // 0x01D442
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4095, 0},    // 0x01D443
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4096, 0},    // 0x01D444
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4097, 0},    // 0x01D445
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4098, 0},    // 0x01D446
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4099, 0},    // 0x01D447
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4100, 0},    // 0x01D448
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4101, 0},    // 0x01D449
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4102, 0},    // 0x01D44A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4103, 0},    // 0x01D44B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4104, 0},    // 0x01D44C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4105, 0},    // 0x01D44D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4106, 0},    // 0x01D44E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4107, 0},    // 0x01D44F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4108, 0},    // 0x01D450
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4109, 0},    // 0x01D451
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4110, 0},    // 0x01D452
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4111, 0},    // 0x01D453
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4112, 0},    // 0x01D454
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4113, 0},    // 0x01D456
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4114, 0},    // 0x01D457
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4115, 0},    // 0x01D458
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4116, 0},    // 0x01D459
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4117, 0},    // 0x01D45A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4118, 0},    // 0x01D45B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4119, 0},    // 0x01D45C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4120, 0},    // 0x01D45D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4121, 0},    // 0x01D45E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4122, 0},    // 0x01D45F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4123, 0},    // 0x01D460
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4124, 0},    // 0x01D461
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4125, 0},    // 0x01D462
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4126, 0},    // 0x01D463
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4127, 0},    // 0x01D464
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4128, 0},    // 0x01D465
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4129, 0},    // 0x01D466
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4130, 0},    // 0x01D467
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4131, 0},    // 0x01D468
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4132, 0},    // 0x01D469
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4133, 0},    // 0x01D46A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4134, 0},    // 0x01D46B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4135, 0},    // 0x01D46C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4136, 0},    // 0x01D46D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4137, 0},    // 0x01D46E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4138, 0},    // 0x01D46F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4139, 0},    // 0x01D470
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4140, 0},    // 0x01D471
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4141, 0},    // 0x01D472
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4142, 0},    // 0x01D473
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4143, 0},    // 0x01D474
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4144, 0},    // 0x01D475
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4145, 0},    // 0x01D476
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4146, 0},    // 0x01D477
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4147, 0},    // 0x01D478
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4148, 0},    // 0x01D479
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4149, 0},    // 0x01D47A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4150, 0},    // 0x01D47B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4151, 0},    // 0x01D47C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4152, 0},    // 0x01D47D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4153, 0},    // 0x01D47E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4154, 0},    // 0x01D47F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4155, 0},    // 0x01D480
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4156, 0},    // 0x01D481
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4157, 0},    // 0x01D482
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4158, 0},    // 0x01D483
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4159, 0},    // 0x01D484
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4160, 0},    // 0x01D485
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4161, 0},    // 0x01D486
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4162, 0},    // 0x01D487
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4163, 0},    // 0x01D488
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4164, 0},    // 0x01D489
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4165, 0},    // 0x01D48A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4166, 0},    // 0x01D48B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4167, 0},    // 0x01D48C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4168, 0},    // 0x01D48D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4169, 0},    // 0x01D48E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4170, 0},    // 0x01D48F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4171, 0},    // 0x01D490
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4172, 0},    // 0x01D491
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4173, 0},    // 0x01D492
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4174, 0},    // 0x01D493
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4175, 0},    // 0x01D494
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4176, 0},    // 0x01D495
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4177, 0},    // 0x01D496
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4178, 0},    // 0x01D497
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4179, 0},    // 0x01D498
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4180, 0},    // 0x01D499
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4181, 0},    // 0x01D49A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4182, 0},    // 0x01D49B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4183, 0},    // 0x01D49C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4184, 0},    // 0x01D49E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4185, 0},    // 0x01D49F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4186, 0},    // 0x01D4A2
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4187, 0},    // 0x01D4A5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4188, 0},    // 0x01D4A6
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4189, 0},    // 0x01D4A9
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4190, 0},    // 0x01D4AA
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4191, 0},    // 0x01D4AB
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4192, 0},    // 0x01D4AC
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4193, 0},    // 0x01D4AE
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4194, 0},    // 0x01D4AF
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4195, 0},    // 0x01D4B0
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4196, 0},    // 0x01D4B1
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4197, 0},    // 0x01D4B2
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4198, 0},    // 0x01D4B3
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4199, 0},    // 0x01D4B4
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4200, 0},    // 0x01D4B5
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4201, 0},    // 0x01D4B6
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4202, 0},    // 0x01D4B7
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4203, 0},    // 0x01D4B8
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4204, 0},    // 0x01D4B9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4205, 0},    // 0x01D4BB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4206, 0},    // 0x01D4BD
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4207, 0},    // 0x01D4BE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4208, 0},    // 0x01D4BF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4209, 0},    // 0x01D4C0
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4210, 0},    // 0x01D4C1
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4211, 0},    // 0x01D4C2
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4212, 0},    // 0x01D4C3
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4213, 0},    // 0x01D4C5
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4214, 0},    // 0x01D4C6
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4215, 0},    // 0x01D4C7
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4216, 0},    // 0x01D4C8
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4217, 0},    // 0x01D4C9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4218, 0},    // 0x01D4CA
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4219, 0},    // 0x01D4CB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4220, 0},    // 0x01D4CC
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4221, 0},    // 0x01D4CD
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4222, 0},    // 0x01D4CE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4223, 0},    // 0x01D4CF
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4224, 0},    // 0x01D4D0
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4225, 0},    // 0x01D4D1
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4226, 0},    // 0x01D4D2
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4227, 0},    // 0x01D4D3
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4228, 0},    // 0x01D4D4
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4229, 0},    // 0x01D4D5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4230, 0},    // 0x01D4D6
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4231, 0},    // 0x01D4D7
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4232, 0},    // 0x01D4D8
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4233, 0},    // 0x01D4D9
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4234, 0},    // 0x01D4DA
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4235, 0},    // 0x01D4DB
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4236, 0},    // 0x01D4DC
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4237, 0},    // 0x01D4DD
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4238, 0},    // 0x01D4DE
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4239, 0},    // 0x01D4DF
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4240, 0},    // 0x01D4E0
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4241, 0},    // 0x01D4E1
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4242, 0},    // 0x01D4E2
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4243, 0},    // 0x01D4E3
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4244, 0},    // 0x01D4E4
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4245, 0},    // 0x01D4E5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4246, 0},    // 0x01D4E6
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4247, 0},    // 0x01D4E7
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4248, 0},    // 0x01D4E8
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4249, 0},    // 0x01D4E9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4250, 0},    // 0x01D4EA
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4251, 0},    // 0x01D4EB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4252, 0},    // 0x01D4EC
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4253, 0},    // 0x01D4ED
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4254, 0},    // 0x01D4EE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4255, 0},    // 0x01D4EF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4256, 0},    // 0x01D4F0
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4257, 0},    // 0x01D4F1
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4258, 0},    // 0x01D4F2
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4259, 0},    // 0x01D4F3
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4260, 0},    // 0x01D4F4
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4261, 0},    // 0x01D4F5
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4262, 0},    // 0x01D4F6
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4263, 0},    // 0x01D4F7
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4264, 0},    // 0x01D4F8
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4265, 0},    // 0x01D4F9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4266, 0},    // 0x01D4FA
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4267, 0},    // 0x01D4FB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4268, 0},    // 0x01D4FC
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4269, 0},    // 0x01D4FD
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4270, 0},    // 0x01D4FE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4271, 0},    // 0x01D4FF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4272, 0},    // 0x01D500
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4273, 0},    // 0x01D501
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4274, 0},    // 0x01D502
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4275, 0},    // 0x01D503
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4276, 0},    // 0x01D504
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4277, 0},    // 0x01D505
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4278, 0},    // 0x01D507
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4279, 0},    // 0x01D508
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4280, 0},    // 0x01D509
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4281, 0},    // 0x01D50A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4282, 0},    // 0x01D50D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4283, 0},    // 0x01D50E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4284, 0},    // 0x01D50F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4285, 0},    // 0x01D510
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4286, 0},    // 0x01D511
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4287, 0},    // 0x01D512
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4288, 0},    // 0x01D513
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4289, 0},    // 0x01D514
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4290, 0},    // 0x01D516
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4291, 0},    // 0x01D517
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4292, 0},    // 0x01D518
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4293, 0},    // 0x01D519
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4294, 0},    // 0x01D51A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4295, 0},    // 0x01D51B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4296, 0},    // 0x01D51C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4297, 0},    // 0x01D51E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4298, 0},    // 0x01D51F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4299, 0},    // 0x01D520
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4300, 0},    // 0x01D521
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4301, 0},    // 0x01D522
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4302, 0},    // 0x01D523
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4303, 0},    // 0x01D524
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4304, 0},    // 0x01D525
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4305, 0},    // 0x01D526
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4306, 0},    // 0x01D527
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4307, 0},    // 0x01D528
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4308, 0},    // 0x01D529
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4309, 0},    // 0x01D52A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4310, 0},    // 0x01D52B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4311, 0},    // 0x01D52C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4312, 0},    // 0x01D52D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4313, 0},    // 0x01D52E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4314, 0},    // 0x01D52F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4315, 0},    // 0x01D530
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4316, 0},    // 0x01D531
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4317, 0},    // 0x01D532
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4318, 0},    // 0x01D533
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4319, 0},    // 0x01D534
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4320, 0},    // 0x01D535
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4321, 0},    // 0x01D536
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4322, 0},    // 0x01D537
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4323, 0},    // 0x01D538
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4324, 0},    // 0x01D539
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4325, 0},    // 0x01D53B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4326, 0},    // 0x01D53C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4327, 0},    // 0x01D53D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4328, 0},    // 0x01D53E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4329, 0},    // 0x01D540
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4330, 0},    // 0x01D541
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4331, 0},    // 0x01D542
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4332, 0},    // 0x01D543
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4333, 0},    // 0x01D544
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4334, 0},    // 0x01D546
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4335, 0},    // 0x01D54A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4336, 0},    // 0x01D54B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4337, 0},    // 0x01D54C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4338, 0},    // 0x01D54D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4339, 0},    // 0x01D54E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4340, 0},    // 0x01D54F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4341, 0},    // 0x01D550
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4342, 0},    // 0x01D552
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4343, 0},    // 0x01D553
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4344, 0},    // 0x01D554
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4345, 0},    // 0x01D555
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4346, 0},    // 0x01D556
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4347, 0},    // 0x01D557
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4348, 0},    // 0x01D558
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4349, 0},    // 0x01D559
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4350, 0},    // 0x01D55A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4351, 0},    // 0x01D55B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4352, 0},    // 0x01D55C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4353, 0},    // 0x01D55D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4354, 0},    // 0x01D55E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4355, 0},    // 0x01D55F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4356, 0},    // 0x01D560
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4357, 0},    // 0x01D561
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4358, 0},    // 0x01D562
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4359, 0},    // 0x01D563
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4360, 0},    // 0x01D564
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4361, 0},    // 0x01D565
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4362, 0},    // 0x01D566
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4363, 0},    // 0x01D567
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4364, 0},    // 0x01D568
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4365, 0},    // 0x01D569
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4366, 0},    // 0x01D56A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4367, 0},    // 0x01D56B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4368, 0},    // 0x01D56C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4369, 0},    // 0x01D56D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4370, 0},    // 0x01D56E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4371, 0},    // 0x01D56F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4372, 0},    // 0x01D570
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4373, 0},    // 0x01D571
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4374, 0},    // 0x01D572
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4375, 0},    // 0x01D573
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4376, 0},    // 0x01D574
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4377, 0},    // 0x01D575
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4378, 0},    // 0x01D576
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4379, 0},    // 0x01D577
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4380, 0},    // 0x01D578
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4381, 0},    // 0x01D579
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4382, 0},    // 0x01D57A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4383, 0},    // 0x01D57B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4384, 0},    // 0x01D57C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4385, 0},    // 0x01D57D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4386, 0},    // 0x01D57E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4387, 0},    // 0x01D57F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4388, 0},    // 0x01D580
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4389, 0},    // 0x01D581
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4390, 0},    // 0x01D582
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4391, 0},    // 0x01D583
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4392, 0},    // 0x01D584
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4393, 0},    // 0x01D585
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4394, 0},    // 0x01D586
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4395, 0},    // 0x01D587
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4396, 0},    // 0x01D588
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4397, 0},    // 0x01D589
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4398, 0},    // 0x01D58A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4399, 0},    // 0x01D58B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4400, 0},    // 0x01D58C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4401, 0},    // 0x01D58D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4402, 0},    // 0x01D58E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4403, 0},    // 0x01D58F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4404, 0},    // 0x01D590
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4405, 0},    // 0x01D591
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4406, 0},    // 0x01D592
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4407, 0},    // 0x01D593
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4408, 0},    // 0x01D594
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4409, 0},    // 0x01D595
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4410, 0},    // 0x01D596
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4411, 0},    // 0x01D597
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4412, 0},    // 0x01D598
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4413, 0},    // 0x01D599
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4414, 0},    // 0x01D59A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4415, 0},    // 0x01D59B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4416, 0},    // 0x01D59C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4417, 0},    // 0x01D59D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4418, 0},    // 0x01D59E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4419, 0},    // 0x01D59F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4420, 0},    // 0x01D5A0
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4421, 0},    // 0x01D5A1
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4422, 0},    // 0x01D5A2
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4423, 0},    // 0x01D5A3
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4424, 0},    // 0x01D5A4
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4425, 0},    // 0x01D5A5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4426, 0},    // 0x01D5A6
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4427, 0},    // 0x01D5A7
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4428, 0},    // 0x01D5A8
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4429, 0},    // 0x01D5A9
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4430, 0},    // 0x01D5AA
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4431, 0},    // 0x01D5AB
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4432, 0},    // 0x01D5AC
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4433, 0},    // 0x01D5AD
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4434, 0},    // 0x01D5AE
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4435, 0},    // 0x01D5AF
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4436, 0},    // 0x01D5B0
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4437, 0},    // 0x01D5B1
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4438, 0},    // 0x01D5B2
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4439, 0},    // 0x01D5B3
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4440, 0},    // 0x01D5B4
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4441, 0},    // 0x01D5B5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4442, 0},    // 0x01D5B6
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4443, 0},    // 0x01D5B7
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4444, 0},    // 0x01D5B8
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4445, 0},    // 0x01D5B9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4446, 0},    // 0x01D5BA
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4447, 0},    // 0x01D5BB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4448, 0},    // 0x01D5BC
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4449, 0},    // 0x01D5BD
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4450, 0},    // 0x01D5BE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4451, 0},    // 0x01D5BF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4452, 0},    // 0x01D5C0
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4453, 0},    // 0x01D5C1
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4454, 0},    // 0x01D5C2
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4455, 0},    // 0x01D5C3
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4456, 0},    // 0x01D5C4
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4457, 0},    // 0x01D5C5
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4458, 0},    // 0x01D5C6
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4459, 0},    // 0x01D5C7
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4460, 0},    // 0x01D5C8
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4461, 0},    // 0x01D5C9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4462, 0},    // 0x01D5CA
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4463, 0},    // 0x01D5CB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4464, 0},    // 0x01D5CC
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4465, 0},    // 0x01D5CD
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4466, 0},    // 0x01D5CE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4467, 0},    // 0x01D5CF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4468, 0},    // 0x01D5D0
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4469, 0},    // 0x01D5D1
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4470, 0},    // 0x01D5D2
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4471, 0},    // 0x01D5D3
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4472, 0},    // 0x01D5D4
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4473, 0},    // 0x01D5D5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4474, 0},    // 0x01D5D6
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4475, 0},    // 0x01D5D7
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4476, 0},    // 0x01D5D8
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4477, 0},    // 0x01D5D9
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4478, 0},    // 0x01D5DA
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4479, 0},    // 0x01D5DB
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4480, 0},    // 0x01D5DC
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4481, 0},    // 0x01D5DD
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4482, 0},    // 0x01D5DE
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4483, 0},    // 0x01D5DF
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4484, 0},    // 0x01D5E0
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4485, 0},    // 0x01D5E1
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4486, 0},    // 0x01D5E2
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4487, 0},    // 0x01D5E3
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4488, 0},    // 0x01D5E4
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4489, 0},    // 0x01D5E5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4490, 0},    // 0x01D5E6
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4491, 0},    // 0x01D5E7
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4492, 0},    // 0x01D5E8
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4493, 0},    // 0x01D5E9
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4494, 0},    // 0x01D5EA
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4495, 0},    // 0x01D5EB
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4496, 0},    // 0x01D5EC
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4497, 0},    // 0x01D5ED
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4498, 0},    // 0x01D5EE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4499, 0},    // 0x01D5EF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4500, 0},    // 0x01D5F0
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4501, 0},    // 0x01D5F1
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4502, 0},    // 0x01D5F2
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4503, 0},    // 0x01D5F3
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4504, 0},    // 0x01D5F4
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4505, 0},    // 0x01D5F5
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4506, 0},    // 0x01D5F6
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4507, 0},    // 0x01D5F7
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4508, 0},    // 0x01D5F8
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4509, 0},    // 0x01D5F9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4510, 0},    // 0x01D5FA
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4511, 0},    // 0x01D5FB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4512, 0},    // 0x01D5FC
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4513, 0},    // 0x01D5FD
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4514, 0},    // 0x01D5FE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4515, 0},    // 0x01D5FF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4516, 0},    // 0x01D600
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4517, 0},    // 0x01D601
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4518, 0},    // 0x01D602
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4519, 0},    // 0x01D603
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4520, 0},    // 0x01D604
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4521, 0},    // 0x01D605
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4522, 0},    // 0x01D606
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4523, 0},    // 0x01D607
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4524, 0},    // 0x01D608
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4525, 0},    // 0x01D609
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4526, 0},    // 0x01D60A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4527, 0},    // 0x01D60B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4528, 0},    // 0x01D60C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4529, 0},    // 0x01D60D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4530, 0},    // 0x01D60E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4531, 0},    // 0x01D60F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4532, 0},    // 0x01D610
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4533, 0},    // 0x01D611
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4534, 0},    // 0x01D612
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4535, 0},    // 0x01D613
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4536, 0},    // 0x01D614
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4537, 0},    // 0x01D615
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4538, 0},    // 0x01D616
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4539, 0},    // 0x01D617
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4540, 0},    // 0x01D618
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4541, 0},    // 0x01D619
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4542, 0},    // 0x01D61A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4543, 0},    // 0x01D61B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4544, 0},    // 0x01D61C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4545, 0},    // 0x01D61D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4546, 0},    // 0x01D61E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4547, 0},    // 0x01D61F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4548, 0},    // 0x01D620
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4549, 0},    // 0x01D621
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4550, 0},    // 0x01D622
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4551, 0},    // 0x01D623
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4552, 0},    // 0x01D624
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4553, 0},    // 0x01D625
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4554, 0},    // 0x01D626
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4555, 0},    // 0x01D627
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4556, 0},    // 0x01D628
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4557, 0},    // 0x01D629
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4558, 0},    // 0x01D62A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4559, 0},    // 0x01D62B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4560, 0},    // 0x01D62C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4561, 0},    // 0x01D62D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4562, 0},    // 0x01D62E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4563, 0},    // 0x01D62F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4564, 0},    // 0x01D630
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4565, 0},    // 0x01D631
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4566, 0},    // 0x01D632
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4567, 0},    // 0x01D633
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4568, 0},    // 0x01D634
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4569, 0},    // 0x01D635
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4570, 0},    // 0x01D636
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4571, 0},    // 0x01D637
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4572, 0},    // 0x01D638
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4573, 0},    // 0x01D639
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4574, 0},    // 0x01D63A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4575, 0},    // 0x01D63B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4576, 0},    // 0x01D63C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4577, 0},    // 0x01D63D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4578, 0},    // 0x01D63E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4579, 0},    // 0x01D63F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4580, 0},    // 0x01D640
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4581, 0},    // 0x01D641
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4582, 0},    // 0x01D642
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4583, 0},    // 0x01D643
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4584, 0},    // 0x01D644
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4585, 0},    // 0x01D645
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4586, 0},    // 0x01D646
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4587, 0},    // 0x01D647
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4588, 0},    // 0x01D648
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4589, 0},    // 0x01D649
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4590, 0},    // 0x01D64A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4591, 0},    // 0x01D64B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4592, 0},    // 0x01D64C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4593, 0},    // 0x01D64D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4594, 0},    // 0x01D64E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4595, 0},    // 0x01D64F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4596, 0},    // 0x01D650
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4597, 0},    // 0x01D651
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4598, 0},    // 0x01D652
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4599, 0},    // 0x01D653
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4600, 0},    // 0x01D654
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4601, 0},    // 0x01D655
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4602, 0},    // 0x01D656
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4603, 0},    // 0x01D657
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4604, 0},    // 0x01D658
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4605, 0},    // 0x01D659
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4606, 0},    // 0x01D65A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4607, 0},    // 0x01D65B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4608, 0},    // 0x01D65C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4609, 0},    // 0x01D65D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4610, 0},    // 0x01D65E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4611, 0},    // 0x01D65F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4612, 0},    // 0x01D660
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4613, 0},    // 0x01D661
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4614, 0},    // 0x01D662
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4615, 0},    // 0x01D663
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4616, 0},    // 0x01D664
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4617, 0},    // 0x01D665
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4618, 0},    // 0x01D666
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4619, 0},    // 0x01D667
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4620, 0},    // 0x01D668
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4621, 0},    // 0x01D669
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4622, 0},    // 0x01D66A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4623, 0},    // 0x01D66B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4624, 0},    // 0x01D66C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4625, 0},    // 0x01D66D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4626, 0},    // 0x01D66E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4627, 0},    // 0x01D66F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4628, 0},    // 0x01D670
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4629, 0},    // 0x01D671
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4630, 0},    // 0x01D672
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4631, 0},    // 0x01D673
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4632, 0},    // 0x01D674
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4633, 0},    // 0x01D675
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4634, 0},    // 0x01D676
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4635, 0},    // 0x01D677
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4636, 0},    // 0x01D678
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4637, 0},    // 0x01D679
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4638, 0},    // 0x01D67A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4639, 0},    // 0x01D67B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4640, 0},    // 0x01D67C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4641, 0},    // 0x01D67D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4642, 0},    // 0x01D67E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4643, 0},    // 0x01D67F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4644, 0},    // 0x01D680
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4645, 0},    // 0x01D681
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4646, 0},    // 0x01D682
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4647, 0},    // 0x01D683
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4648, 0},    // 0x01D684
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4649, 0},    // 0x01D685
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4650, 0},    // 0x01D686
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4651, 0},    // 0x01D687
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4652, 0},    // 0x01D688
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4653, 0},    // 0x01D689
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4654, 0},    // 0x01D68A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4655, 0},    // 0x01D68B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4656, 0},    // 0x01D68C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4657, 0},    // 0x01D68D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4658, 0},    // 0x01D68E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4659, 0},    // 0x01D68F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4660, 0},    // 0x01D690
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4661, 0},    // 0x01D691
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4662, 0},    // 0x01D692
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4663, 0},    // 0x01D693
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4664, 0},    // 0x01D694
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4665, 0},    // 0x01D695
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4666, 0},    // 0x01D696
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4667, 0},    // 0x01D697
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4668, 0},    // 0x01D698
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4669, 0},    // 0x01D699
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4670, 0},    // 0x01D69A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4671, 0},    // 0x01D69B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4672, 0},    // 0x01D69C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4673, 0},    // 0x01D69D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4674, 0},    // 0x01D69E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4675, 0},    // 0x01D69F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4676, 0},    // 0x01D6A0
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4677, 0},    // 0x01D6A1
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4678, 0},    // 0x01D6A2
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4679, 0},    // 0x01D6A3
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4680, 0},    // 0x01D6A4
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4681, 0},    // 0x01D6A5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4682, 0},    // 0x01D6A8
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4683, 0},    // 0x01D6A9
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4684, 0},    // 0x01D6AA
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4685, 0},    // 0x01D6AB
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4686, 0},    // 0x01D6AC
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4687, 0},    // 0x01D6AD
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4688, 0},    // 0x01D6AE
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4689, 0},    // 0x01D6AF
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4690, 0},    // 0x01D6B0
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4691, 0},    // 0x01D6B1
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4692, 0},    // 0x01D6B2
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4693, 0},    // 0x01D6B3
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4694, 0},    // 0x01D6B4
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4695, 0},    // 0x01D6B5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4696, 0},    // 0x01D6B6
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4697, 0},    // 0x01D6B7
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4698, 0},    // 0x01D6B8
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4699, 0},    // 0x01D6B9
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4700, 0},    // 0x01D6BA
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4701, 0},    // 0x01D6BB
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4702, 0},    // 0x01D6BC
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4703, 0},    // 0x01D6BD
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4704, 0},    // 0x01D6BE
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4705, 0},    // 0x01D6BF
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4706, 0},    // 0x01D6C0
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 4707, 0},    // 0x01D6C1
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4708, 0},    // 0x01D6C2
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4709, 0},    // 0x01D6C3
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4710, 0},    // 0x01D6C4
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4711, 0},    // 0x01D6C5
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4712, 0},    // 0x01D6C6
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4713, 0},    // 0x01D6C7
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4714, 0},    // 0x01D6C8
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4715, 0},    // 0x01D6C9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4716, 0},    // 0x01D6CA
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4717, 0},    // 0x01D6CB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4718, 0},    // 0x01D6CC
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4719, 0},    // 0x01D6CD
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4720, 0},    // 0x01D6CE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4721, 0},    // 0x01D6CF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4722, 0},    // 0x01D6D0
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4723, 0},    // 0x01D6D1
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4724, 0},    // 0x01D6D2
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4725, 0},    // 0x01D6D3
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4726, 0},    // 0x01D6D4
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4727, 0},    // 0x01D6D5
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4728, 0},    // 0x01D6D6
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4729, 0},    // 0x01D6D7
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4730, 0},    // 0x01D6D8
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4731, 0},    // 0x01D6D9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4732, 0},    // 0x01D6DA
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 4733, 0},    // 0x01D6DB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4734, 0},    // 0x01D6DC
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4735, 0},    // 0x01D6DD
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4736, 0},    // 0x01D6DE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4737, 0},    // 0x01D6DF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4738, 0},    // 0x01D6E0
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4739, 0},    // 0x01D6E1
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4740, 0},    // 0x01D6E2
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4741, 0},    // 0x01D6E3
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4742, 0},    // 0x01D6E4
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4743, 0},    // 0x01D6E5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4744, 0},    // 0x01D6E6
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4745, 0},    // 0x01D6E7
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4746, 0},    // 0x01D6E8
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4747, 0},    // 0x01D6E9
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4748, 0},    // 0x01D6EA
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4749, 0},    // 0x01D6EB
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4750, 0},    // 0x01D6EC
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4751, 0},    // 0x01D6ED
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4752, 0},    // 0x01D6EE
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4753, 0},    // 0x01D6EF
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4754, 0},    // 0x01D6F0
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4755, 0},    // 0x01D6F1
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4756, 0},    // 0x01D6F2
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4757, 0},    // 0x01D6F3
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4758, 0},    // 0x01D6F4
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4759, 0},    // 0x01D6F5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4760, 0},    // 0x01D6F6
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4761, 0},    // 0x01D6F7
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4762, 0},    // 0x01D6F8
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4763, 0},    // 0x01D6F9
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4764, 0},    // 0x01D6FA
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 4765, 0},    // 0x01D6FB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4766, 0},    // 0x01D6FC
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4767, 0},    // 0x01D6FD
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4768, 0},    // 0x01D6FE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4769, 0},    // 0x01D6FF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4770, 0},    // 0x01D700
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4771, 0},    // 0x01D701
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4772, 0},    // 0x01D702
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4773, 0},    // 0x01D703
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4774, 0},    // 0x01D704
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4775, 0},    // 0x01D705
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4776, 0},    // 0x01D706
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4777, 0},    // 0x01D707
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4778, 0},    // 0x01D708
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4779, 0},    // 0x01D709
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4780, 0},    // 0x01D70A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4781, 0},    // 0x01D70B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4782, 0},    // 0x01D70C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4783, 0},    // 0x01D70D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4784, 0},    // 0x01D70E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4785, 0},    // 0x01D70F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4786, 0},    // 0x01D710
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4787, 0},    // 0x01D711
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4788, 0},    // 0x01D712
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4789, 0},    // 0x01D713
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4790, 0},    // 0x01D714
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 4791, 0},    // 0x01D715
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4792, 0},    // 0x01D716
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4793, 0},    // 0x01D717
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4794, 0},    // 0x01D718
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4795, 0},    // 0x01D719
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4796, 0},    // 0x01D71A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4797, 0},    // 0x01D71B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4798, 0},    // 0x01D71C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4799, 0},    // 0x01D71D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4800, 0},    // 0x01D71E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4801, 0},    // 0x01D71F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4802, 0},    // 0x01D720
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4803, 0},    // 0x01D721
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4804, 0},    // 0x01D722
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4805, 0},    // 0x01D723
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4806, 0},    // 0x01D724
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4807, 0},    // 0x01D725
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4808, 0},    // 0x01D726
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4809, 0},    // 0x01D727
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4810, 0},    // 0x01D728
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4811, 0},    // 0x01D729
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4812, 0},    // 0x01D72A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4813, 0},    // 0x01D72B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4814, 0},    // 0x01D72C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4815, 0},    // 0x01D72D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4816, 0},    // 0x01D72E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4817, 0},    // 0x01D72F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4818, 0},    // 0x01D730
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4819, 0},    // 0x01D731
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4820, 0},    // 0x01D732
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4821, 0},    // 0x01D733
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4822, 0},    // 0x01D734
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 4823, 0},    // 0x01D735
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4824, 0},    // 0x01D736
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4825, 0},    // 0x01D737
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4826, 0},    // 0x01D738
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4827, 0},    // 0x01D739
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4828, 0},    // 0x01D73A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4829, 0},    // 0x01D73B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4830, 0},    // 0x01D73C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4831, 0},    // 0x01D73D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4832, 0},    // 0x01D73E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4833, 0},    // 0x01D73F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4834, 0},    // 0x01D740
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4835, 0},    // 0x01D741
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4836, 0},    // 0x01D742
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4837, 0},    // 0x01D743
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4838, 0},    // 0x01D744
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4839, 0},    // 0x01D745
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4840, 0},    // 0x01D746
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4841, 0},    // 0x01D747
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4842, 0},    // 0x01D748
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4843, 0},    // 0x01D749
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4844, 0},    // 0x01D74A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4845, 0},    // 0x01D74B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4846, 0},    // 0x01D74C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4847, 0},    // 0x01D74D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4848, 0},    // 0x01D74E
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 4849, 0},    // 0x01D74F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4850, 0},    // 0x01D750
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4851, 0},    // 0x01D751
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4852, 0},    // 0x01D752
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4853, 0},    // 0x01D753
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4854, 0},    // 0x01D754
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4855, 0},    // 0x01D755
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4856, 0},    // 0x01D756
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4857, 0},    // 0x01D757
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4858, 0},    // 0x01D758
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4859, 0},    // 0x01D759
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4860, 0},    // 0x01D75A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4861, 0},    // 0x01D75B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4862, 0},    // 0x01D75C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4863, 0},    // 0x01D75D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4864, 0},    // 0x01D75E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4865, 0},    // 0x01D75F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4866, 0},    // 0x01D760
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4867, 0},    // 0x01D761
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4868, 0},    // 0x01D762
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4869, 0},    // 0x01D763
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4870, 0},    // 0x01D764
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4871, 0},    // 0x01D765
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4872, 0},    // 0x01D766
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4873, 0},    // 0x01D767
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4874, 0},    // 0x01D768
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4875, 0},    // 0x01D769
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4876, 0},    // 0x01D76A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4877, 0},    // 0x01D76B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4878, 0},    // 0x01D76C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4879, 0},    // 0x01D76D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4880, 0},    // 0x01D76E
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 4881, 0},    // 0x01D76F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4882, 0},    // 0x01D770
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4883, 0},    // 0x01D771
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4884, 0},    // 0x01D772
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4885, 0},    // 0x01D773
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4886, 0},    // 0x01D774
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4887, 0},    // 0x01D775
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4888, 0},    // 0x01D776
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4889, 0},    // 0x01D777
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4890, 0},    // 0x01D778
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4891, 0},    // 0x01D779
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4892, 0},    // 0x01D77A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4893, 0},    // 0x01D77B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4894, 0},    // 0x01D77C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4895, 0},    // 0x01D77D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4896, 0},    // 0x01D77E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4897, 0},    // 0x01D77F
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4898, 0},    // 0x01D780
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4899, 0},    // 0x01D781
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4900, 0},    // 0x01D782
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4901, 0},    // 0x01D783
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4902, 0},    // 0x01D784
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4903, 0},    // 0x01D785
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4904, 0},    // 0x01D786
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4905, 0},    // 0x01D787
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4906, 0},    // 0x01D788
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 4907, 0},    // 0x01D789
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4908, 0},    // 0x01D78A
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4909, 0},    // 0x01D78B
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4910, 0},    // 0x01D78C
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4911, 0},    // 0x01D78D
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4912, 0},    // 0x01D78E
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4913, 0},    // 0x01D78F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4914, 0},    // 0x01D790
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4915, 0},    // 0x01D791
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4916, 0},    // 0x01D792
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4917, 0},    // 0x01D793
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4918, 0},    // 0x01D794
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4919, 0},    // 0x01D795
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4920, 0},    // 0x01D796
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4921, 0},    // 0x01D797
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4922, 0},    // 0x01D798
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4923, 0},    // 0x01D799
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4924, 0},    // 0x01D79A
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4925, 0},    // 0x01D79B
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4926, 0},    // 0x01D79C
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4927, 0},    // 0x01D79D
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4928, 0},    // 0x01D79E
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4929, 0},    // 0x01D79F
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4930, 0},    // 0x01D7A0
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4931, 0},    // 0x01D7A1
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4932, 0},    // 0x01D7A2
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4933, 0},    // 0x01D7A3
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4934, 0},    // 0x01D7A4
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4935, 0},    // 0x01D7A5
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4936, 0},    // 0x01D7A6
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4937, 0},    // 0x01D7A7
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4938, 0},    // 0x01D7A8
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 4939, 0},    // 0x01D7A9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4940, 0},    // 0x01D7AA
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4941, 0},    // 0x01D7AB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4942, 0},    // 0x01D7AC
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4943, 0},    // 0x01D7AD
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4944, 0},    // 0x01D7AE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4945, 0},    // 0x01D7AF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4946, 0},    // 0x01D7B0
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4947, 0},    // 0x01D7B1
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4948, 0},    // 0x01D7B2
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4949, 0},    // 0x01D7B3
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4950, 0},    // 0x01D7B4
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4951, 0},    // 0x01D7B5
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4952, 0},    // 0x01D7B6
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4953, 0},    // 0x01D7B7
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4954, 0},    // 0x01D7B8
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4955, 0},    // 0x01D7B9
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4956, 0},    // 0x01D7BA
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4957, 0},    // 0x01D7BB
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4958, 0},    // 0x01D7BC
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4959, 0},    // 0x01D7BD
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4960, 0},    // 0x01D7BE
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4961, 0},    // 0x01D7BF
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4962, 0},    // 0x01D7C0
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4963, 0},    // 0x01D7C1
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4964, 0},    // 0x01D7C2
    {4, TINYUCD_GC_SM, 0, 0, 0, 0, 0, 4965, 0},    // 0x01D7C3
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4966, 0},    // 0x01D7C4
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4967, 0},    // 0x01D7C5
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4968, 0},    // 0x01D7C6
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4969, 0},    // 0x01D7C7
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4970, 0},    // 0x01D7C8
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4971, 0},    // 0x01D7C9
    {4, TINYUCD_GC_LU, 0, 0, 0, 0, 0, 4972, 0},    // 0x01D7CA
    {4, TINYUCD_GC_LL, 0, 0, 0, 0, 0, 4973, 0},    // 0x01D7CB
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4974, 0},    // 0x01D7CE
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4975, 0},    // 0x01D7CF
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4976, 0},    // 0x01D7D0
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4977, 0},    // 0x01D7D1
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4978, 0},    // 0x01D7D2
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4979, 0},    // 0x01D7D3
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4980, 0},    // 0x01D7D4
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4981, 0},    // 0x01D7D5
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4982, 0},    // 0x01D7D6
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4983, 0},    // 0x01D7D7
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4984, 0},    // 0x01D7D8
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4985, 0},    // 0x01D7D9
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4986, 0},    // 0x01D7DA
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4987, 0},    // 0x01D7DB
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4988, 0},    // 0x01D7DC
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4989, 0},    // 0x01D7DD
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4990, 0},    // 0x01D7DE
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4991, 0},    // 0x01D7DF
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4992, 0},    // 0x01D7E0
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4993, 0},    // 0x01D7E1
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4994, 0},    // 0x01D7E2
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4995, 0},    // 0x01D7E3
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4996, 0},    // 0x01D7E4
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4997, 0},    // 0x01D7E5
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4998, 0},    // 0x01D7E6
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 4999, 0},    // 0x01D7E7
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5000, 0},    // 0x01D7E8
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5001, 0},    // 0x01D7E9
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5002, 0},    // 0x01D7EA
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5003, 0},    // 0x01D7EB
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5004, 0},    // 0x01D7EC
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5005, 0},    // 0x01D7ED
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5006, 0},    // 0x01D7EE
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5007, 0},    // 0x01D7EF
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5008, 0},    // 0x01D7F0
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5009, 0},    // 0x01D7F1
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5010, 0},    // 0x01D7F2
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5011, 0},    // 0x01D7F3
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5012, 0},    // 0x01D7F4
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5013, 0},    // 0x01D7F5
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5014, 0},    // 0x01D7F6
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5015, 0},    // 0x01D7F7
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5016, 0},    // 0x01D7F8
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5017, 0},    // 0x01D7F9
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5018, 0},    // 0x01D7FA
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5019, 0},    // 0x01D7FB
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5020, 0},    // 0x01D7FC
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5021, 0},    // 0x01D7FD
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5022, 0},    // 0x01D7FE
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5023, 0},    // 0x01D7FF
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5024, 0},    // 0x01E030
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5025, 0},    // 0x01E031
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5026, 0},    // 0x01E032
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5027, 0},    // 0x01E033
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5028, 0},    // 0x01E034
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5029, 0},    // 0x01E035
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5030, 0},    // 0x01E036
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5031, 0},    // 0x01E037
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5032, 0},    // 0x01E038
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5033, 0},    // 0x01E039
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5034, 0},    // 0x01E03A
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5035, 0},    // 0x01E03B
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5036, 0},    // 0x01E03C
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5037, 0},    // 0x01E03D
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5038, 0},    // 0x01E03E
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5039, 0},    // 0x01E03F
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5040, 0},    // 0x01E040
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5041, 0},    // 0x01E041
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5042, 0},    // 0x01E042
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5043, 0},    // 0x01E043
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5044, 0},    // 0x01E044
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5045, 0},    // 0x01E045
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5046, 0},    // 0x01E046
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5047, 0},    // 0x01E047
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5048, 0},    // 0x01E048
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5049, 0},    // 0x01E049
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5050, 0},    // 0x01E04A
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5051, 0},    // 0x01E04B
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5052, 0},    // 0x01E04C
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5053, 0},    // 0x01E04D
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5054, 0},    // 0x01E04E
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5055, 0},    // 0x01E04F
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5056, 0},    // 0x01E050
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5057, 0},    // 0x01E051
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5058, 0},    // 0x01E052
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5059, 0},    // 0x01E053
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5060, 0},    // 0x01E054
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5061, 0},    // 0x01E055
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5062, 0},    // 0x01E056
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5063, 0},    // 0x01E057
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5064, 0},    // 0x01E058
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5065, 0},    // 0x01E059
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5066, 0},    // 0x01E05A
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5067, 0},    // 0x01E05B
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5068, 0},    // 0x01E05C
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5069, 0},    // 0x01E05D
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5070, 0},    // 0x01E05E
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5071, 0},    // 0x01E05F
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5072, 0},    // 0x01E060
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5073, 0},    // 0x01E061
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5074, 0},    // 0x01E062
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5075, 0},    // 0x01E063
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5076, 0},    // 0x01E064
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5077, 0},    // 0x01E065
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5078, 0},    // 0x01E066
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5079, 0},    // 0x01E067
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5080, 0},    // 0x01E068
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5081, 0},    // 0x01E069
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5082, 0},    // 0x01E06A
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5083, 0},    // 0x01E06B
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5084, 0},    // 0x01E06C
    {4, TINYUCD_GC_LM, 0, 0, 0, 0, 0, 5085, 0},    // 0x01E06D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2970, 0, 0},    // 0x01E900
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2971, 0, 0},    // 0x01E901
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2972, 0, 0},    // 0x01E902
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2973, 0, 0},    // 0x01E903
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2974, 0, 0},    // 0x01E904
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2975, 0, 0},    // 0x01E905
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2976, 0, 0},    // 0x01E906
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2977, 0, 0},    // 0x01E907
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2978, 0, 0},    // 0x01E908
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2979, 0, 0},    // 0x01E909
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2980, 0, 0},    // 0x01E90A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2981, 0, 0},    // 0x01E90B
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2982, 0, 0},    // 0x01E90C
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2983, 0, 0},    // 0x01E90D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2984, 0, 0},    // 0x01E90E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2985, 0, 0},    // 0x01E90F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2986, 0, 0},    // 0x01E910
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2987, 0, 0},    // 0x01E911
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2988, 0, 0},    // 0x01E912
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2989, 0, 0},    // 0x01E913
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2990, 0, 0},    // 0x01E914
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2991, 0, 0},    // 0x01E915
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2992, 0, 0},    // 0x01E916
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2993, 0, 0},    // 0x01E917
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2994, 0, 0},    // 0x01E918
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2995, 0, 0},    // 0x01E919
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2996, 0, 0},    // 0x01E91A
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2997, 0, 0},    // 0x01E91B
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2998, 0, 0},    // 0x01E91C
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 2999, 0, 0},    // 0x01E91D
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 3000, 0, 0},    // 0x01E91E
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 3001, 0, 0},    // 0x01E91F
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 3002, 0, 0},    // 0x01E920
    {0, TINYUCD_GC_LU, 0, 0, 0, 0, 3003, 0, 0},    // 0x01E921
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3004, 0, 0},    // 0x01E922
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3005, 0, 0},    // 0x01E923
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3006, 0, 0},    // 0x01E924
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3007, 0, 0},    // 0x01E925
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3008, 0, 0},    // 0x01E926
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3009, 0, 0},    // 0x01E927
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3010, 0, 0},    // 0x01E928
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3011, 0, 0},    // 0x01E929
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3012, 0, 0},    // 0x01E92A
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3013, 0, 0},    // 0x01E92B
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3014, 0, 0},    // 0x01E92C
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3015, 0, 0},    // 0x01E92D
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3016, 0, 0},    // 0x01E92E
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3017, 0, 0},    // 0x01E92F
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3018, 0, 0},    // 0x01E930
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3019, 0, 0},    // 0x01E931
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3020, 0, 0},    // 0x01E932
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3021, 0, 0},    // 0x01E933
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3022, 0, 0},    // 0x01E934
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3023, 0, 0},    // 0x01E935
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3024, 0, 0},    // 0x01E936
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3025, 0, 0},    // 0x01E937
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3026, 0, 0},    // 0x01E938
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3027, 0, 0},    // 0x01E939
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3028, 0, 0},    // 0x01E93A
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3029, 0, 0},    // 0x01E93B
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3030, 0, 0},    // 0x01E93C
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3031, 0, 0},    // 0x01E93D
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3032, 0, 0},    // 0x01E93E
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3033, 0, 0},    // 0x01E93F
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3034, 0, 0},    // 0x01E940
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3035, 0, 0},    // 0x01E941
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3036, 0, 0},    // 0x01E942
    {0, TINYUCD_GC_LL, 0, 0, 0, 0, 3037, 0, 0},    // 0x01E943
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5086, 0},    // 0x01EE00
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5087, 0},    // 0x01EE01
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5088, 0},    // 0x01EE02
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5089, 0},    // 0x01EE03
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5090, 0},    // 0x01EE05
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5091, 0},    // 0x01EE06
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5092, 0},    // 0x01EE07
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5093, 0},    // 0x01EE08
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5094, 0},    // 0x01EE09
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5095, 0},    // 0x01EE0A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5096, 0},    // 0x01EE0B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5097, 0},    // 0x01EE0C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5098, 0},    // 0x01EE0D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5099, 0},    // 0x01EE0E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5100, 0},    // 0x01EE0F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5101, 0},    // 0x01EE10
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5102, 0},    // 0x01EE11
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5103, 0},    // 0x01EE12
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5104, 0},    // 0x01EE13
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5105, 0},    // 0x01EE14
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5106, 0},    // 0x01EE15
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5107, 0},    // 0x01EE16
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5108, 0},    // 0x01EE17
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5109, 0},    // 0x01EE18
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5110, 0},    // 0x01EE19
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5111, 0},    // 0x01EE1A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5112, 0},    // 0x01EE1B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5113, 0},    // 0x01EE1C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5114, 0},    // 0x01EE1D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5115, 0},    // 0x01EE1E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5116, 0},    // 0x01EE1F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5117, 0},    // 0x01EE21
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5118, 0},    // 0x01EE22
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5119, 0},    // 0x01EE24
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5120, 0},    // 0x01EE27
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5121, 0},    // 0x01EE29
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5122, 0},    // 0x01EE2A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5123, 0},    // 0x01EE2B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5124, 0},    // 0x01EE2C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5125, 0},    // 0x01EE2D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5126, 0},    // 0x01EE2E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5127, 0},    // 0x01EE2F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5128, 0},    // 0x01EE30
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5129, 0},    // 0x01EE31
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5130, 0},    // 0x01EE32
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5131, 0},    // 0x01EE34
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5132, 0},    // 0x01EE35
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5133, 0},    // 0x01EE36
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5134, 0},    // 0x01EE37
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5135, 0},    // 0x01EE39
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5136, 0},    // 0x01EE3B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5137, 0},    // 0x01EE42
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5138, 0},    // 0x01EE47
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5139, 0},    // 0x01EE49
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5140, 0},    // 0x01EE4B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5141, 0},    // 0x01EE4D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5142, 0},    // 0x01EE4E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5143, 0},    // 0x01EE4F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5144, 0},    // 0x01EE51
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5145, 0},    // 0x01EE52
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5146, 0},    // 0x01EE54
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5147, 0},    // 0x01EE57
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5148, 0},    // 0x01EE59
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5149, 0},    // 0x01EE5B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5150, 0},    // 0x01EE5D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5151, 0},    // 0x01EE5F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5152, 0},    // 0x01EE61
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5153, 0},    // 0x01EE62
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5154, 0},    // 0x01EE64
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5155, 0},    // 0x01EE67
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5156, 0},    // 0x01EE68
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5157, 0},    // 0x01EE69
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5158, 0},    // 0x01EE6A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5159, 0},    // 0x01EE6C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5160, 0},    // 0x01EE6D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5161, 0},    // 0x01EE6E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5162, 0},    // 0x01EE6F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5163, 0},    // 0x01EE70
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5164, 0},    // 0x01EE71
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5165, 0},    // 0x01EE72
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5166, 0},    // 0x01EE74
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5167, 0},    // 0x01EE75
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5168, 0},    // 0x01EE76
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5169, 0},    // 0x01EE77
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5170, 0},    // 0x01EE79
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5171, 0},    // 0x01EE7A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5172, 0},    // 0x01EE7B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5173, 0},    // 0x01EE7C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5174, 0},    // 0x01EE7E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5175, 0},    // 0x01EE80
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5176, 0},    // 0x01EE81
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5177, 0},    // 0x01EE82
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5178, 0},    // 0x01EE83
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5179, 0},    // 0x01EE84
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5180, 0},    // 0x01EE85
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5181, 0},    // 0x01EE86
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5182, 0},    // 0x01EE87
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5183, 0},    // 0x01EE88
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5184, 0},    // 0x01EE89
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5185, 0},    // 0x01EE8B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5186, 0},    // 0x01EE8C
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5187, 0},    // 0x01EE8D
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5188, 0},    // 0x01EE8E
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5189, 0},    // 0x01EE8F
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5190, 0},    // 0x01EE90
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5191, 0},    // 0x01EE91
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5192, 0},    // 0x01EE92
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5193, 0},    // 0x01EE93
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5194, 0},    // 0x01EE94
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5195, 0},    // 0x01EE95
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5196, 0},    // 0x01EE96
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5197, 0},    // 0x01EE97
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5198, 0},    // 0x01EE98
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5199, 0},    // 0x01EE99
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5200, 0},    // 0x01EE9A
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5201, 0},    // 0x01EE9B
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5202, 0},    // 0x01EEA1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5203, 0},    // 0x01EEA2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5204, 0},    // 0x01EEA3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5205, 0},    // 0x01EEA5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5206, 0},    // 0x01EEA6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5207, 0},    // 0x01EEA7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5208, 0},    // 0x01EEA8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5209, 0},    // 0x01EEA9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5210, 0},    // 0x01EEAB
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5211, 0},    // 0x01EEAC
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5212, 0},    // 0x01EEAD
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5213, 0},    // 0x01EEAE
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5214, 0},    // 0x01EEAF
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5215, 0},    // 0x01EEB0
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5216, 0},    // 0x01EEB1
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5217, 0},    // 0x01EEB2
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5218, 0},    // 0x01EEB3
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5219, 0},    // 0x01EEB4
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5220, 0},    // 0x01EEB5
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5221, 0},    // 0x01EEB6
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5222, 0},    // 0x01EEB7
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5223, 0},    // 0x01EEB8
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5224, 0},    // 0x01EEB9
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5225, 0},    // 0x01EEBA
    {4, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5226, 0},    // 0x01EEBB
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5227, 0},    // 0x01F100
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5228, 0},    // 0x01F101
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5229, 0},    // 0x01F102
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5230, 0},    // 0x01F103
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5231, 0},    // 0x01F104
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5232, 0},    // 0x01F105
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5233, 0},    // 0x01F106
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5234, 0},    // 0x01F107
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5235, 0},    // 0x01F108
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5236, 0},    // 0x01F109
    {4, TINYUCD_GC_NO, 0, 0, 0, 0, 0, 5237, 0},    // 0x01F10A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5238, 0},    // 0x01F110
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5239, 0},    // 0x01F111
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5240, 0},    // 0x01F112
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5241, 0},    // 0x01F113
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5242, 0},    // 0x01F114
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5243, 0},    // 0x01F115
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5244, 0},    // 0x01F116
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5245, 0},    // 0x01F117
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5246, 0},    // 0x01F118
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5247, 0},    // 0x01F119
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5248, 0},    // 0x01F11A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5249, 0},    // 0x01F11B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5250, 0},    // 0x01F11C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5251, 0},    // 0x01F11D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5252, 0},    // 0x01F11E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5253, 0},    // 0x01F11F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5254, 0},    // 0x01F120
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5255, 0},    // 0x01F121
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5256, 0},    // 0x01F122
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5257, 0},    // 0x01F123
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5258, 0},    // 0x01F124
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5259, 0},    // 0x01F125
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5260, 0},    // 0x01F126
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5261, 0},    // 0x01F127
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5262, 0},    // 0x01F128
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5263, 0},    // 0x01F129
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5264, 0},    // 0x01F12A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5265, 0},    // 0x01F12B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5266, 0},    // 0x01F12C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5267, 0},    // 0x01F12D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5268, 0},    // 0x01F12E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5269, 0},    // 0x01F130
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5270, 0},    // 0x01F131
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5271, 0},    // 0x01F132
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5272, 0},    // 0x01F133
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5273, 0},    // 0x01F134
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5274, 0},    // 0x01F135
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5275, 0},    // 0x01F136
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5276, 0},    // 0x01F137
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5277, 0},    // 0x01F138
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5278, 0},    // 0x01F139
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5279, 0},    // 0x01F13A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5280, 0},    // 0x01F13B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5281, 0},    // 0x01F13C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5282, 0},    // 0x01F13D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5283, 0},    // 0x01F13E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5284, 0},    // 0x01F13F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5285, 0},    // 0x01F140
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5286, 0},    // 0x01F141
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5287, 0},    // 0x01F142
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5288, 0},    // 0x01F143
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5289, 0},    // 0x01F144
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5290, 0},    // 0x01F145
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5291, 0},    // 0x01F146
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5292, 0},    // 0x01F147
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5293, 0},    // 0x01F148
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5294, 0},    // 0x01F149
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5295, 0},    // 0x01F14A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5296, 0},    // 0x01F14B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5297, 0},    // 0x01F14C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5298, 0},    // 0x01F14D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5299, 0},    // 0x01F14E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5300, 0},    // 0x01F14F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5301, 0},    // 0x01F16A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5302, 0},    // 0x01F16B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5303, 0},    // 0x01F16C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5304, 0},    // 0x01F190
    {0, TINYUCD_GC_SO, 0, 6, 0, 0, 0, 0, 0},       // 26 codepoints in range [0x01F1E6, 0x01F1FF]
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5305, 0},    // 0x01F200
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5306, 0},    // 0x01F201
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5307, 0},    // 0x01F202
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5308, 0},    // 0x01F210
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5309, 0},    // 0x01F211
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5310, 0},    // 0x01F212
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5311, 0},    // 0x01F213
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5312, 0},    // 0x01F214
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5313, 0},    // 0x01F215
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5314, 0},    // 0x01F216
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5315, 0},    // 0x01F217
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5316, 0},    // 0x01F218
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5317, 0},    // 0x01F219
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5318, 0},    // 0x01F21A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5319, 0},    // 0x01F21B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5320, 0},    // 0x01F21C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5321, 0},    // 0x01F21D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5322, 0},    // 0x01F21E
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5323, 0},    // 0x01F21F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5324, 0},    // 0x01F220
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5325, 0},    // 0x01F221
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5326, 0},    // 0x01F222
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5327, 0},    // 0x01F223
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5328, 0},    // 0x01F224
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5329, 0},    // 0x01F225
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5330, 0},    // 0x01F226
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5331, 0},    // 0x01F227
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5332, 0},    // 0x01F228
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5333, 0},    // 0x01F229
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5334, 0},    // 0x01F22A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5335, 0},    // 0x01F22B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5336, 0},    // 0x01F22C
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5337, 0},    // 0x01F22D
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5338, 0},    // 0x01F22E
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5339, 0},    // 0x01F22F
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5340, 0},    // 0x01F230
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5341, 0},    // 0x01F231
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5342, 0},    // 0x01F232
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5343, 0},    // 0x01F233
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5344, 0},    // 0x01F234
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5345, 0},    // 0x01F235
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5346, 0},    // 0x01F236
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5347, 0},    // 0x01F237
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5348, 0},    // 0x01F238
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5349, 0},    // 0x01F239
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5350, 0},    // 0x01F23A
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5351, 0},    // 0x01F23B
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5352, 0},    // 0x01F240
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5353, 0},    // 0x01F241
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5354, 0},    // 0x01F242
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5355, 0},    // 0x01F243
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5356, 0},    // 0x01F244
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5357, 0},    // 0x01F245
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5358, 0},    // 0x01F246
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5359, 0},    // 0x01F247
    {4, TINYUCD_GC_SO, 0, 0, 0, 0, 0, 5360, 0},    // 0x01F248
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5361, 0},    // 0x01F250
    {4, TINYUCD_GC_SO, 0, 0, 0, 1, 0, 5362, 0},    // 0x01F251
    {0, TINYUCD_GC_SK, 0, 4, 2, 0, 0, 0, 0},       // 5 codepoints in range [0x01F3FB, 0x01F3FF]
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5363, 0},    // 0x01FBF0
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5364, 0},    // 0x01FBF1
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5365, 0},    // 0x01FBF2
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5366, 0},    // 0x01FBF3
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5367, 0},    // 0x01FBF4
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5368, 0},    // 0x01FBF5
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5369, 0},    // 0x01FBF6
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5370, 0},    // 0x01FBF7
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5371, 0},    // 0x01FBF8
    {4, TINYUCD_GC_ND, 0, 0, 0, 0, 0, 5372, 0},    // 0x01FBF9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5373, 0},    // 0x02F800
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5374, 0},    // 0x02F801
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5375, 0},    // 0x02F802
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5376, 0},    // 0x02F803
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5377, 0},    // 0x02F804
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5378, 0},    // 0x02F805
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5379, 0},    // 0x02F806
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5380, 0},    // 0x02F807
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5381, 0},    // 0x02F808
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5382, 0},    // 0x02F809
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5383, 0},    // 0x02F80A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5384, 0},    // 0x02F80B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5385, 0},    // 0x02F80C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5386, 0},    // 0x02F80D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5387, 0},    // 0x02F80E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5388, 0},    // 0x02F80F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5389, 0},    // 0x02F810
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5390, 0},    // 0x02F811
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5391, 0},    // 0x02F812
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5392, 0},    // 0x02F813
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5393, 0},    // 0x02F814
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5394, 0},    // 0x02F815
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5395, 0},    // 0x02F816
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5396, 0},    // 0x02F817
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5397, 0},    // 0x02F818
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5398, 0},    // 0x02F819
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5399, 0},    // 0x02F81A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5400, 0},    // 0x02F81B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5401, 0},    // 0x02F81C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5402, 0},    // 0x02F81D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5403, 0},    // 0x02F81E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5404, 0},    // 0x02F81F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5405, 0},    // 0x02F820
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5406, 0},    // 0x02F821
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5407, 0},    // 0x02F822
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5408, 0},    // 0x02F823
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5409, 0},    // 0x02F824
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5410, 0},    // 0x02F825
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5411, 0},    // 0x02F826
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5412, 0},    // 0x02F827
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5413, 0},    // 0x02F828
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5414, 0},    // 0x02F829
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5415, 0},    // 0x02F82A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5416, 0},    // 0x02F82B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5417, 0},    // 0x02F82C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5418, 0},    // 0x02F82D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5419, 0},    // 0x02F82E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5420, 0},    // 0x02F82F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5421, 0},    // 0x02F830
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5422, 0},    // 0x02F831
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5423, 0},    // 0x02F832
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5424, 0},    // 0x02F833
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5425, 0},    // 0x02F834
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5426, 0},    // 0x02F835
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5427, 0},    // 0x02F836
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5428, 0},    // 0x02F837
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5429, 0},    // 0x02F838
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5430, 0},    // 0x02F839
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5431, 0},    // 0x02F83A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5432, 0},    // 0x02F83B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5433, 0},    // 0x02F83C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5434, 0},    // 0x02F83D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5435, 0},    // 0x02F83E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5436, 0},    // 0x02F83F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5437, 0},    // 0x02F840
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5438, 0},    // 0x02F841
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5439, 0},    // 0x02F842
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5440, 0},    // 0x02F843
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5441, 0},    // 0x02F844
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5442, 0},    // 0x02F845
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5443, 0},    // 0x02F846
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5444, 0},    // 0x02F847
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5445, 0},    // 0x02F848
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5446, 0},    // 0x02F849
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5447, 0},    // 0x02F84A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5448, 0},    // 0x02F84B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5449, 0},    // 0x02F84C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5450, 0},    // 0x02F84D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5451, 0},    // 0x02F84E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5452, 0},    // 0x02F84F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5453, 0},    // 0x02F850
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5454, 0},    // 0x02F851
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5455, 0},    // 0x02F852
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5456, 0},    // 0x02F853
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5457, 0},    // 0x02F854
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5458, 0},    // 0x02F855
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5459, 0},    // 0x02F856
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5460, 0},    // 0x02F857
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5461, 0},    // 0x02F858
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5462, 0},    // 0x02F859
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5463, 0},    // 0x02F85A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5464, 0},    // 0x02F85B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5465, 0},    // 0x02F85C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5466, 0},    // 0x02F85D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5467, 0},    // 0x02F85E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5468, 0},    // 0x02F85F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5469, 0},    // 0x02F860
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5470, 0},    // 0x02F861
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5471, 0},    // 0x02F862
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5472, 0},    // 0x02F863
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5473, 0},    // 0x02F864
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5474, 0},    // 0x02F865
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5475, 0},    // 0x02F866
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5476, 0},    // 0x02F867
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5477, 0},    // 0x02F868
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5478, 0},    // 0x02F869
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5479, 0},    // 0x02F86A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5480, 0},    // 0x02F86B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5481, 0},    // 0x02F86C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5482, 0},    // 0x02F86D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5483, 0},    // 0x02F86E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5484, 0},    // 0x02F86F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5485, 0},    // 0x02F870
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5486, 0},    // 0x02F871
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5487, 0},    // 0x02F872
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5488, 0},    // 0x02F873
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5489, 0},    // 0x02F874
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5490, 0},    // 0x02F875
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5491, 0},    // 0x02F876
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5492, 0},    // 0x02F877
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5493, 0},    // 0x02F878
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5494, 0},    // 0x02F879
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5495, 0},    // 0x02F87A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5496, 0},    // 0x02F87B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5497, 0},    // 0x02F87C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5498, 0},    // 0x02F87D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5499, 0},    // 0x02F87E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5500, 0},    // 0x02F87F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5501, 0},    // 0x02F880
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5502, 0},    // 0x02F881
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5503, 0},    // 0x02F882
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5504, 0},    // 0x02F883
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5505, 0},    // 0x02F884
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5506, 0},    // 0x02F885
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5507, 0},    // 0x02F886
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5508, 0},    // 0x02F887
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5509, 0},    // 0x02F888
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5510, 0},    // 0x02F889
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5511, 0},    // 0x02F88A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5512, 0},    // 0x02F88B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5513, 0},    // 0x02F88C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5514, 0},    // 0x02F88D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5515, 0},    // 0x02F88E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5516, 0},    // 0x02F88F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5517, 0},    // 0x02F890
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5518, 0},    // 0x02F891
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5519, 0},    // 0x02F892
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5520, 0},    // 0x02F893
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5521, 0},    // 0x02F894
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5522, 0},    // 0x02F895
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5523, 0},    // 0x02F896
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5524, 0},    // 0x02F897
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5525, 0},    // 0x02F898
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5526, 0},    // 0x02F899
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5527, 0},    // 0x02F89A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5528, 0},    // 0x02F89B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5529, 0},    // 0x02F89C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5530, 0},    // 0x02F89D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5531, 0},    // 0x02F89E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5532, 0},    // 0x02F89F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5533, 0},    // 0x02F8A0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5534, 0},    // 0x02F8A1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5535, 0},    // 0x02F8A2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5536, 0},    // 0x02F8A3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5537, 0},    // 0x02F8A4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5538, 0},    // 0x02F8A5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5539, 0},    // 0x02F8A6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5540, 0},    // 0x02F8A7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5541, 0},    // 0x02F8A8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5542, 0},    // 0x02F8A9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5543, 0},    // 0x02F8AA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5544, 0},    // 0x02F8AB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5545, 0},    // 0x02F8AC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5546, 0},    // 0x02F8AD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5547, 0},    // 0x02F8AE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5548, 0},    // 0x02F8AF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5549, 0},    // 0x02F8B0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5550, 0},    // 0x02F8B1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5551, 0},    // 0x02F8B2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5552, 0},    // 0x02F8B3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5553, 0},    // 0x02F8B4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5554, 0},    // 0x02F8B5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5555, 0},    // 0x02F8B6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5556, 0},    // 0x02F8B7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5557, 0},    // 0x02F8B8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5558, 0},    // 0x02F8B9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5559, 0},    // 0x02F8BA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5560, 0},    // 0x02F8BB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5561, 0},    // 0x02F8BC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5562, 0},    // 0x02F8BD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5563, 0},    // 0x02F8BE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5564, 0},    // 0x02F8BF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5565, 0},    // 0x02F8C0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5566, 0},    // 0x02F8C1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5567, 0},    // 0x02F8C2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5568, 0},    // 0x02F8C3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5569, 0},    // 0x02F8C4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5570, 0},    // 0x02F8C5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5571, 0},    // 0x02F8C6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5572, 0},    // 0x02F8C7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5573, 0},    // 0x02F8C8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5574, 0},    // 0x02F8C9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5575, 0},    // 0x02F8CA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5576, 0},    // 0x02F8CB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5577, 0},    // 0x02F8CC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5578, 0},    // 0x02F8CD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5579, 0},    // 0x02F8CE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5580, 0},    // 0x02F8CF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5581, 0},    // 0x02F8D0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5582, 0},    // 0x02F8D1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5583, 0},    // 0x02F8D2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5584, 0},    // 0x02F8D3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5585, 0},    // 0x02F8D4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5586, 0},    // 0x02F8D5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5587, 0},    // 0x02F8D6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5588, 0},    // 0x02F8D7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5589, 0},    // 0x02F8D8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5590, 0},    // 0x02F8D9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5591, 0},    // 0x02F8DA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5592, 0},    // 0x02F8DB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5593, 0},    // 0x02F8DC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5594, 0},    // 0x02F8DD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5595, 0},    // 0x02F8DE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5596, 0},    // 0x02F8DF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5597, 0},    // 0x02F8E0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5598, 0},    // 0x02F8E1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5599, 0},    // 0x02F8E2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5600, 0},    // 0x02F8E3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5601, 0},    // 0x02F8E4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5602, 0},    // 0x02F8E5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5603, 0},    // 0x02F8E6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5604, 0},    // 0x02F8E7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5605, 0},    // 0x02F8E8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5606, 0},    // 0x02F8E9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5607, 0},    // 0x02F8EA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5608, 0},    // 0x02F8EB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5609, 0},    // 0x02F8EC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5610, 0},    // 0x02F8ED
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5611, 0},    // 0x02F8EE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5612, 0},    // 0x02F8EF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5613, 0},    // 0x02F8F0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5614, 0},    // 0x02F8F1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5615, 0},    // 0x02F8F2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5616, 0},    // 0x02F8F3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5617, 0},    // 0x02F8F4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5618, 0},    // 0x02F8F5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5619, 0},    // 0x02F8F6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5620, 0},    // 0x02F8F7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5621, 0},    // 0x02F8F8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5622, 0},    // 0x02F8F9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5623, 0},    // 0x02F8FA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5624, 0},    // 0x02F8FB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5625, 0},    // 0x02F8FC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5626, 0},    // 0x02F8FD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5627, 0},    // 0x02F8FE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5628, 0},    // 0x02F8FF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5629, 0},    // 0x02F900
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5630, 0},    // 0x02F901
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5631, 0},    // 0x02F902
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5632, 0},    // 0x02F903
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5633, 0},    // 0x02F904
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5634, 0},    // 0x02F905
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5635, 0},    // 0x02F906
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5636, 0},    // 0x02F907
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5637, 0},    // 0x02F908
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5638, 0},    // 0x02F909
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5639, 0},    // 0x02F90A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5640, 0},    // 0x02F90B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5641, 0},    // 0x02F90C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5642, 0},    // 0x02F90D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5643, 0},    // 0x02F90E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5644, 0},    // 0x02F90F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5645, 0},    // 0x02F910
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5646, 0},    // 0x02F911
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5647, 0},    // 0x02F912
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5648, 0},    // 0x02F913
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5649, 0},    // 0x02F914
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5650, 0},    // 0x02F915
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5651, 0},    // 0x02F916
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5652, 0},    // 0x02F917
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5653, 0},    // 0x02F918
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5654, 0},    // 0x02F919
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5655, 0},    // 0x02F91A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5656, 0},    // 0x02F91B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5657, 0},    // 0x02F91C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5658, 0},    // 0x02F91D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5659, 0},    // 0x02F91E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5660, 0},    // 0x02F91F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5661, 0},    // 0x02F920
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5662, 0},    // 0x02F921
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5663, 0},    // 0x02F922
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5664, 0},    // 0x02F923
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5665, 0},    // 0x02F924
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5666, 0},    // 0x02F925
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5667, 0},    // 0x02F926
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5668, 0},    // 0x02F927
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5669, 0},    // 0x02F928
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5670, 0},    // 0x02F929
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5671, 0},    // 0x02F92A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5672, 0},    // 0x02F92B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5673, 0},    // 0x02F92C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5674, 0},    // 0x02F92D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5675, 0},    // 0x02F92E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5676, 0},    // 0x02F92F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5677, 0},    // 0x02F930
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5678, 0},    // 0x02F931
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5679, 0},    // 0x02F932
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5680, 0},    // 0x02F933
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5681, 0},    // 0x02F934
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5682, 0},    // 0x02F935
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5683, 0},    // 0x02F936
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5684, 0},    // 0x02F937
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5685, 0},    // 0x02F938
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5686, 0},    // 0x02F939
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5687, 0},    // 0x02F93A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5688, 0},    // 0x02F93B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5689, 0},    // 0x02F93C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5690, 0},    // 0x02F93D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5691, 0},    // 0x02F93E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5692, 0},    // 0x02F93F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5693, 0},    // 0x02F940
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5694, 0},    // 0x02F941
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5695, 0},    // 0x02F942
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5696, 0},    // 0x02F943
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5697, 0},    // 0x02F944
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5698, 0},    // 0x02F945
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5699, 0},    // 0x02F946
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5700, 0},    // 0x02F947
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5701, 0},    // 0x02F948
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5702, 0},    // 0x02F949
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5703, 0},    // 0x02F94A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5704, 0},    // 0x02F94B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5705, 0},    // 0x02F94C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5706, 0},    // 0x02F94D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5707, 0},    // 0x02F94E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5708, 0},    // 0x02F94F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5709, 0},    // 0x02F950
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5710, 0},    // 0x02F951
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5711, 0},    // 0x02F952
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5712, 0},    // 0x02F953
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5713, 0},    // 0x02F954
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5714, 0},    // 0x02F955
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5715, 0},    // 0x02F956
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5716, 0},    // 0x02F957
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5717, 0},    // 0x02F958
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5718, 0},    // 0x02F959
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5719, 0},    // 0x02F95A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5720, 0},    // 0x02F95B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5721, 0},    // 0x02F95C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5722, 0},    // 0x02F95D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5723, 0},    // 0x02F95E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5724, 0},    // 0x02F95F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5725, 0},    // 0x02F960
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5726, 0},    // 0x02F961
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5727, 0},    // 0x02F962
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5728, 0},    // 0x02F963
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5729, 0},    // 0x02F964
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5730, 0},    // 0x02F965
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5731, 0},    // 0x02F966
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5732, 0},    // 0x02F967
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5733, 0},    // 0x02F968
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5734, 0},    // 0x02F969
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5735, 0},    // 0x02F96A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5736, 0},    // 0x02F96B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5737, 0},    // 0x02F96C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5738, 0},    // 0x02F96D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5739, 0},    // 0x02F96E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5740, 0},    // 0x02F96F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5741, 0},    // 0x02F970
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5742, 0},    // 0x02F971
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5743, 0},    // 0x02F972
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5744, 0},    // 0x02F973
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5745, 0},    // 0x02F974
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5746, 0},    // 0x02F975
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5747, 0},    // 0x02F976
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5748, 0},    // 0x02F977
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5749, 0},    // 0x02F978
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5750, 0},    // 0x02F979
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5751, 0},    // 0x02F97A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5752, 0},    // 0x02F97B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5753, 0},    // 0x02F97C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5754, 0},    // 0x02F97D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5755, 0},    // 0x02F97E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5756, 0},    // 0x02F97F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5757, 0},    // 0x02F980
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5758, 0},    // 0x02F981
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5759, 0},    // 0x02F982
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5760, 0},    // 0x02F983
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5761, 0},    // 0x02F984
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5762, 0},    // 0x02F985
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5763, 0},    // 0x02F986
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5764, 0},    // 0x02F987
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5765, 0},    // 0x02F988
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5766, 0},    // 0x02F989
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5767, 0},    // 0x02F98A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5768, 0},    // 0x02F98B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5769, 0},    // 0x02F98C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5770, 0},    // 0x02F98D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5771, 0},    // 0x02F98E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5772, 0},    // 0x02F98F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5773, 0},    // 0x02F990
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5774, 0},    // 0x02F991
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5775, 0},    // 0x02F992
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5776, 0},    // 0x02F993
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5777, 0},    // 0x02F994
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5778, 0},    // 0x02F995
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5779, 0},    // 0x02F996
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5780, 0},    // 0x02F997
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5781, 0},    // 0x02F998
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5782, 0},    // 0x02F999
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5783, 0},    // 0x02F99A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5784, 0},    // 0x02F99B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5785, 0},    // 0x02F99C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5786, 0},    // 0x02F99D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5787, 0},    // 0x02F99E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5788, 0},    // 0x02F99F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5789, 0},    // 0x02F9A0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5790, 0},    // 0x02F9A1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5791, 0},    // 0x02F9A2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5792, 0},    // 0x02F9A3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5793, 0},    // 0x02F9A4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5794, 0},    // 0x02F9A5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5795, 0},    // 0x02F9A6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5796, 0},    // 0x02F9A7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5797, 0},    // 0x02F9A8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5798, 0},    // 0x02F9A9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5799, 0},    // 0x02F9AA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5800, 0},    // 0x02F9AB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5801, 0},    // 0x02F9AC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5802, 0},    // 0x02F9AD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5803, 0},    // 0x02F9AE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5804, 0},    // 0x02F9AF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5805, 0},    // 0x02F9B0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5806, 0},    // 0x02F9B1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5807, 0},    // 0x02F9B2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5808, 0},    // 0x02F9B3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5809, 0},    // 0x02F9B4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5810, 0},    // 0x02F9B5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5811, 0},    // 0x02F9B6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5812, 0},    // 0x02F9B7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5813, 0},    // 0x02F9B8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5814, 0},    // 0x02F9B9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5815, 0},    // 0x02F9BA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5816, 0},    // 0x02F9BB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5817, 0},    // 0x02F9BC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5818, 0},    // 0x02F9BD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5819, 0},    // 0x02F9BE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5820, 0},    // 0x02F9BF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5821, 0},    // 0x02F9C0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5822, 0},    // 0x02F9C1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5823, 0},    // 0x02F9C2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5824, 0},    // 0x02F9C3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5825, 0},    // 0x02F9C4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5826, 0},    // 0x02F9C5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5827, 0},    // 0x02F9C6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5828, 0},    // 0x02F9C7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5829, 0},    // 0x02F9C8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5830, 0},    // 0x02F9C9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5831, 0},    // 0x02F9CA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5832, 0},    // 0x02F9CB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5833, 0},    // 0x02F9CC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5834, 0},    // 0x02F9CD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5835, 0},    // 0x02F9CE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5836, 0},    // 0x02F9CF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5837, 0},    // 0x02F9D0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5838, 0},    // 0x02F9D1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5839, 0},    // 0x02F9D2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5840, 0},    // 0x02F9D3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5841, 0},    // 0x02F9D4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5842, 0},    // 0x02F9D5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5843, 0},    // 0x02F9D6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5844, 0},    // 0x02F9D7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5845, 0},    // 0x02F9D8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5846, 0},    // 0x02F9D9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5847, 0},    // 0x02F9DA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5848, 0},    // 0x02F9DB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5849, 0},    // 0x02F9DC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5850, 0},    // 0x02F9DD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5851, 0},    // 0x02F9DE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5852, 0},    // 0x02F9DF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5853, 0},    // 0x02F9E0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5854, 0},    // 0x02F9E1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5855, 0},    // 0x02F9E2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5856, 0},    // 0x02F9E3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5857, 0},    // 0x02F9E4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5858, 0},    // 0x02F9E5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5859, 0},    // 0x02F9E6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5860, 0},    // 0x02F9E7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5861, 0},    // 0x02F9E8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5862, 0},    // 0x02F9E9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5863, 0},    // 0x02F9EA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5864, 0},    // 0x02F9EB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5865, 0},    // 0x02F9EC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5866, 0},    // 0x02F9ED
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5867, 0},    // 0x02F9EE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5868, 0},    // 0x02F9EF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5869, 0},    // 0x02F9F0
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5870, 0},    // 0x02F9F1
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5871, 0},    // 0x02F9F2
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5872, 0},    // 0x02F9F3
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5873, 0},    // 0x02F9F4
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5874, 0},    // 0x02F9F5
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5875, 0},    // 0x02F9F6
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5876, 0},    // 0x02F9F7
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5877, 0},    // 0x02F9F8
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5878, 0},    // 0x02F9F9
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5879, 0},    // 0x02F9FA
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5880, 0},    // 0x02F9FB
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5881, 0},    // 0x02F9FC
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5882, 0},    // 0x02F9FD
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5883, 0},    // 0x02F9FE
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5884, 0},    // 0x02F9FF
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5885, 0},    // 0x02FA00
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5886, 0},    // 0x02FA01
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5887, 0},    // 0x02FA02
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5888, 0},    // 0x02FA03
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5889, 0},    // 0x02FA04
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5890, 0},    // 0x02FA05
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5891, 0},    // 0x02FA06
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5892, 0},    // 0x02FA07
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5893, 0},    // 0x02FA08
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5894, 0},    // 0x02FA09
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5895, 0},    // 0x02FA0A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5896, 0},    // 0x02FA0B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5897, 0},    // 0x02FA0C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5898, 0},    // 0x02FA0D
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5899, 0},    // 0x02FA0E
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5900, 0},    // 0x02FA0F
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5901, 0},    // 0x02FA10
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5902, 0},    // 0x02FA11
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5903, 0},    // 0x02FA12
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5904, 0},    // 0x02FA13
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5905, 0},    // 0x02FA14
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5906, 0},    // 0x02FA15
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5907, 0},    // 0x02FA16
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5908, 0},    // 0x02FA17
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5909, 0},    // 0x02FA18
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5910, 0},    // 0x02FA19
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5911, 0},    // 0x02FA1A
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5912, 0},    // 0x02FA1B
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5913, 0},    // 0x02FA1C
    {5, TINYUCD_GC_LO, 0, 0, 0, 0, 0, 5914, 0},    // 0x02FA1D
    {0, TINYUCD_GC_CF, 0, 4, 2, 0, 0, 0, 0},       // 96 codepoints in range [0x0E0020, 0x0E007F]
    {0, TINYUCD_GC_CN, 0, 3, 0, 0, 0, 0, 0},       // 3769 codepoints in range [0x2065, 0x0E0FFF]
    {0, TINYUCD_GC_CN, 0, 0, 0, 1, 0, 0, 0},       // 1453 codepoints in range [0x01F02C, 0x01FFFD]
};

static const uint16_t s_tinyucd_stage2_table[TINYUCD_NUM_STAGE2] = {
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    2,    1,    1,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    4,    5,    5,    5,    6,    5,    5,    5,    7,    8,    5,    9,    5,    10,   5,    5,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   5,    5,    12,   13,   14,   5,
    5,    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
    30,   31,   32,   33,   34,   35,   36,   37,   38,   39,   40,   7,    5,    8,    41,   42,
    41,   43,   44,   45,   46,   47,   48,   49,   50,   51,   52,   53,   54,   55,   56,   57,
    58,   59,   60,   61,   62,   63,   64,   65,   66,   67,   68,   7,    9,    8,    9,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    69,   5,    6,    6,    6,    6,    70,   5,    71,   72,   73,   74,   9,    75,   72,   76,
    70,   9,    77,   78,   79,   80,   5,    5,    81,   82,   83,   84,   85,   86,   87,   5,
    88,   89,   90,   91,   92,   93,   94,   95,   96,   97,   98,   99,   100,  101,  102,  103,
    104,  105,  106,  107,  108,  109,  110,  9,    111,  112,  113,  114,  115,  116,  117,  118,
    119,  120,  121,  122,  123,  124,  125,  126,  127,  128,  129,  130,  131,  132,  133,  134,
    135,  136,  137,  138,  139,  140,  141,  9,    142,  143,  144,  145,  146,  147,  148,  149,
    150,  151,  152,  153,  154,  155,  156,  157,  158,  159,  160,  161,  162,  163,  164,  165,
    166,  167,  168,  169,  170,  171,  172,  173,  174,  175,  176,  177,  178,  179,  180,  181,
    182,  183,  184,  185,  186,  187,  188,  189,  190,  191,  192,  193,  194,  195,  196,  197,
    198,  199,  200,  201,  202,  203,  204,  205,  206,  207,  208,  209,  210,  211,  212,  213,
    214,  215,  216,  217,  218,  219,  220,  221,  222,  223,  224,  225,  226,  227,  228,  229,
    230,  231,  232,  233,  234,  235,  236,  237,  238,  239,  240,  241,  242,  243,  244,  245,
    246,  247,  248,  249,  250,  251,  252,  253,  254,  255,  256,  257,  258,  259,  260,  261,
    262,  263,  264,  265,  266,  267,  268,  269,  270,  271,  272,  273,  274,  275,  276,  277,
    278,  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,  289,  290,  206,  291,  292,
    293,  294,  295,  296,  297,  298,  299,  300,  301,  302,  303,  304,  305,  306,  307,  308,
    309,  310,  311,  312,  313,  314,  315,  316,  317,  318,  206,  206,  319,  320,  321,  322,
    323,  324,  325,  326,  327,  328,  329,  330,  331,  332,  206,  333,  334,  335,  206,  336,
    333,  333,  333,  333,  337,  338,  339,  340,  341,  342,  343,  344,  345,  346,  347,  348,
    349,  350,  351,  352,  353,  354,  355,  356,  357,  358,  359,  360,  361,  362,  363,  364,
    365,  366,  367,  368,  369,  370,  371,  372,  373,  374,  375,  376,  377,  378,  379,  380,
    381,  382,  383,  384,  385,  386,  387,  388,  389,  390,  391,  392,  393,  394,  395,  396,
    397,  398,  399,  400,  401,  402,  403,  404,  405,  406,  407,  408,  409,  410,  411,  412,
    413,  414,  415,  416,  417,  418,  419,  420,  421,  422,  423,  424,  425,  426,  427,  428,
    429,  206,  430,  431,  432,  433,  434,  435,  436,  437,  438,  439,  440,  441,  442,  443,
    444,  445,  446,  447,  206,  206,  206,  206,  206,  206,  448,  449,  450,  451,  452,  453,
    454,  455,  456,  457,  458,  459,  460,  461,  462,  463,  464,  465,  466,  467,  468,  469,
    470,  471,  472,  473,  474,  206,  475,  476,  206,  477,  206,  478,  479,  206,  206,  206,
    480,  481,  206,  482,  483,  484,  485,  206,  486,  487,  488,  489,  490,  206,  206,  491,
    206,  492,  493,  206,  206,  494,  206,  206,  206,  206,  206,  206,  206,  495,  206,  206,
    496,  206,  497,  498,  206,  206,  206,  499,  500,  501,  502,  503,  504,  206,  206,  206,
    206,  206,  505,  206,  333,  333,  206,  206,  206,  206,  206,  206,  206,  506,  507,  206,
    206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,
    508,  509,  510,  511,  512,  513,  514,  515,  516,  517,  517,  517,  517,  517,  517,  517,
    517,  517,  41,   41,   41,   41,   517,  517,  517,  517,  517,  517,  517,  517,  517,  517,
    517,  517,  41,   41,   41,   41,   41,   41,   518,  519,  520,  521,  522,  523,  41,   41,
    524,  525,  526,  527,  528,  41,   41,   41,   41,   41,   41,   41,   517,  41,   517,  41,
    41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,
    529,  529,  529,  529,  529,  530,  529,  529,  529,  529,  529,  529,  529,  530,  530,  529,
    530,  529,  530,  529,  529,  531,  532,  532,  532,  532,  531,  533,  532,  532,  532,  532,
    532,  534,  534,  535,  535,  535,  535,  536,  536,  532,  532,  532,  532,  535,  535,  532,
    535,  535,  532,  532,  537,  537,  537,  537,  538,  532,  532,  532,  532,  530,  530,  530,
    539,  540,  529,  541,  542,  543,  530,  532,  532,  532,  530,  530,  530,  532,  532,  544,
    530,  530,  530,  532,  532,  532,  532,  530,  531,  532,  532,  530,  545,  546,  546,  545,
    546,  546,  545,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,
    547,  548,  549,  550,  551,  41,   552,  553,  0,    0,    554,  555,  556,  557,  558,  559,
    0,    0,    0,    0,    560,  561,  562,  563,  564,  565,  566,  0,    567,  0,    568,  569,
    570,  571,  572,  573,  574,  575,  576,  577,  578,  579,  580,  581,  582,  583,  584,  585,
    586,  587,  0,    588,  589,  590,  591,  592,  593,  594,  595,  596,  597,  598,  599,  600,
    601,  602,  603,  604,  605,  606,  607,  608,  609,  610,  611,  612,  613,  614,  615,  616,
    617,  618,  619,  620,  621,  622,  623,  624,  625,  626,  627,  628,  629,  630,  631,  632,
    633,  634,  635,  636,  637,  638,  639,  640,  641,  642,  643,  644,  645,  646,  647,  648,
    649,  650,  651,  652,  653,  654,  655,  656,  657,  658,  659,  660,  661,  662,  663,  664,
    665,  666,  667,  668,  669,  670,  9,    671,  672,  673,  674,  675,  206,  676,  677,  678,
    679,  680,  681,  682,  683,  684,  685,  686,  687,  688,  689,  690,  691,  692,  693,  694,
    695,  696,  697,  698,  699,  700,  701,  702,  703,  704,  705,  706,  707,  708,  709,  710,
    711,  712,  713,  714,  715,  716,  717,  718,  719,  720,  721,  722,  723,  724,  725,  726,
    727,  728,  729,  730,  731,  732,  733,  734,  735,  736,  737,  738,  739,  740,  741,  742,
    743,  744,  745,  746,  747,  748,  749,  750,  751,  752,  753,  754,  755,  756,  757,  758,
    759,  760,  761,  762,  763,  764,  765,  766,  767,  768,  769,  770,  771,  772,  773,  774,
    775,  776,  777,  778,  779,  780,  781,  782,  783,  784,  785,  786,  787,  788,  789,  790,
    791,  792,  793,  794,  795,  796,  797,  798,  799,  800,  801,  802,  803,  804,  805,  806,
    807,  808,  70,   530,  530,  530,  530,  530,  809,  809,  810,  811,  812,  813,  814,  815,
    816,  817,  818,  819,  820,  821,  822,  823,  824,  825,  826,  827,  828,  829,  830,  831,
    832,  833,  834,  835,  836,  837,  838,  839,  840,  841,  842,  843,  844,  845,  846,  847,
    848,  849,  850,  851,  852,  853,  854,  855,  856,  857,  858,  859,  860,  861,  862,  863,
    864,  865,  866,  867,  868,  869,  870,  871,  872,  873,  874,  875,  876,  877,  878,  879,
    880,  881,  882,  883,  884,  885,  886,  887,  888,  889,  890,  891,  892,  893,  894,  895,
    896,  897,  898,  899,  900,  901,  902,  903,  904,  905,  906,  907,  908,  909,  910,  911,
    912,  913,  914,  915,  916,  917,  918,  919,  920,  921,  922,  923,  924,  925,  926,  927,
    928,  929,  930,  931,  932,  933,  934,  935,  936,  937,  938,  939,  940,  941,  942,  943,
    944,  945,  946,  947,  948,  949,  950,  951,  952,  953,  954,  955,  956,  957,  958,  959,
    960,  961,  962,  963,  964,  965,  966,  967,  968,  969,  970,  971,  972,  973,  974,  975,
    0,    976,  977,  978,  979,  980,  981,  982,  983,  984,  985,  986,  987,  988,  989,  990,
    991,  992,  993,  994,  995,  996,  997,  998,  999,  1000, 1001, 1002, 1003, 1004, 1005, 1006,
    1007, 1008, 1009, 1010, 1011, 1012, 1013, 0,    0,    517,  5,    5,    5,    5,    5,    5,
    206,  1014, 1015, 1016, 1017, 1018, 1019, 1020, 1021, 1022, 1023, 1024, 1025, 1026, 1027, 1028,
    1029, 1030, 1031, 1032, 1033, 1034, 1035, 1036, 1037, 1038, 1039, 1040, 1041, 1042, 1043, 1044,
    1045, 1046, 1047, 1048, 1049, 1050, 1051, 1052, 206,  5,    10,   0,    0,    70,   70,   6,
    0,    532,  530,  530,  530,  530,  532,  530,  530,  530,  1053, 532,  530,  530,  530,  530,
    530,  530,  532,  532,  532,  532,  532,  532,  530,  530,  532,  530,  530,  1053, 1054, 530,
    1055, 1056, 1057, 1058, 1059, 1060, 1061, 1062, 1063, 1064, 1064, 1065, 1066, 1067, 10,   1068,
    5,    1069, 1070, 5,    530,  532,  5,    1063, 0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    333,
    333,  333,  333,  5,    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1071, 1071, 1071, 1071, 1071, 1071, 9,    9,    9,    5,    5,    6,    5,    5,    70,   70,
    530,  530,  530,  530,  530,  530,  530,  530,  1072, 1073, 1074, 5,    75,   5,    5,    5,
    333,  333,  1075, 1076, 1077, 1078, 1079, 1080, 333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    517,  333,  333,  333,  333,  333,  333,  333,  1081, 333,  1082, 1083, 1084, 1085, 1072, 1073,
    1074, 1086, 1087, 529,  529,  535,  532,  530,  530,  530,  530,  530,  532,  530,  530,  532,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   5,    5,    5,    5,    333,  333,
    1088, 333,  333,  333,  333,  1089, 1090, 1091, 1092, 333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    1093, 1094, 1095, 333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  1096, 1097, 5,    1098, 530,  530,  530,  530,  530,  530,  530,  1071, 70,   530,
    530,  530,  530,  532,  530,  517,  517,  530,  530,  70,   532,  530,  530,  532,  333,  333,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   333,  333,  333,  70,   70,   333,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    0,    1071,
    333,  1099, 333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    530,  532,  530,  530,  532,  530,  530,  532,  532,  532,  530,  532,  532,  530,  532,  530,
    530,  530,  532,  530,  532,  530,  532,  530,  532,  530,  530,  0,    0,    333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  530,  530,  530,  530,  530,
    530,  530,  532,  530,  517,  517,  70,   5,    5,    5,    517,  0,    0,    532,  6,    6,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  530,  530,  530,  530,  517,  530,  530,  530,  530,  530,
    530,  530,  530,  530,  517,  530,  530,  530,  517,  530,  530,  530,  530,  530,  0,    0,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  532,  532,  532,  0,    0,    5,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  41,   333,  333,  333,  333,  333,  333,  333,
    1071, 1071, 0,    0,    0,    0,    0,    530,  530,  532,  532,  532,  530,  530,  530,  530,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  517,  530,  530,  530,  530,  530,  532,
    532,  532,  532,  532,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,
    530,  530,  1071, 532,  530,  530,  532,  530,  530,  532,  530,  530,  530,  532,  532,  532,
    1083, 1084, 1085, 530,  530,  530,  532,  530,  530,  532,  532,  530,  530,  530,  530,  530,
    544,  544,  544,  1100, 333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1102, 1103, 1101, 1101, 1101, 1101, 1101, 1101,
    1104, 1105, 1101, 1106, 1107, 1101, 1101, 1101, 1101, 1101, 544,  1100, 1108, 333,  1100, 1100,
    1100, 544,  544,  544,  544,  544,  544,  544,  544,  1100, 1100, 1100, 1100, 1109, 1100, 1100,
    333,  530,  532,  530,  530,  544,  544,  544,  1110, 1111, 1112, 1113, 1114, 1115, 1116, 1117,
    333,  333,  544,  544,  5,    5,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    5,    517,  333,  333,  333,  333,  333,  333,  1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    333,  544,  1100, 1100, 0,    333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    333,
    333,  0,    0,    333,  333,  1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 0,    1101, 1101, 1101, 1101, 1101, 1101,
    1101, 0,    1101, 0,    0,    0,    1101, 1101, 1101, 1101, 0,    0,    1118, 333,  1119, 1100,
    1100, 544,  544,  544,  544,  0,    0,    1120, 1100, 0,    0,    1121, 1122, 1109, 333,  0,
    0,    0,    0,    0,    0,    0,    0,    1119, 0,    0,    0,    0,    1123, 1124, 0,    1125,
    333,  333,  544,  544,  0,    0,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    1101, 1101, 6,    6,    1126, 1126, 1126, 1126, 1126, 1126, 70,   6,    333,  5,    530,  0,
    0,    544,  544,  1100, 0,    333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    333,
    333,  0,    0,    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  333,
    333,  0,    333,  1127, 0,    333,  1128, 0,    333,  333,  0,    0,    1118, 0,    1100, 1100,
    1100, 544,  544,  0,    0,    0,    0,    544,  544,  0,    0,    544,  544,  1129, 0,    0,
    0,    544,  0,    0,    0,    0,    0,    0,    0,    1130, 1131, 1132, 333,  0,    1133, 0,
    0,    0,    0,    0,    0,    0,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    544,  544,  333,  333,  333,  544,  5,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    544,  544,  1100, 0,    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,
    333,  333,  0,    333,  333,  1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 0,    1101, 1101, 1101, 1101, 1101, 1101,
    1101, 0,    1101, 1101, 0,    1101, 1101, 1101, 1101, 1101, 0,    0,    1118, 333,  1100, 1100,
    1100, 544,  544,  544,  544,  544,  0,    544,  544,  1100, 0,    1100, 1100, 1109, 0,    0,
    333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  544,  544,  0,    0,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    5,    6,    0,    0,    0,    0,    0,    0,    0,    1101, 544,  544,  544,  544,  544,  544,
    0,    544,  1100, 1100, 0,    333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    333,
    333,  0,    0,    333,  333,  1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 0,    1101, 1101, 1101, 1101, 1101, 1101,
    1101, 0,    1101, 1101, 0,    1101, 1101, 1101, 1101, 1101, 0,    0,    1118, 333,  1119, 544,
    1100, 544,  544,  544,  544,  0,    0,    1134, 1135, 0,    0,    1136, 1137, 1109, 0,    0,
    0,    0,    0,    0,    0,    544,  1138, 1119, 0,    0,    0,    0,    1139, 1140, 0,    1101,
    333,  333,  544,  544,  0,    0,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    70,   1101, 1126, 1126, 1126, 1126, 1126, 1126, 0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    544,  333,  0,    333,  333,  333,  333,  333,  333,  0,    0,    0,    333,  333,
    333,  0,    1141, 333,  1142, 333,  0,    0,    0,    333,  333,  0,    333,  0,    333,  333,
    0,    0,    0,    333,  333,  0,    0,    0,    333,  333,  333,  0,    0,    0,    333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    1119, 1100,
    544,  1100, 1100, 0,    0,    0,    1143, 1144, 1100, 0,    1145, 1146, 1147, 1129, 0,    0,
    333,  0,    0,    0,    0,    0,    0,    1119, 0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    1126, 1126, 1126, 70,   70,   70,   70,   70,   70,   6,    70,   0,    0,    0,    0,    0,
    544,  1100, 1100, 1100, 544,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,
    333,  0,    333,  333,  333,  1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 0,    1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 0,    0,    1118, 333,  544,  544,
    544,  1100, 1100, 1100, 1100, 0,    1148, 544,  1149, 0,    544,  544,  544,  1109, 0,    0,
    0,    0,    0,    0,    0,    1150, 1151, 0,    1101, 1101, 1101, 0,    333,  333,  0,    0,
    333,  333,  544,  544,  0,    0,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    0,    0,    0,    0,    0,    0,    0,    5,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 70,
    333,  544,  1100, 1100, 5,    333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,
    333,  0,    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  0,    0,    1118, 333,  1100, 1152,
    1153, 1100, 1119, 1100, 1100, 0,    1154, 1155, 1156, 0,    1157, 1158, 544,  1129, 0,    0,
    0,    0,    0,    0,    0,    1119, 1119, 0,    0,    0,    0,    0,    333,  333,  333,  0,
    333,  333,  544,  544,  0,    0,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    0,    333,  333,  1100, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    544,  544,  1100, 1100, 333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,
    333,  0,    333,  333,  333,  1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1129, 1129, 333,  1119, 1100,
    1100, 544,  544,  544,  544,  0,    1159, 1160, 1100, 0,    1161, 1162, 1163, 1109, 1164, 70,
    0,    0,    0,    0,    333,  333,  333,  1119, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 333,
    333,  333,  544,  544,  0,    0,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 70,   333,  333,  333,  333,  333,  333,
    0,    544,  1100, 1100, 0,    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  0,    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  0,    0,
    333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    1165, 0,    0,    0,    0,    1119,
    1100, 1100, 544,  544,  544,  0,    544,  0,    1100, 1166, 1167, 1100, 1168, 1169, 1170, 1119,
    0,    0,    0,    0,    0,    0,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    0,    0,    1100, 1100, 5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  544,  333,  1171, 544,  544,  544,  544,  1172, 1172, 1129, 0,    0,    0,    0,    6,
    333,  333,  333,  333,  333,  333,  517,  544,  1173, 1173, 1173, 1173, 544,  544,  544,  5,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   5,    5,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    333,  333,  0,    333,  0,    333,  333,  333,  333,  333,  0,    333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  0,    333,  0,    333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  544,  333,  1174, 544,  544,  544,  544,  1175, 1175, 1129, 544,  544,  333,  0,    0,
    333,  333,  333,  333,  333,  0,    517,  0,    1176, 1176, 1176, 1176, 544,  544,  544,  0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    1177, 1178, 333,  333,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  70,   70,   70,   5,    5,    5,    5,    5,    5,    5,    5,    1179, 5,    5,    5,
    5,    5,    5,    70,   5,    70,   70,   70,   532,  532,  70,   70,   70,   70,   70,   70,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 70,   532,  70,   532,  70,   1180, 7,    8,    7,    8,    1100, 1100,
    333,  333,  333,  1181, 333,  333,  333,  333,  0,    333,  333,  333,  333,  1182, 333,  333,
    333,  333,  1183, 333,  333,  333,  333,  1184, 333,  333,  333,  333,  1185, 333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  1186, 333,  333,  333,  0,    0,    0,
    0,    1187, 1188, 1189, 1190, 1191, 1192, 1193, 1194, 1195, 1188, 1188, 1188, 1188, 544,  1100,
    1188, 1196, 530,  530,  1129, 5,    530,  530,  333,  333,  333,  333,  333,  544,  544,  544,
    544,  544,  544,  1197, 544,  544,  544,  544,  0,    544,  544,  544,  544,  1198, 544,  544,
    544,  544,  1199, 544,  544,  544,  544,  1200, 544,  544,  544,  544,  1201, 544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  1202, 544,  544,  544,  0,    70,   70,
    70,   70,   70,   70,   70,   70,   532,  70,   70,   70,   70,   70,   70,   0,    70,   70,
    5,    5,    5,    5,    5,    70,   70,   70,   70,   5,    5,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1203, 1204, 1101, 1101, 1101, 1101, 1205, 1205, 544,  1138, 544,
    544,  1100, 544,  544,  544,  544,  544,  1118, 1205, 1109, 1129, 1100, 1100, 544,  544,  1101,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   5,    5,    5,    5,    5,    5,
    1101, 1101, 1101, 1101, 1101, 1101, 1100, 1100, 544,  544,  1101, 1101, 1101, 1101, 544,  544,
    544,  1101, 1205, 1205, 1205, 1101, 1101, 1205, 1205, 1205, 1205, 1205, 1205, 1205, 1101, 1101,
    1101, 544,  544,  544,  544,  1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 544,  1205, 1100, 544,  544,  1205, 1205, 1205, 1205, 1205, 1205, 532,  1101, 1205,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   1205, 1205, 1205, 544,  70,   70,
    1206, 1207, 1208, 1209, 1210, 1211, 1212, 1213, 1214, 1215, 1216, 1217, 1218, 1219, 1220, 1221,
    1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229, 1230, 1231, 1232, 1233, 1234, 1235, 1236, 1237,
    1238, 1239, 1240, 1241, 1242, 1243, 0,    1244, 0,    0,    0,    0,    0,    1245, 0,    0,
    1246, 1247, 1248, 1249, 1250, 1251, 1252, 1253, 1254, 1255, 1256, 1257, 1258, 1259, 1260, 1261,
    1262, 1263, 1264, 1265, 1266, 1267, 1268, 1269, 1270, 1271, 1272, 1273, 1274, 1275, 1276, 1277,
    1278, 1279, 1280, 1281, 1282, 1283, 1284, 1285, 1286, 1287, 1288, 5,    1289, 1290, 1291, 1292,
    1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293,
    1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293,
    1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293,
    1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293,
    1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293,
    1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293,
    1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294,
    1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294,
    1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294,
    1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294,
    1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295,
    1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295,
    1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295,
    1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295,
    1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295,
    1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  0,    0,
    333,  333,  333,  333,  333,  333,  333,  0,    333,  0,    333,  333,  333,  333,  0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  0,    333,  333,  333,  333,  0,    0,    333,  333,  333,  333,  333,  333,  333,  0,
    333,  0,    333,  333,  333,  333,  0,    0,    333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  0,    333,  333,  333,  333,  0,    0,    333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    530,  530,  530,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   0,    0,    0,    0,    0,    0,
    1296, 1297, 1298, 1299, 1300, 1301, 1302, 1303, 1304, 1305, 1306, 1307, 1308, 1309, 1310, 1311,
    1312, 1313, 1314, 1315, 1316, 1317, 1318, 1319, 1320, 1321, 1322, 1323, 1324, 1325, 1326, 1327,
    1328, 1329, 1330, 1331, 1332, 1333, 1334, 1335, 1336, 1337, 1338, 1339, 1340, 1341, 1342, 1343,
    1344, 1345, 1346, 1347, 1348, 1349, 1350, 1351, 1352, 1353, 1354, 1355, 1356, 1357, 1358, 1359,
    1360, 1361, 1362, 1363, 1364, 1365, 1366, 1367, 1368, 1369, 1370, 1371, 1372, 1373, 1374, 1375,
    1376, 1377, 1378, 1379, 1380, 1381, 0,    0,    1382, 1383, 1384, 1385, 1386, 1387, 0,    0,
    10,   333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  70,   5,    333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    4,    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  7,    8,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  5,    5,    5,    1388, 1388,
    1388, 333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  544,  544,  1129, 1389, 0,    0,    0,    0,    0,    0,    0,    0,    0,    333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  544,  544,  1389, 5,    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  544,  544,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,
    333,  0,    544,  544,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 544,  544,  1100, 544,  544,  544,  544,  544,  544,  544,  1100, 1100,
    1100, 1100, 1100, 1100, 1100, 1100, 544,  1100, 1100, 544,  544,  544,  544,  544,  544,  544,
    544,  544,  1109, 544,  5,    5,    5,    517,  5,    5,    5,    6,    333,  530,  0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 0,    0,    0,    0,    0,    0,
    5,    5,    5,    5,    5,    5,    10,   5,    5,    5,    5,    544,  544,  544,  75,   544,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  517,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  544,  544,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  1054, 333,  0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,
    544,  544,  544,  1100, 1100, 1100, 1100, 544,  544,  1100, 1100, 1100, 0,    0,    0,    0,
    1100, 1100, 544,  1100, 1100, 1100, 1100, 1100, 1100, 1053, 530,  532,  0,    0,    0,    0,
    70,   0,    0,    0,    5,    5,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,
    333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   1126, 0,    0,    0,    70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  530,  532,  1100, 1100, 544,  0,    0,    5,    5,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1100, 544,  1100, 544,  544,  544,  544,  544,  544,  544,  0,
    1109, 1205, 544,  1205, 1205, 544,  544,  544,  544,  544,  544,  544,  544,  1100, 1100, 1100,
    1100, 1100, 1100, 544,  544,  530,  530,  530,  530,  530,  530,  530,  530,  0,    0,    532,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    5,    5,    5,    5,    5,    5,    5,    517,  5,    5,    5,    5,    5,    5,    0,    0,
    530,  530,  530,  530,  530,  532,  532,  532,  532,  532,  532,  530,  530,  532,  809,  532,
    532,  530,  530,  532,  532,  530,  530,  530,  530,  530,  532,  530,  530,  530,  530,  530,
    530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  532,  0,    0,
    530,  530,  530,  530,  530,  530,  532,  530,  530,  530,  530,  546,  0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    544,  544,  544,  544,  1100, 1390, 1391, 1392, 1393, 1394, 1395, 1396, 1397, 1398, 1399, 333,
    333,  1400, 1401, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1118, 1119, 544,  544,  544,  544,  1402, 1403, 1404, 1405, 1406, 1407,
    1408, 1409, 1410, 1411, 1412, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 0,    5,    5,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   5,    5,    5,    5,    5,    5,
    5,    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   530,  532,  530,  530,  530,
    530,  530,  530,  530,  70,   70,   70,   70,   70,   70,   70,   70,   70,   5,    5,    5,
    544,  544,  1100, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1100, 544,  544,  544,  544,  1100, 1100, 544,  544,  1389, 1109, 544,  544,  1101, 1101,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   333,  1101, 1101, 1101, 333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  1118, 1100, 544,  544,  1100, 1100, 1100, 544,  1100, 544,
    544,  544,  1389, 1389, 0,    0,    0,    0,    0,    0,    0,    0,    5,    5,    5,    5,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 544,  544,  544,  544,
    544,  544,  544,  544,  1100, 1100, 544,  1118, 0,    0,    0,    5,    5,    5,    5,    5,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    333,  333,  333,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  517,  517,  517,  517,  517,  517,  5,    5,
    1413, 1414, 1415, 1416, 1417, 1418, 1419, 1420, 1421, 1422, 1423, 0,    0,    0,    0,    0,
    1424, 1425, 1426, 1427, 1428, 1429, 1430, 1431, 1432, 1433, 1434, 1435, 1436, 1437, 1438, 1439,
    1440, 1441, 1442, 1443, 1444, 1445, 1446, 1447, 1448, 1449, 1450, 1451, 1452, 1453, 1454, 1455,
    1456, 1457, 1458, 1459, 1460, 1461, 1462, 1463, 1464, 1465, 1466, 0,    0,    1467, 1468, 1469,
    5,    5,    5,    5,    5,    5,    5,    5,    0,    0,    0,    0,    0,    0,    0,    0,
    530,  530,  530,  5,    537,  532,  532,  532,  532,  532,  530,  530,  532,  532,  532,  532,
    530,  1100, 537,  537,  537,  537,  537,  537,  537,  333,  333,  333,  333,  532,  333,  333,
    333,  333,  333,  333,  530,  333,  333,  1100, 530,  530,  333,  0,    0,    0,    0,    0,
    206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,
    206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,
    206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  1470, 1471, 1472, 517,
    1473, 1474, 1475, 1476, 1477, 1478, 1479, 1480, 1481, 1482, 1483, 517,  1484, 1485, 1486, 1487,
    1488, 1489, 1490, 1491, 1492, 1493, 1494, 1495, 1496, 1497, 1498, 1499, 1500, 1501, 517,  1502,
    1503, 1504, 1505, 1506, 1507, 1508, 1509, 1510, 1511, 1512, 1513, 1514, 1515, 1516, 1517, 1518,
    1519, 1520, 1521, 1522, 1523, 1524, 1525, 1526, 1527, 1528, 1529, 206,  206,  206,  206,  206,
    206,  206,  206,  206,  206,  206,  206,  206,  1530, 1531, 206,  206,  206,  1532, 206,  206,
    206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  1533, 206,
    206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  1534, 1535, 1536, 1537, 1538,
    1539, 1540, 1541, 1542, 1543, 1544, 1545, 1546, 1547, 1548, 1549, 1550, 1551, 1552, 1553, 1554,
    1555, 1556, 1557, 1558, 1559, 1560, 1561, 1562, 1563, 1564, 1565, 1566, 1567, 1568, 1569, 1570,
    530,  530,  532,  530,  530,  530,  530,  530,  530,  530,  532,  530,  530,  546,  1571, 532,
    534,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,
    530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,
    530,  530,  530,  530,  530,  530,  531,  1054, 1054, 532,  1572, 530,  545,  532,  530,  532,
    1573, 1574, 1575, 1576, 1577, 1578, 1579, 1580, 1581, 1582, 1583, 1584, 1585, 1586, 1587, 1588,
    1589, 1590, 1591, 1592, 1593, 1594, 1595, 1596, 1597, 1598, 1599, 1600, 1601, 1602, 1603, 1604,
    1605, 1606, 1607, 1608, 1609, 1610, 1611, 1612, 1613, 1614, 1615, 1616, 1617, 1618, 1619, 1620,
    1621, 1622, 1623, 1624, 1625, 1626, 1627, 1628, 1629, 1630, 1631, 1632, 1633, 1634, 1635, 1636,
    1637, 1638, 1639, 1640, 1641, 1642, 1643, 1644, 1645, 1646, 1647, 1648, 1649, 1650, 1651, 1652,
    1653, 1654, 1655, 1656, 1657, 1658, 1659, 1660, 1661, 1662, 1663, 1664, 1665, 1666, 1667, 1668,
    1669, 1670, 1671, 1672, 1673, 1674, 1675, 1676, 1677, 1678, 1679, 1680, 1681, 1682, 1683, 1684,
    1685, 1686, 1687, 1688, 1689, 1690, 1691, 1692, 1693, 1694, 1695, 1696, 1697, 1698, 1699, 1700,
    1701, 1702, 1703, 1704, 1705, 1706, 1707, 1708, 1709, 1710, 1711, 1712, 1713, 1714, 1715, 1716,
    1717, 1718, 1719, 1720, 1721, 1722, 1723, 1724, 1725, 1726, 1727, 1728, 206,  206,  1729, 206,
    1730, 1731, 1732, 1733, 1734, 1735, 1736, 1737, 1738, 1739, 1740, 1741, 1742, 1743, 1744, 1745,
    1746, 1747, 1748, 1749, 1750, 1751, 1752, 1753, 1754, 1755, 1756, 1757, 1758, 1759, 1760, 1761,
    1762, 1763, 1764, 1765, 1766, 1767, 1768, 1769, 1770, 1771, 1772, 1773, 1774, 1775, 1776, 1777,
    1778, 1779, 1780, 1781, 1782, 1783, 1784, 1785, 1786, 1787, 1788, 1789, 1790, 1791, 1792, 1793,
    1794, 1795, 1796, 1797, 1798, 1799, 1800, 1801, 1802, 1803, 1804, 1805, 1806, 1807, 1808, 1809,
    1810, 1811, 1812, 1813, 1814, 1815, 1816, 1817, 1818, 1819, 1820, 1821, 1822, 1823, 1824, 1825,
    1826, 1827, 1828, 1829, 1830, 1831, 1832, 1833, 1834, 1835, 1836, 1837, 1838, 1839, 1840, 1841,
    1842, 1843, 1844, 1845, 1846, 1847, 0,    0,    1848, 1849, 1850, 1851, 1852, 1853, 0,    0,
    1854, 1855, 1856, 1857, 1858, 1859, 1860, 1861, 1862, 1863, 1864, 1865, 1866, 1867, 1868, 1869,
    1870, 1871, 1872, 1873, 1874, 1875, 1876, 1877, 1878, 1879, 1880, 1881, 1882, 1883, 1884, 1885,
    1886, 1887, 1888, 1889, 1890, 1891, 0,    0,    1892, 1893, 1894, 1895, 1896, 1897, 0,    0,
    1898, 1899, 1900, 1901, 1902, 1903, 1904, 1905, 0,    1906, 0,    1907, 0,    1908, 0,    1909,
    1910, 1911, 1912, 1913, 1914, 1915, 1916, 1917, 1918, 1919, 1920, 1921, 1922, 1923, 1924, 1925,
    1926, 1927, 1928, 1929, 1930, 1931, 1932, 1933, 1934, 1935, 1936, 1937, 1938, 1939, 0,    0,
    1940, 1941, 1942, 1943, 1944, 1945, 1946, 1947, 1948, 1949, 1950, 1951, 1952, 1953, 1954, 1955,
    1956, 1957, 1958, 1959, 1960, 1961, 1962, 1963, 1964, 1965, 1966, 1967, 1968, 1969, 1970, 1971,
    1972, 1973, 1974, 1975, 1976, 1977, 1978, 1979, 1980, 1981, 1982, 1983, 1984, 1985, 1986, 1987,
    1988, 1989, 1990, 1991, 1992, 0,    1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,
    2003, 2004, 2005, 2006, 2007, 0,    2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016, 2017,
    2018, 2019, 2020, 2021, 0,    0,    2022, 2023, 2024, 2025, 2026, 2027, 0,    2028, 2029, 2030,
    2031, 2032, 2033, 2034, 2035, 2036, 2037, 2038, 2039, 2040, 2041, 2042, 2043, 2044, 2045, 2046,
    0,    0,    2047, 2048, 2049, 0,    2050, 2051, 2052, 2053, 2054, 2055, 2056, 2057, 2058, 0,
    2059, 2060, 2061, 2062, 2063, 2064, 2065, 2066, 2067, 2068, 2069, 75,   2070, 2071, 75,   75,
    10,   2072, 10,   10,   10,   10,   5,    2073, 74,   84,   7,    74,   74,   84,   7,    74,
    5,    5,    5,    5,    2074, 2075, 2076, 5,    2077, 2078, 75,   75,   75,   75,   75,   2079,
    5,    5,    5,    2080, 2081, 5,    2082, 2083, 5,    74,   84,   5,    2084, 5,    2085, 42,
    42,   5,    5,    5,    9,    7,    8,    2086, 2087, 2088, 5,    5,    5,    5,    5,    5,
    5,    5,    9,    5,    42,   5,    5,    2089, 5,    5,    5,    5,    5,    5,    5,    2090,
    75,   75,   75,   75,   75,   8242, 75,   75,   75,   75,   75,   75,   75,   75,   75,   75,
    2091, 2092, 0,    0,    2093, 2094, 2095, 2096, 2097, 2098, 2099, 2100, 2101, 2102, 2103, 2104,
    2105, 2106, 2107, 2108, 2109, 2110, 2111, 2112, 2113, 2114, 2115, 2116, 2117, 2118, 2119, 0,
    2120, 2121, 2122, 2123, 2124, 2125, 2126, 2127, 2128, 2129, 2130, 2131, 2132, 0,    0,    0,
    6,    6,    6,    6,    6,    6,    6,    6,    2133, 6,    6,    6,    6,    6,    6,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    6,    6,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    530,  530,  537,  537,  530,  530,  530,  530,  537,  537,  537,  530,  530,  809,  809,  809,
    809,  530,  809,  809,  809,  537,  537,  530,  532,  530,  537,  537,  532,  532,  532,  532,
    530,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2134, 2135, 2136, 2137, 70,   2138, 2139, 2140, 70,   2141, 2142, 2143, 2144, 2145, 2146, 2147,
    2148, 2149, 2150, 2151, 70,   2152, 2153, 70,   9,    2154, 2155, 2156, 2157, 2158, 70,   70,
    2159, 2160, 2161, 70,   2162, 70,   2163, 70,   2164, 70,   2165, 2166, 2167, 2168, 70,   2169,
    2170, 2171, 2172, 2173, 2174, 2175, 2176, 2177, 2178, 2179, 70,   2180, 2181, 2182, 2183, 2184,
    2185, 9,    9,    9,    9,    2186, 2187, 2188, 2189, 2190, 70,   9,    70,   70,   2191, 70,
    2192, 2193, 2194, 2195, 2196, 2197, 2198, 2199, 2200, 2201, 2202, 2203, 2204, 2205, 2206, 2207,
    2208, 2209, 2210, 2211, 2212, 2213, 2214, 2215, 2216, 2217, 2218, 2219, 2220, 2221, 2222, 2223,
    2224, 2225, 2226, 2227, 2228, 2229, 2230, 2231, 2232, 2233, 2234, 2235, 2236, 2237, 2238, 2239,
    1388, 1388, 1388, 2240, 2241, 1388, 1388, 1388, 1388, 2242, 70,   70,   0,    0,    0,    0,
    2243, 9,    2244, 9,    2245, 72,   72,   72,   72,   72,   2246, 2247, 70,   70,   70,   70,
    9,    70,   70,   9,    70,   70,   9,    70,   70,   72,   72,   70,   70,   70,   2248, 70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   2249, 2250, 2251,
    2252, 70,   2253, 70,   2254, 70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    2255, 2256, 9,    9,    9,    2257, 2258, 9,    2259, 2260, 9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    2261, 2262, 2263, 2264, 9,    9,    9,    9,    9,    2265, 2266, 9,    2267,
    2268, 9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    2269, 9,    9,    9,
    9,    2270, 9,    2271, 2272, 2273, 9,    2274, 2275, 2276, 9,    9,    9,    2277, 9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    2278, 2279, 2280, 9,    2281, 2282, 9,    9,    9,    9,    9,    9,    9,    2283, 2284, 2285,
    2286, 2287, 2288, 2289, 2290, 2291, 2292, 2293, 2294, 2295, 2296, 2297, 2298, 2299, 9,    9,
    2300, 2301, 2302, 2303, 2304, 2305, 2306, 2307, 2308, 2309, 9,    9,    9,    9,    9,    9,
    9,    2310, 2311, 9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    2312, 9,    9,    9,    9,    9,    2313, 2314, 9,    2315, 2316, 2317, 2318, 2319,
    9,    9,    2320, 2321, 2322, 2323, 9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    2324, 2325, 2326, 2327, 9,    9,    9,    9,    9,    9,    2328, 2329, 2330, 2331, 9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    70,   70,   70,   70,   70,   70,   70,   70,   7,    8,    7,    8,    70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   72,   70,   70,   70,   70,
    9,    9,    70,   70,   70,   70,   70,   70,   72,   2332, 2333, 70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   9,    70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   9,    9,    9,    9,
    9,    9,    70,   70,   70,   70,   70,   70,   70,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   70,   70,   70,   70,   72,   72,   72,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2334, 2335, 2336, 2337, 2338, 2339, 2340, 2341, 2342, 2343, 2344, 2345, 2346, 2347, 2348, 2349,
    2350, 2351, 2352, 2353, 2354, 2355, 2356, 2357, 2358, 2359, 2360, 2361, 2362, 2363, 2364, 2365,
    2366, 2367, 2368, 2369, 2370, 2371, 2372, 2373, 2374, 2375, 2376, 2377, 2378, 2379, 2380, 2381,
    2382, 2383, 2384, 2385, 2386, 2387, 2388, 2389, 2390, 2391, 2392, 2393, 2394, 2395, 2396, 2397,
    2398, 2399, 2400, 2401, 2402, 2403, 2404, 2405, 2406, 2407, 2408, 2409, 2410, 2411, 2412, 2413,
    2414, 2415, 2416, 2417, 2418, 2419, 2420, 2421, 2422, 2423, 2424, 2425, 2426, 2427, 2428, 2429,
    2430, 2431, 2432, 2433, 2434, 2435, 2436, 2437, 2438, 2439, 2440, 2441, 2442, 2443, 2444, 2445,
    2446, 2447, 2448, 2449, 2450, 2451, 2452, 2453, 2454, 2455, 2456, 2457, 2458, 2459, 2460, 2461,
    2462, 2463, 2464, 2465, 2466, 2467, 2468, 2469, 2470, 2471, 2472, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   72,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   72,   9,    70,   70,   70,   70,   70,   70,   70,   70,
    72,   9,    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   9,    9,    9,    2473, 2473, 2473, 2473, 9,
    72,   72,   72,   72,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   70,
    70,   72,   70,   70,   72,   72,   70,   70,   72,   70,   70,   70,   70,   72,   70,   70,
    72,   70,   72,   72,   70,   70,   72,   70,   70,   70,   72,   70,   70,   70,   72,   72,
    70,   70,   70,   70,   70,   70,   70,   70,   72,   72,   72,   70,   70,   70,   70,   70,
    72,   70,   72,   70,   70,   70,   70,   70,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,
    72,   70,   70,   72,   70,   72,   72,   70,   72,   70,   70,   70,   70,   70,   70,   9,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   70,   70,   72,   72,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   72,   72,   72,   72,   72,   72,   70,   72,   70,   72,   72,   70,   70,   70,
    72,   72,   70,   70,   70,   70,   70,   72,   70,   70,   72,   72,   70,   70,   70,   70,
    72,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   72,   70,
    70,   70,   70,   70,   72,   72,   70,   70,   72,   70,   70,   70,   70,   70,   72,   72,
    70,   72,   70,   72,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   72,   70,   70,   70,   70,   70,
    72,   72,   72,   72,   72,   72,   70,   72,   72,   72,   72,   70,   70,   72,   70,   70,
    70,   70,   72,   70,   70,   72,   70,   70,   72,   72,   72,   72,   72,   72,   70,   72,
    70,   70,   72,   70,   72,   70,   72,   70,   70,   70,   70,   70,   70,   72,   70,   70,
    70,   72,   70,   70,   70,   70,   70,   70,   72,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   72,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   72,   70,   70,   72,   70,   70,   70,   70,   72,   70,   72,   70,
    70,   70,   70,   72,   72,   72,   70,   72,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   72,   72,   70,   70,   70,   7,    8,    7,    8,    7,    8,    7,    8,
    7,    8,    7,    8,    7,    8,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 70,   72,   72,   72,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,
    9,    9,    9,    9,    9,    7,    8,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    7,    8,    7,    8,    7,    8,    7,    8,    7,    8,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    2473, 2473, 9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    7,    8,    7,    8,    7,    8,    7,    8,    7,    8,    7,    8,    7,
    8,    7,    8,    7,    8,    7,    8,    7,    8,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    7,    8,    7,    8,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    7,    8,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    2474, 9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    2475, 2476, 2477, 9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    2478, 9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    70,   70,   70,   70,   70,   72,   72,   72,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   72,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,    9,
    9,    9,    9,    9,    9,    70,   70,   9,    9,    9,    9,    9,    9,    70,   70,   70,
    72,   70,   70,   70,   70,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   0,    0,    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    2479, 2480, 2481, 2482, 2483, 2484, 2485, 2486, 2487, 2488, 2489, 2490, 2491, 2492, 2493, 2494,
    2495, 2496, 2497, 2498, 2499, 2500, 2501, 2502, 2503, 2504, 2505, 2506, 2507, 2508, 2509, 2510,
    2511, 2512, 2513, 2514, 2515, 2516, 2517, 2518, 2519, 2520, 2521, 2522, 2523, 2524, 2525, 2526,
    2527, 2528, 2529, 2530, 2531, 2532, 2533, 2534, 2535, 2536, 2537, 2538, 2539, 2540, 2541, 2542,
    2543, 2544, 2545, 2546, 2547, 2548, 2549, 2550, 2551, 2552, 2553, 2554, 2555, 2556, 2557, 2558,
    2559, 2560, 2561, 2562, 2563, 2564, 2565, 2566, 2567, 2568, 2569, 2570, 2571, 2572, 2573, 2574,
    2575, 2576, 2577, 2578, 2579, 2580, 2581, 2582, 2583, 2584, 2585, 2586, 2587, 2588, 2589, 2590,
    2591, 206,  2592, 2593, 206,  2594, 2595, 206,  206,  206,  206,  206,  2596, 2597, 2598, 2599,
    2600, 2601, 2602, 2603, 2604, 2605, 2606, 2607, 2608, 2609, 2610, 2611, 2612, 2613, 2614, 2615,
    2616, 2617, 2618, 2619, 2620, 2621, 2622, 2623, 2624, 2625, 2626, 2627, 2628, 2629, 2630, 2631,
    2632, 2633, 2634, 2635, 2636, 2637, 2638, 2639, 2640, 2641, 2642, 2643, 2644, 2645, 2646, 2647,
    2648, 2649, 2650, 2651, 2652, 2653, 2654, 2655, 2656, 2657, 2658, 2659, 2660, 2661, 2662, 2663,
    2664, 2665, 2666, 2667, 2668, 2669, 2670, 2671, 2672, 2673, 2674, 2675, 2676, 2677, 2678, 2679,
    2680, 2681, 2682, 2683, 2684, 2685, 2686, 2687, 2688, 2689, 2690, 2691, 2692, 2693, 2694, 2695,
    2696, 2697, 2698, 2699, 206,  70,   70,   70,   70,   70,   70,   2700, 2701, 2702, 2703, 530,
    530,  530,  2704, 2705, 0,    0,    0,    0,    0,    5,    5,    5,    5,    1126, 5,    5,
    2706, 2707, 2708, 2709, 2710, 2711, 2712, 2713, 2714, 2715, 2716, 2717, 2718, 2719, 2720, 2721,
    2722, 2723, 2724, 2725, 2726, 2727, 2728, 2729, 2730, 2731, 2732, 2733, 2734, 2735, 2736, 2737,
    2738, 2739, 2740, 2741, 2742, 2743, 0,    2744, 0,    0,    0,    0,    0,    2745, 0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    2746,
    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1129,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  333,  333,  0,
    333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  333,  333,  0,
    333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  333,  333,  0,
    333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  333,  333,  0,
    530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,
    530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,
    5,    5,    74,   84,   74,   84,   5,    5,    5,    74,   84,   5,    74,   84,   5,    5,
    5,    5,    5,    5,    5,    5,    5,    10,   5,    5,    10,   5,    74,   84,   5,    5,
    74,   84,   7,    8,    7,    8,    7,    8,    7,    8,    5,    5,    5,    5,    5,    517,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    10,   10,   5,    5,    5,    5,
    10,   5,    7,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    70,   70,   5,    5,    5,    7,    8,    7,    8,    7,    8,    7,    8,    10,   0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   0,    70,   70,   70,   70,   2747,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   2748, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    2749, 2750, 2751, 2752, 2753, 2754, 2755, 2756, 2757, 2758, 2759, 2760, 2761, 2762, 2763, 2764,
    2765, 2766, 2767, 2768, 2769, 2770, 2771, 2772, 2773, 2774, 2775, 2776, 2777, 2778, 2779, 2780,
    2781, 2782, 2783, 2784, 2785, 2786, 2787, 2788, 2789, 2790, 2791, 2792, 2793, 2794, 2795, 2796,
    2797, 2798, 2799, 2800, 2801, 2802, 2803, 2804, 2805, 2806, 2807, 2808, 2809, 2810, 2811, 2812,
    2813, 2814, 2815, 2816, 2817, 2818, 2819, 2820, 2821, 2822, 2823, 2824, 2825, 2826, 2827, 2828,
    2829, 2830, 2831, 2832, 2833, 2834, 2835, 2836, 2837, 2838, 2839, 2840, 2841, 2842, 2843, 2844,
    2845, 2846, 2847, 2848, 2849, 2850, 2851, 2852, 2853, 2854, 2855, 2856, 2857, 2858, 2859, 2860,
    2861, 2862, 2863, 2864, 2865, 2866, 2867, 2868, 2869, 2870, 2871, 2872, 2873, 2874, 2875, 2876,
    2877, 2878, 2879, 2880, 2881, 2882, 2883, 2884, 2885, 2886, 2887, 2888, 2889, 2890, 2891, 2892,
    2893, 2894, 2895, 2896, 2897, 2898, 2899, 2900, 2901, 2902, 2903, 2904, 2905, 2906, 2907, 2908,
    2909, 2910, 2911, 2912, 2913, 2914, 2915, 2916, 2917, 2918, 2919, 2920, 2921, 2922, 2923, 2924,
    2925, 2926, 2927, 2928, 2929, 2930, 2931, 2932, 2933, 2934, 2935, 2936, 2937, 2938, 2939, 2940,
    2941, 2942, 2943, 2944, 2945, 2946, 2947, 2948, 2949, 2950, 2951, 2952, 2953, 2954, 2955, 2956,
    2957, 2958, 2959, 2960, 2961, 2962, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    2963, 5,    5,    5,    70,   517,  333,  1388, 7,    8,    7,    8,    7,    8,    7,    8,
    7,    8,    70,   70,   7,    8,    7,    8,    7,    8,    7,    8,    10,   7,    8,    8,
    70,   1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1572, 1054, 531,  1053, 2964, 2964,
    2965, 517,  517,  517,  517,  517,  2966, 70,   2967, 2968, 2969, 517,  333,  2970, 70,   70,
    0,    333,  333,  333,  333,  333,  2971, 333,  333,  333,  333,  2972, 2973, 2974, 2975, 2976,
    2977, 2978, 2979, 2980, 2981, 2982, 2983, 2984, 2985, 2986, 2987, 2988, 2989, 2990, 2991, 2992,
    2993, 2994, 2995, 333,  2996, 2997, 2998, 2999, 3000, 3001, 333,  333,  333,  333,  333,  3002,
    3003, 3004, 3005, 3006, 3007, 3008, 3009, 3010, 3011, 3012, 3013, 3014, 3015, 3016, 333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  3017, 333,  333,  0,    0,    3018, 3018, 3019, 3020, 3021, 3022, 3023,
    10,   333,  333,  333,  333,  333,  3024, 333,  333,  333,  333,  3025, 3026, 3027, 3028, 3029,
    3030, 3031, 3032, 3033, 3034, 3035, 3036, 3037, 3038, 3039, 3040, 3041, 3042, 3043, 3044, 3045,
    3046, 3047, 3048, 333,  3049, 3050, 3051, 3052, 3053, 3054, 333,  333,  333,  333,  333,  3055,
    3056, 3057, 3058, 3059, 3060, 3061, 3062, 3063, 3064, 3065, 3066, 3067, 3068, 3069, 333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  3070,
    3071, 3072, 3073, 333,  3074, 333,  333,  3075, 3076, 3077, 3078, 5,    517,  3079, 3080, 3081,
    0,    0,    0,    0,    0,    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    0,    3082, 3083, 3084, 3085, 3086, 3087, 3088, 3089, 3090, 3091, 3092, 3093, 3094, 3095, 3096,
    3097, 3098, 3099, 3100, 3101, 3102, 3103, 3104, 3105, 3106, 3107, 3108, 3109, 3110, 3111, 3112,
    3113, 3114, 3115, 3116, 3117, 3118, 3119, 3120, 3121, 3122, 3123, 3124, 3125, 3126, 3127, 3128,
    3129, 3130, 3131, 3132, 3133, 3134, 3135, 3136, 3137, 3138, 3139, 3140, 3141, 3142, 3143, 3144,
    3145, 3146, 3147, 3148, 3149, 3150, 3151, 3152, 3153, 3154, 3155, 3156, 3157, 3158, 3159, 3160,
    3161, 3162, 3163, 3164, 3165, 3166, 3167, 3168, 3169, 3170, 3171, 3172, 3173, 3174, 3175, 0,
    70,   70,   3176, 3177, 3178, 3179, 3180, 3181, 3182, 3183, 3184, 3185, 3186, 3187, 3188, 3189,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   0,    0,    0,    0,    0,    0,    0,    0,    0,    70,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    3190, 3191, 3192, 3193, 3194, 3195, 3196, 3197, 3198, 3199, 3200, 3201, 3202, 3203, 3204, 3205,
    3206, 3207, 3208, 3209, 3210, 3211, 3212, 3213, 3214, 3215, 3216, 3217, 3218, 3219, 3220, 0,
    3221, 3222, 3223, 3224, 3225, 3226, 3227, 3228, 3229, 3230, 3231, 3232, 3233, 3234, 3235, 3236,
    3237, 3238, 3239, 3240, 3241, 3242, 3243, 3244, 3245, 3246, 3247, 3248, 3249, 3250, 3251, 3252,
    3253, 3254, 3255, 3256, 3257, 3258, 3259, 3260, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    3261, 3262, 3263, 3264, 3265, 3266, 3267, 3268, 3269, 3270, 3271, 3272, 3273, 3274, 3275, 3276,
    3277, 3278, 3279, 3280, 3281, 3282, 3283, 3284, 3285, 3286, 3287, 3288, 3289, 3290, 3291, 3292,
    3293, 3294, 3295, 3296, 3297, 3298, 3299, 3300, 3301, 3302, 3303, 3304, 3305, 3306, 3307, 70,
    3308, 3309, 3310, 3311, 3312, 3313, 3314, 3315, 3316, 3317, 3318, 3319, 3320, 3321, 3322, 3323,
    3324, 3325, 3326, 3327, 3328, 3329, 3330, 3331, 3332, 3333, 3334, 3335, 3336, 3337, 3338, 3339,
    3340, 3341, 3342, 3343, 3344, 3345, 3346, 3347, 3348, 3349, 3350, 3351, 3352, 3353, 3354, 3355,
    3356, 3357, 3358, 3359, 3360, 3361, 3362, 3363, 3364, 3365, 3366, 3367, 3368, 3369, 3370, 3371,
    3372, 3373, 3374, 3375, 3376, 3377, 3378, 3379, 3380, 3381, 3382, 3383, 3384, 3385, 3386, 3387,
    3388, 3389, 3390, 3391, 3392, 3393, 3394, 3395, 3396, 3397, 3398, 3399, 3400, 3401, 3402, 3403,
    3404, 3405, 3406, 3407, 3408, 3409, 3410, 3411, 3412, 3413, 3414, 3415, 3416, 3417, 3418, 3419,
    3420, 3421, 3422, 3423, 3424, 3425, 3426, 3427, 3428, 3429, 3430, 3431, 3432, 3433, 3434, 3435,
    3436, 3437, 3438, 3439, 3440, 3441, 3442, 3443, 3444, 3445, 3446, 3447, 3448, 3449, 3450, 3451,
    3452, 3453, 3454, 3455, 3456, 3457, 3458, 3459, 3460, 3461, 3462, 3463, 3464, 3465, 3466, 3467,
    3468, 3469, 3470, 3471, 3472, 3473, 3474, 3475, 3476, 3477, 3478, 3479, 3480, 3481, 3482, 3483,
    3484, 3485, 3486, 3487, 3488, 3489, 3490, 3491, 3492, 3493, 3494, 3495, 3496, 3497, 3498, 3499,
    3500, 3501, 3502, 3503, 3504, 3505, 3506, 3507, 3508, 3509, 3510, 3511, 3512, 3513, 3514, 3515,
    3516, 3517, 3518, 3519, 3520, 3521, 3522, 3523, 3524, 3525, 3526, 3527, 3528, 3529, 3530, 3531,
    3532, 3533, 3534, 3535, 3536, 3537, 3538, 3539, 3540, 3541, 3542, 3543, 3544, 3545, 3546, 3547,
    3548, 3549, 3550, 3551, 3552, 3553, 3554, 3555, 3556, 3557, 3558, 3559, 3560, 3561, 3562, 3563,
    3564, 3565, 3566, 3567, 3568, 3569, 3570, 3571, 3572, 3573, 3574, 3575, 3576, 3577, 3578, 3579,
    3580, 3581, 3582, 3583, 3584, 3585, 3586, 3587, 3588, 3589, 3590, 3591, 3592, 3593, 3594, 3595,
    3596, 3597, 3598, 3599, 3600, 3601, 3602, 3603, 3604, 3605, 3606, 3607, 3608, 3609, 3610, 3611,
    3612, 3613, 3614, 3615, 3616, 3617, 3618, 3619, 3620, 3621, 3622, 3623, 3624, 3625, 3626, 3627,
    3628, 3629, 3630, 3631, 3632, 3633, 3634, 3635, 3636, 3637, 3638, 3639, 3640, 3641, 3642, 3643,
    3644, 3645, 3646, 3647, 3648, 3649, 3650, 3651, 3652, 3653, 3654, 3655, 3656, 3657, 3658, 3659,
    3660, 3661, 3662, 3663, 3664, 3665, 3666, 3667, 3668, 3669, 3670, 3671, 3672, 3673, 3674, 3675,
    3676, 3677, 3678, 3679, 3680, 3681, 3682, 3683, 3684, 3685, 3686, 3687, 3688, 3689, 3690, 3691,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  517,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  517,  517,  517,  517,  517,  517,  5,    5,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  517,  5,    5,    5,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   333,  333,  0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3692, 3693, 3694, 3695, 3696, 3697, 3698, 3699, 3700, 3701, 3702, 3703, 3704, 3705, 3706, 3707,
    3708, 3709, 3710, 3711, 3712, 3713, 3714, 3715, 3716, 3717, 3718, 3719, 3720, 3721, 3722, 3723,
    3724, 3725, 3726, 3727, 3728, 3729, 3730, 3731, 3732, 3733, 3734, 3735, 3736, 3737, 333,  530,
    809,  809,  809,  5,    530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  5,    517,
    3738, 3739, 3740, 3741, 3742, 3743, 3744, 3745, 3746, 3747, 3748, 3749, 3750, 3751, 3752, 3753,
    3754, 3755, 3756, 3757, 3758, 3759, 3760, 3761, 3762, 3763, 3764, 3765, 3766, 3767, 530,  530,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388,
    530,  530,  5,    5,    5,    5,    5,    5,    0,    0,    0,    0,    0,    0,    0,    0,
    41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,
    41,   41,   41,   41,   41,   41,   41,   517,  517,  517,  517,  517,  517,  517,  517,  517,
    41,   41,   3768, 3769, 3770, 3771, 3772, 3773, 3774, 3775, 3776, 3777, 3778, 3779, 3780, 3781,
    206,  206,  3782, 3783, 3784, 3785, 3786, 3787, 3788, 3789, 3790, 3791, 3792, 3793, 3794, 3795,
    3796, 3797, 3798, 3799, 3800, 3801, 3802, 3803, 3804, 3805, 3806, 3807, 3808, 3809, 3810, 3811,
    3812, 3813, 3814, 3815, 3816, 3817, 3818, 3819, 3820, 3821, 3822, 3823, 3824, 3825, 3826, 3827,
    3828, 3829, 3830, 3831, 3832, 3833, 3834, 3835, 3836, 3837, 3838, 3839, 3840, 3841, 3842, 3843,
    3844, 206,  206,  206,  206,  206,  206,  206,  206,  3845, 3846, 3847, 3848, 3849, 3850, 3851,
    3852, 3853, 3854, 3855, 3856, 3857, 3858, 3859, 517,  41,   41,   3860, 3861, 3862, 206,  333,
    3863, 3864, 3865, 3866, 3867, 206,  3868, 3869, 3870, 3871, 3872, 3873, 3874, 3875, 3876, 3877,
    3878, 3879, 3880, 3881, 3882, 3883, 3884, 3885, 3886, 3887, 3888, 3889, 3890, 3891, 3892, 206,
    3893, 3894, 3895, 3896, 3897, 3898, 3899, 3900, 3901, 3902, 3903, 3904, 3905, 3906, 3907, 3908,
    3909, 3910, 3911, 3912, 3913, 3914, 3915, 3916, 3917, 3918, 3919, 3920, 3921, 3922, 3923, 3924,
    3925, 3926, 3927, 3928, 3929, 3930, 3931, 3932, 3933, 3934, 3935, 3936, 3937, 0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3938, 3939, 3940, 3941, 3942, 3943, 333,  3944, 3945, 206,  333,  333,  333,  333,  333,
    333,  333,  544,  333,  333,  333,  1129, 333,  333,  333,  333,  544,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  1100, 1100, 544,  544,  1100, 70,   70,   70,   70,   1129, 0,    0,    0,
    1126, 1126, 1126, 1126, 1126, 1126, 70,   70,   6,    70,   0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  5,    5,    5,    5,    0,    0,    0,    0,    0,    0,    0,    0,
    1100, 1100, 333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100,
    1100, 1100, 1100, 1100, 1129, 544,  0,    0,    0,    0,    0,    0,    0,    0,    5,    5,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,  530,
    530,  530,  333,  333,  333,  333,  333,  333,  5,    5,    5,    333,  5,    333,  333,  544,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  544,  544,  544,  544,  544,  532,  532,  532,  5,    5,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  1100, 1389, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,
    1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293,
    1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 1293, 0,    0,    0,
    544,  544,  544,  1100, 333,  333,  333,  333,  333,  1101, 1101, 1101, 333,  333,  333,  1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1118, 1100, 1100, 544,  544,  544,  544,  1100, 1100, 544,  544,  1100, 1100,
    1412, 5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    0,    517,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    5,    5,
    1101, 1101, 1101, 1101, 1101, 544,  517,  1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   1101, 1101, 1101, 1101, 1101, 0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  544,  544,  544,  544,  544,  544,  1100,
    1100, 544,  544,  1100, 1100, 544,  544,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  544,  333,  333,  333,  333,  333,  333,  333,  333,  544,  1100, 0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    5,    5,    5,    5,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    517,  1101, 1101, 1101, 333,  333,  333,  70,   70,   70,   1101, 1205, 544,  1205, 1101, 1101,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    530,  333,  530,  530,  532,  333,  333,  530,  530,  333,  333,  333,  333,  333,  530,  530,
    333,  530,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    333,  333,  517,  5,    5,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1100, 544,  544,  1100, 1100,
    5,    5,    333,  517,  517,  1100, 1109, 0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    333,  333,  333,  333,  333,  333,  0,    0,    333,  333,  333,  333,  333,  333,  0,
    0,    333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  333,  333,  0,
    206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,
    206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,
    206,  206,  206,  3946, 206,  206,  206,  206,  206,  206,  206,  41,   3947, 3948, 3949, 3950,
    206,  206,  206,  206,  206,  206,  206,  206,  206,  3951, 41,   41,   0,    0,    0,    0,
    3952, 3953, 3954, 3955, 3956, 3957, 3958, 3959, 3960, 3961, 3962, 3963, 3964, 3965, 3966, 3967,
    3968, 3969, 3970, 3971, 3972, 3973, 3974, 3975, 3976, 3977, 3978, 3979, 3980, 3981, 3982, 3983,
    3984, 3985, 3986, 3987, 3988, 3989, 3990, 3991, 3992, 3993, 3994, 3995, 3996, 3997, 3998, 3999,
    4000, 4001, 4002, 4003, 4004, 4005, 4006, 4007, 4008, 4009, 4010, 4011, 4012, 4013, 4014, 4015,
    4016, 4017, 4018, 4019, 4020, 4021, 4022, 4023, 4024, 4025, 4026, 4027, 4028, 4029, 4030, 4031,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 333,  333,  333,  333,  333,
    333,  333,  333,  1100, 1100, 544,  1100, 1100, 544,  1100, 1100, 5,    1100, 1129, 0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4032, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033, 4033,
    4033, 4033, 4033, 4033, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294, 1294,
    1294, 1294, 1294, 1294, 1294, 1294, 1294, 0,    0,    0,    0,    1295, 1295, 1295, 1295, 1295,
    1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295,
    1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295,
    1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 1295, 0,    0,    0,    0,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034, 4034,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4036, 4037, 4038, 4039, 4040, 4041, 4042, 4043, 4044, 4045, 4046, 4047, 4048, 4049, 4050, 4051,
    4052, 4053, 4054, 4055, 4056, 4057, 4058, 4059, 4060, 4061, 4062, 4063, 4064, 4065, 4066, 4067,
    4068, 4069, 4070, 4071, 4072, 4073, 4074, 4075, 4076, 4077, 4078, 4079, 4080, 4081, 4082, 4083,
    4084, 4085, 4086, 4087, 4088, 4089, 4090, 4091, 4092, 4093, 4094, 4095, 4096, 4097, 4098, 4099,
    4100, 4101, 4102, 4103, 4104, 4105, 4106, 4107, 4108, 4109, 4110, 4111, 4112, 4113, 4114, 4115,
    4116, 4117, 4118, 4119, 4120, 4121, 4122, 4123, 4124, 4125, 4126, 4127, 4128, 4129, 4130, 4131,
    4132, 4133, 4134, 4135, 4136, 4137, 4138, 4139, 4140, 4141, 4142, 4143, 4144, 4145, 4146, 4147,
    4148, 4149, 4150, 4151, 4152, 4153, 4154, 4155, 4156, 4157, 4158, 4159, 4160, 4161, 4162, 4163,
    4164, 4165, 4166, 4167, 4168, 4169, 4170, 4171, 4172, 4173, 4174, 4175, 4176, 4177, 4178, 4179,
    4180, 4181, 4182, 4183, 4184, 4185, 4186, 4187, 4188, 4189, 4190, 4191, 4192, 4193, 4194, 4195,
    4196, 4197, 4198, 4199, 4200, 4201, 4202, 4203, 4204, 4205, 4206, 4207, 4208, 4209, 4210, 4211,
    4212, 4213, 4214, 4215, 4216, 4217, 4218, 4219, 4220, 4221, 4222, 4223, 4224, 4225, 4226, 4227,
    4228, 4229, 4230, 4231, 4232, 4233, 4234, 4235, 4236, 4237, 4238, 4239, 4240, 4241, 4242, 4243,
    4244, 4245, 4246, 4247, 4248, 4249, 4250, 4251, 4252, 4253, 4254, 4255, 4256, 4257, 4258, 4259,
    4260, 4261, 4262, 4263, 4264, 4265, 4266, 4267, 4268, 4269, 4270, 4271, 4272, 4273, 4274, 4275,
    4276, 4277, 4278, 4279, 4280, 4281, 4282, 4283, 4284, 4285, 4286, 4287, 4288, 4289, 4290, 4291,
    4292, 4293, 4294, 4295, 4296, 4297, 4298, 4299, 4300, 4301, 4302, 4303, 4304, 4305, 333,  333,
    4306, 333,  4307, 333,  333,  4308, 4309, 4310, 4311, 4312, 4313, 4314, 4315, 4316, 4317, 333,
    4318, 333,  4319, 333,  333,  4320, 4321, 333,  333,  333,  4322, 4323, 4324, 4325, 4326, 4327,
    4328, 4329, 4330, 4331, 4332, 4333, 4334, 4335, 4336, 4337, 4338, 4339, 4340, 4341, 4342, 4343,
    4344, 4345, 4346, 4347, 4348, 4349, 4350, 4351, 4352, 4353, 4354, 4355, 4356, 4357, 4358, 4359,
    4360, 4361, 4362, 4363, 4364, 4365, 4366, 4367, 4368, 4369, 4370, 4371, 4372, 4373, 4374, 4375,
    4376, 4377, 4378, 4379, 4380, 4381, 4382, 4383, 4384, 4385, 4386, 4387, 4388, 4389, 0,    0,
    4390, 4391, 4392, 4393, 4394, 4395, 4396, 4397, 4398, 4399, 4400, 4401, 4402, 4403, 4404, 4405,
    4406, 4407, 4408, 4409, 4410, 4411, 4412, 4413, 4414, 4415, 4416, 4417, 4418, 4419, 4420, 4421,
    4422, 4423, 4424, 4425, 4426, 4427, 4428, 4429, 4430, 4431, 4432, 4433, 4434, 4435, 4436, 4437,
    4438, 4439, 4440, 4441, 4442, 4443, 4444, 4445, 4446, 4447, 4448, 4449, 4450, 4451, 4452, 4453,
    4454, 4455, 4456, 4457, 4458, 4459, 4460, 4461, 4462, 4463, 4464, 4465, 4466, 4467, 4468, 4469,
    4470, 4471, 4472, 4473, 4474, 4475, 4476, 4477, 4478, 4479, 4480, 4481, 4482, 4483, 4484, 4485,
    4486, 4487, 4488, 4489, 4490, 4491, 4492, 4493, 4494, 4495, 0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    4496, 4497, 4498, 4499, 4500, 4501, 4502, 0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    4503, 4504, 4505, 4506, 4507, 0,    0,    0,    0,    0,    4508, 4509, 4510,
    4511, 4512, 4513, 4514, 4515, 4516, 4517, 4518, 4519, 4520, 4521, 4522, 4523, 4524, 4525, 4526,
    4527, 4528, 4529, 4530, 4531, 4532, 4533, 0,    4534, 4535, 4536, 4537, 4538, 0,    4539, 0,
    4540, 4541, 0,    4542, 4543, 0,    4544, 4545, 4546, 4547, 4548, 4549, 4550, 4551, 4552, 4553,
    4554, 4555, 4556, 4557, 4558, 4559, 4560, 4561, 4562, 4563, 4564, 4565, 4566, 4567, 4568, 4569,
    4570, 4571, 4572, 4573, 4574, 4575, 4576, 4577, 4578, 4579, 4580, 4581, 4582, 4583, 4584, 4585,
    4586, 4587, 4588, 4589, 4590, 4591, 4592, 4593, 4594, 4595, 4596, 4597, 4598, 4599, 4600, 4601,
    4602, 4603, 4604, 4605, 4606, 4607, 4608, 4609, 4610, 4611, 4612, 4613, 4614, 4615, 4616, 4617,
    4618, 4619, 4620, 4621, 4622, 4623, 4624, 4625, 4626, 4627, 4628, 4629, 4630, 4631, 4632, 4633,
    4634, 4635, 4636, 4637, 4638, 4639, 4640, 4641, 4642, 4643, 4644, 4645, 4646, 4647, 4648, 4649,
    4650, 4651, 41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,   41,
    41,   41,   41,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   4652, 4653, 4654, 4655, 4656, 4657, 4658, 4659, 4660, 4661, 4662, 4663, 4664,
    4665, 4666, 4667, 4668, 4669, 4670, 4671, 4672, 4673, 4674, 4675, 4676, 4677, 4678, 4679, 4680,
    4681, 4682, 4683, 4684, 4685, 4686, 4687, 4688, 4689, 4690, 4691, 4692, 4693, 4694, 4695, 4696,
    4697, 4698, 4699, 4700, 4701, 4702, 4703, 4704, 4705, 4706, 4707, 4708, 4709, 4710, 4711, 4712,
    4713, 4714, 4715, 4716, 4717, 4718, 4719, 4720, 4721, 4722, 4723, 4724, 4725, 4726, 4727, 4728,
    4729, 4730, 4731, 4732, 4733, 4734, 4735, 4736, 4737, 4738, 4739, 4740, 4741, 4742, 4743, 4744,
    4745, 4746, 4747, 4748, 4749, 4750, 4751, 4752, 4753, 4754, 4755, 4756, 4757, 4758, 4759, 4760,
    4761, 4762, 4763, 4764, 4765, 4766, 4767, 4768, 4769, 4770, 4771, 4772, 4773, 4774, 4775, 4776,
    4777, 4778, 4779, 4780, 4781, 4782, 4783, 4784, 4785, 4786, 4787, 4788, 4789, 4790, 4791, 4792,
    4793, 4794, 4795, 4796, 4797, 4798, 4799, 4800, 4801, 4802, 4803, 4804, 4805, 4806, 4807, 4808,
    4809, 4810, 4811, 4812, 4813, 4814, 4815, 4816, 4817, 4818, 4819, 4820, 4821, 4822, 4823, 4824,
    4825, 4826, 4827, 4828, 4829, 4830, 4831, 4832, 4833, 4834, 4835, 4836, 4837, 4838, 4839, 4840,
    4841, 4842, 4843, 4844, 4845, 4846, 4847, 4848, 4849, 4850, 4851, 4852, 4853, 4854, 4855, 4856,
    4857, 4858, 4859, 4860, 4861, 4862, 4863, 4864, 4865, 4866, 4867, 4868, 4869, 4870, 4871, 4872,
    4873, 4874, 4875, 4876, 4877, 4878, 4879, 4880, 4881, 4882, 4883, 4884, 4885, 4886, 4887, 4888,
    4889, 4890, 4891, 4892, 4893, 4894, 4895, 4896, 4897, 4898, 4899, 4900, 4901, 4902, 4903, 4904,
    4905, 4906, 4907, 4908, 4909, 4910, 4911, 4912, 4913, 4914, 4915, 4916, 4917, 4918, 4919, 4920,
    4921, 4922, 4923, 4924, 4925, 4926, 4927, 4928, 4929, 4930, 4931, 4932, 4933, 4934, 4935, 4936,
    4937, 4938, 4939, 4940, 4941, 4942, 4943, 4944, 4945, 4946, 4947, 4948, 4949, 4950, 4951, 4952,
    4953, 4954, 4955, 4956, 4957, 4958, 4959, 4960, 4961, 4962, 4963, 4964, 4965, 4966, 4967, 4968,
    4969, 4970, 4971, 4972, 4973, 4974, 4975, 4976, 4977, 4978, 4979, 4980, 4981, 4982, 4983, 4984,
    4985, 4986, 4987, 4988, 4989, 4990, 4991, 4992, 4993, 4994, 4995, 4996, 4997, 4998, 4999, 5000,
    5001, 5002, 5003, 5004, 5005, 5006, 5007, 5008, 5009, 5010, 5011, 5012, 5013, 5014, 8,    7,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    5015, 5016, 5017, 5018, 5019, 5020, 5021, 5022, 5023, 5024, 5025, 5026, 5027, 5028, 5029, 5030,
    5031, 5032, 5033, 5034, 5035, 5036, 5037, 5038, 5039, 5040, 5041, 5042, 5043, 5044, 5045, 5046,
    5047, 5048, 5049, 5050, 5051, 5052, 5053, 5054, 5055, 5056, 5057, 5058, 5059, 5060, 5061, 5062,
    5063, 5064, 5065, 5066, 5067, 5068, 5069, 5070, 5071, 5072, 5073, 5074, 5075, 5076, 5077, 5078,
    70,   70,   5079, 5080, 5081, 5082, 5083, 5084, 5085, 5086, 5087, 5088, 5089, 5090, 5091, 5092,
    5093, 5094, 5095, 5096, 5097, 5098, 5099, 5100, 5101, 5102, 5103, 5104, 5105, 5106, 5107, 5108,
    5109, 5110, 5111, 5112, 5113, 5114, 5115, 5116, 5117, 5118, 5119, 5120, 5121, 5122, 5123, 5124,
    5125, 5126, 5127, 5128, 5129, 5130, 5131, 5132, 70,   70,   70,   70,   70,   70,   70,   70,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    5133, 5134, 5135, 5136, 5137, 5138, 5139, 5140, 5141, 5142, 5143, 5144, 5145, 70,   70,   70,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    5146, 5147, 5148, 5149, 5150, 5151, 5152, 5153, 5154, 5155, 0,    0,    0,    0,    0,    0,
    530,  530,  530,  530,  530,  530,  530,  532,  532,  532,  532,  532,  532,  532,  530,  530,
    5156, 5157, 5158, 5159, 5160, 5161, 5162, 5163, 5164, 5165, 5166, 5167, 5168, 5169, 5170, 5171,
    5172, 5173, 5174, 5175, 5176, 5,    5,    5177, 5178, 5179, 5180, 5181, 5182, 5183, 5184, 5185,
    5186, 5187, 5188, 0,    5189, 5190, 5191, 5192, 5193, 5194, 5195, 5196, 5197, 5198, 5199, 5200,
    5201, 5202, 5203, 5204, 5205, 5206, 5207, 0,    5208, 5209, 5210, 5211, 0,    0,    0,    0,
    5212, 5213, 5214, 333,  5215, 0,    5216, 5217, 5218, 5219, 5220, 5221, 5222, 5223, 5224, 5225,
    5226, 5227, 5228, 5229, 5230, 5231, 5232, 5233, 5234, 5235, 5236, 5237, 5238, 5239, 5240, 5241,
    5242, 5243, 5244, 5245, 5246, 5247, 5248, 5249, 5250, 5251, 5252, 5253, 5254, 5255, 5256, 5257,
    5258, 5259, 5260, 5261, 5262, 5263, 5264, 5265, 5266, 5267, 5268, 5269, 5270, 5271, 5272, 5273,
    5274, 5275, 5276, 5277, 5278, 5279, 5280, 5281, 5282, 5283, 5284, 5285, 5286, 5287, 5288, 5289,
    5290, 5291, 5292, 5293, 5294, 5295, 5296, 5297, 5298, 5299, 5300, 5301, 5302, 5303, 5304, 5305,
    5306, 5307, 5308, 5309, 5310, 5311, 5312, 5313, 5314, 5315, 5316, 5317, 5318, 5319, 5320, 5321,
    5322, 5323, 5324, 5325, 5326, 5327, 5328, 5329, 5330, 5331, 5332, 5333, 5334, 5335, 5336, 5337,
    5338, 5339, 5340, 5341, 5342, 5343, 5344, 5345, 5346, 5347, 5348, 5349, 5350, 0,    0,    75,
    0,    5351, 5352, 5353, 5354, 5355, 5356, 5357, 5358, 5359, 5360, 5361, 5362, 5363, 5364, 5365,
    5366, 5367, 5368, 5369, 5370, 5371, 5372, 5373, 5374, 5375, 5376, 5377, 5378, 5379, 5380, 5381,
    5382, 5383, 5384, 5385, 5386, 5387, 5388, 5389, 5390, 5391, 5392, 5393, 5394, 5395, 5396, 5397,
    5398, 5399, 5400, 5401, 5402, 5403, 5404, 5405, 5406, 5407, 5408, 5409, 5410, 5411, 5412, 5413,
    5414, 5415, 5416, 5417, 5418, 5419, 5420, 5421, 5422, 5423, 5424, 5425, 5426, 5427, 5428, 5429,
    5430, 5431, 5432, 5433, 5434, 5435, 5436, 5437, 5438, 5439, 5440, 5441, 5442, 5443, 5444, 5445,
    5446, 5447, 5448, 5449, 5450, 5451, 5452, 5453, 5454, 5455, 5456, 5457, 5458, 5459, 5460, 5461,
    5462, 5463, 5464, 5465, 5466, 5467, 5468, 5469, 5470, 5471, 5472, 5473, 5474, 5475, 5476, 5477,
    5478, 5479, 5480, 5481, 5482, 5483, 5484, 5485, 5486, 5487, 5488, 5489, 5490, 5491, 5492, 5493,
    5494, 5495, 5496, 5497, 5498, 5499, 5500, 5501, 5502, 5503, 5504, 5505, 5506, 5507, 5508, 5509,
    5510, 5511, 5512, 5513, 5514, 5515, 5516, 5517, 5518, 5519, 5520, 5521, 5522, 5523, 5524, 5525,
    5526, 5527, 5528, 5529, 5530, 5531, 5532, 5533, 5534, 5535, 5536, 5537, 5538, 5539, 5540, 0,
    0,    0,    5541, 5542, 5543, 5544, 5545, 5546, 0,    0,    5547, 5548, 5549, 5550, 5551, 5552,
    0,    0,    5553, 5554, 5555, 5556, 5557, 5558, 0,    0,    5559, 5560, 5561, 0,    0,    0,
    5562, 5563, 5564, 5565, 5566, 5567, 5568, 0,    5569, 5570, 5571, 5572, 5573, 5574, 5575, 0,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 75,   75,   75,   70,   70,   0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  0,    333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,
    5,    5,    5,    0,    0,    0,    0,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 0,    0,    0,    70,   70,   70,   70,   70,   70,   70,   70,   70,
    1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388,
    1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388,
    1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388,
    1388, 1388, 1388, 1388, 1388, 1126, 1126, 1126, 1126, 70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   1126, 1126, 70,   70,   70,   0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   0,    0,    0,
    70,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   532,  0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    532,  1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    1126, 1126, 1126, 1126, 0,    0,    0,    0,    0,    0,    0,    0,    0,    333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  1388, 333,  333,  333,  333,  333,  333,  333,  333,  1388, 0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  530,  530,  530,  530,  530,  0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    5,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  0,    0,    0,    0,    333,  333,  333,  333,  333,  333,  333,  333,
    5,    1388, 1388, 1388, 1388, 1388, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    5576, 5577, 5578, 5579, 5580, 5581, 5582, 5583, 5584, 5585, 5586, 5587, 5588, 5589, 5590, 5591,
    5592, 5593, 5594, 5595, 5596, 5597, 5598, 5599, 5600, 5601, 5602, 5603, 5604, 5605, 5606, 5607,
    5608, 5609, 5610, 5611, 5612, 5613, 5614, 5615, 5616, 5617, 5618, 5619, 5620, 5621, 5622, 5623,
    5624, 5625, 5626, 5627, 5628, 5629, 5630, 5631, 5632, 5633, 5634, 5635, 5636, 5637, 5638, 5639,
    5640, 5641, 5642, 5643, 5644, 5645, 5646, 5647, 5648, 5649, 5650, 5651, 5652, 5653, 5654, 5655,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    5656, 5657, 5658, 5659, 5660, 5661, 5662, 5663, 5664, 5665, 5666, 5667, 5668, 5669, 5670, 5671,
    5672, 5673, 5674, 5675, 5676, 5677, 5678, 5679, 5680, 5681, 5682, 5683, 5684, 5685, 5686, 5687,
    5688, 5689, 5690, 5691, 0,    0,    0,    0,    5692, 5693, 5694, 5695, 5696, 5697, 5698, 5699,
    5700, 5701, 5702, 5703, 5704, 5705, 5706, 5707, 5708, 5709, 5710, 5711, 5712, 5713, 5714, 5715,
    5716, 5717, 5718, 5719, 5720, 5721, 5722, 5723, 5724, 5725, 5726, 5727, 0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,
    5728, 5729, 5730, 5731, 5732, 5733, 5734, 5735, 5736, 5737, 5738, 0,    5739, 5740, 5741, 5742,
    5743, 5744, 5745, 5746, 5747, 5748, 5749, 5750, 5751, 5752, 5753, 0,    5754, 5755, 5756, 5757,
    5758, 5759, 5760, 0,    5761, 5762, 0,    5763, 5764, 5765, 5766, 5767, 5768, 5769, 5770, 5771,
    5772, 5773, 0,    5774, 5775, 5776, 5777, 5778, 5779, 5780, 5781, 5782, 5783, 5784, 5785, 5786,
    5787, 5788, 0,    5789, 5790, 5791, 5792, 5793, 5794, 5795, 0,    5796, 5797, 0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  5798, 333,  333,  333,  333,  333,  333,
    333,  333,  5799, 333,  333,  333,  333,  333,  333,  333,  5800, 333,  333,  333,  333,  333,
    333,  333,  333,  333,  5801, 333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    517,  5802, 5803, 5804, 5805, 5806, 0,    5807, 5808, 5809, 5810, 5811, 5812, 5813, 5814, 5815,
    5816, 5817, 5818, 5819, 5820, 5821, 5822, 5823, 5824, 5825, 5826, 5827, 5828, 5829, 5830, 5831,
    5832, 5833, 5834, 5835, 5836, 5837, 5838, 5839, 5840, 5841, 5842, 5843, 5844, 5845, 5846, 5847,
    5848, 0,    5849, 5850, 5851, 5852, 5853, 5854, 5855, 5856, 5857, 0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  0,    0,    333,  0,    333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  0,    333,  333,  0,    0,    0,    333,  0,    0,    333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  0,    5,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  70,   70,   1126, 1126, 1126, 1126, 1126, 1126, 1126,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,
    0,    0,    0,    0,    0,    0,    0,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  0,    333,  333,  0,    0,    0,    0,    0,    1126, 1126, 1126, 1126, 1126,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  1126, 1126, 1126, 1126, 1126, 1126, 0,    0,    0,    5,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    5,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    1126, 1126, 333,  333,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    0,    0,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1101, 544,  544,  544,  0,    544,  544,  0,    0,    0,    0,    0,    544,  532,  544,  530,
    1101, 1101, 1101, 1101, 0,    1101, 1101, 1101, 0,    1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 0,    0,    530,  537,  532,  0,    0,    0,    0,    1109,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 0,    0,    0,    0,    0,    0,    0,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  1126, 1126, 5,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  1126, 1126, 1126,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  70,   333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  530,  532,  0,    0,    0,    0,    1126, 1126, 1126, 1126, 1126,
    5,    5,    5,    5,    5,    5,    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  0,    0,    0,    5,    5,    5,    5,    5,    5,    5,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  0,    0,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  0,    0,    0,    0,    0,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  0,    0,    0,    0,    0,    0,    0,    5,    5,    5,    5,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1126, 1126, 1126, 1126, 1126, 1126, 1126,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    5858, 5859, 5860, 5861, 5862, 5863, 5864, 5865, 5866, 5867, 5868, 5869, 5870, 5871, 5872, 5873,
    5874, 5875, 5876, 5877, 5878, 5879, 5880, 5881, 5882, 5883, 5884, 5885, 5886, 5887, 5888, 5889,
    5890, 5891, 5892, 5893, 5894, 5895, 5896, 5897, 5898, 5899, 5900, 5901, 5902, 5903, 5904, 5905,
    5906, 5907, 5908, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    5909, 5910, 5911, 5912, 5913, 5914, 5915, 5916, 5917, 5918, 5919, 5920, 5921, 5922, 5923, 5924,
    5925, 5926, 5927, 5928, 5929, 5930, 5931, 5932, 5933, 5934, 5935, 5936, 5937, 5938, 5939, 5940,
    5941, 5942, 5943, 5944, 5945, 5946, 5947, 5948, 5949, 5950, 5951, 5952, 5953, 5954, 5955, 5956,
    5957, 5958, 5959, 0,    0,    0,    0,    0,    0,    0,    1126, 1126, 1126, 1126, 1126, 1126,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  530,  530,  530,  530,  0,    0,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   333,  333,  333,  333,  517,  333,
    5960, 5961, 5962, 5963, 5964, 5965, 5966, 5967, 5968, 5969, 5970, 5971, 5972, 5973, 5974, 5975,
    5976, 5977, 5978, 5979, 5980, 5981, 0,    0,    0,    530,  530,  530,  530,  530,  10,   517,
    5982, 5983, 5984, 5985, 5986, 5987, 5988, 5989, 5990, 5991, 5992, 5993, 5994, 5995, 5996, 5997,
    5998, 5999, 6000, 6001, 6002, 6003, 0,    0,    0,    0,    0,    0,    0,    0,    9,    9,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    530,  530,  10,   0,    0,
    333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    333,  333,  333,  517,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,
    5,    70,   70,   70,   70,   70,   70,   70,   70,   0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    532,  532,  544,  532,  532,  532,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 333,  0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  532,  532,  530,  530,  530,  532,  530,  532,  532,  532,
    532,  1126, 1126, 1126, 1126, 5,    5,    5,    5,    5,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  530,  532,  530,  532,  5,    5,    5,    5,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  1126, 1126, 1126, 1126, 1126, 1126, 1126, 0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    1100, 544,  1100, 333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  1129, 5,    5,    5,    5,    5,    5,    5,    0,    0,
    0,    0,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    1129, 333,  333,  544,  544,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    1129,
    544,  544,  1100, 333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  6004, 6005, 6006, 6007, 333,  333,  333,
    333,  333,  333,  333,  333,  6008, 333,  333,  333,  333,  333,  6009, 333,  333,  333,  333,
    1100, 1100, 1100, 544,  544,  544,  544,  1100, 1100, 1129, 1108, 5,    5,    1071, 5,    5,
    5,    5,    544,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    1071, 0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    530,  530,  530,  1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1138, 544,  544,  544,  544,  1100, 544,  6010, 6011,
    544,  6012, 6013, 1109, 1129, 0,    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    5,    5,    5,    5,    1101, 1100, 1100, 1101, 0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  1118, 5,    5,    333,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    544,  544,  1100, 333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  1100, 1100, 1100, 544,  544,  544,  544,  544,  544,  544,  544,  544,  1100,
    1389, 333,  1164, 1164, 333,  5,    5,    5,    5,    544,  1118, 544,  544,  5,    1100, 544,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   333,  5,    333,  5,    5,    5,
    0,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  0,    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  1100, 1100, 1100, 544,
    544,  544,  1100, 1100, 544,  1389, 1118, 544,  5,    5,    5,    5,    5,    5,    544,  333,
    333,  544,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  0,    333,  0,    333,  333,  333,  333,  0,    333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  5,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  544,
    1100, 1100, 1100, 544,  544,  544,  544,  544,  544,  1118, 1129, 0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    544,  544,  1100, 1100, 0,    333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    333,
    333,  0,    0,    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  333,
    333,  0,    333,  333,  0,    333,  333,  333,  333,  333,  0,    1118, 1118, 333,  1119, 1100,
    544,  1100, 1100, 1100, 1100, 0,    0,    6014, 1100, 0,    0,    6015, 6016, 1389, 0,    0,
    333,  0,    0,    0,    0,    0,    0,    1119, 0,    0,    0,    0,    0,    333,  333,  333,
    333,  333,  1100, 1100, 0,    0,    530,  530,  530,  530,  530,  530,  530,  0,    0,    0,
    530,  530,  530,  530,  530,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1101, 1101, 6017, 6018, 6019, 6020, 1101, 1101, 1101, 1101, 0,    6021, 0,    0,    6022, 0,
    6023, 6024, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 0,    333,  1119, 1100, 1100, 1138, 544,  544,  544,  544,
    544,  0,    6025, 0,    0,    6026, 0,    6027, 6028, 1119, 1100, 0,    1100, 1100, 1129, 1389,
    1109, 1164, 544,  333,  5,    5,    0,    5,    5,    0,    0,    0,    0,    0,    0,    0,
    0,    544,  544,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  1100, 1100, 1100, 544,  544,  544,  544,  544,  544,  544,  544,
    1100, 1100, 1129, 544,  544,  1100, 1118, 333,  333,  333,  333,  5,    5,    5,    5,    5,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   5,    5,    0,    5,    530,  333,
    333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    1119, 1100, 1100, 544,  544,  544,  544,  544,  544,  6029, 1138, 6030, 6031, 1119, 6032, 544,
    544,  1100, 1129, 1118, 333,  333,  5,    333,  0,    0,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  1119,
    1100, 1100, 544,  544,  544,  544,  0,    0,    6033, 6034, 6035, 6036, 544,  544,  1100, 1129,
    1118, 5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    333,  333,  333,  333,  544,  544,  0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    1100, 1100, 1100, 544,  544,  544,  544,  544,  544,  544,  544,  1100, 1100, 544,  1100, 1129,
    544,  5,    5,    5,    333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  544,  1100, 544,  1100, 1100,
    544,  544,  544,  544,  544,  544,  1389, 1118, 333,  5,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
    11,   11,   11,   11,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    544,  1100, 544,
    1205, 1205, 544,  544,  544,  544,  1100, 544,  544,  544,  544,  1129, 0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   1126, 1126, 5,    5,    5,    70,
    333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  1100, 1100, 1100, 544,
    544,  544,  544,  544,  544,  544,  544,  544,  1100, 1129, 1118, 5,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6037, 6038, 6039, 6040, 6041, 6042, 6043, 6044, 6045, 6046, 6047, 6048, 6049, 6050, 6051, 6052,
    6053, 6054, 6055, 6056, 6057, 6058, 6059, 6060, 6061, 6062, 6063, 6064, 6065, 6066, 6067, 6068,
    6069, 6070, 6071, 6072, 6073, 6074, 6075, 6076, 6077, 6078, 6079, 6080, 6081, 6082, 6083, 6084,
    6085, 6086, 6087, 6088, 6089, 6090, 6091, 6092, 6093, 6094, 6095, 6096, 6097, 6098, 6099, 6100,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    333,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 0,    0,    1101, 0,    0,    1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 0,    1101, 1101, 0,    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1119, 1100, 1100, 1100, 1100, 6101, 0,    1100, 6102, 0,    0,    544,  544,  1389, 1109, 1164,
    1100, 1164, 1100, 1118, 5,    5,    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  1100, 1100, 1100, 544,  544,  544,  544,  0,    0,    544,  544,  1100, 1100, 1100, 1100,
    1129, 333,  5,    333,  1100, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1101, 544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 544,  1129, 544,  544,  544,  544,  1100, 333,  544,  544,  544,  544,  5,
    5,    5,    5,    5,    5,    5,    5,    1109, 0,    0,    0,    0,    0,    0,    0,    0,
    1101, 544,  544,  544,  544,  544,  544,  1100, 1100, 544,  544,  544,  1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1164, 1164, 1164, 1164, 1164, 1164, 544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  1100, 544,  1109, 5,    5,    5,    333,  5,    5,
    5,    5,    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    544,  1100, 544,  544,  544,  1100, 544,  1100, 0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  1100,
    544,  544,  544,  544,  544,  544,  544,  0,    544,  544,  544,  544,  544,  544,  1100, 1129,
    333,  5,    5,    5,    5,    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 0,    0,    0,
    5,    5,    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    0,    0,    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  0,    1100, 544,  544,  544,  544,  544,  544,
    544,  1100, 544,  544,  1100, 544,  544,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  0,    333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  544,  544,  544,  544,  544,  544,  0,    0,    0,    544,  0,    544,  544,  0,    544,
    544,  544,  1118, 544,  1129, 1129, 1164, 544,  0,    0,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  0,    333,  333,  0,    333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  1100, 1100, 1100, 1100, 1100, 0,
    544,  544,  0,    1100, 1100, 544,  1100, 1129, 333,  0,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  517,  333,  333,  0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  544,  544,  1100, 1100, 5,    5,    0,    0,    0,    0,    0,    0,    0,
    544,  544,  1164, 1100, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 0,    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101, 1101,
    1101, 1101, 1101, 1101, 1100, 1100, 544,  544,  544,  544,  544,  0,    0,    0,    1100, 1100,
    544,  1389, 1109, 5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   544,  0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 70,   70,   70,   70,   70,   70,   70,   70,   6,    6,    6,
    6,    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    5,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388,
    1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388,
    1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388,
    1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388,
    1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388,
    1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388,
    1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 1388, 0,
    5,    5,    5,    5,    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  5,    5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    75,   75,   75,   75,   75,   75,   75,   75,   75,   75,   75,   75,   75,   75,   75,   75,
    544,  333,  333,  333,  333,  333,  333,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  6103, 1138,
    1138, 6104, 6105, 6106, 6107, 6108, 6109, 6110, 6111, 6112, 1100, 1100, 1100, 544,  544,  1129,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    5,    5,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,
    537,  537,  537,  537,  537,  5,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    530,  530,  530,  530,  530,  530,  530,  5,    5,    5,    5,    5,    70,   70,   70,   70,
    517,  517,  517,  517,  5,    70,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    1126, 1126, 1126, 1126, 1126,
    1126, 1126, 0,    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    517,  517,  517,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  6113, 333,  333,  333,  6114, 6115, 6116, 6117, 517,  517,  5,    5,    5,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6118, 6119, 6120, 6121, 6122, 6123, 6124, 6125, 6126, 6127, 6128, 6129, 6130, 6131, 6132, 6133,
    6134, 6135, 6136, 6137, 6138, 6139, 6140, 6141, 6142, 6143, 6144, 6145, 6146, 6147, 6148, 6149,
    6150, 6151, 6152, 6153, 6154, 6155, 6156, 6157, 6158, 6159, 6160, 6161, 6162, 6163, 6164, 6165,
    6166, 6167, 6168, 6169, 6170, 6171, 6172, 6173, 6174, 6175, 6176, 6177, 6178, 6179, 6180, 6181,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 5,    5,    5,    5,    0,    0,    0,    0,    0,
    6182, 6183, 6184, 6185, 6186, 6187, 6188, 6189, 6190, 6191, 6192, 6193, 6194, 6195, 6196, 6197,
    6198, 6199, 6200, 6201, 6202, 6203, 6204, 6205, 6206, 0,    0,    6207, 6208, 6209, 6210, 6211,
    6212, 6213, 6214, 6215, 6216, 6217, 6218, 6219, 6220, 6221, 6222, 6223, 6224, 6225, 6226, 6227,
    6228, 6229, 6230, 6231, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    544,
    333,  1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100,
    1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100,
    1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100,
    1100, 1100, 1100, 1100, 1100, 1100, 1100, 1100, 0,    0,    0,    0,    0,    0,    0,    544,
    544,  544,  544,  517,  517,  517,  517,  517,  517,  517,  517,  517,  517,  517,  517,  517,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    517,  517,  5,    517,  544,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6232, 6232, 517,  517,  1388, 1388, 1388, 0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    517,  517,  517,  517,  0,    517,  517,  517,  517,  517,  517,  517,  0,    517,  517,  0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  0,    0,    333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    70,   544,  537,  5,
    75,   75,   75,   75,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   6233, 6234, 6235, 6236, 6237, 6238, 6239, 6240, 6241, 6242,
    6243, 6244, 6245, 6246, 6247, 6248, 6249, 6250, 6251, 6252, 6253, 6254, 6255, 6256, 6257, 6258,
    6259, 6260, 6261, 6262, 6263, 6264, 6265, 6266, 6267, 6268, 70,   70,   70,   0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   0,    0,    0,    0,    0,    0,    70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  0,    0,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   0,    0,    70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   6269, 6270,
    6271, 6272, 6273, 6274, 6275, 6276, 6276, 537,  537,  537,  70,   70,   70,   6277, 6276, 6276,
    6276, 6276, 6276, 75,   75,   75,   75,   75,   75,   75,   75,   532,  532,  532,  532,  532,
    532,  532,  532,  70,   70,   530,  530,  530,  530,  530,  532,  532,  70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   530,  530,  530,  530,  70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   6278, 6279, 6280, 6281, 6282,
    6283, 70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   530,  530,  530,  70,   0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   0,    0,    0,    0,    0,    0,    0,    0,    0,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    6284, 6285, 6286, 6287, 6288, 6289, 6290, 6291, 6292, 6293, 6294, 6295, 6296, 6297, 6298, 6299,
    6300, 6301, 6302, 6303, 6304, 6305, 6306, 6307, 6308, 6309, 6310, 6311, 6312, 6313, 6314, 6315,
    6316, 6317, 6318, 6319, 6320, 6321, 6322, 6323, 6324, 6325, 6326, 6327, 6328, 6329, 6330, 6331,
    6332, 6333, 6334, 6335, 6336, 6337, 6338, 6339, 6340, 6341, 6342, 6343, 6344, 6345, 6346, 6347,
    6348, 6349, 6350, 6351, 6352, 6353, 6354, 6355, 6356, 6357, 6358, 6359, 6360, 6361, 6362, 6363,
    6364, 6365, 6366, 6367, 6368, 0,    6369, 6370, 6371, 6372, 6373, 6374, 6375, 6376, 6377, 6378,
    6379, 6380, 6381, 6382, 6383, 6384, 6385, 6386, 6387, 6388, 6389, 6390, 6391, 6392, 6393, 6394,
    6395, 6396, 6397, 6398, 6399, 6400, 6401, 6402, 6403, 6404, 6405, 6406, 6407, 6408, 6409, 6410,
    6411, 6412, 6413, 6414, 6415, 6416, 6417, 6418, 6419, 6420, 6421, 6422, 6423, 6424, 6425, 6426,
    6427, 6428, 6429, 6430, 6431, 6432, 6433, 6434, 6435, 6436, 6437, 6438, 6439, 0,    6440, 6441,
    0,    0,    6442, 0,    0,    6443, 6444, 0,    0,    6445, 6446, 6447, 6448, 0,    6449, 6450,
    6451, 6452, 6453, 6454, 6455, 6456, 6457, 6458, 6459, 6460, 0,    6461, 0,    6462, 6463, 6464,
    6465, 6466, 6467, 6468, 0,    6469, 6470, 6471, 6472, 6473, 6474, 6475, 6476, 6477, 6478, 6479,
    6480, 6481, 6482, 6483, 6484, 6485, 6486, 6487, 6488, 6489, 6490, 6491, 6492, 6493, 6494, 6495,
    6496, 6497, 6498, 6499, 6500, 6501, 6502, 6503, 6504, 6505, 6506, 6507, 6508, 6509, 6510, 6511,
    6512, 6513, 6514, 6515, 6516, 6517, 6518, 6519, 6520, 6521, 6522, 6523, 6524, 6525, 6526, 6527,
    6528, 6529, 6530, 6531, 6532, 6533, 0,    6534, 6535, 6536, 6537, 0,    0,    6538, 6539, 6540,
    6541, 6542, 6543, 6544, 6545, 0,    6546, 6547, 6548, 6549, 6550, 6551, 6552, 0,    6553, 6554,
    6555, 6556, 6557, 6558, 6559, 6560, 6561, 6562, 6563, 6564, 6565, 6566, 6567, 6568, 6569, 6570,
    6571, 6572, 6573, 6574, 6575, 6576, 6577, 6578, 6579, 6580, 0,    6581, 6582, 6583, 6584, 0,
    6585, 6586, 6587, 6588, 6589, 0,    6590, 0,    0,    0,    6591, 6592, 6593, 6594, 6595, 6596,
    6597, 0,    6598, 6599, 6600, 6601, 6602, 6603, 6604, 6605, 6606, 6607, 6608, 6609, 6610, 6611,
    6612, 6613, 6614, 6615, 6616, 6617, 6618, 6619, 6620, 6621, 6622, 6623, 6624, 6625, 6626, 6627,
    6628, 6629, 6630, 6631, 6632, 6633, 6634, 6635, 6636, 6637, 6638, 6639, 6640, 6641, 6642, 6643,
    6644, 6645, 6646, 6647, 6648, 6649, 6650, 6651, 6652, 6653, 6654, 6655, 6656, 6657, 6658, 6659,
    6660, 6661, 6662, 6663, 6664, 6665, 6666, 6667, 6668, 6669, 6670, 6671, 6672, 6673, 6674, 6675,
    6676, 6677, 6678, 6679, 6680, 6681, 6682, 6683, 6684, 6685, 6686, 6687, 6688, 6689, 6690, 6691,
    6692, 6693, 6694, 6695, 6696, 6697, 6698, 6699, 6700, 6701, 6702, 6703, 6704, 6705, 6706, 6707,
    6708, 6709, 6710, 6711, 6712, 6713, 6714, 6715, 6716, 6717, 6718, 6719, 6720, 6721, 6722, 6723,
    6724, 6725, 6726, 6727, 6728, 6729, 6730, 6731, 6732, 6733, 6734, 6735, 6736, 6737, 6738, 6739,
    6740, 6741, 6742, 6743, 6744, 6745, 6746, 6747, 6748, 6749, 6750, 6751, 6752, 6753, 6754, 6755,
    6756, 6757, 6758, 6759, 6760, 6761, 6762, 6763, 6764, 6765, 6766, 6767, 6768, 6769, 6770, 6771,
    6772, 6773, 6774, 6775, 6776, 6777, 6778, 6779, 6780, 6781, 6782, 6783, 6784, 6785, 6786, 6787,
    6788, 6789, 6790, 6791, 6792, 6793, 6794, 6795, 6796, 6797, 6798, 6799, 6800, 6801, 6802, 6803,
    6804, 6805, 6806, 6807, 6808, 6809, 6810, 6811, 6812, 6813, 6814, 6815, 6816, 6817, 6818, 6819,
    6820, 6821, 6822, 6823, 6824, 6825, 6826, 6827, 6828, 6829, 6830, 6831, 6832, 6833, 6834, 6835,
    6836, 6837, 6838, 6839, 6840, 6841, 6842, 6843, 6844, 6845, 6846, 6847, 6848, 6849, 6850, 6851,
    6852, 6853, 6854, 6855, 6856, 6857, 6858, 6859, 6860, 6861, 6862, 6863, 6864, 6865, 6866, 6867,
    6868, 6869, 6870, 6871, 6872, 6873, 6874, 6875, 6876, 6877, 6878, 6879, 6880, 6881, 6882, 6883,
    6884, 6885, 6886, 6887, 6888, 6889, 6890, 6891, 6892, 6893, 6894, 6895, 6896, 6897, 6898, 6899,
    6900, 6901, 6902, 6903, 6904, 6905, 6906, 6907, 6908, 6909, 6910, 6911, 6912, 6913, 6914, 6915,
    6916, 6917, 6918, 6919, 6920, 6921, 6922, 6923, 6924, 6925, 6926, 6927, 6928, 6929, 6930, 6931,
    6932, 6933, 6934, 6935, 6936, 6937, 0,    0,    6938, 6939, 6940, 6941, 6942, 6943, 6944, 6945,
    6946, 6947, 6948, 6949, 6950, 6951, 6952, 6953, 6954, 6955, 6956, 6957, 6958, 6959, 6960, 6961,
    6962, 6963, 6964, 6965, 6966, 6967, 6968, 6969, 6970, 6971, 6972, 6973, 6974, 6975, 6976, 6977,
    6978, 6979, 6980, 6981, 6982, 6983, 6984, 6985, 6986, 6987, 6988, 6989, 6990, 6991, 6992, 6993,
    6994, 6995, 6996, 6997, 6998, 6999, 7000, 7001, 7002, 7003, 7004, 7005, 7006, 7007, 7008, 7009,
    7010, 7011, 7012, 7013, 7014, 7015, 7016, 7017, 7018, 7019, 7020, 7021, 7022, 7023, 7024, 7025,
    7026, 7027, 7028, 7029, 7030, 7031, 7032, 7033, 7034, 7035, 7036, 7037, 7038, 7039, 7040, 7041,
    7042, 7043, 7044, 7045, 7046, 7047, 7048, 7049, 7050, 7051, 7052, 7053, 7054, 7055, 7056, 7057,
    7058, 7059, 7060, 7061, 7062, 7063, 7064, 7065, 7066, 7067, 7068, 7069, 7070, 7071, 7072, 7073,
    7074, 7075, 7076, 7077, 7078, 7079, 7080, 7081, 7082, 7083, 7084, 7085, 7086, 7087, 7088, 7089,
    7090, 7091, 7092, 7093, 7094, 7095, 7096, 7097, 7098, 7099, 7100, 7101, 7102, 7103, 7104, 7105,
    7106, 7107, 7108, 7109, 7110, 7111, 7112, 7113, 7114, 7115, 7116, 7117, 7118, 7119, 7120, 7121,
    7122, 7123, 7124, 7125, 7126, 7127, 7128, 7129, 7130, 7131, 7132, 7133, 7134, 7135, 7136, 7137,
    7138, 7139, 7140, 7141, 7142, 7143, 7144, 7145, 7146, 7147, 7148, 7149, 7150, 7151, 7152, 7153,
    7154, 7155, 7156, 7157, 7158, 7159, 7160, 7161, 7162, 7163, 7164, 7165, 7166, 7167, 7168, 7169,
    7170, 7171, 7172, 7173, 7174, 7175, 7176, 7177, 7178, 7179, 7180, 7181, 7182, 7183, 7184, 7185,
    7186, 7187, 7188, 7189, 7190, 7191, 7192, 7193, 7194, 7195, 7196, 7197, 7198, 7199, 7200, 7201,
    7202, 7203, 7204, 7205, 7206, 7207, 7208, 7209, 7210, 7211, 7212, 7213, 7214, 7215, 7216, 7217,
    7218, 7219, 7220, 7221, 7222, 7223, 7224, 7225, 7226, 7227, 7228, 7229, 0,    0,    7230, 7231,
    7232, 7233, 7234, 7235, 7236, 7237, 7238, 7239, 7240, 7241, 7242, 7243, 7244, 7245, 7246, 7247,
    7248, 7249, 7250, 7251, 7252, 7253, 7254, 7255, 7256, 7257, 7258, 7259, 7260, 7261, 7262, 7263,
    7264, 7265, 7266, 7267, 7268, 7269, 7270, 7271, 7272, 7273, 7274, 7275, 7276, 7277, 7278, 7279,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  70,   70,   70,   70,   544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  70,   70,   70,
    70,   70,   70,   70,   70,   544,  70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   544,  70,   70,   5,    5,    5,    5,    5,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    544,  544,  544,  544,  544,
    0,    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  333,  206,  206,  206,  206,  206,
    206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  206,  0,
    0,    0,    0,    0,    0,    206,  206,  206,  206,  206,  206,  0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    530,  530,  530,  530,  530,  530,  530,  0,    530,  530,  530,  530,  530,  530,  530,  530,
    530,  530,  530,  530,  530,  530,  530,  530,  530,  0,    0,    530,  530,  530,  530,  530,
    530,  530,  0,    530,  530,  0,    530,  530,  530,  530,  530,  0,    0,    0,    0,    0,
    7280, 7281, 7282, 7283, 7284, 7285, 7286, 7287, 7288, 7289, 7290, 7291, 7292, 7293, 7294, 7295,
    7296, 7297, 7298, 7299, 7300, 7301, 7302, 7303, 7304, 7305, 7306, 7307, 7308, 7309, 7310, 7311,
    7312, 7313, 7314, 7315, 7316, 7317, 7318, 7319, 7320, 7321, 7322, 7323, 7324, 7325, 7326, 7327,
    7328, 7329, 7330, 7331, 7332, 7333, 7334, 7335, 7336, 7337, 7338, 7339, 7340, 7341, 0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    530,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,
    530,  530,  530,  530,  530,  530,  530,  517,  517,  517,  517,  517,  517,  517,  0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    333,  70,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  530,  0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  530,  530,  530,  530,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    6,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  517,  531,  531,  532,  530,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  530,  532,
    333,  11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    5,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,
    333,  333,  333,  530,  333,  333,  530,  333,  333,  333,  333,  333,  333,  333,  530,  530,
    333,  333,  333,  333,  333,  530,  0,    0,    0,    0,    0,    0,    0,    0,    333,  517,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  0,    333,  333,  333,  333,  0,    333,  333,  0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  0,    0,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    532,  532,  532,  532,  532,  532,  532,  0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    7342, 7343, 7344, 7345, 7346, 7347, 7348, 7349, 7350, 7351, 7352, 7353, 7354, 7355, 7356, 7357,
    7358, 7359, 7360, 7361, 7362, 7363, 7364, 7365, 7366, 7367, 7368, 7369, 7370, 7371, 7372, 7373,
    7374, 7375, 7376, 7377, 7378, 7379, 7380, 7381, 7382, 7383, 7384, 7385, 7386, 7387, 7388, 7389,
    7390, 7391, 7392, 7393, 7394, 7395, 7396, 7397, 7398, 7399, 7400, 7401, 7402, 7403, 7404, 7405,
    7406, 7407, 7408, 7409, 530,  530,  530,  530,  530,  530,  1118, 517,  0,    0,    0,    0,
    11,   11,   11,   11,   11,   11,   11,   11,   11,   11,   0,    0,    0,    0,    5,    5,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 70,   1126, 1126, 1126,
    6,    1126, 1126, 1126, 1126, 0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 70,   1126,
    1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 1126, 0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    7410, 7411, 7412, 7413, 0,    7414, 7415, 7416, 7417, 7418, 7419, 7420, 7421, 7422, 7423, 7424,
    7425, 7426, 7427, 7428, 7429, 7430, 7431, 7432, 7433, 7434, 7435, 7436, 7437, 7438, 7439, 7440,
    0,    7441, 7442, 0,    7443, 0,    0,    7444, 0,    7445, 7446, 7447, 7448, 7449, 7450, 7451,
    7452, 7453, 7454, 0,    7455, 7456, 7457, 7458, 0,    7459, 0,    7460, 0,    0,    0,    0,
    0,    0,    7461, 0,    0,    0,    0,    7462, 0,    7463, 0,    7464, 0,    7465, 7466, 7467,
    0,    7468, 7469, 0,    7470, 0,    0,    7471, 0,    7472, 0,    7473, 0,    7474, 0,    7475,
    0,    7476, 7477, 0,    7478, 0,    0,    7479, 7480, 7481, 7482, 0,    7483, 7484, 7485, 7486,
    7487, 7488, 7489, 0,    7490, 7491, 7492, 7493, 0,    7494, 7495, 7496, 7497, 0,    7498, 0,
    7499, 7500, 7501, 7502, 7503, 7504, 7505, 7506, 7507, 7508, 0,    7509, 7510, 7511, 7512, 7513,
    7514, 7515, 7516, 7517, 7518, 7519, 7520, 7521, 7522, 7523, 7524, 7525, 0,    0,    0,    0,
    0,    7526, 7527, 7528, 0,    7529, 7530, 7531, 7532, 7533, 0,    7534, 7535, 7536, 7537, 7538,
    7539, 7540, 7541, 7542, 7543, 7544, 7545, 7546, 7547, 7548, 7549, 7550, 0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    9,    9,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    70,   70,   70,   70,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   8243, 8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   8243,
    8243, 70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    8243, 70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,
    8243, 70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    7551, 7552, 7553, 7554, 7555, 7556, 7557, 7558, 7559, 7560, 7561, 1126, 1126, 70,   70,   70,
    7562, 7563, 7564, 7565, 7566, 7567, 7568, 7569, 7570, 7571, 7572, 7573, 7574, 7575, 7576, 7577,
    7578, 7579, 7580, 7581, 7582, 7583, 7584, 7585, 7586, 7587, 7588, 7589, 7590, 7591, 7592, 70,
    7593, 7594, 7595, 7596, 7597, 7598, 7599, 7600, 7601, 7602, 7603, 7604, 7605, 7606, 7607, 7608,
    7609, 7610, 7611, 7612, 7613, 7614, 7615, 7616, 7617, 7618, 7619, 7620, 7621, 7622, 7623, 7624,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   7625, 7626, 7627, 70,   70,   70,
    72,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   72,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   70,
    7628, 72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629,
    7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629, 7629,
    7630, 7631, 7632, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    7633, 7634, 7635, 7636, 7637, 7638, 7639, 7640, 7641, 7642, 7643, 7644, 7645, 7646, 7647, 7648,
    7649, 7650, 7651, 7652, 7653, 7654, 7655, 7656, 7657, 7658, 7659, 7660, 7661, 7662, 7663, 7664,
    7665, 7666, 7667, 7668, 7669, 7670, 7671, 7672, 7673, 7674, 7675, 7676, 8243, 8243, 8243, 8243,
    7677, 7678, 7679, 7680, 7681, 7682, 7683, 7684, 7685, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    7686, 7687, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   70,   70,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   70,   70,   72,   72,   70,   72,   72,   72,   70,   70,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   70,   70,   72,   72,   72,   70,   72,   72,   72,   72,   7688, 7688, 7688, 7688, 7688,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   70,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   72,   72,   72,   72,   72,   70,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   70,   70,   70,   70,   70,   70,   70,   72,
    72,   70,   70,   72,   72,   72,   72,   72,   72,   72,   72,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   72,   70,   70,   72,   72,   72,   72,   70,   70,
    72,   70,   70,   70,   70,   72,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   72,   72,   70,   70,   72,   70,   70,   70,   70,   70,   70,   70,
    70,   72,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   70,   70,   70,
    70,   70,   72,   72,   72,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   72,   72,   72,   70,   70,   70,   70,   70,   70,   70,   70,   72,   72,   72,   70,
    70,   72,   70,   72,   70,   70,   70,   70,   72,   70,   70,   70,   70,   70,   70,   72,
    70,   70,   70,   72,   70,   70,   70,   70,   70,   70,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   70,   70,   70,   70,   70,   72,   72,   72,   72,   72,
    72,   72,   72,   70,   70,   72,   72,   72,   72,   8243, 8243, 8243, 72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   70,   70,   70,   72,   70,   72,   72,   8243, 8243, 8243,
    72,   70,   70,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   8243, 8243, 8243, 8243, 8243, 8243,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   8243, 8243, 8243, 8243,
    72,   8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   8243, 8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   8243, 8243, 8243, 8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   8243, 8243, 8243, 8243,
    70,   70,   8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    9,    9,    9,    9,    9,    9,    9,    9,    9,    8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   70,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   70,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   8243, 8243,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   8243, 8243, 8243,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   8243, 8243, 8243, 72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   8243, 72,   8243, 8243, 8243, 8243, 72,   72,   72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   8243, 8243, 72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,   8243, 8243, 8243, 8243, 72,
    72,   72,   72,   72,   72,   72,   72,   72,   72,   8243, 8243, 8243, 8243, 8243, 8243, 8243,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   0,    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
    7689, 7690, 7691, 7692, 7693, 7694, 7695, 7696, 7697, 7698, 70,   0,    0,    0,    0,    0,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243,
    8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 8243, 0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    7699, 7700, 7701, 7702, 7703, 7704, 7705, 7706, 7707, 7708, 7709, 7710, 7711, 7712, 7713, 7714,
    7715, 7716, 7717, 7718, 7719, 7720, 7721, 7722, 7723, 7724, 7725, 7726, 7727, 7728, 7729, 7730,
    7731, 7732, 7733, 7734, 7735, 7736, 7737, 7738, 7739, 7740, 7741, 7742, 7743, 7744, 7745, 7746,
    7747, 7748, 7749, 7750, 7751, 7752, 7753, 7754, 7755, 7756, 7757, 7758, 7759, 7760, 7761, 7762,
    7763, 7764, 7765, 7766, 7767, 7768, 7769, 7770, 7771, 7772, 7773, 7774, 7775, 7776, 7777, 7778,
    7779, 7780, 7781, 7782, 7783, 7784, 7785, 7786, 7787, 7788, 7789, 7790, 7791, 7792, 7793, 7794,
    7795, 7796, 7797, 7798, 7799, 7800, 7801, 7802, 7803, 7804, 7805, 7806, 7807, 7808, 7809, 7810,
    7811, 7812, 7813, 7814, 7815, 7816, 7817, 7818, 7819, 7820, 7821, 7822, 7823, 7824, 7825, 7826,
    7827, 7828, 7829, 7830, 7831, 7832, 7833, 7834, 7835, 7836, 7837, 7838, 7839, 7840, 7841, 7842,
    7843, 7844, 7845, 7846, 7847, 7848, 7849, 7850, 7851, 7852, 7853, 7854, 7855, 7856, 7857, 7858,
    7859, 7860, 7861, 7862, 7863, 7864, 7865, 7866, 7867, 7868, 7869, 7870, 7871, 7872, 7873, 7874,
    7875, 7876, 7877, 7878, 7879, 7880, 7881, 7882, 7883, 7884, 7885, 7886, 7887, 7888, 7889, 7890,
    7891, 7892, 7893, 7894, 7895, 7896, 7897, 7898, 7899, 7900, 7901, 7902, 7903, 7904, 7905, 7906,
    7907, 7908, 7909, 7910, 7911, 7912, 7913, 7914, 7915, 7916, 7917, 7918, 7919, 7920, 7921, 7922,
    7923, 7924, 7925, 7926, 7927, 7928, 7929, 7930, 7931, 7932, 7933, 7934, 7935, 7936, 7937, 7938,
    7939, 7940, 7941, 7942, 7943, 7944, 7945, 7946, 7947, 7948, 7949, 7950, 7951, 7952, 7953, 7954,
    7955, 7956, 7957, 7958, 7959, 7960, 7961, 7962, 7963, 7964, 7965, 7966, 7967, 7968, 7969, 7970,
    7971, 7972, 7973, 7974, 7975, 7976, 7977, 7978, 7979, 7980, 7981, 7982, 7983, 7984, 7985, 7986,
    7987, 7988, 7989, 7990, 7991, 7992, 7993, 7994, 7995, 7996, 7997, 7998, 7999, 8000, 8001, 8002,
    8003, 8004, 8005, 8006, 8007, 8008, 8009, 8010, 8011, 8012, 8013, 8014, 8015, 8016, 8017, 8018,
    8019, 8020, 8021, 8022, 8023, 8024, 8025, 8026, 8027, 8028, 8029, 8030, 8031, 8032, 8033, 8034,
    8035, 8036, 8037, 8038, 8039, 8040, 8041, 8042, 8043, 8044, 8045, 8046, 8047, 8048, 8049, 8050,
    8051, 8052, 8053, 8054, 8055, 8056, 8057, 8058, 8059, 8060, 8061, 8062, 8063, 8064, 8065, 8066,
    8067, 8068, 8069, 8070, 8071, 8072, 8073, 8074, 8075, 8076, 8077, 8078, 8079, 8080, 8081, 8082,
    8083, 8084, 8085, 8086, 8087, 8088, 8089, 8090, 8091, 8092, 8093, 8094, 8095, 8096, 8097, 8098,
    8099, 8100, 8101, 8102, 8103, 8104, 8105, 8106, 8107, 8108, 8109, 8110, 8111, 8112, 8113, 8114,
    8115, 8116, 8117, 8118, 8119, 8120, 8121, 8122, 8123, 8124, 8125, 8126, 8127, 8128, 8129, 8130,
    8131, 8132, 8133, 8134, 8135, 8136, 8137, 8138, 8139, 8140, 8141, 8142, 8143, 8144, 8145, 8146,
    8147, 8148, 8149, 8150, 8151, 8152, 8153, 8154, 8155, 8156, 8157, 8158, 8159, 8160, 8161, 8162,
    8163, 8164, 8165, 8166, 8167, 8168, 8169, 8170, 8171, 8172, 8173, 8174, 8175, 8176, 8177, 8178,
    8179, 8180, 8181, 8182, 8183, 8184, 8185, 8186, 8187, 8188, 8189, 8190, 8191, 8192, 8193, 8194,
    8195, 8196, 8197, 8198, 8199, 8200, 8201, 8202, 8203, 8204, 8205, 8206, 8207, 8208, 8209, 8210,
    8211, 8212, 8213, 8214, 8215, 8216, 8217, 8218, 8219, 8220, 8221, 8222, 8223, 8224, 8225, 8226,
    8227, 8228, 8229, 8230, 8231, 8232, 8233, 8234, 8235, 8236, 8237, 8238, 8239, 8240, 0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  333,
    333,  333,  333,  333,  333,  333,  333,  333,  333,  333,  0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    8242, 75,   8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241,
    8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241,
    8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241,
    8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241,
    8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241,
    8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241, 8241,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,  544,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242, 8242,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035,
    4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 4035, 0,    0};

static const uint8_t s_tinyucd_stage1_table[TINYUCD_NUM_STAGE1] = {
    0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14,  15,  16,  17,  18,
    19,  20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,
    38,  39,  40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  52,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  53,  21,  21,  21,  54,  21,  55,  56,  57,  58,  59,
    60,  61,  62,  63,  64,  65,  66,  67,  61,  62,  63,  64,  65,  66,  67,  61,  62,  63,  64,
    65,  66,  67,  61,  62,  63,  64,  65,  66,  67,  61,  62,  63,  64,  65,  66,  67,  61,  62,
    63,  64,  65,  66,  67,  61,  68,  69,  69,  69,  69,  69,  69,  69,  69,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  71,  72,  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,  83,  21,  84,  85,  86,
    87,  88,  89,  90,  91,  92,  93,  94,  95,  96,  97,  98,  99,  100, 101, 102, 103, 104, 105,
    106, 107, 108, 21,  21,  21,  109, 110, 111, 112, 112, 112, 112, 112, 112, 112, 112, 112, 113,
    21,  21,  21,  21,  114, 21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    115, 21,  21,  116, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 117, 112, 112, 112, 112, 112, 112, 21,
    21,  118, 119, 112, 120, 121, 122, 21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  123, 124, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 125, 21,  126, 127, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 128, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 129, 40,  130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 40,  40,  140,
    112, 112, 112, 112, 141, 142, 143, 144, 112, 145, 146, 147, 148, 149, 150, 112, 112, 151, 152,
    153, 112, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 166, 166, 167, 21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  168, 21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  169, 21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  170, 21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  171, 21,  21,  172, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    173, 174, 175, 112, 112, 112, 112, 112, 21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  176, 21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,  21,
    21,  21,  21,  177, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 178, 179, 180, 180, 180, 180, 180,
    180, 180, 180, 180, 180, 180, 180, 180, 180, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112, 112,
    112, 112, 70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  181, 70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    181};

#endif // TINYUC_DATA_UNICODE_TABLE_H
