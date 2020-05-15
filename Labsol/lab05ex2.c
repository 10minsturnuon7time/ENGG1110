/**
 * ENGG1110 Problem Solving by Programming
 * Lab 05 Exercise 2
 * More on Prime Numbers
 */

#include <stdio.h>
#include <math.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    for (int x = a; x <= b; x++) {
        int sqrt_x = sqrt(x), x_is_prime = 1;
        for (int i=2; i <= sqrt_x; i++) {
            if (0 == x % i) {
                x_is_prime = 0;
                break;
            }
        }
        if (x_is_prime)
            printf("%d\n", x);
    }

    return 0;
}
