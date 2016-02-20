/* 11-fibonacci_loop.c -- calculates Fibonacci numbers */
/* using a loop rather than a recursive function */

#include <stdio.h>

unsigned long fibonacci(unsigned n);

int main(void)
{
    unsigned int n;
    printf("\n\n");

    printf("Enter the Fibonacci number would you like: ");
    scanf("%u", &n);

    printf("The Fibonacci number is: %lu\n", (fibonacci(n)));

    printf("\n\n");

    return 0;
}

unsigned long fibonacci(unsigned n)
{
    unsigned long fib_a = 1;
    unsigned long fib_b = 1;
    unsigned long fib_curr = 1;
    int x;

    if (n > 2) {
        for (x = 3; x <= n; x++) {
            fib_a = fib_b;
            fib_b = fib_curr;
            fib_curr = fib_a + fib_b;
        }
    }

    return fib_curr;

}

