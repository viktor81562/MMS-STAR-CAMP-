//napishete kod za razmqna na ukazateli 
//napishete funkciq koqto priema dva ukazatelq kato argumenti i razmenq stoinostite im kum koito sochat

#include <stdio.h>

void swappingFunction(int* a, int* b) {
    *a += *b;
    *b = *a-*b;
    *a = *a-*b; 
}

int main() {

    int x = 3;
    int y = 5;

    swappingFunction(&x,&y);

    printf("value of x: %d\n", x);
    printf("value of y: %d\n", y);



    return 0;
}