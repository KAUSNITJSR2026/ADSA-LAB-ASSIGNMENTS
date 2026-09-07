#include<stdio.h>
int main(){
    int gap , n=10 , a[]={1 , 0 , 3 , 9 , 2 , 8 , 4 , 7 , 5 , 6};
    for(gap =n/2 ; gap>=1 ; gap/=2){
        for(int j=gap ; j<n ; j++){
            for(int i=j-gap ; i>=0 ; i-=gap){
                if(a[i+gap] > a[i])
                break;
                else{
                    int t=a[i+gap];
                    a[i+gap] = a[i];
                    a[i] = t;
                }
            }
        }
    }
    printf("\n THE SORTED ARRAY IS ::");
    for(int i=0 ; i<n ; i++){
        printf("%d " , a[i]);
    }
    return 0;
}