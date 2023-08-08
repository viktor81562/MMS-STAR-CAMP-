#include<stdio.h>
#include<stdlib.h>

int compare_ints(const void* p1, const void* p2){
    return *(int*)p1 - *(int*)p2;
}

int main(int argc, char* argv) {

int arr[] = {4,5, -10, 15, -7,-6,7,8};

qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(int), compare_ints);


    for (size_t i = 0; i < 8; i++)
    {
    printf("%d\n", arr[i]);
    }
    

    return 0;
}

typedef struct A{
    double x;
    double y;
} A;