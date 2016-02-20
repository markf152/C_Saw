/* Q_02.c -- code from Ch 13 Review Question 2 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char * argv[])
{
    int ch;
    FILE * fp;

    puts("\n");

    if (argc < 2)
        exit(EXIT_FAILURE);

    if ((fp = fopen(argv[1], "r")) == NULL)
        exit(EXIT_FAILURE);

    while ((ch = getc(fp)) != EOF)
        if (isdigit(ch))
            putchar(ch);
    fclose(fp);

    puts("\n");

    return 0;
}

