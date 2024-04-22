#include<stdio.h>
#include<stdlib.h>
typedef struct graph {
	int v;
	int **matrix;
}Graph;

Graph *createGraph(int v) {
	int i;
	Graph *G = (Graph*)malloc(sizeof(Graph));
	G->v = v;
	G->matrix = (int**)malloc(v * sizeof(int*));
	for (i = 0; i < v; i++)
	{
		G->matrix[i] = (int*)malloc(v * sizeof(int));
		memset(G->matrix[i], -1, sizeof(int)*v);  //전체를 -1로 초기화
	}
	return G;
}
void addEdge(Graph *G, int start, int dest, int weight) {
	G->matrix[start - 1][dest - 1] = weight;
	G->matrix[dest - 1][start - 1] = weight;
}
void deleteEdge(Graph *G, int start, int dest) {
	G->matrix[start - 1][dest - 1] = -1;
	G->matrix[dest - 1][start - 1] = -1;
}
void printGraph(Graph *G) {
	int i, j;
	for (i = 0; i < G->v; i++) {
		printf("%d ", i + 1);
		for (j = 0; j < G->v; j++)
			printf("%d ", G->matrix[i][j]);
		printf("\n");
	}
}
void funa(Graph *G) {
	int v, i;
	scanf("%d", &v);
	if (v > 6 || v < 1) printf("-1\n");
	else {
		for (i = 0; i < G->v; i++) {
			if (G->matrix[v - 1][i] != -1)
				printf("%d %d ", i + 1, G->matrix[v - 1][i]);
		}
		printf("\n");
	}
}
void funm(Graph *G) {
	int start, dest, weight;
	scanf("%d %d %d", &start, &dest, &weight);
	if (start > 6 || start < 1 || dest > 6 || dest < 1) {
		printf("-1\n");
	}
	else {
		deleteEdge(G, start, dest);
		if (weight != 0)
			addEdge(G, start, dest, weight);
	}
}
int main()
{
	char ch;
	Graph *G = createGraph(6);
	addEdge(G, 5, 6, 3);
	addEdge(G, 5, 5, 4);
	addEdge(G, 3, 5, 4);
	addEdge(G, 2, 3, 1);
	addEdge(G, 1, 6, 2);
	addEdge(G, 1, 4, 1);
	addEdge(G, 1, 3, 1);
	addEdge(G, 1, 2, 1);
	while (1) {
		scanf("%c", &ch);
		switch (ch) {
		case 'a':
			getchar();
			funa(G);
			break;
		case 'm':
			getchar();
			funm(G);
			break;
		case 'q':
			return 0;
		}
	}
}
