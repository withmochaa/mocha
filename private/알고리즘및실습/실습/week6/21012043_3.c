#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable: 4996)

int main(void) {
    int a, b, k, num, i, m;
    char ch;

    // 시작 범위 a, 끝 범위 b, 질문 횟수 num를 입력 받음
    scanf("%d %d %d", &a, &b, &num);
    getchar(); // 버퍼에서 개행 문자('\n')를 제거

    for (i = 0; i < num; i++) {
        m = (a + b) / 2; // 현재 범위의 중간값을 계산

        // 'Y' 또는 'N'을 입력 받음
        scanf("%c", &ch);

        if (ch == 'Y') {
            a = m + 1; // 중간값보다 큰 범위로 업데이트
        } else if (ch == 'N') {
            b = m; // 중간값보다 작은 범위로 업데이트
        }

        // 범위가 더 이상 좁아지지 않으면 답을 출력
        if (a == b) {
            printf("%d", a);
        }
    }

    return 0;
}