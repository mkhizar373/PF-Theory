#include <stdio.h>

void printHorizontalHistogram(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Value %d: ", i + 1);
        for (int j = 0; j < arr[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printVerticalHistogram(int arr[], int n, int max) {
    for (int i = max; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (arr[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    int max = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("\nHorizontal Histogram:\n");
    printHorizontalHistogram(arr, n);

    printf("\nVertical Histogram:\n");
    printVerticalHistogram(arr, n, max);

    return 0;
}
