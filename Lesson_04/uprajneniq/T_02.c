#include <stdio.h>

int main() {

    int *pc,c;

    c=22;
    printf("adress of c: %p\n", &c);
    printf("adress of c: %d\n", c);
    
    pc = &c;
    printf("adress of pointer pc: %p\n", pc);
    printf("content of pointer pc: %d\n", *pc);

    c = 11;

    printf("adress of pointer pc: %p\n", pc);
    printf("content of pointer pc: %d\n", *pc);

    *pc = 7;

    printf("adress of c: %p\n", &c);
    printf("adress of c: %d\n", c);


    return 0;
}