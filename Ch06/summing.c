/* summing.c -- sums a variable number of integers entered by the user */

#include <stdio.h>

int main(void)
{
    long num;
    long sum = 0L;
    int status;

    printf("\n\n");  /* Blank lines for readability */
    
    printf("Please enter an integer to be summed ");
    printf("(q to quit) :");
    
    while (scanf("%ld", &num) == 1) {
        sum = sum + num;
        printf("Please enter the next integer (q to quit): ");
    }

    printf("Those integers sum to %ld.\n", sum);

    return 0;

    printf("\n\n");  /* Blank lines for readability */
}
