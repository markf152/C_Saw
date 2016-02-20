/* 9-floatmath.c -- takes two floating point numbers and returns the */
/* value of their difference divided by their product.               */
/* (same as 8-floatmath.c, except that it uses a function            */

#include <stdio.h>

float fcalc(float f1, float f2);

int main(void)
{

    float fnum1;
    float fnum2;

    printf("\n\n");  /* Blank lines for readability */

    printf("This program takes two floating point numbers as input and\n");
    printf("returns the value of their difference divided by their product\n\n");

    printf("Enter two floating point numbers: ");
    while (scanf("%f %f", &fnum1, &fnum2) == 2) { 
        printf("For those two numbers, the result is %f\n\n", fcalc(fnum1, fnum2));
        printf("Enter two more floating point numbers (q to quit): "); 
    }

    printf("Bye.\n");
    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

float fcalc(float f1, float f2)
{
    return ((f1 - f2) / (f1 * f2));
}
