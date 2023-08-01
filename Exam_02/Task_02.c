// Да се направят 6 функции, с помощта на които да се сортира масив от автомобили (сравняващи функции каквито се подават в стандартната qsort()): 
// Сравнение по марка - възходящ лексикографски ред;
// Сравнение по марка - низходящ лексикографски ред;
// Сравнение по максимална скорост - възходящ ред;
// Сравнение по максимална скорост - низходящ ред;
// Сравнение по цена - възходящ ред.
// Сравнение по цена - низходящ ред.

// Да се направи функция, която да връща сравняваща функция, от тези които дефинирахме по-горе.
// int (*getComparator(int n))(const void*, const void*);
// Номерът на функцията n, да е между 1 и 6. При число различно от това, да се върне нулев указател.

// Да се създаде масив от 10 автомобила. Да се запълни с произволни стойности:
// Марка - [A-Z][a-z]{4,10}
// Максимална скорост - 100 - 300
// Цена - 1000.00 - 100 000.00

// Потребител да въведе от стандартния вход цяло число между 1 и 6, с което да избира начин на сортиране на масива от автомобили, като използва функцията getComparator().
// Сортирането да се извърши със стандартната функция qsort().
// Да се изведе сортираният масив в подходящ формат.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct car {
    char model[20];
    uint8_t maxspeed;
    double price;
} Car;

int compare_up_brand(const void* a, const void* b) {
    const Car* carA = (const Car*)a;
    const Car* carB = (const Car*)b;
    return strcmp(carA->model, carB->model);
}

int compare_down_brand(const void* a, const void* b) {
    const Car* carA = (const Car*)a;
    const Car* carB = (const Car*)b;
    return strcmp(carB->model, carA->model);
}

int compare_up_maxspeed(const void* a, const void* b) {
    const Car* carA = (const Car*)a;
    const Car* carB = (const Car*)b;
    return (int)(carA->maxspeed - carB->maxspeed);
}

int compare_down_maxspeed(const void* a, const void* b) {
    const Car* carA = (const Car*)a;
    const Car* carB = (const Car*)b;
    return (int)(carB->maxspeed - carA->maxspeed);
}

int compare_up_price(const void* a, const void* b) {
    const Car* carA = (const Car*)a;
    const Car* carB = (const Car*)b;
    return (carA->price > carB->price) - (carA->price < carB->price);
}

int compare_down_price(const void* a, const void* b) {
    const Car* carA = (const Car*)a;
    const Car* carB = (const Car*)b;
    return (carB->price > carA->price) - (carB->price < carA->price);
}

int (*getComparator(int n))(const void*, const void*) {
    switch (n) {
        case 1: return compare_up_brand;
        case 2: return compare_down_brand;
        case 3: return compare_up_maxspeed;
        case 4: return compare_down_maxspeed;
        case 5: return compare_up_price;
        case 6: return compare_down_price;
        default: return NULL;
    }
}

int main() {
    int n;
    printf("Enter a number between 1 and 6 to choose a sorting method:\n");
    scanf("%d", &n);

    if (n < 1 || n > 6) {
        printf("Invalid input. Please enter a number between 1 and 6.\n");
        return 1;
    }

    int num_cars = 10;
    Car cars[] = {
        {"Toyota", 200, 30000.00},
        {"BMW", 250, 45000.00},
        {"Ford", 180, 22000.00},
        {"Mercedes", 280, 55000.00},
        {"Honda", 190, 28000.00},
        {"Audi", 240, 50000.00},
        {"Chevrolet", 210, 32000.00},
        {"Nissan", 195, 29000.00},
        {"Volkswagen", 230, 38000.00},
        {"Hyundai", 175, 21000.00}
    };

    int (*compareFunc)(const void*, const void*) = getComparator(n);
    if (!compareFunc) {
        printf("Invalid comparator function selected.\n");
        return 1;
    }

    qsort(cars, num_cars, sizeof(Car), compareFunc);

    printf("Sorted cars:\n");
    for (int i = 0; i < num_cars; i++) {
        printf("Model: %s, Max Speed: %d, Price: %.2f\n", cars[i].model, cars[i].maxspeed, cars[i].price);
    }

    return 0;
}

