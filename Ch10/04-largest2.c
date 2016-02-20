/* 04-largest2.c -- returns the index of the largest value stored */ /* in an array of double */ 
#include<stdio.h>

int large_index(int * arr, int n);

int main(void)
{

    int arrd[] = {9,5,3,8,5,2,7,1,13,5};
    int x;

    printf("\n\n");

    printf("The array 'arrd' . . .\n");
    for (x = 0; x < 10; x++)
        printf("%d ", arrd[x]);
    printf("\n");

    printf("The index number of the largest value in the array is: %d\n",
            (large_index(arrd, 10)));

    printf("\n\n");

    return 0;
}


int large_index(int * arr, int n)
{

    int x;
    int lgst = 0;
    int lgst_indx = 0;

    for (x = 0; x < n; x++) {
        printf("%d: %d  ", x, (*(arr + x)));
        if (*(arr + x) > lgst) {
            lgst = *(arr + x);
            lgst_indx = x;
        }
    }
    printf("\n");

    return lgst_indx;

}
