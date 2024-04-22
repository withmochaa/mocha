#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) 

int main(void) {

    int A[100][100] = { 0, }, row, col, val=1; // 2차원 배열 및 변수 선언, 초기화

    scanf("%d %d", &col, &row); // 열과 행의 크기 입력 받음

    int l=0, r=row-1, t=0, b=col-1; // 배열의 테두리 인덱스 변수 초기화

    // 테두리를 따라 값 채워넣기
    while(l <= r && t <= b) {
        // 왼쪽에서 오른쪽으로 채움
        for (int i = l; i <= r; i++) {
            if (val <= row * col) { // 배열이 채워지지 않았으면 값 삽입
                A[t][i] = val;
                val++;
            }
        }
        
        t++; // 위쪽 테두리를 내려감

        // 위쪽에서 아래쪽으로 채움
        for (int i = t; i <= b; i++) {
            if (val <= row * col) { // 배열이 채워지지 않았으면 값 삽입
                A[i][r] = val;
                val++;
            }
        }

        r--; // 오른쪽 테두리를 좌측으로 이동

        // 오른쪽에서 왼쪽으로 채움
        for (int i = r; i >= l; i--) {
            if (val <= row * col) { // 배열이 채워지지 않았으면 값 삽입
                A[b][i] = val;
                val++;
            }
        }

        b--; // 아래쪽 테두리를 위로 이동

        // 아래쪽에서 위쪽으로 채움
        for (int i = b; i >= t; i--) {
            if (val <= row * col) { // 배열이 채워지지 않았으면 값 삽입
                A[i][l] = val;
                val++;
            }
        }
        l++; // 왼쪽 테두리를 오른쪽으로 이동
    }

    // 출력
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%3d ", A[i][j]); // 각 요소 출력
        }
        printf("\n"); // 행이 바뀌면 줄바꿈
    }

    return 0; 
}