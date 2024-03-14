#include<stdio.h>

int swap(int *a, int *b);
int main(){
    int n, a, b, *p, arr[50];
    scanf("%d", &n);
    for(p=arr;p<arr+n;p++){
        scanf("%d", p);
    }
    scanf("%d %d", &a, &b);
    swap(arr+a, arr+b);
    for(p=arr;p<arr+n;p++){
        printf(" %d", *p);
    }
    return 0;
}
int swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}