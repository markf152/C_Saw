/* fgets3.c -- using fgets() */

#include <stdio.h>

#define STLEN 10

int main(void)
{
    char words[STLEN];
    int i;
    char ch;

    printf("\n\n");

    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL
                         && words[0] != '\n') {
        puts("...");
        i = 0;
        while (words[i] != '\n' && words[i] != '\0')
            i++;
        if (words[i] == '\n')
            words[i] = '\0';
        else  // must have words[i] == '\0'
            fputs("Discarded characters: ", stdout);
            while ((ch = getchar()) != '\n') 
               putchar(ch);
            putchar('\n');
        fputs("Contents of 'words': ", stdout);
        puts(words);
    }
    puts("done");

    printf("\n\n");
    
    return 0;
}

