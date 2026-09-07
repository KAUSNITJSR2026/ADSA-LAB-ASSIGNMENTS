#include <stdio.h>
int main(){
    int a[5] = {45, 12, 78, 23, 56};
    int address[100] = {0};
    int i;
    for(i = 0; i < 5; i++){
        address[a[i]] = a[i];
    }
    printf("Sorted Array: ");
    for(i = 0; i < 100; i++){
        if(address[i] != 0){
            printf("%d ", address[i]);
        }
    }
    return 0;
}