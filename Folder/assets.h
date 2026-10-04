#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct
{
    int id;
    char name[50];
    char type[30];
    float purchaseValue;
    char department[50];
    char condition[30];

} Asset;

void addAsset(void);
void displayAssets(void);
void searchAsset(void);

#endif