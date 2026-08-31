#include <stdio.h>

#define MAX 100  

void addressCalculationSort(int arr[], int n) {
    int addressTable[MAX] = {0};  
    for (int i = 0; i < n; i++) {
        addressTable[arr[i]] = 1;  
    }
    printf("Sorted Array:\n");
    for (int i = 0; i < MAX; i++) {
        if (addressTable[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {25, 12, 45, 8, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    addressCalculationSort(arr, n);

    return 0;
}
