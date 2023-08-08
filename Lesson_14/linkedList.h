#include<stdio.h>
#include<stdlib.h>
#ifndef LINKED_LIST_H
#define LINKED_LIST_H 1

// Структура, която съхранява данните във възлите на свързания списък
typedef struct Data {
    int val;
} Data;

// Структура за възел от свързания списък
struct Node {
    Data d;
    struct Node* next;
};
typedef struct Node Node;

typedef struct LL {
    Node *head;
    Node *tail;
}LL;

// Функция за извеждане на стойностите на елементите в свързания списък
void print_linked_list(LL *ll);

// Функция за добавяне на елемент в края на свързания списък
void push_back(Data new_data, LL *ll);

// Функция за премахване на последния елемент от свързания списък
void pop_back(LL *ll, Data* result);

// Функция за добавяне на елемент в началото на свързания списък
void push_front(Data new_data, LL *ll);

// Функция за премахване на първия елемент от свързания списък
void pop_front(LL *ll, Data* result);

// Функция за вмъкване на елемент след определен индекс в свързания списък
void insert_after(size_t skip_n, Node** head, Data new_data);

LL* init_linked_list();
void deinit_linked_list(LL *ll);

#endif
