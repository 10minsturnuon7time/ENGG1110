/**
 * ENGG1110 Problem Solving by Programming
 * Lab 07 Exercise 1
 * GCD & LCM
 */

#include <stdio.h>

// This function returns the GCD of x and y
// You don't have to modify this function
int gcd(int x, int y)
{
    // This function implements the Euclidean Algorithm for finding GCD
    // See: https://en.wikipedia.org/wiki/Euclidean_algorithm
    while (y != 0) {
        int tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

// Complete the implementation of this function so that it returns the
// LCM of x and y
int lcm(int x, int y)
{
    return (x * y) / gcd(x,y);
}

// Complete the implementation of the main function.
int main(void)
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    printf("GCD is %d\n", gcd( gcd( gcd(a, b), c), d) );
    printf("LCM is %d",   lcm( lcm( lcm(a, b), c), d) );

    return 0;
}
