#include <stdio.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int a[], int lb, int ub) {
    int pivot = a[lb];
    int start = lb;
    int end = ub;
    while (start < end) {
        while (a[start] <= pivot ) {
            start++;
        }
        while (a[end] > pivot ) {
            end--;
        }
        if (start < end) {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[lb], &a[end]);
    return end;
}
void qs(int a[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(a, lb, ub);
        qs(a, lb, loc - 1);
        qs(a, loc + 1, ub);
    }
}
int main() {
    int n = 10;
    int a[] = {1, 0, 3, 9, 2, 8, 4, 7, 5, 6};
    qs(a, 0, n - 1);
    printf("\nTHE SORTED ARRAY IS :: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
