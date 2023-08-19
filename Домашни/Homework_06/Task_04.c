#include <stdio.h>
#include <math.h>

#define EVEN 1
#define SQUARE 2
#define BIT_COUNT 3

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count = count + (num & 1);
        num = num >> 1;
    }
    return count;
}

int filter(int num) {
    if (num % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int square(int num) {
    for (size_t i = 2; i <= sqrt(num); i++) {
        if (num % i == 0 && num != i) {
            return 0;
        }
    }
    return num * num;
}

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int dest[], size_t* dest_cnt, int func) {
    *dest_cnt = 0;

    if (func == EVEN) {
        for (int i = 0; i < n; i++) {
            int flag = filter_f(arr[i]);
            if (flag == 1) {
                dest[*dest_cnt] = arr[i];
                (*dest_cnt)++;
            }
        }

        printf("Size of new array is: %zu\n", *dest_cnt);
        printf("Values in new dest array: ");

        for (size_t i = 0; i < *dest_cnt; i++) {
            printf("%d ", dest[i]);
        }
        printf("\n");
    } else if (func == SQUARE) {
        for (int i = 0; i < n; i++) {
            int flag = square(arr[i]);
            if (flag > 0) {
                dest[*dest_cnt] = flag;
                (*dest_cnt)++;
            }
        }

        printf("Size of new array is: %zu\n", *dest_cnt);
        printf("Values in new dest array: ");

        for (size_t i = 0; i < *dest_cnt; i++) {
            printf("%d ", dest[i]);
        }
        printf("\n");
    } else if (func == BIT_COUNT) {
        for (int i = 0; i < n; i++) {
            int flag = arr[i];
            if (flag > 0) {
                flag = 1;
            } else {
                flag = 0;
            }
            if (flag == 1) {
                dest[*dest_cnt] = arr[i];
                (*dest_cnt)++;
            }
        }

        int bitsCount = 0;

        for (size_t i = 0; i < *dest_cnt; i++) {
            bitsCount = bitsCount + countSetBits(dest[i]);
        }

        printf("Size of new array is: %zu\n", *dest_cnt);
        printf("Values in new dest array: ");

        for (size_t i = 0; i < *dest_cnt; i++) {
            printf("%d ", dest[i]);
        }
        printf("\nAll bits that are 1 in this array are: %d\n", bitsCount);
    }
}

int main(int argc, char* argv[]) {
    int arr[8] = {1, 2, 3, 4, -1, -2, 11, -100};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    int dest[10];
    size_t dest_cnt;

    filter_and_map(arr, size, filter, dest, &dest_cnt, EVEN);

    return 0;
}
