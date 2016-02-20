/* 12-infiniteseries.c -- evaluates the running totals of two infinite series */

#include <stdio.h>

int main(void)
{
    int x;  /* Loop Counter */
    int limit;      /* Number of terms user wishes to evaluate */
    float series1 = 1.0;  /* Running total for the first series */
    float series2 = 1.0;  /* Running total for the second series */
    int plusMinusOne = -1.0;  /* Variable to allow the changing sign in the second series */

    printf("\n\n");  /* Blank lines for readability */

    printf("This program evaluates the running totals of the following series:\n");
    printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...\n");
    printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...\n\n");

    printf("Enter the number of terms you want to evaluation for the series above: \n");
    scanf("%d", &limit);

    for (x = 2; x <= limit; x++){
       series1 += 1.0 / (float)x;
       series2 += plusMinusOne / (float)x;
       plusMinusOne *= -1.0;
    }
    
    printf("Series One over %d terms = %f\n", limit, series1);
    printf("Series Two over %d terms = %f\n", limit, series2);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
