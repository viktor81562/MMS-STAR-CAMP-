#include <stdio.h>

void merge (int arr1[],int arr2[],int n1,int n2, int *dest) {
    
   
    size_t i1=0, i2=0;
    while(i1 < n1 && i2 < n2) {
        if(arr1[i1] <= arr2){
            *(dest++) = arr1[i1];
            i1++;
        }else {
            *(dest++) = arr2[i2];
            i2++;
        }

    }
    while(i1 < n1) {
        *(dest++) = arr1[i1];
        i1++;
    }
    while(i2 < n2) {
        *(dest++) = arr2[i2];
        i2++;
    }

}

int main() {

    int arr1[] = {1,5,8};
    int arr2[] = {3,7,10,11,12};

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    int dest[n1+n2];
    merge(arr1,arr2,n1,n2,dest);

    for(size_t i = 0; i < n1 +n2; i++) {
        printf("%d\n", dest[i]);
    }


    return 0;
}