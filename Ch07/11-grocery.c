/* 11-grocery.c -- program takes a grocery order, applies discounts as needed */
/* calculates the total order and outputs appropriate information regarding   */
/* the order, including total cost, pounds ordered, etc                       */

#include <stdio.h>
#include <string.h>

#define ARTICHOKES 2.05
#define BEETS      1.15
#define CARROTS    1.09
#define DISCOUNT   0.05

int printmenu(void);

int main(void)
{
    float lbs = 0.0;
    float artichokes = 0.0;
    float beets = 0.0;
    float carrots = 0.0;
    float totalweight = 0.0;
    float totalcharges = 0.0;
    float grandtotal = 0.0;
    float discount = 0.0;
    float shipping = 0.0;
    char choice;
    char choicename[25];

    printf("\n\n");  // Blank lines for readability

    printmenu();
    scanf("%c", &choice);

    while (choice != 'q') {
        switch (choice) {
            case 'a' :
                strncpy(choicename, "artichokes", 25);
                break;
            case 'b' :
                strncpy(choicename, "beets", 25);
                break;
            case 'c' : 
                strncpy(choicename, "carrots", 25);
                break;
            case 'q' :
                break;
        }
        printf("Enter the number of pounds of %s: ", choicename);
        scanf("%f", &lbs);
        switch (choice) {
            case 'a' :
                artichokes += lbs;
                break;
            case 'b' :
                beets += lbs;
                break;
            case 'c' : 
                carrots += lbs;
                break;
            default :
                break;
        }
        printmenu();
        scanf("%c", &choice);
        scanf("%c", &choice);
        printf("Choice: %c\n", choice);
    }

    totalweight = artichokes + beets + carrots;
    totalcharges = (artichokes * ARTICHOKES) + (beets * BEETS) + (carrots * CARROTS);
    if (totalcharges > 100.00)
        discount = totalcharges * 0.05;
    if (totalweight <= 5.00)
        shipping = 6.50;
    else if (totalweight < 20)
        shipping = 14.00;
    else 
        shipping = 14.00 + (totalweight * 0.50);
    grandtotal = totalcharges - discount + shipping;
    
    printf("Here is your order information:\n");
    printf("Cost per pound: %.2f\n", (grandtotal / totalweight));
    printf("Pounds ordered: %.2f\n\n", totalweight);
    printf("Cost for artichokes: %.2f\n", (artichokes * ARTICHOKES));
    printf("Cost for beets: %.2f\n", (beets * BEETS));
    printf("Cost for carrots: %.2f\n", (carrots * CARROTS));
    printf("-----------------------------\n");
    printf("Total cost of order: %.3f\n", totalcharges);
    printf("Discount: %.3f\n", discount);
    printf("Shipping charge: %.3f\n", shipping);
    printf("=============================\n");
    printf("Grand Total: %.2f\n", grandtotal);

    printf("\n\n");  // Blank lines for readability

    return 0;
}

int printmenu(void)
{
    printf("******************************\n");
    printf("Enter item number (q to quit)\n");
    printf("a) Artichokes ($2.05 / lb)\n");
    printf("b) Beets ($1.15 / lb)\n");
    printf("c) Carrots ($1.15 / lb)\n");
    printf("q) Finished with order\n");
    printf("******************************\n\n");
}
