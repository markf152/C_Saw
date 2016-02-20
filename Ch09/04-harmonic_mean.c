/* 04-harmonic_mean.c -- calculates the harmonic mean of two numbers */

#include <stdio.h>

double harmonic_mean(double num1, double num2);

int main(void)
{
    double num1;
    double num2;

    printf("\n\n");  // Blank lines for readability

    printf("Enter two floating point numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("The harmonic mean of those two numbers is: %f\n",
            (harmonic_mean(num1, num2)));
    
    printf("\n\n");  // Blank lines for readability

    return 0;
}

double harmonic_mean(double num1, double num2)
{
    return (1 / (((1 / num1) + (1 / num2)) / 2));
}

