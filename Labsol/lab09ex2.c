/**
 * ENGG1110 Problem Solving by Programming
 * Lab 09 Exercise 2
 * Pass-Code Generation
 */

#define VERSION 1

#if VERSION == 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[21];
    int count = 0, i;
    fgets(str, 21, stdin);
    for (i = strlen(str)-1; i >= 0; i--) {
        if (!isalpha(str[i]))
            count++;
        putchar(str[i]);
    }
    putchar('\n');
    if (count > 4)
        for (i = strlen(str)-1; i >= 0; i--) {
            if (!isalpha(str[i]))
                putchar(str[i]);
        }
    else
        printf("Your pass-code is too short.\n");
    return 0;
}

#elif VERSION == 2

#include <stdio.h>
#include <string.h>

int is_special(char a)
{
    if ((a >= 33 && a <= 47) || (a >= 58  && a <= 64) ||
        (a >= 91 && a <= 96) || (a >= 123 && a <= 126))
        return 1;
    return 0;
}

int is_digit(char a)
{
    return (a >= 48 && a <= 57) ? 1 : 0;
}

int main(void)
{
    char str[21], out[21];
    int i, length, count = 0;
    scanf("%s", str);
    for (i = strlen(str)-1; i >= 0; i--){
        printf("%c", str[i]);
        if (is_digit(str[i]) || is_special(str[i]))
            out[count++] = str[i];
    }
    out[count] = '\0';
    printf("\n");
    if(count >= 5)
        printf("%s\n", out);
    else
        printf("Your pass-code is too short.\n");
    return 0;
}

#endif // VERSION
