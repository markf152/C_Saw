/* 04-cmd_line_list -- sequentially displays on screen a list of all the files */
/* listed in the command line */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char * argv[])
{
    int n;
    FILE * file;
    char ch;

    puts("\n");

    if (argc == 1) {
        printf("Usage: %s <filename> ... \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (n = 1; n < argc; n++) {
        printf("****** File: %s:\n", argv[n]);
        if ((file = fopen(argv[n], "r")) == NULL) {
            printf("Could not open %s\n", argv[n]);
            exit(EXIT_FAILURE);
        }
        while((ch = getc(file)) != EOF)
            putchar(ch);

        if (fclose(file) != 0)
            fprintf(stderr, "Could not close file %s\n", argv[n]);
    }

    puts("\n");
    
    return 0;
}



