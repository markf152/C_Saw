/* 08-char_check.c -- takes a character and zero or more */
/* file names as command line arguments.  If no file names */
/* are included as command line arguments, stdin is used. */
/* Program opens each file in turn and reports how many times */
/* the character supplied appears in the file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    char test_ch;
    char last_ch = 0;
    char ch;
    long int ch_count = 0;
    FILE * file;
    int i;

    puts("\n");

    if (argc < 2 || strlen(argv[1]) > 1) {
        printf("Usage: %s <ltr> [filename]...[filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ch = argv[1][0];  // take first char of first argument

    if (argc == 2) {
        puts("Enter text followed by <enter> twice in a row to end input.");
        test_ch = getc(stdin);
        while (!(test_ch == 10 && last_ch == 10)) {
            if (test_ch == ch)
                ch_count++;
            last_ch = test_ch;
            test_ch = getc(stdin);
        }
        printf("Character \"%c\" appears in 'stdin' %ld times.\n",
                ch, ch_count);
    }
    else {
        for (i = 2; i < argc; i++) {
            if ((file = fopen(argv[i], "r")) == NULL) {
                fprintf(stderr, "Can't open file %s.  Ignoring.\n", argv[i]);
                continue;
            }
            test_ch = getc(file);
            while (test_ch != EOF) {
                if (test_ch == ch)
                    ch_count++;
                test_ch = getc(file);
            }
            printf("Character \"%c\" appears in file %s %ld times.\n",
                    ch, argv[i], ch_count);
            ch_count = 0; 
            if (fclose(file) != 0) {
                printf("Could not close file %s\n", argv[i]);
                exit(EXIT_FAILURE);
            }
        }            
    }

    puts("\n");

    return 0;
}
