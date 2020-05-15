/**
 * ENGG1110 Problem Solving by Programming
 * Lab 13 Exercise 3 (Revision)
 * Audio array processing
 */

#include <stdio.h>

int main() {
    int n, left[100], right[100];

    printf("Number of sound samples?\n");
    scanf("%d", &n);

    printf("Left:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &left[i]);

    printf("Right:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &right[i]);

    printf("Output: ");
    for (int i = 0; i < n; i++) {
        int diff = left[i] - right[i];
        if (diff < -32768) diff = -32768;
        if (diff >  32767) diff =  32767;
        printf("%d%s", diff, i < n-1 ? " " : "");
    }
    return 0;
}
