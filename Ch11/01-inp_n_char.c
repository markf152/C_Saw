/* 01-inp_n_char.c -- input the first n characters, including */
/* blanks, tabs and newlines; store results in an array whose */
/* address is passed as an argument */

char * in_n_char(char * input, int n);







char * in_n_char(char * input, int n)
{
    int x;

    for (x = 0; x < n; x++) {
        input[x] = getchar();
    }
   return input;
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
