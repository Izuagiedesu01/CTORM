#ifndef SBUF_H
#define SBUF_H

#include <stddef.h> // Required for size_t

// Structure representing a dynamic string buffer
typedef struct {
    char *data;      // Pointer to heap-allocated memory holding characters
    size_t capacity; // Total allocated buffer memory size in bytes
    size_t length;   // Current length of string (excluding null terminator)
} DynamicBuffer;

// Function Prototypes
DynamicBuffer* sbuf_create(size_t initial_capacity);
int sbuf_append(DynamicBuffer *buf, const char *str);
void sbuf_clear(DynamicBuffer *buf);
void sbuf_free(DynamicBuffer *buf);

#endif // SBUF_H