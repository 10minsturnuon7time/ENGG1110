/**
 * ENGG1110 Problem Solving by Programming
 * Lab 12 Exercise 2
 * Recursive Selection Sort Revisited Again
 */

#include <stdio.h>
// may need inclusion of additional headers
#include <stdlib.h>
// #include <malloc.h>  /* this one also works */

/* Swap the values stored in x and y */
void swap(char* x, char* y)
{
    // Copy and paste from last exercise
    char tmp = *x;
    *x = *y;
    *y = tmp;
}

/* Return the index of the minimum element found in the sub-array
   from a[i] to a[j] */
int min_index(char a[], int i, int j)
{
    if (i == j)
        return i;

    int k = min_index(a, i + 1, j);

    if (a[i] < a[k])
        return i;
    else
        return k;
}

/* Recursive selection sort.
   index is the index of the starting element.
   n is size of the array a.  */
void selection_sort(char a[], int index, int n)
{
    // Copy and paste your code from last exercise
    // return when the starting index has reached the array size
    if (index == n)
        return;

    // call min_index function to locate the smallest element
    int k = min_index(a, index, n-1);

    // call swap if necessary
    // Enter your code here
    if (k != index)
        swap(&a[k], &a[index]);

    // recursively call selection_sort function
    selection_sort(a, index + 1, n);
}

int main()
{
    int n;
    // Read the input array from the user
    scanf("%d", &n);

    // Enter your code here
    // (allocate a char array arr of size n using malloc)
    char* arr = (char*) malloc(n * sizeof(char));

    // Read n array elements
    for (int i=0; i < n ; i++) {
        scanf(" %c", &arr[i]);
    }

    // sort the input array recursively
    selection_sort(arr, 0, n);

    // print the sorted array
    for (int i=0; i < n ; i++)
        printf("%c ", arr[i]);
    printf("\n");

    // Enter your code here
    // (free the char array arr)
    free(arr);

    return 0;
}
