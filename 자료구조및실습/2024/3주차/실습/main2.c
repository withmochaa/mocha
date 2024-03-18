#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int find(int n);


int main(void){

    int n;

    scanf("%d",&n);

    find(n);


    return 0;
}

int find(int n){
    
    if(n<10){
        printf("%d\n",n);
    }
    else{
        find(n/10);
        printf("%d\n",n%10);
    }

}