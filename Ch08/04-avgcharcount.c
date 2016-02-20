/* 04-avgcharcount.c - returns the average number of characters per word in input */

#include <stdio.h>

int main(void)
{
    char ch;
    int charcount = 0;
    int wordcount = 0;

    printf("\n\n");  // Blank lines for readability
    
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch))
            charcount++;
        else
            wordcount++;
    }

    printf("\n"); 
    printf("Characters: %d    Words: %d\n\n", charcount, wordcount);
    printf("The average number of characters per word is: %.1f\n",
            ((float)charcount / (float)wordcount));


    printf("\n\n");  // Blank lines for readability

    return 0;

}

