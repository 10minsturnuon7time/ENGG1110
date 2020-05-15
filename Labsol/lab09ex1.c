/**
 * ENGG1110 Problem Solving by Programming
 * Lab 09 Exercise 1
 * Letter Conversion
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str[21];
    int count = 0;
    fgets(str, 21, stdin);
    for (int i = 0; i < strlen(str); i++) {
        if (isupper(str[i]))
            count++;
        str[i] = tolower(str[i]);
    }
    printf("%s%d\n", str, count);
    return 0;
}
