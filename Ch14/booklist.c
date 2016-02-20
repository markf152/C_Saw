// 03-booklist.c -- revised version of the program from (manybook.c) listing 14.2

// This program places a list of books (title, author and value) into
// an array of structures.
// It prints the listings in:
//    (1) in  the order entered
//    (2) alphabetized by title
//    (3) in order of increasing value

#include <stdio.h>
#include <string.h>

char * s_gets(char * st, int n);

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;

    puts("\n");

    printf("Please enter the book title.\n");
    printf("Press <enter> at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0') {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;   // clear input line
        if (count < MAXBKS)
        printf("Enter the next title.\n");
    }

    if (count > 0) {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                    library[index].author, library[index].value);
    }
    else
        printf("No books?  Too bad.\n");

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

