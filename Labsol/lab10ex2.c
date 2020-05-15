/**
 * ENGG1110 Problem Solving by Programming
 * Lab10 Exercise 2
 * Simulating an ATM Menu
 */
#define VERSION 1

#if VERSION == 1

#include <stdio.h>
int main()
{
    int c;
    int amount[] = {0, 2000, 1000, 500, 100};
    printf("Welcome to CUHK ATM.\n");
    while (1) {
        printf( "Please input your choice:\n"
                "1. $2000\n"
                "2. $1000\n"
                "3. $500\n"
                "4. $100\n"
                "0. Quit\n" );
        scanf("%d", &c);
        if (c == 0)
            break;
        if (c > 0 && c <= 4) {
            printf("Please take $%d.\n", amount[c]);
            break;
        }
        if (c % 100 == 0) {
            printf("Please take $%d.\n", c);
            break;
        }
        printf("We cannot fulfill your choice, sorry.\n");
    }
    printf("Thanks for using CUHK ATM system.");
    return 0;
}

#elif VERSION == 2

#include <stdio.h>

int main()
{
    int i, j, choice, okay = 0;

    printf("Welcome to CUHK ATM.\n");
    while (!okay)
    {
        printf("Please input your choice:\n1. $2000\n2. $1000\n3. $500\n4. $100\n0. Quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Please take $2000.\n");
            okay = 1;
            break;
        case 2:
            printf("Please take $1000.\n");
            okay = 1;
            break;
        case 3:
            printf("Please take $500.\n");
            okay = 1;
            break;
        case 4:
            printf("Please take $100.\n");
            okay = 1;
            break;
        case 0:
            okay = 1;
            break;
        default:
            if (choice % 100 == 0)
            {
                printf("Please take $%d.\n", choice);
                okay = 1;
                break;
            }
            else
                printf("We cannot fulfill your choice, sorry.\n");
        }
    }
    printf("Thanks for using CUHK ATM system.");
    return 0;
}

#endif // VERSION
