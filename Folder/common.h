#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>

/* ---- Shared limits ---- */
#define MAX_EMPLOYEES 100
#define MAX_NAME_LEN  50

/* ---- Employee (Student 1) ---- */
typedef struct {
    int    id;
    char   name[MAX_NAME_LEN];
    char   position[MAX_NAME_LEN];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double totalSalary;
} Employee;

/* ---- Input validation functions (Student 6) ---- */
int getValidInteger(const char *prompt);
int getValidPositiveInteger(const char *prompt);
void getValidNonEmptyString(const char *prompt, char *output, size_t size);

#endif