#include <stdio.h>
#include <string.h>

void countLetters(char str[], int length);

int main() {
    int n;
    printf("Enter number of slogans: ");
    scanf("%d", &n);

    getchar(); 

    char str[50];
    for (int i = 0; i < n; i++) {
        printf("Slogan %d: ", i + 1);
        fgets(str, 50, stdin);

        str[strcspn(str, "\n")] = '\0';

        printf("\nFor slogan %d: '%s'\n", i + 1, str);
        countLetters(str, strlen(str));
    }

    return 0;
}

void countLetters(char str[], int length) {
    int freq[256] = {0};  
    int printed[256] = {0};  

    for (int i = 0; i < length; i++) {
        if (str[i] != ' ') {  
            freq[(int)str[i]]++;
        }
    }

    for (int i = 0; i < length; i++) {
        if (str[i] != ' ' && !printed[(int)str[i]]) {  
            printed[(int)str[i]] = 1;  
            printf("'%c': %d\n", str[i], freq[(int)str[i]]);
        }
    }
}