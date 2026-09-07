#include <stdio.h>
void merge(int a[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[5];
    while(i <= mid && j <= high){
        if(a[i] < a[j]){
            temp[k] = a[i];
            i++;
        }
        else{
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j <= high){
        temp[k] = a[j];
        j++;
        k++;
    }
    for(i = low, k = 0; i <= high; i++, k++){
        a[i] = temp[k];
    }
}
void mergeSort(int a[], int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
int main(){
    int a[5] = {45, 12, 78, 23, 56};
    int i;
    mergeSort(a, 0, 4);
    printf("Sorted Array: ");
    for(i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    return 0;
}