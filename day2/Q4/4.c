//Implement merge sort without using recursion. 
//You may use a stack data structure in order to 
//keep track of dividing and conquering the task.
// This will be a top-down approach of solving the 
 //problem
#include <stdio.h>
struct Stack{
    int low;
    int high;
};
void merge(int a[], int low, int mid, int high){
    int temp[5];
    int i = low;
    int j = mid + 1;
    int k = low;
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
    for(i = low; i <= high; i++){
        a[i] = temp[i];
    }
}
int main(){
    int a[5] = {45, 12, 78, 23, 56};
    struct Stack stack[20];
    int top = -1;
    int low, high, mid;
    int size, i;
    top++;
    stack[top].low = 0;
    stack[top].high = 4;
    while(top >= 0){
        low = stack[top].low;
        high = stack[top].high;
        top--;
        if(low < high){
            mid = (low + high) / 2;
            top++;
            stack[top].low = mid + 1;
            stack[top].high = high;
            top++;
            stack[top].low = low;
            stack[top].high = mid;
        }
    }
    for(size = 1; size < 5; size = size * 2){
        for(low = 0; low < 5 - size; low = low + 2 * size){
            mid = low + size - 1;
            high = low + 2 * size - 1;
            if(high >= 5)
                high = 4;
            merge(a, low, mid, high);
        }
    }
    printf("Sorted Array: ");
    for(i = 0; i < 5; i++){
        printf("%d ", a[i]);
    }
    return 0;
}