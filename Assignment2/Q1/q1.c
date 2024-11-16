#include <stdio.h>

int main() {
    int arr[5], i, first, second;

    for(i = 0; i < 5; i++) {
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
    }

    first = second = 9999;

    for(i = 0; i < 5; i++) {
        if(arr[i] < first) {
            second = first;
            first = arr[i];
        } else if(arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    printf("The Second smallest element in the array is: %d\n", second);

    return 0;
}
