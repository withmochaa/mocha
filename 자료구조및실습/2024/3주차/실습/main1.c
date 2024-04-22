#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) 

// N부터 1까지의 정수의 합을 반환하는 함수
int NumSum(int N);

int main(void){

    int N;

    // 사용자로부터 정수 입력 받기
    scanf("%d",&N);

    // NumSum 함수 호출하여 결과 출력
    printf("%d",NumSum(N));

    return 0;
}

// 재귀적으로 정수의 합을 계산하는 함수
int NumSum(int N){

    // 기저 사례: N이 1일 때는 N을 반환
    if(N==1){
        return N;
    }
    else{
        // N부터 1까지의 정수 합을 재귀적으로 계산하여 반환
        return(N+NumSum(N-1));
    }
}
