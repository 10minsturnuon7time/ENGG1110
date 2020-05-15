/**
 * ENGG1110 Problem Solving by Programming
 * Lab 02 Exercise 4
 * Water Supplies
 */

#define VERSION 4

#if VERSION == 1

#include <stdio.h>
#include <math.h>

int main(void)
{
    unsigned int n, x;

    printf("Total amount of water:\n");
    scanf("%u", &n);
    printf("Barrel capacity:\n");
    scanf("%u", &x);

    printf("%d barrels are needed\n", (int) ceil( (double) n / x));

    return 0;
}

#elif VERSION == 2

#include <stdio.h>

int main(void)
{
    unsigned int n, x;

    printf("Total amount of water:\n");
    scanf("%u", &n);
    printf("Barrel capacity:\n");
    scanf("%u", &x);

    int m = n / x;
    if (n % x != 0) m++;
    printf("%d barrels are needed\n", m);

    return 0;
}


#elif VERSION == 3

int main(void)
{
    unsigned int n, x;

    printf("Total amount of water:\n");
    scanf("%u", &n);
    printf("Barrel capacity:\n");
    scanf("%u", &x);

    printf("%d barrels are needed", n/x + (n % x ? 1 : 0) );

    return 0;
}

#elif VERSION == 4

int main(void)
{
    unsigned int n, x;

    printf("Total amount of water:\n");
    scanf("%u", &n);
    printf("Barrel capacity:\n");
    scanf("%u", &x);

    printf("%d barrels are needed", (n + x - 1) / x );

    return 0;
}

#endif // VERSION
