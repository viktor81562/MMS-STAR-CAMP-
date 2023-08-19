#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>

int main() {
    int n;

    scanf_s("%d", &n);

    double* ptr = (double*)malloc(sizeof(double) * n);

    srand(time(NULL));

    for (size_t i = 0; i < n; i++) {
        ptr[i] = (rand() % 100) / 100.0;
    }

    for (size_t i = 0; i < n; i++) {
        printf("%.2lf ", *(ptr + i));
    }
    printf("\n");

    int m;
    scanf_s("%d", &m);

    ptr = (double*)realloc(ptr, (m + n) * sizeof(double));

    for (size_t i = n; i < (m + n); i++) {
        ptr[i] = (rand() % 100 + 100) / 100.0;
    }
    for (size_t i = 0; i < (m + n); i++) {
        printf("%.2lf ", *(ptr + i));
    }
    printf("\n");

    int p;
    scanf_s("%d", &p);

    ptr = (double*)realloc(ptr, (m + n + p) * sizeof(double));

    for (size_t i = m + n; i < (m + n + p); i++) {
        ptr[i] = (rand() % 100 + 200) / 100.0;
    }

    for (size_t i = 0; i < (m + n + p); i++) {
        printf("%.2lf ", *(ptr + i));
    }

    free(ptr);

    return 0;
}
