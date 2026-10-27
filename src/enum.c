/**
 * @file unicode_enum.c
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief Unicode enum implementation
 */

#include <tinyuc/enum.h>

#include "private/helpers.h"

const char* tinyuc_norm_form_to_str(enum tinyuc_norm_form form)
{
    switch (form)
    {
    case TINYUC_NORM_NFC:
        return "NFC";
    case TINYUC_NORM_NFD:
        return "NFD";
    case TINYUC_NORM_NFKC:
        return "NFKC";
    case TINYUC_NORM_NFKD:
        return "NFKD";
    default:
        break;
    }
    return "";
}

enum tinyuc_norm_form tinyuc_norm_form_from_str(const char* str)
{
    if (tinyuc_stricomp(str, "NFC") == 0)
        return TINYUC_NORM_NFC;
    if (tinyuc_stricomp(str, "NFD") == 0)
        return TINYUC_NORM_NFD;
    if (tinyuc_stricomp(str, "NFKC") == 0)
        return TINYUC_NORM_NFKC;
    if (tinyuc_stricomp(str, "NFKD") == 0)
        return TINYUC_NORM_NFKD;
    return TINYUC_NORM_INVALID;
}
