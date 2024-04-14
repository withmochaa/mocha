#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int n;
    int *pn1;
    int *pn2;
    pn1 = (int*)malloc(sizeof(int)*n);
    pn2 = (int*)malloc(sizeof(int)*n);
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &pn1[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d", &pn2[i]);
    }
    for(int i=0;i<n;i++){
        pn1[i] += pn2[n-1-i];
    }
    for(int i=0;i<n;i++){
        printf(" %d", pn1[i]);
    }
    free(pn1);
    free(pn2);
}