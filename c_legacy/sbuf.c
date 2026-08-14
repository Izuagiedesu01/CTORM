#include "sbuf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DynamicBuffer* sbuf_create(size_t initial_capacity) {
    if (initial_capacity == 0) {
        initial_capacity = 16; // Default baseline size
    }

    // Step 1: Allocate memory on the heap for the struct itself
    DynamicBuffer *buf = (DynamicBuffer*) malloc(sizeof(DynamicBuffer));
    if (buf == NULL) {
        return NULL; // Heap allocation failed
    }

    // Step 2: Allocate memory on the heap for the char array inside
    buf->data = (char*) malloc(initial_capacity);
    if (buf->data == NULL) {
        free(buf); // Clean up the struct to prevent a memory leak
        return NULL;
    }

    buf->data[0] = '\0'; // Properly null-terminate the initial empty string
    buf->capacity = initial_capacity;
    buf->length = 0;

    return buf;
}

int sbuf_append(DynamicBuffer *buf, const char *str) {
    if (buf == NULL || str == NULL) {
        return -1; // Guard clause against null pointers
    }

    size_t str_len = strlen(str);
    size_t needed_capacity = buf->length + str_len + 1; // +1 for the null terminator '\0'

    // Step 3: Check if we need to grow the buffer
    if (needed_capacity > buf->capacity) {
        size_t new_capacity = buf->capacity * 2;
        if (new_capacity < needed_capacity) {
            new_capacity = needed_capacity;
        }

        // CRITICAL: Store in a temporary pointer first!
        char *new_data = (char*) realloc(buf->data, new_capacity);
        if (new_data == NULL) {
            return -1; // Reallocation failed, original memory remains intact
        }

        buf->data = new_data;
        buf->capacity = new_capacity;
    }

    // Step 4: Copy the new string to the end of existing data
    memcpy(buf->data + buf->length, str, str_len + 1);
    buf->length += str_len;

    return 0; // Success
}

void sbuf_clear(DynamicBuffer *buf) {
    if (buf != NULL && buf->data != NULL) {
        buf->length = 0;
        buf->data[0] = '\0'; // Logically reset without deallocating
    }
}

void sbuf_free(DynamicBuffer *buf) {
    if (buf == NULL) return;

    if (buf->data != NULL) {
        free(buf->data); // 1. Free internal memory first
        buf->data = NULL;
    }

    free(buf); // 2. Free the container struct second
}