#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// func to create new elem of type node 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to make a free list 
void freeList(struct Node* cll) {
    struct Node* current = cll->next;
    while (current != cll) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(cll);
}

// func to add new elem after any position
struct Node* insertAfter(struct Node* cll, int skipCount, int newElem) {
    struct Node* current = cll;
    for (int i = 0; i < skipCount; i++) {
        current = current->next;
    }
    struct Node* newNode = createNode(newElem);
    newNode->next = current->next;
    current->next = newNode;
    return newNode;
}

// func that prints the list 
void print(struct Node* cll) {
    struct Node* current = cll->next;
    while (current != cll) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);

    if (N <= 0) {
        printf("N should be greater than 0.\n");
        return 0;
    }

    int data;
    scanf("%d", &data);
    struct Node* cll = createNode(data);
    struct Node* last = cll;

    for (int i = 1; i < N; i++) {
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        last->next = newNode;
        last = newNode;
    }

    last->next = cll; // Make the list circular

    print(cll);

    int skipCount, newElem;
    printf("Enter skipCount and newElem: ");
    scanf("%d %d", &skipCount, &newElem);

    insertAfter(cll, skipCount, newElem);
    printf("List after insertion: ");
    print(cll);

    freeList(cll); // Free the memory 

    return 0;
}
