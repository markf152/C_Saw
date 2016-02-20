/* r_drive1a.c -- test rand1() and srand1() */
/* compile with s_and_r.c                  */

#include <stdio.h>

extern void srand1(unsigned int x);
extern int rand1(void);

int main(void)
{
    int count;
    unsigned seed;
    int cont = 1;
    char redo = 'y';

    puts("\n");

//    printf("Please enter your choice for seed.\n");
    while (cont) {
        srand1((unsigned int)time(0));    /* reset seed */
        for (count = 0; count < 5; count++)
            printf("%d\n", rand1());
        printf("Hit <enter> to re-run with a new seed or q, then <enter> to quit):\n");
        scanf("%c", &redo);
        if (redo == 'q')
            cont = 0;
    }

    printf("Done.\n");

    puts("\n");

    return 0;
}

