/* friend_ptr.c -- example of a nested structure */

#include <stdio.h>

#define LEN 20

const char * msgs[5] = 
{
    "    Thank you for the wonderful evening, ",
    "You certainly prove that a ",
    "is a special kind of guy. We must get together",
    "over a delicious ",
    " and have a few laughs"
};

struct names {
    char first[LEN];
    char last[LEN];
};

struct pnames {
    char * first;
    char * last;
};

struct guy {
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void)
{
    struct guy fellow = {
        { "Ewen", "Villard" },
        "grilled salmon",
        "personality coach",
        68112.00
    };

    struct names pers1 = {
         "Bob", "Smith"
    };

    struct pnames pers2 = {
         "Bob", "Smith" 
    };

    int * int_ptr;

    puts("\n");

    printf("sizeof(int_ptr) = %ld (pointer to int)\n", sizeof(int_ptr));
    printf("sizeof(pers1) = %ld (names structure)\n", sizeof(pers1));
    printf("sizeof(pers2) = %ld (structure made of 2 pointers)\n\n", sizeof(pers2));

    printf("Dear %s, \n\n", fellow.handle.first);
    printf("%s%s.\n", msgs[0], fellow.handle.first);
    printf("%s%s\n", msgs[1], fellow.job);
    printf("%s\n", msgs[2]);
    printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);

    if (fellow.income > 150000.0)
        puts("!!");
    else if (fellow.income > 75000.0)
       puts("!");
    else
       puts(".");
    printf("\n%40s%s\n", " ", "See you soon,");
    printf("%40s%s\n", " ", "Shalala");

    puts("\n");

    return 0;
}

