#include<stdio.h>
#include<stdlib.h>

int main() {
    char buf[100], c;
    FILE *stream = fopen("text.txt","r+");
  

    if(stream == NULL){
        perror("cannot open file");
        exit(0);
    }
    
    c = fgetc(stream);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(stream);
    }
    fclose(stream);
    return 0;
}