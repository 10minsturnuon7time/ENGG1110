/**
 * ENGG1110 Problem Solving by Programming
 * Lab10 Exercise 1
 * Show Card Desktop
 */

/* include header file */
#include <stdio.h>

typedef struct card {
    char suit;   // 'S'pade / 'H'eart / 'C'lub / 'D'iamond
    int  rank;   // A (1) / 2 - 10 / J (11) / Q (12) / K (13);
    int  status; // covered (0) or flipped (1) or chosen (-1), etc.
} TypeCard;

void printCard(TypeCard aCard)
{
    if (aCard.status == 0)
        printf("XXX");
    else
    {
        switch (aCard.suit) {
            case 'S':
            case 'H':
            case 'C':
            case 'D':
                printf("%c", aCard.suit);
                break;
            default:
                printf("?");
        }
        switch (aCard.rank) {
            case  1: printf(" A"); break;
            case 11: printf(" J"); break;
            case 12: printf(" Q"); break;
            case 13: printf(" K"); break;
            default:
                if (aCard.rank >= 2 && aCard.rank <= 10)
                    printf("%2d", aCard.rank);
                else
                    printf("??");
        }
    }
    return;
}

void showDesktop(TypeCard desktop[4][14])
{
    int row, col;
    for (row = 0; row < 4; row++)
    {
        for (col = 1; col <= 13; col++)
        {
            printCard(desktop[row][col]);
            printf("\t");
        }
        printf("\n");
    }
}

void swapCardPair(TypeCard desktop[4][14], int card1row, int card1col, int card2row, int card2col)
{
    TypeCard tmp = desktop[card1row][card1col];
    desktop[card1row][card1col] = desktop[card2row][card2col];
    desktop[card2row][card2col] = tmp;
}

void flipAllCards(TypeCard desktop[4][14])
{
    int row, col;

    for (row = 0; row < 4; row++)
        for (col = 1; col <= 13; col++)
            desktop[row][col].status = 1;
}

/* starting point of this C program */
int main(void)
{
    /* given initial card arrangement, DO NOT modify */
    TypeCard desktop[4][14] = {
        {{}, {'S', 1}, {'S', 2}, {'S', 3}, {'S', 4}, {'S', 5}, {'S', 6}, {'S', 7}, {'S', 8}, {'S', 9}, {'S', 10, 1 /* flipped */}, {'S', 11}, {'S', 12}, {'S', 13}},
        {{}, {'H', 1}, {'H', 2}, {'H', 3}, {'H', 4}, {'H', 5}, {'H', 6}, {'H', 7}, {'H', 8}, {'H', 9}, {'H', 10, 1 /* flipped */}, {'H', 11}, {'H', 12}, {'H', 13}},
        {{}, {'C', 1}, {'C', 2}, {'C', 3}, {'C', 4}, {'C', 5}, {'C', 6}, {'C', 7}, {'C', 8}, {'C', 9}, {'C', 10, 1 /* flipped */}, {'C', 11}, {'C', 12}, {'C', 13}},
        {{}, {'D', 1}, {'D', 2}, {'D', 3}, {'D', 4}, {'D', 5}, {'D', 6}, {'D', 7}, {'D', 8}, {'D', 9}, {'D', 10, 1 /* flipped */}, {'D', 11}, {'D', 12}, {'D', 13}}
    };

    int row, col;

    // given code: rearrange all row 2 cards
    row = 2;
    for (col = 1; col <= 13/2; col++)
        swapCardPair(desktop, row, col, row, 13 - col + 1);

    // given code: flip open all row 2 cards
    row = 2;
    for (col = 1; col <= 13; col++)
        desktop[row][col].status = 1;

    // show initial desktop
    printf("Initial desktop:\n");
    showDesktop(desktop);

    // Enter your code here.
    int i;
    for (i = 0; i < 5; i++)
    {
        int card1row, card1col;
        int card2row, card2col;
        scanf("%d%d", &card1row, &card1col);
        desktop[card1row][card1col].status = 1;
        printf("User chose 1st card (%d,%2d) and it is ", card1row, card1col);
        printCard(desktop[card1row][card1col]);
        printf("\n");

        scanf("%d%d", &card2row, &card2col);
        desktop[card2row][card2col].status = 1;
        printf("User chose 2nd card (%d,%2d) and it is ", card2row, card2col);
        printCard(desktop[card2row][card2col]);
        printf("\n");

        printf("After flipping and swapping:\n");
        swapCardPair(desktop, card1row, card1col, card2row, card2col);
        showDesktop(desktop);
    }

    printf("Flipping open all cards:\n");
    flipAllCards(desktop);
    showDesktop(desktop);

    /* last statement of this C program */
    return 0;
}
