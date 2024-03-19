#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) 

// 각 자리의 숫자를 출력하는 함수
int find(int n);

int main(void){

    int n;

    // 사용자로부터 정수 입력 받기
    scanf("%d",&n);

    // find 함수 호출하여 각 자리의 숫자 출력
    find(n);

    return 0;
}

// 재귀적으로 각 자리의 숫자를 출력하는 함수
int find(int n){

    // n이 한 자리 숫자라면 그대로 출력
    if(n<10){
        printf("%d",n);
    }
    else{
        // n을 10으로 나눈 나머지를 출력하여 현재 자리의 숫자 출력
        printf("%d\n",n%10);
        // n을 10으로 나누어서 다음 자리의 숫자를 출력하도록 재귀 호출
        find(n/10);
    }
}






    
