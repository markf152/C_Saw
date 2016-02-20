/* 02-file_copy.c -- copies a file. Name of copy file and copy-to file */
/* supplied by user as command-line arguments */
/* standard I/O and binary mode are used */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXFINAME 256
#define BUFSIZE 4096

int main (int argc, char * argv[])
{
    FILE * src;
    FILE * dst;
    char readbuf[BUFSIZE];
    size_t bytesread = 0;
    size_t numwritten = 0;
    size_t lastread = 0;
    char ch;

    puts("\n");

    // check for enough command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source filename> <destination filename>\n\n", 
                argv[0]);  
        exit(EXIT_FAILURE);
    }

    // check to make sure source and destination aren't the same
    if (strcmp(argv[1], argv[2]) == 0) {
        fprintf(stderr, "No point in copying a file to itself.  Exiting.  Bye.\n\n");
        exit(EXIT_FAILURE);
    }

    // open the source file
    if ((src = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Could not open the file \"%s\"\n\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // open the destination file
    if ((dst = fopen(argv[2], "wbx")) == NULL) {
        fprintf(stderr, "File %s may already exist. Enter 'y' to overwrite.\n",
                argv[2]);
        ch = getchar();
        if (ch == 'y') {
            if ((dst = fopen(argv[2], "wb+")) == NULL) {
                fprintf(stderr, "Could not open the file \"%s\"\n\n", argv[2]);
                exit(EXIT_FAILURE);
            }
        }
        else {
            fprintf(stderr, "Exiting without copying file.  Bye.\n");
            exit(EXIT_FAILURE);
        }
    }

    // copy the file now!
    while ((bytesread = fread(readbuf, sizeof(char), BUFSIZE, src)) > 0) {
        numwritten = fwrite(readbuf, sizeof(char), bytesread, dst);
        lastread = bytesread;
    }

//    printf("Bytes read: %zd\n", lastread);
//    printf("Bytes written: %zd\n", numwritten);

    if (numwritten ==  lastread)
        printf("File copied!  Bye.\n");
    else
        fprintf(stderr, "There was an error copying the file.\n");

    puts("\n");

    return 0;

}

