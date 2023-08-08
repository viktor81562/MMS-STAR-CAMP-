#include<stdio.h>

#include <stdlib.h>


int main() {
    
    int N = 10;

    

    FILE *stream = fopen("viktor.txt", "w");

    if(stream == NULL) {
        perror("cannot open file");
        exit(0);
    }
    
    for(int i =0; i < N; i++) {
        int num;
        scanf("%d", &num);
        fprintf(stream,"%d ", num);

    }

    fclose(stream);

    stream = fopen("viktor.txt", "r");

    if(stream == NULL) {
        perror("cannot open file");
        exit(0);
    }
    printf("numbers of this ");
    int num;
    while (fscanf(stream, "%d", &num) != EOF)
    {
        printf("%d ", num);

    }

    printf("\n");
    


    return 0;
}