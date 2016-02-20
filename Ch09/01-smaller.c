/* 01-smaller.c -- returns the smaller of two double values */

#include <stdio.h>

double smaller(double num1, double num2);

int main(void)
{

    double num1;
    double num2;
    double smallest;

    printf("\n\n");  // Blank lines for readability
    printf("Enter two floating point numbers: ");
    scanf("%lf %lf", &num1, &num2);
    smallest = smaller(num1, num2);
    printf("The smallest of the two numbers is: %f", smallest); 

    printf("\n\n");  // Blank lines for readability

    return 0;
}

double smaller(double num1, double num2)
{
    return ((num1 < num2) ? num1 : num2);
}

