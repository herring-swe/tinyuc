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

#ifndef TINYUC_DATA_UNICODE_COMBINE_H
#define TINYUC_DATA_UNICODE_COMBINE_H

#include "unicode_defines.h"

#include <stdint.h>


typedef struct {
    uint32_t combiner;
    uint32_t composed;
} tinyucd_combiner_entry;

TINYUC_DIAG_PUSH()
TINYUC_DIAG_IGN_PADDED()
typedef struct
{
#ifdef TINYUCD_WITH_VERIF
    uint32_t starter; // Original starter codepoint
#endif
    uint8_t len; // Number of combiners (only canonical)
    const tinyucd_combiner_entry* entries; // Pointer entry table, which is sorted by combiner
} tinyucd_combiners;
TINYUC_DIAG_POP()

static const tinyucd_combiner_entry s_combiner_entries_00003c[1] = {
    {   0x0338,   0x226E }
};
static const tinyucd_combiner_entry s_combiner_entries_00003d[1] = {
    {   0x0338,   0x2260 }
};
static const tinyucd_combiner_entry s_combiner_entries_00003e[1] = {
    {   0x0338,   0x226F }
};
static const tinyucd_combiner_entry s_combiner_entries_000041[16] = {
    {   0x0300,   0x00C0 },
    {   0x0301,   0x00C1 },
    {   0x0302,   0x00C2 },
    {   0x0303,   0x00C3 },
    {   0x0304,   0x0100 },
    {   0x0306,   0x0102 },
    {   0x0307,   0x0226 },
    {   0x0308,   0x00C4 },
    {   0x0309,   0x1EA2 },
    {   0x030A,   0x00C5 },
    {   0x030C,   0x01CD },
    {   0x030F,   0x0200 },
    {   0x0311,   0x0202 },
    {   0x0323,   0x1EA0 },
    {   0x0325,   0x1E00 },
    {   0x0328,   0x0104 }
};
static const tinyucd_combiner_entry s_combiner_entries_000042[3] = {
    {   0x0307,   0x1E02 },
    {   0x0323,   0x1E04 },
    {   0x0331,   0x1E06 }
};
static const tinyucd_combiner_entry s_combiner_entries_000043[5] = {
    {   0x0301,   0x0106 },
    {   0x0302,   0x0108 },
    {   0x0307,   0x010A },
    {   0x030C,   0x010C },
    {   0x0327,   0x00C7 }
};
static const tinyucd_combiner_entry s_combiner_entries_000044[6] = {
    {   0x0307,   0x1E0A },
    {   0x030C,   0x010E },
    {   0x0323,   0x1E0C },
    {   0x0327,   0x1E10 },
    {   0x032D,   0x1E12 },
    {   0x0331,   0x1E0E }
};
static const tinyucd_combiner_entry s_combiner_entries_000045[17] = {
    {   0x0300,   0x00C8 },
    {   0x0301,   0x00C9 },
    {   0x0302,   0x00CA },
    {   0x0303,   0x1EBC },
    {   0x0304,   0x0112 },
    {   0x0306,   0x0114 },
    {   0x0307,   0x0116 },
    {   0x0308,   0x00CB },
    {   0x0309,   0x1EBA },
    {   0x030C,   0x011A },
    {   0x030F,   0x0204 },
    {   0x0311,   0x0206 },
    {   0x0323,   0x1EB8 },
    {   0x0327,   0x0228 },
    {   0x0328,   0x0118 },
    {   0x032D,   0x1E18 },
    {   0x0330,   0x1E1A }
};
static const tinyucd_combiner_entry s_combiner_entries_000046[1] = {
    {   0x0307,   0x1E1E }
};
static const tinyucd_combiner_entry s_combiner_entries_000047[7] = {
    {   0x0301,   0x01F4 },
    {   0x0302,   0x011C },
    {   0x0304,   0x1E20 },
    {   0x0306,   0x011E },
    {   0x0307,   0x0120 },
    {   0x030C,   0x01E6 },
    {   0x0327,   0x0122 }
};
static const tinyucd_combiner_entry s_combiner_entries_000048[7] = {
    {   0x0302,   0x0124 },
    {   0x0307,   0x1E22 },
    {   0x0308,   0x1E26 },
    {   0x030C,   0x021E },
    {   0x0323,   0x1E24 },
    {   0x0327,   0x1E28 },
    {   0x032E,   0x1E2A }
};
static const tinyucd_combiner_entry s_combiner_entries_000049[15] = {
    {   0x0300,   0x00CC },
    {   0x0301,   0x00CD },
    {   0x0302,   0x00CE },
    {   0x0303,   0x0128 },
    {   0x0304,   0x012A },
    {   0x0306,   0x012C },
    {   0x0307,   0x0130 },
    {   0x0308,   0x00CF },
    {   0x0309,   0x1EC8 },
    {   0x030C,   0x01CF },
    {   0x030F,   0x0208 },
    {   0x0311,   0x020A },
    {   0x0323,   0x1ECA },
    {   0x0328,   0x012E },
    {   0x0330,   0x1E2C }
};
static const tinyucd_combiner_entry s_combiner_entries_00004a[1] = {
    {   0x0302,   0x0134 }
};
static const tinyucd_combiner_entry s_combiner_entries_00004b[5] = {
    {   0x0301,   0x1E30 },
    {   0x030C,   0x01E8 },
    {   0x0323,   0x1E32 },
    {   0x0327,   0x0136 },
    {   0x0331,   0x1E34 }
};
static const tinyucd_combiner_entry s_combiner_entries_00004c[6] = {
    {   0x0301,   0x0139 },
    {   0x030C,   0x013D },
    {   0x0323,   0x1E36 },
    {   0x0327,   0x013B },
    {   0x032D,   0x1E3C },
    {   0x0331,   0x1E3A }
};
static const tinyucd_combiner_entry s_combiner_entries_00004d[3] = {
    {   0x0301,   0x1E3E },
    {   0x0307,   0x1E40 },
    {   0x0323,   0x1E42 }
};
static const tinyucd_combiner_entry s_combiner_entries_00004e[9] = {
    {   0x0300,   0x01F8 },
    {   0x0301,   0x0143 },
    {   0x0303,   0x00D1 },
    {   0x0307,   0x1E44 },
    {   0x030C,   0x0147 },
    {   0x0323,   0x1E46 },
    {   0x0327,   0x0145 },
    {   0x032D,   0x1E4A },
    {   0x0331,   0x1E48 }
};
static const tinyucd_combiner_entry s_combiner_entries_00004f[16] = {
    {   0x0300,   0x00D2 },
    {   0x0301,   0x00D3 },
    {   0x0302,   0x00D4 },
    {   0x0303,   0x00D5 },
    {   0x0304,   0x014C },
    {   0x0306,   0x014E },
    {   0x0307,   0x022E },
    {   0x0308,   0x00D6 },
    {   0x0309,   0x1ECE },
    {   0x030B,   0x0150 },
    {   0x030C,   0x01D1 },
    {   0x030F,   0x020C },
    {   0x0311,   0x020E },
    {   0x031B,   0x01A0 },
    {   0x0323,   0x1ECC },
    {   0x0328,   0x01EA }
};
static const tinyucd_combiner_entry s_combiner_entries_000050[2] = {
    {   0x0301,   0x1E54 },
    {   0x0307,   0x1E56 }
};
static const tinyucd_combiner_entry s_combiner_entries_000052[8] = {
    {   0x0301,   0x0154 },
    {   0x0307,   0x1E58 },
    {   0x030C,   0x0158 },
    {   0x030F,   0x0210 },
    {   0x0311,   0x0212 },
    {   0x0323,   0x1E5A },
    {   0x0327,   0x0156 },
    {   0x0331,   0x1E5E }
};
static const tinyucd_combiner_entry s_combiner_entries_000053[7] = {
    {   0x0301,   0x015A },
    {   0x0302,   0x015C },
    {   0x0307,   0x1E60 },
    {   0x030C,   0x0160 },
    {   0x0323,   0x1E62 },
    {   0x0326,   0x0218 },
    {   0x0327,   0x015E }
};
static const tinyucd_combiner_entry s_combiner_entries_000054[7] = {
    {   0x0307,   0x1E6A },
    {   0x030C,   0x0164 },
    {   0x0323,   0x1E6C },
    {   0x0326,   0x021A },
    {   0x0327,   0x0162 },
    {   0x032D,   0x1E70 },
    {   0x0331,   0x1E6E }
};
static const tinyucd_combiner_entry s_combiner_entries_000055[19] = {
    {   0x0300,   0x00D9 },
    {   0x0301,   0x00DA },
    {   0x0302,   0x00DB },
    {   0x0303,   0x0168 },
    {   0x0304,   0x016A },
    {   0x0306,   0x016C },
    {   0x0308,   0x00DC },
    {   0x0309,   0x1EE6 },
    {   0x030A,   0x016E },
    {   0x030B,   0x0170 },
    {   0x030C,   0x01D3 },
    {   0x030F,   0x0214 },
    {   0x0311,   0x0216 },
    {   0x031B,   0x01AF },
    {   0x0323,   0x1EE4 },
    {   0x0324,   0x1E72 },
    {   0x0328,   0x0172 },
    {   0x032D,   0x1E76 },
    {   0x0330,   0x1E74 }
};
static const tinyucd_combiner_entry s_combiner_entries_000056[2] = {
    {   0x0303,   0x1E7C },
    {   0x0323,   0x1E7E }
};
static const tinyucd_combiner_entry s_combiner_entries_000057[6] = {
    {   0x0300,   0x1E80 },
    {   0x0301,   0x1E82 },
    {   0x0302,   0x0174 },
    {   0x0307,   0x1E86 },
    {   0x0308,   0x1E84 },
    {   0x0323,   0x1E88 }
};
static const tinyucd_combiner_entry s_combiner_entries_000058[2] = {
    {   0x0307,   0x1E8A },
    {   0x0308,   0x1E8C }
};
static const tinyucd_combiner_entry s_combiner_entries_000059[9] = {
    {   0x0300,   0x1EF2 },
    {   0x0301,   0x00DD },
    {   0x0302,   0x0176 },
    {   0x0303,   0x1EF8 },
    {   0x0304,   0x0232 },
    {   0x0307,   0x1E8E },
    {   0x0308,   0x0178 },
    {   0x0309,   0x1EF6 },
    {   0x0323,   0x1EF4 }
};
static const tinyucd_combiner_entry s_combiner_entries_00005a[6] = {
    {   0x0301,   0x0179 },
    {   0x0302,   0x1E90 },
    {   0x0307,   0x017B },
    {   0x030C,   0x017D },
    {   0x0323,   0x1E92 },
    {   0x0331,   0x1E94 }
};
static const tinyucd_combiner_entry s_combiner_entries_000061[16] = {
    {   0x0300,   0x00E0 },
    {   0x0301,   0x00E1 },
    {   0x0302,   0x00E2 },
    {   0x0303,   0x00E3 },
    {   0x0304,   0x0101 },
    {   0x0306,   0x0103 },
    {   0x0307,   0x0227 },
    {   0x0308,   0x00E4 },
    {   0x0309,   0x1EA3 },
    {   0x030A,   0x00E5 },
    {   0x030C,   0x01CE },
    {   0x030F,   0x0201 },
    {   0x0311,   0x0203 },
    {   0x0323,   0x1EA1 },
    {   0x0325,   0x1E01 },
    {   0x0328,   0x0105 }
};
static const tinyucd_combiner_entry s_combiner_entries_000062[3] = {
    {   0x0307,   0x1E03 },
    {   0x0323,   0x1E05 },
    {   0x0331,   0x1E07 }
};
static const tinyucd_combiner_entry s_combiner_entries_000063[5] = {
    {   0x0301,   0x0107 },
    {   0x0302,   0x0109 },
    {   0x0307,   0x010B },
    {   0x030C,   0x010D },
    {   0x0327,   0x00E7 }
};
static const tinyucd_combiner_entry s_combiner_entries_000064[6] = {
    {   0x0307,   0x1E0B },
    {   0x030C,   0x010F },
    {   0x0323,   0x1E0D },
    {   0x0327,   0x1E11 },
    {   0x032D,   0x1E13 },
    {   0x0331,   0x1E0F }
};
static const tinyucd_combiner_entry s_combiner_entries_000065[17] = {
    {   0x0300,   0x00E8 },
    {   0x0301,   0x00E9 },
    {   0x0302,   0x00EA },
    {   0x0303,   0x1EBD },
    {   0x0304,   0x0113 },
    {   0x0306,   0x0115 },
    {   0x0307,   0x0117 },
    {   0x0308,   0x00EB },
    {   0x0309,   0x1EBB },
    {   0x030C,   0x011B },
    {   0x030F,   0x0205 },
    {   0x0311,   0x0207 },
    {   0x0323,   0x1EB9 },
    {   0x0327,   0x0229 },
    {   0x0328,   0x0119 },
    {   0x032D,   0x1E19 },
    {   0x0330,   0x1E1B }
};
static const tinyucd_combiner_entry s_combiner_entries_000066[1] = {
    {   0x0307,   0x1E1F }
};
static const tinyucd_combiner_entry s_combiner_entries_000067[7] = {
    {   0x0301,   0x01F5 },
    {   0x0302,   0x011D },
    {   0x0304,   0x1E21 },
    {   0x0306,   0x011F },
    {   0x0307,   0x0121 },
    {   0x030C,   0x01E7 },
    {   0x0327,   0x0123 }
};
static const tinyucd_combiner_entry s_combiner_entries_000068[8] = {
    {   0x0302,   0x0125 },
    {   0x0307,   0x1E23 },
    {   0x0308,   0x1E27 },
    {   0x030C,   0x021F },
    {   0x0323,   0x1E25 },
    {   0x0327,   0x1E29 },
    {   0x032E,   0x1E2B },
    {   0x0331,   0x1E96 }
};
static const tinyucd_combiner_entry s_combiner_entries_000069[14] = {
    {   0x0300,   0x00EC },
    {   0x0301,   0x00ED },
    {   0x0302,   0x00EE },
    {   0x0303,   0x0129 },
    {   0x0304,   0x012B },
    {   0x0306,   0x012D },
    {   0x0308,   0x00EF },
    {   0x0309,   0x1EC9 },
    {   0x030C,   0x01D0 },
    {   0x030F,   0x0209 },
    {   0x0311,   0x020B },
    {   0x0323,   0x1ECB },
    {   0x0328,   0x012F },
    {   0x0330,   0x1E2D }
};
static const tinyucd_combiner_entry s_combiner_entries_00006a[2] = {
    {   0x0302,   0x0135 },
    {   0x030C,   0x01F0 }
};
static const tinyucd_combiner_entry s_combiner_entries_00006b[5] = {
    {   0x0301,   0x1E31 },
    {   0x030C,   0x01E9 },
    {   0x0323,   0x1E33 },
    {   0x0327,   0x0137 },
    {   0x0331,   0x1E35 }
};
static const tinyucd_combiner_entry s_combiner_entries_00006c[6] = {
    {   0x0301,   0x013A },
    {   0x030C,   0x013E },
    {   0x0323,   0x1E37 },
    {   0x0327,   0x013C },
    {   0x032D,   0x1E3D },
    {   0x0331,   0x1E3B }
};
static const tinyucd_combiner_entry s_combiner_entries_00006d[3] = {
    {   0x0301,   0x1E3F },
    {   0x0307,   0x1E41 },
    {   0x0323,   0x1E43 }
};
static const tinyucd_combiner_entry s_combiner_entries_00006e[9] = {
    {   0x0300,   0x01F9 },
    {   0x0301,   0x0144 },
    {   0x0303,   0x00F1 },
    {   0x0307,   0x1E45 },
    {   0x030C,   0x0148 },
    {   0x0323,   0x1E47 },
    {   0x0327,   0x0146 },
    {   0x032D,   0x1E4B },
    {   0x0331,   0x1E49 }
};
static const tinyucd_combiner_entry s_combiner_entries_00006f[16] = {
    {   0x0300,   0x00F2 },
    {   0x0301,   0x00F3 },
    {   0x0302,   0x00F4 },
    {   0x0303,   0x00F5 },
    {   0x0304,   0x014D },
    {   0x0306,   0x014F },
    {   0x0307,   0x022F },
    {   0x0308,   0x00F6 },
    {   0x0309,   0x1ECF },
    {   0x030B,   0x0151 },
    {   0x030C,   0x01D2 },
    {   0x030F,   0x020D },
    {   0x0311,   0x020F },
    {   0x031B,   0x01A1 },
    {   0x0323,   0x1ECD },
    {   0x0328,   0x01EB }
};
static const tinyucd_combiner_entry s_combiner_entries_000070[2] = {
    {   0x0301,   0x1E55 },
    {   0x0307,   0x1E57 }
};
static const tinyucd_combiner_entry s_combiner_entries_000072[8] = {
    {   0x0301,   0x0155 },
    {   0x0307,   0x1E59 },
    {   0x030C,   0x0159 },
    {   0x030F,   0x0211 },
    {   0x0311,   0x0213 },
    {   0x0323,   0x1E5B },
    {   0x0327,   0x0157 },
    {   0x0331,   0x1E5F }
};
static const tinyucd_combiner_entry s_combiner_entries_000073[7] = {
    {   0x0301,   0x015B },
    {   0x0302,   0x015D },
    {   0x0307,   0x1E61 },
    {   0x030C,   0x0161 },
    {   0x0323,   0x1E63 },
    {   0x0326,   0x0219 },
    {   0x0327,   0x015F }
};
static const tinyucd_combiner_entry s_combiner_entries_000074[8] = {
    {   0x0307,   0x1E6B },
    {   0x0308,   0x1E97 },
    {   0x030C,   0x0165 },
    {   0x0323,   0x1E6D },
    {   0x0326,   0x021B },
    {   0x0327,   0x0163 },
    {   0x032D,   0x1E71 },
    {   0x0331,   0x1E6F }
};
static const tinyucd_combiner_entry s_combiner_entries_000075[19] = {
    {   0x0300,   0x00F9 },
    {   0x0301,   0x00FA },
    {   0x0302,   0x00FB },
    {   0x0303,   0x0169 },
    {   0x0304,   0x016B },
    {   0x0306,   0x016D },
    {   0x0308,   0x00FC },
    {   0x0309,   0x1EE7 },
    {   0x030A,   0x016F },
    {   0x030B,   0x0171 },
    {   0x030C,   0x01D4 },
    {   0x030F,   0x0215 },
    {   0x0311,   0x0217 },
    {   0x031B,   0x01B0 },
    {   0x0323,   0x1EE5 },
    {   0x0324,   0x1E73 },
    {   0x0328,   0x0173 },
    {   0x032D,   0x1E77 },
    {   0x0330,   0x1E75 }
};
static const tinyucd_combiner_entry s_combiner_entries_000076[2] = {
    {   0x0303,   0x1E7D },
    {   0x0323,   0x1E7F }
};
static const tinyucd_combiner_entry s_combiner_entries_000077[7] = {
    {   0x0300,   0x1E81 },
    {   0x0301,   0x1E83 },
    {   0x0302,   0x0175 },
    {   0x0307,   0x1E87 },
    {   0x0308,   0x1E85 },
    {   0x030A,   0x1E98 },
    {   0x0323,   0x1E89 }
};
static const tinyucd_combiner_entry s_combiner_entries_000078[2] = {
    {   0x0307,   0x1E8B },
    {   0x0308,   0x1E8D }
};
static const tinyucd_combiner_entry s_combiner_entries_000079[10] = {
    {   0x0300,   0x1EF3 },
    {   0x0301,   0x00FD },
    {   0x0302,   0x0177 },
    {   0x0303,   0x1EF9 },
    {   0x0304,   0x0233 },
    {   0x0307,   0x1E8F },
    {   0x0308,   0x00FF },
    {   0x0309,   0x1EF7 },
    {   0x030A,   0x1E99 },
    {   0x0323,   0x1EF5 }
};
static const tinyucd_combiner_entry s_combiner_entries_00007a[6] = {
    {   0x0301,   0x017A },
    {   0x0302,   0x1E91 },
    {   0x0307,   0x017C },
    {   0x030C,   0x017E },
    {   0x0323,   0x1E93 },
    {   0x0331,   0x1E95 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000a8[3] = {
    {   0x0300,   0x1FED },
    {   0x0301,   0x0385 },
    {   0x0342,   0x1FC1 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000c2[4] = {
    {   0x0300,   0x1EA6 },
    {   0x0301,   0x1EA4 },
    {   0x0303,   0x1EAA },
    {   0x0309,   0x1EA8 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000c4[1] = {
    {   0x0304,   0x01DE }
};
static const tinyucd_combiner_entry s_combiner_entries_0000c5[1] = {
    {   0x0301,   0x01FA }
};
static const tinyucd_combiner_entry s_combiner_entries_0000c6[2] = {
    {   0x0301,   0x01FC },
    {   0x0304,   0x01E2 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000c7[1] = {
    {   0x0301,   0x1E08 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000ca[4] = {
    {   0x0300,   0x1EC0 },
    {   0x0301,   0x1EBE },
    {   0x0303,   0x1EC4 },
    {   0x0309,   0x1EC2 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000cf[1] = {
    {   0x0301,   0x1E2E }
};
static const tinyucd_combiner_entry s_combiner_entries_0000d4[4] = {
    {   0x0300,   0x1ED2 },
    {   0x0301,   0x1ED0 },
    {   0x0303,   0x1ED6 },
    {   0x0309,   0x1ED4 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000d5[3] = {
    {   0x0301,   0x1E4C },
    {   0x0304,   0x022C },
    {   0x0308,   0x1E4E }
};
static const tinyucd_combiner_entry s_combiner_entries_0000d6[1] = {
    {   0x0304,   0x022A }
};
static const tinyucd_combiner_entry s_combiner_entries_0000d8[1] = {
    {   0x0301,   0x01FE }
};
static const tinyucd_combiner_entry s_combiner_entries_0000dc[4] = {
    {   0x0300,   0x01DB },
    {   0x0301,   0x01D7 },
    {   0x0304,   0x01D5 },
    {   0x030C,   0x01D9 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000e2[4] = {
    {   0x0300,   0x1EA7 },
    {   0x0301,   0x1EA5 },
    {   0x0303,   0x1EAB },
    {   0x0309,   0x1EA9 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000e4[1] = {
    {   0x0304,   0x01DF }
};
static const tinyucd_combiner_entry s_combiner_entries_0000e5[1] = {
    {   0x0301,   0x01FB }
};
static const tinyucd_combiner_entry s_combiner_entries_0000e6[2] = {
    {   0x0301,   0x01FD },
    {   0x0304,   0x01E3 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000e7[1] = {
    {   0x0301,   0x1E09 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000ea[4] = {
    {   0x0300,   0x1EC1 },
    {   0x0301,   0x1EBF },
    {   0x0303,   0x1EC5 },
    {   0x0309,   0x1EC3 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000ef[1] = {
    {   0x0301,   0x1E2F }
};
static const tinyucd_combiner_entry s_combiner_entries_0000f4[4] = {
    {   0x0300,   0x1ED3 },
    {   0x0301,   0x1ED1 },
    {   0x0303,   0x1ED7 },
    {   0x0309,   0x1ED5 }
};
static const tinyucd_combiner_entry s_combiner_entries_0000f5[3] = {
    {   0x0301,   0x1E4D },
    {   0x0304,   0x022D },
    {   0x0308,   0x1E4F }
};
static const tinyucd_combiner_entry s_combiner_entries_0000f6[1] = {
    {   0x0304,   0x022B }
};
static const tinyucd_combiner_entry s_combiner_entries_0000f8[1] = {
    {   0x0301,   0x01FF }
};
static const tinyucd_combiner_entry s_combiner_entries_0000fc[4] = {
    {   0x0300,   0x01DC },
    {   0x0301,   0x01D8 },
    {   0x0304,   0x01D6 },
    {   0x030C,   0x01DA }
};
static const tinyucd_combiner_entry s_combiner_entries_000102[4] = {
    {   0x0300,   0x1EB0 },
    {   0x0301,   0x1EAE },
    {   0x0303,   0x1EB4 },
    {   0x0309,   0x1EB2 }
};
static const tinyucd_combiner_entry s_combiner_entries_000103[4] = {
    {   0x0300,   0x1EB1 },
    {   0x0301,   0x1EAF },
    {   0x0303,   0x1EB5 },
    {   0x0309,   0x1EB3 }
};
static const tinyucd_combiner_entry s_combiner_entries_000112[2] = {
    {   0x0300,   0x1E14 },
    {   0x0301,   0x1E16 }
};
static const tinyucd_combiner_entry s_combiner_entries_000113[2] = {
    {   0x0300,   0x1E15 },
    {   0x0301,   0x1E17 }
};
static const tinyucd_combiner_entry s_combiner_entries_00014c[2] = {
    {   0x0300,   0x1E50 },
    {   0x0301,   0x1E52 }
};
static const tinyucd_combiner_entry s_combiner_entries_00014d[2] = {
    {   0x0300,   0x1E51 },
    {   0x0301,   0x1E53 }
};
static const tinyucd_combiner_entry s_combiner_entries_00015a[1] = {
    {   0x0307,   0x1E64 }
};
static const tinyucd_combiner_entry s_combiner_entries_00015b[1] = {
    {   0x0307,   0x1E65 }
};
static const tinyucd_combiner_entry s_combiner_entries_000160[1] = {
    {   0x0307,   0x1E66 }
};
static const tinyucd_combiner_entry s_combiner_entries_000161[1] = {
    {   0x0307,   0x1E67 }
};
static const tinyucd_combiner_entry s_combiner_entries_000168[1] = {
    {   0x0301,   0x1E78 }
};
static const tinyucd_combiner_entry s_combiner_entries_000169[1] = {
    {   0x0301,   0x1E79 }
};
static const tinyucd_combiner_entry s_combiner_entries_00016a[1] = {
    {   0x0308,   0x1E7A }
};
static const tinyucd_combiner_entry s_combiner_entries_00016b[1] = {
    {   0x0308,   0x1E7B }
};
static const tinyucd_combiner_entry s_combiner_entries_00017f[1] = {
    {   0x0307,   0x1E9B }
};
static const tinyucd_combiner_entry s_combiner_entries_0001a0[5] = {
    {   0x0300,   0x1EDC },
    {   0x0301,   0x1EDA },
    {   0x0303,   0x1EE0 },
    {   0x0309,   0x1EDE },
    {   0x0323,   0x1EE2 }
};
static const tinyucd_combiner_entry s_combiner_entries_0001a1[5] = {
    {   0x0300,   0x1EDD },
    {   0x0301,   0x1EDB },
    {   0x0303,   0x1EE1 },
    {   0x0309,   0x1EDF },
    {   0x0323,   0x1EE3 }
};
static const tinyucd_combiner_entry s_combiner_entries_0001af[5] = {
    {   0x0300,   0x1EEA },
    {   0x0301,   0x1EE8 },
    {   0x0303,   0x1EEE },
    {   0x0309,   0x1EEC },
    {   0x0323,   0x1EF0 }
};
static const tinyucd_combiner_entry s_combiner_entries_0001b0[5] = {
    {   0x0300,   0x1EEB },
    {   0x0301,   0x1EE9 },
    {   0x0303,   0x1EEF },
    {   0x0309,   0x1EED },
    {   0x0323,   0x1EF1 }
};
static const tinyucd_combiner_entry s_combiner_entries_0001b7[1] = {
    {   0x030C,   0x01EE }
};
static const tinyucd_combiner_entry s_combiner_entries_0001ea[1] = {
    {   0x0304,   0x01EC }
};
static const tinyucd_combiner_entry s_combiner_entries_0001eb[1] = {
    {   0x0304,   0x01ED }
};
static const tinyucd_combiner_entry s_combiner_entries_000226[1] = {
    {   0x0304,   0x01E0 }
};
static const tinyucd_combiner_entry s_combiner_entries_000227[1] = {
    {   0x0304,   0x01E1 }
};
static const tinyucd_combiner_entry s_combiner_entries_000228[1] = {
    {   0x0306,   0x1E1C }
};
static const tinyucd_combiner_entry s_combiner_entries_000229[1] = {
    {   0x0306,   0x1E1D }
};
static const tinyucd_combiner_entry s_combiner_entries_00022e[1] = {
    {   0x0304,   0x0230 }
};
static const tinyucd_combiner_entry s_combiner_entries_00022f[1] = {
    {   0x0304,   0x0231 }
};
static const tinyucd_combiner_entry s_combiner_entries_000292[1] = {
    {   0x030C,   0x01EF }
};
static const tinyucd_combiner_entry s_combiner_entries_000391[7] = {
    {   0x0300,   0x1FBA },
    {   0x0301,   0x0386 },
    {   0x0304,   0x1FB9 },
    {   0x0306,   0x1FB8 },
    {   0x0313,   0x1F08 },
    {   0x0314,   0x1F09 },
    {   0x0345,   0x1FBC }
};
static const tinyucd_combiner_entry s_combiner_entries_000395[4] = {
    {   0x0300,   0x1FC8 },
    {   0x0301,   0x0388 },
    {   0x0313,   0x1F18 },
    {   0x0314,   0x1F19 }
};
static const tinyucd_combiner_entry s_combiner_entries_000397[5] = {
    {   0x0300,   0x1FCA },
    {   0x0301,   0x0389 },
    {   0x0313,   0x1F28 },
    {   0x0314,   0x1F29 },
    {   0x0345,   0x1FCC }
};
static const tinyucd_combiner_entry s_combiner_entries_000399[7] = {
    {   0x0300,   0x1FDA },
    {   0x0301,   0x038A },
    {   0x0304,   0x1FD9 },
    {   0x0306,   0x1FD8 },
    {   0x0308,   0x03AA },
    {   0x0313,   0x1F38 },
    {   0x0314,   0x1F39 }
};
static const tinyucd_combiner_entry s_combiner_entries_00039f[4] = {
    {   0x0300,   0x1FF8 },
    {   0x0301,   0x038C },
    {   0x0313,   0x1F48 },
    {   0x0314,   0x1F49 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003a1[1] = {
    {   0x0314,   0x1FEC }
};
static const tinyucd_combiner_entry s_combiner_entries_0003a5[6] = {
    {   0x0300,   0x1FEA },
    {   0x0301,   0x038E },
    {   0x0304,   0x1FE9 },
    {   0x0306,   0x1FE8 },
    {   0x0308,   0x03AB },
    {   0x0314,   0x1F59 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003a9[5] = {
    {   0x0300,   0x1FFA },
    {   0x0301,   0x038F },
    {   0x0313,   0x1F68 },
    {   0x0314,   0x1F69 },
    {   0x0345,   0x1FFC }
};
static const tinyucd_combiner_entry s_combiner_entries_0003ac[1] = {
    {   0x0345,   0x1FB4 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003ae[1] = {
    {   0x0345,   0x1FC4 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003b1[8] = {
    {   0x0300,   0x1F70 },
    {   0x0301,   0x03AC },
    {   0x0304,   0x1FB1 },
    {   0x0306,   0x1FB0 },
    {   0x0313,   0x1F00 },
    {   0x0314,   0x1F01 },
    {   0x0342,   0x1FB6 },
    {   0x0345,   0x1FB3 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003b5[4] = {
    {   0x0300,   0x1F72 },
    {   0x0301,   0x03AD },
    {   0x0313,   0x1F10 },
    {   0x0314,   0x1F11 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003b7[6] = {
    {   0x0300,   0x1F74 },
    {   0x0301,   0x03AE },
    {   0x0313,   0x1F20 },
    {   0x0314,   0x1F21 },
    {   0x0342,   0x1FC6 },
    {   0x0345,   0x1FC3 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003b9[8] = {
    {   0x0300,   0x1F76 },
    {   0x0301,   0x03AF },
    {   0x0304,   0x1FD1 },
    {   0x0306,   0x1FD0 },
    {   0x0308,   0x03CA },
    {   0x0313,   0x1F30 },
    {   0x0314,   0x1F31 },
    {   0x0342,   0x1FD6 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003bf[4] = {
    {   0x0300,   0x1F78 },
    {   0x0301,   0x03CC },
    {   0x0313,   0x1F40 },
    {   0x0314,   0x1F41 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003c1[2] = {
    {   0x0313,   0x1FE4 },
    {   0x0314,   0x1FE5 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003c5[8] = {
    {   0x0300,   0x1F7A },
    {   0x0301,   0x03CD },
    {   0x0304,   0x1FE1 },
    {   0x0306,   0x1FE0 },
    {   0x0308,   0x03CB },
    {   0x0313,   0x1F50 },
    {   0x0314,   0x1F51 },
    {   0x0342,   0x1FE6 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003c9[6] = {
    {   0x0300,   0x1F7C },
    {   0x0301,   0x03CE },
    {   0x0313,   0x1F60 },
    {   0x0314,   0x1F61 },
    {   0x0342,   0x1FF6 },
    {   0x0345,   0x1FF3 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003ca[3] = {
    {   0x0300,   0x1FD2 },
    {   0x0301,   0x0390 },
    {   0x0342,   0x1FD7 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003cb[3] = {
    {   0x0300,   0x1FE2 },
    {   0x0301,   0x03B0 },
    {   0x0342,   0x1FE7 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003ce[1] = {
    {   0x0345,   0x1FF4 }
};
static const tinyucd_combiner_entry s_combiner_entries_0003d2[2] = {
    {   0x0301,   0x03D3 },
    {   0x0308,   0x03D4 }
};
static const tinyucd_combiner_entry s_combiner_entries_000406[1] = {
    {   0x0308,   0x0407 }
};
static const tinyucd_combiner_entry s_combiner_entries_000410[2] = {
    {   0x0306,   0x04D0 },
    {   0x0308,   0x04D2 }
};
static const tinyucd_combiner_entry s_combiner_entries_000413[1] = {
    {   0x0301,   0x0403 }
};
static const tinyucd_combiner_entry s_combiner_entries_000415[3] = {
    {   0x0300,   0x0400 },
    {   0x0306,   0x04D6 },
    {   0x0308,   0x0401 }
};
static const tinyucd_combiner_entry s_combiner_entries_000416[2] = {
    {   0x0306,   0x04C1 },
    {   0x0308,   0x04DC }
};
static const tinyucd_combiner_entry s_combiner_entries_000417[1] = {
    {   0x0308,   0x04DE }
};
static const tinyucd_combiner_entry s_combiner_entries_000418[4] = {
    {   0x0300,   0x040D },
    {   0x0304,   0x04E2 },
    {   0x0306,   0x0419 },
    {   0x0308,   0x04E4 }
};
static const tinyucd_combiner_entry s_combiner_entries_00041a[1] = {
    {   0x0301,   0x040C }
};
static const tinyucd_combiner_entry s_combiner_entries_00041e[1] = {
    {   0x0308,   0x04E6 }
};
static const tinyucd_combiner_entry s_combiner_entries_000423[4] = {
    {   0x0304,   0x04EE },
    {   0x0306,   0x040E },
    {   0x0308,   0x04F0 },
    {   0x030B,   0x04F2 }
};
static const tinyucd_combiner_entry s_combiner_entries_000427[1] = {
    {   0x0308,   0x04F4 }
};
static const tinyucd_combiner_entry s_combiner_entries_00042b[1] = {
    {   0x0308,   0x04F8 }
};
static const tinyucd_combiner_entry s_combiner_entries_00042d[1] = {
    {   0x0308,   0x04EC }
};
static const tinyucd_combiner_entry s_combiner_entries_000430[2] = {
    {   0x0306,   0x04D1 },
    {   0x0308,   0x04D3 }
};
static const tinyucd_combiner_entry s_combiner_entries_000433[1] = {
    {   0x0301,   0x0453 }
};
static const tinyucd_combiner_entry s_combiner_entries_000435[3] = {
    {   0x0300,   0x0450 },
    {   0x0306,   0x04D7 },
    {   0x0308,   0x0451 }
};
static const tinyucd_combiner_entry s_combiner_entries_000436[2] = {
    {   0x0306,   0x04C2 },
    {   0x0308,   0x04DD }
};
static const tinyucd_combiner_entry s_combiner_entries_000437[1] = {
    {   0x0308,   0x04DF }
};
static const tinyucd_combiner_entry s_combiner_entries_000438[4] = {
    {   0x0300,   0x045D },
    {   0x0304,   0x04E3 },
    {   0x0306,   0x0439 },
    {   0x0308,   0x04E5 }
};
static const tinyucd_combiner_entry s_combiner_entries_00043a[1] = {
    {   0x0301,   0x045C }
};
static const tinyucd_combiner_entry s_combiner_entries_00043e[1] = {
    {   0x0308,   0x04E7 }
};
static const tinyucd_combiner_entry s_combiner_entries_000443[4] = {
    {   0x0304,   0x04EF },
    {   0x0306,   0x045E },
    {   0x0308,   0x04F1 },
    {   0x030B,   0x04F3 }
};
static const tinyucd_combiner_entry s_combiner_entries_000447[1] = {
    {   0x0308,   0x04F5 }
};
static const tinyucd_combiner_entry s_combiner_entries_00044b[1] = {
    {   0x0308,   0x04F9 }
};
static const tinyucd_combiner_entry s_combiner_entries_00044d[1] = {
    {   0x0308,   0x04ED }
};
static const tinyucd_combiner_entry s_combiner_entries_000456[1] = {
    {   0x0308,   0x0457 }
};
static const tinyucd_combiner_entry s_combiner_entries_000474[1] = {
    {   0x030F,   0x0476 }
};
static const tinyucd_combiner_entry s_combiner_entries_000475[1] = {
    {   0x030F,   0x0477 }
};
static const tinyucd_combiner_entry s_combiner_entries_0004d8[1] = {
    {   0x0308,   0x04DA }
};
static const tinyucd_combiner_entry s_combiner_entries_0004d9[1] = {
    {   0x0308,   0x04DB }
};
static const tinyucd_combiner_entry s_combiner_entries_0004e8[1] = {
    {   0x0308,   0x04EA }
};
static const tinyucd_combiner_entry s_combiner_entries_0004e9[1] = {
    {   0x0308,   0x04EB }
};
static const tinyucd_combiner_entry s_combiner_entries_000627[3] = {
    {   0x0653,   0x0622 },
    {   0x0654,   0x0623 },
    {   0x0655,   0x0625 }
};
static const tinyucd_combiner_entry s_combiner_entries_000648[1] = {
    {   0x0654,   0x0624 }
};
static const tinyucd_combiner_entry s_combiner_entries_00064a[1] = {
    {   0x0654,   0x0626 }
};
static const tinyucd_combiner_entry s_combiner_entries_0006c1[1] = {
    {   0x0654,   0x06C2 }
};
static const tinyucd_combiner_entry s_combiner_entries_0006d2[1] = {
    {   0x0654,   0x06D3 }
};
static const tinyucd_combiner_entry s_combiner_entries_0006d5[1] = {
    {   0x0654,   0x06C0 }
};
static const tinyucd_combiner_entry s_combiner_entries_000928[1] = {
    {   0x093C,   0x0929 }
};
static const tinyucd_combiner_entry s_combiner_entries_000930[1] = {
    {   0x093C,   0x0931 }
};
static const tinyucd_combiner_entry s_combiner_entries_000933[1] = {
    {   0x093C,   0x0934 }
};
static const tinyucd_combiner_entry s_combiner_entries_0009c7[2] = {
    {   0x09BE,   0x09CB },
    {   0x09D7,   0x09CC }
};
static const tinyucd_combiner_entry s_combiner_entries_000b47[3] = {
    {   0x0B3E,   0x0B4B },
    {   0x0B56,   0x0B48 },
    {   0x0B57,   0x0B4C }
};
static const tinyucd_combiner_entry s_combiner_entries_000b92[1] = {
    {   0x0BD7,   0x0B94 }
};
static const tinyucd_combiner_entry s_combiner_entries_000bc6[2] = {
    {   0x0BBE,   0x0BCA },
    {   0x0BD7,   0x0BCC }
};
static const tinyucd_combiner_entry s_combiner_entries_000bc7[1] = {
    {   0x0BBE,   0x0BCB }
};
static const tinyucd_combiner_entry s_combiner_entries_000c46[1] = {
    {   0x0C56,   0x0C48 }
};
static const tinyucd_combiner_entry s_combiner_entries_000cbf[1] = {
    {   0x0CD5,   0x0CC0 }
};
static const tinyucd_combiner_entry s_combiner_entries_000cc6[3] = {
    {   0x0CC2,   0x0CCA },
    {   0x0CD5,   0x0CC7 },
    {   0x0CD6,   0x0CC8 }
};
static const tinyucd_combiner_entry s_combiner_entries_000cca[1] = {
    {   0x0CD5,   0x0CCB }
};
static const tinyucd_combiner_entry s_combiner_entries_000d46[2] = {
    {   0x0D3E,   0x0D4A },
    {   0x0D57,   0x0D4C }
};
static const tinyucd_combiner_entry s_combiner_entries_000d47[1] = {
    {   0x0D3E,   0x0D4B }
};
static const tinyucd_combiner_entry s_combiner_entries_000dd9[3] = {
    {   0x0DCA,   0x0DDA },
    {   0x0DCF,   0x0DDC },
    {   0x0DDF,   0x0DDE }
};
static const tinyucd_combiner_entry s_combiner_entries_000ddc[1] = {
    {   0x0DCA,   0x0DDD }
};
static const tinyucd_combiner_entry s_combiner_entries_001025[1] = {
    {   0x102E,   0x1026 }
};
static const tinyucd_combiner_entry s_combiner_entries_001b05[1] = {
    {   0x1B35,   0x1B06 }
};
static const tinyucd_combiner_entry s_combiner_entries_001b07[1] = {
    {   0x1B35,   0x1B08 }
};
static const tinyucd_combiner_entry s_combiner_entries_001b09[1] = {
    {   0x1B35,   0x1B0A }
};
static const tinyucd_combiner_entry s_combiner_entries_001b0b[1] = {
    {   0x1B35,   0x1B0C }
};
static const tinyucd_combiner_entry s_combiner_entries_001b0d[1] = {
    {   0x1B35,   0x1B0E }
};
static const tinyucd_combiner_entry s_combiner_entries_001b11[1] = {
    {   0x1B35,   0x1B12 }
};
static const tinyucd_combiner_entry s_combiner_entries_001b3a[1] = {
    {   0x1B35,   0x1B3B }
};
static const tinyucd_combiner_entry s_combiner_entries_001b3c[1] = {
    {   0x1B35,   0x1B3D }
};
static const tinyucd_combiner_entry s_combiner_entries_001b3e[1] = {
    {   0x1B35,   0x1B40 }
};
static const tinyucd_combiner_entry s_combiner_entries_001b3f[1] = {
    {   0x1B35,   0x1B41 }
};
static const tinyucd_combiner_entry s_combiner_entries_001b42[1] = {
    {   0x1B35,   0x1B43 }
};
static const tinyucd_combiner_entry s_combiner_entries_001e36[1] = {
    {   0x0304,   0x1E38 }
};
static const tinyucd_combiner_entry s_combiner_entries_001e37[1] = {
    {   0x0304,   0x1E39 }
};
static const tinyucd_combiner_entry s_combiner_entries_001e5a[1] = {
    {   0x0304,   0x1E5C }
};
static const tinyucd_combiner_entry s_combiner_entries_001e5b[1] = {
    {   0x0304,   0x1E5D }
};
static const tinyucd_combiner_entry s_combiner_entries_001e62[1] = {
    {   0x0307,   0x1E68 }
};
static const tinyucd_combiner_entry s_combiner_entries_001e63[1] = {
    {   0x0307,   0x1E69 }
};
static const tinyucd_combiner_entry s_combiner_entries_001ea0[2] = {
    {   0x0302,   0x1EAC },
    {   0x0306,   0x1EB6 }
};
static const tinyucd_combiner_entry s_combiner_entries_001ea1[2] = {
    {   0x0302,   0x1EAD },
    {   0x0306,   0x1EB7 }
};
static const tinyucd_combiner_entry s_combiner_entries_001eb8[1] = {
    {   0x0302,   0x1EC6 }
};
static const tinyucd_combiner_entry s_combiner_entries_001eb9[1] = {
    {   0x0302,   0x1EC7 }
};
static const tinyucd_combiner_entry s_combiner_entries_001ecc[1] = {
    {   0x0302,   0x1ED8 }
};
static const tinyucd_combiner_entry s_combiner_entries_001ecd[1] = {
    {   0x0302,   0x1ED9 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f00[4] = {
    {   0x0300,   0x1F02 },
    {   0x0301,   0x1F04 },
    {   0x0342,   0x1F06 },
    {   0x0345,   0x1F80 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f01[4] = {
    {   0x0300,   0x1F03 },
    {   0x0301,   0x1F05 },
    {   0x0342,   0x1F07 },
    {   0x0345,   0x1F81 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f02[1] = {
    {   0x0345,   0x1F82 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f03[1] = {
    {   0x0345,   0x1F83 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f04[1] = {
    {   0x0345,   0x1F84 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f05[1] = {
    {   0x0345,   0x1F85 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f06[1] = {
    {   0x0345,   0x1F86 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f07[1] = {
    {   0x0345,   0x1F87 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f08[4] = {
    {   0x0300,   0x1F0A },
    {   0x0301,   0x1F0C },
    {   0x0342,   0x1F0E },
    {   0x0345,   0x1F88 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f09[4] = {
    {   0x0300,   0x1F0B },
    {   0x0301,   0x1F0D },
    {   0x0342,   0x1F0F },
    {   0x0345,   0x1F89 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f0a[1] = {
    {   0x0345,   0x1F8A }
};
static const tinyucd_combiner_entry s_combiner_entries_001f0b[1] = {
    {   0x0345,   0x1F8B }
};
static const tinyucd_combiner_entry s_combiner_entries_001f0c[1] = {
    {   0x0345,   0x1F8C }
};
static const tinyucd_combiner_entry s_combiner_entries_001f0d[1] = {
    {   0x0345,   0x1F8D }
};
static const tinyucd_combiner_entry s_combiner_entries_001f0e[1] = {
    {   0x0345,   0x1F8E }
};
static const tinyucd_combiner_entry s_combiner_entries_001f0f[1] = {
    {   0x0345,   0x1F8F }
};
static const tinyucd_combiner_entry s_combiner_entries_001f10[2] = {
    {   0x0300,   0x1F12 },
    {   0x0301,   0x1F14 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f11[2] = {
    {   0x0300,   0x1F13 },
    {   0x0301,   0x1F15 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f18[2] = {
    {   0x0300,   0x1F1A },
    {   0x0301,   0x1F1C }
};
static const tinyucd_combiner_entry s_combiner_entries_001f19[2] = {
    {   0x0300,   0x1F1B },
    {   0x0301,   0x1F1D }
};
static const tinyucd_combiner_entry s_combiner_entries_001f20[4] = {
    {   0x0300,   0x1F22 },
    {   0x0301,   0x1F24 },
    {   0x0342,   0x1F26 },
    {   0x0345,   0x1F90 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f21[4] = {
    {   0x0300,   0x1F23 },
    {   0x0301,   0x1F25 },
    {   0x0342,   0x1F27 },
    {   0x0345,   0x1F91 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f22[1] = {
    {   0x0345,   0x1F92 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f23[1] = {
    {   0x0345,   0x1F93 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f24[1] = {
    {   0x0345,   0x1F94 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f25[1] = {
    {   0x0345,   0x1F95 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f26[1] = {
    {   0x0345,   0x1F96 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f27[1] = {
    {   0x0345,   0x1F97 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f28[4] = {
    {   0x0300,   0x1F2A },
    {   0x0301,   0x1F2C },
    {   0x0342,   0x1F2E },
    {   0x0345,   0x1F98 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f29[4] = {
    {   0x0300,   0x1F2B },
    {   0x0301,   0x1F2D },
    {   0x0342,   0x1F2F },
    {   0x0345,   0x1F99 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f2a[1] = {
    {   0x0345,   0x1F9A }
};
static const tinyucd_combiner_entry s_combiner_entries_001f2b[1] = {
    {   0x0345,   0x1F9B }
};
static const tinyucd_combiner_entry s_combiner_entries_001f2c[1] = {
    {   0x0345,   0x1F9C }
};
static const tinyucd_combiner_entry s_combiner_entries_001f2d[1] = {
    {   0x0345,   0x1F9D }
};
static const tinyucd_combiner_entry s_combiner_entries_001f2e[1] = {
    {   0x0345,   0x1F9E }
};
static const tinyucd_combiner_entry s_combiner_entries_001f2f[1] = {
    {   0x0345,   0x1F9F }
};
static const tinyucd_combiner_entry s_combiner_entries_001f30[3] = {
    {   0x0300,   0x1F32 },
    {   0x0301,   0x1F34 },
    {   0x0342,   0x1F36 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f31[3] = {
    {   0x0300,   0x1F33 },
    {   0x0301,   0x1F35 },
    {   0x0342,   0x1F37 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f38[3] = {
    {   0x0300,   0x1F3A },
    {   0x0301,   0x1F3C },
    {   0x0342,   0x1F3E }
};
static const tinyucd_combiner_entry s_combiner_entries_001f39[3] = {
    {   0x0300,   0x1F3B },
    {   0x0301,   0x1F3D },
    {   0x0342,   0x1F3F }
};
static const tinyucd_combiner_entry s_combiner_entries_001f40[2] = {
    {   0x0300,   0x1F42 },
    {   0x0301,   0x1F44 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f41[2] = {
    {   0x0300,   0x1F43 },
    {   0x0301,   0x1F45 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f48[2] = {
    {   0x0300,   0x1F4A },
    {   0x0301,   0x1F4C }
};
static const tinyucd_combiner_entry s_combiner_entries_001f49[2] = {
    {   0x0300,   0x1F4B },
    {   0x0301,   0x1F4D }
};
static const tinyucd_combiner_entry s_combiner_entries_001f50[3] = {
    {   0x0300,   0x1F52 },
    {   0x0301,   0x1F54 },
    {   0x0342,   0x1F56 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f51[3] = {
    {   0x0300,   0x1F53 },
    {   0x0301,   0x1F55 },
    {   0x0342,   0x1F57 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f59[3] = {
    {   0x0300,   0x1F5B },
    {   0x0301,   0x1F5D },
    {   0x0342,   0x1F5F }
};
static const tinyucd_combiner_entry s_combiner_entries_001f60[4] = {
    {   0x0300,   0x1F62 },
    {   0x0301,   0x1F64 },
    {   0x0342,   0x1F66 },
    {   0x0345,   0x1FA0 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f61[4] = {
    {   0x0300,   0x1F63 },
    {   0x0301,   0x1F65 },
    {   0x0342,   0x1F67 },
    {   0x0345,   0x1FA1 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f62[1] = {
    {   0x0345,   0x1FA2 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f63[1] = {
    {   0x0345,   0x1FA3 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f64[1] = {
    {   0x0345,   0x1FA4 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f65[1] = {
    {   0x0345,   0x1FA5 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f66[1] = {
    {   0x0345,   0x1FA6 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f67[1] = {
    {   0x0345,   0x1FA7 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f68[4] = {
    {   0x0300,   0x1F6A },
    {   0x0301,   0x1F6C },
    {   0x0342,   0x1F6E },
    {   0x0345,   0x1FA8 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f69[4] = {
    {   0x0300,   0x1F6B },
    {   0x0301,   0x1F6D },
    {   0x0342,   0x1F6F },
    {   0x0345,   0x1FA9 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f6a[1] = {
    {   0x0345,   0x1FAA }
};
static const tinyucd_combiner_entry s_combiner_entries_001f6b[1] = {
    {   0x0345,   0x1FAB }
};
static const tinyucd_combiner_entry s_combiner_entries_001f6c[1] = {
    {   0x0345,   0x1FAC }
};
static const tinyucd_combiner_entry s_combiner_entries_001f6d[1] = {
    {   0x0345,   0x1FAD }
};
static const tinyucd_combiner_entry s_combiner_entries_001f6e[1] = {
    {   0x0345,   0x1FAE }
};
static const tinyucd_combiner_entry s_combiner_entries_001f6f[1] = {
    {   0x0345,   0x1FAF }
};
static const tinyucd_combiner_entry s_combiner_entries_001f70[1] = {
    {   0x0345,   0x1FB2 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f74[1] = {
    {   0x0345,   0x1FC2 }
};
static const tinyucd_combiner_entry s_combiner_entries_001f7c[1] = {
    {   0x0345,   0x1FF2 }
};
static const tinyucd_combiner_entry s_combiner_entries_001fb6[1] = {
    {   0x0345,   0x1FB7 }
};
static const tinyucd_combiner_entry s_combiner_entries_001fbf[3] = {
    {   0x0300,   0x1FCD },
    {   0x0301,   0x1FCE },
    {   0x0342,   0x1FCF }
};
static const tinyucd_combiner_entry s_combiner_entries_001fc6[1] = {
    {   0x0345,   0x1FC7 }
};
static const tinyucd_combiner_entry s_combiner_entries_001ff6[1] = {
    {   0x0345,   0x1FF7 }
};
static const tinyucd_combiner_entry s_combiner_entries_001ffe[3] = {
    {   0x0300,   0x1FDD },
    {   0x0301,   0x1FDE },
    {   0x0342,   0x1FDF }
};
static const tinyucd_combiner_entry s_combiner_entries_002190[1] = {
    {   0x0338,   0x219A }
};
static const tinyucd_combiner_entry s_combiner_entries_002192[1] = {
    {   0x0338,   0x219B }
};
static const tinyucd_combiner_entry s_combiner_entries_002194[1] = {
    {   0x0338,   0x21AE }
};
static const tinyucd_combiner_entry s_combiner_entries_0021d0[1] = {
    {   0x0338,   0x21CD }
};
static const tinyucd_combiner_entry s_combiner_entries_0021d2[1] = {
    {   0x0338,   0x21CF }
};
static const tinyucd_combiner_entry s_combiner_entries_0021d4[1] = {
    {   0x0338,   0x21CE }
};
static const tinyucd_combiner_entry s_combiner_entries_002203[1] = {
    {   0x0338,   0x2204 }
};
static const tinyucd_combiner_entry s_combiner_entries_002208[1] = {
    {   0x0338,   0x2209 }
};
static const tinyucd_combiner_entry s_combiner_entries_00220b[1] = {
    {   0x0338,   0x220C }
};
static const tinyucd_combiner_entry s_combiner_entries_002223[1] = {
    {   0x0338,   0x2224 }
};
static const tinyucd_combiner_entry s_combiner_entries_002225[1] = {
    {   0x0338,   0x2226 }
};
static const tinyucd_combiner_entry s_combiner_entries_00223c[1] = {
    {   0x0338,   0x2241 }
};
static const tinyucd_combiner_entry s_combiner_entries_002243[1] = {
    {   0x0338,   0x2244 }
};
static const tinyucd_combiner_entry s_combiner_entries_002245[1] = {
    {   0x0338,   0x2247 }
};
static const tinyucd_combiner_entry s_combiner_entries_002248[1] = {
    {   0x0338,   0x2249 }
};
static const tinyucd_combiner_entry s_combiner_entries_00224d[1] = {
    {   0x0338,   0x226D }
};
static const tinyucd_combiner_entry s_combiner_entries_002261[1] = {
    {   0x0338,   0x2262 }
};
static const tinyucd_combiner_entry s_combiner_entries_002264[1] = {
    {   0x0338,   0x2270 }
};
static const tinyucd_combiner_entry s_combiner_entries_002265[1] = {
    {   0x0338,   0x2271 }
};
static const tinyucd_combiner_entry s_combiner_entries_002272[1] = {
    {   0x0338,   0x2274 }
};
static const tinyucd_combiner_entry s_combiner_entries_002273[1] = {
    {   0x0338,   0x2275 }
};
static const tinyucd_combiner_entry s_combiner_entries_002276[1] = {
    {   0x0338,   0x2278 }
};
static const tinyucd_combiner_entry s_combiner_entries_002277[1] = {
    {   0x0338,   0x2279 }
};
static const tinyucd_combiner_entry s_combiner_entries_00227a[1] = {
    {   0x0338,   0x2280 }
};
static const tinyucd_combiner_entry s_combiner_entries_00227b[1] = {
    {   0x0338,   0x2281 }
};
static const tinyucd_combiner_entry s_combiner_entries_00227c[1] = {
    {   0x0338,   0x22E0 }
};
static const tinyucd_combiner_entry s_combiner_entries_00227d[1] = {
    {   0x0338,   0x22E1 }
};
static const tinyucd_combiner_entry s_combiner_entries_002282[1] = {
    {   0x0338,   0x2284 }
};
static const tinyucd_combiner_entry s_combiner_entries_002283[1] = {
    {   0x0338,   0x2285 }
};
static const tinyucd_combiner_entry s_combiner_entries_002286[1] = {
    {   0x0338,   0x2288 }
};
static const tinyucd_combiner_entry s_combiner_entries_002287[1] = {
    {   0x0338,   0x2289 }
};
static const tinyucd_combiner_entry s_combiner_entries_002291[1] = {
    {   0x0338,   0x22E2 }
};
static const tinyucd_combiner_entry s_combiner_entries_002292[1] = {
    {   0x0338,   0x22E3 }
};
static const tinyucd_combiner_entry s_combiner_entries_0022a2[1] = {
    {   0x0338,   0x22AC }
};
static const tinyucd_combiner_entry s_combiner_entries_0022a8[1] = {
    {   0x0338,   0x22AD }
};
static const tinyucd_combiner_entry s_combiner_entries_0022a9[1] = {
    {   0x0338,   0x22AE }
};
static const tinyucd_combiner_entry s_combiner_entries_0022ab[1] = {
    {   0x0338,   0x22AF }
};
static const tinyucd_combiner_entry s_combiner_entries_0022b2[1] = {
    {   0x0338,   0x22EA }
};
static const tinyucd_combiner_entry s_combiner_entries_0022b3[1] = {
    {   0x0338,   0x22EB }
};
static const tinyucd_combiner_entry s_combiner_entries_0022b4[1] = {
    {   0x0338,   0x22EC }
};
static const tinyucd_combiner_entry s_combiner_entries_0022b5[1] = {
    {   0x0338,   0x22ED }
};
static const tinyucd_combiner_entry s_combiner_entries_003046[1] = {
    {   0x3099,   0x3094 }
};
static const tinyucd_combiner_entry s_combiner_entries_00304b[1] = {
    {   0x3099,   0x304C }
};
static const tinyucd_combiner_entry s_combiner_entries_00304d[1] = {
    {   0x3099,   0x304E }
};
static const tinyucd_combiner_entry s_combiner_entries_00304f[1] = {
    {   0x3099,   0x3050 }
};
static const tinyucd_combiner_entry s_combiner_entries_003051[1] = {
    {   0x3099,   0x3052 }
};
static const tinyucd_combiner_entry s_combiner_entries_003053[1] = {
    {   0x3099,   0x3054 }
};
static const tinyucd_combiner_entry s_combiner_entries_003055[1] = {
    {   0x3099,   0x3056 }
};
static const tinyucd_combiner_entry s_combiner_entries_003057[1] = {
    {   0x3099,   0x3058 }
};
static const tinyucd_combiner_entry s_combiner_entries_003059[1] = {
    {   0x3099,   0x305A }
};
static const tinyucd_combiner_entry s_combiner_entries_00305b[1] = {
    {   0x3099,   0x305C }
};
static const tinyucd_combiner_entry s_combiner_entries_00305d[1] = {
    {   0x3099,   0x305E }
};
static const tinyucd_combiner_entry s_combiner_entries_00305f[1] = {
    {   0x3099,   0x3060 }
};
static const tinyucd_combiner_entry s_combiner_entries_003061[1] = {
    {   0x3099,   0x3062 }
};
static const tinyucd_combiner_entry s_combiner_entries_003064[1] = {
    {   0x3099,   0x3065 }
};
static const tinyucd_combiner_entry s_combiner_entries_003066[1] = {
    {   0x3099,   0x3067 }
};
static const tinyucd_combiner_entry s_combiner_entries_003068[1] = {
    {   0x3099,   0x3069 }
};
static const tinyucd_combiner_entry s_combiner_entries_00306f[2] = {
    {   0x3099,   0x3070 },
    {   0x309A,   0x3071 }
};
static const tinyucd_combiner_entry s_combiner_entries_003072[2] = {
    {   0x3099,   0x3073 },
    {   0x309A,   0x3074 }
};
static const tinyucd_combiner_entry s_combiner_entries_003075[2] = {
    {   0x3099,   0x3076 },
    {   0x309A,   0x3077 }
};
static const tinyucd_combiner_entry s_combiner_entries_003078[2] = {
    {   0x3099,   0x3079 },
    {   0x309A,   0x307A }
};
static const tinyucd_combiner_entry s_combiner_entries_00307b[2] = {
    {   0x3099,   0x307C },
    {   0x309A,   0x307D }
};
static const tinyucd_combiner_entry s_combiner_entries_00309d[1] = {
    {   0x3099,   0x309E }
};
static const tinyucd_combiner_entry s_combiner_entries_0030a6[1] = {
    {   0x3099,   0x30F4 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030ab[1] = {
    {   0x3099,   0x30AC }
};
static const tinyucd_combiner_entry s_combiner_entries_0030ad[1] = {
    {   0x3099,   0x30AE }
};
static const tinyucd_combiner_entry s_combiner_entries_0030af[1] = {
    {   0x3099,   0x30B0 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030b1[1] = {
    {   0x3099,   0x30B2 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030b3[1] = {
    {   0x3099,   0x30B4 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030b5[1] = {
    {   0x3099,   0x30B6 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030b7[1] = {
    {   0x3099,   0x30B8 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030b9[1] = {
    {   0x3099,   0x30BA }
};
static const tinyucd_combiner_entry s_combiner_entries_0030bb[1] = {
    {   0x3099,   0x30BC }
};
static const tinyucd_combiner_entry s_combiner_entries_0030bd[1] = {
    {   0x3099,   0x30BE }
};
static const tinyucd_combiner_entry s_combiner_entries_0030bf[1] = {
    {   0x3099,   0x30C0 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030c1[1] = {
    {   0x3099,   0x30C2 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030c4[1] = {
    {   0x3099,   0x30C5 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030c6[1] = {
    {   0x3099,   0x30C7 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030c8[1] = {
    {   0x3099,   0x30C9 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030cf[2] = {
    {   0x3099,   0x30D0 },
    {   0x309A,   0x30D1 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030d2[2] = {
    {   0x3099,   0x30D3 },
    {   0x309A,   0x30D4 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030d5[2] = {
    {   0x3099,   0x30D6 },
    {   0x309A,   0x30D7 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030d8[2] = {
    {   0x3099,   0x30D9 },
    {   0x309A,   0x30DA }
};
static const tinyucd_combiner_entry s_combiner_entries_0030db[2] = {
    {   0x3099,   0x30DC },
    {   0x309A,   0x30DD }
};
static const tinyucd_combiner_entry s_combiner_entries_0030ef[1] = {
    {   0x3099,   0x30F7 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030f0[1] = {
    {   0x3099,   0x30F8 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030f1[1] = {
    {   0x3099,   0x30F9 }
};
static const tinyucd_combiner_entry s_combiner_entries_0030f2[1] = {
    {   0x3099,   0x30FA }
};
static const tinyucd_combiner_entry s_combiner_entries_0030fd[1] = {
    {   0x3099,   0x30FE }
};
static const tinyucd_combiner_entry s_combiner_entries_0105d2[1] = {
    {   0x0307, 0x0105C9 }
};
static const tinyucd_combiner_entry s_combiner_entries_0105da[1] = {
    {   0x0307, 0x0105E4 }
};
static const tinyucd_combiner_entry s_combiner_entries_011099[1] = {
    { 0x0110BA, 0x01109A }
};
static const tinyucd_combiner_entry s_combiner_entries_01109b[1] = {
    { 0x0110BA, 0x01109C }
};
static const tinyucd_combiner_entry s_combiner_entries_0110a5[1] = {
    { 0x0110BA, 0x0110AB }
};
static const tinyucd_combiner_entry s_combiner_entries_011131[1] = {
    { 0x011127, 0x01112E }
};
static const tinyucd_combiner_entry s_combiner_entries_011132[1] = {
    { 0x011127, 0x01112F }
};
static const tinyucd_combiner_entry s_combiner_entries_011347[2] = {
    { 0x01133E, 0x01134B },
    { 0x011357, 0x01134C }
};
static const tinyucd_combiner_entry s_combiner_entries_011382[1] = {
    { 0x0113C9, 0x011383 }
};
static const tinyucd_combiner_entry s_combiner_entries_011384[1] = {
    { 0x0113BB, 0x011385 }
};
static const tinyucd_combiner_entry s_combiner_entries_01138b[1] = {
    { 0x0113C2, 0x01138E }
};
static const tinyucd_combiner_entry s_combiner_entries_011390[1] = {
    { 0x0113C9, 0x011391 }
};
static const tinyucd_combiner_entry s_combiner_entries_0113c2[3] = {
    { 0x0113B8, 0x0113C7 },
    { 0x0113C2, 0x0113C5 },
    { 0x0113C9, 0x0113C8 }
};
static const tinyucd_combiner_entry s_combiner_entries_0114b9[3] = {
    { 0x0114B0, 0x0114BC },
    { 0x0114BA, 0x0114BB },
    { 0x0114BD, 0x0114BE }
};
static const tinyucd_combiner_entry s_combiner_entries_0115b8[1] = {
    { 0x0115AF, 0x0115BA }
};
static const tinyucd_combiner_entry s_combiner_entries_0115b9[1] = {
    { 0x0115AF, 0x0115BB }
};
static const tinyucd_combiner_entry s_combiner_entries_011935[1] = {
    { 0x011930, 0x011938 }
};
static const tinyucd_combiner_entry s_combiner_entries_01611e[4] = {
    { 0x01611E, 0x016121 },
    { 0x01611F, 0x016123 },
    { 0x016120, 0x016125 },
    { 0x016129, 0x016122 }
};
static const tinyucd_combiner_entry s_combiner_entries_016121[2] = {
    { 0x01611F, 0x016126 },
    { 0x016120, 0x016128 }
};
static const tinyucd_combiner_entry s_combiner_entries_016122[1] = {
    { 0x01611F, 0x016127 }
};
static const tinyucd_combiner_entry s_combiner_entries_016129[1] = {
    { 0x01611F, 0x016124 }
};
static const tinyucd_combiner_entry s_combiner_entries_016d63[1] = {
    { 0x016D67, 0x016D69 }
};
static const tinyucd_combiner_entry s_combiner_entries_016d67[1] = {
    { 0x016D67, 0x016D68 }
};
static const tinyucd_combiner_entry s_combiner_entries_016d69[1] = {
    { 0x016D67, 0x016D6A }
};

// Main combiner table
static const tinyucd_combiners s_tinyucd_combiner_table[TINYUCD_NUM_COMBINER] = {
    {   0x003C,  1, s_combiner_entries_00003c },
    {   0x003D,  1, s_combiner_entries_00003d },
    {   0x003E,  1, s_combiner_entries_00003e },
    {   0x0041, 16, s_combiner_entries_000041 },
    {   0x0042,  3, s_combiner_entries_000042 },
    {   0x0043,  5, s_combiner_entries_000043 },
    {   0x0044,  6, s_combiner_entries_000044 },
    {   0x0045, 17, s_combiner_entries_000045 },
    {   0x0046,  1, s_combiner_entries_000046 },
    {   0x0047,  7, s_combiner_entries_000047 },
    {   0x0048,  7, s_combiner_entries_000048 },
    {   0x0049, 15, s_combiner_entries_000049 },
    {   0x004A,  1, s_combiner_entries_00004a },
    {   0x004B,  5, s_combiner_entries_00004b },
    {   0x004C,  6, s_combiner_entries_00004c },
    {   0x004D,  3, s_combiner_entries_00004d },
    {   0x004E,  9, s_combiner_entries_00004e },
    {   0x004F, 16, s_combiner_entries_00004f },
    {   0x0050,  2, s_combiner_entries_000050 },
    {   0x0052,  8, s_combiner_entries_000052 },
    {   0x0053,  7, s_combiner_entries_000053 },
    {   0x0054,  7, s_combiner_entries_000054 },
    {   0x0055, 19, s_combiner_entries_000055 },
    {   0x0056,  2, s_combiner_entries_000056 },
    {   0x0057,  6, s_combiner_entries_000057 },
    {   0x0058,  2, s_combiner_entries_000058 },
    {   0x0059,  9, s_combiner_entries_000059 },
    {   0x005A,  6, s_combiner_entries_00005a },
    {   0x0061, 16, s_combiner_entries_000061 },
    {   0x0062,  3, s_combiner_entries_000062 },
    {   0x0063,  5, s_combiner_entries_000063 },
    {   0x0064,  6, s_combiner_entries_000064 },
    {   0x0065, 17, s_combiner_entries_000065 },
    {   0x0066,  1, s_combiner_entries_000066 },
    {   0x0067,  7, s_combiner_entries_000067 },
    {   0x0068,  8, s_combiner_entries_000068 },
    {   0x0069, 14, s_combiner_entries_000069 },
    {   0x006A,  2, s_combiner_entries_00006a },
    {   0x006B,  5, s_combiner_entries_00006b },
    {   0x006C,  6, s_combiner_entries_00006c },
    {   0x006D,  3, s_combiner_entries_00006d },
    {   0x006E,  9, s_combiner_entries_00006e },
    {   0x006F, 16, s_combiner_entries_00006f },
    {   0x0070,  2, s_combiner_entries_000070 },
    {   0x0072,  8, s_combiner_entries_000072 },
    {   0x0073,  7, s_combiner_entries_000073 },
    {   0x0074,  8, s_combiner_entries_000074 },
    {   0x0075, 19, s_combiner_entries_000075 },
    {   0x0076,  2, s_combiner_entries_000076 },
    {   0x0077,  7, s_combiner_entries_000077 },
    {   0x0078,  2, s_combiner_entries_000078 },
    {   0x0079, 10, s_combiner_entries_000079 },
    {   0x007A,  6, s_combiner_entries_00007a },
    {   0x00A8,  3, s_combiner_entries_0000a8 },
    {   0x00C2,  4, s_combiner_entries_0000c2 },
    {   0x00C4,  1, s_combiner_entries_0000c4 },
    {   0x00C5,  1, s_combiner_entries_0000c5 },
    {   0x00C6,  2, s_combiner_entries_0000c6 },
    {   0x00C7,  1, s_combiner_entries_0000c7 },
    {   0x00CA,  4, s_combiner_entries_0000ca },
    {   0x00CF,  1, s_combiner_entries_0000cf },
    {   0x00D4,  4, s_combiner_entries_0000d4 },
    {   0x00D5,  3, s_combiner_entries_0000d5 },
    {   0x00D6,  1, s_combiner_entries_0000d6 },
    {   0x00D8,  1, s_combiner_entries_0000d8 },
    {   0x00DC,  4, s_combiner_entries_0000dc },
    {   0x00E2,  4, s_combiner_entries_0000e2 },
    {   0x00E4,  1, s_combiner_entries_0000e4 },
    {   0x00E5,  1, s_combiner_entries_0000e5 },
    {   0x00E6,  2, s_combiner_entries_0000e6 },
    {   0x00E7,  1, s_combiner_entries_0000e7 },
    {   0x00EA,  4, s_combiner_entries_0000ea },
    {   0x00EF,  1, s_combiner_entries_0000ef },
    {   0x00F4,  4, s_combiner_entries_0000f4 },
    {   0x00F5,  3, s_combiner_entries_0000f5 },
    {   0x00F6,  1, s_combiner_entries_0000f6 },
    {   0x00F8,  1, s_combiner_entries_0000f8 },
    {   0x00FC,  4, s_combiner_entries_0000fc },
    {   0x0102,  4, s_combiner_entries_000102 },
    {   0x0103,  4, s_combiner_entries_000103 },
    {   0x0112,  2, s_combiner_entries_000112 },
    {   0x0113,  2, s_combiner_entries_000113 },
    {   0x014C,  2, s_combiner_entries_00014c },
    {   0x014D,  2, s_combiner_entries_00014d },
    {   0x015A,  1, s_combiner_entries_00015a },
    {   0x015B,  1, s_combiner_entries_00015b },
    {   0x0160,  1, s_combiner_entries_000160 },
    {   0x0161,  1, s_combiner_entries_000161 },
    {   0x0168,  1, s_combiner_entries_000168 },
    {   0x0169,  1, s_combiner_entries_000169 },
    {   0x016A,  1, s_combiner_entries_00016a },
    {   0x016B,  1, s_combiner_entries_00016b },
    {   0x017F,  1, s_combiner_entries_00017f },
    {   0x01A0,  5, s_combiner_entries_0001a0 },
    {   0x01A1,  5, s_combiner_entries_0001a1 },
    {   0x01AF,  5, s_combiner_entries_0001af },
    {   0x01B0,  5, s_combiner_entries_0001b0 },
    {   0x01B7,  1, s_combiner_entries_0001b7 },
    {   0x01EA,  1, s_combiner_entries_0001ea },
    {   0x01EB,  1, s_combiner_entries_0001eb },
    {   0x0226,  1, s_combiner_entries_000226 },
    {   0x0227,  1, s_combiner_entries_000227 },
    {   0x0228,  1, s_combiner_entries_000228 },
    {   0x0229,  1, s_combiner_entries_000229 },
    {   0x022E,  1, s_combiner_entries_00022e },
    {   0x022F,  1, s_combiner_entries_00022f },
    {   0x0292,  1, s_combiner_entries_000292 },
    {   0x0391,  7, s_combiner_entries_000391 },
    {   0x0395,  4, s_combiner_entries_000395 },
    {   0x0397,  5, s_combiner_entries_000397 },
    {   0x0399,  7, s_combiner_entries_000399 },
    {   0x039F,  4, s_combiner_entries_00039f },
    {   0x03A1,  1, s_combiner_entries_0003a1 },
    {   0x03A5,  6, s_combiner_entries_0003a5 },
    {   0x03A9,  5, s_combiner_entries_0003a9 },
    {   0x03AC,  1, s_combiner_entries_0003ac },
    {   0x03AE,  1, s_combiner_entries_0003ae },
    {   0x03B1,  8, s_combiner_entries_0003b1 },
    {   0x03B5,  4, s_combiner_entries_0003b5 },
    {   0x03B7,  6, s_combiner_entries_0003b7 },
    {   0x03B9,  8, s_combiner_entries_0003b9 },
    {   0x03BF,  4, s_combiner_entries_0003bf },
    {   0x03C1,  2, s_combiner_entries_0003c1 },
    {   0x03C5,  8, s_combiner_entries_0003c5 },
    {   0x03C9,  6, s_combiner_entries_0003c9 },
    {   0x03CA,  3, s_combiner_entries_0003ca },
    {   0x03CB,  3, s_combiner_entries_0003cb },
    {   0x03CE,  1, s_combiner_entries_0003ce },
    {   0x03D2,  2, s_combiner_entries_0003d2 },
    {   0x0406,  1, s_combiner_entries_000406 },
    {   0x0410,  2, s_combiner_entries_000410 },
    {   0x0413,  1, s_combiner_entries_000413 },
    {   0x0415,  3, s_combiner_entries_000415 },
    {   0x0416,  2, s_combiner_entries_000416 },
    {   0x0417,  1, s_combiner_entries_000417 },
    {   0x0418,  4, s_combiner_entries_000418 },
    {   0x041A,  1, s_combiner_entries_00041a },
    {   0x041E,  1, s_combiner_entries_00041e },
    {   0x0423,  4, s_combiner_entries_000423 },
    {   0x0427,  1, s_combiner_entries_000427 },
    {   0x042B,  1, s_combiner_entries_00042b },
    {   0x042D,  1, s_combiner_entries_00042d },
    {   0x0430,  2, s_combiner_entries_000430 },
    {   0x0433,  1, s_combiner_entries_000433 },
    {   0x0435,  3, s_combiner_entries_000435 },
    {   0x0436,  2, s_combiner_entries_000436 },
    {   0x0437,  1, s_combiner_entries_000437 },
    {   0x0438,  4, s_combiner_entries_000438 },
    {   0x043A,  1, s_combiner_entries_00043a },
    {   0x043E,  1, s_combiner_entries_00043e },
    {   0x0443,  4, s_combiner_entries_000443 },
    {   0x0447,  1, s_combiner_entries_000447 },
    {   0x044B,  1, s_combiner_entries_00044b },
    {   0x044D,  1, s_combiner_entries_00044d },
    {   0x0456,  1, s_combiner_entries_000456 },
    {   0x0474,  1, s_combiner_entries_000474 },
    {   0x0475,  1, s_combiner_entries_000475 },
    {   0x04D8,  1, s_combiner_entries_0004d8 },
    {   0x04D9,  1, s_combiner_entries_0004d9 },
    {   0x04E8,  1, s_combiner_entries_0004e8 },
    {   0x04E9,  1, s_combiner_entries_0004e9 },
    {   0x0627,  3, s_combiner_entries_000627 },
    {   0x0648,  1, s_combiner_entries_000648 },
    {   0x064A,  1, s_combiner_entries_00064a },
    {   0x06C1,  1, s_combiner_entries_0006c1 },
    {   0x06D2,  1, s_combiner_entries_0006d2 },
    {   0x06D5,  1, s_combiner_entries_0006d5 },
    {   0x0928,  1, s_combiner_entries_000928 },
    {   0x0930,  1, s_combiner_entries_000930 },
    {   0x0933,  1, s_combiner_entries_000933 },
    {   0x09C7,  2, s_combiner_entries_0009c7 },
    {   0x0B47,  3, s_combiner_entries_000b47 },
    {   0x0B92,  1, s_combiner_entries_000b92 },
    {   0x0BC6,  2, s_combiner_entries_000bc6 },
    {   0x0BC7,  1, s_combiner_entries_000bc7 },
    {   0x0C46,  1, s_combiner_entries_000c46 },
    {   0x0CBF,  1, s_combiner_entries_000cbf },
    {   0x0CC6,  3, s_combiner_entries_000cc6 },
    {   0x0CCA,  1, s_combiner_entries_000cca },
    {   0x0D46,  2, s_combiner_entries_000d46 },
    {   0x0D47,  1, s_combiner_entries_000d47 },
    {   0x0DD9,  3, s_combiner_entries_000dd9 },
    {   0x0DDC,  1, s_combiner_entries_000ddc },
    {   0x1025,  1, s_combiner_entries_001025 },
    {   0x1B05,  1, s_combiner_entries_001b05 },
    {   0x1B07,  1, s_combiner_entries_001b07 },
    {   0x1B09,  1, s_combiner_entries_001b09 },
    {   0x1B0B,  1, s_combiner_entries_001b0b },
    {   0x1B0D,  1, s_combiner_entries_001b0d },
    {   0x1B11,  1, s_combiner_entries_001b11 },
    {   0x1B3A,  1, s_combiner_entries_001b3a },
    {   0x1B3C,  1, s_combiner_entries_001b3c },
    {   0x1B3E,  1, s_combiner_entries_001b3e },
    {   0x1B3F,  1, s_combiner_entries_001b3f },
    {   0x1B42,  1, s_combiner_entries_001b42 },
    {   0x1E36,  1, s_combiner_entries_001e36 },
    {   0x1E37,  1, s_combiner_entries_001e37 },
    {   0x1E5A,  1, s_combiner_entries_001e5a },
    {   0x1E5B,  1, s_combiner_entries_001e5b },
    {   0x1E62,  1, s_combiner_entries_001e62 },
    {   0x1E63,  1, s_combiner_entries_001e63 },
    {   0x1EA0,  2, s_combiner_entries_001ea0 },
    {   0x1EA1,  2, s_combiner_entries_001ea1 },
    {   0x1EB8,  1, s_combiner_entries_001eb8 },
    {   0x1EB9,  1, s_combiner_entries_001eb9 },
    {   0x1ECC,  1, s_combiner_entries_001ecc },
    {   0x1ECD,  1, s_combiner_entries_001ecd },
    {   0x1F00,  4, s_combiner_entries_001f00 },
    {   0x1F01,  4, s_combiner_entries_001f01 },
    {   0x1F02,  1, s_combiner_entries_001f02 },
    {   0x1F03,  1, s_combiner_entries_001f03 },
    {   0x1F04,  1, s_combiner_entries_001f04 },
    {   0x1F05,  1, s_combiner_entries_001f05 },
    {   0x1F06,  1, s_combiner_entries_001f06 },
    {   0x1F07,  1, s_combiner_entries_001f07 },
    {   0x1F08,  4, s_combiner_entries_001f08 },
    {   0x1F09,  4, s_combiner_entries_001f09 },
    {   0x1F0A,  1, s_combiner_entries_001f0a },
    {   0x1F0B,  1, s_combiner_entries_001f0b },
    {   0x1F0C,  1, s_combiner_entries_001f0c },
    {   0x1F0D,  1, s_combiner_entries_001f0d },
    {   0x1F0E,  1, s_combiner_entries_001f0e },
    {   0x1F0F,  1, s_combiner_entries_001f0f },
    {   0x1F10,  2, s_combiner_entries_001f10 },
    {   0x1F11,  2, s_combiner_entries_001f11 },
    {   0x1F18,  2, s_combiner_entries_001f18 },
    {   0x1F19,  2, s_combiner_entries_001f19 },
    {   0x1F20,  4, s_combiner_entries_001f20 },
    {   0x1F21,  4, s_combiner_entries_001f21 },
    {   0x1F22,  1, s_combiner_entries_001f22 },
    {   0x1F23,  1, s_combiner_entries_001f23 },
    {   0x1F24,  1, s_combiner_entries_001f24 },
    {   0x1F25,  1, s_combiner_entries_001f25 },
    {   0x1F26,  1, s_combiner_entries_001f26 },
    {   0x1F27,  1, s_combiner_entries_001f27 },
    {   0x1F28,  4, s_combiner_entries_001f28 },
    {   0x1F29,  4, s_combiner_entries_001f29 },
    {   0x1F2A,  1, s_combiner_entries_001f2a },
    {   0x1F2B,  1, s_combiner_entries_001f2b },
    {   0x1F2C,  1, s_combiner_entries_001f2c },
    {   0x1F2D,  1, s_combiner_entries_001f2d },
    {   0x1F2E,  1, s_combiner_entries_001f2e },
    {   0x1F2F,  1, s_combiner_entries_001f2f },
    {   0x1F30,  3, s_combiner_entries_001f30 },
    {   0x1F31,  3, s_combiner_entries_001f31 },
    {   0x1F38,  3, s_combiner_entries_001f38 },
    {   0x1F39,  3, s_combiner_entries_001f39 },
    {   0x1F40,  2, s_combiner_entries_001f40 },
    {   0x1F41,  2, s_combiner_entries_001f41 },
    {   0x1F48,  2, s_combiner_entries_001f48 },
    {   0x1F49,  2, s_combiner_entries_001f49 },
    {   0x1F50,  3, s_combiner_entries_001f50 },
    {   0x1F51,  3, s_combiner_entries_001f51 },
    {   0x1F59,  3, s_combiner_entries_001f59 },
    {   0x1F60,  4, s_combiner_entries_001f60 },
    {   0x1F61,  4, s_combiner_entries_001f61 },
    {   0x1F62,  1, s_combiner_entries_001f62 },
    {   0x1F63,  1, s_combiner_entries_001f63 },
    {   0x1F64,  1, s_combiner_entries_001f64 },
    {   0x1F65,  1, s_combiner_entries_001f65 },
    {   0x1F66,  1, s_combiner_entries_001f66 },
    {   0x1F67,  1, s_combiner_entries_001f67 },
    {   0x1F68,  4, s_combiner_entries_001f68 },
    {   0x1F69,  4, s_combiner_entries_001f69 },
    {   0x1F6A,  1, s_combiner_entries_001f6a },
    {   0x1F6B,  1, s_combiner_entries_001f6b },
    {   0x1F6C,  1, s_combiner_entries_001f6c },
    {   0x1F6D,  1, s_combiner_entries_001f6d },
    {   0x1F6E,  1, s_combiner_entries_001f6e },
    {   0x1F6F,  1, s_combiner_entries_001f6f },
    {   0x1F70,  1, s_combiner_entries_001f70 },
    {   0x1F74,  1, s_combiner_entries_001f74 },
    {   0x1F7C,  1, s_combiner_entries_001f7c },
    {   0x1FB6,  1, s_combiner_entries_001fb6 },
    {   0x1FBF,  3, s_combiner_entries_001fbf },
    {   0x1FC6,  1, s_combiner_entries_001fc6 },
    {   0x1FF6,  1, s_combiner_entries_001ff6 },
    {   0x1FFE,  3, s_combiner_entries_001ffe },
    {   0x2190,  1, s_combiner_entries_002190 },
    {   0x2192,  1, s_combiner_entries_002192 },
    {   0x2194,  1, s_combiner_entries_002194 },
    {   0x21D0,  1, s_combiner_entries_0021d0 },
    {   0x21D2,  1, s_combiner_entries_0021d2 },
    {   0x21D4,  1, s_combiner_entries_0021d4 },
    {   0x2203,  1, s_combiner_entries_002203 },
    {   0x2208,  1, s_combiner_entries_002208 },
    {   0x220B,  1, s_combiner_entries_00220b },
    {   0x2223,  1, s_combiner_entries_002223 },
    {   0x2225,  1, s_combiner_entries_002225 },
    {   0x223C,  1, s_combiner_entries_00223c },
    {   0x2243,  1, s_combiner_entries_002243 },
    {   0x2245,  1, s_combiner_entries_002245 },
    {   0x2248,  1, s_combiner_entries_002248 },
    {   0x224D,  1, s_combiner_entries_00224d },
    {   0x2261,  1, s_combiner_entries_002261 },
    {   0x2264,  1, s_combiner_entries_002264 },
    {   0x2265,  1, s_combiner_entries_002265 },
    {   0x2272,  1, s_combiner_entries_002272 },
    {   0x2273,  1, s_combiner_entries_002273 },
    {   0x2276,  1, s_combiner_entries_002276 },
    {   0x2277,  1, s_combiner_entries_002277 },
    {   0x227A,  1, s_combiner_entries_00227a },
    {   0x227B,  1, s_combiner_entries_00227b },
    {   0x227C,  1, s_combiner_entries_00227c },
    {   0x227D,  1, s_combiner_entries_00227d },
    {   0x2282,  1, s_combiner_entries_002282 },
    {   0x2283,  1, s_combiner_entries_002283 },
    {   0x2286,  1, s_combiner_entries_002286 },
    {   0x2287,  1, s_combiner_entries_002287 },
    {   0x2291,  1, s_combiner_entries_002291 },
    {   0x2292,  1, s_combiner_entries_002292 },
    {   0x22A2,  1, s_combiner_entries_0022a2 },
    {   0x22A8,  1, s_combiner_entries_0022a8 },
    {   0x22A9,  1, s_combiner_entries_0022a9 },
    {   0x22AB,  1, s_combiner_entries_0022ab },
    {   0x22B2,  1, s_combiner_entries_0022b2 },
    {   0x22B3,  1, s_combiner_entries_0022b3 },
    {   0x22B4,  1, s_combiner_entries_0022b4 },
    {   0x22B5,  1, s_combiner_entries_0022b5 },
    {   0x3046,  1, s_combiner_entries_003046 },
    {   0x304B,  1, s_combiner_entries_00304b },
    {   0x304D,  1, s_combiner_entries_00304d },
    {   0x304F,  1, s_combiner_entries_00304f },
    {   0x3051,  1, s_combiner_entries_003051 },
    {   0x3053,  1, s_combiner_entries_003053 },
    {   0x3055,  1, s_combiner_entries_003055 },
    {   0x3057,  1, s_combiner_entries_003057 },
    {   0x3059,  1, s_combiner_entries_003059 },
    {   0x305B,  1, s_combiner_entries_00305b },
    {   0x305D,  1, s_combiner_entries_00305d },
    {   0x305F,  1, s_combiner_entries_00305f },
    {   0x3061,  1, s_combiner_entries_003061 },
    {   0x3064,  1, s_combiner_entries_003064 },
    {   0x3066,  1, s_combiner_entries_003066 },
    {   0x3068,  1, s_combiner_entries_003068 },
    {   0x306F,  2, s_combiner_entries_00306f },
    {   0x3072,  2, s_combiner_entries_003072 },
    {   0x3075,  2, s_combiner_entries_003075 },
    {   0x3078,  2, s_combiner_entries_003078 },
    {   0x307B,  2, s_combiner_entries_00307b },
    {   0x309D,  1, s_combiner_entries_00309d },
    {   0x30A6,  1, s_combiner_entries_0030a6 },
    {   0x30AB,  1, s_combiner_entries_0030ab },
    {   0x30AD,  1, s_combiner_entries_0030ad },
    {   0x30AF,  1, s_combiner_entries_0030af },
    {   0x30B1,  1, s_combiner_entries_0030b1 },
    {   0x30B3,  1, s_combiner_entries_0030b3 },
    {   0x30B5,  1, s_combiner_entries_0030b5 },
    {   0x30B7,  1, s_combiner_entries_0030b7 },
    {   0x30B9,  1, s_combiner_entries_0030b9 },
    {   0x30BB,  1, s_combiner_entries_0030bb },
    {   0x30BD,  1, s_combiner_entries_0030bd },
    {   0x30BF,  1, s_combiner_entries_0030bf },
    {   0x30C1,  1, s_combiner_entries_0030c1 },
    {   0x30C4,  1, s_combiner_entries_0030c4 },
    {   0x30C6,  1, s_combiner_entries_0030c6 },
    {   0x30C8,  1, s_combiner_entries_0030c8 },
    {   0x30CF,  2, s_combiner_entries_0030cf },
    {   0x30D2,  2, s_combiner_entries_0030d2 },
    {   0x30D5,  2, s_combiner_entries_0030d5 },
    {   0x30D8,  2, s_combiner_entries_0030d8 },
    {   0x30DB,  2, s_combiner_entries_0030db },
    {   0x30EF,  1, s_combiner_entries_0030ef },
    {   0x30F0,  1, s_combiner_entries_0030f0 },
    {   0x30F1,  1, s_combiner_entries_0030f1 },
    {   0x30F2,  1, s_combiner_entries_0030f2 },
    {   0x30FD,  1, s_combiner_entries_0030fd },
    { 0x0105D2,  1, s_combiner_entries_0105d2 },
    { 0x0105DA,  1, s_combiner_entries_0105da },
    { 0x011099,  1, s_combiner_entries_011099 },
    { 0x01109B,  1, s_combiner_entries_01109b },
    { 0x0110A5,  1, s_combiner_entries_0110a5 },
    { 0x011131,  1, s_combiner_entries_011131 },
    { 0x011132,  1, s_combiner_entries_011132 },
    { 0x011347,  2, s_combiner_entries_011347 },
    { 0x011382,  1, s_combiner_entries_011382 },
    { 0x011384,  1, s_combiner_entries_011384 },
    { 0x01138B,  1, s_combiner_entries_01138b },
    { 0x011390,  1, s_combiner_entries_011390 },
    { 0x0113C2,  3, s_combiner_entries_0113c2 },
    { 0x0114B9,  3, s_combiner_entries_0114b9 },
    { 0x0115B8,  1, s_combiner_entries_0115b8 },
    { 0x0115B9,  1, s_combiner_entries_0115b9 },
    { 0x011935,  1, s_combiner_entries_011935 },
    { 0x01611E,  4, s_combiner_entries_01611e },
    { 0x016121,  2, s_combiner_entries_016121 },
    { 0x016122,  1, s_combiner_entries_016122 },
    { 0x016129,  1, s_combiner_entries_016129 },
    { 0x016D63,  1, s_combiner_entries_016d63 },
    { 0x016D67,  1, s_combiner_entries_016d67 },
    { 0x016D69,  1, s_combiner_entries_016d69 },
};

#endif // TINYUC_DATA_UNICODE_COMBINE_H
