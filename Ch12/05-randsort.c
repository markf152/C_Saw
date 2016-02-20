/* 05-randsort.c -- generates a list of 100 random numbers */
/* in the range 1-10, sorted in decreasing order */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x;
    int temp;
    int i;
    int j;
    int ctr = 0;
    int randList[100];

    puts("\n");


    srand((unsigned int) time(0));

    for (x = 0; x < 100; x++)
        randList[x] = rand() % 10 + 1;

    for (i = 0; i < 99; i++)
        for (j = i + 1; j < 100; j++)
            if (randList[j] > randList[i]) {
                temp = randList[i];
                randList[i] = randList[j];
                randList[j] = temp;
            }

    for (x = 0; x < 100; x++) {
        ctr++;
        printf("%2d", randList[x]);
        if (ctr == 10) {
            ctr = 0;
            printf("\n");
        }
        else
            printf(", ");
    }    

    puts("\n");

    return 0;

}
