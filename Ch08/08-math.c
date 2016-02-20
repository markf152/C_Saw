/* 08-math.c -- performs addition, subtraction, multiplication and division */
/* on floating point numbers supplied by the user */

#include <stdio.h>
#include <ctype.h>

char get_op_type(void);
float get_num(int op_num);
void clean_buffer(void);
void print_result(float op1, float op2, char op_type, float res);

int main(void)
{
    char operation = 'x';
    float oper_1 = 0;
    float oper_2 = 0;
    float result = 0;

    printf("\n\n");  // Blank lines for readability
    
    while ((operation = get_op_type()) != 'q') {
        oper_1 = get_num(1);
        oper_2 = get_num(2); 
        switch (operation) {
            case 'a' : 
                result = oper_1 + oper_2;
                break;
            case 's' :
                result = oper_1 - oper_2;
                break;
            case 'm' :
                result = oper_1 * oper_2;
                break;
            case 'd' :
                while (oper_2 == 0) {
                    printf("\nYou can't divide by zero, enter another divisor.\n");
                    oper_2 = get_num(2);
                }
                result = oper_1 / oper_2;
                break;
        }
        print_result(oper_1, oper_2, operation, result);
        clean_buffer(); 
    }
                     
    printf("\n\n");  // Blank lines for readability

    return 0;

}

char get_op_type(void)
{
    char menu_choice;
    int choice_ok = 0;

    printf("\n");

    choice_ok = 0;

    while (! choice_ok) {
        printf(" ---------------------------------\n");
        printf("|  A - Add          S - Subtract  |\n");
        printf("|  M - Multiply     D - Divide    |\n");
        printf("|       Q - Quit Program          |\n");
        printf(" ---------------------------------\n\n");
        printf("Enter your choice: ");
        scanf("%c", &menu_choice);
        choice_ok = 1;
        switch (menu_choice) {
            case 'A' :
            case 'a': 
                menu_choice = 'a';
                break;
            case 'S' :
            case 's' :
                menu_choice = 's';
                break;
            case 'M' :
            case 'm' :
                menu_choice = 'm';
                break;
            case 'D' :
            case 'd' :
                menu_choice = 'd';
                break;
            case 'Q' :
            case 'q' :
                menu_choice = 'q';
                break;
            default  :
                choice_ok = 0;
                printf("\n");
                clean_buffer();
        }
    }
    return menu_choice;
}

float get_num(int op_num)
{
    float operand = 0.0;

    printf("Enter operand %d: ", op_num);
    while (scanf("%f", &operand) != 1) {
        printf("\n"); 
        printf("Enter operand %d: ", op_num);
    }
    return operand;
}

void clean_buffer(void)
{
    while (getchar() != '\n')
        continue;
} 

void print_result(float op1, float op2, char op_type, float res)
{
    
    printf("%.3f ", op1);
    switch (op_type) {
        case 'a' :
            printf("+ ");
            break;
        case 's' :
            printf("- ");
            break;
        case 'm' :
            printf("* ");
            break;
        case 'd' :
            printf("/ ");
            break;
    }
    printf("%.3f = %.3f\n", op2, res);
}

