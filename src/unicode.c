/**
 * @file unicode.c
 *
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Unicode support implementation
 */

#include <tinyuc/unicode.h>

#include "private/buffer.h"
#include "private/helpers.h"
#include "unicode_combine.h"
#include "unicode_decomp.h"
#include "unicode_defines.h"
#include "unicode_mapping.h"
#include "unicode_props.h"

#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------------------------- */
/*                                   Macros                                   */
/* -------------------------------------------------------------------------- */

#define FOR_EACH_CODEPOINT(cp, str, len)                              \
    const unsigned char* _iter = (const unsigned char*)(str);         \
    const unsigned char* _last = (const unsigned char*)_iter + (len); \
    for (; tinyuc_iter_next(&_iter, _last, &(cp));)

#define FOR_EACH_CODEPOINT_CHECK_RET(failval) \
    do                                        \
    {                                         \
        if (_iter != _last)                   \
        {                                     \
            return failval;                   \
        }                                     \
    } while (0);

#define CODEPOINT_BYTE_POS(str) (size_t)(_iter - (const unsigned char*)(str))

#define TINYUC_COMP(a, b) (((a) > (b)) ? 1 : ((a) < (b)) ? -1 : 0)

/* -------------------------------------------------------------------------- */
/*                               Property lookup                              */
/* -------------------------------------------------------------------------- */

static const tinyucd_prop* tinyuc_get_prop(uint32_t cp)
{
    assert(cp <= 0x110000);
    unsigned int offset = s_tinyucd_stage1_table[cp / TINYUCD_BLOCK_SIZE] * TINYUCD_BLOCK_SIZE;
    unsigned int index = s_tinyucd_stage2_table[offset + cp % TINYUCD_BLOCK_SIZE];
    assert(index < TINYUCD_NUM_PROPERTIES);
    return s_tinyucd_prop_table + index;
}

static const tinyucd_mapping* tinyuc_get_mapping(const tinyucd_prop* prop)
{
    if (prop && prop->mapping_idx)
    {
        assert(prop->mapping_idx > 0 && prop->mapping_idx <= TINYUCD_NUM_MAPPING);
        return s_tinyucd_mapping_table + prop->mapping_idx - 1;
    }
    return NULL;
}

static const tinyucd_decomp* tinyuc_get_decomp(const tinyucd_prop* prop)
{
    if (prop && prop->decomp_idx)
    {
        assert(prop->decomp_idx > 0 && prop->decomp_idx <= TINYUCD_NUM_DECOMP);
        return s_tinyucd_decomp_table + prop->decomp_idx - 1;
    }
    return NULL;
}

static const tinyucd_combiners* tinyuc_get_combiners(const tinyucd_prop* prop)
{
    if (prop && prop->combiner_idx)
    {
        assert(prop->combiner_idx > 0 && prop->combiner_idx <= TINYUCD_NUM_COMBINER);
        return s_tinyucd_combiner_table + prop->combiner_idx - 1;
    }
    return NULL;
}

static inline tinyucd_gcb tinyucd_prop_gcb(const tinyucd_prop* prop)
{
    return prop ? (tinyucd_gcb)prop->gcb : TINYUCD_GCB_OTHER;
}

static inline tinyucd_incb tinyucd_prop_incb(const tinyucd_prop* prop)
{
    return prop ? (tinyucd_incb)prop->incb : TINYUCD_INCB_NONE;
}

static inline bool tinyucd_prop_extpict(const tinyucd_prop* prop)
{
    return prop && prop->extpict;
}

// static bool is_combining_mark(tinyucd_prop* prop)
// {
//     return prop && prop->ccc > 0;
// }

/* -------------------------------------------------------------------------- */
/*                                 Validation                                 */
/* -------------------------------------------------------------------------- */

static inline uint32_t tinyuc_fetch2(const unsigned char* bytes)
{
    return ((bytes[0] & 0x1Fu) << 6) //
           | (bytes[1] & 0x3Fu);
}

static inline uint32_t tinyuc_fetch3(const unsigned char* bytes)
{
    return ((bytes[0] & 0x0Fu) << 12)  //
           | ((bytes[1] & 0x3Fu) << 6) //
           | (bytes[2] & 0x3Fu);       //
}

static inline uint32_t tinyuc_fetch4(const unsigned char* bytes)
{
    return ((bytes[0] & 0x07u) << 18)   //
           | ((bytes[1] & 0x3Fu) << 12) //
           | ((bytes[2] & 0x3Fu) << 6)  //
           | (bytes[3] & 0x3Fu);        //
}

/**
 * @brief UTF-8 string iterator, only works on validated string
 * @param iter pointer to current position, will increment to next valid position
 * @return uint32_t, might be NULL
 */
static uint32_t tinyuc_next_valid(const unsigned char** iter)
{
    const unsigned char* bytes = *iter;
    uint32_t cp;
    if (bytes[0] < 0x80u)
    {
        cp = bytes[0];
        *iter = bytes + 1;
    }
    else if ((bytes[0] & 0xE0) == 0xC0u)
    {
        cp = tinyuc_fetch2(bytes);
        *iter = bytes + 2;
    }
    else if ((bytes[0] & 0xF0) == 0xE0u)
    {
        cp = tinyuc_fetch3(bytes);
        *iter = bytes + 3;
    }
    else // 4-byte sequence
    {
        cp = tinyuc_fetch4(bytes);
        *iter = bytes + 4;
    }
    return cp;
}

uint32_t tinyuc_iter_utf8(const unsigned char** iter)
{
    return tinyuc_next_valid(iter);
}

/**
 * @brief Decode the next codepoint if it starts before @p last.
 *
 * Unlike @ref tinyuc_next_valid(), this never reads at or past @p last, so it
 * is safe for buffers that are not null-terminated.
 *
 * @param iter in/out pointer to the current position
 * @param last pointer one past the end of the buffer
 * @param out receives the decoded codepoint
 * @return true if a codepoint was decoded, false if @p *iter reached @p last
 */
static bool tinyuc_iter_next(const unsigned char** iter, const unsigned char* last, uint32_t* out)
{
    if (*iter >= last)
        return false;
    *out = tinyuc_next_valid(iter);
    return true;
}

// static inline size_t tinyuc_iter_pos(const unsigned char* iter, const char* src)
// {
//     return (size_t)(iter - (const unsigned char*)src);
// }

// NOTE:
// See implementation notes here:
// https://unicode.org/mail-arch/unicode-ml/y2003-m02/att-0467/01-The_Algorithm_to_Valide_an_UTF-8_String
enum tinyuc_result tinyuc_validate(const char* str, size_t len, char** errmsg)
{
    if (!str)
    {
        return TINYUC_INVALID_ARGS;
    }

    if (len == TINYUC_NPOS)
    {
        len = strlen(str);
    }

    const unsigned char* bytes = (const unsigned char*)str;

    bool success = false;
    size_t errpos = SIZE_MAX;
    size_t expected = 0;

    uint32_t cp;
    size_t i = 0;

    while (i < len)
    {
        unsigned char c = bytes[i];
        if (c < 0x80) // < 0xxx xxxx
        {
            i++;
            continue;
        }
        if ((c & 0xE0u) == 0xC0u) // 110x xxxx, 2 bytes
        {
            if (i + 1 >= len) // Truncated
            {
                errpos = i;
                expected = 2;
                break;
            }
            if ((bytes[i + 1] & 0xC0u) != 0x80u)
            {
                errpos = i;
                break;
            }
            cp = tinyuc_fetch2(bytes + i);
            if (cp < 0x80u) // Overlong
            {
                errpos = i;
                break;
            }
            i += 2;
        }
        else if ((c & 0xF0u) == 0xE0u) // 1110 xxxx, 3 bytes
        {
            if (i + 2 >= len) // Truncated
            {
                errpos = i;
                expected = 3;
                break;
            }
            if ((bytes[i + 1] & 0xC0u) != 0x80u || (bytes[i + 2] & 0xC0u) != 0x80u)
            {
                errpos = i;
                break;
            }
            cp = tinyuc_fetch3(bytes + i);
            if (cp < 0x800u) // Overlong
            {
                errpos = i;
                break;
            }
            if (cp >= 0xD800u && cp <= 0xDFFFu) // Surrogate
            {
                errpos = i;
                break;
            }
            i += 3;
        }
        else if ((c & 0xF8u) == 0xF0u) // 1111 xxxx, 4 bytes
        {
            if (i + 3 >= len) // Truncated
            {
                errpos = i;
                expected = 4;
                break;
            }
            if ((bytes[i + 1] & 0xC0u) != 0x80u || (bytes[i + 2] & 0xC0u) != 0x80u ||
                (bytes[i + 3] & 0xC0u) != 0x80u)
            {
                errpos = i;
                break;
            }
            cp = tinyuc_fetch4(bytes + i);
            if (cp < 0x10000u || cp > 0x10FFFFu) // Out of range
            {
                errpos = i;
                break;
            }
            i += 4;
        }
        else
        {
            errpos = i;
            break;
        }
    }
    if (i == len)
    {
        success = true;
    }
    else if (errmsg)
    {
        if (expected)
        {
            tinyuc_asprintf(errmsg,
                            "Truncated UTF-8 sequence at position %zu: expected %zu bytes, got %zu",
                            errpos,
                            expected,
                            len - errpos);
        }
        else
        {
            tinyuc_asprintf(errmsg, "Invalid UTF-8 sequence at position %zu", errpos);
        }
    }
    return success ? TINYUC_OK : TINYUC_INVALID_UTF8;
}

/* -------------------------------------------------------------------------- */
/*                             Buffer and encoder                             */
/* -------------------------------------------------------------------------- */

int tinyuc_encode_codepoint(uint8_t* dst, const uint32_t cp)
{
    int bytes_len = 0;
    if (cp <= 0x7F)
    {
        // 1-byte sequence (0xxxxxxx)
        if (dst)
        {
            dst[bytes_len++] = (uint8_t)cp;
        }
        else
        {
            bytes_len++;
        }
    }
    else if (cp <= 0x7FF)
    {
        // 2-byte sequence (110xxxxx 10xxxxxx)
        if (dst)
        {
            dst[bytes_len++] = (uint8_t)(0xC0 | (cp >> 6));
            dst[bytes_len++] = (uint8_t)(0x80 | (cp & 0x3F));
        }
        else
        {
            bytes_len += 2;
        }
    }
    else if (cp <= 0xFFFF)
    {
        // Surrogates are not valid Unicode scalar values
        if (cp >= 0xD800 && cp <= 0xDFFF)
            return -1;
        // 3-byte sequence (1110xxxx 10xxxxxx 10xxxxxx)
        if (dst)
        {
            dst[bytes_len++] = (uint8_t)(0xE0 | (cp >> 12));
            dst[bytes_len++] = (uint8_t)(0x80 | ((cp >> 6) & 0x3F));
            dst[bytes_len++] = (uint8_t)(0x80 | (cp & 0x3F));
        }
        else
        {
            bytes_len += 3;
        }
    }
    else if (cp <= 0x10FFFF)
    {
        // 4-byte sequence (11110xxx 10xxxxxx 10xxxxxx 10xxxxxx)
        if (dst)
        {
            dst[bytes_len++] = (uint8_t)(0xF0 | (cp >> 18));
            dst[bytes_len++] = (uint8_t)(0x80 | ((cp >> 12) & 0x3F));
            dst[bytes_len++] = (uint8_t)(0x80 | ((cp >> 6) & 0x3F));
            dst[bytes_len++] = (uint8_t)(0x80 | (cp & 0x3F));
        }
        else
        {
            bytes_len += 4;
        }
    }
    else
    {
        // Invalid code point (outside Unicode range)
        return -1;
    }
    return bytes_len;
}

enum tinyuc_result tinyuc_encode_codepoints_buf(const uint32_t* cp,
                                                size_t cplen,
                                                char* buf,
                                                size_t blen,
                                                size_t* o_len,
                                                size_t* o_npcp,
                                                char** errmsg)
{
    if (!cp || !o_len)
    {
        if (errmsg)
            *errmsg = strdup("Invalid arguments, either cp or o_len is NULL");
        return TINYUC_INVALID_ARGS;
    }

    size_t out_len = 0;
    size_t out_cp = 0;

    if (!buf)
    {
        // Calculate the required buffer size
        for (size_t i = 0; i < cplen; i++)
        {
            int res = tinyuc_encode_codepoint(NULL, cp[i]);
            if (res < 0)
            {
                if (errmsg)
                {
                    tinyuc_asprintf(errmsg, "Invalid codepoint: %" PRIu32, cp[i]);
                }
                *o_len = out_len;
                *o_npcp = out_cp;
                return TINYUC_INVALID_CODEPOINT;
            }
            out_len += (size_t)res;
            out_cp++;
        }
        *o_len = out_len;
        *o_npcp = out_cp;
        return TINYUC_OK;
    }

    if (blen < 4)
    {
        *o_len = 0;
        *o_npcp = 0;
        return TINYUC_BUFFER_TOO_SMALL;
    }

    uint8_t cpbuf[4];
    for (size_t i = 0; i < cplen; i++)
    {
        int res = tinyuc_encode_codepoint(cpbuf, cp[i]);
        if (res < 0)
        {
            if (errmsg)
            {
                tinyuc_asprintf(errmsg, "Invalid codepoint: %" PRIu32, cp[i]);
            }
            *o_len = out_len;
            *o_npcp = out_cp;
            return TINYUC_INVALID_CODEPOINT;
        }
        else if (out_len + (size_t)res > blen)
        {
            // Buffer is full, return early
            break;
        }
        // Append
        out_len += (size_t)res;
        out_cp++;
        memcpy(buf + out_len - (size_t)res, cpbuf, (size_t)res);
    }
    *o_len = out_len;
    *o_npcp = out_cp;
    return TINYUC_OK;
}

/**
 * Encodes an array of unicode code points into UTF-8 and appends them
 * to the buffer.
 * Assumes that the buffer codepoints and len are valid.
 */
static enum tinyuc_result tinyuc_encode_codepoints(tinyuc_buffer* buf,
                                                   const uint32_t* codepoints,
                                                   size_t len,
                                                   char** errmsg)
{
    // Minimum chunks to work with
    uint8_t bytes[5 * TINYUCD_MAX_MULTI_LEN];
    size_t bytes_len = 0;
    for (size_t i = 0; i < len; i++)
    {
        int res = tinyuc_encode_codepoint(bytes + bytes_len, codepoints[i]);
        if (res < 0)
        {
            if (errmsg)
            {
                tinyuc_asprintf(errmsg, "Invalid codepoint: %" PRIu32, codepoints[i]);
            }
            return TINYUC_INVALID_CODEPOINT;
        }
        bytes_len += (size_t)res;

        // Push to buffer if next pass might overflow
        if (bytes_len >= (size_t)(4 * TINYUCD_MAX_MULTI_LEN))
        {
            if (!tinyuc_buffer_push(buf, bytes, bytes_len))
                return TINYUC_OUT_OF_MEMORY;
            bytes_len = 0;
        }
    }
    // Push remaining bytes
    if (bytes_len > 0 && !tinyuc_buffer_push(buf, bytes, bytes_len))
    {
        return TINYUC_OUT_OF_MEMORY;
    }
    return TINYUC_OK;
}

/* -------------------------------------------------------------------------- */
/*                                 Characters                                 */
/* -------------------------------------------------------------------------- */

size_t tinyuc_num_cp(const char* str, size_t len)
{
    size_t num = 0;
    if (str)
    {
        if (len == TINYUC_NPOS)
            len = strlen(str);

        uint32_t cp;
        FOR_EACH_CODEPOINT(cp, str, len)
        {
            TINYUC_UNUSED(cp);
            num++;
        }
        FOR_EACH_CODEPOINT_CHECK_RET(TINYUC_NPOS);
    }
    return num;
}

/* -------------------------------------------------------------------------- */
/*                          Extended grapheme clusters                        */
/* -------------------------------------------------------------------------- */

// State carried while scanning for grapheme cluster boundaries (UAX #29).
typedef struct tinyucd_grapheme_state
{
    bool ri_odd;      // Odd number of consecutive Regional_Indicator before current
    uint8_t gb11;     // 0 none, 1 ExtPict, 2 ExtPict Extend*, 3 ExtPict Extend* ZWJ
    bool incb_seq;    // Inside Consonant [Extend Linker]*
    bool incb_linker; // A Linker has been seen since the consonant
} tinyucd_grapheme_state;

static void tinyucd_grapheme_update(tinyucd_grapheme_state* st,
                                    tinyucd_gcb gcb,
                                    bool extpict,
                                    tinyucd_incb incb)
{
    // GB11: track Extended_Pictographic Extend* ZWJ
    if (extpict)
        st->gb11 = 1;
    else if (gcb == TINYUCD_GCB_EXTEND && (st->gb11 == 1 || st->gb11 == 2))
        st->gb11 = 2;
    else if (gcb == TINYUCD_GCB_ZWJ && (st->gb11 == 1 || st->gb11 == 2))
        st->gb11 = 3;
    else
        st->gb11 = 0;

    // GB12/GB13: parity of consecutive regional indicators
    if (gcb == TINYUCD_GCB_REGIONAL_INDICATOR)
        st->ri_odd = !st->ri_odd;
    else
        st->ri_odd = false;

    // GB9c: track Consonant [Extend Linker]* with at least one Linker
    if (incb == TINYUCD_INCB_CONSONANT)
    {
        st->incb_seq = true;
        st->incb_linker = false;
    }
    else if (st->incb_seq && (incb == TINYUCD_INCB_EXTEND || incb == TINYUCD_INCB_LINKER))
    {
        if (incb == TINYUCD_INCB_LINKER)
            st->incb_linker = true;
    }
    else
    {
        st->incb_seq = false;
        st->incb_linker = false;
    }
}

// Evaluate the UAX #29 boundary rules in order. Returns true when a break is
// required between the previous codepoint (described by @p st) and the current.
static bool tinyucd_grapheme_should_break(const tinyucd_grapheme_state* st,
                                          tinyucd_gcb a,
                                          tinyucd_gcb b,
                                          bool cur_extpict,
                                          tinyucd_incb cur_incb)
{
    // GB3: CR x LF
    if (a == TINYUCD_GCB_CR && b == TINYUCD_GCB_LF)
        return false;
    // GB4: (Control | CR | LF) ÷
    if (a == TINYUCD_GCB_CONTROL || a == TINYUCD_GCB_CR || a == TINYUCD_GCB_LF)
        return true;
    // GB5: ÷ (Control | CR | LF)
    if (b == TINYUCD_GCB_CONTROL || b == TINYUCD_GCB_CR || b == TINYUCD_GCB_LF)
        return true;
    // GB6: L x (L | V | LV | LVT)
    if (a == TINYUCD_GCB_L &&
        (b == TINYUCD_GCB_L || b == TINYUCD_GCB_V || b == TINYUCD_GCB_LV || b == TINYUCD_GCB_LVT))
        return false;
    // GB7: (LV | V) x (V | T)
    if ((a == TINYUCD_GCB_LV || a == TINYUCD_GCB_V) && (b == TINYUCD_GCB_V || b == TINYUCD_GCB_T))
        return false;
    // GB8: (LVT | T) x T
    if ((a == TINYUCD_GCB_LVT || a == TINYUCD_GCB_T) && b == TINYUCD_GCB_T)
        return false;
    // GB9: x (Extend | ZWJ)
    if (b == TINYUCD_GCB_EXTEND || b == TINYUCD_GCB_ZWJ)
        return false;
    // GB9a: x SpacingMark
    if (b == TINYUCD_GCB_SPACINGMARK)
        return false;
    // GB9b: Prepend x
    if (a == TINYUCD_GCB_PREPEND)
        return false;
    // GB9c: Consonant [Extend Linker]* Linker [Extend Linker]* x Consonant
    if (st->incb_seq && st->incb_linker && cur_incb == TINYUCD_INCB_CONSONANT)
        return false;
    // GB11: ExtPict Extend* ZWJ x ExtPict
    if (st->gb11 == 3 && cur_extpict)
        return false;
    // GB12/GB13: RI x RI when preceded by an odd number of RI
    if (a == TINYUCD_GCB_REGIONAL_INDICATOR && b == TINYUCD_GCB_REGIONAL_INDICATOR && st->ri_odd)
        return false;
    // GB999: Any ÷ Any
    return true;
}

// Step back to the start of the codepoint ending just before @p pos.
static const unsigned char* tinyuc_prev_start(const unsigned char* base, const unsigned char* pos)
{
    pos--; // Last byte of the previous codepoint
    while (pos > base && (*pos & 0xC0u) == 0x80u)
        pos--;
    return pos;
}

// Decode the codepoint at @p start and return its property entry. If @p end is
// given, it receives the position after the codepoint.
static const tinyucd_prop* tinyucd_prop_at(const unsigned char* start, const unsigned char** end)
{
    const unsigned char* iter = start;
    uint32_t cp = tinyuc_next_valid(&iter);
    if (end)
        *end = iter;
    return tinyuc_get_prop(cp);
}

// Reconstruct the scanner state for a valid cluster boundary at @p from.
static void tinyucd_grapheme_state_at(const char* str, size_t from, tinyucd_grapheme_state* st)
{
    memset(st, 0, sizeof(*st));
    if (from == 0)
        return;

    const unsigned char* base = (const unsigned char*)str;
    const unsigned char* pos = base + from;

    // GB12/GB13: parity of the trailing run of Regional_Indicator.
    {
        bool odd = false;
        const unsigned char* p = pos;
        while (p > base)
        {
            const unsigned char* q = tinyuc_prev_start(base, p);
            const tinyucd_prop* prop = tinyucd_prop_at(q, NULL);
            if (!prop || tinyucd_prop_gcb(prop) != TINYUCD_GCB_REGIONAL_INDICATOR)
                break;
            odd = !odd;
            p = q;
        }
        st->ri_odd = odd;
    }

    // GB11: does the sequence end with Extended_Pictographic Extend* ZWJ?
    {
        const unsigned char* p = pos;
        if (p > base)
        {
            const unsigned char* q = tinyuc_prev_start(base, p);
            const tinyucd_prop* prop = tinyucd_prop_at(q, NULL);
            if (prop && tinyucd_prop_gcb(prop) == TINYUCD_GCB_ZWJ)
            {
                p = q;
                while (p > base)
                {
                    q = tinyuc_prev_start(base, p);
                    prop = tinyucd_prop_at(q, NULL);
                    if (prop && tinyucd_prop_extpict(prop))
                    {
                        st->gb11 = 3;
                        break;
                    }
                    if (!prop || tinyucd_prop_gcb(prop) != TINYUCD_GCB_EXTEND)
                        break;
                    p = q;
                }
            }
        }
    }

    // GB9c: does the sequence end with Consonant [Extend Linker]* including a Linker?
    {
        bool linker = false;
        const unsigned char* p = pos;
        while (p > base)
        {
            const unsigned char* q = tinyuc_prev_start(base, p);
            const tinyucd_prop* prop = tinyucd_prop_at(q, NULL);
            tinyucd_incb incb = tinyucd_prop_incb(prop);
            if (incb == TINYUCD_INCB_LINKER)
            {
                linker = true;
                p = q;
            }
            else if (incb == TINYUCD_INCB_EXTEND)
            {
                p = q;
            }
            else if (incb == TINYUCD_INCB_CONSONANT)
            {
                st->incb_seq = true;
                st->incb_linker = linker;
                break;
            }
            else
            {
                break;
            }
        }
    }
}

// Find the next cluster boundary at or after @p start. @p st must describe the
// position @p start, which itself must be a boundary.
static size_t tinyucd_grapheme_next_from(const char* str,
                                         const unsigned char* start,
                                         const unsigned char* last,
                                         tinyucd_grapheme_state* st)
{
    const unsigned char* iter = start;
    const tinyucd_prop* prop = tinyucd_prop_at(iter, &iter);
    if (!prop)
    {
        return TINYUC_NPOS;
    }
    tinyucd_grapheme_update(st,
                            tinyucd_prop_gcb(prop),
                            tinyucd_prop_extpict(prop),
                            tinyucd_prop_incb(prop));

    while (iter < last)
    {
        const unsigned char* cp_start = iter;
        const tinyucd_prop* next_prop = tinyucd_prop_at(iter, &iter);
        if (!next_prop)
        {
            return TINYUC_NPOS;
        }

        if (tinyucd_grapheme_should_break(st,
                                          tinyucd_prop_gcb(prop),
                                          tinyucd_prop_gcb(next_prop),
                                          tinyucd_prop_extpict(next_prop),
                                          tinyucd_prop_incb(next_prop)))
            return (size_t)(cp_start - (const unsigned char*)str);

        tinyucd_grapheme_update(st,
                                tinyucd_prop_gcb(next_prop),
                                tinyucd_prop_extpict(next_prop),
                                tinyucd_prop_incb(next_prop));
        prop = next_prop;
    }
    return TINYUC_NPOS;
}

size_t tinyuc_num_char(const char* str, size_t len)
{
    size_t num = 0;

    if (str)
    {
        if (len == TINYUC_NPOS)
            len = strlen(str);

        const unsigned char* iter = (const unsigned char*)str;
        const unsigned char* last = iter + len;
        if (iter < last)
        {
            tinyucd_grapheme_state st = {0};
            const tinyucd_prop* prop = tinyucd_prop_at(iter, &iter);
            if (!prop)
                return TINYUC_NPOS;

            tinyucd_grapheme_update(&st,
                                    tinyucd_prop_gcb(prop),
                                    tinyucd_prop_extpict(prop),
                                    tinyucd_prop_incb(prop));
            num = 1;

            while (iter < last)
            {
                const tinyucd_prop* next_prop = tinyucd_prop_at(iter, &iter);
                if (!next_prop)
                    return TINYUC_NPOS;

                if (tinyucd_grapheme_should_break(&st,
                                                  tinyucd_prop_gcb(prop),
                                                  tinyucd_prop_gcb(next_prop),
                                                  tinyucd_prop_extpict(next_prop),
                                                  tinyucd_prop_incb(next_prop)))
                    num++;
                tinyucd_grapheme_update(&st,
                                        tinyucd_prop_gcb(next_prop),
                                        tinyucd_prop_extpict(next_prop),
                                        tinyucd_prop_incb(next_prop));
                prop = next_prop;
            }
        }
    }
    return num;
}

size_t tinyuc_next_char(const char* str, size_t len, size_t from_byte)
{
    if (!str)
        return TINYUC_NPOS;

    if (from_byte >= len)
        return TINYUC_NPOS;

    tinyucd_grapheme_state st;
    tinyucd_grapheme_state_at(str, from_byte, &st);

    const unsigned char* start = (const unsigned char*)str + from_byte;
    const unsigned char* last = (const unsigned char*)str + len;
    return tinyucd_grapheme_next_from(str, start, last, &st);
}

size_t tinyuc_char_index(const char* str, size_t len, size_t index)
{
    if (!str || index == 0)
        return len;

    const unsigned char* base = (const unsigned char*)str;
    const unsigned char* iter = base;
    const unsigned char* last = base + len;

    if (iter >= last)
        return len;

    tinyucd_grapheme_state st = {0};
    const tinyucd_prop* prop = tinyucd_prop_at(iter, &iter);
    if (!prop)
        return len;

    tinyucd_grapheme_update(&st,
                            tinyucd_prop_gcb(prop),
                            tinyucd_prop_extpict(prop),
                            tinyucd_prop_incb(prop));

    // `num` is the cluster currently being scanned (1-based). A break at the
    // start of the next cluster completes `num` and yields its end boundary.
    size_t num = 1;

    while (iter < last)
    {
        const unsigned char* cp_start = iter;
        const tinyucd_prop* next_prop = tinyucd_prop_at(iter, &iter);
        if (!next_prop)
            return len;

        if (tinyucd_grapheme_should_break(&st,
                                          tinyucd_prop_gcb(prop),
                                          tinyucd_prop_gcb(next_prop),
                                          tinyucd_prop_extpict(next_prop),
                                          tinyucd_prop_incb(next_prop)))
        {
            if (num == index)
                return (size_t)(cp_start - base);
            num++;
        }

        tinyucd_grapheme_update(&st,
                                tinyucd_prop_gcb(next_prop),
                                tinyucd_prop_extpict(next_prop),
                                tinyucd_prop_incb(next_prop));
        prop = next_prop;
    }

    // The final cluster ends at the end of the string.
    return len;
}

/* -------------------------------------------------------------------------- */
/*                               Case conversion                              */
/* -------------------------------------------------------------------------- */

typedef enum tinyuc_case_op
{
    TINYUCD_CASE_UPPER,
    TINYUCD_CASE_LOWER,
    TINYUCD_CASE_TITLE,
    TINYUCD_CASE_FOLD,
} tinyuc_case_op_t;

// Returns true if the code point is a word separator for titlecase purposes.
static bool tinyuc_is_word_separator(uint32_t cp, const tinyucd_prop* prop)
{
    if (cp == 0x27)
        return false; // Apostrophe (') is not a separator
    // if (cp == 0x2D)
    //     return true; // Hyphen (-) is a separator (optional)

    switch (prop->category)
    {
    // Whitespace
    case TINYUCD_GC_ZS: // Space separator
    case TINYUCD_GC_ZL: // Line separator
    case TINYUCD_GC_ZP: // Paragraph separator
    // Punctuation (excluding apostrophes)
    case TINYUCD_GC_PO: // Other punctuation (e.g., !, ?, .)
    case TINYUCD_GC_PS: // Opening punctuation (e.g., (
    case TINYUCD_GC_PE: // Closing punctuation (e.g., ))
    // Controls
    case TINYUCD_GC_CC: // Control characters (e.g., \n, \t)
        return true;
    default:
        return false;
    }
}

typedef struct
{
    size_t out_len;
    uint32_t buf[TINYUCD_MAX_MULTI_LEN];
    tinyuc_case_op_t op;
    const tinyucd_prop* last_prop;
    uint32_t last_cp;
} casemap_ctx_t;

static enum tinyuc_result tinyuc_case_map_cp(casemap_ctx_t* ctx, char** errmsg)
{
    ctx->out_len = 1; // By default, keep value sent in
    if (!ctx->buf[0]) // Null terminator
        return TINYUC_OK;

    const tinyucd_prop* prop = tinyuc_get_prop(ctx->buf[0]);

    if (!prop)
    {
        if (errmsg)
            tinyuc_asprintf(errmsg, "Invalid codepoint: %" PRIu32, ctx->buf[0]);
        return TINYUC_INVALID_CODEPOINT;
    }

    const tinyucd_mapping* mapping = tinyuc_get_mapping(prop);
    if (!mapping)
    {
        ctx->last_cp = ctx->buf[0];
        ctx->last_prop = prop;
        return TINYUC_OK;
    }

    uint16_t ref;
    switch (ctx->op)
    {
    case TINYUCD_CASE_UPPER:
        ref = mapping->to_upper;
        break;
    case TINYUCD_CASE_LOWER:
        ref = mapping->to_lower;
        break;
    case TINYUCD_CASE_TITLE:
    {
        if (!ctx->last_prop || tinyuc_is_word_separator(ctx->last_cp, ctx->last_prop))
            ref = mapping->to_title;
        else
            ref = mapping->to_lower;
        break;
    }
    case TINYUCD_CASE_FOLD:
        ref = mapping->to_casefold;
        break;
    default:
        tinyuc_error("Invalid casemap operation");
        return TINYUC_INTERNAL_ERROR;
    }

    // No more use for last prop
    ctx->last_prop = prop;
    ctx->last_cp = ctx->buf[0];

    if (!ref)
        return TINYUC_OK;

    if (ref <= TINYUCD_NUM_SIMPLE_MAP)
    {
        int idx = ref - 1;
        ctx->buf[0] = s_tinyucd_smap_table[idx].value;
    }
    else
    {
        int idx = ref - TINYUCD_NUM_SIMPLE_MAP - 1;
        TINYUC_ASSERT(idx <= TINYUCD_NUM_MULTI_MAP, "Invalid mapping index");
        const tinyucd_mmap* entry = &s_tinyucd_mmap_table[idx];

        size_t len = 0;
        for (; len < TINYUCD_MAX_MULTI_LEN && entry->value[len] != TINYUCD_NO_VALUE; len++)
        {
            ctx->buf[len] = entry->value[len];
        }
        ctx->out_len = len;
    }
    return TINYUC_OK;
}

/**
 * Instead of working on a string, work on a buffer object
 * Setting codepoint of different sizes + UTF-8 encoding may result in different string
 * lengths.
 */
static enum tinyuc_result tinyuc_case_map(const char* str,
                                          size_t size,
                                          tinyuc_case_op_t op,
                                          char** ostr,
                                          size_t* osize,
                                          char** errmsg)
{
    if (!str)
    {
        if (errmsg)
            *errmsg = strdup("Invalid input string");
        return TINYUC_INVALID_ARGS;
    }
    if (!ostr)
    {
        if (errmsg)
            *errmsg = strdup("Invalid output string");
        return TINYUC_INVALID_ARGS;
    }

    enum tinyuc_result ret = TINYUC_ERROR;

    uint32_t cp;
    casemap_ctx_t ctx;
    ctx.last_cp = TINYUCD_NO_VALUE;
    ctx.last_prop = NULL;
    ctx.op = op;

    tinyuc_buffer dstbuf = {
        .data = (char*)calloc(size + 1, sizeof(char)),
        .size = 0,
        .capacity = size + 1,
    };
    if (!dstbuf.data)
    {
        return TINYUC_OUT_OF_MEMORY;
    }

    FOR_EACH_CODEPOINT(cp, str, size)
    {
        ctx.buf[0] = cp;

        if ((ret = tinyuc_case_map_cp(&ctx, errmsg)) != TINYUC_OK)
        {
            goto cleanup;
        }

        assert(ctx.out_len > 0 && ctx.out_len <= TINYUCD_MAX_MULTI_LEN);

        if ((ret = tinyuc_encode_codepoints(&dstbuf, ctx.buf, ctx.out_len, errmsg)) != TINYUC_OK)
        {
            goto cleanup;
        }
    }

    if (!tinyuc_buffer_push(&dstbuf, "\0", 1))
    {
        ret = TINYUC_OUT_OF_MEMORY;
        goto cleanup;
    }

    tinyuc_buffer_fit(&dstbuf);
    tinyuc_buffer_transfer(&dstbuf, ostr, osize, NULL);
    if (osize)
        *osize -= 1; // Do not count null-terminator

    ret = TINYUC_OK;
cleanup:
    tinyuc_buffer_release(&dstbuf);
    return ret;
}

enum tinyuc_result tinyuc_to_upper(const char* str,
                                   size_t size,
                                   char** ostr,
                                   size_t* osize,
                                   char** errmsg)
{
    return tinyuc_case_map(str, size, TINYUCD_CASE_UPPER, ostr, osize, errmsg);
}

enum tinyuc_result tinyuc_to_lower(const char* str,
                                   size_t size,
                                   char** ostr,
                                   size_t* osize,
                                   char** errmsg)
{
    return tinyuc_case_map(str, size, TINYUCD_CASE_LOWER, ostr, osize, errmsg);
}

enum tinyuc_result tinyuc_to_title(const char* str,
                                   size_t size,
                                   char** ostr,
                                   size_t* osize,
                                   char** errmsg)
{
    return tinyuc_case_map(str, size, TINYUCD_CASE_TITLE, ostr, osize, errmsg);
}

enum tinyuc_result tinyuc_casefold(const char* str,
                                   size_t size,
                                   char** ostr,
                                   size_t* osize,
                                   char** errmsg)
{
    return tinyuc_case_map(str, size, TINYUCD_CASE_FOLD, ostr, osize, errmsg);
}

/* -------------------------------------------------------------------------- */
/*                                Normalization                               */
/* -------------------------------------------------------------------------- */

// Size of the on-stack canonical reordering window. Segments longer than this
// grow to the heap; a canonical segment (starter + non-starters) has no upper
// bound, so this must never be treated as a hard limit.
#define NORM_CTX_BUFSIZE 18
#define UC_FLAGS_COMPOSE 0x01
#define UC_FLAGS_COMPAT 0x02

typedef struct
{
    tinyuc_buffer cp; // Codepoint buffer
    uint32_t cp_inline[NORM_CTX_BUFSIZE];
    uint8_t ccc_inline[NORM_CTX_BUFSIZE];
    uint32_t* cp_buf; // Reorder window, either cp_inline or a heap block
    uint8_t* ccc_buf; // Reorder window, either ccc_inline or a heap block
    size_t len;
    size_t cap;
    char* errpos;
    uint8_t flags;
} norm_ctx_t;

static void norm_ctx_init(norm_ctx_t* ctx)
{
    ctx->cp_buf = ctx->cp_inline;
    ctx->ccc_buf = ctx->ccc_inline;
    ctx->cap = NORM_CTX_BUFSIZE;
}

static void norm_ctx_destroy(norm_ctx_t* ctx)
{
    if (ctx->cp_buf != ctx->cp_inline)
        free(ctx->cp_buf);
    norm_ctx_init(ctx);
    ctx->len = 0;
}

// Slow path: grow the reorder window. Both arrays live in one allocation.
static enum tinyuc_result norm_ctx_grow_slow(norm_ctx_t* ctx, size_t needed, char** errmsg)
{
    TINYUC_UNUSED(errmsg);
    const size_t unit = sizeof(uint32_t) + sizeof(uint8_t);
    size_t newcap = ctx->cap;
    while (newcap < needed && newcap <= SIZE_MAX / 2)
        newcap *= 2;
    if (newcap < needed)
        newcap = needed;
    if (newcap > SIZE_MAX / unit)
        return TINYUC_OUT_OF_MEMORY;

    uint32_t* mem = (uint32_t*)malloc(newcap * unit);
    if (!mem)
        return TINYUC_OUT_OF_MEMORY;

    uint32_t* new_cp = mem;
    uint8_t* new_ccc = (uint8_t*)(mem + newcap);
    if (ctx->len > 0)
    {
        memcpy(new_cp, ctx->cp_buf, ctx->len * sizeof(uint32_t));
        memcpy(new_ccc, ctx->ccc_buf, ctx->len * sizeof(uint8_t));
    }
    if (ctx->cp_buf != ctx->cp_inline)
        free(ctx->cp_buf);

    ctx->cp_buf = new_cp;
    ctx->ccc_buf = new_ccc;
    ctx->cap = newcap;
    return TINYUC_OK;
}

static inline enum tinyuc_result norm_ctx_add(norm_ctx_t* ctx,
                                              uint32_t cp,
                                              uint8_t ccc,
                                              char** errmsg)
{
    enum tinyuc_result ret = TINYUC_OK;
    if (ctx->len >= ctx->cap && (ret = norm_ctx_grow_slow(ctx, ctx->len + 1, errmsg)) != TINYUC_OK)
        return ret;

    ctx->cp_buf[ctx->len] = cp;
    ctx->ccc_buf[ctx->len] = ccc;
    ctx->len++;

    // If this is a combining mark (CCC > 0), insert it in the correct position
    if (ccc > 0 && ctx->len > 1)
    {
        size_t i = ctx->len - 1;
        // Bubble it leftward past any combining marks with higher CCC
        while (i > 0 && ctx->ccc_buf[i - 1] > ccc)
        {
            // Swap with the previous mark
            ctx->cp_buf[i] = ctx->cp_buf[i - 1];
            ctx->ccc_buf[i] = ctx->ccc_buf[i - 1];
            ctx->cp_buf[i - 1] = cp;
            ctx->ccc_buf[i - 1] = ccc;
            i--;
        }
    }
    return ret;
}

static enum tinyuc_result norm_ctx_flush(norm_ctx_t* ctx, char** errmsg)
{
    enum tinyuc_result ret = TINYUC_OK;
    if (ctx->len > 0)
    {
        if (ctx->flags & UC_FLAGS_COMPOSE)
        {
            // Flush as codepoints
            if (!tinyuc_buffer_push(&ctx->cp, ctx->cp_buf, ctx->len * sizeof(uint32_t)))
            {
                return TINYUC_OUT_OF_MEMORY;
            }
        }
        else
        {
            // Flush as UTF-8
            ret = tinyuc_encode_codepoints(&ctx->cp, ctx->cp_buf, ctx->len, errmsg);
        }
    }
    ctx->len = 0;
    return ret;
}

static inline bool is_hangul_syllable(uint32_t c)
{
    return (c >= 0xAC00 && c <= 0xD7A3); // was 0xD7AF
}
static inline bool is_leading_jamo(uint32_t c)
{
    return (c >= 0x1100 && c <= 0x1112);
}
static inline bool is_vowel_jamo(uint32_t c)
{
    return (c >= 0x1161 && c <= 0x1175);
}
static inline bool is_trailing_jamo(uint32_t c)
{
    return (c >= 0x11A8 && c <= 0x11C2);
}

static enum tinyuc_result norm_decompose_hangul(norm_ctx_t* ctx, uint32_t syllable, char** errmsg)
{
    assert(is_hangul_syllable(syllable));

    const uint32_t S = syllable - 0xAC00;
    const uint32_t T_idx1 = S % 28;
    const uint32_t V_idx0 = ((S - T_idx1) % 588) / 28; // was = (S / 28) % 21;
    const uint32_t L_idx0 = S / 588;                   // was = S / (28 * 21);

    enum tinyuc_result ret = TINYUC_OK;
    ret = norm_ctx_add(ctx, 0x1100 + L_idx0, 0, errmsg);
    if (ret != TINYUC_OK)
        return ret;

    ret = norm_ctx_add(ctx, 0x1161 + V_idx0, 0, errmsg);
    if (ret != TINYUC_OK)
        return ret;

    if (T_idx1 != 0)
    {
        ret = norm_ctx_add(ctx, 0x11A7 + T_idx1, 0, errmsg);
    }
    return ret;
}

static inline uint32_t compose_hangul(uint32_t L, uint32_t V, uint32_t T)
{
    const uint32_t L_idx0 = L - 0x1100;
    const uint32_t V_idx0 = V - 0x1161;
    const uint32_t T_idx1 = (T != 0) ? T - 0x11A7 : 0; // Note: SUBTRACT 0x11A8 - 1
    return 0xAC00 + (L_idx0 * 21 + V_idx0) * 28 + T_idx1;
}

static enum tinyuc_result norm_decompose_cp(norm_ctx_t* ctx,
                                            uint32_t cp,
                                            bool must_decomp,
                                            char** errmsg)
{
    enum tinyuc_result ret = TINYUC_OK;
    uint8_t ccc = 0;
    const tinyucd_prop* prop = tinyuc_get_prop(cp);
    const tinyucd_decomp* decomp = NULL;
    if (prop)
    {
        ccc = prop->ccc;
        if (must_decomp)
            decomp = tinyuc_get_decomp(prop);
    }
#ifdef TINYUCD_WITH_VERIF
    assert(!decomp || cp == decomp->cp);
#endif
    if (!decomp || !(decomp->type == TINYUCD_DC_CANON || ctx->flags & UC_FLAGS_COMPAT))
    {
        if (ccc == 0 && (ret = norm_ctx_flush(ctx, errmsg)) != TINYUC_OK)
            return ret;
        // No decomposition or wrong type: append as-is
        return norm_ctx_add(ctx, cp, ccc, errmsg);
    }

    // Recursively decompose each codepoint
    for (size_t i = 0; i < decomp->len; i++)
    {
        uint32_t next_cp = (decomp->len <= 2) ? decomp->vals[i] : decomp->ptr[i];
        if ((ret = norm_decompose_cp(ctx, next_cp, must_decomp, errmsg)) != TINYUC_OK)
            return ret;
    }
    return ret;
}

static uint32_t norm_compose_cp(uint32_t starter,
                                uint32_t combiner,
                                const tinyucd_combiners* combiners)
{
    if (!combiners)
        return 0;
#ifdef TINYUCD_WITH_VERIF
    TINYUC_UNUSED(starter);
    assert(starter == combiners->starter);
#endif
    const tinyucd_combiner_entry* entries = combiners->entries;

    // Binary search for the combiner
    size_t left = 0;
    size_t right = combiners->len;
    while (left < right)
    {
        size_t mid = (left + right) / 2;
        if (entries[mid].combiner < combiner)
            left = mid + 1;
        else if (entries[mid].combiner > combiner)
            right = mid;
        else
        {
            assert(entries[mid].combiner == combiner);
            return entries[mid].composed; // Found
        }
    }
    return 0; // Not found
}

static size_t norm_compose(uint32_t* cps, size_t count)
{
    if (count < 2)
        return count; // Nothing to compose

    const tinyucd_prop* prop;
    const tinyucd_prop* prev_prop;
    const tinyucd_combiners* combiners = NULL;
    // size_t last_starter_idx             = 0; // Only valid if combiners != NULL
    for (size_t i = 1; i < count; i++)
    {
        if (is_leading_jamo(cps[i - 1]) && is_vowel_jamo(cps[i]))
        {
            uint32_t T = (i + 1 < count) ? cps[i + 1] : 0;
            if (!is_trailing_jamo(T))
                T = 0;

            cps[i - 1] = compose_hangul(cps[i - 1], cps[i], T);
            // Remove 1 or 2 codepoints and shift the rest
            size_t shift = (T != 0) ? 2 : 1;
            memmove(&cps[i], &cps[i + shift], (count - i - shift) * sizeof(uint32_t));
            count -= shift;
            i--; // recheck same index
            continue;
        }

        // Seek back left to find last starting character
        // int due to possible overflow
        prop = tinyuc_get_prop(cps[i]);
        for (int j = (int)i - 1; j >= 0; j--)
        {
            prev_prop = tinyuc_get_prop(cps[j]);
            combiners = prev_prop ? tinyuc_get_combiners(prev_prop) : NULL;
            uint32_t composed = 0;
            if (combiners)
                composed = norm_compose_cp(cps[j], cps[i], combiners);
            if (composed != 0)
            {
                cps[j] = composed;
                // Remove current combiner and shift the rest
                memmove(&cps[i], &cps[i + 1], (count - i - 1) * sizeof(uint32_t));
                count--;
                i--; // recheck same index
                break;
            }

            // If we can't compose with current j, we must check
            // That it doesn't block the composition chain
            uint8_t ccc_i = prop ? prop->ccc : 0;
            uint8_t ccc_j = prev_prop ? prev_prop->ccc : 0;
            if (ccc_j == 0 || ccc_j >= ccc_i)
                break;
        }
    }
    return count;
}

static enum tinyuc_result normalize(norm_ctx_t* ctx,
                                    const char* str,
                                    size_t size,
                                    bool must_decomp,
                                    char** errmsg)
{
    enum tinyuc_result ret = TINYUC_OK;
    uint32_t cp;

    FOR_EACH_CODEPOINT(cp, str, size)
    {
        if (is_hangul_syllable(cp))
        {
            if ((ret = norm_decompose_hangul(ctx, cp, errmsg)) != TINYUC_OK)
                return ret;
            if ((ret = norm_ctx_flush(ctx, errmsg)) != TINYUC_OK)
                return ret;
        }
        else
        {
            if ((ret = norm_decompose_cp(ctx, cp, must_decomp, errmsg)) != TINYUC_OK)
                return ret;

            // Only flush if last is a starter
            if (ctx->len > 0 && ctx->ccc_buf[ctx->len - 1] == 0)
            {
                if ((ret = norm_ctx_flush(ctx, errmsg)) != TINYUC_OK)
                    return ret;
            }
        }
    }
    if ((ret = norm_ctx_flush(ctx, errmsg)) != TINYUC_OK)
        return ret;

    if (ctx->flags & UC_FLAGS_COMPOSE)
    {
        uint32_t* cps = (uint32_t*)ctx->cp.data;
        size_t count = ctx->cp.size / sizeof(uint32_t);

        count = norm_compose(cps, count);

        tinyuc_buffer_clear(&ctx->cp);
        if ((ret = tinyuc_encode_codepoints(&ctx->cp, cps, count, errmsg)) != TINYUC_OK)
            return ret;
    }

    return tinyuc_buffer_push(&ctx->cp, "\0", 1) ? TINYUC_OK : TINYUC_OUT_OF_MEMORY;
}

/**
 * @brief Quick check whether a string is already in the requested normalization form.
 *
 * The result is conservative: it only returns true when the string is guaranteed to be
 * in the requested form. A false result means full normalization is required.
 *
 * This mirrors the Unicode quick check
 * (https://unicode.org/reports/tr15/#Detecting_Normalization_Forms) using data we already carry in
 * the property table:
 *   - NFD:  no canonical decomposition and no Hangul syllable.
 *   - NFKD: no decomposition at all and no Hangul syllable.
 *   - NFC:  no composition exclusion (NFC_QC=No) and no code point that can compose
 *           with a preceding starter (NFC_QC=Maybe).
 *   - NFKC: no code point that is not in NFKC form (NFKC_QC=No) and no code point that
 *           can compose with a preceding starter (NFKC_QC=Maybe).
 * Canonical ordering is verified for all forms.
 */
static bool tinyuc_is_normalized(const char* str, size_t size, enum tinyuc_norm_form form)
{
    const bool decomp = (form == TINYUC_NORM_NFD || form == TINYUC_NORM_NFKD);
    const bool compat = (form == TINYUC_NORM_NFKD || form == TINYUC_NORM_NFKC);

    uint8_t last_ccc = 0;
    uint32_t cp;

    FOR_EACH_CODEPOINT(cp, str, size)
    {
        if (is_hangul_syllable(cp))
        {
            // Hangul syllables are already composed (NFC/NFKC) but always decompose.
            if (decomp)
                return false;
            last_ccc = 0; // Starter
            continue;
        }

        const tinyucd_prop* prop = tinyuc_get_prop(cp);
        if (!prop)
            return false;

        if (decomp)
        {
            if (prop->decomp_idx)
            {
                if (compat)
                    return false;
                const tinyucd_decomp* d = tinyuc_get_decomp(prop);
                if (d && d->type == TINYUCD_DC_CANON)
                    return false;
            }
        }
        else
        {
            // NFC/NFKC quick check: reject NFC_QC/NFKC_QC = No and Maybe.
            uint8_t reject = compat ? TINYUCD_PROP_NFKCNO : TINYUCD_PROP_COMPEXCL;
            if (prop->flags & (reject | TINYUCD_PROP_COMPMAYBE))
                return false;
            // Hangul vowel/trailing jamo compose algorithmically
            if (is_vowel_jamo(cp) || is_trailing_jamo(cp))
                return false;
        }

        // Canonical ordering: combining classes must be non-decreasing.
        uint8_t ccc = prop->ccc;
        if (ccc != 0 && ccc < last_ccc)
            return false;
        last_ccc = ccc;
    }
    FOR_EACH_CODEPOINT_CHECK_RET(false);

    return true;
}

static enum tinyuc_result normalize_common(const char* str,
                                           size_t len,
                                           enum tinyuc_norm_form form,
                                           char** ostr,
                                           size_t* olen,
                                           char** errmsg,
                                           bool quick)
{
    norm_ctx_t ctx = {0};
    enum tinyuc_result ret = TINYUC_OK;

    switch (form)
    {
    case TINYUC_NORM_NFD:
        break;
    case TINYUC_NORM_NFKD:
        ctx.flags |= UC_FLAGS_COMPAT;
        break;
    case TINYUC_NORM_NFC:
        ctx.flags |= UC_FLAGS_COMPOSE;
        break;
    case TINYUC_NORM_NFKC:
        ctx.flags |= UC_FLAGS_COMPAT | UC_FLAGS_COMPOSE;
        break;
    case TINYUC_NORM_INVALID:
    default:
        tinyuc_error("Invalid normalization operation");
        return TINYUC_INTERNAL_ERROR;
    }

    if (!str)
    {
        if (errmsg)
            *errmsg = strdup("Invalid input string");
        return TINYUC_INVALID_ARGS;
    }
    if (!*str)
    {
        if (errmsg)
            *errmsg = strdup("Invalid output string pointer");
        return TINYUC_INVALID_ARGS;
    }

    if (len == TINYUC_NPOS)
        len = strlen(str);

    // Quick path: the string is already in the requested form, just copy it.
    if (quick && tinyuc_is_normalized(str, len, form))
    {
        char* data = (char*)malloc((len + 1) * sizeof(char));
        if (!data)
            return TINYUC_OUT_OF_MEMORY;
        memcpy(data, str, len);
        data[len] = '\0';
        *ostr = data;
        if (olen)
            *olen = len;
        return ret;
    }

    // Find out how many codepoints we deal with for the worst case allocation
    size_t numcp = tinyuc_num_cp(str, len);

    // Allocate for the worst case decomposition of the input
    if (!tinyuc_buffer_init(&ctx.cp, 4 * numcp * sizeof(uint32_t) + 1))
    {
        return TINYUC_OUT_OF_MEMORY;
    }
    norm_ctx_init(&ctx);

    if ((ret = normalize(&ctx, str, len, true, errmsg)) != TINYUC_OK)
    {
        norm_ctx_destroy(&ctx);
        tinyuc_buffer_release(&ctx.cp);
        return ret;
    }

    norm_ctx_destroy(&ctx);
    tinyuc_buffer_fit(&ctx.cp);
    tinyuc_buffer_transfer(&ctx.cp, ostr, olen, NULL);
    tinyuc_buffer_release(&ctx.cp);
    if (olen)
        *olen -= 1; // Do not count null-terminator
    return ret;
}

enum tinyuc_result tinyuc_normalize(const char* str,
                                    size_t len,
                                    enum tinyuc_norm_form form,
                                    char** ostr,
                                    size_t* olen,
                                    char** errmsg)
{
    return normalize_common(str, len, form, ostr, olen, errmsg, true);
}

enum tinyuc_result tinyuc_normalize_full(const char* str,
                                         size_t len,
                                         enum tinyuc_norm_form form,
                                         char** ostr,
                                         size_t* olen,
                                         char** errmsg)
{
    return normalize_common(str, len, form, ostr, olen, errmsg, false);
}

// Streaming case-folding iterator used for case-insensitive comparison. A
// single input codepoint can fold into several codepoints, so the folded
// overflow is buffered until it has been consumed.
typedef struct tinyuc_fold_iter
{
    const unsigned char* pos;
    const unsigned char* end;
    casemap_ctx_t ctx;
    uint32_t pending[TINYUCD_MAX_MULTI_LEN];
    size_t pending_pos;
    size_t pending_len;
} tinyuc_fold_iter;

static void tinyuc_fold_iter_init(tinyuc_fold_iter* iter, const char* str, size_t len)
{
    iter->pos = (const unsigned char*)str;
    iter->end = iter->pos + len;
    iter->ctx.last_cp = TINYUCD_NO_VALUE;
    iter->ctx.last_prop = NULL;
    iter->ctx.op = TINYUCD_CASE_FOLD;
    iter->pending_pos = 0;
    iter->pending_len = 0;
}

// Get the next folded codepoint. Returns false when the input is exhausted, or
// on error (which is reported).
static bool tinyuc_fold_iter_next(tinyuc_fold_iter* iter, uint32_t* out)
{
    if (iter->pending_pos < iter->pending_len)
    {
        *out = iter->pending[iter->pending_pos++];
        return true;
    }
    if (iter->pos >= iter->end)
        return false;

    iter->ctx.buf[0] = tinyuc_next_valid(&iter->pos);

    if (tinyuc_case_map_cp(&iter->ctx, NULL) != TINYUC_OK)
        return false;

    assert(iter->ctx.out_len > 0 && iter->ctx.out_len <= TINYUCD_MAX_MULTI_LEN);
    iter->pending_len = iter->ctx.out_len;
    for (size_t i = 0; i < iter->pending_len; i++)
        iter->pending[i] = iter->ctx.buf[i];
    iter->pending_pos = 0;

    *out = iter->pending[iter->pending_pos++];
    return true;
}

int tinyuc_icomp(const char* str1, size_t len1, const char* str2, size_t len2)
{
    if ((!str1 && !str2) || str1 == str2)
    {
        return 0;
    }
    else if (!str1)
    {
        return -1;
    }
    else if (!str2)
    {
        return 1;
    }

    tinyuc_fold_iter iter1;
    tinyuc_fold_iter iter2;
    tinyuc_fold_iter_init(&iter1, str1, len1);
    tinyuc_fold_iter_init(&iter2, str2, len2);

    for (;;)
    {
        uint32_t c1 = 0;
        uint32_t c2 = 0;
        bool has1 = tinyuc_fold_iter_next(&iter1, &c1);
        bool has2 = tinyuc_fold_iter_next(&iter2, &c2);

        if (!has1 && !has2)
            return 0;
        if (!has1)
            return -1;
        if (!has2)
            return 1;

        if (c1 != c2)
            return TINYUC_COMP(c1, c2);
    }
}
