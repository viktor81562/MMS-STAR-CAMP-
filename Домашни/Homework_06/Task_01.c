#include <stdio.h>

double find_cbrt_binary_search(double C, double epsilon);

int main() {
    double C = 27.0; 
    double epsilon = 0.0001; 

    double result = find_cbrt_binary_search(C, epsilon);
    printf("Cubic root of %.2f is %.2f\n", C, result);
    return 0;
}

double find_cbrt_binary_search(double C, double epsilon) {
    double low = 0.0; 
    double high = C; 
    double mid; 

    while (high - low > epsilon) {
        mid = (low + high) / 2.0;
        double cube = mid * mid * mid;

        if (cube < C) {
            low = mid;
        }
        else {
            high = mid;
        }
    }

    return (low + high) / 2.0; 
}
