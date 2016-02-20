/* binary.c -- prints integer in binary form */

#include <stdio.h>

void to_binary(unsigned long n);

int main(void)
{
    unsigned long number;

    printf("\n\n");  // Blank lines for readability

    printf("Enter an integer (q to quit):\n");
    while (scanf("%lu", &number) == 1) {
        printf("Binary equivalent: ");
        to_binary(number);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done.\n");

    printf("\n\n");  // Blank lines for readability

    return 0;
}

void to_binary(unsigned long n)  /*recursive function */
{
    int r;
    r = n % 2;
    if (n >= 2)
        to_binary(n / 2);
    putchar(r == 0 ? '0' : '1');
    // printf("(%ld) ", n);

    return;
}

