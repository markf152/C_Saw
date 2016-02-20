//07-booksave.c -- modificatin of listing 14.14 (loc 17304)

//Programming Exercise - loc 18152

// TEST TEST TEST 123


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

char * s_gets(char * st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    char change ;
};

int main(void)
{
    struct book library[MAXBKS];
    int count = 0;
    int index;
    int filecount;
    int fileEmpty = 0;
    FILE * pbooks;
    int size = sizeof(struct book);
    int i;
    int j = 0;
    char chgdel[5];
    char chgtitl[MAXTITL];
    char chgauth[MAXAUTL];
    char chgvalue[21];
    float newvalue;

    puts("\n");

    if ((pbooks = fopen("07-book.dat", "r+b")) == NULL)
        if ((pbooks = fopen("07-book.dat", "wb")) == NULL){
            fputs("Can't open or create 07-book.dat file\n", stderr);
            exit(1);
        }
        else
            fileEmpty = 1;

    if (!fileEmpty) {
        rewind(pbooks);
        while (count < MAXBKS && fread(&library[count], size,
                                       1, pbooks) == 1)       {
            if (count == 0)
                puts("Current contents of book.dat:");
            printf("%s by %s: $%.2f\n", library[count].title,
                    library[count].author, library[count].value);
            library[count].change = 'k';
            printf("Type 'm' to modify this entry or 'del' to remove\n");
            printf("this book from the list or <return> to move to the next entry\n");
            s_gets(chgdel, 4);
            if ((strcmp(chgdel, "del") == 0) || (strcmp(chgdel, "DEL") == 0)) {
                puts("Marking for delete.\n");
                library[count].change = 'd';
            }
            if ((strcmp(chgdel, "m") == 0) || (strcmp(chgdel, "M") == 0)) {
                printf("Update the title or hit <return> to leave unchanged\n");
                s_gets(chgtitl, MAXTITL);
                if (strlen(chgtitl) > 0) 
                    strcpy(library[count].title, chgtitl);
                printf("Update the author or hit <return> to leave unchanged\n");
                s_gets(chgauth, MAXAUTL);
                if (strlen(chgauth) > 0)
                    strcpy(library[count].title, chgtitl);
                printf("Update the value or hit <return> to leave unchanged\n");
                s_gets(chgvalue, 20);
                if (strlen(chgvalue) > 0) {
                    newvalue = atof(chgvalue);
                    if (newvalue >= 0)
                        library[count].value = newvalue;
                }
            }
            count++;
        }
    }

    fclose(pbooks);

    for (i = 0; i < count; i++) 
        if (library[i].change != 'd') 
            library[j++] = library[i];

    filecount = j;
    count = j;

    if (count == MAXBKS) {
        fputs("The book.dat file is full.", stderr);
    }

    puts("");

    puts("Please add new book titles.");
    puts("Press <enter> at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0') {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count].value);
        while (getchar() != '\n')
            continue;   // clear input line
        library[count].change = 0;
        count++;
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0) {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                    library[index].author, library[index].value);

        // write book info to file
        if ((pbooks = fopen("07-book.dat", "wb")) == NULL){
            fputs("Can't open '07-book.dat' file for writing.\n", stderr);
            exit(1);
        }
        fwrite(&library[0], size, count,
               pbooks);
    }
    else
        printf("No books?  Too bad.\n");

    fclose(pbooks);

    puts("\nBye.");

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
