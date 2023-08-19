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
};

int compareTitlesASC(const void *a, const void *b) {
    return strcmp(((struct Book *)a)->title, ((struct Book *)b)->title);
}

int compareTitlesDESC(const void *a, const void *b) {
    return strcmp(((struct Book *)b)->title, ((struct Book *)a)->title);
}

int compareAuthorsASC(const void *a, const void *b) {
    return strcmp(((struct Book *)a)->author, ((struct Book *)b)->author);
}

int compareAuthorsDESC(const void *a, const void *b) {
    return strcmp(((struct Book *)b)->author, ((struct Book *)a)->author);
}

int comparePageCountASC(const void *a, const void *b) {
    return (((struct Book *)a)->pageCount - ((struct Book *)b)->pageCount);
}

int comparePageCountDESC(const void *a, const void *b) {
    return (((struct Book *)b)->pageCount - ((struct Book *)a)->pageCount);
}

int comparePriceASC(const void *a, const void *b) {
    return (((struct Book *)a)->price - ((struct Book *)b)->price);
}

int comparePriceDESC(const void *a, const void *b) {
    return (((struct Book *)b)->price - ((struct Book *)a)->price);
}

void generateRandomData(struct Book *books, int count) {
    const char *letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(NULL));

    for (int i = 0; i < count; i++) {
        
        int titleLen = rand() % 11 + 10;  
        int authorLen = rand() % 11 + 10; 

        for (int j = 0; j < titleLen; j++) {
            books[i].title[j] = letters[rand() % 52];
        }
        books[i].title[titleLen] = '\0';

        for (int j = 0; j < authorLen; j++) {
            books[i].author[j] = letters[rand() % 52];
        }
        books[i].author[authorLen] = '\0';

        books[i].pageCount = rand() % 1996 + 5;     
        books[i].price = (rand() % 100000) / 100.0; 
    }
}

void printBooks(struct Book *books, int count) {
    for (int i = 0; i < count; i++) {
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Page Count: %d\n", books[i].pageCount);
        printf("Price: %.2f\n\n", books[i].price);
    }
}

int main() {
    struct Book books[COUNT];

    generateRandomData(books, COUNT);

    printf("Unsorted books:\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), compareTitlesASC);
    printf("Sorted by title (ASC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), compareTitlesDESC);
    printf("Sorted by title (DESC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), compareAuthorsASC);
    printf("Sorted by author (ASC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), compareAuthorsDESC);
    printf("Sorted by author (DESC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), comparePageCountASC);
    printf("Sorted by page count (ASC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), comparePageCountDESC);
    printf("Sorted by page count (DESC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), comparePriceASC);
    printf("Sorted by price (ASC):\n");
    printBooks(books, COUNT);

    qsort(books, COUNT, sizeof(struct Book), comparePriceDESC);
    printf("Sorted by price (DESC):\n");
    printBooks(books, COUNT);

    return 0;
}
