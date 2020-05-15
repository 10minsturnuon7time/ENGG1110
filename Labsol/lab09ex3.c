/**
 * ENGG1110 Problem Solving by Programming
 * Lab09 Exercise 3
 * ROT18 Encoding - a combination of ROT5 and ROT13
 */

#define VERSION 2

#if VERSION == 1

#include <stdio.h>

int main(void)
{
    while (1) {
        char c = getchar();
        if ('.' == c)
            break;
        if (c >= 'A' && c <= 'Z')
            putchar('A' + (c - 'A' + 13) % 26);
        else
        if (c >= 'a' && c <= 'z')
            putchar('a' + (c - 'a' + 13) % 26);
        else
        if (c >= '0' && c <= '9')
            putchar('0' + (c - '0' + 5) % 10);
        else
            putchar(c);
    }
    return 0;
}

#elif VERSION == 2


#include <stdio.h>

int main(void)
{
    while (1) {
        char c = getchar();
        if (c == '.')
            break;
        if ('A' <= c && c <= 'M')
            putchar(c + 13);
        else if ('N' <= c && c <= 'Z')
            putchar(c - 13);
        else if ('a' <= c && c <= 'm')
            putchar(c + 13);
        else if ('n' <= c && c <= 'z')
            putchar(c - 13);
        else if ('0' <= c && c <= '4')
            putchar(c + 5);
        else if ('5' <= c && c <= '9')
            putchar(c - 5);
        else
            putchar(c);
    }
    return 0;
}

#endif // VERSION

