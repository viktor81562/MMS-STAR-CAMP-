#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


int evaluateExpression(const char *expr, int *index); //function for rating the sentence 


int evaluateOperation(const char *expr, int *index); // func for + or *


int evaluatePower(const char *expr, int *index); //func for pow


bool isDigit(char c); //check for digit


int charToDigit(char c); //convert symbol to digit


int main() {
    char expression[1000];
    fgets(expression, sizeof(expression), stdin);

    
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    int index = 0;
    int result = evaluateExpression(expression, &index);
    printf("%d\n", result);

    return 0;
}

int evaluateExpression(const char *expr, int *index) {
    int result = evaluateOperation(expr, index);
    while (expr[*index] == '+' || expr[*index] == '*') {
        char operation = expr[(*index)++];
        int nextOperand = evaluateOperation(expr, index);
        if (operation == '+') {
            result += nextOperand;
        } else {
            result *= nextOperand;
        }
    }
    return result;
}

int evaluateOperation(const char *expr, int *index) {
    int result = evaluatePower(expr, index);
    while (expr[*index] == '^') {
        (*index)++;
        int nextOperand = evaluatePower(expr, index);
        result = (int)pow(result, nextOperand);
    }
    return result;
}

int evaluatePower(const char *expr, int *index) {
    int result = 0;
    if (expr[*index] == '(') {
        (*index)++;
        result = evaluateExpression(expr, index);
        (*index)++; 
    } else {
        while (isDigit(expr[*index])) {
            result = result * 10 + charToDigit(expr[(*index)++]);
        }
    }
    return result;
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

int charToDigit(char c) {
    return c - '0';
}

