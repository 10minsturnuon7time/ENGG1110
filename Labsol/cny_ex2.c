/**
 * ENGG1110 Problem Solving by Programming
 * Chinese New Year Exercise 2
 * Beautiful Sequence
 */

#include <stdio.h>
int main()
{
    int n = 3;
    // insert code here to get n from user
    printf("Input n:\n");
    scanf("%d", &n);

    if (n >= 2 && n <= 40) {
        // first 2 terms are simple - it's defined to be 0 and 1!
        printf("0,1");
        // 3rd term onward...
        int lastTerm = 1;       // last term is 2nd, 2nd term is 1, right?
        int beforeLastTerm = 0; // term before last term is 1st, 1st term is zero, right?
        int nextterm;
        int i;
        for (i = 2; i < n; ++i)
        {
            printf(",%d", lastTerm + beforeLastTerm);
            // insert code here to print each subsequent term correctly
            nextterm = beforeLastTerm + lastTerm;
            beforeLastTerm = lastTerm;
            lastTerm = nextterm;
        }
        printf("\nBeautiful!");
    }
    else {
        printf("out of range");
    }
    return 0;
}
