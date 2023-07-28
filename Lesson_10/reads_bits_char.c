#include <stdio.h>
#include <stdint.h>
typedef union A {
    double a;
    uint64_t b;

}A;
int main() {

    A union1;
    union1.a = 3.14;
    printf("%lf", union1.a);
    printf("%lu", union1.b);

}