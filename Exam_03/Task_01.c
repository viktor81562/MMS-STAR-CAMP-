#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_hex_dump(FILE *file) {
    int byte;
    int offset = 0;

    while ((byte = fgetc(file)) != EOF) {
        if (offset % 16 == 0) {
            if (offset > 0) {
                printf("\n");
            }
            printf("%08X:", offset);
        }
        printf(" %02X", byte);
        offset++;
    }

    printf("\n");
}

void print_binary(FILE *file) {
    int byte;
    int offset = 0;

    while ((byte = fgetc(file)) != EOF) {
        if (offset % 6 == 0) {
            if (offset > 0) {
                printf(" ");
            }
            printf("\n%08X:", offset);
        }
        
        for (int i = 7; i >= 0; i--) {
            printf(" %d", (byte >> i) & 1);
        }

        offset++;
    }

    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage problem with: %s", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("PROBLEM WITH OPENING THE FILE!");
        return 1;
    }

    for (int i = 0; i < 100; i++)
    {
        fprintf(file,"%d", i);
    }
    

    if (strcmp(argv[2], "-H") == 0) {
        print_hex_dump(file);
    } else if (strcmp(argv[2], "-B") == 0) {
        print_binary(file);
    } else {
        printf("Invalid print mode. Use -H for hex dump or -B for binary.\n");
        return 1;
    }

    fclose(file);

    return 0;
}
