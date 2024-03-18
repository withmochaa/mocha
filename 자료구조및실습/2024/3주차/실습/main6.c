#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int gcd(int a,int b);

int main(void){
    int a,b,tmp;

    scanf("%d %d",&a,&b);

    if(a<b){
        tmp=a;
        a=b;
        b=tmp;
    }

    printf("%d",gcd(a,b));

    return 0;
}

int gcd(int a,int b){
    
    if(b==0){
        return a;
    }
    else{
        gcd(b,a%b);
    }
    
}
