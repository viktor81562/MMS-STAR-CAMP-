#include <stdio.h>

 int arr[] = {1,2,3};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void permutations(int begin, int total) {
    if(begin == total) {
        for(size_t i = 0; i < total; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    else {
        for(size_t i = begin; i < total; i++) {
            swap(&arr[begin], &arr[i]);
            permutations(begin + 1, total);
            swap(&arr[begin], &arr[i]);
        }
    }

}

int main(int argc, char const *argv[]) {

    permutations(0,3);

    return 0;
}