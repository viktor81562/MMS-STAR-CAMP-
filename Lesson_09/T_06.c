#include <stdio.h>
#include<stdlib.h>

void f() {
    static int a = 0;
    a++;
    printf("%d\n", a);
}
int main() {

    f();
    f();
    f();
    f();
    f();
    f();
    f();

    return 0;
}