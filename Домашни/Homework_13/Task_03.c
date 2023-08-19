#include <stdio.h>

// 1.1
#define MAX(x, y, z) ((x) > (y) ? ((x) > (z) ? (x) : (z)) : ((y) > (z) ? (y) : (z)))

// 1.2
#define MIN(x, y, z) ((x) < (y) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z)))

// 1.3
#define SETBIT(mask, bit) ((mask) |= (1 << (bit)))

// 1.4
#define CLEARBIT(mask, bit) ((mask) &= ~(1 << (bit)))

// 1.5
#define INVERSEBIT(mask, bit) ((mask) ^= (1 << (bit)))

// 1.6
#define CHECKBIT(mask, bit) (((mask) >> (bit)) & 1)

// 1.7
#define SWAP(a, b) do { (a) ^= (b); (b) ^= (a); (a) ^= (b); } while (0)

int main() {
    int x = 5, y = 10, z = 3;
    int mask = 0x0A; 

    printf("Max: %d\n", MAX(x, y, z));
    printf("Min: %d\n", MIN(x, y, z));

    SETBIT(mask, 2); 
    printf("Set Bit: %d\n", mask); 
    CLEARBIT(mask, 3); 
    printf("Clear Bit: %d\n", mask); 

    INVERSEBIT(mask, 1); 
    printf("Inverted Bit: %d\n", mask); 

    printf("Check Bit: %d\n", CHECKBIT(mask, 2)); 

    int a = 10, b = 20;
    SWAP(a, b);
    printf("After Swap: a = %d, b = %d\n", a, b); 

    return 0;
}
