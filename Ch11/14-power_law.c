/* 14-power_law.c -- echoes command line arguments in reverse order */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[])
{

    int i;
    char *ptr1;
    char *ptr2;

    puts("\n");

//    printf("argc = %d\n", argc);

//    for (i = (argc - 1); i > 0; i--)
//        printf("%s ", argv[i]);
    printf("%f raised to the %ld power = %f\n",
     (strtod(argv[1], &ptr1)), (strtol(argv[2], &ptr2, 10)),
     (pow((strtod(argv[1], &ptr1)), ((double)(strtol(argv[2], &ptr2, 10))))));


    puts("\n");
}

