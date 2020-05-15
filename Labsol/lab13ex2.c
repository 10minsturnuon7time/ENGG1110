/**
 * ENGG1110 Problem Solving by Programming
 * Lab 13 Exercise 2 (Revision)
 * 2D Array Processing
 */

#include <stdio.h>

int main() {
    int rows, cols, i, j, sum;
    printf("Rows:\n");
    scanf("%d", &rows);
    printf("Columns:\n");
    scanf("%d", &cols);
    printf("Input %dx%d elements:\n", rows, cols);

    int matrix[10][10];
    for (i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);

    printf("Row sums:\n");
    for (i = 0; i < rows; i++) {
        sum = 0;
        for (int j = 0; j < cols; j++)
            sum += matrix[i][j];
        printf("%d\n", sum);
    }
    printf("Column sums:\n");
    for (j = 0; j < cols; j++) {
        sum = 0;
        for (i = 0; i < rows; i++)
            sum += matrix[i][j];
        printf("%d%s", sum, j < cols-1 ? " " : "");
    }
    printf("\n");
    return 0;
}
