#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) 


int main(void) {
    int n, a, b, c, tmp, N[100]; 

    scanf("%d", &n); 

    for(int i = 0; i < n; i++) { 
        scanf("%d", &N[i]);
    }

    scanf("%d", &c); // 반전할 위치의 개수 입력 받음

    int change[c]; // 반전할 위치를 저장할 배열

    for(int i = 0; i < c; i++) { // 반전할 위치들을 입력 받음
        scanf("%d", &change[i]);
    }

    tmp = N[change[0]]; // 첫 번째 위치의 값을 임시 변수에 저장

    // 배열의 뒷부분부터 순서대로 반전시킴
    for(int i = c - 1; i > 0; i--) {
        N[change[i]] = N[change[i - 1]]; // 한 칸씩 뒤로 이동
    }

    N[change[1]] = tmp; // 뒤로 밀렸던 값을 첫 번째 위치에 삽입

    
    for(int i = 0; i < n; i++) {
        printf(" %d", N[i]);
    }

    return 0; 
}