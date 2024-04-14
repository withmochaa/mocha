#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct VERTEX {
    unsigned int d; // 최소 거리
    int locator;    // 위치 지정자
    unsigned int pNumber; // 부모 노드 번호
    unsigned int p;       // 부모 노드의 거리
} VERTEX;

typedef struct pQueue {
    unsigned int Key; // 우선순위 큐의 키 값
    int e;            // 원소 값
} pQueue;

typedef struct GRAPH {
    unsigned int **arr; // 그래프의 인접 행렬
} GRAPH;

GRAPH G; // 전역 변수로 그래프 선언

// 최소 신장 트리(Minimum Spanning Tree) 구하는 함수
void MST(int n) {
    int i, e, z, Qsize = n;
    unsigned int totalWeight = 0;
    unsigned int u;
    VERTEX *vertex, s;
    pQueue *Q;
    vertex = (VERTEX *)malloc(sizeof(VERTEX) * n); // 정점 정보 동적 할당
    Q = (pQueue *)malloc(sizeof(pQueue) * n);      // 우선순위 큐 동적 할당

    // 초기화
    for (i = 0; i < n; i++) {
        vertex[i].d = 2147483647; // 최소 거리를 최대값으로 설정
        vertex[i].p = 0;
    }

    s = vertex[0];
    s.d = 0;

    Q[0].Key = s.d;
    Q[0].e = 0;

    for (i = 1; i < n; i++) {
        Q[i].Key = vertex[i].d;
        Q[i].e = i;
    }

    while (Qsize != 0) {
        u = removeMin(Q, Qsize); // 최소값을 갖는 노드를 가져와서 u로 설정
        printf(" %d", u + 1);   // 현재 처리 중인 노드 출력
        Qsize--;

        // 모든 노드를 확인하여 거리를 업데이트
        for (i = 0; i < n; i++) {
            e = G.arr[u][i]; // 현재 노드에서 다른 노드로의 간선 가중치 확인
            z = opposite(u, e, n); // 현재 노드의 반대편 노드 인덱스 찾기

            // 우선순위 큐에 존재하고, 현재 거리보다 더 짧은 거리를 찾으면 업데이트
            if (isQueue(Q, z, Qsize) && (G.arr[u][z] < vertex[z].d)) {
                vertex[z].d = G.arr[u][z];
                vertex[z].p = e;
                vertex[z].pNumber = z;
                replaceKey(Q, z, G.arr[u][z], Qsize); // 우선순위 큐 업데이트
            }
        }
    }

    // 최종 최소 신장 트리의 가중치 계산
    for (i = 1; i < n; i++)
        totalWeight += vertex[i].d;
    printf("\n%d", totalWeight);
}

// 우선순위 큐가 비어있는지 확인하는 함수
int isEmpty(pQueue *Q) {
    if (Q[0].Key == 0)
        return 1;
    return 0;
}

// 우선순위 큐에서 최솟값을 삭제하는 함수
int removeMin(pQueue *Q, int n) {
    int result = Q[0].e;
    int i;
    for (i = 0; i < n - 1; i++) {
        Q[i] = Q[i + 1];
    }
    return result;
}

// 반대편 노드의 인덱스를 찾는 함수
int opposite(int u, int e, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (G.arr[u][i] == e)
            return i;
    }
}

// 해당 노드가 우선순위 큐에 있는지 확인하는 함수
int isQueue(pQueue *Q, int z, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (Q[i].e == z)
            return 1;
    }
    return 0;
}

// 우선순위 큐에서 특정 노드의 가중치를 업데이트하는 함수
void replaceKey(pQueue *Q, int z, int weight, int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (Q[i].e == z) {
            Q[i].Key = weight;
        }
    }
    PQSort(Q, n); // 업데이트 후 우선순위 큐 재정렬
}

// 우선순위 큐 정렬 함수
void PQSort(pQueue *Q, int n) {
    int i, j;
    pQueue Max, temp;

    for (i = 1; i < n; i++) {
        temp = Q[i];
        j = i - 1;
        while (Q[j].Key > temp.Key && j >= 0) {
            Q[j + 1] = Q[j];
            j -= 1;
        }
        Q[j + 1] = temp;
    }
}

int main() {
    int n, m, i, j;
    int from, to, weight;
    scanf("%d %d", &n, &m);

    G.arr = (unsigned int **)malloc(sizeof(unsigned int *) * n);

    for (i = 0; i < n; i++)
        G.arr[i] = (unsigned int *)malloc(sizeof(unsigned int *) * n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            G.arr[i][j] = 2147483647; // 초기값으로 최대값 설정
        }
    }

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &weight);
        G.arr[from - 1][to - 1] = weight;
        G.arr[to - 1][from - 1] = weight;
    }

    MST(n); // 최소 신장 트리 함수 호출
}
