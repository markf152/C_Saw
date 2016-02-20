/* ptr_test.c -- testing some sample code in the book */
/*  . . . "Pointer Compatibility" in Ch 10 */

#include <stdio.h>

int main(void)
{

    // const int **pp2;
    int **pp2;
    int *p1;
    const int n = 13;
    // int n = 13;

    printf("\n\n");

    printf("&p1  = %p\n", &p1);
    printf("pp2  = %p\n", pp2);
    // printf("*pp2 = %p\n", *pp2);
    printf("*p1 = %d\n", *p1);
    printf("(Note: *p1 hasn't been assigned . . .\n");
    printf(" . . . and really shouldn't be dereferenced yet.)\n\n");

    printf("Setting pp2 = &p1\n");
    pp2 = &p1;  // allowed, but const qualifier disregarded
    printf("pp2 = %p\n\n", pp2);
    printf("*pp2 = %p\n", *pp2);

    printf("Setting *pp2 = &n\n");
    *pp2 = &n;  // valid, both const, but sets p1 to point at n
    printf("&n   = %p\n", &n);
    printf("*pp2 = %p\n", *pp2);
    printf("n = %d\n", n);
    printf("**pp2 = %d\n\n", **pp2);

    printf("Setting **pp2 = 4\n");
    **pp2 = 4;
    printf("n = %d\n", n);
    printf("**pp2 = %d\n\n", **pp2);

    printf("Setting *p1 = 10\n");
    *p1 = 10;   // valid, but tries to change const n
    printf("*p1 = %d\n", *p1);

    printf("\n\n");

    return 0;
}

