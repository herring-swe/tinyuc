/**
 * @file unicode.h
 *
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Unicode support
 *
 * Operates on UTF-8 strings, unless specifically documented.
 */

#ifndef TINYUC_UNICODE_H
#define TINYUC_UNICODE_H

#include <tinyuc/diag.h>
#include <tinyuc/enum.h>
#include <tinyuc/export.h>

#include <stddef.h>
#include <stdint.h>

#define TINYUC_NOCP 0xFFFF
#define TINYUC_NPOS (SIZE_MAX - 1)

/**
 * @brief Decode the next codepoint and advance a UTF-8 iterator.
 *
 * Reads the codepoint starting at @p *iter, advances @p *iter past it and
 * returns the codepoint.
 *
 * @warning No validation is performed. The memory must contain a complete,
 * valid UTF-8 codepoint. A null byte is decoded as U+0000, which is
 * indistinguishable from the end of a null-terminated string; use an explicit
 * length when iterating strings that may contain embedded null characters.
 *
 * @param iter in/out pointer to the current position
 * @return the decoded codepoint
 */
TINYUC_API uint32_t tinyuc_iter_utf8(const unsigned char** iter);

/**
 * @brief Encode a single codepoint as UTF-8
 *
 * The codepoint must be a valid Unicode code point (0 to 0x10FFFF, excluding surrogate pairs).
 *
 * @param dst destination buffer, must have space for at least 4 bytes. If NULL, the function
 * will return the number of bytes needed to encode the codepoint.
 * @param cp codepoint to encode
 * @return number of bytes written or needed
 * @return -1 if codepoint is invalid (outside the Unicode range or a surrogate)
 */
TINYUC_API int tinyuc_encode_codepoint(uint8_t* dst, const uint32_t cp);

// /**
//  * @brief Encode an array of codepoints as UTF-8 and append them to a buffer.
//  *
//  * The codepoints are appended to any existing content of @p buf. The buffer is
//  * grown as needed. Encoding is all-or-nothing: if any codepoint is invalid the
//  * function returns false and the buffer content is left unspecified.
//  *
//  * @param buf destination buffer
//  * @param codepoints array of codepoints to encode
//  * @param len number of codepoints
//  * @param perr optional pointer that may be set on error
//  * @return true on success
//  * @return false on invalid codepoint or allocation failure
//  */
// TINYUC_API bool tinyuc_encode_codepoints(tinyuc_buffer* buf,
//                                       const uint32_t* codepoints,
//                                       size_t len,
//                                       tinyuc_error** perr);

/**
 * @brief Encode an array of codepoints as UTF-8 into a buffer.
 *
 * The function will encode as many codepoints as possible into the buffer.
 *
 * If @p buf is NULL, the function will
 * set @p blen to the number of bytes needed to fit all of the encoded codepoints.
 *
 * If @p buf is set, the function will write as many codepoints that fits,
 * set @p blen to the number of bytes written. Use @p o_npcp to determine how many
 * codepoints that were processed.
 *
 * If @p blen is too small to fit a single codepoint, the function will return
 * TINYUC_BUFFER_TOO_SMALL.
 *
 * If a codepoint is invalid, in any mode, the function will stop and return early with
 * TINYUC_INVALID_CODEPOINT. @p o_npcp will be set to the number of processed codepoints
 * before the invalid codepoint.
 *
 * @param cp array of codepoints to encode
 * @param cplen number of codepoints
 * @param buf destination buffer
 * @param blen size of the buffer
 * @param o_len out pointer to the number of bytes required/written.
 * @param o_npcp out pointer to the number of processed codepoints.
 * @param errmsg optional pointer that may be set on error
 * @return TINYUC_OK on success
 * @return TINYUC_INVALID_ARGS if either cp or o_len is NULL
 * @return TINYUC_INVALID_CODEPOINT if any codepoint is invalid
 * @return TINYUC_BUFFER_TOO_SMALL if @p blen is less than 4.
 */
TINYUC_API enum tinyuc_result tinyuc_encode_codepoints_buf(const uint32_t* cp,
                                                           size_t cplen,
                                                           char* buf,
                                                           size_t blen,
                                                           size_t* o_len,
                                                           size_t* o_npcp,
                                                           char** errmsg);

/**
 * @brief Validate a string as UTF-8
 *
 * If @p len is specified, the string may contain multiple null characters.
 * If @p len is TINYUC_NPOS, the string must only be null-terminated.
 * @param str null-terminated string to validate
 * @param len length of string or TINYUC_NPOS
 * @param perr optional pointer that may be set on error
 * @return true if the string is valid UTF-8
 * @return false otherwise, with TINYUC_ERROR_INVALID_UTF8 set through @p perr
 */
TINYUC_API enum tinyuc_result tinyuc_validate(const char* str, size_t len, char** errmsg);

/**
 * @brief Count the number of codepoints in a UTF-8 string.
 *
 * The string must already have been validated as UTF-8.
 * If @p len is specified, the string may contain multiple null characters.
 * If @p len is TINYUC_NPOS, the string must only be null-terminated.
 * @param str the string
 * @param len length of string or TINYUC_NPOS
 * @return number of codepoints in string or TINYUC_NPOS if the string is not valid UTF-8.
 */
TINYUC_API size_t tinyuc_num_cp(const char* str, size_t len);

/**
 * @brief Count the number of printable characters in a UTF-8 string.
 *
 * Counts extended grapheme clusters as defined by UAX #29. This is the number
 * of user-perceived characters, and is not the same as the number of
 * codepoints (see @ref tinyuc_num_cp).
 *
 * The string must already have been validated as UTF-8.
 *
 * If @p len is specified, the string may contain multiple null characters.
 * If @p len is TINYUC_NPOS, the string must only be null-terminated.
 *
 * @param str the string
 * @param len length of string or TINYUC_NPOS
 * @return number of printable characters in string
 */
TINYUC_API size_t tinyuc_num_char(const char* str, size_t len);

/**
 * @brief Get the byte offset just past the @p index-th printable character.
 *
 * Characters are extended grapheme clusters (UAX #29). The returned offset is a
 * valid boundary that can be passed to @ref tinyuc_next_char().
 *
 * @param str valid UTF-8 string
 * @param len length of string
 * @param index 1-based character index
 * @return byte offset after the @p index-th character, or @p len if there is no
 * such character (including @p index equal to 0, which is not a valid
 * 1-based index)
 */
TINYUC_API size_t tinyuc_char_index(const char* str, size_t len, size_t index);

/**
 * @brief Get the next character position
 *
 * Characters are extended grapheme clusters (UAX #29).
 *
 * Calls with @p from_byte >= string length (including TINYUC_NPOS) will return TINYUC_NPOS.
 *
 * This function is only valid if called with
 * @p from_byte being one of:
 *   - 0 (start of string)
 *   - a value returned from previous call
 *   - value from @ref tinyuc_char_index()
 *
 * The string must not be modified between calls.
 * @param str valid UTF-8 string
 * @param len length of string (must be specified)
 * @param from_byte byte offset to start from
 * @return byte offset to next character or TINYUC_NPOS if at end of string
 */
TINYUC_API size_t tinyuc_next_char(const char* str, size_t len, size_t from_byte);

/**
 * @brief Map a UTF-8 string to upper case.
 *
 * The string must already have been validated as UTF-8. The mapping uses the
 * Unicode full case mapping tables and may change the number of codepoints
 * (for example "ß" maps to "SS").
 *
 * @param str valid UTF-8 string
 * @param size length of string in bytes; the string may contain embedded nulls
 * @param perr optional pointer that may be set on error
 * @return result; on success @ref tinyuc_result::data is allocated with
 * @ref tinyuc_malloc and must be freed by the caller
 */
TINYUC_API enum tinyuc_result tinyuc_to_upper(const char* str,
                                              size_t size,
                                              char** ostr,
                                              size_t* osize,
                                              char** errmsg);

/**
 * @brief Map a UTF-8 string to lower case.
 * @see tinyuc_to_upper()
 * @param str valid UTF-8 string
 * @param size length of string in bytes; the string may contain embedded nulls
 * @param perr optional pointer that may be set on error
 * @return result; on success @ref tinyuc_result::data must be freed by the caller
 */
TINYUC_API enum tinyuc_result tinyuc_to_lower(const char* str,
                                              size_t size,
                                              char** ostr,
                                              size_t* osize,
                                              char** errmsg);

/**
 * @brief Map a UTF-8 string to title case.
 *
 * Each word starts with a titlecase mapping and continues in lower case. Word
 * boundaries are separators and punctuation; an apostrophe is not a separator.
 *
 * @see tinyuc_to_upper()
 * @param str valid UTF-8 string
 * @param size length of string in bytes; the string may contain embedded nulls
 * @param perr optional pointer that may be set on error
 * @return result; on success @ref tinyuc_result::data must be freed by the caller
 */
TINYUC_API enum tinyuc_result tinyuc_to_title(const char* str,
                                              size_t size,
                                              char** ostr,
                                              size_t* osize,
                                              char** errmsg);

/**
 * @brief Case fold a UTF-8 string.
 *
 * Uses full case folding (Unicode C+F). The result is intended for
 * case-insensitive comparison, not for display.
 *
 * @see tinyuc_to_upper()
 * @param str valid UTF-8 string
 * @param size length of string in bytes; the string may contain embedded nulls
 * @param perr optional pointer that may be set on error
 * @return result; on success @ref tinyuc_result::data must be freed by the caller
 */
TINYUC_API enum tinyuc_result tinyuc_casefold(const char* str,
                                              size_t size,
                                              char** ostr,
                                              size_t* olen,
                                              char** errmsg);

/**
 * @brief Normalize an UTF-8 string
 *
 * The string must already have been validated as UTF-8.
 *
 * If @p len is specified, the string may contain multiple null characters.
 * If @p len is TINYUC_NPOS, the string must only be null-terminated.
 * @param str string to normalize, must be a valid utf-8 string
 * @param len length of string or TINYUC_NPOS
 * @param form the normalization form to use
 * @param perr optional pointer that will be set on normalization error
 * @returns result, with the normalized string on success
 */
TINYUC_API enum tinyuc_result tinyuc_normalize(const char* str,
                                               size_t len,
                                               enum tinyuc_norm_form form,
                                               char** ostr,
                                               size_t* olen,
                                               char** errmsg);

/**
 * @brief Normalize an UTF-8 string, skipping the quick check fast path.
 *
 * Internal/benchmark-only variant of tinyuc_normalize() that always runs the
 * full decomposition/composition algorithm. Used to measure the quick path.
 * Not part of the public, installed API.
 */
TINYUC_API enum tinyuc_result tinyuc_normalize_full(const char* str,
                                                    size_t len,
                                                    enum tinyuc_norm_form form,
                                                    char** ostr,
                                                    size_t* olen,
                                                    char** errmsg);

/**
 * @brief Case-insensitive comparison of two UTF-8 strings.
 *
 * Both strings are compared using full case folding, so the comparison is
 * independent of case. The strings should be in the same normalization form
 * for meaningful results.
 *
 * @param str1 first UTF-8 string
 * @param len1 length of @p str1 in bytes
 * @param str2 second UTF-8 string
 * @param len2 length of @p str2 in bytes
 * @return 0 if equal, a negative value if @p str1 sorts before @p str2 and a
 * positive value otherwise
 */
TINYUC_API int tinyuc_icomp(const char* str1, size_t len1, const char* str2, size_t len2);

#endif // TINYUC_UNICODE_H
