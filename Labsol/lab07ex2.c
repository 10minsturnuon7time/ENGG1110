/**
 * ENGG1110 Problem Solving by Programming
 * Lab07 Exercise 2
 * Binary Number Adder
 */

#include <stdio.h>

// Convert a decimal number to a binary number
void convertDecToBin(double num, int len, int binary[])
{
    // this function STORES conversion result in binary[]
    // the content of the array parameter will be CHANGED
    double tmp = num;
    binary[0] = 0;
    for (int i = 0; i < len; i++) {
        tmp *= 2;
        binary[i + 1] = tmp >= 1;
        if (tmp >= 1) {
            tmp -= 1;
        }
    }

}


// Binary number addition
void addTwoBinary(int binary1[], int binary2[], int sum[])
{
    // you should NOT modify the contents in binary1[] and binary2[]
    // you should STORE your result in sum[]
    int carry = 0;
    for (int i=20; i>=0; i--) {
        sum[i] = binary1[i] + binary2[i] + carry;
        if (carry = sum[i] > 1)
            sum[i] -= 2;
    }

}

void printBinary(int bin[], int len) {
    printf("%d.", bin[0]);
    for (int i=1; i<len; i++)
        printf("%d", bin[i]);
    printf("\n");
}

int main(void)
{
    int binary1[30], binary2[30], sum[30];

    double num1, num2;
    int i;

    scanf("%lf %lf", &num1, &num2);

    // call convertDecToBin
    convertDecToBin(num1, 21, binary1);
    convertDecToBin(num2, 21, binary2);

    // print sum of these binary binary digits
    addTwoBinary(binary1, binary2, sum);

    printf("num1 is ");
    printBinary(binary1, 21);

    printf("num2 is ");
    printBinary(binary2, 21);

    printf("sum is ");
    printBinary(sum, 21);

    return 0;
}
