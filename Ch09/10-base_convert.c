/* base_convert.c -- takes a number in base 10 */
/* and converts it to a another base, 2 through 10 */

#include <stdio.h>

void change_base(unsigned long n, int b);

int main(void)
{
    unsigned long n;
    int b;

    printf("\n\n");

    printf("This program converts a decimal integer in base 10\n");
    printf("to a chose base, 2 through 10.\n\n");
    printf("Enter your base 10 integer: ");
    scanf("%ld", &n);
    printf("Enter the base to convert to: ");
    scanf("%d", &b);

    change_base(n, b);

    printf("\n\n");

    return 0;
}


void change_base(unsigned long n, int b)
{
    int r;

    r = n % b;
    if (n >= b)
        change_base((n / b), b);
    putchar(r + 48);

    return; 

}
