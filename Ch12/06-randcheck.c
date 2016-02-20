/* 06-randcheck.c -- generates 1000 random numbers in the range 1 - 10 */
/* for 10 different seed values. The number of times each value was   */
/* selected is printed out for comparison */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int runs;
    int x;
    int randNum;
    int stats[11] = {0,0,0,0,0,0,0,0,0,0,0};

    puts("\n");

    for (runs = 0; runs < 10; runs++) {
        srand((unsigned int) time(0) + runs);
        for (x = 0; x < 1000; x++) {
            randNum = rand() % 10 + 1;
            stats[randNum]++;
        }
    }
    printf("Number   Nr of Times Generated\n");
    for (x = 0; x < 10; x++)
        printf("  %2d             %4d\n", (x + 1), stats[x + 1]);

    puts("\n");

    return 0;

}
