/* 15-atoi_new.c -- implements functionality of atoi() */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <locale.h>
#include <stdlib.h>
 
char * s_gets(char * st, int n);

int main(void)
{

    char numstring[20]; 
    int n;
    int oknum;
    int numint;
    int pow;
    int numdigits;
    char digchar;
    int digit;
    int neg;
 
    int num;
    setlocale(LC_NUMERIC, "");
    puts("\n");

    printf("INT_MAX = %'d\n", INT_MAX);
//    printf("INT_MAX + 1 = %'d\n", (INT_MAX + 1));
    printf("INT_MIN= %'d\n", INT_MIN);
//    printf("INT_MIN - 1 = %'d\n", (INT_MIN - 1));

//    printf("Environment Variable LC_NUMERIC = %s\n", getenv("LC_NUMERIC"));

//    num = atoi("2147483647");
//    printf("num = %'d\n", num);
  
//    num = 0;
//    num += (int)('1');
//    printf("num = %'d\n", num);

    printf("Enter an integer . . . ");
    s_gets(numstring, 20);
    n = 0;
    oknum = 1;
    numint = 0;
    pow = 1;
    numdigits = 0;
    neg = 0;

    while (numstring[n] != '\0'  && oknum) {
        numdigits++;
        digchar = numstring[n];
        if ((digchar == '-') && (n == 0)) {
            neg = 1;
            n++;
            continue;
        }
        if ((digchar < 48) || (digchar > 57)) {
            oknum = 0;
            printf("The number you entered wasn't an integer");
            printf(" or contained non-numeric characters.\n");
            continue;
        }
        if (numdigits > (10 + neg)) {
            oknum = 0;
            printf("The number you entered is too large to be stored ");
            printf("as an integer in this system.\n");
            continue;
        }
        n++;
    }
    if (oknum) {
        for (n = (numdigits - 1); n >= neg; n--) {
            digchar = numstring[n];
            digit = ((int)digchar) - 48;
            if (((n - neg) == 0) && (digit >= 2) && ((numint > 147483647) ||
                                                     (numint < -147483648))) {
                printf("The number you entered is too large to be stored ");
                printf("as an integer in this system.\n");
                oknum = 0;
                break;
            }
            if (neg)
                numint -= (pow * digit);
            else
                numint += (pow * digit);
            pow *= 10;
        }
    }
    if (oknum) {
        printf("numstring: ");
        for (n = 0; n < numdigits; n++) {
            printf("%c", numstring[n]);
            if ((n >= neg) && (((n + 1) % 3) == (numdigits % 3))
                          && (n < (numdigits - neg - 1)))
                printf(",");
        }
        printf("\n");
        printf("numint:    %'d\n", numint);
    }

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

