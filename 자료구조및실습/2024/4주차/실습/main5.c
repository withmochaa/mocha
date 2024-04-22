#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) 


int main(void) {

    int A[100][100] = { 0, }; 

    int row, col, k, val = 0; 

    scanf("%d %d", &col, &row); // 열과 행의 크기 입력 받음

    // 왼쪽 위에서부터 대각선 방향으로 값을 채워넣음
    for(int j = 0; j < row; j++) {
        k = 0; // k 초기화
        for(int i = j; i >= 0 && k != col; i--) { // 대각선 방향으로 이동하며 값 채움
            val++; // 값 증가
            A[k++][i] = val; // 배열에 값 삽입
        }
    }

    // 오른쪽 아래 대각선 방향으로 값을 채워넣음
    for(int j = 1; j < col; j++) {
        k = row - 1; // k 초기화
        for(int i = j; i < col && k >= 0; i++) { // 대각선 방향으로 이동하며 값 채움
            val++; // 값 증가
            A[i][k--] = val; // 배열에 값 삽입
        }
    }

    // 출력
    for (int i = 0; i < col; i++) { // 행에 대한 반복문
        for (int j = 0; j < row; j++) { // 열에 대한 반복문
            printf("%3d ", A[i][j]); // 배열 요소 출력
        }
        printf("\n"); // 행이 바뀌면 줄바꿈
    }
    
    return 0; 
}