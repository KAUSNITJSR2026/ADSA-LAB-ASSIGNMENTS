/* Implement merge sort without using recursion and
 without using any stack. You need to use only two 
 nested loops to complete your task. You do not need
 any stack. You do not need dividing and conquering 
 the task. This will be a bottom-up approach of 
 solving the problem. */
 #include <stdio.h>
void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int m = left; m <= right; m++)
        arr[m] = temp[m];
}
void mergeSortBottomUp(int arr[], int n) {
    int temp[n];
    for (int size = 1; size < n; size = 2 * size) {
        for (int leftStart = 0; leftStart < n - size; leftStart += 2 * size) {
            int mid = leftStart + size - 1;
            int rightEnd = (leftStart + 2 * size - 1 < n - 1) ? (leftStart + 2 * size - 1) : (n - 1);
            merge(arr, temp, leftStart, mid, rightEnd);
        }
    }
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original Array:\n");
    display(arr, n);
    mergeSortBottomUp(arr, n);
    printf("Sorted Array:\n");
    display(arr, n);
    return 0;
}
