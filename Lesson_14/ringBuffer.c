#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *buffer;
    int capacity;
    int size;
    int front;
    int rear;
} Queue;


Queue *initializeQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (!queue) {
        perror("Could not allocate memory for the queue\n");
        exit(EXIT_FAILURE);
    }

    queue->buffer = (int *)malloc(sizeof(int) * capacity);
    if (!queue->buffer) {
        perror("Could not allocate memory for the buffer\n");
        exit(EXIT_FAILURE);
    }

    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;

    return queue;
}

int isEmpty(Queue *queue) {
    return queue->size == 0;
}

int isFull(Queue *queue) {
    return queue->size == queue->capacity;
}


void enqueue(Queue *queue, int item) {
    if (isFull(queue)) {
        perror("Queue is full\n");
        exit(EXIT_FAILURE);
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->buffer[queue->rear] = item;
    queue->size++;
}


int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        perror("Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    int item = queue->buffer[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return item;
}

void destroyQueue(Queue *queue) {
    free(queue->buffer);
    free(queue);
}

int main() {
    Queue *queue = initializeQueue(5);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Dequeued: %d\n", dequeue(queue));
    printf("Dequeued: %d\n", dequeue(queue));

    enqueue(queue, 40);
    enqueue(queue, 50);

    while (!isEmpty(queue)) {
        printf("Dequeued: %d\n", dequeue(queue));
    }

    destroyQueue(queue);

    return 0;
}