#include <stdio.h>
#include <stdlib.h>

void displayHex(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    int byte;
    while ((byte = fgetc(file)) != EOF) {
        printf("%02x ", byte);
    }

    fclose(file);
    printf("\n");
}

void displayText(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    int byte;
    while ((byte = fgetc(file)) != EOF) {
        putchar(byte);
    }

    fclose(file);
    printf("\n");
}

void appendByte(const char* filename, unsigned char new_byte) {
    FILE* file = fopen(filename, "ab");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fputc(new_byte, file);

    fclose(file);
}

void cutBytes(const char* filename, size_t start_index, size_t end_index) {
    FILE* file = fopen(filename, "r+b");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fseek(file, start_index, SEEK_SET);
    size_t bytes_to_cut = end_index - start_index + 1;

    while (bytes_to_cut > 0) {
        fputc(0, file); 
        bytes_to_cut--;
    }

    fclose(file);
}

void editByte(const char* filename, size_t index, unsigned char new_byte) {
    FILE* file = fopen(filename, "r+b");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fseek(file, index, SEEK_SET);
    fputc(new_byte, file);

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    char command;
    size_t start_index, end_index, index;
    unsigned char new_byte;

    while (1) {
        scanf("%c", &command);

        switch (command) {
            case 'd':
                displayHex(filename);
                break;
            case 't':
                displayText(filename);
                break;
            case 'a':
                scanf("%hhx", &new_byte);
                appendByte(filename, new_byte);
                break;
            case 'c':
                scanf("%lu %lu", &start_index, &end_index);
                cutBytes(filename, start_index, end_index);
                break;
            case 'e':
                scanf("%lu %hhx", &index, &new_byte);
                editByte(filename, index, new_byte);
                break;
            case '\n': 
                break;
            case EOF:
                printf("Program terminated.\n");
                return 0;
            default:
                printf("Invalid command: %c\n", command);
                break;
        }
    }

    return 0;
}
