#include <stdio.h>

typedef struct Data {
    int val;
}Data;

typedef struct Node {
    Data val;
    struct Node *next;
    struct Node *prev;
}Node;

void print_linked_list(Node *head){

    while(head){
        printf("%d ", head->val);
        head = head->next;
    }

}

void push_back(Data new_data, Node *head) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed.");
        return;
    }

    new_node->val = new_data;
    new_node->next = NULL;

    if (!head) {   // If the list is empty set the new node as the head
        
        head = new_node;
    } else {
        Node *current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void pop_back(Node *head) {
    if (!head) {
        printf("List is empty. Cannot pop.\n");
        return;
    }

    if (head->next == NULL) {  // If the list has only one node, set head to NULL (empty list after popping)
        
        free(head);
        head = NULL;
        return;
    }

    Node *current = head;
    Node *prev = NULL;
    while (current->next) {
        prev = current;
        current = current->next;
    }

    
    prev->next = NULL;
    free(current);
}

void push_front(Data new_data, Node **head) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed.");
        return;
    }

    new_node->val = new_data;
    new_node->next = *head;
    *head = new_node;
}
void pop_front(Node **head) {
    if (!*head) {
        printf("List is empty. Cannot pop.\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}


int main() {
    Node *head;
    Node n1, n2, n3;

    head = &n1;

    n1.val.val = 13;
    n1.next = &n2;

    n2.val.val = 15;
    n2.next = &n3;

    n3.val.val = 20;
    n3.next = NULL;

    print_linked_list(&n1);



    push_back((Data){40}, head);

    print_linked_list(&head);

    return 0;
} 