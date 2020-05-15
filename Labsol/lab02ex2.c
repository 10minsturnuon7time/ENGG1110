/**
 * ENGG1110 Problem Solving by Programming
 * Lab 02 Exercise 2
 * Secret of your mobile phone (15-digit IMEI number check)
 */

#define VERSION 1

#if VERSION == 1

#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
          &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o);

    int b2, d2, f2, h2, j2, l2, n2;
    b2 = (b * 2) / 10 + (b * 2) % 10;
    d2 = (d * 2) / 10 + (d * 2) % 10;
    f2 = (f * 2) / 10 + (f * 2) % 10;
    h2 = (h * 2) / 10 + (h * 2) % 10;
    j2 = (j * 2) / 10 + (j * 2) % 10;
    l2 = (l * 2) / 10 + (l * 2) % 10;
    n2 = (n * 2) / 10 + (n * 2) % 10;

    int sum = b2 + d2 + f2 + h2 + j2 + l2 + n2; // sum even digits
    sum += a + c + e + g + i + k + m + o;       // sum odd digits
    printf("%d\n", sum % 10);

    return 0;
}

#elif VERSION == 2

#include <stdio.h>

int main(void)
{
    int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
          &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n, &o);

    int b2 = 2 * b;  if (b2 > 9) b2 -= 9;
    int d2 = 2 * d;  if (d2 > 9) d2 -= 9;
    int f2 = 2 * f;  if (f2 > 9) f2 -= 9;
    int h2 = 2 * h;  if (h2 > 9) h2 -= 9;
    int j2 = 2 * j;  if (j2 > 9) j2 -= 9;
    int l2 = 2 * l;  if (l2 > 9) l2 -= 9;
    int n2 = 2 * n;  if (n2 > 9) n2 -= 9;

    int sum = a + b2 + c + d2 + e + f2 + g + h2 + i + j2 + k + l2 + m + n2 + o;
    printf("%d\n", sum % 10);

    return 0;
}

#elif VERSION == 3

#include <stdio.h>

int main(void)
{
    int a[15], i, sum = 0;
    printf("Enter digits:\n");
    for (i = 0; i < 15; i++) {
        scanf("%d", &a[i]);
        if (i % 2 != 0) {
            a[i] = 2 * a[i];
            a[i] = a[i] / 10 + a[i] % 10;
        }
        sum += a[i];
    }
    printf("%d\n", sum % 10);
    return 0;
}

#elif VERSION == 4

#include <stdio.h>

const int N = 15;   // number of digits

int main(void)
{
    printf("Enter digits:\n");
    const int EVEN = (N % 2 == 0) ? 1 : 0; // is N even?
    int a[N], i, sum = 0;
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    for (i = N-1; i >= 0; i--) {
        int k = (i % 2 == 0);
        if (k == EVEN) {
            a[i] = 2 * a[i];
            a[i] = a[i] / 10 + a[i] % 10;
        }
        sum += a[i];
    }
    printf("%d\n", sum % 10);
    return 0;
}

#endif // VERSION
