#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct
{
    double x;
    double y;

} P;

double dist(P one, P two)
{
    return sqrt((one.x - two.x) * (one.x - two.x) + (one.y - two.y) * (one.y - two.y));
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {

        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    unsigned N;

    if (sscanf(argv[1], "%u", &N) != 1)
    {
        fprintf(stderr, "invalid inputtt");
        return 1;
    }

    P points[N];

    for (size_t i = 0; i < N; i++)
    {
        points[i].x = (double)(rand() % 1000) / 1000;
        points[i].y = (double)(rand() % 1000) / 1000;
    }

    for (size_t i = 0; i < N; i++)
    {
        printf("%f %f\n\n\n\n\n", (*(points + i)).x, (*(points + i)).y);
    }
    for (size_t j = 0; j < N; j++)
    {
        for (size_t i = j+1; i < N; i++)
        {
            printf("The diff between %lf and %lf is: %lf \n", (*(points + j)).x, (*(points + i)).y, dist(points[j], points[i]));
        }
    }

    return 0;
}