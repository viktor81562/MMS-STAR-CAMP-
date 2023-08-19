#include <stdio.h>
#include <stdint.h>

void printBits(double num) {
    uint64_t* ptr = (uint64_t*)&num;
    
    uint64_t bits = *ptr;

    for (int i = 63; i >= 0; i--) {
        printf("%u", (bits >> i) & 1);
    }
    printf("\n");
}

void printDoubleInfo(double num) {
    uint64_t* ptr = (uint64_t*)&num;
    
    uint64_t bits = *ptr;

    int sign = (bits >> 63) & 1;
    int exponent = (bits >> 52) & 0x7FF;
    uint64_t mantissa = bits & 0x000FFFFFFFFFFFFF;

    printf("Sign: %d\n", sign);
    printf("Exponent: %d\n", exponent);
    printf("Mantissa: %llu\n", mantissa);
}

int main() {
    double num = 123.456; 
    
    printf("Binary representation: ");
    printBits(num);

    printf("Double info:\n");
    printDoubleInfo(num);

    return 0;
}
