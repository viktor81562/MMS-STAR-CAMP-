#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define COUNT 10

struct Book {
    char title[150];
    char author[100];
    int pageCount;
    double price;
    struct Book* next;
};

struct Book* createBook(const char* title, const char* author, int pageCount, double price) {
    struct Book* book = (struct Book*)malloc(sizeof(struct Book));
    strcpy(book->title, title);
    strcpy(book->author, author);
    book->pageCount = pageCount;
    book->price = price;
    book->next = NULL;
    return book;
}

void insertBook(struct Book** list, struct Book* newBook) {
    if (*list == NULL || strcmp(newBook->title, (*list)->title) < 0) {
        newBook->next = *list;
        *list = newBook;
    } else {
        struct Book* current = *list;
        while (current->next != NULL && strcmp(newBook->title, current->next->title) >= 0) {
            current = current->next;
        }
        newBook->next = current->next;
        current->next = newBook;
    }
}

void printBooks(struct Book* list) {
    while (list != NULL) {
        printf("Title: %s\n", list->title);
        printf("Author: %s\n", list->author);
        printf("Page Count: %d\n", list->pageCount);
        printf("Price: %.2f\n\n", list->price);
        list = list->next;
    }
}

void freeBooks(struct Book* list) {
    while (list != NULL) {
        struct Book* temp = list;
        list = list->next;
        free(temp);
    }
}

int main() {
    const char* titles[COUNT] = {"Book1", "Book2", "Book3", "Book4", "Book5", "Book6", "Book7", "Book8", "Book9", "Book10"};
    const char* authors[COUNT] = {"Author1", "Author2", "Author3", "Author4", "Author5", "Author6", "Author7", "Author8", "Author9", "Author10"};
    
    srand(time(NULL));

    struct Book* bookList = NULL;

    for (int i = 0; i < COUNT; i++) {
        int pageCount = rand() % 1996 + 5;     
        double price = (rand() % 100000) / 100.0; 

        struct Book* newBook = createBook(titles[i], authors[i], pageCount, price);
        insertBook(&bookList, newBook);
    }

    printf("Sorted books by title:\n");
    printBooks(bookList);

    freeBooks(bookList);

    return 0;
}
