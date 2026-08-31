#include <stdio.h>
void radixExchangeSort(int arr[], int left, int right, int bit) {
    if (left >= right || bit < 0)
        return;
    int i = left, j = right;
    while (i <= j) {
        while (i <= right && ((arr[i] >> bit) & 1) == 0)
            i++;
        while (j >= left && ((arr[j] >> bit) & 1) == 1)
            j--;
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    radixExchangeSort(arr, left, j, bit - 1);
    radixExchangeSort(arr, i, right, bit - 1);
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {13, 7, 2, 8, 3, 15, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    display(arr, n);
    radixExchangeSort(arr, 0, n - 1, 3);

    printf("Sorted Array:\n");
    display(arr, n);

    return 0;
}
