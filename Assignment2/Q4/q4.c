#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void groupAnagrams(char transactions[100][100], int size) {
    char sortedTransactions[100][100];
    int grouped[100] = {0};
    char *groups[100][100];  
    int groupCount = 0;

    for (int i = 0; i < size; i++) {
        if (!grouped[i]) {
            strcpy(sortedTransactions[i], transactions[i]);
            sortString(sortedTransactions[i]);
            groups[groupCount][0] = transactions[i];  
            for (int j = i + 1; j < size; j++) {
                if (!grouped[j]) {
                    char temp[100];
                    strcpy(temp, transactions[j]);
                    sortString(temp);

                    if (strcmp(sortedTransactions[i], temp) == 0) {
                        groups[groupCount][j] = transactions[j];
                        grouped[j] = 1;
                    }
                }
            }
            groupCount++;
        }
    }

    printf("[");
    for (int i = 0; i < groupCount; i++) {
        printf("[");
        int first = 1;
        for (int j = 0; j < size; j++) {
            if (groups[i][j] != NULL) {
                if (!first) {
                    printf(", ");
                }
                printf("\"%s\"", groups[i][j]);
                first = 0;
            }
        }
        if (i < groupCount - 1) {
            printf("], ");
        } else {
            printf("]");
        }
    }
    printf("]\n");
}

int main() {
    int size;
    printf("Enter the number of transactions: ");
    scanf("%d", &size);
    getchar();

    char transactions[100][100];
    
    printf("Enter the transactions :\n");
    for (int i = 0; i < size; i++) {
        fgets(transactions[i], 100, stdin);
        transactions[i][strcspn(transactions[i], "\n")] = '\0';
    }

    printf("\nGrouped Anagrams:\n");
    groupAnagrams(transactions, size);

return 0;
}