/* fgets3.c -- using fgets() */

#include <stdio.h>

#define STLEN 10

char * s_gets(char * st, int n);

int main(void)
{
    char words[STLEN];
    int i;
    char ch;

    printf("\n\n");

    puts("Enter strings (empty line to quit):");
    while (s_gets(words, STLEN) != NULL
                         && words[0] != '\0') {
        fputs("Contents of 'words': ", stdout);
        puts(words);
    }
    puts("done");

    printf("\n\n");
    
    return 0;
}


char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val)  // i.e., ret_val != NULL
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else      // must have words[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

