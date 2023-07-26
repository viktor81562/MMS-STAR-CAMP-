#include <stdio.h>

void myFunction() {
    int myVar = 5;
    printf("myVar inside of myFunction(): %d\n",myVar);
}

int main(int argc, char* argv[]) {

    myFunction();

    return 0;

}