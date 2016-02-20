/* shoes2.c -- calculates foot length for several sizes */

#include <stdio.h>

#define ADJUST 7.31

int main(void)
{
    const double SCALE = 0.333;
    
    double shoe;
    double foot;

    printf("\n\n");  /* Blank lines for readability */

    printf("Shoe size (men's)   foot length\n");
    shoe = 3.0;
    while (shoe < 18.5)
    {
        foot = SCALE * shoe + ADJUST;
        printf("%10.1f %15.2f inches\n", shoe, foot);
        shoe = shoe + 1.0;
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
