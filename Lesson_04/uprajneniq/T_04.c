#include <stdio.h>

int* addOffset(int* ptr, int offset) {
    int* newPtr = ptr + offset;
    return newPtr;
}

int main() {
    int arr[] = {10,20,30,40,50};
    int* ptr = arr;

    printf("array: ");
    for(int i = 0; i<5  ; i++) {
        printf("%d ", *(ptr+i));
    }

    int offset = 2;
    int* newPtr = addOffset(ptr,offset);





    return 0;
}