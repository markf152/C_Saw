/* manydice.c -- multiple dice rolls */
/* compile with diceroll.c           */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "diceroll.h"

int main(void)
{
    int dice;
    int roll;
    int sides;
    int status;
    int x;

    puts("\n");
    
    srand((unsigned int)time(0));  // randomize seed
    printf("Enter the number of sides per die, 0 to stop.\n");
    while (scanf("%d", &sides) == 1 && sides > 0) {
        printf("How many dice?\n");
        if ((status = scanf("%d", &dice)) != 1) {
            if (status == EOF)
                break;
            else {
                printf("You should have entered an integer.");
                printf("Let's begin again.\n");
                while (getchar() != '\n');
                    continue;
                printf("How many sides? Enter 0 to stop.\n");
                continue;
            }
        }
        for (x = 0; x < 10; x++) {
            roll = roll_n_dice(dice, sides);
            printf("You have rolled a total of %2d using %d %d-sided di",
                    roll, dice, sides);
            if (dice == 1)
                printf("e.\n");
            else
                printf("ce.\n");
        }
        printf("How many sides? Enter 0 to stop.\n");
    }
    printf("The rollem() function was called %d times.\n",
            roll_count);
    printf("Bye.\n");

    puts("\n");

    return 0;
}

