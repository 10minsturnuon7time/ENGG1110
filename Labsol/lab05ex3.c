/**
 * ENGG1110 Problem Solving by Programming
 * Lab 05 Exercise 3
 * Board Drawing Game
 */

#include <stdio.h>

int main() {
    int board_size, periods, printed;
    printf("Board size?\n");
    scanf("%d", &board_size);

    printf("Period?\n");
    scanf("%d", &periods);

    printed = 0;

    for (int i=0; i < board_size; i++) {
        for (int j=0; j < board_size; j++) {
            if ( (printed++) % periods)
                printf(".");
            else
                printf("@");
        }
        printf("\n");
    }

    return 0;
}
