/**
 * ENGG1110 Problem Solving by Programming
 * Lab 05 Exercise 1
 * Prime Numbers
 */

#define VERSION 1

#if VERSION == 1

#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);

    for (int i=2; i < x; i++) {
        if (0 == x % i) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}

#elif VERSION == 2

#include <stdio.h>
#include <math.h>

int main() {
    int x;
    scanf("%d", &x);
    int sqrt_x = sqrt(x);
    for (int i=2; i <= sqrt_x; i++) {
        if (0 == x % i) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}

#endif // VERSION
