#include<stdio.h>
int main(){
    int n=5 , min , t;
   int a[]={4 , 2 , 7 , 8 ,9};
   for(int i=0 ; i<n-1 ; i++){
    min = i;
    for(int j=i+1 ; j<n ; j++){
        if(a[j] < a[min])
        min = j;
    }
    if(min!=i){
        t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
   }
     printf("\n THE SORTED ARRAY LIST IS ::");
    for(int k=0 ; k<n ; k++){
        printf("%d " , a[k]);
    }
    return 0;
}