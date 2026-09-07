#include <stdio.h>
int main(){
    int a[5] = {45, 12, 78, 23, 56};
    int bucket[10][10];
    int count[10] = {0};
    int i, j, k, b, temp;
    for(i = 0; i < 5; i++){
        b = a[i] / 10;
        bucket[b][count[b]] = a[i];
        count[b]++;
    }
    for(i = 0; i < 10; i++){
        for(j = 0; j < count[i] - 1; j++){
            for(k = j + 1; k < count[i]; k++){
                if(bucket[i][j] > bucket[i][k]){
                    temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }
            }
        }
    }
    k = 0;
    for(i = 0; i < 10; i++){
        for(j = 0; j < count[i]; j++){
            a[k] = bucket[i][j];
            k++;
        }
    }
    printf("Sorted Array: ");
    for(i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    return 0;
}