#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct edge {
    int d; // 목적지 노드
    int s; // 출발지 노드
    int w; // 가중치
} edge;

int n, m, s, *res;
edge *e;

// 벨만-포드 알고리즘을 이용하여 최단 경로를 계산하는 함수
int *bellman() {
    int i, j;
    res = (int *)malloc(sizeof(int) * n);
    int u, z;
    edge tmp;

    // 초기화: 최단 거리를 초기값으로 설정
    for (i = 0; i < n; i++)
        res[i] = 21 * m; // 초기값은 충분히 큰 값으로 설정

    res[s - 1] = 0; // 시작 노드의 최단 거리는 0으로 설정

    for (i = 1; i < n; i++) {
        for (j = 0; j < m; j++) {
            tmp = e[j];
            u = tmp.s - 1;
            if (res[u] != 21 * m) {
                z = tmp.d - 1;
                // 최단 거리 갱신
                res[z] = min(res[z], res[u] + tmp.w);
            }
        }
    }
}

int main() {
    int i;
    scanf("%d%d%d", &n, &m, &s);
    e = (edge *)malloc(sizeof(edge) * m);

    // 간선 정보 입력
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &e[i].s, &e[i].d, &e[i].w);
    }

    bellman(); // 벨만-포드 알고리즘을 이용하여 최단 경로 계산

    // 최단 경로 출력
    for (i = 0; i < n; i++) {
        if (i + 1 != s && res[i] < 21 * m) {
            printf("%d %d\n", i + 1, res[i]);
        }
    }

    return 0;
}
