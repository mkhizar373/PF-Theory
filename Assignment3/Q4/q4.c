#include <stdio.h>
#include <stdlib.h>

void inputEmployees(int **ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            int rating;
            do {
                printf("Rating for Period %d (1-10): ", j + 1);
                scanf("%d", &rating);
            } while (rating < 1 || rating > 10);
            ratings[i][j] = rating;
        }
    }
}

void displayPerformance(int **ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Ratings for Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

int findEmployeeOfTheYear(int **ratings, int numEmployees, int numPeriods) {
    int bestEmployee = 0;
    float bestAverage = 0.0;
    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        float average = (float)total / numPeriods;
        if (average > bestAverage) {
            bestAverage = average;
            bestEmployee = i;
        }
    }
    return bestEmployee;
}

int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods) {
    int bestPeriod = 0;
    float bestAverage = 0.0;
    for (int j = 0; j < numPeriods; j++) {
        int total = 0;
        for (int i = 0; i < numEmployees; i++) {
            total += ratings[i][j];
        }
        float average = (float)total / numEmployees;
        if (average > bestAverage) {
            bestAverage = average;
            bestPeriod = j;
        }
    }
    return bestPeriod;
}

int findWorstPerformingEmployee(int **ratings, int numEmployees, int numPeriods) {
    int worstEmployee = 0;
    float worstAverage = 100.0;
    for (int i = 0; i < numEmployees; i++) {
        int total = 0;
        for (int j = 0; j < numPeriods; j++) {
            total += ratings[i][j];
        }
        float average = (float)total / numPeriods;
        if (average < worstAverage) {
            worstAverage = average;
            worstEmployee = i;
        }
    }
    return worstEmployee;
}

int main() {
    int numEmployees, numPeriods;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter the number of evaluation periods: ");
    scanf("%d", &numPeriods);

    int **ratings = (int **)malloc(numEmployees * sizeof(int *));
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int *)malloc(numPeriods * sizeof(int));
    }

    inputEmployees(ratings, numEmployees, numPeriods);
    displayPerformance(ratings, numEmployees, numPeriods);

    int employeeOfTheYear = findEmployeeOfTheYear(ratings, numEmployees, numPeriods);
    printf("Employee of the Year: Employee %d\n", employeeOfTheYear + 1);

    int highestRatedPeriod = findHighestRatedPeriod(ratings, numEmployees, numPeriods);
    printf("Highest Rated Period: Period %d\n", highestRatedPeriod + 1);

    int worstEmployee = findWorstPerformingEmployee(ratings, numEmployees, numPeriods);
    printf("Worst Performing Employee: Employee %d\n", worstEmployee + 1);

    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}
