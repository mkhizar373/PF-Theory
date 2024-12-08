#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char *email) {
    int atCount = 0, dotAfterAt = 0;
    int len = strlen(email);

    if (len == 0) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            atCount++;
            for (int j = i + 1; j < len; j++) {
                if (email[j] == '.') {
                    dotAfterAt = 1;
                    break;
                }
            }
        }
    }

    if (atCount == 1 && dotAfterAt == 1) {
        return 1;
    }

    return 0;
}

int main() {
    char *email;
    int length;

    printf("Enter the length of your email address: ");
    scanf("%d", &length);

    email = (char *)malloc((length + 1) * sizeof(char));

    if (email == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the email address: ");
    scanf("%s", email);

    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    free(email);

    return 0;
}
