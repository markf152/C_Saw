/* 10-print_part.c -- opens a file whose name is obtained interactively */
/* Loop:                                                                */
/* User enters a file position. Program prints the part of the file     */
/* starting at that position and ending at the next newline character   */
/* Negative or non-numeric input terminates the loop                    */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 81
#define MAXINTLEN 16
#define MAXSTRLEN 1024

char * s_gets(char * st, int n);

int main(void)
{
    char file_name[MAXLEN];
    FILE * file;
    long int fpos = 0;
    char fposstr[MAXINTLEN];
    char * strptr;           // pointer for strttol() -- not used otherwise
    char string[MAXSTRLEN];
    int test;

    puts("\n");

    puts("Enter the name of the file to use . . .");
    s_gets(file_name, MAXLEN);
    if ((file = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    puts("Enter the position in the file where you want to start reading.");
    puts("The program will read from that point until the next new line");
    puts("character or End of File (EOF)");
    fgets(fposstr, MAXINTLEN, stdin);
    fpos = strtol(fposstr, &strptr, 10) - 1;  // -1 for to make first char 0 vice 1
    
    while (fpos >= 0) {
        if (0 != fseek(file, fpos, SEEK_SET)) {
            puts("Unable to read the file. Exiting program.");
            exit(EXIT_FAILURE);
        }
        fgets(string, MAXSTRLEN, file);
        putchar('\n');
        printf("The contents of the file starting at position %ld are: \n%s",
              fpos, string);
        putchar('\n');
        puts("Enter the position in the file where you want to start reading.");
        puts("The program will read from that point until the next new line");
        puts("character or End of File (EOF)");
        puts("(enter a negative number or non-numeric char to quit)");
        fgets(fposstr, MAXINTLEN, stdin);
        fpos = strtol(fposstr, &strptr, 10) - 1;  // -1 for to make first char 0 vice 1
        printf("fpos: %ld\n", fpos);
    }

    puts("\n");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

