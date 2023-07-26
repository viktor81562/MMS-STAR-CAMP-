#include <stdio.h>
#include <math.h>

int main(void) {

    int number = 347;

    int base = 10;

    int cnt = 0;

     int result = 0;

    while(number>0) {

        int digit = number % 10;
        result = result + digit  * pow(base,cnt);
        cnt++;
        number = number / 10;
    }
    printf("%d\n", result);

    return 0;
}