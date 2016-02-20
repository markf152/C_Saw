/* double.c -- displays a float value with various numbers of digits */
/*              to the right of the decimal point.                   */

#include <stdio.h>
#include <float.h>

int main(void)
{
    double dvar = 1.0/3.0;
    float fvar = 1./3.0;

    printf("\n\n");  /* Blank lines for readability */

    printf("Double variable . . .\n");
    printf("%.4f\n", dvar);
    printf("%.12f\n", dvar);
    printf("%.16f\n\n", dvar);

    printf("Float variable . . .\n");
    printf("%.4f\n", fvar);
    printf("%.12f\n", fvar);
    printf("%.16f\n\n", fvar);

    printf("FLT_DIG = %d\n", FLT_DIG);
    printf("DBL_DIG = %d\n", DBL_DIG);

    printf("\n\n");  /* Blank lines for readability */
}
