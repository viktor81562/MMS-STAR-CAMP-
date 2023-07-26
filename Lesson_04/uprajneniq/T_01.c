
#include <stdio.h>
#include<stdint.h>

// making function 

uint16_t set_bit(uint16_t mask, int bit){
    return mask | (1 << bit);
}

uint16_t clear_bit(uint16_t mask, int bit){
    return mask & ~(1 << bit);
}

int check_bit(uint16_t mask, int bit) {
    return mask & (1 << bit)? 1 : 0;
}

void PrintBit(uint16_t mask) {
    for(int i = 16 - 1; i>= 0; i--) {
        printf("%d", check_bit(mask, i));
    }

}


int main() {

    uint16_t digit = 0xffff;

    PrintBit(digit);
    printf("\n");
    digit = clear_bit(digit, 15);
    PrintBit(digit);
    printf("\n");
    digit = set_bit(digit, 15);
    PrintBit(digit);
    printf("\n");
    digit = check_bit(digit, 15);
    PrintBit(digit);
    printf("\n");
    

    return 0;
}