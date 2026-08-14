#include <stdio.h>
#include <time.h>
#include "sbuf.h"

int main(void) {
    printf("=== C Legacy Benchmark (1,000,000 Appends) ===\n");

    DynamicBuffer *buf = sbuf_create(16);
    if (buf == NULL) {
        fprintf(stderr, "Allocation failed!\n");
        return 1;
    }

    clock_t start = clock();

    for (int i = 0; i < 1000000; i++) {
        sbuf_append(buf, "CTORM Benchmark String ");
    }

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time : %.4f seconds\n", cpu_time_used);
    printf("Final Capacity : %zu bytes\n", buf->capacity);
    printf("Final Length   : %zu bytes\n", buf->length);

    sbuf_free(buf);
    return 0;
}