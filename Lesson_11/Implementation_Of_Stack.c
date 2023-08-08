#include<stdio.h>
#include <stdlib.h>
//realizing a stack with array

typedef struct A {
    int data;
}A;


size_t capacity;// the maximum number of the elemnts in the stack
size_t cur_elem_count; //the current number of the elements in stack

A *arr_begin = NULL;
void init_stack_array(size_t max_elem_count){
    capacity = max_elem_count;
    cur_elem_count = 0;
    arr_begin = (A*)malloc(capacity*sizeof(A));
}


int push(A elem){
    if(cur_elem_count == capacity){
        printf("Stack is full\n");
        return -1;
    }
    else{
        arr_begin[cur_elem_count] = elem;
        cur_elem_count++;
        return 0;
    }
}

int pop(A *res) {
    if(cur_elem_count == 0){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        *res = arr_begin[cur_elem_count-1];
        cur_elem_count--;
        return 0;
    }
}

void print_elem(){
    for(size_t i = 0; i < cur_elem_count; i++){
        printf("%d\n", arr_begin[i].data);
    }
}

int main(){
    init_stack_array(10);
    A elem;
    elem.data = 10;
    push(elem);
    elem.data = 20;
    push(elem);
    elem.data = 30;
    push(elem);
    elem.data = 40;
    push(elem);
    elem.data = 50;
    push(elem);
    elem.data = 60;
    push(elem);
    elem.data = 70;
    push(elem);
    elem.data = 80;
    push(elem);
    elem.data = 90;
    push(elem);
    elem.data = 100;
    push(elem);
    elem.data = 110;
    push(elem);
    elem.data = 120;
    push(elem);
    elem.data = 130;
    push(elem);
print_elem();
    pop(&elem);

    print_elem();

    free(arr_begin);
    return 0;
}