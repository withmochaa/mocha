#pragma warning(disable:4996) // 경고 4996을 무시 (Visual Studio에서 사용되는 경고)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    int n, *x, temp; // int형 변수를 선언, 초기화는 하지 않음

    scanf("%d", &n);

    x = (int*)malloc(n * sizeof(int)); // 변수 x에 동적 할당

    for (int i = 0; i < n; i++) // 동적 할당 받은 x의 메모리에 정수를 입력받음
        scanf("%d", &x[i]);

    for (int i = 0; i < n - 1; i++) { // 삽입 정렬 알고리즘의 이중 반복문
        for (int j = 0; j <= i; j++) {
            if (x[j] > x[i + 1]) {
                temp = x[i + 1];
                for (int k = i + 1; k > j; k--) {
                    x[k] = x[k - 1];
                }
                x[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf(" %d", x[i]);
    }

    free(x); // 동적 할당 받은 메모리 해제

    return 0;
}
