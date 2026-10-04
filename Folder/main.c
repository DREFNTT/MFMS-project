#include <stdio.h>
#include "suppliers.h"
#include "budget.h"
#include "employees.h"
#include "common.h"


int main(void)
{
    Supplier suppliers[MAX_SUPPLIERS];
    int supplierCount = 0;

    Budget budgets[MAX_DEPARTMENTS];
    int budgetCount = 0;

    int choice;

    do
    {
        printf("\n=====================================\n");
        printf(" Municipal Financial Management System\n");
        printf("=====================================\n");

       printf("1. Supplier Management\n");
printf("2. Budget Management\n");
printf("3. Employee Management\n");
printf("4. Exit\n");

        choice = getValidInteger("Enter your choice: ");

        switch (choice)
        {
            case 1:
            {
                int supplierChoice;

                do
                {
                    printf("\n--- Supplier Management ---\n");
                    printf("1. Add Supplier\n");
                    printf("2. Display Suppliers\n");
                    printf("3. Search Supplier\n");
                    printf("4. Compare Suppliers\n");
                    printf("5. Back to Main Menu\n");

                    supplierChoice = getValidInteger("Enter your choice: ");

                    switch (supplierChoice)
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
                            printf("\nReturning to Main Menu...\n");
                            break;

                        default:
                            printf("\nInvalid choice. Please try again.\n");
                    }

                } while (supplierChoice != 5);

                break;
            }

                       case 2:
                budgetMenu(budgets, &budgetCount);
                break;

            case 3:
            {
                int employeeChoice;

                do
                {
                    printf("\n--- Employee Management ---\n");
                    printf("1. Add Employee\n");
                    printf("2. Display Employees\n");
                    printf("3. Search Employee\n");
                    printf("4. Back to Main Menu\n");

                    employeeChoice = getValidInteger("Enter your choice: ");

                    switch (employeeChoice)
                    {
                        case 1:
                            addEmployee();
                            break;

                        case 2:
                            displayEmployees();
                            break;

                        case 3:
                            searchEmployee();
                            break;

                        case 4:
                            printf("\nReturning to Main Menu...\n");
                            break;

                        default:
                            printf("\nInvalid choice. Please try again.\n");
                    }

                } while (employeeChoice != 4);

                break;
            }

            case 4:
                printf("\nExiting Municipal Financial Management System...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}