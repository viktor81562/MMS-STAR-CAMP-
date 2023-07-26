#include <stdio.h>

int main(void)
{
    int x = 10;
    int y = 20;
    int z;
    int a = 5;
    int b = 2;
    float c;
    c = (float)a / b;
    printf("The result of a divided by b is: %f\n", c);
        z = x + y; // addition operation
            printf("The sum of x and y is: %d\n", z);              // expression

    z = x - y;     // subtraction operation
        printf("The dierence between x and y is: %d\n", z);    // expression

    z = x * y;     // multiplication operation
        printf("The product of x and y is: %d\n", z);          // expression

    z = y / x;     // division operation
        printf("The quotient of y divided by x is: %d\n", z);  // expression

    z = y % x;     // modulus operation
        printf("The remainder of y divided by x is: %d\n", z); // expression


    return 0;
}