#pragma warning(disable:4996) 
#pragma warning(disable:4013) 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

// 주어진 배열의 접두사 평균을 계산하여 반환하는 함수 (방법 1)
int* prefixAverages1(int *x, int n) {
    int* y;
    y = (int*)malloc(n * sizeof(int));
    int i, j;

    // 각 위치의 접두사 평균 계산
    for (i = 0; i < n; i++) {
        double sum = 0;
        // 현재 위치까지의 합을 구함
        for (j = 0; j <= i; j++) {
            sum += x[j];
        }
        // 접두사 평균 계산 후 반올림하여 저장
        y[i] = (int)(sum / (i + 1) + 0.5);
    }
    return y;
}

// 주어진 배열의 접두사 평균을 계산하여 반환하는 함수 (방법 2)
int* prefixAverages2(int *x, int n) {
    int* y;
    y = (int*)malloc(n * sizeof(int));
    double sum = 0;
    int i;

    // 각 위치의 접두사 평균 계산
    for (i = 0; i < n; i++) {
        // 현재 위치까지의 합을 구함
        sum += x[i];
        // 접두사 평균 계산 후 반올림하여 저장
        y[i] = (int)(sum / (i + 1) + 0.5);
    }
    return y;
}

int main(void) {
    int n, *x, *p, *q;
    scanf("%d", &n); // 배열 크기 입력
    x = (int*)malloc(n * sizeof(int)); // 배열 동적 할당

    // 배열 요소 입력
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    // 각 함수를 통해 접두사 평균 계산
    p = prefixAverages1(x, n);
    q = prefixAverages2(x, n);

    // 결과 출력
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}
