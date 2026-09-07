/*Implement merge sort without using recursion and 
without using any stack. You need to use only two
nested loops to complete your task. You do not need 
any stack. You do not need dividing and conquering 
the task. This will be a bottom-up approach of 
solving the problem.*/
#include <stdio.h>
int main(){
    int a[5] = {45, 12, 78, 23, 56};
    int temp[5];
    int size, left, mid, right;
    int i, j, k;
    for(size = 1; size < 5; size = size * 2){
        for(left = 0; left < 5 - size; left = left + 2 * size){
            mid = left + size;
            right = left + 2 * size;
            if(right > 5)
                right = 5;
            i = left;
            j = mid;
            k = left;
            while(i < mid && j < right){
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
            while(i < mid){
                temp[k] = a[i];
                i++;
                k++;
            }
            while(j < right){
                temp[k] = a[j];
                j++;
                k++;
            }
            for(i = left; i < right; i++){
                a[i] = temp[i];
            }
        }
    }
    printf("Sorted Array: ");
    for(i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    return 0;
}