/* paint.c -- uses conditional operator */

#include <stdio.h>

#define COVERAGE 350  // square feet per can of paint

int main(void)
{
    int sq_feet;
    int cans;

    printf("\n\n");  /* Blank lines for readability */

    printf("Enter the number fo square feet to be painted:\n");

    while (scanf("%d", &sq_feet) == 1) {
        cans = sq_feet / COVERAGE;
        cans += ((sq_feet % COVERAGE == 0)) ? 0 : 1;
        printf("You need %d %s of paint.\n", cans,
               (cans == 1 ? "can" : "cans"));
        printf("Enter the next value (q to quit):\n");
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

