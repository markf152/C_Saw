/* Q_04.c -- takes floating point numbers from a user-specified file */
/* or stdin if no file is specified and calculates the arithmetic mean */

#include <stdio.h>

int main (int argc, char * argv[])
{

    FILE * numfile;
    float total;
    int numcount = 0;
    float num;

    puts("\n");

    // check for user-supplied input file
    if (argc < 2) 
        numfile = stdin;
    else
        numfile = fopen(argv[1], "r");

    while (fscanf(numfile, "%f", &num) != EOF) {
        total += num;
        numcount++;
    }

    printf("%d floating point values read in.  The average of those is: %.4f\n",
           numcount, (total / (float)numcount));

    puts("\n");

    return 0;
}

