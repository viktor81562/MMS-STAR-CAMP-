#include<stdio.h>

int main() {

    int decimal = 25;
    int binary[100];
    int cnt = 0;
    while(decimal > 0) {
        
        binary[cnt] = decimal % 2;
        decimal = decimal / 2;
        cnt++;
    }

    for(int i = cnt - 1; i > -1; i--) {
        printf("%d", binary[i]);
    }


    return 0;
}