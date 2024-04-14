#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) // 경고 4996을 무시

void rBuildHeap(int i); // 반환값이 없는 rBuildHeap 함수 정의
void BuildHeap();
void downheap(int i);
void printHeap();

int H[100], n = 0;

int main(void) {

    int i;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
    }
    // 함수 호출
    BuildHeap();
    printHeap();

    return 0;
}

void rBuildHeap(int i) { // rBuildHeap 함수

    if (i > n) { // 함수 종료 조건 : 반환값은 없음, 약간의 종료 조건
        return;
    }
    rBuildHeap(2 * i); // 자기 자신(함수)를 다시 호출
    rBuildHeap(2 * i + 1);
    downheap(i);
    return;
}

void BuildHeap() { // BuildHeap 함수

    int i;
    for (i = n / 2; i >= 1; i--) { // 반복문을 생성해 downheap 함수를 반복적으로 호출
        downheap(i);
    }
}

void downheap(int i) { // downheap 함수

    int left = 2 * i, right = 2 * i + 1, big, tmp; // 사용할 변수 선언 및 초기화

    if (left > n) { // 함수 종료 : 반환값이 없음을 이용
        return;
    }

    big = left;

    if (right <= n) {
        if (H[right] > H[big]) {
            big = right;
        }
    }

    if (H[i] >= H[big]) {
        return;
    }
    // 스왑
    tmp = H[big];
    H[big] = H[i];
    H[i] = tmp;

    downheap(big); // downheap 함수 호출
}

void printHeap() { // printHeap 함수

    int i;

    for (i = 1; i <= n; i++) { // 출력
        printf(" %d", H[i]);
    }
    printf("\n");
}
