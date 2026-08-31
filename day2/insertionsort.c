/*Implement the 
(i) insertion sort, 
(ii) bubble sort, 
(iii) selection sort, 
(iv) shell sort, 
(v) quick sort, 
(vi) merge sort, 
(vii) heap sort, 
(viii) radix sort, 
(ix) counting sort, 
(x) bucket sort, 
(xi) radix exchange sort, and 
(xii) address calculation sort.   */
#include<stdio.h>
void is(int a[] , int n){
    for(int i=1 ; i<n ; i++){
        int k=a[i];
        int j=i-1;
        while(j>=0 && a[j]>k){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=k;
    }
    
}
void show(int a[] ,int  n){
    printf("\n THE SORTED ARRAY IS ::");
        for(int i=0 ; i<n ; i++){
            printf("%d    " , a[i]);
        }
    }
int main(){
    int a[100];
    int n ;
    printf("\n ENTER THE SIZE OF THE ARRAY ::");
    scanf("%d" , &n);
    printf("\n ENTER THE ELEMENTS IN THE ARRAY ::");
    for(int i=0 ; i<n ; i++){
        scanf("%d" , &a[i]);
    }
    is(a , n);
    show(a , n);
}