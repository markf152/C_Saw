/* addaword_mod.c -- uses fprintf(), fscanf(), and rewind() */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main(void)
{
    FILE * fp;
    char words[MAX];
    long int word_count = 0;
    int num;

    puts("\n");

    if ((fp = fopen("wordy", "a+")) == NULL) {
        fprintf(stderr, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

//    num = fscanf(stdin, "%ld %s", &word_count, words);
//    printf("num = %d\n", num);
    while (fscanf(fp,"%ld %s", &word_count, words) == 2) {
//        printf("word_count = %ld\n", word_count);
        continue;
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin, "%40s", words) == 1) &&
            (words[0] != '#')) {
        fprintf(fp, "%ld %s\n", ++word_count, words);
    }
        
    puts("File contents:");
    rewind(fp);              // back to the beginning of the file
    while (fscanf(fp,"%ld %s", &word_count, words) == 2)
        fprintf(stdout, "%ld %s\n", word_count, words);

    puts("Done!");

    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    puts("\n");

    return 0;
}

