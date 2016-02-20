/* file_eof.c -- open a file and display it */

#include <stdio.h>
#include <stdlib.h>  // for exit()

int main(void)
{
    int ch;
    FILE *fp;
    char fname[50];

    printf("\n\n");  // blank lines for readability

    printf("Enter the name of the file: ");
    scanf("%s", fname);  // open file for reading

    fp = fopen(fname, "r");
    if (fp == NULL) {
        printf("Failed to open file.  Bye.\n");
        exit(1);
    }

    // getc(fp) gets a character from the open file
    while ((ch = getc(fp)) != EOF)
        putchar(ch);
    fclose(fp);

    printf("\n\n");  // blank lines for readability

    return 0;
}

    
