#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

void stack_init(Stack *stack);
int stack_push(Stack *stack, int value);
int stack_pop(Stack *stack, int *value);

#endif
