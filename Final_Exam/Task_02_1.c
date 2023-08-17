#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        perror(" ");
        exit(-1);
    }

    char *filename = argv[1];
    uint64_t N = strtoull(argv[2], NULL, 10);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("File opening failed");
        return 2;
    }

    srand(time(NULL)); 

    for (uint64_t i = 0; i < N; i++) {
        uint64_t number = rand() % 1000000; 
        fwrite(&number, sizeof(uint64_t), 1, file);
    }

    fclose(file);

    printf("%lu numbers writed%s\n", N, filename);

    return 0;
}
