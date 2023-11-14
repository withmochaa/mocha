#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#define MAX 6
#define SWAP(a,b) ((a)^=(b)^=(a)^=(b)) // Swap 매크로 정의

// 간선 리스트를 나타내는 구조체
typedef struct incidentEdge {
	int edge_num; // 간선 번호
	struct incidentEdge *next; // 다음 간선을 가리키는 포인터
}incidentEdge;

// 정점을 나타내는 구조체
typedef struct vertex {
	int name; // 정점의 이름
	int label; // 방문 여부를 나타내는 레이블
	incidentEdge *incidentEdges; // 해당 정점과 연결된 간선 리스트의 헤드 포인터
}vertex;

// 간선을 나타내는 구조체
typedef struct edge {
	char name; // 간선의 이름
	int weight; // 간선의 가중치
	int label; // 방문 여부를 나타내는 레이블
	int endpoints[2]; // 간선의 두 끝점을 나타내는 배열
}edge;

// 그래프를 나타내는 구조체
typedef struct graph {
	vertex *vertices; // 정점 배열을 가리키는 포인터
	edge *edges; // 간선 배열을 가리키는 포인터
	int N, M; // 정점의 개수와 간선의 개수
}graph;

// 함수 원형 선언
void initi(graph *);
void insertIncidentEdge(graph *, int, int);
void removeIncidentEdge(graph *, int, int);
void insertEdge(graph *, int, int, int);
void DFS(graph *, int);
void rDFS(graph *, vertex *);

int main() {
	int point_0, point_1, S; // 입력 받을 변수 선언
	graph Graph; // 그래프 구조체 선언

	// 정점의 개수(N), 간선의 개수(M), 시작 정점(S) 입력
	scanf("%d %d %d", &Graph.N, &Graph.M, &S);

	// 그래프의 정점과 간선에 동적 메모리 할당
	Graph.vertices = (vertex *)malloc(Graph.N * sizeof(vertex));
	Graph.edges = (edge *)malloc(Graph.N * (Graph.N + 1) / 2 * sizeof(edge));
	initi(&Graph); // 그래프 초기화

	// 간선 정보 입력받아 그래프에 삽입
	for (int i = 0; i < Graph.M; ++i) {
		scanf("%d %d", &point_0, &point_1);
		insertEdge(&Graph, point_0, point_1, 1);
	}

	DFS(&Graph, S); // 깊이 우선 탐색 수행
	return 0;
}

// 그래프 초기화 함수
void initi(graph* g) {
	int i, j, edge_num;

	// 각 정점 초기화
	for (i = 0; i < g->N; ++i) {
		g->vertices[i].name = i + 1;
		g->vertices[i].incidentEdges = (incidentEdge *)malloc(sizeof(incidentEdge));
		g->vertices[i].incidentEdges->edge_num = -1; // 헤더 확인
		g->vertices[i].incidentEdges->next = NULL;
		for (j = 0; j <= i; ++j) {
			edge_num = i * (i + 1) / 2 + j;
			g->edges[edge_num].endpoints[0] = i + 1;
			g->edges[edge_num].endpoints[1] = j + 1;
			g->edges[edge_num].weight = 0;
		}
	}
}

// 해당 정점에 새로운 incident edge를 삽입하는 함수
void insertIncidentEdge(graph *g, int edge_num, int index) {
	incidentEdge *p = g->vertices[index].incidentEdges, *t = (incidentEdge *)malloc(sizeof(incidentEdge));
	t->edge_num = edge_num;

	// 해당 정점과 연결된 간선 리스트에 새로운 간선 삽입
	while (p->next) {
		if (p->next->edge_num == edge_num) {
			free(t);
			return;
		}
		if (p->next->edge_num > edge_num) break;
		p = p->next;
	}
	t->next = p->next;
	p->next = t;
}

// 해당 정점에서 incident edge를 제거하는 함수
void removeIncidentEdge(graph *g, int edge_num, int index) {
	incidentEdge *p = g->vertices[index].incidentEdges, *t;

	// 해당 정점과 연결된 간선 리스트에서 간선 제거
	while (p->next) {
		if (p->next->edge_num == edge_num) break;
		p = p->next;
	}
	if (p->next) {
		t = p->next;
		p->next = p->next->next;
		free(t);
	}
}

// 그래프에 새로운 간선을 삽입하는 함수
void insertEdge(graph *g, int a, int b, int w) {
	int initial_point = a - 1, terminal_point = b - 1, edge_num;

	if (initial_point < 0 || initial_point >= g->N || terminal_point < 0 || terminal_point >= g->N)
		puts("-1"); // 잘못된 입력 처리

	else {
		if (initial_point > terminal_point) SWAP(initial_point, terminal_point);
		edge_num = terminal_point * (terminal_point + 1) / 2 + initial_point;

		if (g->edges[edge_num].weight) {
			if (w == 0) {
				removeIncidentEdge(g, edge_num, initial_point);
				removeIncidentEdge(g, edge_num, terminal_point);
			}
		}
		else {
			insertIncidentEdge(g, edge_num, initial_point);
			insertIncidentEdge(g, edge_num, terminal_point);
		}
		g->edges[edge_num].weight = w;
	}
}

// 깊이 우선 탐색 함수
void DFS(graph* g, int S) {
	int i;

	// 방문 여부 초기화
	for (i = 0; i < g->N; ++i)
		g->vertices[i].label = 0;
	
	for (i = 0; i < ((g->N + 1) * g->N) / 2; ++i)
		g->edges[i].label = 0;

	rDFS(g, &g->vertices[S - 1]); // 재귀적인 DFS 호출
}

// 깊이 우선 탐색의 실제 구현 함수
void rDFS(graph *g, vertex *v) {
	incidentEdge *e = v->incidentEdges;
	vertex *w = NULL;

	printf("%d\n", v->name); // 현재 정점의 이름 출력
	v->label = 1; // 방문 표시

	while (e->next != NULL) {
		e = e->next;
		if (g->edges[e->edge_num].label == 0) {
			w = &g->vertices[g->edges[e->edge_num].endpoints[v->name == g->edges[e->edge_num].endpoints[0] ? 1 : 0] - 1];
			if (w->label == 0) {
				g->edges[e->edge_num].label = 1;
				rDFS(g, w); // 재귀적으로 다음 정점 방문
			}
			else g->edges[e->edge_num].label = 2;
		}
	}
}
