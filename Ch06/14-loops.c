/* 14-loops.c -- user supplies values for 8 elements of one array */
/* program fills elements of second array with corresponding cumulative */
/* totals from the first array */

#include <stdio.h>

int main(void)
{
    double initArray[9];
    double totalArray[9];
    int x;

    printf("\n\n");  /* Blank lines for readability */

    printf("This program takes 8 double precision floating point numbers,\n");
    printf("enters them in an array and then enters the running total of the\n");
    printf("that array's numbers in a second array.  E.g. the 5th element of the\n");
    printf("second array is the sum of the first 5 elements of the first array.\n\n");

    printf("Enter 8 floating point numbers:\n");
    initArray[0] = 0; /* Set this to 0 to make single loop method of filling 2nd array work */
    for (x = 1; x < 9; x++) {
        scanf("%lf", &initArray[x]);
        totalArray[x] += (initArray[x] + initArray[x - 1]);
    }

    printf("\n");
    
    for (x = 1; x < 9; x++)
        printf("%10.5f", initArray[x]);

    printf("\n");

    for (x = 1; x < 9; x++)
        printf("%10.5f", totalArray[x]);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
