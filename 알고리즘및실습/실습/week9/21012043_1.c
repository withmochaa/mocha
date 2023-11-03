#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef struct Node{
	int key;
	struct Node *next;
}Node;

void initBucketArray();
int H(int x);
void insert(int k);
int find(int k);
int remove_(int k);
void print();

Node *h;
int M;

int main() {

	int k;
	char ch;

	scanf("%d", &M);
	h = (Node*)malloc(sizeof(Node)*M);

	initBucketArray();

	while (1) {
		getchar();
		scanf("%c", &ch);
		if (ch == 'i') {
			scanf("%d", &k);
			insert(k);
		}
		else if (ch == 's') {
			scanf("%d", &k);
			printf("%d\n", find(k));
		}
		else if (ch == 'd') {
			scanf("%d", &k);
			printf("%d\n", remove_(k));
		}
		else if (ch == 'p') {
			print(k);
		}
		else {
			break;
		}

	}
	

	return 0;
}

void initBucketArray() {
	int i;
	for (i = 0; i < M; i++) {
		(h + i)->next = NULL;
	}
}

int H(int x) {
	return x % M;
}

void insert(int k) {
	int v = H(k);
	Node *new = (Node*)malloc(sizeof(Node));
	new->key = k;
	new->next = NULL;

	if ((h + v)->next == NULL) {
		(h + v)->next = new;
	}
	else {
		new->next = (h + v)->next;
		(h + v)->next = new;
	}
}

int find(int k) {
	int v = H(k), cnt = 0;
	Node *tmp = (h + v)->next;

	if (tmp == NULL) {
		return 0;
	}
	else {
		while (tmp != NULL) {
			cnt++;
			if (tmp->key == k) {
				return cnt;
			}
			else {
				tmp = tmp->next;
			}
		}
		return 0;
	}
}

int remove_(int k) {
	int v = H(k), cnt = 0;
	Node *tmp, *p;

	tmp = p = h + v;

	if (p->next == NULL) {
		return 0;
	}
	else {
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

void print() {
	Node *tmp;
	int i;
	for(i = 0; i < M; i++) {
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