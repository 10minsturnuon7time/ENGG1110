/**
 * ENGG1110 Problem Solving by Programming
 * Chinese New Year Exercise 1
 * Lesson Reminder
 */

#include <stdio.h>

int main(){

    printf("Please enter the weekday for your lessons.\n");
    printf("(0 for Sunday, 1 for Monday, ..., 6 for Saturday)\n");
    int weekday;
    scanf("%d", &weekday);

    printf("Great, here are the days for your lessons (dd/mm/yyyy):\n");

    int month = 1, day = 6;
    day += weekday;
    while (month < 4 || month == 4 && day <= 18) {
        if (day > 31 && (month == 1 || month == 3)) {
            day -= 31;
            month++;
        }
        else if (day > 28 && month == 2) {
            day -= 28;
            month++;
        }
        else {
            printf("%02d/%02d/2019\n", day, month);
            day += 7;
        }
    }
    return 0;
}
