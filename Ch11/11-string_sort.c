/* 11-string_sort.c -- reads in up to 10 strings . . .                            */
/* Offers this menu                                                               */
/*   1 - Print the original list of strings                                       */
/*   2 - Print the strings in ASCII collating sequence                            */
/*   3 - Print the strings in order of increasing length                          */
/*   4 - Print the strings in order of the length of the first word in the string */
/*   5 - Quit                                                                     */

#include <stdio.h>
#include <string.h>

#define MAX 80


void print_menu(void);
char * print_orig_list(char str[][MAX], int n);
char * print_ASCII(char str[][MAX], int n);
char * print_inc_len(char str[][MAX], int n);
char * print_first_word_len(char str[][MAX], int n);
char * s_gets(char * st, int n);

int main(void)
{
    int i = 0;
    char choice[MAX];
    int n;            // TEMP CODE
    char str[10][MAX];     

    puts("\n");
    for (i = 0; i < MAX; i++)
        str[i][0] = '\0';

    i = 0;
    printf("Enter up to 10 strings.  If less than 10, type Ctrl-D to stop input.\n");
    while ((i < 10) && (s_gets(str[i], MAX))) {
        i++;
    }

    n = i;            // TEMP CODE
//    i = 0;            // TEMP CODE
//    while (i < n) {   // TEMP CODE
//        puts(str[i]); // TEMP CODE
//        i++;          // TEMP CODE
//    }                 // TEMP CODE
    do {
        print_menu();
        printf("Enter choice: ");
//        s_gets(choice, 2);
//        printf("s_gets worked; choice[0] = %c\n", choice[0]);
//        printf("choice: %d\n", atoi(choice));
        while (s_gets(choice, 2) && (atoi(choice) < 1 || (atoi(choice) > 5 ))) {
            printf("Enter a valid choice (1-5): "); 
            continue;
        }
        puts("\n");
        if ((atoi(choice)) == 1)
            print_orig_list(str, n);
        else if ((atoi(choice)) == 2)
            print_ASCII(str, n);
        else if ((atoi(choice)) == 3)
            print_inc_len(str, n);
        else if ((atoi(choice)) == 4)
            print_first_word_len(str, n);
        puts("\n");
    }
    while ((atoi(choice)) != 5);

    puts("\n");

    return 0;

}

void print_menu(void)
{
    printf("***********************************************************\n");
    printf("1 - Print original list of strings\n");
    printf("2 - Print the strings in ASCII collating sequence\n");
    printf("3 - Print the strings in order of increasing length\n");
    printf("4 - Print the strings in order of length of the first word\n");
    printf("5 - Quit the program\n");
    printf("***********************************************************\n");
}

char * print_orig_list(char str[][MAX], int n)
{
    int i = 0;

    for (i = 0; i < n; i++)
        puts(str[i]);
}

char * print_ASCII(char str[][MAX], int n)
{
    int order[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;
    int k;
    int temp;
    char temps[MAX];
    
    for (i = 1; i < n; i++) {
        temp = order[i];
        strcpy(temps, str[i]);
        k = i - 1;
        while ((strcmp(temps, str[order[k]]) < 0) && k >= 0) {
            order[k+1] = order[k];
            k--;
        }
       order[k+1] = temp;
    } 
    for (i = 0; i < n; i++)
        puts(str[(order[i])]);
}

char * print_inc_len(char str[][MAX], int n)
{
    int order[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;
    int k;
    int temp;
    char temps[MAX];
    
    for (i = 1; i < n; i++) {
        temp = order[i];
        strcpy(temps, str[i]);
        k = i - 1;
        while ((strlen(temps) < strlen(str[order[k]])) && k >= 0) {
            order[k+1] = order[k];
            k--;
        }
       order[k+1] = temp;
    } 
    for (i = 0; i < n; i++) 
        puts(str[(order[i])]);
}

char * print_first_word_len(char str[][MAX], int n)
{
    int order[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int first_word_len[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i;
    int k;
    int temp;
    int temp_ord;

    for (i = 0; i < n; i++) {
        k = 0;
        while (!isspace(str[i][k]) && str[i][k] != '\0')
            k++;
        first_word_len[i] = k;
    }

    for (i = 1; i < n; i++) {
        temp = first_word_len[i];
        temp_ord = order[i];
        k = i - 1;
        while ((temp < first_word_len[order[k]]) && k >= 0) {
            order[k+1] = order[k];
            k--;
        }
        order[k+1] = temp_ord;
    } 

    for (i = 0; i < n; i++) 
        puts(str[order[i]]);
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

