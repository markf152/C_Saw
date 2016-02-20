/* 07-manydicerolls.c -- modification to text book listing 12.13 */
/* to enable to user to request multiple rolls for a given set of */
/* input parameters */

/* Compile with 07-diceroll.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "07-diceroll.h"

int main(void)
{
    int sets = 1;
    int dice = 1;
    int sides = 6;
    int status;
    int i;
    char * ptr;
    char numstr[100];

    puts("\n");

    srand((unsigned int) time(0));
    do {
        i = 0;
        printf("Enter the number of sets; enter q to stop: ");
        numstr[i] = getchar();
        if (numstr[i] == '\n')
            numstr[i] = getchar();
        while (numstr[i] != '\n') {
            i++;
            numstr[i] = getchar();
        }
        if (numstr[0] == 'q') {
            sets = 'q';
        }
        else {
            sets = strtol(numstr, &ptr, 10);     
            printf("How many sides and how many dice? ");
            scanf("%d %d", &sides, &dice);
            printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
            for (i = 0; i < sets; i++) {
                printf("%5d", roll_n_dice(dice, sides));
                if (((i+1) % 10) == 0)
                    printf("\n");
            }
        }
        printf("\n");
    } while (sets != 'q');

    printf("Program ending.");

    puts("\n");

    return 0;
}

