#include "stack.h"

void stack_init(Stack *stack) {
    stack->top = -1;
}

int stack_push(Stack *stack, int value) {
    if (stack->top < STACK_SIZE - 1) {
        stack->data[++stack->top] = value;
        return 1;
    }
    return 0; 
}

int stack_pop(Stack *stack, int *value) {
    if (stack->top >= 0) {
        *value = stack->data[stack->top--];
        return 1; 
    }
    return 0; 
