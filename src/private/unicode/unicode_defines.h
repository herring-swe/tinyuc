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

#ifndef TINYUC_DATA_UNICODE_DEF_H
#define TINYUC_DATA_UNICODE_DEF_H

#include <tinyuc/diag.h>

/*
 * Additional data is included to verify design assumptions.
 * This is removed to save space in release versions.
 */
#ifndef TINYUCD_WITH_VERIF
#define TINYUCD_WITH_VERIF 1
#endif

#define TINYUCD_NO_VALUE 0xFFFF

// Max folding values in entries
#define TINYUCD_MAX_MULTI_LEN 3

// Covered codepoints
#define TINYUCD_NUM_CODEPOINTS 304604

// Blocksize used for lookup tables
#define TINYUCD_BLOCK_SIZE 256

// Table sizes
#define TINYUCD_NUM_STAGE1 4352
#define TINYUCD_NUM_STAGE2 46592
#define TINYUCD_NUM_PROPERTIES 8244
#define TINYUCD_NUM_SIMPLE_MAP 2961
#define TINYUCD_NUM_MULTI_MAP 73
#define TINYUCD_NUM_MAPPING 3037
#define TINYUCD_NUM_DECOMP 5914
#define TINYUCD_NUM_COMBINER 391

/**
 * General Categories
 */
typedef enum tinyucd_gc
{
    TINYUCD_GC_LU = 0,  // Uppercase letter
    TINYUCD_GC_LL = 1,  // Lowercase letter
    TINYUCD_GC_LT = 2,  // Titlecase letter
    TINYUCD_GC_LM = 3,  // Modifier letter
    TINYUCD_GC_LO = 4,  // Other letter
    TINYUCD_GC_MN = 5,  // Nonspacing mark
    TINYUCD_GC_MC = 6,  // Spacing combining mark
    TINYUCD_GC_ME = 7,  // Enclosing mark
    TINYUCD_GC_ND = 8,  // Decimal digit number
    TINYUCD_GC_NL = 9,  // Letter like number
    TINYUCD_GC_NO = 10, // Other number
    TINYUCD_GC_PC = 11, // Connector punctuation
    TINYUCD_GC_PD = 12, // Dash punctuation
    TINYUCD_GC_PS = 13, // Open punctuation
    TINYUCD_GC_PE = 14, // Close punctuation
    TINYUCD_GC_PI = 15, // Initial quote punctuation
    TINYUCD_GC_PF = 16, // Final quote punctuation
    TINYUCD_GC_PO = 17, // Other punctuation
    TINYUCD_GC_SM = 18, // Math symbol
    TINYUCD_GC_SC = 19, // Currency symbol
    TINYUCD_GC_SK = 20, // Modifier symbol
    TINYUCD_GC_SO = 21, // Other symbol
    TINYUCD_GC_ZS = 22, // Whitespace
    TINYUCD_GC_ZL = 23, // Line separator
    TINYUCD_GC_ZP = 24, // Paragraph separator
    TINYUCD_GC_CC = 25, // Control character
    TINYUCD_GC_CF = 26, // Control Format
    TINYUCD_GC_CS = 27, // Control Surrogate
    TINYUCD_GC_CO = 28, // Control private Use
    TINYUCD_GC_CN = 29, // Control unassigned
} tinyucd_gc;

/**
 * Decomposition types
 */
typedef enum tinyucd_dctype
{
    TINYUCD_DC_CANON = 0,   // Canonical decomposition (not tagged in UnicodeData.txt)
    TINYUCD_DC_FONT = 1,    // Font variant
    TINYUCD_DC_NOBRK = 2,   // No-break version of a space or hyphen
    TINYUCD_DC_INIT = 3,    // Initial presentation form (Arabic)
    TINYUCD_DC_MEDIAL = 4,  // Medial presentation form (Arabic)
    TINYUCD_DC_FINAL = 5,   // Final presentation form (Arabic)
    TINYUCD_DC_ISOL = 6,    // Isolated presentation form (Arabic)
    TINYUCD_DC_CIRCLE = 7,  // Encircled form
    TINYUCD_DC_SUPER = 8,   // Superscript form
    TINYUCD_DC_SUB = 9,     // Subscript form
    TINYUCD_DC_VERT = 10,   // Vertical layout presentation form
    TINYUCD_DC_WIDE = 11,   // Wide (or zenkaku) compatibility character
    TINYUCD_DC_NARROW = 12, // Narrow (or hankaku) compatibility character
    TINYUCD_DC_SMALL = 13,  // Small variant form (CNS compatibility)
    TINYUCD_DC_SQUARE = 14, // CJK squared font variant
    TINYUCD_DC_FRACT = 15,  // Vulgar fraction form
    TINYUCD_DC_COMPAT = 16, // Otherwise unspecified compatibility character
} tinyucd_dctype;

/**
 * Grapheme cluster break (UAX #29)
 */
typedef enum tinyucd_gcb
{
    TINYUCD_GCB_OTHER = 0,              // Any other code point
    TINYUCD_GCB_CR = 1,                 // Carriage return
    TINYUCD_GCB_LF = 2,                 // Line feed
    TINYUCD_GCB_CONTROL = 3,            // Control character
    TINYUCD_GCB_EXTEND = 4,             // Grapheme extend
    TINYUCD_GCB_ZWJ = 5,                // Zero width joiner
    TINYUCD_GCB_REGIONAL_INDICATOR = 6, // Regional indicator
    TINYUCD_GCB_PREPEND = 7,            // Prepend character
    TINYUCD_GCB_SPACINGMARK = 8,        // Spacing combining mark
    TINYUCD_GCB_L = 9,                  // Hangul leading jamo
    TINYUCD_GCB_V = 10,                 // Hangul vowel jamo
    TINYUCD_GCB_T = 11,                 // Hangul trailing jamo
    TINYUCD_GCB_LV = 12,                // Hangul LV syllable
    TINYUCD_GCB_LVT = 13,               // Hangul LVT syllable
} tinyucd_gcb;

/**
 * Indic conjunct break (UAX #29, GB9c)
 */
typedef enum tinyucd_incb
{
    TINYUCD_INCB_NONE = 0,      // Not part of an Indic conjunct
    TINYUCD_INCB_CONSONANT = 1, // Indic consonant
    TINYUCD_INCB_EXTEND = 2,    // Indic conjunct extend
    TINYUCD_INCB_LINKER = 3,    // Indic conjunct linker
} tinyucd_incb;

// General category macros
#define TINYUCD_IS_LETTER(c) ((c) >= TINYUCD_GC_LU && (c) <= TINYUCD_GC_LO)
#define TINYUCD_IS_MARK(c) ((c) >= TINYUCD_GC_MN && (c) <= TINYUCD_GC_ME)
#define TINYUCD_IS_NUMBER(c) ((c) >= TINYUCD_GC_ND && (c) <= TINYUCD_GC_NO)
#define TINYUCD_IS_PUNCTUATION(c) ((c) >= TINYUCD_GC_PC && (c) <= TINYUCD_GC_PO)
#define TINYUCD_IS_SYMBOL(c) ((c) >= TINYUCD_GC_SM && (c) <= TINYUCD_GC_SO)
#define TINYUCD_IS_SEPARATOR(c) ((c) >= TINYUCD_GC_ZS && (c) <= TINYUCD_GC_ZP)
#define TINYUCD_IS_OTHER(c) ((c) >= TINYUCD_GC_CC && (c) <= TINYUCD_GC_CN)

// Specialized macros
#define TINYUCD_IS_ALPHA(c) TINYUCD_IS_LETTER(c)
// Exclude NO
#define TINYUCD_IS_NUMERIC(c) ((c) >= TINYUCD_GC_ND && (c) <= TINYUCD_GC_NL)
#define TINYUCD_IS_ALPHANUMERIC(c) (TINYUCD_IS_LETTER(c) || TINYUCD_IS_NUMBER(c))
#define TINYUCD_IS_WHITESPACE(c) TINYUCD_IS_SEPARATOR(c)

#endif // TINYUC_DATA_UNICODE_DEF_H
