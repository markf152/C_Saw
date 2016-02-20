/* zeno.c -- series sum */

#include <stdio.h>

int main(void)
{
    int t_ct;  /* term count */
    double time;
    double power_of_2;
    int limit;

    printf("\n\n");  /* Blank lines for readability */
    
    printf("Enter the number of terms you want: ");
    scanf("%d", &limit);
    
    for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit; 
          t_ct++, power_of_2 *= 2.0) {
        time += 1.0 / power_of_2;
        printf("time = %f when terms = %d.\n", time, t_ct);
    }

    printf("\n\n");  /* Blank lines for readability */

    return 0;
}

