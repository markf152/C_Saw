/* 7-cubed.c -- takes a number as input, cubes it, and prints the result */

#include <stdio.h>

double cubeit(double n);

int main(void)
{
    double num = 0;

    printf("\n\n");  /* Blank lines for readability */
    
    printf("Please enter a number to be cubed: ");
    scanf("%lf", &num);
    printf("\n\n");

    printf("%f cubed = %f\n", num, cubeit(num) );

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

double cubeit(double n)
{
    return (n * n * n);
}

