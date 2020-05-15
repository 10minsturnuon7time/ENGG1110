/**
 * ENGG1110 Problem Solving by Programming
 * Lab 04 Exercise 3
 * Setting Up a Digital Lock PIN code
 */

#include <stdio.h>

const int PIN_LEN = 4;
const int KEY_DIGIT = 8;

int main(void)
{
    int err1 = 0;   // assume PIN code has 4 digits
    int err2 = 0;   // assume PIN code contains digits '1' to '8' only
    int err3 = 1;   // assume PIN code is missing '8'

    int pin, len = 0;

    printf("Input PIN code:\n");
    scanf("%d", &pin);

    while (1) {
        int digit = pin % 10;
        len++;
        pin /= 10;

        if (digit < 1 || digit > KEY_DIGIT)
            err2 = 1;   // some digit other than 1-8 found

        if (digit == KEY_DIGIT)
            err3 = 0;   // clear the missing '8' error

        if (len > PIN_LEN) {
            err1 = 1;   // PIN code too long
            break;
        }

        if (pin == 0)
            break;
    }

    if (len < PIN_LEN) {
        err1 = 1;   // PIN code too short
    }

    if (!err1 && !err2 && !err3)
        printf("OK!");
    if (err1 == 1)
        printf("PIN code must have %d-digits\n", PIN_LEN);
    if (err2 == 1)
        printf("PIN code must contain digits '1' to '%d' only\n", KEY_DIGIT);
    if (err3 == 1)
        printf("PIN code must have at least one '%d'", KEY_DIGIT);

    return 0;
}
