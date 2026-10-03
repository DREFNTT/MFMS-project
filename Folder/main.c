#include <stdio.h>
#include "suppliers.h"
#include "common.h"

int main(void)
{
    Supplier suppliers[MAX_SUPPLIERS];
    int supplierCount = 0;
    int choice;

    do
    {
        printf("\n=====================================\n");
        printf(" Municipal Financial Management System\n");
        printf("=====================================\n");

        printf("\n--- Supplier Management ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Compare Suppliers\n");
        printf("5. Exit\n");

       choice = getValidInteger("Enter your choice: ");
        
        switch (choice)
        {
            case 1:
                addSupplier(suppliers, &supplierCount);
                break;

            case 2:
                displaySuppliers(suppliers, supplierCount);
                break;

            case 3:
                searchSupplier(suppliers, supplierCount);
                break;

            case 4:
                compareSuppliers(suppliers, supplierCount);
                break;

            case 5:
                printf("\nExiting Supplier Management...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}