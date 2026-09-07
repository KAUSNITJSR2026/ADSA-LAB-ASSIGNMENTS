#include <stdio.h>
void radixExchangeSort(int a[], int left, int right, int bit){
    int i, j, temp;
    if(left >= right || bit < 0)
        return;
    i = left;
    j = right;
    while(i <= j){
        while(i <= right && ((a[i] >> bit) & 1) == 0)
            i++;
        while(j >= left && ((a[j] >> bit) & 1) == 1)
            j--;
        if(i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    radixExchangeSort(a, left, j, bit - 1);
    radixExchangeSort(a, i, right, bit - 1);
}
int main(){
    int a[5] = {45, 12, 78, 23, 56};
    int i;
    radixExchangeSort(a, 0, 4, 7);
    printf("Sorted Array: ");
    for(i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    return 0;
}