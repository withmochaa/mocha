#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)


int find_max(int n,int a[]);


int main(void){

    int n,max,arr[20];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    max=find_max(n-1,arr);

    printf("%d",max);

    return 0;
}

int find_max(int n,int arr[]){

    int max;

    if(n==0){
        return max;
    }
    max=find_max(n-1,arr);

    if(max<arr[n]){
        return arr[n];
    }
    else{
        return max;
    }

}