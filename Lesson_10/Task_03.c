#include <stdio.h>
#include <stdlib.h>

void *genArray(void (*init_elem)(void*), size_t elem_c, size_t elem_size) {
    void* ptr = (void *)malloc(elem_c * elem_size);
    for (size_t i = 0; i < elem_c; i++) {
        init_elem(ptr + i * elem_size);
    }
    return ptr;
}

void init_int(void* int_adr) {
    *((int*)int_adr) = 23;
    // return int_adr;
}

int main() {

    int *arr = genArray(init_int, 7, sizeof(int));
    for (size_t i = 0; i < 7; i++) {
        printf("%d\n", *((int*)arr + i));
    }
    free(arr);

    return 0;
}