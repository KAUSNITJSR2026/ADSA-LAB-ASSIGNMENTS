#include<stdio.h>
int main(){
    int n , a[100];
    printf("\n ENTER THE SIZE OF THE ARRAY LIST ::");
    scanf("%d" , &n);
    printf("\n enter the elements in the array list ::");
    for(int i=0 ; i<n ; i++){
        scanf("%d" , &a[i]);
    }
    int t;
    for(int i=1 ; i<n ; i++){
        t=a[i];
        int j=i-1;
        while(j>=0 && a[j]>t){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
    printf("\n sorted array list is ::");
    for(int i=0 ; i<n ; i++){
        printf(" %d" , a[i]);
    }
    return 0;
}