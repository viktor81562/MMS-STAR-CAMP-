#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* toUpper(const char* str) {

    char *arr = (char *)malloc(sizeof(char) * 100); //array for cpy
    strcpy(arr, str); // arr = str

    for(int i = 0; i < strlen(arr); i++) {
        if(arr[i] >= 95) {
            arr[i] = arr[i] - 32;
        }
    } 
    return arr;
}



int main() {

    char str[100];
    scanf("%s", str);
    char* arr = toUpper(str);
    printf("%s\n",arr);
    free(arr);

    return 0;
}