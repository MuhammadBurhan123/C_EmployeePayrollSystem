#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50
#define FILENAME "employees.txt"

// Structure to store employee information
struct Employee {
    char name[50];
    int id;
    float basicSalary;
    float allowances;
    float deductions;
    float netSalary;
};

// Function to input employee data from the user
void inputEmployeeData(struct Employee *employee) {
    printf("Enter employee name: ");
    scanf("%s", employee->name);
    printf("Enter employee ID: ");
    scanf("%d", &employee->id);
    printf("Enter basic salary: ");
    scanf("%f", &employee->basicSalary);
    printf("Enter allowances: ");
    scanf("%f", &employee->allowances);
    printf("Enter deductions: ");
    scanf("%f", &employee->deductions);

    // Calculate net salary
    employee->netSalary = employee->basicSalary + employee->allowances - employee->deductions;
}

// Function to display employee information
void displayEmployeeInfo(struct Employee *employee) {
    printf("\nName: %s\nID: %d\nBasic Salary: %.2f\nAllowances: %.2f\nDeductions: %.2f\nNet Salary: %.2f\n",
           employee->name,
           employee->id,
           employee->basicSalary,
           employee->allowances,
           employee->deductions,
           employee->netSalary);
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    // Input data for each employee
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        inputEmployeeData(&employees[i]);
        numEmployees++;

        // Save the information to the file (optional)
        FILE *file = fopen(FILENAME, "a");
        if (file != NULL) {
            fprintf(file, "%s %d %.2f %.2f %.2f %.2f\n",
                    employees[i].name,
                    employees[i].id,
                    employees[i].basicSalary,
                    employees[i].allowances,
                    employees[i].deductions,
                    employees[i].netSalary);
            fclose(file);
        }

        // Display employee information
        displayEmployeeInfo(&employees[i]);

        char more;
        printf("Do you want to input data for another employee? (y/n): ");
        scanf(" %c", &more);

        if (more != 'y' && more != 'Y') {
            break;
        }
    }

    return 0;
}
