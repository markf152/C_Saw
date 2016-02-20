/* 01-count_mod.c -- using standard I/O */

#include <stdio.h>
#include <stdlib.h>   // exit() prototype
#include <string.h>

#define MAXFILEN 256

int main(int argc, char * argv[])
{
    int ch;    // place to store each char as read
    char fname[MAXFILEN];
    FILE * fp;  // "file pointer"
    unsigned long count = 0;
    char * pos;   // to test out another way to strip fgets()-induced '\n'

    puts("\n");

    puts("Enter the name of the file for a charcter count:");
    fgets(fname, MAXFILEN, stdin);
//    fname[strlen(fname) - 1] = 0;
//    puts(fname);
    if ((pos = strchr(fname, '\n')) != NULL)
        *pos = '\0';

    if ((fp = fopen(fname, "r")) == NULL) {
        printf("Can't open %s\n", fname);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);   // same as putchar(ch);
        count++;
    }

    fclose(fp);
    printf("File %s has %lu characters\n", fname, count);

    puts("\n");

    return 0;
}

