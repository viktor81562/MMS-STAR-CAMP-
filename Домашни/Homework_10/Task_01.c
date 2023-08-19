#include <stdio.h>
#include <stdint.h>

void swapBytes(uint16_t* word) {
    uint8_t msb = (*word >> 8) & 0xFF;
    uint8_t lsb = *word & 0xFF;
    *word = (lsb << 8) | msb;
}

int main() {
    uint16_t myVariable = 0xABCD;
    printf("Before swapping: 0x%04X\n", myVariable);
    
    swapBytes(&myVariable);
    printf("After swapping: 0x%04X\n", myVariable);
    
    return 0;
}
