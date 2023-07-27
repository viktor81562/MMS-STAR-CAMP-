#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int triangle(double a, double b, double c, double *area, double *perimeter)
{

    int P, HP;
    if (a <= 0 || b <= 0 || c <= 0)
    {
        printf("there is no triangle like this one! ");
        return -1;
    }
    else if (a + b < c || a + c < b || b + c < a)
    {
        printf("there is no triangle like this oneeeeeeeeee! ");
        return -1;
    }
    else
    {

        P = a + b + c;
        HP = P / 2;
        *area = sqrt(HP * (HP - a) * (HP - b) * (HP - c));
        *perimeter = P;
        return 0;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "invalid input\n");
        return -1;
    }
    double a, b, c;
    double area, perimeter;
    int ret;
    int scanFRes;

    a = atof(argv[1]);
    b = atof(argv[2]);
    c = atof(argv[3]);

   
    ret = triangle(a, b, c, &area, &perimeter);
    if (ret == 0)
    {
        printf("The area of the triangle is %f\n", area);
        printf("The perimeter of the triangle is %f\n", perimeter);
    } else {
        printf("Error\n");
    }
    

    
    return 0;
}