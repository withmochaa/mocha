#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef struct Node {
	char ch;
	struct Node *next;
}Node;


typedef struct Stack {
	Node *t;
}Stack;

// 함수 선언
void push(Stack *s, char c); // 스택에 요소를 추가하는 함수
char pop(Stack *s); // 스택에서 요소를 제거하고 반환하는 함수
void freeStack(Stack *s); // 스택 메모리 해제를 위한 함수 선언
int isBalanced(char *st); // 괄호가 균형을 이루는지 확인하는 함수
int isCounterpart(char a, char st); // 짝이 맞는 괄호인지 확인하는 함수


void push(Stack *s, char c) {
	Node *p = (Node*)malloc(sizeof(Node)); // 새 노드 동적 할당
	p->ch = c;
	p->next = s->t;
	s->t = p;
}


char pop(Stack *s) {
	if (s->t == NULL) {
		return 0; // 스택이 비어 있으면 0 반환
	} else {
		char e = (s->t)->ch;
		Node *p = s->t;
		s->t = (s->t)->next;
		free(p); 
		return e;
	}
}


void freeStack(Stack *s) {
	Node *p = s->t;
	while (p != NULL) { // 스택이 비어있을 때까지
		Node *temp = p;
		p = p->next;
		free(temp); 
	}
	free(s); 
}


int isCounterpart(char a, char st) {
	if (st == '(' && a == ')') return 1;
	else if (st == '{' && a == '}') return 1;
	else if (st == '[' && a == ']') return 1;
	else return 0;
}


int isBalanced(char *st) {
	int i = 0, num = 0, plag = 1;
	char a;
	Stack *stack = (Stack*)malloc(sizeof(Stack)); 
	stack->t = NULL;

	while (st[i] != NULL) {
		if ((st[i] == '(') || (st[i] == '{') || (st[i] == '[')) {
			num++;
			push(stack, st[i]); // 여는 괄호일 경우 스택에 push
		}
		else if ((st[i] == ')') || (st[i] == '}') || (st[i] == ']')) {
			num++;
			if (stack->t == NULL) {
				plag = 0;
			}
			else {
				a = pop(stack); // 닫는 괄호일 경우 스택에서 pop
				if (!isCounterpart(st[i], a)) {
					plag = 0;
				}
			}
		}
		i++;
	}

	if (stack->t != NULL) plag = 0; // 스택이 비어있지 않다면 균형이 맞지 x

	if (plag == 0) {
		printf("Wrong_%d", num); // 균형이 맞지 않는 경우
	}
	else {
		printf("OK_%d", num); // 균형이 맞는 경우
	}

	freeStack(stack); // 스택 메모리 해제 호출

	return 0;
}

int main(void) {
	char st[1001];

	gets(st); 
	isBalanced(st);

	return 0;
}
