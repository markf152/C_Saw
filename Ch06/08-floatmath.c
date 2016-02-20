/* 8-floatmath.c -- takes two floating point numbers and returns the */
/* value of their difference divided by their product.               */

#include <stdio.h>

int main(void)
{

    float fnum1;
    float fnum2;
    float answer;

    printf("\n\n");  /* Blank lines for readability */

    printf("This program takes two floating point numbers as input and\n");
    printf("returns the value of their difference divided by their product\n\n");

    printf("Enter two floating point numbers: ");
    while (scanf("%f %f", &fnum1, &fnum2) == 2) { 
        answer = (fnum1 - fnum2) / (fnum1 * fnum2);
        printf("For those two numbers, the result is %f\n\n", answer);
        printf("Enter two more floating point numbers (q to quit): "); 
    }

    printf("Bye.\n");
    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
