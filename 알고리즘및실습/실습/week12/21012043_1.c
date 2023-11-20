#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct _Node {
	int element;
	struct _Node* next;
} Node;

typedef struct _Vertex {
	char name;
	Node* outEdges;  // 정점에서 나가는 간선을 나타내는 연결 리스트의 헤드 노드
	Node* inEdges;   // 정점으로 들어오는 간선을 나타내는 연결 리스트의 헤드 노드
	int inDegree;    // 들어오는 간선의 수
} vertex;

typedef struct _Edge {
	int origin;
	int destination;
} edge;

typedef struct _Graph {
	vertex* vertices;  // 정점 배열
	edge* edges;       // 간선 배열
} Graph;

Graph G;               // 그래프 객체
int n, m;              // 정점의 개수와 간선의 개수
int topOrder[101];     // 위상 정렬 결과를 저장하는 배열
int* Q;
int front = -1, rear = -1;
int* in;


void initializeGraph() {
	// 그래프 초기화 - 정점과 간선 배열 할당
	G.vertices = (vertex*)malloc(sizeof(vertex) * 100);
	G.edges = (edge*)malloc(sizeof(edge) * 1000);
}

void inserVertex(char vName, int i) {
	// 그래프에 정점 추가
	G.vertices[i].name = vName;
	// 각 정점의 나가는 간선과 들어오는 간선을 나타내는 연결 리스트 초기화
	G.vertices[i].outEdges = (Node*)malloc(sizeof(Node));
	G.vertices[i].outEdges->next = NULL;
	G.vertices[i].inEdges = (Node*)malloc(sizeof(Node));
	G.vertices[i].inEdges->next = NULL;
	G.vertices[i].inDegree = 0; // 들어오는 간선의 수 초기화
	return;
}

int index(char vName) {
	// 정점의 인덱스 반환
	int i;
	for (i = 0; i < n; i++)
		if (G.vertices[i].name == vName)
			return i;
}

void insertFirst(Node* H, int i) {
	// 리스트의 첫 번째에 원소 삽입
	Node* node = (Node*)malloc(sizeof(Node));
	node->element = i;
	node->next = H->next;
	H->next = node;
	return;
}

void insertDirectedEdge(char uName, char wName, int i) {
	// 방향성 있는 간선 추가
	int u, w;
	u = index(uName); // 출발 정점의 인덱스
	w = index(wName); // 도착 정점의 인덱스
	G.edges[i].origin = u;
	G.edges[i].destination = w;
	insertFirst(G.vertices[u].outEdges, i);  // 출발 정점의 나가는 간선 리스트에 추가
	insertFirst(G.vertices[w].inEdges, i);   // 도착 정점의 들어오는 간선 리스트에 추가
	G.vertices[w].inDegree++;               // 도착 정점의 들어오는 간선 수 증가
	return;
}

int isEmpty() {
	// 큐가 비어 있는지 확인
	if (front == rear)
		return 1;
	else
		return 0;
}

void enqueue(int v) {
	// 큐에 원소 추가
	rear += 1;
	Q[rear] = v;
}

int dequeue() {
	// 큐에서 원소 제거
	front += 1;
	return Q[front];
}

void topologicalSort() {
	// 위상 정렬 수행
	int i, t, u, e, w;
	Node* tmp = (Node*)malloc(sizeof(Node));
	Q = (int*)malloc(sizeof(int) * n + 1);
	in = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		in[i] = G.vertices[i].inDegree;
		if (in[i] == 0)
			enqueue(i); // 들어오는 간선이 없는 정점 큐에 추가
	}
	t = 1;
	while (!isEmpty()) {
		u = dequeue(); // 큐에서 정점 추출
		topOrder[t] = u; // 결과를 위한 배열에 순서대로 저장
		t = t + 1;
		tmp = G.vertices[u].outEdges->next;
		while (tmp != NULL) {
			e = tmp->element; // 간선의 인덱스
			w = G.edges[e].destination; // 도착 정점의 인덱스
			in[w] = in[w] - 1; // 해당 정점의 들어오는 간선 수 감소
			if (in[w] == 0)
				enqueue(w); // 들어오는 간선이 없어진 경우 큐에 추가
			tmp = tmp->next;
		}
	}
	if (t <= n)
		topOrder[0] = 0; // 사이클이 존재하는 경우
	else
		topOrder[0] = 1; // 위상 정렬이 완료된 경우
	free(in);
	return;
}

void buildGraph() {
	// 그래프 구성
	int i;
	char vName;
	char uName, wName;
	scanf("%d", &n); // 정점의 개수 입력
	initializeGraph();
	for (i = 0; i < n; i++) {
		getchar();
		scanf("%c", &vName); // 정점 이름 입력
		inserVertex(vName, i); // 정점 추가
	}
	scanf("%d", &m); // 간선의 개수 입력
	for (i = 0; i < m; i++) {
		getchar();
		scanf("%c", &uName); // 출발 정점 이름 입력
		getchar();
		scanf("%c", &wName); // 도착 정점 이름 입력
		insertDirectedEdge(uName, wName, i); // 방향성 있는 간선 추가
	}
	return;
}

int main() {
	// 메인 함수
	int i;
	buildGraph(); // 그래프 구성
	topologicalSort(); // 위상 정렬 수행
	if (topOrder[0] == 0)
		printf("0\n"); // 사이클이 존재하는 경우
	else {
		for (i = 1; i < n + 1; i++)
			printf("%c ", G.vertices[topOrder[i]].name); // 위상 정렬 결과 출력
		printf("\n");
	}
	return 0;
}
