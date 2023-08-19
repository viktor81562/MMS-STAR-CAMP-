#include <stdio.h>

//Създайте функция, която намира максималния елемент в масив:


void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)) {
    char* array = (char*)arr;
    void* max = arr;
    for (size_t i = 0; i < n; i++)
    {
        if (cmp(array + i * elem_s, max) == -1) {
            max = array + i * elem_s;
        }
    }

    return max;
}

int compare(const void* a, const void* b) {
    return *(const int*)a > *(const int*)b ? -1 : (*(const int*)a < *(const int*)b ? 1 : 0);
}



int main(int argvc, char* argv[]) {

    char arr[] = {"viktor"};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    size_t elem_s = sizeof(char);

    int* max = (int*)findMax(arr, size, elem_s, compare);

    printf("%c", *max);
    

    return 0;
}