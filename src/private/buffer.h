/**
 * @file buffer.h
 * This file is part of the TinyUC project
 * - SPDX-FileCopyrightText: © 2026 Åke Svedin <ake@svedin.org>
 * - SPDX-License-Identifier: MIT
 *
 * @brief
 */

#ifndef TINYUC_SRC_BUFFER_H
#define TINYUC_SRC_BUFFER_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* data;
    size_t size;
    size_t capacity;
} tinyuc_buffer;

static inline bool tinyuc_buffer_init(tinyuc_buffer* buf, size_t initial_capacity)
{
    assert(buf && initial_capacity);

    memset(buf, 0, sizeof(tinyuc_buffer));

    buf->data = (char*)calloc(1, initial_capacity);
    if (!buf->data)
        return false;

    buf->size = 0;
    buf->capacity = initial_capacity;
    return true;
}

static inline tinyuc_buffer* tinyyuc_buffer_new(size_t initial_capacity)
{
    tinyuc_buffer* buf = (tinyuc_buffer*)calloc(1, sizeof(tinyuc_buffer));
    if (!buf)
        return NULL;
    if (!tinyuc_buffer_init(buf, initial_capacity))
    {
        free(buf);
        buf = NULL;
    }
    return buf;
}

static inline bool tinyuc_buffer_resize(tinyuc_buffer* buf, size_t new_capacity)
{
    assert(buf);

    if (buf->capacity == new_capacity)
    {
        return true;
    }
    if (new_capacity == 0)
    {
        free(buf->data);
        buf->data = NULL;
        buf->capacity = 0;
        return true;
    }

    char* tmp = (char*)realloc(buf->data, new_capacity);
    if (!tmp)
        return false;

    buf->data = tmp;
    buf->capacity = new_capacity;
    if (buf->size > new_capacity)
        buf->size = new_capacity;
    return true;
}

bool tinyuc_buffer_grow(tinyuc_buffer* buf, size_t inc_capacity)
{
    assert(buf);

    size_t cap = buf->capacity;
    if (cap == 0)
        cap = 1;
    else if (cap <= SIZE_MAX / 2)
        cap *= 2;
    else
        cap = SIZE_MAX;

    while (inc_capacity > cap - buf->capacity)
    {
        if (cap > SIZE_MAX / 2)
            return false;
        cap *= 2;
    }

    if (cap < buf->capacity)
        cap = buf->capacity;
    return tinyuc_buffer_resize(buf, cap);
}

bool tinyuc_buffer_ensure(tinyuc_buffer* buf, size_t size)
{
    assert(buf);
    size_t spare = buf->capacity - buf->size;
    if (size <= spare)
        return true;
    return tinyuc_buffer_grow(buf, size - spare);
}

bool tinyuc_buffer_push(tinyuc_buffer* buf, const void* data, size_t size)
{
    assert(buf && data);
    if (size > 0)
    {
        size_t spare = buf->capacity - buf->size;
        if (size > spare)
        {
            if (!tinyuc_buffer_grow(buf, size - spare))
                return false;
        }

        memcpy(buf->data + buf->size, data, size);
        buf->size += size;
    }
    return true;
}

static inline bool tinyuc_buffer_fit(tinyuc_buffer* buf)
{
    assert(buf);
    if (buf->size == buf->capacity)
        return true;
    return tinyuc_buffer_resize(buf, buf->size);
}

static inline bool tinyuc_buffer_transfer(tinyuc_buffer* buf,
                                          char** out_data,
                                          size_t* out_size,
                                          size_t* out_capacity)
{
    assert(buf && out_data);

    *out_data = buf->data;
    if (out_size)
        *out_size = buf->size;
    if (out_capacity)
        *out_capacity = buf->capacity;
    memset(buf, 0, sizeof(tinyuc_buffer));
    return true;
}

static inline void tinyuc_buffer_release(tinyuc_buffer* buf)
{
    assert(buf);
    free(buf->data);
    buf->data = NULL;
    buf->size = 0;
    buf->capacity = 0;
}

static inline void tinyuc_buffer_free(tinyuc_buffer* buf)
{
    if (buf)
    {
        tinyuc_buffer_release(buf);
        free(buf);
    }
}

static inline void tinyuc_buffer_clear(tinyuc_buffer* buf)
{
    assert(buf);
    buf->size = 0;
}

#endif // TINYUC_SRC_BUFFER_H