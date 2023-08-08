#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"

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



// Функция за извеждане на стойностите на елементите в свързания списък
void print_linked_list(LL *ll) {
    Node *head = ll->head;
    // Да изпечатаме всеки елемент на свързания списък
    for(;head != NULL; head=head->next) {
        printf("%d ", head->d.val);
    }
    printf("\n");
}

// Функция за добавяне на елемент в края на свързания списък
void push_back(Data new_data, LL *ll) {
    // *head - Node*
    // **head - Node
    // Allocate dynamic memory for new node
    Node **head = &(ll->head);
    Node **tail = &(ll->tail);

    Node *new_last_node = malloc(sizeof(Node));
    if(!new_last_node) {
        perror("Could not malloc\n");
        exit(-1);
    }
    new_last_node->d = new_data;
    new_last_node->next = NULL;

    // Empty linked list
    if(*head == NULL) {
        *head = new_last_node;
        *tail = new_last_node;
        return;
    }

    // След последния елемент добавяме нов Node
    (*tail) -> next = new_last_node;
    // *tail ще пази адреса на новия последен елемент
    *tail = (*tail) -> next;
}

// Функция за премахване на последния елемент от свързания списък
void pop_back(LL *ll, Data *result) {
    Node **head = &(ll->head);
    Node **tail = &(ll->tail);

    // Empty linked list
    if(!(*head)) { // *head == NULL
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }
    // Only one element in linked list
    if((*head)->next == NULL) {
        *result = (*head)->d;
        free(*head);
        *head = NULL; 
        *tail = NULL;
        return;
    }
    // Find second to last element
    Node *cur_node = *head;
    // While the next node is not the last one
    while(cur_node->next->next != NULL) {
        cur_node = cur_node->next;
    }
    // After while - cur_node is second to last node
    // After while - cur_node->next to last node
    *result = cur_node->next->d;
    // Free last node
    free(cur_node->next);
    cur_node->next = NULL;

    // Tail will point to new last node
    *tail = cur_node;
}

// Функция за добавяне на елемент в началото на свързания списък
void push_front(Data new_data, LL *ll) {
            Node **head = &(ll->head); 

    Node* new_first_node = (Node*)malloc(sizeof(Node));
    if (new_first_node == NULL) {
        perror("Could not malloc\n");
        exit(-1);
    }
    new_first_node->d = new_data;
    new_first_node->next = *head; // Новият възел сочи към текущото начало на списъка
    *head = new_first_node; // Променяме началото на списъка да сочи към новия възел
}

// Функция за премахване на първия елемент от свързания списък
void pop_front(LL *ll, Data *result) {
    Node **head = &(ll->head);

    if(*head == NULL) {
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }
    // Ако подадем NULL Като втори аргумент - не записваме премахнатия NODE никъде
    if(result != NULL) {
        *result = (*head)->d;
    }
    Node *second_node = (*head)->next;
    free(*head);
    *head = second_node;

    // След премахване на първия елемент
    // Ако преди е имало само един елемент
    // Тогава *head Ще е станал NULL
    if(*head == NULL) {
        ll->tail = NULL;
    }
}

// Функция за вмъкване на елемент след определен индекс в свързания списък
void insert_after(size_t skip_n, Node** head, Data new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        perror("Could not malloc\n");
        exit(-1);
    }
    new_node->d = new_data;

    if (skip_n == 0 || !(*head)) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node* cur_node = *head;
    while (skip_n > 1 && cur_node->next != NULL) {
        cur_node = cur_node->next;
        skip_n--;
    }

    new_node->next = cur_node->next;
    cur_node->next = new_node;
}

LL* init_linked_list() {
    // Allocate memory for LL
    LL *ll = (LL*)malloc(sizeof(LL));
    if(!ll) {
        perror("Could not malloc\n");
        exit(-1);
    }
    // Empty linked list
    ll -> head = NULL; 
    ll -> tail = NULL;
    return ll;
}
void deinit_linked_list(LL* ll) {
    // Is linked list empty
    // NODE **head;
    // *head дали е NULL

    // LL *ll;
    // ll->head дали е NULL

    // Is empty
    while(!(ll->head)) {
        // NULL - не искаме никъде да запишем резултата
        pop_front(ll, NULL);
    }
    free(ll);
}
