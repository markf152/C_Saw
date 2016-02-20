/* Q_05.c -- prints lines from user-specified file containing a */
/* a user-specified character; both are input via command line arguments */
/* first command line argument is the character; 2nd is the file name */

#include <stdio.h>
#include <stdlib.h>

#define MAXSTLEN 256

int main (int argc, char * argv[])
{

    FILE * textfile;
    char ch;
    int charnum = 0;
    char textline[256];

    puts("\n");

    // check for user-supplied input file and character to search for
    if (argc == 3) {
        if ((textfile = fopen(argv[2], "r")) == NULL) {
            fprintf(stderr, "Can't open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        ch = argv[1][0];       
    }
    else {
        fprintf(stderr, "Usage: %s [character] [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    while (fgets(textline, MAXSTLEN, textfile) != NULL) {
        while (textline[charnum] != ch && textline[charnum] != '\n')
            charnum++;
        if (textline[charnum] != '\n')
            fputs(textline, stdout);
        charnum = 0;
    }

    puts("Done searching file.");

    fclose(textfile);

    puts("\n");

    return 0;
}

