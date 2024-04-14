#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {
    int key;
    struct Node* next;
} Node;

void initBucketArray();
int H(int x);
void insert(int k);
int find(int k);
int remove_(int k);
void print();

Node* h;
int M;

int main() {
    int k;
    char ch;

    // 배열 크기(M) 입력 받기
    scanf("%d", &M);
    h = (Node*)malloc(sizeof(Node) * M);

    // 버킷 배열 초기화
    initBucketArray();

    while (1) {
        getchar();
        scanf("%c", &ch);
        if (ch == 'i') {
            // 'i' 입력 시, 숫자를 읽어서 삽입
            scanf("%d", &k);
            insert(k);
        } else if (ch == 's') {
            // 's' 입력 시, 숫자를 읽어서 찾고 결과 출력
            scanf("%d", &k);
            printf("%d\n", find(k));
        } else if (ch == 'd') {
            // 'd' 입력 시, 숫자를 읽어서 삭제하고 결과 출력
            scanf("%d", &k);
            printf("%d\n", remove_(k));
        } else if (ch == 'p') {
            // 'p' 입력 시, 버킷 배열 내용 출력
            print(k);
        } else {
            // 그 외 입력 시, 루프 종료
            break;
        }
    }

    return 0;
}

// 버킷 배열 초기화
void initBucketArray() {
    int i;
    for (i = 0; i < M; i++) {
        (h + i)->next = NULL;
    }
}

// 해시 함수
int H(int x) {
    return x % M;
}

// 특정 키를 삽입하는 함수
void insert(int k) {
    int v = H(k);
    Node* new = (Node*)malloc(sizeof(Node));
    new->key = k;
    new->next = NULL;

    if ((h + v)->next == NULL) {
        (h + v)->next = new;
    } else {
        new->next = (h + v)->next;
        (h + v)->next = new;
    }
}

// 특정 키를 찾는 함수
int find(int k) {
    int v = H(k), cnt = 0;
    Node* tmp = (h + v)->next;

    if (tmp == NULL) {
        return 0;
    } else {
        while (tmp != NULL) {
            cnt++;
            if (tmp->key == k) {
                return cnt;
            } else {
                tmp = tmp->next;
            }
        }
        return 0;
    }
}

// 특정 키를 삭제하는 함수
int remove_(int k) {
    int v = H(k), cnt = 0;
    Node* tmp, *p;

    tmp = p = h + v;

    if (p->next == NULL) {
        return 0;
    } else {
        while (1) {
            p = p->next;
            cnt++;
            if (p->key == k) {
                while (tmp->next != p) {
                    tmp = tmp->next;
                }
                tmp->next = p->next;
                free(p);
                return cnt;
            }
            if (p->next == NULL) {
                return 0;
            }
        }
    }
}

// 버킷 배열의 내용을 출력하는 함수
void print() {
    Node* tmp;
    int i;
    for (i = 0; i < M; i++) {
        tmp = h + i;
        if (tmp->next != NULL) {
            tmp = tmp->next;
            printf(" %d", tmp->key);
            while (tmp->next != NULL) {
                tmp = tmp->next;
                printf(" %d", tmp->key);
            }
        }
    }
    printf("\n");
}
