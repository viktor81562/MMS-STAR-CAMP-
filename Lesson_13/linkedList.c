#include<stdio.h>
#include<stdlib.h>

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
void print_linked_list(Node* head) {
    for (; head != NULL; head = head->next) {
        printf("%d ", head->d.val);
    }
    printf("\n");
}

// Функция за добавяне на елемент в края на свързания списък
void push_back(Data new_data, Node** head) {
    Node* new_last_node = (Node*)malloc(sizeof(Node));
    if (!new_last_node) {
        perror("Could not malloc\n");
        exit(-1);
    }
    new_last_node->d = new_data;
    new_last_node->next = NULL;

    if (*head == NULL) {
        *head = new_last_node; // Ако списъкът е празен, новият възел става начало на списъка
        return;
    }

    Node* cur_node = *head;
    while (cur_node->next != NULL) {
        cur_node = cur_node->next;
    }
    cur_node->next = new_last_node; // Променяме последния възел да сочи към новия възел
}

// Функция за премахване на последния елемент от свързания списък
void pop_back(Node** head, Data* result) {
    if (!(*head)) {
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }
    if ((*head)->next == NULL) {
        *result = (*head)->d;
        free(*head);
        *(head) = NULL; // Ако има само един елемент, го изтриваме и указателят става NULL
    }
    Node* cur_node = *head;
    while (cur_node->next->next != NULL) {
        cur_node = cur_node->next;
    }
    *result = cur_node->next->d;
    free(cur_node->next);
    cur_node->next = NULL; // Зануляваме указателя към изтрития възел
}

// Функция за добавяне на елемент в началото на свързания списък
void push_front(Data new_data, Node** head) {
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
void pop_front(Node** head, Data* result) {
    if (!(*head)) {
        perror("Cannot pop from empty linked list\n");
        exit(-1);
    }
    Node* temp = *head;
    *result = temp->d;
    *head = temp->next; // Променяме началото на списъка да сочи към следващия възел
    free(temp); // Освобождаваме паметта на изтрития възел
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

int main() {
    Node* head = NULL;

    Data data1 = { 100 };
    push_front(data1, &head);

    Data data2 = { 200 };
    push_back(data2, &head);

    Data data3 = { 300 };
    push_back(data3, &head);

    Data data4 = { 400 };
    push_back(data4, &head);

    Data data5 = { 900 };
    push_front(data5, &head);

    Data data6 = { 1000 };
    push_front(data6, &head);

    print_linked_list(head);
    return 0;
}
