// Roll#24k-0001 Name:Masoom Khan Assignment:3 Q1
#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 4

// Struct forEmployee details
typedef struct {
    int employeeCode;
    char employeeName[50];
    int dateOfJoining; // YYYYMMDD format
} Employee;

// Function for values
void assignEmployee(Employee *emp, int code, const char *name, int joiningDate) {
    emp->employeeCode = code;
    strcpy(emp->employeeName, name);
    emp->dateOfJoining = joiningDate;
}

// Function for tenure and employees with tenure less than 3 years
void calculateTenure(Employee employees[], int count) {
    int currentYear, currentMonth, currentDay;
    int tenureYears, tenureMonths, tenureDays, eligibleCount = 0;

    printf("Enter the current date (YYYY MM DD): ");
    scanf("%d %d %d", &currentYear, &currentMonth, &currentDay);
    
    printf("\nEmployees with more than 3 years of tenure:\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        int joiningYear = employees[i].dateOfJoining / 10000;
        int joiningMonth = (employees[i].dateOfJoining / 100) % 100;
        int joiningDay = employees[i].dateOfJoining % 100;

        // Calculate tenure
        tenureYears = currentYear - joiningYear;
        tenureMonths = currentMonth - joiningMonth;
        tenureDays = currentDay - joiningDay;

        // Adjust for negative values
        if (tenureDays < 0) {
            tenureDays += 30; // Approximation
            tenureMonths--;
        }
        if (tenureMonths < 0) {
            tenureMonths += 12;
            tenureYears--;
        }

        if (tenureYears > 3 || (tenureYears == 3 && (tenureMonths > 0 || tenureDays > 0))) {
            printf("Employee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Date of Joining: %04d-%02d-%02d\n", joiningYear, joiningMonth, joiningDay);
            printf("Tenure: %d years, %d months, %d days\n\n", tenureYears, tenureMonths, tenureDays);
            eligibleCount++;
        }
    }

    printf("Total employees with tenure > 3 years: %d\n", eligibleCount);
}
//start main
int main() {
    Employee employees[MAX_EMPLOYEES];

    // Initialize the array
    assignEmployee(&employees[0], 101, "Masoom", 20041115);
    assignEmployee(&employees[1], 102, "Ali", 20181010);
    assignEmployee(&employees[2], 103, "Bilal", 20200120);
    assignEmployee(&employees[3], 104, "Dawood", 20170605);

    // Calculate tenure and display details
    calculateTenure(employees, MAX_EMPLOYEES);

    return 0;
}