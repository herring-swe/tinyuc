/**
 * @file helpers.c
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 */

#include "private/helpers.h"

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tinyuc_error(const char* msg)
{
    return fprintf(stderr, "TinyUC Error: %s\n", msg);
}

int tinyuc_stricomp(const char* a, const char* b)
{
    if (!a && !b)
        return 0;
    if (!a)
        return -1;
    if (!b)
        return 1;
#ifdef _WIN32
    return _stricmp(a, b);
#else
    return strcasecmp(a, b);
#endif
}

int tinyuc_vsnprintf(char* buffer, size_t count, const char* fmt, va_list vlist)
{
    assert(fmt);
    assert((buffer && count != 0) || (!buffer && count == 0));
    return vsnprintf(buffer, count, fmt, vlist);
}

int tinyuc_asprintf(char** restrict pstr, const char* restrict fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    int r = tinyuc_vasprintf(pstr, fmt, ap);
    va_end(ap);
    return r;
}

int tinyuc_vasprintf(char** restrict pstr, const char* restrict fmt, va_list vlist)
{
    if (!pstr)
        return -1;
    if (!fmt)
    {
        *pstr = NULL;
        return 0;
    }
    va_list args_copy;
    va_copy(args_copy, vlist);
    int len = tinyuc_vsnprintf(NULL, 0, fmt, args_copy);
    va_end(args_copy);
    if (len < 0)
        return -1;
    char* str = (char*)malloc((len + 1) * sizeof(char));
    if (!str)
        return -1;
    len = tinyuc_vsnprintf(str, (size_t)len + 1, fmt, vlist);
    if (len < 0)
    {
        free(str);
        return -1;
    }
    *pstr = str;
    return len;
}