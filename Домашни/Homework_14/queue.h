#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_SIZE 100

typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;

void queue_init(Queue *queue);
int queue_enqueue(Queue *queue, int value);
int queue_dequeue(Queue *queue, int *value);

#endif
