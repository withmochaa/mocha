#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable: 4996)

int tmp = -1;

// 이진 탐색 함수 정의
int rSearch(int A[], int k, int l, int r);

int main(void) {
    int n, k, *A, i, result;

    // 배열 크기와 찾을 값을 입력 받음
    scanf("%d %d", &n, &k);

    // 동적으로 정수 배열 할당
    A = (int*)malloc(sizeof(int) * n);

    // 배열 요소 입력
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // 이진 탐색 함수 호출
    result = rSearch(A, k, 0, n - 1);

    // 결과 출력
    printf("%d", result);

    // 메모리 해제
    free(A);

    return 0;
}

// 재귀적 이진 탐색 함수 정의
int rSearch(int A[], int k, int l, int r) {
    int mid, result;

    // 범위가 역전되면 원하는 값이 배열에 없음
    if (l > r) {
        return tmp;
    }

    // 중간 위치 계산
    mid = (l + r) / 2;

    // 원하는 값 찾으면 인덱스 반환
    if (k == A[mid]) {
        return mid;
    }
    else if (k < A[mid]) {
        // 왼쪽 반 배열에서 재귀 호출
        return rSearch(A, k, l, mid - 1);
    }
    else {
        // 오른쪽 반 배열에서 재귀 호출
        tmp = mid; // 임시 변수에 mid 저장
        return rSearch(A, k, mid + 1, r);
    }
}
