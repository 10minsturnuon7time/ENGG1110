/**
 * ENGG1110 Problem Solving by Programming
 * Lab 02 Exercise 1
 * Discriminant of a cubic equation
 */

#define VERSION 2

#if VERSION == 1

#include <stdio.h>

int main(void)
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);

    int delta;
    delta = b * b * c * c;
    delta -= 4 * a * c * c * c;
    delta -= 4 * b * b * b * d;
    delta -= 27 * a * a * d * d;
    delta += 18 * a * b * c * d;

    printf("%d\n", delta);

    return 0;
}

#elif VERSION == 2


#include <stdio.h>
#include <math.h>

int main(void)
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int delta = pow(b, 2) * pow(c, 2) - 4 * a * pow(c, 3)
                - 4 * pow(b, 3) * d - 27 * pow(a, 2) * pow(d, 2)
                + 18 * a * b * c * d;
    printf("%d\n", delta);
    return 0;
}

#endif // VERSION
