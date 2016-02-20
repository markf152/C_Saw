/* height.c -- user enters height in inches; outut is height in feet */

#include <stdio.h>

int main(void)
{

    char name[30];
    float heightInches;

    printf("\n\n");  /*  Blank lines for readability */


    printf("Please enter your name: ");
    scanf("%s", name);
    printf("%s, please enter your height in inches (decimal portions e.g. 72.5 are ok): ", name);
    scanf("%f", &heightInches);
    printf("\n\n");

    printf("%s, you are %f feet tall.", name, (heightInches / 12));

    printf("\n\n");  /*  Blank lines for readability */

}
