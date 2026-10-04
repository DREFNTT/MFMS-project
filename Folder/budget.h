#ifndef BUDGET_H
#define BUDGET_H

#include "common.h"

#define MAX_DEPARTMENTS 100
#define DEPT_LEN 50

typedef struct {
    char department[DEPT_LEN];
    double allocatedBudget;
    double expenditure;
} Budget;

// Student 2: Sevelina Kuugongelwa (Budget Management)

void budgetMenu(Budget budgets[], int *budgetCount);

void enterBudget(Budget budgets[], int *budgetCount);
void enterExpenditure(Budget budgets[], int budgetCount);
double calculateRemainingBudget(Budget b);
const char *checkBudgetStatus(Budget b);
void displayBudgetStatus(Budget budgets[], int budgetCount);

#endif
