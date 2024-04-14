#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// 느린 방법으로 1의 개수를 세는 함수
int countOnesButSlow(int **X, int n);
// 빠른 방법으로 1의 개수를 세는 함수
int countOnes(int **X, int n);

int main(void) {
    int **A = NULL, N;

    scanf("%d", &N);
    
    // 비트 행렬 A에 동적 할당
    A = (int**)malloc(N * sizeof(int*));

    for (int i = 0; i < N; i++) {
        A[i] = (int*)malloc(N * sizeof(int));
    }

    // 행렬의 값 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int count_slow = 0, count_fast = 0;

    // 느린 방법으로 1의 개수를 세기
    count_slow = countOnesButSlow(A, N);
    // 빠른 방법으로 1의 개수를 세기
    count_fast = countOnes(A, N);
    
    // 결과 출력
    printf("%d\n", count_slow);
    printf("%d", count_fast);

    // 동적 할당 해제
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}

// 느린 방법으로 1의 개수를 세는 함수
int countOnesButSlow(int **X, int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (X[i][j] == 1) {
                count++;
            } else if (X[i][j] == 0) {
                // 0을 만나면 해당 행의 계산을 중단
                break;
            }
        }
    }

    return count;
}

// 빠른 방법으로 1의 개수를 세는 함수
int countOnes(int **X, int n) {
    int i = 0, j = 0;
    int count = 0;

    while (i < n) {
        if (X[i][j] == 1) {
            // 다음 열로 이동하고 1의 개수를 증가
            j++;
            count++;
        }
        if (X[i][j] == 0 || j == n) {
            // 행의 끝에 도달하거나 0을 만나면 다음 행으로 이동
            i++;
            j = 0;
        }
    }
    
    return count;
}
