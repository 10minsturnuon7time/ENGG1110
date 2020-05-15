/**
 * ENGG1110 Problem Solving by Programming
 * Lab 13 Exercise 1 (Revision)
 * String Processing
 */
#define VERSION 1

#if VERSION == 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Insert a fragment into original string at a given position */
char strInsert(char original[], char fragment[], int position)
{
    int o_len = strlen(original);
    int f_len = strlen(fragment);

    char temp[1000];
    strcpy(temp, original); // back up original

    int pos = position;     // starting position
    if (position < 0)       pos = 0;
    if (position > o_len)   pos = o_len;
    int i;
    for (i = 0; i < f_len; i++)
        original[pos + i] = fragment[i];

    for (i = pos; i < o_len + 1; i++)
        original[f_len + i] = temp[i];

    return original;
}

/* starting point of this C program */
int main(void)
{
    char original[1000];
    char fragment[255];
    int pos;

    puts("Input original string:");
    fgets(original, 1000, stdin);
    while (isspace(original[strlen(original) - 1]))
        original[strlen(original) - 1] = '\0';

    puts("Input fragment string:");
    fgets(fragment, 255, stdin);
    while (isspace(fragment[strlen(fragment) - 1]))
        fragment[strlen(fragment) - 1] = '\0';

    puts("Input position:");
    scanf("%d", &pos);

    printf("BEFORE strInsert(), Original string: [%s]\n", original);
    printf("BEFORE strInsert(), Fragment string: [%s]\n", fragment);

    printf("strInsert return: [%s]\n", strInsert(original, fragment, pos));

    printf("AFTER strInsert(), Original string: [%s]\n", original);
    printf("AFTER strInsert(), Fragment string: [%s]\n", fragment);

    /* last statement of this C program */
    return 0;
}

#elif VERSION == 2

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Insert a fragment into original string at a given position */
char *strInsert(char *original, char *fragment, int position)
{
    if (position < 0)
        position = 0;

    if (position > strlen(original))
        position = strlen(original);

    // back up the latter part of the original string
    char backup[1000];
    char *start = original + position;
    strcpy(backup, start);

    // insert the fragment at the specified position
    int len = strlen(fragment);

    for (int i=0; i < len; i++)
        *start++ = *fragment++;

    char *back = backup;

    for (int i=0; i < strlen(backup)+1; i++)
        *start++ = *back++;

    return original;
}

/* starting point of this C program */
int main(void)
{
    char original[1000];
    char fragment[255];
    int pos;

    puts("Input original string:");
    fgets(original, 1000, stdin);
    while (isspace(original[strlen(original) - 1]))
        original[strlen(original) - 1] = '\0';

    puts("Input fragment string:");
    fgets(fragment, 255, stdin);
    while (isspace(fragment[strlen(fragment) - 1]))
        fragment[strlen(fragment) - 1] = '\0';

    puts("Input position:");
    scanf("%d", &pos);

    printf("BEFORE strInsert(), Original string: [%s]\n", original);
    printf("BEFORE strInsert(), Fragment string: [%s]\n", fragment);

    printf("strInsert return: [%s]\n", strInsert(original, fragment, pos));

    printf("AFTER strInsert(), Original string: [%s]\n", original);
    printf("AFTER strInsert(), Fragment string: [%s]\n", fragment);

    /* last statement of this C program */
    return 0;
}

#endif  // VERSION
