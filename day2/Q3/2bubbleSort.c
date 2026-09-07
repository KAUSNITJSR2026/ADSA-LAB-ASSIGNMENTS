#include<stdio.h>
int main(){
    int n=5;
   int a[]={4 , 2 , 7 , 8 ,9};
    for(int i=0 ; i<n-1 ; i++){
        int f=0;
        for(int j=0 ; j<n-1 ; j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                f++;
            }
        }
        if(f==0){
            break;
        }
    }
     printf("\n THE SORTED ARRAY LIST IS ::");
    for(int k=0 ; k<n ; k++){
        printf("%d " , a[k]);
    }
    return 0;
}