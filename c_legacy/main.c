#include <stdio.h>
#include "sbuf.h"

int main(void) {
    printf("=== CTORM C Dynamic Buffer Test ===\n\n");

    // 1. Create a buffer with an intentionally small capacity (8 bytes)
    DynamicBuffer *buf = sbuf_create(8);
    if (buf == NULL) {
        fprintf(stderr, "Failed to allocate buffer!\n");
        return 1;
    }

    printf("Initial Buffer -> Length: %zu, Capacity: %zu\n", buf->length, buf->capacity);

    // 2. Append first string (fits in initial 8 bytes)
    sbuf_append(buf, "Hello");
    printf("After 'Hello'  -> Length: %zu, Capacity: %zu, Data: \"%s\"\n", 
            buf->length, buf->capacity, buf->data);

    // 3. Append second string (forces realloc to grow capacity)
    sbuf_append(buf, ", World! CTORM C Library Test.");
    printf("After Append   -> Length: %zu, Capacity: %zu, Data: \"%s\"\n", 
            buf->length, buf->capacity, buf->data);

    // 4. Test resetting the buffer
    sbuf_clear(buf);
    printf("After Clear    -> Length: %zu, Capacity: %zu, Data: \"%s\"\n", 
            buf->length, buf->capacity, buf->data);

    // 5. Reuse cleared buffer
    sbuf_append(buf, "Reused Buffer!");
    printf("After Reuse    -> Length: %zu, Capacity: %zu, Data: \"%s\"\n\n", 
            buf->length, buf->capacity, buf->data);

    // 6. Free memory
    sbuf_free(buf);
    printf("Memory successfully freed.\n");

    return 0;
}