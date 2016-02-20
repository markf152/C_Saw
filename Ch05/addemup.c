/* addemup.c -- five kinds of statements */
/* sums up the first 20 integers, starting with 1 */

#include <stdio.h>

int main(void)
{
    int count;
    int sum;

    printf("\n\n");  /* Blank lines for readability */

    count = 0;
    sum = 0;

    while (count++ < 20) 
        sum = sum + count;

    printf("sum = %d\n", sum);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

