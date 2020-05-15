/**
 * ENGG1110 Problem Solving by Programming
 * Lab 06 Exercise 1
 * Using array to store variable number of input
 */

#include <stdio.h>

#define SIZE 10

int main() {
    int a[SIZE], input, i, j;

    for (i = 0; i < SIZE;) {
        scanf("%d", &input);
        if (input > 0)
            a[i++] = input;
        else if (input == 0)
            break;
    }

    for (j = i-1; j >= 0; j--)
        printf("%d ", a[j]);

    return 0;
}
