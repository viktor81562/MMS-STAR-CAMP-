#include<stdio.h>
#include<stdint.h>
#define TINT 1
#define TDOUBLE 2
#define TCHAR 3
#define TUINT8 4
#define TUINT16 5
#define TUINT32 6

void printValue(const void* valuePtr, uint8_t flag);

int main(int argc, char* argv[]) {

    int num = 23;

        printValue(&num, TINT);
    return 0;
}

void printValue(const void* valuePtr, uint8_t flag) {
    
    switch(flag) {
        case 1:
        int value1 = *((int*)valuePtr);
        printf("%d\n", value1);
        break;
        case 2:
        double value2 = *((double*)valuePtr);
        printf("%lf\n", value2);
        break;
        case 3:
        char value3 = *((char*)valuePtr);
        printf("%c\n", value3);
        break;
        case 4:
        uint8_t value4 = *((uint8_t*)valuePtr);
        printf("%u\n", value4);
        break;
        case 5:
        uint16_t value5 = *((uint16_t*)valuePtr);
        printf("%u\n", value5);
        break;
        case 6:
        uint32_t value6 = *((uint32_t*)valuePtr);
        printf("%u\n", value6);
        break;
        default:
        printf("you can put on the second position only: TINT, TDOUBLE, TCHAR, TUINT8, TUINT16, TUINT32. \n Choose one of them and try again. ");
    }
}