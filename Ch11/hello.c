/* hello.c -- converts command-line argument to number */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int i;
    int times;

    puts("\n\n");

    if (argc < 2 || (times = atoi(argv[1])) < 1)
        printf("Usage: %s positive-number\n", argv[0]);
    else
        for (i = 0; i < times; i++)
            puts("Hello!");

    printf("\n");

    printf("argv[0] = %s\n\n", argv[0]);

    i = atoi("Hello");
    printf("atoi(\"Hello\") = %d", i);

    puts("\n\n");

    return 0;
}

