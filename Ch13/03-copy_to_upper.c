/* 03-copy_to_upper.c -- copies one text file to another file, */
/* converting all text to uppercase */
/* User supplies file names via program prompts */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILEN 256

int main(void)
{
    FILE * src;
    FILE * dst;
    char fname[MAXFILEN];
    char * pos;
    char ch;

    puts("\n");

    puts("Enter the name of the source file:");
    fgets(fname, MAXFILEN, stdin);
    if ((pos = strchr(fname, '\n')) != NULL)
        *pos = '\0';
    if ((src = fopen(fname, "r")) == NULL) {
        printf("Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }

    puts("Enter the name of the destination file:");
    fgets(fname, MAXFILEN, stdin);
    if ((pos = strchr(fname, '\n')) != NULL)
        *pos = '\0';
    if ((dst = fopen(fname, "w")) == NULL) {
        printf("Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(src)) != EOF) 
        putc(toupper(ch), dst);

    fclose(src);
    fclose(dst);

    puts("\n");

    return 0;
}

