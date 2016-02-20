/* timeconv.c -- converts time in minutes to time in hours and minutes */

#include <stdio.h>

#define MIN_HR 60

int main(void)
{
    int mins = 0;

    printf("\n\n");  /* Blank lines for readability */

    printf("This program inputs a number of minutes and\n");
    printf("expresses it in hours and minutes.\n\n");

    printf("Please enter the number of minutes to convert\n");
    printf("Enter 0 or negative number to quit the program\n");
    scanf("%d", &mins);
    printf("\n");

    while (mins > 0) {
        printf("%d minutes equates to %d hour(s) and %d minute(s).\n\n", 
               mins, (mins / 60), (mins % 60)); 
        printf("Please enter the number of minutes to convert\n");
        printf("Enter 0 or a negative number to quit the program\n");
        scanf("%d", &mins);
        printf("\n");
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
