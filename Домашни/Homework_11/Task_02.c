#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top >= STACK_SIZE - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        fprintf(stderr, "Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluateReversePolish(const char *expression) {
    const char *delimiter = " ";
    char *token = strtok((char *)expression, delimiter);

    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            int operand2 = pop();
            int operand1 = pop();
            push(operand1 + operand2);
        } else if (strcmp(token, "*") == 0) {
            int operand2 = pop();
            int operand1 = pop();
            push(operand1 * operand2);
        } else if (strcmp(token, "-") == 0) {
            int operand2 = pop();
            int operand1 = pop();
            push(operand1 - operand2);
        } else {
            int operand = atoi(token);
            push(operand);
        }
        token = strtok(NULL, delimiter);
    }

    return pop();
}

int main() {
    char expression[1000];
    fgets(expression, sizeof(expression), stdin);

    int result = evaluateReversePolish(expression);
    printf("%d\n", result);

    return 0;
}
