/* 06-arr_reverse.c -- reverses the contents of an array of double */

#include <stdio.h>

void arr_rev(double * arr1, int size);

int main(void)
{
    double array[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int x;

    printf("\n\n");

    printf("The array contains the following:\n");
    for (x = 0; x < 12; x++)
        printf("%.2f ", array[x]);
    printf("\n\n");
    
    arr_rev(array, 12);

    printf("After being reversed, the array contains the following:\n");
    for (x = 0; x < 12; x++)
        printf("%.2f ", array[x]);
    printf("\n");

    printf("\n\n");

    return 0;
}


void arr_rev(double * arr1, int size)
{
    double arr2[12];    
    int x;

    for (x = 0; x < size; x++)
        arr2[x] = *(arr1 + (size-1) - x);
    for (x = 0; x < size; x++)
        *(arr1 + x) = arr2[x];
}
