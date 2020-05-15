/**
 * ENGG1110 Problem Solving by Programming
 * Lab 06 Exercise 2
 * Compute the ranking order of an input
 */

#include <stdio.h>

#define SIZE 10

int main() {
    int a[SIZE], k = 1;
    for (int i=0; i<SIZE; i++)
        scanf("%d", &a[i]);

    for (int i=0; i<SIZE-1; i++)
        if (a[SIZE-1] > a[i])
            k++;

    printf("%d", k);
    return 0;
}
