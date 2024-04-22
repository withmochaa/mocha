#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
void rPrintDigits(int N);
void printDigits(int N);



void printDigits(int N){

    if(N<10){
        printf("error");
    }
    else{
        rPrintDigits(N);
    }
}

void rPrintDigits(int N){
    if(N<10){
        printf("%d\n",N);
    }
    else{
        rPrintDigits(N/10);
        printf("%dㅇ\n",N%10);

    }
}

int main(void){
    int N;

    scanf("%d",&N);

    printDigits(N);

    return 0;
}


