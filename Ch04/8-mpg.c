/* mpg.c -- user inputs miles traveled and gallons of fuel used      */
/*           output is miles per gallon (MPG) and liters per 100 km */

#include <stdio.h>

#define KM_PER_MILE 1.609
#define LITERS_PER_GAL 3.785

int main(void)
{
    float milestraveled = 0;
    float galsconsumed = 0;

    printf("\n\n");  /* Blank lines for readability */
    
    printf("Please enter the number of miles traveled: ");
    scanf("%f", &milestraveled);
    printf("Please enter the number of gallons of gasoline consumed: ");
    scanf("%f", &galsconsumed);
    printf("\n");

    printf("Your gas mileage was: %.1f miles per gallon (MPG)\n\n", (milestraveled / galsconsumed));
    printf("In European terms, your MPG was %.1f liters-per-100-km.\n",
            ((galsconsumed * LITERS_PER_GAL) / (milestraveled * KM_PER_MILE / 100)));
    printf("Note: you traveled %.3f km and used %.3f liters of gasoline", (milestraveled *KM_PER_MILE),
            (galsconsumed * LITERS_PER_GAL));

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
