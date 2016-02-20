//04-namestructa.c -- creates and initialize an array 5 structures:
//  1st member contains a social security number
//  2nd member contains a structure:
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

void printperslist(struct person printpers[], int num);

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

    printperslist(perslist, N);

    puts("\n");

    return 0;
}


void printperslist(struct person printpers[], int num)
{
    int i;

    for (i = 0; i < num; i++) { 
        printf("%s, %s, ", printpers[i].persname.last, printpers[i].persname.first);
        if (printpers[i].persname.middle[0] != '\0')
            printf("%c.", printpers[i].persname.middle[0]);
        printf(" -- %d\n", printpers[i].ssn);
    }
}

