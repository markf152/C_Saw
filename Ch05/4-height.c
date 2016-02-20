/* 4-height.c -- takes height in cm and converts to feet and inches */

#include <stdio.h>

#define IN_PER_CM 0.3937

int main(void)
{
    float height_cm = 0;
    int height_ft = 0; /* Feet portion of height in feet and inches   */
    float height_in = 0; /* Inches portion of height in feet and inches */

    printf("\n\n");  /* Blank lines for readability */

    printf("This program takes as input a height in centimeters (cm)\n");
    printf("and converts it to feet and inches\n");

    printf("Enter a height in centimeters: ");
    scanf("%f", &height_cm);
    printf("\n");

    while (height_cm > 0) {
        height_ft = (int)(height_cm * IN_PER_CM) / 12;
        height_in = (height_cm * IN_PER_CM) - (height_ft * 12); 
        printf("%.1f cm = %d feet, %.1f inches\n\n", height_cm, height_ft, height_in); 
               
        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &height_cm);
        printf("\n");
    }
    printf("bye");

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
