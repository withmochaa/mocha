#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) // 경고 메시지 무시

typedef struct vertex {
    int d; // 최단 거리
    int p; // 이전 노드
    int l; // 사용 여부 (미사용)
} vertex;

typedef struct Queue {
    int k; // 우선순위 (거리 값)
    int e; // 노드 번호
} Queue;

typedef struct Graph {
    int w[100][100]; // 그래프의 간선 가중치를 저장할 이차원 배열
} Graph;

Graph G;
vertex *v; // 정점 배열
Queue *Q; // 우선순위 큐
int n, m, s; // 노드의 수, 간선의 수, 시작 노드 번호

// 우선순위 큐를 거리 값으로 정렬하는 함수
void PQSort(int n) {
    int i, j;
    Queue Max, tmp;

    for (i = 1; i < n; i++) {
        tmp = Q[i];
        j = i - 1;
        while (Q[j].k > tmp.k && j >= 0) {
            Q[j + 1] = Q[j];
            j -= 1;
        }
        Q[j + 1] = tmp;
    }
}

// 우선순위 큐에서 최소값을 제거하는 함수
int removeMin(int n) {
    int i, res = Q[0].e;
    for (i = 0; i < n - 1; i++) {
        Q[i] = Q[i + 1];
    }
    return res;
}

// 특정 노드가 우선순위 큐에 존재하는지 확인하는 함수
int is_Q(int z, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (Q[i].e == z)
            return 1; // 존재함
    }
    return 0; // 존재하지 않음
}

// 우선순위 큐에서 특정 노드의 거리 값을 변경하는 함수
void replaceKey(int z, int w, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (Q[i].e == z) {
            Q[i].k = w; // 거리 값을 변경
        }
    }
    PQSort(n); // 변경 후 재정렬
}

// 다익스트라 알고리즘 함수
void Dijkstra() {
    int i, u, e, z;
    int tmp = n; // 남은 노드 수

    // 초기화
    for (i = 0; i < n; i++) {
        v[i].d = 21 * m; // 시작 노드로부터의 최단 거리 초기화
    }
    v[s].d = 0; // 시작 노드의 최단 거리는 0
    Q[0].k = v[s].d; // 우선순위 큐에 시작 노드 추가
    Q[0].e = s;

    // 모든 노드를 우선순위 큐에 추가
    for (i = 0; i < n; i++) {
        Q[i].k = v[i].d; // 거리 값 설정
        Q[i].e = i; // 노드 번호 설정
    }
    PQSort(n); // 우선순위 큐 정렬

    while (tmp != 0) {
        u = removeMin(tmp); // 최소값을 우선순위 큐에서 제거
        tmp--; // 남은 노드 수 감소

        // u와 연결된 간선들을 확인하며 최단 거리 갱신
        for (i = 0; i < n; i++) {
            e = G.w[u][i]; // u와 연결된 간선 가중치 확인
            if (e != 0) {
                z = i;
                if (is_Q(z, tmp)) { // z가 우선순위 큐에 존재하면
                    if (v[u].d + G.w[u][z] < v[z].d) { // 최단 거리 갱신 조건
                        v[z].d = v[u].d + G.w[u][z]; // 최단 거리 갱신
                        replaceKey(z, v[z].d, tmp); // 우선순위 큐 갱신
                    }
                }
            }
        }
    }
}

int main() {
    int i, j;
    int st, d, w;

    scanf("%d%d%d", &n, &m, &s);
    s = s - 1; // 시작 노드 번호를 배열 인덱스에 맞게 조정

    v = (vertex *)malloc(sizeof(vertex) * n); // 정점 배열 메모리 할당
    Q = (Queue *)malloc(sizeof(Queue) * n); // 우선순위 큐 메모리 할당

    // 그래프 초기화: 간선 가중치를 0으로 초기화
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            G.w[i][j] = 0;
        }
    }

    // 간선 정보 입력 및 저장
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &st, &d, &w);
        G.w[st - 1][d - 1] = w; // 가중치 정보 입력
        G.w[d - 1][st - 1] = w; // 가중치 정보 입력 (무방향 그래프를 가정)
    }

    Dijkstra(); // 다익스트라 알고리즘 실행

    // 결과 출력
    for (i = 0; i < n; i++) {
        if (i != s && v[i].d != 21 * m) // 시작 노드가 아니고 최단 거리가 초기값이 아닌 경우 출력
            printf("%d %d\n", i + 1, v[i].d); // 노드 번호와 최단 거리 출력
    }

    return 0;
}
