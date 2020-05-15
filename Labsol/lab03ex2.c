/**
 * ENGG1110 Problem Solving by Programming
 * Lab 03 Exercise 2
 * Maximum and Minimum Values
 */

#if VERSION == 1

#include <stdio.h>

int main(void)
{
    int a, b, c, d;

    printf("Input 1:\n");
    scanf("%d", &a);

    printf("Input 2:\n");
    scanf("%d", &b);

    printf("Input 3:\n");
    scanf("%d", &c);

    printf("Input 4:\n");
    scanf("%d", &d);

    int max, min;

    if (a >= b && a >= c && a >= d) max = a;
    if (b >= a && b >= c && b >= d) max = b;
    if (c >= a && c >= b && c >= d) max = c;
    if (d >= a && d >= b && d >= c) max = d;

    if (a <= b && a <= c && a <= d) min = a;
    if (b <= a && b <= c && b <= d) min = b;
    if (c <= a && c <= b && c <= d) min = c;
    if (d <= a && d <= b && d <= c) min = d;

    printf("The minimum value is %d whereas the maximum value is %d.\n", min, max);

    return 0;
}

#elif VERSION == 2

#include <stdio.h>

int main(void)
{
    int x, min, max;

    printf("Input 1:\n");
    scanf("%d", &x);
    min = max = x;

    printf("Input 2:\n");
    scanf("%d", &x);
    if (x > max) max = x;
    if (x < min) min = x;

    printf("Input 3:\n");
    scanf("%d", &x);
    if (x > max) max = x;
    if (x < min) min = x;

    printf("Input 4:\n");
    scanf("%d", &x);
    if (x > max) max = x;
    if (x < min) min = x;

    printf("The minimum value is %d whereas the maximum value is %d.", min, max);

    return 0;
}

#endif // VERSION
