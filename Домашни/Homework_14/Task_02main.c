#include <stdio.h>
#include "Task_02stack.h"

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);

    printf("Top element: %d\n", peek(&stack));

    pop(&stack);

    printf("Top element after pop: %d\n", peek(&stack));

    push(&stack, 20);

    printf("Top element after push: %d\n", peek(&stack));

    destroy(&stack);

    return 0;
}
