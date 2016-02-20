/* cups-vol.c -- takes number of cups and returns number of pints, ounces, */
/*     tablespoons, and teaspoons */
/* Must use -lm GCC option to get floor function */

#include <stdio.h>
#include <math.h>

int main(void)
{

    float cups;
    int pints;
    int ounces;
    int tablespoons;
    int teaspoons;
    float remainder;
    _Bool exactly;

    printf("\n\n");  /* blank lines for readability */

    printf("Enter a number of cups: ");
    scanf("%f", &cups);
    pints = (int)floor(cups / 2.0);
    remainder = (cups / 2.0) - floor(cups / 2.0);
    ounces = (int)floor(remainder * 16);
    remainder = (remainder * 16) - floor(ounces);
    tablespoons = (int)floor(remainder * 2); 
    remainder = (remainder * 2) - floor(tablespoons);
    teaspoons = (int)floor(remainder * 3 + 0.5);
    printf("\n");

    /* If the conversion is exact (i.e. 0 remainder) set exactly = TRUE (!0) */
    exactly = !(remainder);

    if (exactly)
        printf("%f cups is exactly . . .\n", cups);
    else
        printf("%f cups is approximately . . .\n", cups);

    if (pints == 1)
        printf("    %d pint plus\n", pints);
    else
        printf("    %d pints plus\n", pints);
    if (ounces == 1)
        printf("    %d ounce plus\n", ounces);
    else
        printf("    %d ounces plus\n", ounces);
    if (tablespoons == 1)
        printf("    %d tablespoon plus\n", tablespoons);
    else
        printf("    %d tablespoons plus\n", tablespoons);
    if (teaspoons == 1)
        printf("    %d teaspoon\n", teaspoons); 
    else
        printf("    %d teaspoons\n", teaspoons); 

    printf("\n\n");  /* blank lines for readability */

}
