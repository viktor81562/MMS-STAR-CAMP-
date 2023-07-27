#include <stdio.h>
#include <string.h>
#include <limits.h>
typedef struct A {
   unsigned char b;
    unsigned int a;
} A;

void printBytes(const void *p, int numBytes){
    char buf[numBytes];
    memcpy(buf, p, numBytes);
    for(int i = 0; i < numBytes; i++){
        printf("%02x ", buf[i]);
    }
}

int main(int argc, char *argv[]) {

A a = {UCHAR_MAX, UINT_MAX};
printBytes(&a, sizeof(A));
printf("\n");

return 0;
}