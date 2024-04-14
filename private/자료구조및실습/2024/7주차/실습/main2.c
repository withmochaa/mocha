#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


typedef struct Node {
	int data;
	struct Node* next;
}Node;


void add(Node *List, int a);
Node* Union(Node *A, Node *B);
Node* Intersect(Node *A, Node *B);



int main(void) {

	Node *A, *B, *U, *I, *tmp, *A1, *B1;
	int n, i, a;

    // 각 집합들 초기화

	A = (Node*)malloc(sizeof(Node));
	A->next = NULL;

	B = (Node*)malloc(sizeof(Node));
	B->next = NULL;

	A1 = (Node*)malloc(sizeof(Node));
	A1->next = NULL;

	B1 = (Node*)malloc(sizeof(Node));
	B1->next = NULL;

	scanf("%d", &n);
    //집합 A 입력
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		add(A1, a);
		add(A, a);
	}

	scanf("%d", &n);
    //집합 B 입력
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		add(B1, a);
		add(B, a);
	}

    //A와 B의 합집합 계산함
	U = Union(A1, B1);
	tmp = U->next;

    //합집합 출력
	if (tmp == NULL) {
		printf(" 0\n");
	}
	else {
		while (tmp != NULL) {
			printf(" %d ", tmp->data);
			tmp = tmp->next;
		}
		printf("\n");
	}

    //A와 B의 교집합 계산
	I = Intersect(A, B);
	tmp = I->next;

    //교집합 출력
	if (tmp == NULL) {
		printf(" 0\n");
	}
	else {
		while (tmp != NULL) {
			printf(" %d ", tmp->data);
			tmp = tmp->next;
		}
	}

    //동적 할당된 메모리 해제
    free(A);
    free(A1);
    free(B);
    free(B1);

	return 0;
}

//노드에 원소 추가
void add(Node *List, int a) {

	Node *p, *q;
	p = List;

	while (p->next != NULL) {
		p = p->next;
	}

	q = (Node*)malloc(sizeof(Node));
	q->data = a;
	p->next = q;
	q->next = NULL;

}

// 두 집합의 합집합을 계산함
Node* Union(Node *A, Node *B) {

	int a, b;
	Node *U, *tmp;

	U = (Node*)malloc(sizeof(Node));
	U->next = NULL;

	while (A->next != NULL & B->next != NULL) {
		a = (A->next)->data;
		b = (B->next)->data;
		if (a < b) {
			add(U, a);
			tmp = A->next;
			A->next = (A->next)->next;
			free(tmp);
		}
		else if (a > b) {
			add(U, b);
			tmp = B->next;
			B->next = (B->next)->next;
			free(tmp);
		}
		else {
			add(U, a);
			tmp = A->next;
			A->next = (A->next)->next;
			free(tmp);
			tmp = B->next;
			B->next = (B->next)->next;
			free(tmp);
		}
	}
	while (A->next != NULL) {
		a = (A->next)->data;
		add(U, a);
		tmp = A->next;
		A->next = (A->next)->next;
		free(tmp);
	}
	while (B->next != NULL) {
		b = (B->next)->data;
		add(U, b);
		tmp = B->next;
		B->next = (B->next)->next;
		free(tmp);
	}
	return U;

}

//두 집합의 교집합을 계산
Node* Intersect(Node *A, Node *B) {

	int a, b;
	Node *I, *tmp;

	I = (Node*)malloc(sizeof(Node));
	I->next = NULL;

	while (A->next != NULL & B->next != NULL) {
		a = (A->next)->data;
		b = (B->next)->data;
		if (a < b) {
			tmp = A->next;
			A->next = (A->next)->next;
			free(tmp);
		}
		else if (a > b) {
			tmp = B->next;
			B->next = (B->next)->next;
			free(tmp);
		}
		else {
			add(I, a);
			tmp = A->next;
			A->next = (A->next)->next;
			free(tmp);
			tmp = B->next;
			B->next = (B->next)->next;
			free(tmp);
		}
	}
	while (A->next != NULL) {
		tmp = A->next;
		A->next = (A->next)->next;
		free(tmp);
	}
	while (B->next != NULL) {
		tmp = B->next;
		B->next = (B->next)->next;
		free(tmp);
	}
	return I;

}