/**
 * ENGG1110 Problem Solving by Programming
 * Lab 02 Exercise 3
 * Date time format conversion
 */

#include <stdio.h>

int main(void)
{
    unsigned int n;
    scanf("%u", &n);    // input an unsigned integer value

    int seconds =  n % 60;
    int minutes = (n / 60) % 60;
    int hours   = (n / 3600) % 24;
    int days    =  n / (3600 * 24);

    printf("%d Days %d Hours %d Minutes %d Seconds", days, hours, minutes, seconds);

    return 0;
}
