#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "employees.h"

/* ---------- Module data (private to this file) ---------- */
static Employee employees[MAX_EMPLOYEES];
static int      employeeCount = 0;

/* ---------- Private input helpers ----------
 * Kept local so this module works on its own. Once Student 6's shared
 * validation helpers exist, these can be swapped for them. */

static void trim(char *s)
{
    size_t len = strlen(s);
    size_t start = 0;

    while (len > 0 && isspace((unsigned char)s[len - 1])) {
        s[--len] = '\0';
       }
          while (s[start] != '\0' && isspace((unsigned char)s[start])) {
             start++;
          } 
           if (start > 0) {
              memmove(s, s + start, strlen(s + start) + 1);
      }
}

/* Reads one line safely. Returns 0 on end of input, 1 otherwise. */
static int readLine(const char *prompt, char *buf, size_t size)
   {
       printf("%s", prompt);
         if (fgets(buf, (int)size, stdin) == NULL) {
           buf[0] = '\0';
             return 0;
       }
          if (strchr(buf, '\n') == NULL) {            /* line was too long: discard rest */
            int c;
             while ((c = getchar()) != '\n' && c != EOF) {
               ;
           }
      }
              buf[strcspn(buf, "\n")] = '\0';
                trim(buf);
                  return 1;
}

/* Keeps asking until the text is not empty. Returns 0 if input ended. */
static int readNonEmpty(const char *prompt, char *buf, size_t size)
{
         for (;;) {
             if (!readLine(prompt, buf, size)) {
               return 0;
           }
              if (buf[0] != '\0') {
                return 1;
          }
             printf("  Error: this field cannot be empty.\n");
      }
}

/* Keeps asking until a whole number >= minValue is entered. */
static int readInt(const char *prompt, int minValue, int *out)
{
        char buf[64];
          char *end;
            long value;

                for (;;) {
                    if (!readLine(prompt, buf, sizeof buf)) {
                        return 0;
             }
                 value = strtol(buf, &end, 10);
                    if (buf[0] == '\0' || *end != '\0') {
                     printf("  Error: please enter a whole number.\n");
             } else if (value < minValue || value > 2147483647L) {
                 printf("  Error: value must be at least %d.\n", minValue);
                } else {
                  *out = (int)value;
                    return 1;
            }
         }
}

/* Keeps asking until a number >= 0 is entered (rejects negatives). */
static int readMoney(const char *prompt, double *out)
{
       char buf[64];
         char *end;
          double value;

           for (;;) {
           if (!readLine(prompt, buf, sizeof buf)) {
              return 0;
            }
              value = strtod(buf, &end);
                 if (buf[0] == '\0' || *end != '\0') {
                    printf("  Error: please enter a number.\n");
                      } else if (value < 0.0) {
                        printf("  Error: amount cannot be negative.\n");
                            } else {
                  *out = value;
                     return 1;
             }
                    }
}  

/* ---------- Other private helpers ---------- */

static int findIndexById(int id)
{
        int i;
         for (i = 0; i < employeeCount; i++) {
           if (employees[i].id == id) {
             return i;
           }
       }
          return -1;
}

/* Case-insensitive "does text contain pattern?" */
static int containsIgnoreCase(const char *text, const char *pattern)
{
        size_t i, j;
        size_t tl = strlen(text);
        size_t pl = strlen(pattern);

               if (pl == 0) {
                   return 1;
        }
              for (i = 0; i + pl <= tl; i++) {
                   for (j = 0; j < pl; j++) {
                       if (tolower((unsigned char)text[i + j]) !=
                          tolower((unsigned char)pattern[j])) {
                      break;
               }
              }
                 if (j == pl) {
               return 1;
           }
        }
          return 0;
}

static void printTableHeader(void)
{
             printf("\n%-6s %-22s %-18s %11s %11s %11s %12s\n",
                   "ID", "Name", "Position", "Basic", "Housing", "Transport", "Total");
                     printf("------------------------------------------------------------"
                                 "-----------------------------\n");
}

      static void printEmployeeRow(const Employee *e)
{
          printf("%-6d %-22.22s %-18.18s %11.2f %11.2f %11.2f %12.2f\n",
             e->id, e->name, e->position,
             e->basicSalary, e->housingAllowance,
              e->transportAllowance, e->totalSalary);
}

/* ---------- Public functions ---------- */

double calculateSalary(double basic, double housing, double transport)
{
    return basic + housing + transport;
}

void addEmployee(void)
{
    Employee e;
    int id;

    if (employeeCount >= MAX_EMPLOYEES) {
        printf("Error: employee list is full (%d maximum).\n", MAX_EMPLOYEES);
        return;
    }

    printf("\n--- Add Employee ---\n");

    if (!readInt("Employee ID (positive number): ", 1, &id)) return;
    if (findIndexById(id) != -1) {
        printf("Error: an employee with ID %d already exists.\n", id);
        return;
    }
    e.id = id;

    if (!readNonEmpty("Full name: ", e.name, sizeof e.name)) return;
    if (!readNonEmpty("Position: ", e.position, sizeof e.position)) return;
    if (!readMoney("Basic salary: ", &e.basicSalary)) return;
    if (!readMoney("Housing allowance: ", &e.housingAllowance)) return;
    if (!readMoney("Transport allowance: ", &e.transportAllowance)) return;

    e.totalSalary = calculateSalary(e.basicSalary,
                                    e.housingAllowance,
                                    e.transportAllowance);

    employees[employeeCount++] = e;
    printf("Employee added. Total salary: %.2f\n", e.totalSalary);
}

void displayEmployees(void)
{
    int i;

    if (employeeCount == 0) {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n--- All Employees (%d) ---", employeeCount);
    printTableHeader();
    for (i = 0; i < employeeCount; i++) {
        printEmployeeRow(&employees[i]);
    }
}

void searchEmployee(void)
{
    int choice;
    int i, found = 0;

    if (employeeCount == 0) {
        printf("\nNo employees to search. Add some first.\n");
        return;
    }

    printf("\n--- Search Employee ---\n");
    printf("1. Search by ID\n");
    printf("2. Search by name\n");
    if (!readInt("Choice: ", 1, &choice)) return;

    if (choice == 1) {
        int id, idx;
        if (!readInt("Enter ID: ", 1, &id)) return;
        idx = findIndexById(id);
        if (idx == -1) {
            printf("No employee found with ID %d.\n", id);
            return;
        }
        printTableHeader();
        printEmployeeRow(&employees[idx]);
         }    else if (choice == 2) {
              char term[MAX_NAME_LEN];
                 if (!readNonEmpty("Enter name (or part of it): ", term, sizeof term)) return;
                     for (i = 0; i < employeeCount; i++) {
                      if (containsIgnoreCase(employees[i].name, term)) {
                      if (!found) {
                        printTableHeader();
                }
                    printEmployeeRow(&employees[i]);
                        found++;
            }
        }
        if (!found) {
            printf("No employee found matching \"%s\".\n", term);
        }
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }
}

int getEmployeeCount(void)
{
       return employeeCount;
}

const Employee *getEmployeeAt(int index)
{
           if (index < 0 || index >= employeeCount) {
            return NULL;
        }
        return &employees[index];
}

