#ifndef COMMON_H
#define COMMON_H

/* ---- Shared limits (agree on these as a group) ---- */
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
    double totalSalary;          /* basic + housing + transport */
} Employee;

/* Budget, Supplier and Asset structs get added here by Students 2, 3, 4 */

#endif

