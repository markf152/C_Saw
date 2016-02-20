/* 09-prime.c -- finds all the prime numbers up to a number input by the user */

#include <stdio.h>

int main(void)
{
    int userint;
    int n;
    int x;
    int prime;
    int nextline = 0;

    printf("\n\n");  // Blank lines for readability

    printf("Enter a positive integer: ");
    scanf("%d", &userint);
    printf("\n");
    printf("The following are the prime numbers between 0 and %d\n", userint);

    switch (userint) {
        case 1 :
            printf("1 is not a prime number\n");
            break;
        case 2 :
            printf("2 is a prime number\n");
            break;
        case 3 : 
            printf("2 is a prime number\n");
            printf("3 is a prime number\n");
            break;
        default :
            for (x = 4; x <= userint; x++) {
                prime = 1;
                for (n = 2; (n * n) <= x; n++) {
                    if (x % n == 0) {
                        prime = 0;
                    }
                }
                if (prime == 1) {
                    if (nextline)
                        printf(", ");
                    nextline++;
                    printf("%4d", x);
                    if (nextline == 10) {
                        printf("\n"); 
                        nextline = 0;
                    }
                }
            } 
    }
    
    printf("\n\n");  // Blank lines for readability

    return 0;
}
