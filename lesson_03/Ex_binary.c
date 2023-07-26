#include <stdio.h>
#include <math.h>

int main() {

    int decimal; //declarating decimal num
    scanf("%d", &decimal); //entering the value of the decimal

    int binary;// declaring binary num

    int array[100]; 
        int array1[100]; 

    int cnt = 0; //intializing counter
    while(decimal>0) {
        binary = decimal % 2; //taking the result of the mod
        array[cnt] = binary; //storing the result in the array
        decimal = decimal / 2;
        cnt++;
    }
     printf("This is the binary presentation of the decimal number(%d): \n",decimal );
    for(int i = cnt-1; i >= 0; i--) {
     printf("%d", array[i]);
    }

    decimal = 0; //changing the value of the decimal to be sure

    for(int i = cnt-1; i >= 0; i--) {
        decimal = decimal + array[i] * pow(2, i); //multiplying the array with the power of 2
    }
    printf("\nThis is the decimal presentation of the binary number(%d): %d\n\n\n",binary, decimal);

    int octal; // declaring octal
    //converting from binary to octal number

    for(int i = cnt-1; i >= 0; i--) {
        octal = octal + array[i] * pow(2, i); //multiplying the array with the power of 2
    }
    
    
    cnt = 0; //intializing counter
    while(decimal>0) {
        octal = decimal % 8; //taking the result of the mod
        array1[cnt] = octal; //storing the result in the array
        decimal = decimal / 8;
        cnt++;
    }
     printf("This is the octal presentation of the decimal number(%d): \n",decimal );
    for(int i = cnt-1; i >= 0; i--) {
     printf("%d", array1[i]);
    }

    printf("\n\n\n");

    
    
            


    return 0; 
}