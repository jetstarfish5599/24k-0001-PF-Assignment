// Roll#24k-0001 Name:Masoom Khan Assignment:3 Q4
#include <stdio.h>
#include <stdlib.h>

// Input Ratings Function
void inputEmployees(int** ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEnter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            int rating;
            do {
                printf("Rating for period %d (1-10): ", j + 1);
                scanf("%d", &rating);
                if (rating < 1 || rating > 10) {
                    printf("Invalid rating. Please enter a value between 1 and 10.\n");
                }
            } while (rating < 1 || rating > 10);
            ratings[i][j] = rating;
        }
    }
}

// Display Performance Function
void displayPerformance(int** ratings, int numEmployees, int numPeriods) {
    printf("\nEmployee Performance Ratings:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

// Find Employee of the Year Function
int findEmployeeOfTheYear(int** ratings, int numEmployees, int numPeriods) {
    int bestEmployee = -1;
    double highestAvg = 0;

    for (int i = 0; i < numEmployees; i++) {
        int totalScore = 0;
        for (int j = 0; j < numPeriods; j++) {
            totalScore += ratings[i][j];
        }
        double average = (double)totalScore / numPeriods;
        if (average > highestAvg) {
            highestAvg = average;
            bestEmployee = i;
        }
    }

    return bestEmployee;
}

// Find Highest Rated Period Function
int findHighestRatedPeriod(int** ratings, int numEmployees, int numPeriods) {
    int bestPeriod = -1;
    double highestAvg = 0;

    for (int j = 0; j < numPeriods; j++) {
        int totalScore = 0;
        for (int i = 0; i < numEmployees; i++) {
            totalScore += ratings[i][j];
        }
        double average = (double)totalScore / numEmployees;
        if (average > highestAvg) {
            highestAvg = average;
            bestPeriod = j;
        }
    }

    return bestPeriod;
}

// Find Worst Performing Employee Function
int findWorstPerformingEmployee(int** ratings, int numEmployees, int numPeriods) {
    int worstEmployee = -1;
    double lowestAvg = 11; 

    for (int i = 0; i < numEmployees; i++) {
        int totalScore = 0;
        for (int j = 0; j < numPeriods; j++) {
            totalScore += ratings[i][j];
        }
        double average = (double)totalScore / numPeriods;
        if (average < lowestAvg) {
            lowestAvg = average;
            worstEmployee = i;
        }
    }

    return worstEmployee;
}
//start main
int main() {
    int numEmployees, numPeriods;

    // Input number of employees and evaluation periods
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    // Dynamically allocate memory for ratings
    int** ratings = (int*)malloc(numEmployees * sizeof(int));
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int*)malloc(numPeriods * sizeof(int));
    }

    // Input ratings
    inputEmployees(ratings, numEmployees, numPeriods);

    // Display ratings
    displayPerformance(ratings, numEmployees, numPeriods);

    // Find and display Employee of the Year
    int employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("\nEmployee of the Year: Employee %d\n", employeeOfTheYear + 1);

    // Find and display Highest Rated Period
    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Evaluation Period: Period %d\n", highestRatedPeriod + 1);

    // Find and display Worst Performing Employee
    int worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstEmployee + 1);

    // Free allocated memory
    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
//end main