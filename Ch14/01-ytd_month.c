/* 01-ytd_month.c -- user enters the month number; returns the */
/* total number of days in the year up to and including that month */
/* "re-do Review Question 5, but make the argument the spelled-out */
/* name of the month instead of the month number. (Don't forget about */
/* strcmp().) */

#include <stdio.h>
#include <string.h>

struct month {
    char mname[10];
    char mabbr[4];
    int mdays;
    int mnmbr;
};

struct month months[12] = {
    {"January", "Jan", 31, 1},
    {"Februray", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

char * s_gets(char * st, int n);

int main(void)
{
    char mon[10];
    int i = 0;
    int totaldays = 0;

    puts("\n"); 

    puts("Enter the name of a month\n");
    s_gets(mon, 10);

    while (i < 12) {
        totaldays += months[i].mdays;
        if (strcmp(mon, months[i].mname) == 0)
            break;
        i++;
    }

    if (i == 12)
        puts("The name you entered isn't the name of a month");
    else
        printf("The number of days in the year through %s is %d.\n", mon, totaldays);

    puts("\n"); 
    
    return 0;

}

char * s_gets(char * st, int n)
{
    char * ret_val;
    int i = 0;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

