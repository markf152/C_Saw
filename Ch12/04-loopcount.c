/* 04-loopcount.c -- test of a function that returns */
/* the number of times it has been called */

#include <stdio.h>
#include <stdlib.h>

int callcount(void);

int main(void)
{
    int calls = 0;
    int count = 0;
    int loop;

    puts("\n");
    
    srand((unsigned int) time(0));
    calls = rand() % 100 + 1;
    printf("Planned number of calls: %d\n", calls);

    for (loop = 0; loop < calls; loop++)
        count = callcount();

    printf("Total number of calls: %d\n", count);
    
    puts("\n");

    return 0;
}


int callcount(void)
{
    static int callCount = 0;

    callCount++;

    return callCount;
}

