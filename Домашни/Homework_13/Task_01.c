#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Deque {
    struct Node* front;
    struct Node* rear;
};

struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

void pushFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    
    if (deque->front == NULL) {
        newNode->next = NULL;
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

void pushRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (deque->rear == NULL) {
        newNode->prev = NULL;
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

int popFront(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty\n");
        return -1; 
    }
    
    int data = deque->front->data;
    struct Node* temp = deque->front;
    
    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = NULL;
    }
    
    free(temp);
    return data;
}

int popRear(struct Deque* deque) {
    if (deque->rear == NULL) {
        printf("Deque is empty\n");
        return -1;
    }
    
    int data = deque->rear->data;
    struct Node* temp = deque->rear;
    
    if (deque->front == deque->rear) {
        deque->front = deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
    }
    
    free(temp);
    return data;
}

int main() {
    struct Deque* deque = createDeque();
    
    pushFront(deque, 1);
    pushFront(deque, 2);
    pushRear(deque, 3);
    pushRear(deque, 4);
    
    printf("Front: %d\n", popFront(deque)); 
    printf("Rear: %d\n", popRear(deque));   
    
    free(deque);
    
    return 0;
}
