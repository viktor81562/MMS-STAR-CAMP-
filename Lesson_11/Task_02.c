#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
const A O = {0.0};

typedef struct A{
    double x;
    double y;
} A;

double dist(A a, A b) {
    double dX = a.x - b.x;
    double dY = a.y - b.y;
    return sqrt(dX * dX + dY * dY);
}

int cmp_x(const void* p1, const void* p2) {
   return (((A*)p1)->x - ((A*)p2) ->x) * 1000;
}

int cmp_y(const void* p1, const void* p2) {
   return (((A*)p2) ->y - ((A*)p1)->y) * 1000;
}

int compare_dist(const void* p1, const void* p2) {
    double dist1 = dist(*(A*)p1, O);
    double dist2 = dist(*(A*)p2, O);
    return (dist1-dist2)*1000;
}

void printArr(A arr[], size_t n){
    for (size_t i = 0; i < n; i++)
    {
        printf("%lf %lf %lf\n", arr[i].x, arr[i].y,dist(arr[i], O));
    }
    printf("\n");
}

int main(int argc, char* argv[]) {

    srand(time(NULL));
    A *a = (A*)malloc(sizeof(a)*10);


    for (size_t i = 0; i < 10; i++){
        a[i].x = (-1000 +rand() % 2001)/ 1000.;
        a[i].y = (-1000 +rand() % 2001)/ 1000.;
    }

    qsort(a, 10, sizeof(A),cmp_x);
    qsort(a, 10, sizeof(A),cmp_y);


    printArr(a,10);

    free(a);
    return 0;
}

