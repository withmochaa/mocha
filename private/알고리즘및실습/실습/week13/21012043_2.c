#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

// Union-Find에 사용될 배열과 구조체 정의
int parent[100];
int num[100];

typedef struct {
    int v;      // 간선의 시작 노드
    int u;      // 간선의 끝 노드
    int key;    // 간선의 가중치
} Graph;

typedef struct {
    Graph heap[100];   // 간선들을 저장할 힙 구조체
    int heap_size;      // 힙의 크기
} Heap;

// 힙 초기화 함수
void InitHeap(Heap *h) {
    h->heap_size = 0;   // 힙 크기를 0으로 초기화
}

// 힙에 원소 삽입하는 함수
void InsertHeap(Heap *h, Graph item) {
    int i;
    i = ++(h->heap_size);

    // 힙에 원소 삽입 후 정렬
    while (i != 1 && item.key < h->heap[i / 2].key) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}

// 힙에서 원소 삭제하는 함수
Graph DeleteHeap(Heap *h) {
    int parent = 1, child = 2;
    Graph data, temp;

    data = h->heap[parent];
    temp = h->heap[(h->heap_size)--];

    // 힙 재구성
    while (child <= h->heap_size) {
        if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
            child++;

        if (temp.key <= h->heap[child].key) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;
    return data;
}

// Union-Find 초기화 함수
void InitUF(void) {
    int i;
    for (i = 0; i < 100; i++) {
        parent[i] = -1; // 초기에는 모든 노드가 본인이 집합의 대표이므로 -1로 초기화
        num[i] = 1;     // 각 집합의 크기는 초기에 1로 설정
    }
}

// 원소 찾기 함수 (경로 압축 기법 사용)
int Find_element(int v) {
    int i, p, temp;

    for (i = v; (p = parent[i]) >= 0; i = p);

    temp = i;

    for (i = v; (p = parent[i]) >= 0; i = p)
        parent[i] = temp; // 경로 압축: 부모 노드를 대표 노드로 설정하여 검색 시간 최적화

    return temp;
}

// 두 집합 합치기 함수
void SetUnion(int v1, int v2) {
    if (num[v1] < num[v2]) {
        parent[v1] = v2;
        num[v1] += num[v2]; // 노드 수 갱신
    }
    else {
        parent[v2] = v1;
        num[v2] += num[v1]; // 노드 수 갱신
    }
}

// 힙에 간선 삽입하는 함수
void InsertHeapEdge(Heap *h, int v, int u, int weight) {
    Graph node;
    node.v = v;
    node.u = u;
    node.key = weight;

    InsertHeap(h, node);
}

int main() {
    int n, m, i;
    int S2, S1, edgeCount = 0, sum = 0;
    Graph e;
    Graph *tmp;
    Heap h;
    tmp = (Graph *)malloc(sizeof(Graph));

    InitHeap(&h); // 힙 초기화
    InitUF();     // Union-Find 초기화

    // 노드 수 및 간선 수 입력
    scanf("%d", &n);
    getchar();

    scanf("%d", &m);

    // 간선 정보 입력 및 힙에 삽입
    for (i = 0; i < m; i++) {
        getchar();
        scanf("%d %d %d", &tmp->u, &tmp->v, &tmp->key);
        InsertHeapEdge(&h, tmp->u, tmp->v, tmp->key);
    }

    // 최소 신장 트리 생성
    while (edgeCount < n - 1) {
        e = DeleteHeap(&h);

        S1 = Find_element(e.u);
        S2 = Find_element(e.v);

        if (S1 != S2) {
            printf(" %d", e.key);
            sum += e.key;
            edgeCount++;
            SetUnion(S1, S2);
        }
    }

    // 최소 신장 트리의 총 가중치 출력
    printf("\n%d", sum);

    return 0;
}
