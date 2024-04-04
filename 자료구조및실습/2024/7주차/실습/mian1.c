#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


typedef struct node{
	int elem;
	struct node *next;
}node;



void add(node *L, int n);
int member(node* L, int n);
int subset(node *A, node *B);



int main(void) {

	int a, b, i, n, result;

	node *A = NULL, *B = NULL, *p;

	scanf("%d", &a);//집합 A 입력

	for (i = 1; i <= a; i++) {
		scanf("%d", &n);

		if (A == NULL) {
			A = (node*)malloc(sizeof(node));
			A->next = NULL;
			A->elem = n;
		}
		else {
			add(A, n);
		}
	}

	scanf("%d", &b);//집합 B입력

	for (i = 1; i <= b; i++) {

		scanf("%d", &n);

		if (B == NULL) {
			B = (node*)malloc(sizeof(node));
			B->next = NULL;
			B->elem = n;
		}
		else {
			add(B, n);
		}
	}

	result = subset(A, B);//A가 B의 부분집합인지 확인 그리고 출력
	printf("%d", result);

    free(A);//동적 할당된 메모리 해제
    free(B);

    return 0;
}

//노드에 원소를 추가하는 함수
void add(node *L, int n) {

	node *p, *q;
	p = L;

	while (p->next != NULL) {
		p = p->next;
	}

  	q = (node*)malloc(sizeof(node));
	p->next = q;
	q->elem = n;
	q->next = NULL;

}

// 원소가 집합에 속하는지 확인하는 함수
int member(node* L, int n) {

	node *p;
	p = L;

	if (L == NULL) {
		return 0;
	}
	else {
		while (p != NULL) {
			if (p->elem > n) {
				return 0;
			}
			else if (p->elem == n) {
				return 1;
			}
			else {
				p = p->next;
			}
		}
	}
    return 0;
}

//A가 B의 부분집합인지 확인하는 함수
int subset(node *A, node *B) {

	int m;
	node *p;
	p = A;

	if (A == NULL) {
		return 0;
	}
	while (p != NULL) {
		m = member(B, p->elem);
		if (m == 0) {
			return p->elem;
		}
		else {
			p = p->next;
		}
	}
	return 0;
}