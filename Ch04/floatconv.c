/* floatconv.c -- mismatched floating point conversions */

#include <stdio.h>

int main(void)
{
    float n1 = 3.0;
    double n2 = 3.0;
    long n3 = 2000000000;
    long n4 = 1234567890;
    int printCount = 0;   /* takes return value for printf */

    printf("\n\n");  /* Blank lines for readability */

    printf("n1 = %f\n", n1);
    printf("n2 = %f\n", n2);
    printf("n3 = %ld\n", n3);
    printf("n4 = %ld\n\n", n4);

    printf("n1 (%%.1e) = %.1e\n", n1);
    printf("n2 (%%.1e) = %.1e\n", n2); 
    printf("n3 (%%.1e) = %.1e\n", n3);
    printf("n4 (%%.1e) = %.1e\n\n", n4);

    printf("n3 (%%ld) = %ld\n", n3);
    printf("n4 (%%ld) = %ld\n\n", n4);

    printf("n1 (%%ld) = %ld\n", n1);
    printf("n2 (%%ld) = %ld\n", n2);
    printf("n3 (%%ld) = %ld\n", n3);
    printf("n4 (%%ld) = %ld\n\n", n4);

    printCount = printf("%ld %ld %ld %ld*\n", n1, n2, n3, n4);

    printf("123456789|123456789|123456789|123456789|123456789|\n");
    printf("The number of characters printed in the line above is: %d\n", printCount);

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
