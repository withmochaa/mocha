#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996) 

// 정렬된 배열에서 요소를 검색하고 위치를 반환하는 함수
int Search(int A[], int k, int n);

int main() {
    int n, k, *A, i, result;

    // 배열 크기와 검색할 값을 입력받습니다.
    scanf("%d %d", &n, &k);

    // 정수 배열을 동적으로 할당합니다.
    A = (int*)malloc(sizeof(int) * n);

    // 배열 요소를 입력받습니다.
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Search 함수를 호출하여 배열에서 k의 위치를 찾습니다.
    result = Search(A, k, n);

    // 결과를 출력합니다.
    printf("%d", result);

    // 동적으로 할당한 메모리를 해제합니다.
    free(A);

    return 0;
}

// 이진 검색 함수
int Search(int A[], int k, int n) {
    int l = 0, r = n - 1, mid, tmp = n; // 변수 초기화

    while (l <= r) {
        mid = (l + r) / 2; // 중간 인덱스를 계산합니다.

        if (k == A[mid]) {
            return mid; // 요소를 찾으면 위치를 반환합니다.
        } else if (k < A[mid]) {
            tmp = mid; // 임시 결과를 업데이트하고 왼쪽 절반에서 검색합니다.
            r = mid - 1;
        } else {
            l = mid + 1; // 오른쪽 절반에서 검색합니다.
        }
    }

    return tmp; // 요소의 위치나 삽입해야 할 위치를 반환합니다.
}
