/* wheat.c -- exponential growth */

#include <stdio.h>

#define SQUARES 64

int main(void)
{
    const double CROP = 2e16;  /* World wheat production in wheat grains */

    double current;
    double total;
    int count = 1;

    printf("\n\n");  /* Blank lines for readability */

    printf("Square     Grains       Total      ");
    printf("Fraction of \n");
    printf("           Added        Grains     ");
    printf("World Total\n");

    total = current = 1.0;  /* Start with 1 grain */

    printf("%4d %13.2e %12.2e %12.2e\n", count, current,
           total, (total / CROP));
    while (count < SQUARES)
    {
        count = count + 1;
        current = 2.0 * current;
        /* double grains on next square */
        total = total + current;
        printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, (total / CROP));
    }
    printf("That's all.");

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
