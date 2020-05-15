/**
 * ENGG1110 Problem Solving by Programming
 * Lab 04 Exercise 1
 * More on Air Quality Health Index (AQHI)
 */

#include <stdio.h>

int main() {
    double a = 0.0;
    int n;
    printf("Please input number of days:\n");
    scanf("%d", &n);
    for (int i=1; i<=n; i++) {
        double x;
        printf("Please input AQHI for Day %d:\n", i);
        scanf("%lf", &x);
        a += x;
    }
    a /= n;
    if (a < 4.5)
        printf("AQHI of %.1f refers to LOW Health Risk Category.\n", a);
    else if (a < 7.5)
        printf("AQHI of %.1f refers to MODERATE Health Risk Category.\n", a);
    else if (a < 8.5)
        printf("AQHI of %.1f refers to HIGH Health Risk Category.\n", a);
    else if (a < 10.0)
        printf("AQHI of %.1f refers to VERY HIGH Health Risk Category.\n", a);
    else
        printf("AQHI of %.1f refers to SERIOUS Health Risk Category.\n", a);
}
