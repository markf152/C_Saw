/* 08-power.c -- rasies numbers to integer powers */
/* accomodates 0 powers and raising to a negative power */

#include <stdio.h>

double power(double n, int p);  /* ANSI function prototype */

int main(void)
{
    double x;
    double xpow;
    int exp;

    printf("\n\n");  /* Blank lines for readability */

    printf("Enter a number and the integer power to");
    printf(" which\nthe number is to be raised. Enter q");
    printf(" to quit.\n");

    while (scanf("%lf %d", &x, &exp) == 2) {
        xpow = power(x, exp);
        printf("%.3g to the power %d is %.5g\n\n", x, exp, xpow);
        printf("Enter the next pair of numbers or q to quit.\n");
    }

    printf("\n\n");  /* Blank lines for readability */

    return ;
}

double power(double n, int p)
{
    double pow = 1;
    int i;
    int neg = 0;

    if (n == 0) {
        if (p == 0) {
            printf("0 raised to the power of 0 is undefined\n");
            printf("(returning a value of 1)\n");
            pow = 1;
        }
        else
            pow = 1;
    }
    else {
        if (p < 0) { 
            neg = 1;
            p *= -1;
        }
        for (i = 1; i <= p; i++)
            pow *= n;
        if (neg)
            pow = 1 / pow;
    }

    return pow;
}

