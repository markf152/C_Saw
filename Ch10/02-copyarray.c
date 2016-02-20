/* 02-copyarray.c -- copies arrays using functions with different */
/* methods of passing information from the main program */

#include <stdio.h>

void copy_arr(double * targ, double * sourc, int n);
void copy_ptr(double * targ, double * sourc, int n);
void copy_ptrs(double * targ, double * sourc, double * end);

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    int x;

    printf("\n\n");
    
    copy_arr(target1, source, 5);
    printf("Array: target1\n");
    for (x = 0; x < 5; x++)
       printf("%d: %f\n", x, target1[x]);

    printf("\n");

    copy_ptr(target2, source, 5);
    printf("Array: target2\n");
    for (x = 0; x < 5; x++)
       printf("%d: %f\n", x, target2[x]);

    printf("\n");

    copy_ptrs(target3, source, (source + 5));
    printf("Array: target3\n");
    for (x = 0; x < 5; x++)
       printf("%d: %f\n", x, target3[x]);

    printf("\n\n");

    return 0;
}

void copy_arr(double * targ, double * sourc, int n)
{
    int x;

    for (x = 0; x < n; x++) 
        targ[x] = sourc[x];
}

void copy_ptr(double * targ, double * sourc, int n)
{
    int x;

    for (x = 0; x < n; x++) {
        *(targ + x) = *(sourc + x);
    }
}

void copy_ptrs(double * targ, double * sourc, double * end)
{
    int x;

    for (x = 0; x < (end - sourc); x++)
        *(targ + x) = *(sourc + x);
}

