#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

int main(void){

    int ar[50]={0},N;

    int *p;

    scanf("%d",&N);

    for(p=ar;p<ar+N;p++){
        scanf("%d",p);
    }

    int count=0;

    for(p=ar;p<ar+N;p++){
        if(*p==0){
            printf("%d",count);
            break;
        }
        else{
            count++;
        }
    }
}