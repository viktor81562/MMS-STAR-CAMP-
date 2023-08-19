#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_LEN 10

struct Person {
    char name[100];
    char id[ID_LEN];
    unsigned short birthYear;
    unsigned char birthDay;
    char gender;
};

struct Person *peopleArray = NULL;
size_t arrayCapacity = 0;
size_t arraySize = 0;

void* initArray(size_t capacity) {
    peopleArray = (struct Person*)malloc(sizeof(struct Person) * capacity);
    if (peopleArray == NULL) {
        return NULL;
    }
    arrayCapacity = capacity;
    arraySize = 0;
    return peopleArray;
}

int addPerson(char *name, unsigned short birthYear, unsigned char birthDay, char gender) {
    if (arraySize == arrayCapacity) {
        return -1; // Array is full
    }

    // Generate unique id
    char id[ID_LEN];
    sprintf(id, "ID%d", arraySize + 1);

    // Add person to the array
    struct Person newPerson;
    strcpy(newPerson.name, name);
    strcpy(newPerson.id, id);
    newPerson.birthYear = birthYear;
    newPerson.birthDay = birthDay;
    newPerson.gender = gender;

    peopleArray[arraySize++] = newPerson;

    return 0;
}

int removePerson(char *id) {
    for (size_t i = 0; i < arraySize; i++) {
        if (strcmp(peopleArray[i].id, id) == 0) {
            // Shift elements to remove the person
            for (size_t j = i; j < arraySize - 1; j++) {
                peopleArray[j] = peopleArray[j + 1];
            }
            arraySize--;
            return 0;
        }
    }
    return -1; // Person not found
}

void readPerson() {
    char name[100];
    unsigned short birthYear;
    unsigned char birthDay;
    char gender;

    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter birth year: ");
    scanf("%hu", &birthYear);
    printf("Enter birth day: ");
    scanf("%hhu", &birthDay);
    printf("Enter gender (M/F): ");
    scanf(" %c", &gender);

    addPerson(name, birthYear, birthDay, gender);
}

int printPerson(char *id) {
    for (size_t i = 0; i < arraySize; i++) {
        if (strcmp(peopleArray[i].id, id) == 0) {
            printf("Name: %s\n", peopleArray[i].name);
            printf("ID: %s\n", peopleArray[i].id);
            printf("Birth Year: %hu\n", peopleArray[i].birthYear);
            printf("Birth Day: %hhu\n", peopleArray[i].birthDay);
            printf("Gender: %c\n", peopleArray[i].gender);
            return 0;
        }
    }
    return -1; // Person not found
}

int main() {
    initArray(100);

    // Test the functions here
    addPerson("John", 1990, 15, 'M');
    addPerson("Jane", 1985, 28, 'F');
    readPerson();

    printPerson("ID1");
    printPerson("ID2");
    printPerson("ID3");

    free(peopleArray);
    return 0;
}
