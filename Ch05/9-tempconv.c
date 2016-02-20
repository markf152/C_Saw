/* 9-tempconv.c -- converts a Fahrenheit temperature to Celcius and Kelvin */

#include <stdio.h>

void Temperatures (float tempF);

int main(void)
{
    double tempF = 0;
    double tempC = 0;
    double tempK = 0;
    int more = 1;     /* Return value for scanf; 1 means a number was entered */

    printf("\n\n");  /* Blank lines for readability */
    printf("Enter a temperature in degrees Fahrenheit: ");
    more = scanf("%lf", &tempF);
    
    while (more == 1)  {
        Temperatures(tempF);
        printf("Enter a temperature in degrees Fahrenheit (non-number to quit): ");
        more = scanf("%lf", &tempF);
    }
   
    printf("Done\n");

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

void Temperatures(float TempF)
{
    const float F_C_Ratio = (5.0 / 9.0);
    const float F_Freeze = 32.0;
    const float K_C_Conv = 273.16;

    printf("%.2f degrees F = %.2f degrees C\n", TempF, (F_C_Ratio * (TempF - F_Freeze)));
    printf("%.2f degrees F = %.2f degrees K\n\n", TempF, ((F_C_Ratio * (TempF - F_Freeze) + K_C_Conv)));
}
