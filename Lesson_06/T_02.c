#include <stdio.h>

//f == int addOne(int);
// myMap()

void myMap(int arr[], int n, int(*f)(int)) {
for(int i = 0; i < n;i++){
    arr[i] = f(arr[i]);
}
}
int scanEl(int a){
    int temp;
    scanf("%d",&temp);
    return temp;
}
int printEl(int el){
    printf("%d\n",el);
    return el;
}
int square(int el) {
    return el*el;
}

int main() {
    int arr[100];
    myMap(arr,5,scanEl);
    myMap(arr,5,square);
    myMap(arr,5,printEl);

    return 0;
}