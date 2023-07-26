
// main.c
#include <stdio.h>
#include "my_math.h"

double square(double num);
double cube(double num);
int main(void){
double num = 5.0;
double sq = square(num);
double cu = cube(num);
printf("The square of %f is %f.\n", num, sq);
printf("The square of %f is %f.\n", num, cu);

return 0;
}