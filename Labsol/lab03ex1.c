/**
 * ENGG1110 Problem Solving by Programming
 * Lab 03 Exercise 1
 * Magic number - simple condition
 */

#if VERSION == 1

#include <stdio.h>

int main(void)
{
    const int MAGIC = 900;
    int n;
    printf("Input:\n");
    scanf("%d", &n);
    
    if (MAGIC >= n)
        printf("Magic number is greater than or equal to yours\n");
    else
        printf("Magic number is smaller\n");

    return 0;
}

#elif VERSION == 2

#include <stdio.h>

#define MAGIC 900

int main(void)
{
    int n;
    printf("Input:\n");
    scanf("%d", &n);
    printf( MAGIC >= n ?
           "Magic number is greater than or equal to yours\n" :
           "Magic number is smaller\n"
           );
    return 0;
}

#endif // VERSION
