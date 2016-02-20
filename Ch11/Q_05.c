/* Q_05.c -- test program for Ch 11 Review Question 5 */

#include <stdio.h>

char * pr (char * str);

int main(void)
{
    char string[] = "Ho Ho Ho!";

    puts("\n\n");

    pr(string);

    puts("\n\n");

    return 0;
}

char * pr(char * str)
{
    char * pc;
    
    pc = str;

    while (*pc)
        putchar(*pc++);

    do {
        putchar (*--pc);
       } while (pc - str);

    return (pc);
}

