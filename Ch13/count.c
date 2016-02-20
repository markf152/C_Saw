/* count.c -- using standard I/O */

#include <stdio.h>
#include <stdlib.h>   // exit() prototype

int main(int argc, char * argv[])
{
    int ch;    // place to store each char as read
    FILE *fp;  // "file pointer"
    unsigned long count = 0;

    puts("\n");

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit (EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);   // same as putchar(ch);
        count++;
    }

    fclose(fp);
    printf("File %s has %lu characters\n", argv[1], count);

    puts("\n");

    return 0;
}

