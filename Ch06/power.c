/* power.c -- rasies numbers to integer powers */

#include <stdio.h>

double power(double n, int p);  /* ANSI function prototype */

int main(void)
{
    double x;
    double xpow;
    int exp;

    printf("\n\n");  /* Blank lines for readability */

    printf("Enter a number and the positive integer power");
    printf(" to which\nthe number will be raised. Enter q");
    printf(" to quit.\n");

    while (scanf("%lf%d", &x, &exp) == 2) {
        xpow = power(x, exp);
        printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
        printf("Enter the next pair of numbers or q to quit.\n");
    }

    printf("Hope you enjoyed this power trip -- bye!\n");

    printf("\n\n");  /* Blank lines for readability */

    return ;
}

double power(double n, int p)
{
    double pow = 1;
    int i;

    for (i = 1; i <= p; i++)
        pow *= n;

    return pow;
}

