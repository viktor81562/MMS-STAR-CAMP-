#include "queue.h"

void queue_init(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

int queue_enqueue(Queue *queue, int value) {
    if (queue->count < QUEUE_SIZE) {
        queue->rear = (queue->rear + 1) % QUEUE_SIZE;
        queue->data[queue->rear] = value;
        queue->count++;
        return 1;
    }
    return 0; 
}

int queue_dequeue(Queue *queue, int *value) {
    if (queue->count > 0) {
        *value = queue->data[queue->front];
        queue->front = (queue->front + 1) % QUEUE_SIZE;
        queue->count--;
        return 1;
    }
    return 0; 
}
