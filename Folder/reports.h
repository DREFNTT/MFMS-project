#ifndef REPORTS_H
#define REPORTS_H

#include "common.h"
#include "budget.h"
#include "suppliers.h"

void employeeReport(void);
void budgetReport(Budget budgets[], int budgetCount);
void supplierReport(Supplier suppliers[], int supplierCount);
void assetReport(void);

#endif
