#include <stdio.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*)) {
    char* array = (char*)arr;
    void* max = arr;
    for (size_t i = 0; i < n; i++)
    {
        if (cmp(array + i * elem_s, max) == -1) {
            max = array + i * elem_s;
        }
    }
    return max;
}

typedef struct Point {
    double x;
    double y;
    double z;
} Point;

void* findMax(void* arr, size_t n, size_t elem_s, int (*cmp)(const void*, const void*));

int compare_uint64(const void* a, const void* b) {
    uint64_t num_a = *(const uint64_t*)a;
    uint64_t num_b = *(const uint64_t*)b;

    return (num_a > num_b) ? -1 : ((num_a < num_b) ? 1 : 0);
}

int compare_point(const void* a, const void* b) {
    const Point* point_a = (const Point*)a;
    const Point* point_b = (const Point*)b;

    double distance_a = point_a->x * point_a->x + point_a->y * point_a->y + point_a->z * point_a->z;
    double distance_b = point_b->x * point_b->x + point_b->y * point_b->y + point_b->z * point_b->z;

    return (distance_a > distance_b) ? -1 : ((distance_a < distance_b) ? 1 : 0);
}

typedef struct Human {
    double weight_kg;
    uint16_t height_cm;
} Human;

int compare_human(const void* a, const void* b) {
    const Human* human_a = (const Human*)a;
    const Human* human_b = (const Human*)b;

    double bmi_a = human_a->weight_kg / ((human_a->height_cm / 100.0) * (human_a->height_cm / 100.0));
    double bmi_b = human_b->weight_kg / ((human_b->height_cm / 100.0) * (human_b->height_cm / 100.0));

    return (bmi_a < bmi_b) ? -1 : ((bmi_a > bmi_b) ? 1 : 0);
}

int main() {

    uint64_t uint64_arr[] = { 10, 20, 30, 40, 50 };
    size_t uint64_size = sizeof(uint64_arr) / sizeof(uint64_arr[0]);
    size_t uint64_elem_s = sizeof(uint64_t);
    uint64_t* max_uint64 = (uint64_t*)findMax(uint64_arr, uint64_size, uint64_elem_s, compare_uint64);
    printf("Max uint64_t: %u", *max_uint64);

    Point point_arr[] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    size_t point_size = sizeof(point_arr) / sizeof(point_arr[0]);
    size_t point_elem_s = sizeof(Point);
    Point* max_point = (Point*)findMax(point_arr, point_size, point_elem_s, compare_point);
    printf("Max Point: (%lf, %lf, %lf)\n", max_point->x, max_point->y, max_point->z);

    Human human_arr[] = { {80, 180}, {70, 170}, {90, 190} };
    size_t human_size = sizeof(human_arr) / sizeof(human_arr[0]);
    size_t human_elem_s = sizeof(Human);
    Human* lowest_bmi_human = (Human*)findMax(human_arr, human_size, human_elem_s, compare_human);
    printf("Lowest BMI Human: Weight %.2lf kg, Height %d cm\n", lowest_bmi_human->weight_kg, lowest_bmi_human->height_cm);

    return 0;
}
