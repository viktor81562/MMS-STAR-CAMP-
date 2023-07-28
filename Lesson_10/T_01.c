#include <stdio.h>

struct Point3D{
    double x;
    double y;
    double z;
}p1;

struct Point3D {
    char a;
    int b;
};

typedef union C {
    int a;
    double b;
}C;

int main() {
printf("%lu", sizeof(C));

    return 0;
}