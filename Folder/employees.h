#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include "common.h"

/* Core functions (called from the main menu) */
void   addEmployee(void);
void   displayEmployees(void);
void   searchEmployee(void);
double calculateSalary(double basic, double housing, double transport);

/* Read-only access for the Reports module (Student 5) */
int             getEmployeeCount(void);
const Employee *getEmployeeAt(int index);   /* NULL if index is out of range */

#endif
