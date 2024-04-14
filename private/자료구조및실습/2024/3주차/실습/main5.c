#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) 

// 하노이 탑을 구현하는 함수
void ha(int N, char a, char b, char c);

int main(void){

    int N;

    // 사용자로부터 입력 받은 원반의 개수
    scanf("%d", &N);

    // 하노이 탑을 구현하는 함수 호출
    ha(N, 'A', 'B', 'C');

    return 0;
}

// 하노이 탑을 재귀적으로 구현하는 함수
void ha(int N, char a, char b, char c){

    // 원반이 1개일 때
    if(N == 1){
        printf("%c %c\n", a, c);
        return;
    }

    // 가장 큰 원반을 제외한 원반들을 C로 이동
    ha(N - 1, a, c, b);
    // 가장 큰 원반을 목적지로 이동
    printf("%c %c\n", a, c);
    // C에 있는 원반들을 다시 목적지로 이동
    ha(N - 1, b, a, c);

    return;
}
