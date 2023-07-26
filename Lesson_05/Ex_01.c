#include <stdio.h>

//linear search

int main() {

    int value = 17;

    int arr[] = {10,1,2,5,4,7,17,19,220,814,18};

    int size_of_arr = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < size_of_arr; i++) {
        printf("%d", arr[i]);
    }

    printf("\n\n\n\n----------------------->\n\n\n\n");


      int temp;

      
    for(int i = 0; i < size_of_arr; i++) {
        if(arr[i] == value) {
            temp = value;
            printf("%d", temp);
        } 
    }
    if(temp!=value) {
        printf("%d not found\n", value);
    }

    return 0;
}