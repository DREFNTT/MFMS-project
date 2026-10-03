#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "common.h"

void addSupplier(Supplier suppliers[], int *count)
{
    if (*count >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    printf("\n--- Add Supplier ---\n");

    suppliers[*count].supplierID = getValidPositiveInteger("Enter supplier ID: ");

  getValidNonEmptyString("Enter supplier name: ",
                       suppliers[*count].name,
                       sizeof(suppliers[*count].name));
                       
    printf("Enter supplier email: ");
    fgets(suppliers[*count].email, sizeof(suppliers[*count].email), stdin);
    suppliers[*count].email[strcspn(suppliers[*count].email, "\n")] = '\0';

    printf("Enter supplier telephone: ");
    fgets(suppliers[*count].telephone, sizeof(suppliers[*count].telephone), stdin);
    suppliers[*count].telephone[strcspn(suppliers[*count].telephone, "\n")] = '\0';

    printf("Enter supplier town: ");
    fgets(suppliers[*count].town, sizeof(suppliers[*count].town), stdin);
    suppliers[*count].town[strcspn(suppliers[*count].town, "\n")] = '\0';

    (*count)++;

    printf("Supplier added successfully.\n");
}

void displaySuppliers(Supplier suppliers[], int count)
{
    printf("\n--- Supplier List ---\n");

    if (count == 0)
    {
        printf("No suppliers available.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("ID: %d\n", suppliers[i].supplierID);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Telephone: %s\n", suppliers[i].telephone);
        printf("Town: %s\n", suppliers[i].town);
    }
}

void searchSupplier(Supplier suppliers[], int count)

{
    

    int id;
    int found = 0;

    printf("\n--- Search Supplier ---\n");
    id = getValidPositiveInteger("Enter supplier ID: ");

    for (int i = 0; i < count; i++)
    {
        if (suppliers[i].supplierID == id)
        {
            printf("\nSupplier found:\n");
            printf("ID: %d\n", suppliers[i].supplierID);
            printf("Name: %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].telephone);
            printf("Town: %s\n", suppliers[i].town);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Supplier not found.\n");
    }
}

void compareSuppliers(Supplier suppliers[], int count)
{
    if (count < 2)
    {
        printf("\nAt least two suppliers are required for comparison.\n");
        return;
    }

    int firstID;
    int secondID;
    int firstIndex = -1;
    int secondIndex = -1;

    printf("\n--- Compare Suppliers ---\n");

    
firstID = getValidPositiveInteger("Enter first supplier ID: ");

secondID = getValidPositiveInteger("Enter second supplier ID: ");


   

    for (int i = 0; i < count; i++)
    {
        if (suppliers[i].supplierID == firstID)
        {
            firstIndex = i;
        }

        if (suppliers[i].supplierID == secondID)
        {
            secondIndex = i;
        }
    }

    if (firstIndex == -1 || secondIndex == -1)
    {
        printf("One or both suppliers were not found.\n");
        return;
    }

    printf("\nSupplier 1: %s\n", suppliers[firstIndex].name);
    printf("Town: %s\n", suppliers[firstIndex].town);

    printf("\nSupplier 2: %s\n", suppliers[secondIndex].name);
    printf("Town: %s\n", suppliers[secondIndex].town);

    if (strcmp(suppliers[firstIndex].town, suppliers[secondIndex].town) == 0)
    {
        printf("\nBoth suppliers are located in the same town.\n");
    }
    else
    {
        printf("\nThe suppliers are located in different towns.\n");
    }
}
