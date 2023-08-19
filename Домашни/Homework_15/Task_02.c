#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_strings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <arg1> <arg2> ... <argN>\n", argv[0]);
        return 1;
    }

    qsort(argv + 1, argc - 1, sizeof(char *), compare_strings);

    char outputFilename[100];
    printf("Enter the output filename: ");
    scanf("%s", outputFilename);

    FILE *outputFile = fopen(outputFilename, "r");
    if (outputFile != NULL) {
        printf("Error: File already exists.\n");
        fclose(outputFile);
        return 2;
    }

    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error: Could not create the file.\n");
        return 3;
    }

    for (int i = 1; i < argc; i++) {
        fprintf(outputFile, "%s\n", argv[i]);
    }

    fclose(outputFile);
    printf("Sorted and written to %s\n", outputFilename);

    return 0;
}
