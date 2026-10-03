#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

typedef struct {
    int supplierID;
    char name[100];
    char email[100];
    char telephone[30];
    char town[50];
} Supplier;

void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(Supplier suppliers[], int count);
void searchSupplier(Supplier suppliers[], int count);
void compareSuppliers(Supplier suppliers[], int count);

#endif
