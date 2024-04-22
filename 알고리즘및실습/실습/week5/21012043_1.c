#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996) // 경고 4996을 무시

// Node 구조체 정의
typedef struct Node {
    int elem;
    struct Node* next;
} Node;

// 두 개의 연결 리스트를 가지고 있는 구조체 정의
typedef struct Ls {
    Node* L_1;
    Node* L_2;
} Ls;

// Node에 값을 추가하는 함수
void add(Node* L, int n);

// Node를 출력하는 함수
void print(Node* L);

// 연결 리스트를 병합 정렬하는 함수
void mergeSort(Node** L, int size);

// 두 개의 연결 리스트를 병합하는 함수
Node* merge(Node* L1, Node* L2);

// 연결 리스트를 분할하는 함수
Ls partition(Node* L, int k);

int main() {
    Node* L = NULL;
    int n, i, e;

    // 더미 노드 생성
    L = (Node*)malloc(sizeof(Node));
    L->next = NULL;

    // 입력 받을 숫자의 개수를 n에 저장
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &e);
        add(L, e);
    }

    // 병합 정렬 수행
    mergeSort(&L->next, n);

    // 정렬된 결과 출력
    print(L->next);

    return 0;
}

// 연결 리스트에 원소를 추가하는 함수
void add(Node* L, int n) {
    Node* p, * q;

    p = L;

    while (p->next != NULL) {
        p = p->next;
    }

    q = (Node*)malloc(sizeof(Node));
    q->elem = n;
    q->next = NULL;
    p->next = q;
}

// 병합 정렬 함수
void mergeSort(Node** L, int size) {
    Node* L1 = NULL, * L2 = NULL;
    Ls p;

    if (size > 1) {
        // 연결 리스트를 두 개로 분할
        p = partition(*L, size / 2);
        L1 = p.L_1;
        L2 = p.L_2;

        // 분할된 두 부분에 대해 병합 정렬 수행
        mergeSort(&L1, size / 2);
        mergeSort(&L2, size - size / 2);

        // 두 부분을 병합
        *L = merge(L1, L2);
    }
}

// 두 개의 연결 리스트를 병합하는 함수
Node* merge(Node* L1, Node* L2) {
    Node* L = NULL, * p;

    if (L1->elem <= L2->elem) {
        L = L1;
        L1 = L1->next;
    }
    else {
        L = L2;
        L2 = L2->next;
    }

    p = L;

    while (L1 != NULL && L2 != NULL) {
        if (L1->elem <= L2->elem) {
            p->next = L1;
            L1 = L1->next;
            p = p->next;
        }
        else {
            p->next = L2;
            L2 = L2->next;
            p = p->next;
        }
    }

    while (L1 != NULL) {
        p->next = L1;
        L1 = L1->next;
        p = p->next;
    }

    while (L2 != NULL) {
        p->next = L2;
        L2 = L2->next;
        p = p->next;
    }

    return L;
}

// 연결 리스트를 분할하는 함수
Ls partition(Node* L, int k) {
    Node* p, * L1, * L2;
    Ls result;
    int i;

    p = L;
    L1 = L;

    for (i = 0; i < k - 1; i++) {
        p = p->next;
    }
    L2 = p->next;
    p->next = NULL;

    result.L_1 = L1;
    result.L_2 = L2;

    return result;
}

// 연결 리스트를 출력하는 함수
void print(Node* L) {
    Node* p = L;
    while (p != NULL) {
        printf(" %d", p->elem);
        p = p->next;
    }
}
