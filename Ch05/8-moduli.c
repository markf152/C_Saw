/* 8-moduli.c -- takes one number to serve as second operand and a */
/* series of numbers to serve as the first operand for which a     */
/* a modulus will be computed.                                     */

#include <stdio.h>

int main(void)
{

    int firstOp = 0;
    int secondOp = 0;

    printf("\n\n");  /* Blank lines for readability */
    
    printf("This program computes moduli.\n");
    printf("Enter an integer to serve as the second operand: ");
    scanf("%d", &secondOp);
    printf("Now enter the first operand: ");
    scanf("%d", &firstOp);
 
    while (firstOp > 0) {
        printf("%d %% %d is %d\n", firstOp, secondOp, (firstOp % secondOp) );
        printf("Enter the next number for first operand ( <= 0 to quit): ");
        scanf("%d", &firstOp);
    }
    printf("Done");
    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

