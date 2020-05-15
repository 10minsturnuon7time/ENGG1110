/**
 * ENGG1110 Problem Solving by Programming
 * Lab 03 Exercise 3
 * Air Quality Health Index (AQHI)
 */

#define VERSION == 1

#if VERSION == 1

#include <stdio.h>

int main(void)
{
    double index;
    printf("Please input AQHI:\n");
    scanf("%lf", &index);

    if (index < 4.5)
        printf("AQHI of %.1f refers to LOW Health Risk Category.", index);
    else if (index < 7.5)
        printf("AQHI of %.1f refers to MODERATE Health Risk Category.", index);
    else if (index < 8.5)
        printf("AQHI of %.1f refers to HIGH Health Risk Category.", index);
    else if (index < 10.0)
        printf("AQHI of %.1f refers to VERY HIGH Health Risk Category.", index);
    else
        printf("AQHI of %.1f refers to SERIOUS Health Risk Category.", index);

    return 0;
}

#elif VERSION == 2

#include <stdio.h>

int main(void)
{
    double x;
    char* s;

    printf("Please input AQHI:\n");
    scanf("%lf", &x);

    if (x < 4.5)        s = "LOW";
    else if (x < 7.5)   s = "MODERATE";
    else if (x < 8.5)   s = "HIGH";
    else if (x < 10)    s = "VERY HIGH";
    else                s = "SERIOUS";

    printf("AQHI of %.1f refers to %s Health Risk Category.", x, s);
    return 0;
}

#endif // VERSION
