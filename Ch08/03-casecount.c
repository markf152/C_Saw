/* 03-casecount.c -- reads characters from input stream and prints their */
/* ASCII decimal values */

// islower()  isupper()
//location 7276

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int lower = 0;  // ASCII 97-122 
    int upper = 0;  // ASCII 65-90
    int other = 0;

    printf("\n\n");  // Blank lines for readability
    
    while ((ch = getchar()) != EOF) {
        if (isupper(ch))
            upper++;
        else if (islower(ch))
            lower++;
        else
            other++;
    }
    printf("\n");
    printf("Number of uppercase characters: %d\n", upper);
    printf("Number of lowercase characters: %d\n", lower);
    printf("Number of other characters    : %d\n", other);

    printf("\n\n");  // Blank lines for readability

    return 0;

}

