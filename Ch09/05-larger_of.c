/* 05-larger_of.c -- replaces contents of two double variables */
/* with the maximum value of the two variables */

#include <stdio.h>

double larger_of(double num1, double num2);

int main(void)
{

    double num1;
    double num2;

    printf("\n\n"); 

    printf("Enter two floating point numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("The larger of the two numbers is: %f",
            (larger_of(num1, num2)));
    
    printf("\n\n"); 

    return 0;
}

double larger_of(double num1, double num2)
{

    return ((num1 > num2) ? num1 : num2);

}
