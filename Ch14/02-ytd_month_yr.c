/* 02-ytd_month_yr.c -- uaer inputs the day, month and year */
/* program returns the total number of days in the year up through */
/* the given day. Program takes into account leap years */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
    int day = 0;
    char monthname[10];
    int month = 0;
    int year = 0;
    int totaldays = 0;
    int i = 0;
    int day_ok = 0;
    char * charptr;  // needed for strtol(); otherwise unused
    char strinput[10]; 
    
    puts("\n");

    puts("This program takes the day, month and year as input");
    puts("and returns the total number of days in the year through");
    puts("that day.\n");

    do {
        puts("Enter the 4-digit year (e.g. 2015):");
        s_gets(strinput, 5);
        if isdigit(strinput[0])
            year = (int)strtol(strinput, &charptr, 10);
    } while (year < 1);

    do {
        puts("Enter the month (e.g. January, Jan or 1):");
        s_gets(strinput, 10);
        if isdigit(strinput[0]) 
            month = strtol(strinput, &charptr, 10);
        else {
            strcpy(monthname, strinput);
            while (i < 12) {
                if ((strcmp(monthname, months[i].mname) == 0) ||
                    (strcmp(monthname, months[i].mabbr) == 0)) {
                        month = i + 1;
                        break;
                }    
                i++;
            }
        }
    } while (month < 1 && month > 12);
    
    do {
        puts("Enter the day (e.g. for the 3rd, enter 3):");
        s_gets(strinput, 3);
        if isdigit(strinput[0]) {
            day = strtol(strinput, &charptr, 10);
            if ((day >= 1 && day <= months[(month-1)].mdays) ||
                (month == 2 && day == 29 && ((year % 4) == 0)))
                day_ok = 1;
        }
    } while (!day_ok);

    for (i = 0; i < (month-1); i++) {   // count up days from earlier months
        totaldays += months[i].mdays;
        if (((year % 4) == 0) && (i == 1))
            totaldays++;                // add 1 for leap-year Feb
    }
    totaldays += day;  // add in days for current month

    printf("The year-to-date count of days through %4d %2d %2d is: %d\n",
            year, month, day, totaldays);

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

