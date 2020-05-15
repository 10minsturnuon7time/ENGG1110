/**
 * ENGG1110 Problem Solving by Programming
 * Lab 04 Exercise 2
 * Magic Number Game
 */

#include <stdio.h>
#include <stdlib.h>

const int MAX_TIMES = 5;
const int MAGIC = 445;

int main() {
    int i, guess;
    for (i=1; i <= MAX_TIMES; i++) {
        printf("Guess:\n");
        scanf("%d", &guess);
        if (MAGIC == guess) {
            printf("Bingo! You made it in %d guess(es)!", i);
            break;
        }
        else
        if (guess - MAGIC >= 10)
            printf("Too large!\n");
        else
        if (MAGIC - guess >= 10)
            printf("Too small!\n");
        else
            printf("Close!\n");
    }
    if (i > MAX_TIMES)
        printf("You run out of chances. Game Over!");

    return 0;
}
