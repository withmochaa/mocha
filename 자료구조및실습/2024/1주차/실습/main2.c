#include<stdio.h>

int ABC(int a[], int k);
void main(){
    int arr[10], k;
    for(int i=0;i<10;i++){
        scanf("%d", &arr[i]);
    }
    for(k=0;k<10;k++){
        ABC(arr, k);
    }
    for(int i=0;i<10;i++){
        printf(" %d", arr[i]);
    }
}
int ABC(int a[], int k){
    int max=a[k], maxi=k, tmp;
    for(int i=k;i<10;i++){
        if(a[i]>max){
            max = a[i];
            maxi = i;
        }
    }
    tmp = a[k];
    a[k] = a[maxi];
    a[maxi] = tmp;
}