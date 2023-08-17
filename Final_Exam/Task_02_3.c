#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>

int sum_digits(uint64_t number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

void *sum_thread(void *filename) {
    uint64_t local_sum = 0;
    FILE *file = fopen((char *)filename, "r");
    if (file == NULL) {
        perror((char *)filename);
        pthread_exit(NULL);
    }

    uint64_t number;
    while (fread(&number, sizeof(uint64_t), 1, file) == 1) {
        local_sum += sum_digits(number);
    }

    fclose(file);
    pthread_exit((void *)(uintptr_t)local_sum);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s file1 file2 ... fileN\n", argv[0]);
        return 1;
    }

    uint64_t total_sum = 0;
    pthread_t threads[argc - 1];

    for (int i = 1; i < argc; i++) {
        pthread_create(&threads[i - 1], NULL, sum_thread, (void *)argv[i]);
    }

    for (int i = 1; i < argc; i++) {
        void *thread_result;
        pthread_join(threads[i - 1], &thread_result);
        total_sum += (uint64_t)(uintptr_t)thread_result;
    }

    printf("Total sum of digits - %lu\n", total_sum);

    return 0;
}
