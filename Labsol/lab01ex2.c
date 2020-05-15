/**
 * ENGG1110 Problem Solving by Programming
 * Lab 01 Exercise 2
 * Sphere surface area and volume calculation
 */

#include <stdio.h>
#include <math.h>

/* starting point of this C program */
int main(void)
{
    const double PI = 3.14159265;   // a math constant
    double radius, area, volume;    // variables


    /* prompt and then read radius from user */
    printf("Please enter radius:\n");
    scanf("%lf", &radius);

    /* calculation */
    area = 4 * PI * radius * radius;

    volume = 4 / 3  * PI * pow(radius, 3);

    double volume1, volume2;

    volume1 = 4.0 / 3;
    volume2 = 4 / 3;

    printf("Volume1: %.4f\n", volume1);
    printf("Volume2: %.4f\n", volume2);

    /* print results */
    printf("Area: %.4f\n", area);
    printf("Volume: %.4f\n", volume);

    return 0;
}
