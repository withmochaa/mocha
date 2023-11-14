#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#define MAX 6
#define SWAP(a,b) ((a)^=(b)^=(a)^=(b))

typedef struct {
	int *que;
	int front, rear;
	int size;
} queue;

typedef struct vertex {
	int name;
	int label;
} vertex;

typedef struct edge {
	char name;
	int weight;
	int label;
	int endpoints[2];
} edge;

typedef struct graph {
	vertex *vertices;
	edge *edges;
	int **adjacencyMatrix;
	int N, M;
} graph;

void enqueue(queue*, int);
int dequeue(queue*);

void initi(graph *);
void insertMatrixItem(graph *, int, int, int);
void removeMatrixItem(graph *, int, int);
void insertEdge(graph *, int, int, int);
void BFS(graph *, int);
void BFS1(graph *, vertex *);

int main() {
	int point_0, point_1, S;
	graph Graph;

	// 입력: 정점의 수(N), 간선의 수(M), 시작 정점(S)
	scanf("%d %d %d", &Graph.N, &Graph.M, &S);

	// 그래프의 정점, 간선, 인접행렬에 동적 메모리 할당
	Graph.vertices = (vertex *)malloc(Graph.N * sizeof(vertex));
	Graph.edges = (edge *)malloc(Graph.N * (Graph.N + 1) / 2 * sizeof(edge));
	Graph.adjacencyMatrix = (int**)malloc(Graph.N * sizeof(int*));

	for (int i = 0; i < Graph.N; ++i)
		Graph.adjacencyMatrix[i] = (int*)malloc(Graph.N * sizeof(int));

	initi(&Graph); // 그래프 초기화

	// 간선 정보 입력받아 그래프에 삽입
	for (int i = 0; i < Graph.M; ++i) {
		scanf("%d %d", &point_0, &point_1);
		insertEdge(&Graph, point_0, point_1, 1);
	}

	BFS(&Graph, S); // 너비 우선 탐색 수행
	return 0;
}

// 그래프 초기화 함수
void initi(graph* g) {
	int i, j, edge_num;

	for (i = 0; i < g->N; ++i) {
		g->vertices[i].name = i + 1;
		for (j = 0; j < g->N; ++j) {
			g->adjacencyMatrix[i][j] = -1; // 인접 행렬 초기화
			if (j <= i) {
				edge_num = i * (i + 1) / 2 + j;
				g->edges[edge_num].endpoints[0] = i + 1;
				g->edges[edge_num].endpoints[1] = j + 1;
				g->edges[edge_num].weight = 0;
			}
		}
	}
	// 초기 그래프 예시
	/*
	insertEdge(g, 1, 2, 1);
	insertEdge(g, 1, 3, 1);
	insertEdge(g, 1, 4, 1);
	insertEdge(g, 1, 6, 2);
	insertEdge(g, 2, 3, 1);
	insertEdge(g, 3, 5, 4);
	insertEdge(g, 5, 5, 4);
	insertEdge(g, 5, 6, 3);
	*/
}

// 큐에 요소 추가
void enqueue(queue* q, int e) {
	if ((q->rear + 1) % q->size == q->front) {
		printf("오버플로우\n");
		exit(-1);
	}
	else {
		q->rear = (q->rear + 1) % q->size;
		q->que[q->rear] = e;
	}
}

// 큐에서 요소 제거
int dequeue(queue* q) {
	int e;

	if (q->rear == q->front) {
		printf("언더플로우\n");
		exit(-1);
	}
	else {
		q->front = (q->front + 1) % q->size;
		e = q->que[q->front];
		q->que[q->front] = 0;
		return e;
	}
}

// 인접 행렬에 간선 정보 삽입
void insertMatrixItem(graph *g, int edge_num, int initial_point, int terminal_point) {
	g->adjacencyMatrix[initial_point][terminal_point] = edge_num;
	g->adjacencyMatrix[terminal_point][initial_point] = edge_num;
}

// 인접 행렬에서 간선 정보 제거
void removeMatrixItem(graph *g, int initial_point, int terminal_point) {
	g->adjacencyMatrix[initial_point][terminal_point] = -1;
	g->adjacencyMatrix[terminal_point][initial_point] = -1;
}

// 그래프에 새로운 간선을 삽입하는 함수
void insertEdge(graph *g, int a, int b, int w) {
	int initial_point = a - 1,
		terminal_point = b - 1,
		edge_num;

	if (initial_point < 0 || initial_point >= g->N || terminal_point < 0 || terminal_point >= g->N) puts("-1");
	else {
		if (initial_point > terminal_point) SWAP(initial_point, terminal_point);
		edge_num = terminal_point * (terminal_point + 1) / 2 + initial_point;
		if (g->edges[edge_num].weight) {
			if (w == 0)
				removeMatrixItem(g, initial_point, terminal_point);
		}
		else
			insertMatrixItem(g, edge_num, initial_point, terminal_point);

		g->edges[edge_num].weight = w;
	}
}

// 너비 우선 탐색 함수
void BFS(graph* g, int S) {
	int i;

	// 방문 여부 초기화
	for (i = 0; i < g->N; ++i)
		g->vertices[i].label = 0;

	for (i = 0; i < ((g->N + 1) * g->N) / 2; ++i)
		g->edges[i].label = 0;

	BFS1(g, &g->vertices[S - 1]); // BFS1 함수 호출
}

// 너비 우선 탐색의 실제 구현 함수
void BFS1(graph *g, vertex *v) {
	queue list = { NULL, 0, 0, g->N };
	vertex *w = NULL;

	list.que = (int*)calloc(list.size, sizeof(int));

	enqueue(&list, v->name);
	printf("%d\n", v->name);
	v->label = 1;

	while (list.front != list.rear) {
		v = &g->vertices[dequeue(&list) - 1];
		for (int i = 0; i < g->N; ++i) {
			if (g->adjacencyMatrix[v->name - 1][i] != -1)
				if (g->edges[g->adjacencyMatrix[v->name - 1][i]].label == 0) {
					w = &g->vertices[i];
					if (w->label == 0) {
						g->edges[g->adjacencyMatrix[v->name - 1][i]].label = 1;
						printf("%d\n", w->name);
						w->label = 1;
						enqueue(&list, w->name);
					}
					else g->edges[g->adjacencyMatrix[v->name - 1][i]].label = 2;
				}
		}
	}
}
