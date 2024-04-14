#pragma warning(disable:4013) // 경고 4013을 무시
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {

    int n, *x, max, temp; // 정수형 변수 선언, 초기화는 하지 않는다

    scanf("%d", &n);

    x = (int*)malloc(n * sizeof(int)); // 동적 할당

    for (int i = 0; i < n; i++) { // 동적 할당으로 받은 x의 메모리에 입력 값을 받음
        scanf("%d", &x[i]);
    }

    for (int i = n - 1; i >= 0; i--) { // max 값을 찾기 위한 이중 for 문 (외부 for 루프)
        max = i;
        for (int j = i - 1; j >= 0; j--) { // 내부 for 루프
            if (x[j] > x[max]) {
                max = j;
            }
        }

        temp = x[i]; // 스왑 (두 원소의 위치를 교환)
        x[i] = x[max];
        x[max] = temp;
    }

    for (int i = 0; i < n; i++) { // 정렬된 배열을 출력
        printf(" %d", x[i]);
    }

    free(x); // 동적 할당 받은 메모리 해제

    return 0;
}
