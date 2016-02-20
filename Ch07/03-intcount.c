/* 03-intcount.c -- reads integers until a zero is entered; outputs  */
/* counts of even and odd integers along with average values of each */

#include <stdio.h>
#define STOP 0

int main(void)
{
    int intnum = 0;
    int evenint = 0;
    int oddint = 0;
    int eventotal = 0;
    int oddtotal = 0;

    printf("\n\n");  /* Blank lines for readability */

    printf("Enter integers to count / average (even and odd), zero to quit\n\n");
    
    scanf("%d", &intnum);
    while (intnum != STOP) {
        if (!(intnum % 2)) {
            evenint++;
            eventotal += intnum;
        }
        else {
            oddint++;
            oddtotal += intnum;
        }
        scanf("%d", &intnum);
    }

    if (evenint != 0) {
        printf("The total number of even integers entered is %d\n", evenint);
        printf("The average value of the even integers entered is %.2f\n", (float)(eventotal / evenint));
    }
    else
        printf("There were no even integers entered.\n");

    if (oddint != 0) {
        printf("The total number of odd integers entered is %d\n", oddint);
        printf("The average value of the odd integers entered is %.2f\n", ((float)oddtotal / (float)oddint));
    }
    else
        printf("There were no odd integers entered.\n");


    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
