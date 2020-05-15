/**
 * ENGG1110 Problem Solving by Programming
 * Lab 08 Exercise 1
 * Symmetric Matrix Checking
 */

#include <stdio.h>

int checkSymmetricMatrix( int matrix[16][16], int size )
{

    int success = 1;

    // check whether the matrix is symmetric
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix[i][j] != matrix[j][i])
                success = 0;

    // return 1 if it is symmetric; otherwise return 0
    return success;
}

int main()
{
    int n;
    int matrixRead[16][16];

    // read matrix from user input
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrixRead[i][j]);

    // call function - checkSymmetricMatrix
    int symmetric = checkSymmetricMatrix(matrixRead, n);

    // print your checking result
    printf("It is %s symmetric matrix!", symmetric ? "a" : "not a");

    return 0;
}
