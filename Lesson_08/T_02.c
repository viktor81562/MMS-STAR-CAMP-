#include <stdio.h>
#include <math.h>

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
    double a, b, c;
    double area, perimeter;
    int ret;
    int scanFRes;

    while((scanFRes = scanf("%lf %lf %lf", &a, &b, &c)) != EOF && scanFRes == 3) {
    ret = triangle(a, b, c, &area, &perimeter);
    if (ret == 0)
    {
        printf("The area of the triangle is %f\n", area);
        printf("The perimeter of the triangle is %f\n", perimeter);
    } else {
        printf("Error\n");
    }

    }
    return 0;
}
