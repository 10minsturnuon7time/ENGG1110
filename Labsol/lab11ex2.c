/**
 * ENGG1110 Problem Solving by Programming
 * Lab 11 Exercise 2
 * Recursive Selection Sort
 */

#include <stdio.h>

/* Return the index of the minimum element found in the sub-array from
   a[i] to a[j] */
int min_index(int a[], int i, int j)
{
    // insert your code to locate the smallest element between index i and j
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
void selection_sort(int a[], int index, int n)
{
    // return when the starting index has reached the array size
    if (index == n)
        return;

    // call min_index function to locate the smallest element
    int min_pos = min_index(a, index, n-1);

    if (min_pos != index) {
        int tmp = a[index];
        a[index] = a[min_pos];
        a[min_pos] = tmp;
    }

    // recursively call selection_sort function
    return selection_sort(a, index + 1, n);
}

int main()
{
    int n, arr[10] = {0};

    // Read the input array size from the user
    scanf("%d", &n);

    // Read n array elements
    for (int i=0; i < n ; i++) {
        scanf("%d", &arr[i]);
    }

    // sort the input array recursively
    selection_sort(arr, 0, n);

    // print the sorted array
    for (int i=0; i < n ; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
