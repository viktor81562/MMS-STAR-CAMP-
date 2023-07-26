#include <stdio.h>

int square(int num);

int main(void) {

 int num = 10;

 //scanf("%d", &num);

    int result = square(num);

    printf("%d\n", result);

    return 0;
}

int square(int num) {
    return num * num;
}
