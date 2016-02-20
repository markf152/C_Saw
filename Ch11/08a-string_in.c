/* Programming Exercise 11-8 */

#include <stdio.h>
#include <string.h>

#define LEN 20

char * string_in(const char * s1, const char * s2);

int main(void)
{
    char orig[LEN] = "transportation";
    char * find;

    puts("\n");

    puts(orig);

    find = string_in(orig, "port");
    if (find)
        puts(find);
    else
        puts("Not found");

    find = string_in(orig, "part");
    if (find)
        puts(find);
    else
        puts("Not found");

    puts("\n");

    return 0;
}

char * string_in(const char * s1, const char * s2)
{
    int l2 = strlen(s2);
    int tries;
    int nomatch = 1;

    tries = strlen(s1) + 1 - l2;
    if (tries > 0)
        while (( nomatch = strncmp(s1, s2, l2)) && tries --)
            s1++;
    if (nomatch)
        return NULL;
    else
        return (char *) s1;
}

