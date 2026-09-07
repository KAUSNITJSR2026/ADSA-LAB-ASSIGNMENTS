#include <stdio.h>
int getMax(int a[], int n){
    int max = a[0];
    int i;
    for(i = 1; i < n; i++){
        if(a[i] > max)
            max = a[i];
    }
    return max;
}
void cSort(int a[], int n, int place){
    int output[5];
    int count[10] = {0};
    int i;
    for(i = 0; i < n; i++){
        count[(a[i] / place) % 10]++;
    }
    for(i = 1; i < 10; i++){
        count[i] = count[i] + count[i - 1];
    }
    for(i = n - 1; i >= 0; i--){
        output[count[(a[i] / place) % 10] - 1] = a[i];
        count[(a[i] / place) % 10]--;
    }
    for(i = 0; i < n; i++){
        a[i] = output[i];
    }
}
void radixSort(int a[], int n){
    int max;
    int place;
    max = getMax(a, n);
    for(place = 1; max / place > 0; place = place * 10){
        cSort(a, n, place);
    }
}
int main(){
    int a[5] = {45, 12, 78, 23, 56};
    int i;
    radixSort(a, 5);
    printf("Sorted Array: ");
    for(i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    return 0;
}