/**
 * ENGG1110 Problem Solving by Programming
 * Lab 11 Exercise 1
 * Palindrome Checker
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * This function returns 1 if str is a palindrome and 0 otherwise.
 * b indexes the beginning character you would access in the str array.
 * e indexes the ending character you would access in the str array.
 */
int is_palindrome(char str[], int b, int e)
{
    // Modify this function body to make it work for strings with whitespace,
    // punctuation marks and with upper-case or lower-case letters.

    if ( e <= b )
        return 1;

    if ( (isalpha(str[b]) || isdigit(str[b])) &&
        !(isalpha(str[e]) || isdigit(str[e])) )
        return is_palindrome(str, b, e-1);

    if (!(isalpha(str[b]) || isdigit(str[b])) &&
         (isalpha(str[e]) || isdigit(str[e])) )
        return is_palindrome(str, b+1, e);

    if ( (isalpha(str[b]) || isdigit(str[b])) &&
         (isalpha(str[e]) || isdigit(str[e])) ) {
        if ( tolower(str[b]) != tolower(str[e]) )
            return 0;
    }

    return is_palindrome(str, b+1, e-1);
}

int main(void)
{
    char str[100];
    fgets(str, 100, stdin);
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[--len] = '\0';  // remove the newline character
    }
    // len now stores the length of input string excluding \n

    printf("String \"%s\" is%s a palindrome.\n",
        str, is_palindrome(str, 0, len-1) ? "" : " NOT");
    return 0;
}
