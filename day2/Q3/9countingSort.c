#include <stdio.h>
int main(){
    int a[5] = {45, 12, 78, 23, 56};
    int count[100] = {0};
    int i, j;
    for(i = 0; i < 5; i++){
        count[a[i]]++;
    }
    printf("Sorted Array: ");
    for(i = 0; i < 100; i++){
        for(j = 0; j < count[i]; j++){
            printf("%d ", i);
        }
    }
    return 0;
}