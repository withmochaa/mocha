#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int find(int k, int *h);
int insert(int k, int *h);
int getNextBucket(int v, int i);
int H(int x);

int M;

int main() {
    int k, *hash, i, n;
    char ch;

    // 버킷 배열 크기(M)와 연산 횟수(n) 입력 받기
    scanf("%d %d", &M, &n);
    hash = (int*)malloc(sizeof(int) * M);

    // 버킷 배열 초기화
    for (i = 0; i < M; i++) {
        hash[i] = 0;
    }

    while (1) {
        getchar();
        scanf("%c", &ch);
        if (ch == 'i') {
            // 'i' 입력 시, 숫자를 읽어서 삽입하고 결과 출력
            scanf("%d", &k);
            printf("%d\n", insert(k, hash));
        } else if (ch == 's') {
            // 's' 입력 시, 숫자를 읽어서 찾고 결과 출력 (존재하는 경우와 존재하지 않는 경우)
            scanf("%d", &k);
            if (find(k, hash) != -1) {
                printf("%d %d\n", find(k, hash), k);
            } else {
                printf("%d\n", find(k, hash));
            }
        } else {
            // 그 외 입력 시, 루프 종료
            break;
        }
    }

    return 0;
}

// 해시 함수
int H(int x) {
    return x % M;
}

// 다음 버킷 위치를 반환하는 함수
int getNextBucket(int v, int i) {
    return (v + i) % M;
}

// 특정 키를 삽입하는 함수
int insert(int k, int *h) {
    int v = H(k), i = 0, b;
    while (i < M) {
        b = getNextBucket(v, i);
        if (*(h + b) == 0) {
            *(h + b) = k;
            return b;
        } else {
            printf("C"); // 충돌 발생 시 출력
            i++;
        }
    }
}

// 특정 키를 찾는 함수
int find(int k, int *h) {
    int v = H(k), i = 0, b;
    while (i < M) {
        b = getNextBucket(v, i);
        if (*(h + b) == 0) {
            return -1; // 키가 존재하지 않는 경우
        } else if (k == *(h + b)) {
            return b; // 키를 찾은 경우
        } else {
            i++;
        }
    }
    return -1; // 키를 찾지 못한 경우
}
