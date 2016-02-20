/* floatpoint.c -- reads in a floating point number, then outputs it in */
/*                   decimal point notation and exponential notation    */

#include <stdio.h>

int main(void)
{
    float floatNum = 0.0;

    printf("\n\n");  /* Blank lines for readability */

    printf("Please enter a floating point number: ");
    scanf("%f", &floatNum);
    printf("\n\n");

    printf("Your floating point number in . . .\n\n");
    printf(". . . Decimal Point notation: %f\n", floatNum);
    printf(". . . Exponential notation: %e\n", floatNum);    

    printf("\n\n");  /* Blank lines for readability */
        
    return 0;
}
