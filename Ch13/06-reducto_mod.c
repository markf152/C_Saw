/* 06-reducto_mod.c -- reduces your files by two-thirds! */
/* mod changes command line interface to interactive interface */

#include <stdio.h>
#include <stdlib.h>   // for exit()
#include <string.h>

#define LEN 40

char * s_gets(char * st, int n);

int main(int argc, char * argv[])
{
    FILE * in;
    FILE * out;
    int ch;
    char name[LEN];
    int count = 0;
    char target_file[LEN];

    puts("\n");
    
    puts("Enter name of file to reduce:");
    s_gets(target_file, LEN);
    if ((in = fopen(target_file, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", target_file);
        exit(EXIT_FAILURE);
    }

    // Set up output
    strncpy(name, target_file, LEN - 5);  // copy file name
    name[LEN-5] = '\0';
    strcat(name, ".red");             // append .red
    if ((out = fopen(name, "w")) == NULL) {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    // Copy data
    while ((ch = getc(in)) != EOF) 
        if (count++ % 3 == 0)
        putc(ch, out);  // Print every 3rd char

    // Clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    puts("\n");

    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if(ret_val) {
        find = strchr(st, '\n');    // look for newline
        if (find)                   // if the address is not NULL
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
