/* addemupmod2.c -- sums up the squares of a user-specified number */
/* of integers, starting with 1 */

#include <stdio.h>

int main(void)
{
    int num;    /* User-entered number of integers to sum up */
    int count;  /* Loop counter */
    int sum;    /* Sum of consecutive integers, starting with 1 */

    printf("\n\n");  /* Blank lines for readability */

    printf("How many integers, starting from 1, would you like to sum up? ");
    scanf("%d", &num);
    printf("\n");

    count = 0;
    sum = 0;

    while (count++ < num) 
        sum = sum + (count * count);

    printf("sum = %d\n", sum);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

