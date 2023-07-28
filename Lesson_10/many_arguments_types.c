#include <stdio.h>

typedef union A {
    char c;
    double d;
    int i;
} A;

typedef struct Arg {
    A argVal;
    int argType;

} Arg;

void print() {
    if (a.argType == 0) {
        printf("%c\n", a.argVal.c);
    }
    if (a.argType == 1) {
        printf("%c\n", a.argVal.d);
    }
    if (a.argType == 2) {
        printf("%c\n", a.argVal.i);
    }

}

int main() {
    Arg argChar;
    argChar.argType =0;
    argChar.argVal.c = 'W';
    print(argChar);

    Arg argDouble;
    argDouble.argType =0;
    argDouble.argVal.d = 'W';
    print(argChar);

    return 0;
}