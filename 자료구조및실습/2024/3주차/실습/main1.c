#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)


int NumSum(int N);

int main(void){

    int N;

    scanf("%d",&N);

    printf("%d",NumSum(N));


    return 0;
}
int NumSum(int N){

    

    if(N==1){
        return N;
    }
    else{
        
        return(N+NumSum(N-1));
    }


}