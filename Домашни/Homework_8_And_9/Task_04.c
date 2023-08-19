#include <stdio.h>
#include <stdint.h>

int clearBits(uint32_t* maskArr, size_t nitems, size_t bit_index) {
    if (maskArr == NULL || bit_index >= 32) {
        return -1; 
    }

    for (size_t i = 0; i < nitems; i++) {
        maskArr[i] &= ~(1u << bit_index); 
    }

    return 0; 
}

int setBits(uint32_t* maskArr, size_t nitems, size_t bit_index) {
    if (maskArr == NULL || bit_index >= 32) {
        return -1; 
    }

    for (size_t i = 0; i < nitems; i++) {
        maskArr[i] |= (1u << bit_index); 
    }

    return 0; 
}

int checkBits(uint32_t* maskArr, size_t nitems, size_t bit_index) {
    if (maskArr == NULL || bit_index >= 32) {
        return -1; 
    }

    int has_zero = 0;
    int has_one = 0;

    for (size_t i = 0; i < nitems; i++) {
        uint32_t bit_value = (maskArr[i] >> bit_index) & 1u;
        if (bit_value == 0) {
            has_zero = 1;
        } else {
            has_one = 1;
        }

        if (has_zero && has_one) {
            return -1; 
        }
    }

    if (has_zero) {
        return 0; 
    } else {
        return 1; 
    }
}

int main() {
    uint32_t maskArr[] = { 0xFFFFFFFF, 0x0000FFFF, 0xAAAAFFFF };
    size_t nitems = sizeof(maskArr) / sizeof(maskArr[0]);
    size_t bit_index = 16;

    
    if (clearBits(maskArr, nitems, bit_index) == 0) {
        printf("Bit at index %zu cleared successfully\n", bit_index);
    } else {
        printf("Error clearing bit at index %zu\n", bit_index);
    }

    if (checkBits(maskArr, nitems, bit_index) == 0) {
        printf("All elements have 0 at bit index %zu\n", bit_index);
    } else if (checkBits(maskArr, nitems, bit_index) == 1) {
        printf("All elements have 1 at bit index %zu\n", bit_index);
    } else {
        printf("Some elements have 0 and some have 1 at bit index %zu\n", bit_index);
    }

    return 0;
}
