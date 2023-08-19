#include <stdio.h>

void filter_and_map(const int arr[], size_t n, int (*filter_f)(int), int (*map_f)(int), int dest[],size_t* dest_cnt){
    
    *dest_cnt = 0;

    for(int i = 0; i < n; i++) {
        int flag = filter_f(arr[i]);
        if(flag == 1) {
            dest[*dest_cnt] = map_f(arr[i]);
            (*dest_cnt)++;
        }
    }

    printf("Size of new array is:%d\n", *dest_cnt);
    printf("Values in new dest array:");

    for (size_t i = 0; i < *dest_cnt; i++)
    {
        printf("%d ", dest[i]);
    }
    

}

int filter(int num) {
    if(num >= 0) {
        return 1;
    } else {
        return 0;
    }
}

int addOne(int num) {
    return num + 1;
}


int main(int argc, char* argv[]) {

    int arr[8] = {1, 2, 3, 4, -1, -2, 11, -100};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    int dest[10];
    size_t dest_cnt;

    filter_and_map(arr, size, filter, addOne, dest, &dest_cnt);  


    return 0;
}