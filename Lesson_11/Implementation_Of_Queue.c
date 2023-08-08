#include<stdio.h>
#include<stdlib.h>
//crating our own queue with many instance made by a stuct

typedef struct A{
    int data;
}A;

typedef struct Queue{
size_t capacity;
A *arr;
size_t cur_elem_count;
}Queue;


Queue intit_queue(size_t capacity){
    Queue q;
    q.capacity = capacity;
    q.arr = (A*)malloc(sizeof(A)*q.capacity);
    q.cur_elem_count = 0;
    return q;
}

//to make dequeue with for loop to navigates

int dequeue(Queue *q, A *res){
    if(q->cur_elem_count == 0){
        return 1;
    }
    for(size_t i = 0; i < q->cur_elem_count; i++){
        res->data = q->arr[i].data;
        q->arr[i].data = 0;
        q->cur_elem_count--;
    }
    return 0;
}

int enqueue(Queue *q, A *res){
    if(q->cur_elem_count == q->capacity){
        return 0;
    }
    q->arr[q->cur_elem_count] = *res;
    q->cur_elem_count++;
    return 1;
}

void print_elem(Queue q){
   for (size_t i = 0; i < q.capacity; i++)
   {
    if(i<q.cur_elem_count){
        printf("%3d ",q.arr[i].data);
    }else{
        printf(" _ ");
    }
   }
   
}

int main(){
    Queue q = intit_queue(10);
    A res;
    res.data = 10;
    enqueue(&q, &res);
    print_elem(q);
    printf("\n\n\n\n\n");
    dequeue(&q, &res);
    print_elem(q);
    printf("\n\n\n\n\n");
    res.data = 11;
    enqueue(&q, &res);
    print_elem(q);
    printf("\n\n\n\n\n");
    res.data = 12;
    enqueue(&q, &res);
    print_elem(q);
    printf("\n\n\n\n\n");
    res.data = 13;
    enqueue(&q, &res);
    print_elem(q);
    printf("\n\n\n\n\n");
    res.data = 14;
    enqueue(&q, &res);
    print_elem(q);
    printf("\n\n\n\n\n");

    

    return 0;
}