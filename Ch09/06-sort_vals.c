/* 06-sort_vals.c -- takes three double variable addresses */
/* and sorts the values with the smallest in the first variable */
/* and the largest in the last variable */

#include <stdio.h>

void sort_values (double * num1, double * num2, double * num3);

int main (void)
{

    double num1;    
    double num2;    
    double num3;    

    printf("\n\n");

    printf("Enter three floating point numbers: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);
    sort_values(&num1, &num2, &num3);
    printf("The values in order (smallest to largest):\n");
    printf("%f\n", num1);
    printf("%f\n", num2);
    printf("%f\n", num3);

    printf("\n\n");
    
    return 0;
}

void sort_values (double * num1, double * num2, double * num3)
{
    double larger;

    if (*num1 > *num2) {
        larger = *num1;
        *num1 = *num2;
        *num2 = larger;
    }
    if (*num2 > *num3) {
        larger = *num3;
        *num2 = *num3;
        *num3 = larger;
    }
    if (*num1 > *num2) {
        larger = *num1;
        *num1 = *num2;
        *num2 = larger;
    } 
}

