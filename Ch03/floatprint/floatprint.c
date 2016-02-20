/* floatprint.c - print floating point number in different formats */

#include <stdio.h>

int main(void)
{

    float floatNum;

    printf("\n\n"); /* blank lines for readability */

    printf("Enter a floating point number: ");
    scanf("%f", &floatNum);

    printf("\n");
    printf("fixed-point notation: %f\n", floatNum);
    printf("exponential notation: %e\n", floatNum);
    printf("P notation:           %a\n", floatNum);    

    printf("\n\n"); /* blank lines for readability */
 
    return 0;
}
