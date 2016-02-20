/* 10-sumintsqrs.c -- inputs lower and upper integer limits and calculates */
/* the sum of the squares of the integers in that range                    */

#include <stdio.h>

int main(void)
{
    int llim;
    int ulim;
    int sqrSum;
    int x;

    printf("\n\n");  /* Blank lines for readability */

    printf("This program inputs two integers, a lower limit and an\n");
    printf("upper limit.  It outputs the sum of the squares of the\n");
    printf("integers in that range, including the two limit integers.\n");
    printf("To end the program, enter an upper limit that is equal to or\n");
    printf("less than the lower limit.\n\n");

    printf("Enter lower and upper integer limits: ");
    scanf("%d %d", &llim, &ulim);

    while (ulim > llim) {
        sqrSum = 0;
        for (x = llim; x <= ulim; x++)
            sqrSum += (x * x);
        printf("The sum of the squares from %d to %d is %d\n",
               (llim * llim), (ulim * ulim), sqrSum);
        printf("Enter the next set of limits: ");
        scanf("%d %d", &llim, &ulim);
    }

    printf("Done");

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
