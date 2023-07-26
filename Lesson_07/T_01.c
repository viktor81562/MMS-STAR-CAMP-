#include <stdio.h>

int add(int a, int b) {
    return a + b;
}
int mult(int a, int b) {
    return a * b;
}

int aggregate(int *arr, int n, int init, int (*f)(int,int)) {
    int result = init;
    for (int i = 0; i < n; i++) {
        result = f(result, arr[i]);
    }
    return result;
}

int main() {

    int arr[] = {1,2,3,4,5};

    printf("%d",aggregate(arr, 5, 15, add));
    printf("%d",aggregate(arr, 5, 15, mult));

    return 0;
}