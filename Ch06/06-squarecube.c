/* 6-squarecube.c -- prints a table with a sequence of integers along with */
/* the square and cube of each.  THe user inputs the lower and upper limits */

#include <stdio.h>

int main(void)
{
    int llim;    /* Lower limit of table */
    int ulim;    /* Upper limit of table */
    int x;       /* Loop counter */

    printf("\n\n");  /* Blank lines for readability */
    
    printf("This program prints a table containing a series of integers\n");
    printf("along with their squares and cubes\n\n");
    
    printf("Please enter the lower limit of the integer range: ");
    scanf("%d", &llim);
    printf("Please enter the upper limit of the integer range: ");
    scanf("%d", &ulim);
    printf("\n");

    printf("%10s %10s %10s\n", "Number", "Squared", "Cubed");
    for (x = llim; x <= ulim; x++) {
        /* printf("llim = %d, ulim = %d, x = %d\n", llim, ulim, x); */
        printf("%10d %10d %10d\n", x, (x * x), (x * x * x));
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
