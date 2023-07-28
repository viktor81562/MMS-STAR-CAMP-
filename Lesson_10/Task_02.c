#include <stdio.h>
#include<stdlib.h>

int* genRandom(size_t elem_c) {
    int *ptr = (int*) malloc(sizeof(int)* 100);
    srand(time(NULL));
    for(size_t i = 0; i < elem_c; i++) {
        ptr[i] = rand() % 200 - 100;
    }
    return ptr;
}

int main() {

    int a = 8;
    int *ptr = genRandom(a);
    for(size_t i = 0; i < a; i++) {
        printf("%d\n", ptr[i]);
    }
    free(ptr);
    return 0;
}