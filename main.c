#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct groceries {

    char type[50];
    char prod_name[50];
    char price[50];
} inventory[100];

int prod_counter;

void addProd(int valid_entry) {

    FILE *fp;

    int counter = 0;

    fp = fopen("INVENTORY.txt", "r");

    for (int i = 0; i < 100; i++) {

        fscanf(fp, "%s%s%s", inventory[i].prod_name, inventory[i].type, inventory[i].price);

        if (strcmp(inventory[i].prod_name, "") == 0) {

            break;
        }

        counter++;

        if (feof(fp)) {

            break;
        }
    }

    fclose(fp);

    if (counter < 100) {

        fp = fopen("INVENTORY.txt", "a");

        for (int i = 0; i < valid_entry; i++) {

            printf("\nEnter the name of the item: ");
            scanf(" %[^\n]", inventory[i].prod_name);
            fprintf(fp, "\n%s", inventory[i].prod_name);

            printf("Enter the type of the item: ");
            scanf(" %[^\n]", inventory[i].type);
            fprintf(fp, "\n%s", inventory[i].type);

            while(1) {

                int flag = 1;

                printf("Enter the price of the item: ");
                scanf(" %[^\n]", inventory[i].price);

                for (int j=0; inventory[i].price[j]!='\0'; j++) {

                    if (!(inventory[i].price[j]<='9' && inventory[i].price[j]>='0')) {

                        flag = 0;
                        printf("\nInvalid input. Please re-enter your price.\n");
                        break;
                    }
                }

                if (flag==1) {

                    break;
                }
            }

            fprintf(fp, "\n%s", inventory[i].price);

            counter++;

            if (counter == 100) {

                printf("\nNow your inventory is full. You cannot store more than 100 items.\n");
                break;
            }
        }

        fclose(fp);
    }

    else {

        printf("\nNow your inventory is full. You cannot store more than 100 items.\n");
    }
}

void viewProd() {

    struct groceries view_inventory[100];

    FILE *fp;
    int count = 0;

    fp = fopen("INVENTORY.txt", "r");

    while (1) {

        fscanf(fp, "%s%s%s", view_inventory[count].prod_name, view_inventory[count].type, view_inventory[count].price);
        count++;
        if (feof(fp))
        break;
    }

    for (int i = 0; i < count; i++) {

        printf("\n%s\n%s\n%s\n", view_inventory[i].prod_name, view_inventory[i].type, view_inventory[i].price);
    }

    fclose(fp);
}

void searchProd() {

    FILE *fp;
    char search_key[50];
    int count = 0;

    fp = fopen("INVENTORY.txt", "r");

    printf("\nEnter search key: ");
    scanf(" %[^\n]", search_key);

    while (1) {

        fscanf(fp, "%s%s%s", inventory[count].prod_name, inventory[count].type, inventory[count].price);

        if (strcmp(search_key, inventory[count].prod_name) == 0) {

            printf("\n%s\n%s\n%s\n", inventory[count].prod_name, inventory[count].type, inventory[count].price);
        }

        count++;

        if (feof(fp)) {
            
            break;
        }
    }

    fclose(fp);
}

void deletProd() {

    FILE *fp;
    int count = 0;
    char search_key[50];

    fp = fopen("INVENTORY.txt", "r");

    while (1) {

        fscanf(fp, "%s%s%s", inventory[count].prod_name, inventory[count].type, inventory[count].price);
        count++;

        if (feof(fp)) {

            break;
        }
    }

    fclose(fp);

    printf("\nEnter search key: ");
    scanf(" %[^\n]", search_key);
    fflush(stdin);

    int sk_idx;

    for (int i = 0; i < count; i++) {

        if (strcmp(search_key, inventory[i].prod_name) == 0) {

            sk_idx = i;
            break;
        }
    }

    for (int i = sk_idx; i < count - 1; i++) {

        strcpy(inventory[i].prod_name, inventory[i + 1].prod_name);
        strcpy(inventory[i].type, inventory[i + 1].type);
        strcpy(inventory[i].price, inventory[i + 1].price);
    }

    count--;

    fp = fopen("INVENTORY.txt", "w");

    for (int i = 0; i < count; i++) {

        fprintf(fp, "%s\n%s\n%s\n", inventory[i].prod_name, inventory[i].type, inventory[i].price);
    }

    fclose(fp);
}

void updateProd() {

    FILE *fp;
    int count = 0;
    char search_key[50];

    fp = fopen("INVENTORY.txt", "r");

    while (1) {

        fscanf(fp, "%s%s%s", inventory[count].prod_name, inventory[count].type, inventory[count].price);

        count++;

        if (feof(fp)) {

            break;
        }
    }

    fclose(fp);

    printf("Enter search key: ");
    scanf(" %[^\n]", search_key);
    fflush(stdin);

    char up_name[50], up_type[50], up_price[50];

    for (int i = 0; i < count; i++) {

        if (strcmp(search_key, inventory[i].prod_name) == 0) {

            printf("\nEnter the name of the item: ");
            scanf(" %[^\n]", up_name);
            fflush(stdin);
            strcpy(inventory[i].prod_name, up_name);

            printf("Enter the type of the item: ");
            scanf(" %[^\n]", up_type);
            fflush(stdin);
            strcpy(inventory[i].type, up_type);

            printf("Enter the price of the item: ");
            scanf(" %[^\n]", up_price);
            fflush(stdin);
            strcpy(inventory[i].price, up_price);
        }
    }

    fp = fopen("INVENTORY.txt", "w");

    for (int i = 0; i < count; i++) {

        fprintf(fp, "%s\n%s\n%s\n", inventory[i].prod_name, inventory[i].type, inventory[i].price);
    }

    fclose(fp);
}

void main_menu() {

    int main_no, valid_input, ret_ex;

    // MAIN MENU

    printf("\n\t# UNIX GROCERY MANAGEMENT SYSTEM #\n\n");

    printf("1.Add Products\n");
    printf("2.View Products\n");
    printf("3.Search Products\n");
    printf("4.Delete Products\n");
    printf("5.Update Products\n");

    printf("\nChoose any of the options above (enter the corresponding number): ");
    scanf("%d", &main_no);
    fflush(stdin);

    switch (main_no) {

        case 1:

            printf("\nEnter the number of items you would like to enter (must be less than 100): ");
            scanf("%d", &valid_input);
            fflush(stdin);

            prod_counter = valid_input;
            addProd(prod_counter);

            printf("\n0: Return to main menu\nPress anything to exit.\n");
            scanf("%d", &ret_ex);
            fflush(stdin);

            if (ret_ex == 0) {

                main_menu();
            }
            else {

                exit(0);
            }

            break;

        case 2:

            viewProd();

            printf("\n0: Return to main menu\nPress anything to exit.\n");
            scanf("%d", &ret_ex);
            fflush(stdin);

            if (ret_ex == 0) {

                main_menu();
            }
            else {
                
                exit(0);
            }

            break;

        case 3:

            searchProd();

            printf("\n0: Return to main menu\nPress anything to exit.\n");
            scanf("%d", &ret_ex);
            fflush(stdin);

            if (ret_ex == 0) {
            
                main_menu();
            }
            else {

                exit(0);
            }

            break;

        case 4:

            deletProd();

            printf("\n0: Return to main menu\nPress anything to exit.\n");
            scanf("%d", &ret_ex);
            fflush(stdin);

            if (ret_ex == 0) {
                
                main_menu();
            }
            else {

                exit(0);
            }

            break;

        case 5:

            updateProd();

            printf("\n0: Return to main menu\nPress anything to exit.\n");
            scanf("%d", &ret_ex);
            fflush(stdin);

            if (ret_ex == 0) {

                main_menu();
            }
            else {

                exit(0);
            }

            break;
    }
}

int main() {

    FILE *fp;

    int main_no, valid_input, ret_ex;

    main_menu();

    return 0;
}
