#include <stdio.h>
#include <stdarg.h>

int my_printf(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int count = 0;
    char c;

    while ((c = *fmt)) {
        if (c == '%') {
            fmt++;

            switch (*fmt) {
                case 'd': {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    count++;
                    break;
                }
                case 'f': {
                    double num = va_arg(args, double);
                    printf("%f", num);
                    count++;
                    break;
                }
                case 'c': {
                    int ch = va_arg(args, int);
                    putchar(ch);
                    count++;
                    break;
                }
                default:
                    putchar(c);
                    count++;
                    break;
            }
        } else {
            putchar(c);
            count++;
        }

        fmt++;
    }

    va_end(args);
    return count;
}

int main() {
    int num = 42;
    double fnum = 3.14;
    char ch = 'A';

    int printed_chars = my_printf("Integer: %d, Float: %f, Character: %c\n", num, fnum, ch);

    printf("Total characters printed: %d\n", printed_chars);

    return 0;
}
