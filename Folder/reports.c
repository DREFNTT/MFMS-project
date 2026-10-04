#include <stdio.h>
#include <string.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"

void employeeReport(void) {
    int totalEmployees = getEmployeeCount();
    double totalSalary = 0.0;
    double highestSalary = 0.0;
    double lowestSalary = 999999999.0;
    char highestPaidName[MAX_NAME_LEN] = "Not Available";
    char lowestPaidName[MAX_NAME_LEN]  = "Not Available";

    printf("\n");
    printf("========================================================\n");
    printf("               EMPLOYEE REPORT\n");
    printf("========================================================\n");

    if (totalEmployees == 0) {
        printf("No employees registered in the system.\n");
        printf("========================================================\n");
        return;
    }

    for (int i = 0; i < totalEmployees; i++) {
        const Employee *emp = getEmployeeAt(i);
        if (emp == NULL) continue;

        double currentSalary = calculateSalary(
        emp->basicSalary,emp->housingAllowance,emp->transportAllowance);
        totalSalary += currentSalary;

        if (currentSalary>highestSalary) {
            highestSalary=currentSalary;
            strcpy(highestPaidName, emp->name);
        }
        if (currentSalary < lowestSalary) {
            lowestSalary = currentSalary;
            strcpy(lowestPaidName, emp->name);
        }
    }

    printf("Total Employees     : %d\n", totalEmployees);
    printf("Total Salary Bill   : N$ %.2f\n", totalSalary);
    printf("Average Salary      : N$ %.2f\n", totalSalary / totalEmployees);
    printf("Highest Salary      : N$ %.2f  (%s)\n", highestSalary, highestPaidName);
    printf("Lowest Salary       : N$ %.2f  (%s)\n", lowestSalary, lowestPaidName);
    printf("========================================================\n");
}

/* ============================================================
   BUDGET REPORT
   ============================================================ */
void budgetReport(Budget budgets[], int budgetCount) {
    double totalAllocated = 0.0;
    double totalExpenditure = 0.0;
    int exceededCount = 0;

    printf("\n");
    printf("========================================================\n");
    printf("                BUDGET REPORT\n");
    printf("========================================================\n");

    if (budgetCount==0) {
        printf("No budget records to display.\n");
        printf("========================================================\n");
        return;
    }

    printf("%-20s %12s %12s %12s   %s\n",
           "DEPARTMENT", "ALLOCATED", "SPENT", "REMAINING", "STATUS");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < budgetCount; i++) {
        double remaining = budgets[i].allocatedBudget - budgets[i].expenditure;
        const char *status = checkBudgetStatus(budgets[i]);
        const char *tag = (strcmp(status, "EXCEEDED")==0) ? "[!]" : "[OK]";

        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;

        printf("%-20s %12.2f %12.2f %12.2f   %-13s %s\n",
               budgets[i].department,
               budgets[i].allocatedBudget,
               budgets[i].expenditure,
               remaining,
               status,
               tag);

        if (strcmp(status, "EXCEEDED") == 0) {
            exceededCount++;
        }
    }

    printf("--------------------------------------------------------------------------\n");
    printf("Total Allocated     : N$ %.2f\n", totalAllocated);
    printf("Total Expenditure   : N$ %.2f\n", totalExpenditure);
    printf("Total Remaining     : N$ %.2f\n", totalAllocated - totalExpenditure);
    printf("Departments Over    : %d of %d\n", exceededCount, budgetCount);
    printf("========================================================\n");
}

/* ============================================================
   SUPPLIER REPORT
   ============================================================ */
void supplierReport(Supplier suppliers[], int supplierCount) {
    printf("\n");
    printf("========================================================\n");
    printf("               SUPPLIER REPORT\n");
    printf("========================================================\n");

    if (supplierCount == 0) {
        printf("No suppliers registered in the system.\n");
        printf("========================================================\n");
        return;
    }

    printf("Total Registered Suppliers: %d\n\n", supplierCount);

    printf("%-10s %-22s %-20s %-15s %-15s\n",
           "ID", "NAME", "EMAIL", "TELEPHONE", "TOWN");
    printf("--------------------------------------------------------------------------------\n");

    for (int i = 0; i < supplierCount; i++) {
        printf("%-10d %-22.22s %-20.20s %-15.15s %-15.15s\n",
               suppliers[i].supplierID,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].telephone,
               suppliers[i].town);
    }
    printf("========================================================\n");
}

/* ============================================================
   ASSET REPORT
   ============================================================ */
void assetReport(void) {
    double totalValue = 0.0;

    printf("\n");
    printf("========================================================\n");
    printf("                 ASSET REPORT\n");
    printf("========================================================\n");

    if (assetCount == 0) {
        printf("No assets registered in the system.\n");
        printf("========================================================\n");
        return;
    }
    printf("Total Registered Assets: %d\n\n", assetCount);

    printf("%-6s %-22s %-15s %-15s %-15s %-15s\n",
           "ID", "NAME", "TYPE", "DEPARTMENT", "CONDITION", "VALUE");
    printf("--------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < assetCount; i++) {
        printf("%-6d %-22.22s %-15.15s %-15.15s %-15.15s N$%-12.2f\n",
               assets[i].id,
               assets[i].name,
               assets[i].type,
               assets[i].department,
               assets[i].condition,
               assets[i].purchaseValue);
        totalValue += assets[i].purchaseValue;
    }
    printf("--------------------------------------------------------------------------------------------\n");
    printf("Total Value of All Assets: N$ %.2f\n", totalValue);
    printf("========================================================\n");
}
