#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) 


int main(void) {

    int v = 1, N, A[100][100]; 

    scanf("%d", &N); 

    for(int i = 0; i < N; i++) { // 행에 대한 반복문
        if(i % 2 == 0) { // 짝수 행일 때
            for(int j = 0; j < N; j++) { // 열에 대한 반복문
                A[i][j] = v; // 배열에 값을 넣어줌
                v++; // 값 증가
            }
        }
        else { // 홀수 행일 때
            for(int j = N - 1; j >= 0; j--) { // 열에 대한 반복문 (역순)
                A[i][j] = v; // 배열에 값을 넣어줌
                v++; // 값 증가
            }
        }
    }

    // 배열 요소 출력
    for(int i = 0; i < N; i++){ // 행에 대한 반복문
        for(int j = 0; j < N; j++) { // 열에 대한 반복문
            printf("%2d ", A[i][j]); // 배열 요소 출력
        }
        printf("\n"); // 한 행이 끝나면 줄 바꿈
    }

    return 0; 
}