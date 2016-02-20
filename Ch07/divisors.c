/* divisors.c -- nested ifs display divisors of a number */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    unsigned long num;     // number to be checked
    unsigned long div;     // potential divisors
    bool isprime;          // prime flag

    printf("\n\n");        // Blank lines for readability

    printf("Please enter a number for analysis; ");
    printf("Enter q to quit.\n");

    while (scanf("%lu", &num)== 1) {
        for (div = 2, isprime = true; (div * div) <= num; div++) {
            if ((num % div == 0)) {
                if ((div * div) != num)
                    printf("%lu is divisible by %lu and %lu.\n",
                            num, div, (num / div));
                else 
                    printf("%lu is divisible by %lu.\n",
                            num, div);
                isprime = false;  // number is not prime
            }
        }
        if (isprime)
            printf("%lu is prime.\n", num);
        printf("Please enter another number for analysis; ");
        printf("Enter q to quit.\n");
    }

    printf("Bye.");

    printf("\n\n");        // Blank lines for readability

    return 0;
}

