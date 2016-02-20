/* find_string.c -- finds and prints all instances of a string found */
/* within a file.  User supplies both the file name and the string   */
/* to be searched for via command line arguments                     */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 81
#define MAXINTLEN 16
#define MAXSTRLEN 256

int main(int argc, char * argv[])
{
    FILE * file;
    char * strptr;      
    char string[MAXSTRLEN];

    puts("\n");

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename search-string\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("In the file \"%s\", the requested search string \"%s\" was found in ",
            argv[1], argv[2]);
    printf("the following lines:\n");
    while ((strptr = fgets(string, MAXSTRLEN, file)) != NULL) {
        if (strstr(string, argv[2]))
            puts(string);
    }
 
    fclose(file);

    puts("\n");

    return 0;
}

