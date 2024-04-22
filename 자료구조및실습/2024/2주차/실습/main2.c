#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) /

// 가장 많은 1을 갖는 행을 찾는 함수
int mostOnes(int x[][100], int n) {
    int index = 0, i = 0;
    int max = 0;

    // 각 행을 반복
    while (i < n) {
        // 현재 요소가 0이면 다음 행으로 이동
        if (x[i][index] == 0)
            i++;
        else {
            // 현재 요소가 1이면 다음 열로 이동
            index++;
            // max를 현재 행 번호로 업데이트
            max = i;
        }
    }
    // 가장 많은 1을 갖는 행의 번호 반환
    return max;
}

int main(void) {
    int n, x[100][100];
    int i, j;
    scanf("%d", &n); // 행렬의 크기 입력

    // 행렬 요소 입력
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &x[i][j]);
        }
    }
    // 함수 호출하여 가장 많은 1을 갖는 행 출력
    printf("%d", mostOnes(x, n));

    return 0;
}

