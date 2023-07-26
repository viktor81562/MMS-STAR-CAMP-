#include <stdio.h>

int strlen(char *str);//dyljinata
void strcpy(char *dest, char *src);// kopira niza v dest
void strcat(char *dest, char *src); // dobavq src kym kraq na dest
void strcmp(char *str1, char *str2); //sravnqva str1 i str2
// vryshta 0 ako str1 i str2 sa ednakvi 
// chislo <0 ako pyrviq simvol, v koito str1 i str2 se razlichavat e po-malyk
//pri str1

int main() {



    return 0;
}

int strlen(char *str){
    int i = 0;
    while(str[i]!= '\0'){
        i++;
    }
    return i;
}
void strcpy(char *dest, char *src){
    char symbol;
    int i = 0;
    while(src[i]!='\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return;
}
void strcat(char *dest, char *src){
    char symbol;
    while(dest != '\0'){
        dest++;
    }
    while(*src != '\0'){
            *dest = *src;
            dest++;
            src++;
        }
        *dest = '\0';
}
void strcmp(char *str1, char *str2){
    while(*str1 ==*str2){
      str1++;
      str2++;
    }
    if(*str1 == '\0' && *str2 == '\0'){
        return 0;
    } else if(*str1 == '\0'){
        return -1;
    } else {
        return 1;
}
