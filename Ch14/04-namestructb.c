//04-namestructb.c -- creates and initialize an array 5 structures:
//  1st member contains a social security number
//  2nd member contains s structure:
//    1st member contains a first name
//    2nd member contains a middle name
//    3rd member contains a last name

//  program prints the data in this format:
//  Last_Name, First_Name, MI. -- #########
//  MI is the middle initial created by taking the first character of the 
//    middle name and adding a period; it is skipped if the middle name is
//    empty

//  Text Location: 18113
//  Nested Strutures ... 16659

#include <stdio.h>
#define N 5

struct name {
    char first[30];
    char middle[30];
    char last[30];
};

struct person {
    int ssn;
    struct name persname;
};

void printpers(struct person printpers);

int main(void)
{
    int i;

    struct person perslist[N] = {
        { 756392965,
         {"Harold", "Allen", "Smith"},
        },
        { 297328265,
         {"Sally", "Anne", "Wilson"},
        },
        { 186349829,
         {"Spence", "", "Zorro"},
        },
        { 387129428,
         {"Terry", "Jean", "Burkowitz"},
        },
        { 752947629,
         {"Tiffany", "Lee", "Jones"},
        }
    };

    puts("\n");

//  Last_Name, First_Name, MI. -- #########
    
    for (i = 0; i < N; i++)
        printpers(perslist[i]);

    puts("\n");

    return 0;
}

void printpers(struct person printpers)
{
    printf("%s, %s, ", printpers.persname.last, printpers.persname.first);
    if (printpers.persname.middle[0] != '\0')
        printf("%c.", printpers.persname.middle[0]);
    printf(" -- %d\n", printpers.ssn);
}

