/* 7-chararray.c -- reads a single word into a char array and prints */
/* the word backward                                                 */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[100];
    int x;
    int wordLen;

    printf("\n\n");  /* Blank lines for readability */
    
    printf("Enter a single word: ");
    scanf("%s", word);
    printf("\n");

    wordLen = strlen(word); 
    printf("Your word: %s\n", word);
    printf("Your word, backwards: ");
    for (x = (wordLen - 1); x >= 0; x--) 
        printf("%c", word[x]);
    printf("\n");

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}
