/* Q_09.c -- Answer to question 9 */

#include <stdio.h>
#include <ctype.h>

void showmenu(void);
int get_menuchoice(void);

int main(void)
{
    int choice;

    printf("\n\n");  // Blank lines for readability
    
    choice = (int)get_menuchoice();
    printf("\n");
    printf("The menu item chosen was: %d", choice);


    printf("\n\n");  // Blank lines for readability
    
    return 0;
}

void show_menu(void)
{

    printf("Please choose one of the following:\n");
    printf("1) copy files            2) move files\n");
    printf("3) remove files          4) quit\n");
    printf("Enter the number of your choice: ");
}

int get_menuchoice(void)
{
    int choice = 0;

    while (choice == 0) {
        show_menu();
        if (scanf("%d", &choice) != 1) 
            choice = 4;
        switch (choice) {
            case 1   :
            case 2   :
            case 3   :
            case 4   : break;
            default  : choice = 0;
                       break;
       }
    }
    return choice;
 }  
