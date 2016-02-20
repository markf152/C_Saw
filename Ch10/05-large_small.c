/* 05-larg_small.c -- returns largest and smalles values found in an array of int */

#include <stdio.h>

int large_small(int * arr1, int size);

int main(void)
{
    int arr[] = {9,12,6,7,8,14,18,-3,1,9,14,16};
    int x;

    printf("\n\n");

    printf("The array 'arr' contains the following:\n");
    for (x = 0; x < 12; x++)
        printf("%d ", arr[x]);
    printf("\n");

    printf("The difference between the largest and smallest numbers\n");
    printf("in the array is: %d", large_small(arr,12));

    printf("\n\n");

    return 0;
}


int large_small(int * arr1, int size)
{
    int x;
    int l = *(arr1);
    int s = *(arr1);
    
    for (x = 0; x < size; x++)
        if (*(arr1 + x) > l)
            l = *(arr1 + x);
        else if (*(arr1 + x) < s)
            s = *(arr1 + x);

    return (l - s);
}
