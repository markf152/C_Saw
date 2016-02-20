/* 03-largest.c -- returns largest value found in an array of int */

#include <stdio.h>

int largest(int * arr1, int size);

int main(void)
{
    int arr[] = {9,12,6,7,8,14,18,3,1,9,14,16};
    int x;

    printf("\n\n");

    printf("The array 'arr' contains the following:\n");
    for (x = 0; x < 12; x++)
        printf("%d ", arr[x]);
    printf("\n");

    printf("The largest value in that array is %d\n", largest(arr, 12));

    printf("\n\n");

    return 0;
}


int largest(int * arr1, int size)
{
    int x;
    int l = 0;

    for (x = 0; x < size; x++)
        if (*(arr1 + x) > l)
            l = *(arr1 + x);
    
    return l;
}
