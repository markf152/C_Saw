/* 07-combine_lines.c -- prints lines from two files such that */
/* line 1 of file 1 is printed, then line 1 of the second file */
/* then line 2 of file 1, then line 2 of file 2, then . . . . */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int argc, char * argv[])
{
    FILE * file1;
    FILE * file2;
    bool reading_f1 = true;
    bool reading_f2 = true;
    long pos1 = 0;
    long pos2 = 0;
    long len1;
    long len2;
    char ch = ' ';

    puts("\n");

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <file 1> <file 2>\n",
                         argv[0]);
        exit(EXIT_FAILURE);
    }

    // open two files
    if ((file1 = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((file2 = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    fseek(file1, 0L, SEEK_END);
    len1 = ftell(file1);
    printf("len1 = %ld\n", len1);

    fseek(file2, 0L, SEEK_END);
    len2 = ftell(file2);
    printf("len2 = %ld\n", len2);

//    printf("%d\n", '\n');

    // loop through both files
    while (reading_f1 || reading_f2) {
        while (reading_f1 && ch !='\n' && ch !=EOF) {
            fseek(file1, pos1, SEEK_SET);
            ch = getc(file1);
//            if (ch < 32 || ch > 126)
//                printf("(%d)", ch);
            if (ch != '\n')
                putc(ch, stdout);
            if (ch == EOF || pos1 == (len1 - 1)) {
                reading_f1 = false;
            }
            pos1++;
        }
        ch = ' ';        
        while (reading_f2 && ch !='\n' && ch !=EOF) {
            fseek(file2, pos2, SEEK_SET);
            ch = getc(file2);
//            if (ch < 32 || ch > 126)
//                printf("(%d)", ch);
            if (ch != '\n')
                putc(ch, stdout);
            if (ch == EOF || pos2 == (len2 - 1))
                reading_f2 = false;
            pos2++;
        }
        ch = ' ';
        putc('\n', stdout);
    }
    
    if (fclose(file1) != 0)
        printf("Could not close file %s\n", argv[1]);
    if (fclose(file2) != 0)
        printf("Could not close file %s\n", argv[2]);

    puts("\n");

    return 0;
}

