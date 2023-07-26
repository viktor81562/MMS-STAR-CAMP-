#include <stdio.h>
#include <stdint.h>



int main() {

uint64_t a;

scanf("%lu",&a);

int sign_bit_value = (!!(a&(1ULL << 63)));

printf("%lu\n", a * !sign_bit_value + (~a-1)*sign_bit_value);

    return 0;
}