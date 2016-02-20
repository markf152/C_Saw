/* scores_in.c -- uses loops for array processing */

#include <stdio.h>

#define SIZE 10
#define PAR 72

int main(void)
{
    int index;
    int score[SIZE];
    int sum = 0;
    float average;

    printf("\n\n");  /* Blank lines for readability */
   
    printf("Enter %d golf scores:\n", SIZE);
    for (index = 0; index < SIZE; index++)
        scanf("%d", &score[index]);

    printf("The scores read in are as follows:\n");
    for (index = 0; index < SIZE; index++)
        printf("%5d", score[index]);
    printf("\n");

    for (index = 0; index < SIZE; index++)
        sum += score[index];
    average = (float) sum / SIZE;

    printf("Sum of scores = %d, average = %.2f\n", sum, average);
    printf("That's a handicap of %.0f.\n", average - PAR);

    printf("\n\n");  /* Blank lines for readability */    

    return 0;
}
