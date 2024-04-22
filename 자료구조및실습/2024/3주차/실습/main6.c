#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) 

// 최대공약수를 구하는 함수
int gcd(int a, int b);

int main(void){
    int a, b, tmp;

    // 사용자로부터 두 정수 입력 받기
    scanf("%d %d", &a, &b);

    // a가 작은 수가 되도록 조정
    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }

    // 최대공약수 출력
    printf("%d", gcd(a, b));

    return 0;
}

// 재귀적으로 최대공약수를 구하는 함수
int gcd(int a, int b){
    
    // b가 0이면 a를 반환
    if(b == 0){
        return a;
    }
    else{
        // 유클리드 호제법을 이용하여 최대공약수 계산
        return gcd(b, a % b);
    }
}
