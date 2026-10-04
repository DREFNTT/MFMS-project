#include <stdio.h>
#include <string.h>
#include "assets.h"

Asset assets[MAX_ASSETS];
int assetCount = 0;

/* Add a new asset */
void addAsset(void)
{
    if (assetCount >= MAX_ASSETS)
    {
        printf("\nAsset storage is full.\n");
        return;
    }

    printf("\n===== ADD ASSET =====\n");

    printf("Enter Asset ID: ");
    scanf("%d", &assets[assetCount].id);

    printf("Enter Asset Name: ");
    scanf(" %49[^\n]", assets[assetCount].name);

    printf("Enter Asset Type: ");
    scanf(" %29[^\n]", assets[assetCount].type);

    printf("Enter Purchase Value: ");
    scanf("%f", &assets[assetCount].purchaseValue);

    printf("Enter Department: ");
    scanf(" %49[^\n]", assets[assetCount].department);

    printf("Enter Condition: ");
    scanf(" %29[^\n]", assets[assetCount].condition);

    assetCount++;

    printf("\nAsset added successfully!\n");
}

/* Display all assets */
void displayAssets(void)
{
    if (assetCount == 0)
    {
        printf("\nNo assets registered.\n");
        return;
    }

    printf("\n===== ALL ASSETS =====\n");

    for (int i = 0; i < assetCount; i++)
    {
        printf("\nAsset %d\n", i + 1);
        printf("ID: %d\n", assets[i].id);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Purchase Value: N$%.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}

/* Search for an asset by ID */
void searchAsset(void)
{
    int id;
    int found = 0;

    printf("\n===== SEARCH ASSET =====\n");

    printf("Enter Asset ID: ");
    scanf("%d", &id);

    for (int i = 0; i < assetCount; i++)
    {
        if (assets[i].id == id)
        {
            printf("\nAsset Found!\n");
            printf("ID: %d\n", assets[i].id);
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Purchase Value: N$%.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nAsset not found.\n");
    }
}