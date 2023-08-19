//#include<stdio.h>
//#include<stdarg.h>
//int variadicF(int argc, ...) {
//	va_list argv;
//	va_start(argv, argc);
//	int sum = 0;
//
//	for (size_t i = 0; i < argc; i++) {
//		sum = sum + va_arg(argv, int);
//
//	}
//	va_end(argv);
//	return sum;
//}
//
//int main(int argc, char* argv[]) {
//
//	int sum = variadicF(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
//
//	printf("%d", sum);
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdarg.h>
//
//void my_printf(const char *fmt, ...) {
//	va_list args;
//	va_start(args, fmt);
//	printf("[CUSTOM PRINTF]");
//	vprintf(fmt, args);
//	va_end(args);
//
//}
//
//int main(int argc, char* argv[]) {
//
//	my_printf("%d %d %d\n", 10, 20, 30);
//	my_printf("Hello viktor!");
//
//	return 0;
//}

#include<stdio.h>
#include<stdarg.h>
#include<time.h>
void my_printf(const char* p, ...) {
    va_list args;
    va_start(args, p);
    time_t viktor;
    struct tm* info;
    time(&viktor);
    info= localtime(&viktor);
    printf("[%s]",asctime(info));
    vprintf(p, args);
    va_end(args);
}

int main(int argc, char* argv[]) {

    my_printf("Viktor e mn gotin");

    return 0;
}
