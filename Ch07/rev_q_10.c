/* rev_q_10.c -- develop answer to review question 10 fm Ch7 of the Prata C text */

#include <stdio.h>

int main(void)
{
    char ch;

    printf("\n\n");  /* Blank lines for readability */
   
    ch = getchar(); 
    while (ch != '#') {
        if (ch != '\n') {
             printf("Step 1\n"); 
             if (ch == 'b')
                 break; 
             if (ch != 'c' && ch != 'h')
                 printf ("Step 2\n");
             if (ch != 'c')
                 printf("Step 3\n");
        }      
    ch = getchar(); 
    }
    printf("Done\n");

    printf("\n\n");  /* Blank lines for readability */

    return 0;
} 

