#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        char line[1000];
        while (fgets(line, sizeof(line), stdin)) {
            printf("%s", line);
        }
    } else {
        for (int i = 1; i < argc; i++) {
            FILE *file = fopen(argv[i], "r");
            if (file == NULL) {
                perror("Error opening file");
                continue;
            }
            
            char ch;
            while ((ch = fgetc(file)) != EOF) {
                printf("%c", ch);
            }
            
            fclose(file);
        }
    }

    return 0;
}
