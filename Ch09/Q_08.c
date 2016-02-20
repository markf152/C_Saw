/* Q_08.c -- test my answer to a question */

#include <stdio.h>

int main(void)
{
    int n1;
    int n2;
    int n3;
    int largest;

    printf("\n\n");  // Blank lines for readability

    printf("Enter 3 integers . . .  ");
    scanf("%d %d %d", &n1, &n2, &n3);

   largest = (n1 > n2) ? n1 : n2;
   largest = (largest > n3) ? largest : n3;

   printf("The largest integer entered is: %d", largest);

   printf("\n\n");  // Blank lines for readability

   return 0;
}

