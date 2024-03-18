#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void ha(int N, char a,char b,char c);

int main(void){

    int N;

    scanf("%d",&N);

    ha(N,'A','B','C');

    return 0;

    
}

void ha(int N, char a,char b,char c){


    if(N==1){
        printf("%c %c\n",a,c);
        return;
    }

    ha(N-1,a,c,b);
    printf("%c %c\n",a,c);
    ha(N-1,b,a,c);

    return;
}
