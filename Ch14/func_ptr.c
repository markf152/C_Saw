// func_ptr.c -- uses function pointers

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 81

char * s_gets(char * st, int n);

char showmenu(void);
void eatline(void);   // read through end of line
void show(void (* fp)(char *), char * str);
void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);

int main(void)
{
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *);  // points to a function having a
                           // char * argument and no return value

    puts("\n");

    puts("Enter a string (empty line to quit):");
    while (s_gets(line, LEN) != NULL && line[0] != '\0') {
        while ((choice = showmenu()) != 'n') {
            switch (choice  ) {   // switch sets pointer 
                case 'u' : pfun = ToUpper;    break;
                case 'l' : pfun = ToLower;    break;
                case 't' : pfun = Transpose;  break;
                case 'o' : pfun = Dummy;      break;
            }
            strcpy(copy, line);  // make copy for show()
            show(pfun, copy);    // use selected function
        }
        puts("Enter a string (empty line to quit):");
    }
    puts("Bye!");

    puts("\n");

    return 0;
}

char showmenu(void)
{
    char ans;
    puts("");
    puts("Enter menu choice:");
    puts("u) uppercase         l) lowercase");
    puts("t) transposed case   o) original case");
    puts("n) next string");
    ans = getchar();
    ans = tolower(ans);
    eatline();
    while (strchr("ulton", ans) == NULL) {
        puts("Please enter a, u, l, t, o, or n:");
        ans = tolower(getchar());
        eatline();
    }

    return ans;
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

void ToUpper(char * str)
{
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}
 
void ToLower(char * str)
{
    while(*str) {
        *str = tolower(*str);
        str++;
    }
}

void Transpose(char * str)
{
    while(*str) {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}

void Dummy(char * str)
{
    // leaves string unchanged
}

void show(void (*fp)(char *), char * str)
{
    (*fp)(str);
    puts(str);
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

