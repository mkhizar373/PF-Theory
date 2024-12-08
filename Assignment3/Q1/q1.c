#include <stdio.h>

struct Employee {
    int employeeCode;
    char employeeName[50];
    int dateOfJoining[3];
};

void assignValues(struct Employee *emp) {
    printf("Enter employee code: ");
    scanf("%d", &emp->employeeCode);
    printf("Enter employee name: ");
    scanf(" %[^\n]", emp->employeeName);
    printf("Enter date of joining (DD MM YYYY): ");
    scanf("%d %d %d", &emp->dateOfJoining[0], &emp->dateOfJoining[1], &emp->dateOfJoining[2]);
}

void calculateTenureAndDisplay(struct Employee employees[], int size) {
    int currentDate[3], count = 0;
    printf("Enter the current date (DD MM YYYY): ");
    scanf("%d %d %d", &currentDate[0], &currentDate[1], &currentDate[2]);

    for (int i = 0; i < size; i++) {
        int years = currentDate[2] - employees[i].dateOfJoining[2];
        int months = currentDate[1] - employees[i].dateOfJoining[1];
        int days = currentDate[0] - employees[i].dateOfJoining[0];

        if (months < 0 || (months == 0 && days < 0)) {
            years--;
        }

        if (years > 3) {
            printf("\nEmployee Code: %d", employees[i].employeeCode);
            printf("\nEmployee Name: %s", employees[i].employeeName);
            printf("\nDate of Joining: %02d/%02d/%04d", 
                   employees[i].dateOfJoining[0], 
                   employees[i].dateOfJoining[1], 
                   employees[i].dateOfJoining[2]);
            printf("\nTenure: %d years\n", years);
            count++;
        }
    }

    printf("\nTotal employees with tenure of more than 3 years: %d\n", count);
}

int main() {
    struct Employee employees[4];
    for (int i = 0; i < 4; i++) {
        printf("\nEnter details for Employee %d\n", i + 1);
        assignValues(&employees[i]);
    }

    calculateTenureAndDisplay(employees, 4);
    return 0;
}
