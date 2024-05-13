#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


// 노드 구조체: 스택 내의 개별 요소를 나타내는 구조체
typedef struct Node {
	char ch; 
	struct Node *next; 
	int index; 
}Node;

// 스택 구조체: 노드들을 연결하여 스택을 구현
typedef struct Stack {
	Node *t; 
}Stack;

//함수 선언
void freeStack(Stack *s); 
void push(Stack *s, char c); 
char pop(Stack *s); 
void convert(char a[]); 


// 스택에 새로운 노드를 추가하는 함수
void push(Stack *s, char c) {
	
	Node *p;
	// 새 노드 생성 및 초기화
	p = (Node*)malloc(sizeof(Node));
	p->ch = c;
	p->next = s->t; // 새 노드를 현재 top 앞에 삽입
	s->t = p; // 새 노드를 새로운 top으로 설정
}

// 스택의 top 노드를 제거하고 그 값을 반환하는 함수
char pop(Stack *s) {
	
	char e;
	Node *p;

	if (s->t == NULL) {
		return 0; // 스택이 비어있으면 0을 반환
	}
	else {
		e = (s->t)->ch; // top 노드의 값을 e에 저장
		p = s->t; // p를 현재 top으로 설정
		s->t = (s->t)->next; // 현재 top을 다음 노드로 변경
		free(p); 
		return e; 
	}

}

// 중위 표현식을 후위 표현식으로 변환하는 함수
void convert(char a[]) {
	Stack *S; // 스택 포인터 선언
	int i = 0, P[7] = { 0,1,2,3,4,5,6 }, idx, sidx; 
	char s, tmp;

	S = (Stack*)malloc(sizeof(Stack)); 
	S->t = NULL; // 스택의 top을 NULL로 초기화

	while (a[i] != NULL) { 
		s = a[i]; 
		if ('A' <= a[i] && a[i] <= 'Z') {
			printf("%c", a[i]); 
		}
		else if (s == '(') {
			push(S, s); // 여는 괄호는 스택에 푸시
			(S->t)->index = 0; // 여는 괄호의 우선 순위를 최하로 설정
		}
		else if (s == ')') {
			while ((S->t)->ch != '(') {
				tmp = pop(S); // 닫는 괄호를 만나면 여는 괄호를 만날 때까지 pop하여 출력
				if (tmp == '&' || tmp == '|') {
					printf("%c", tmp); 
				}
				printf("%c", tmp); 
			}
			pop(S); 
		}
		else { // 연산자의 경우
			// 연산자의 우선 순위 설정
			if (a[i] == '|' && a[i + 1] == '|') {
				idx = 1;
				i++;
			}
			else if (a[i] == '&' && a[i + 1] == '&') {
				idx = 2;
				i++;
			}
			else if (a[i] == '<' || a[i] == '>') {
				idx = 3;
			}
			else if (a[i] == '+' || a[i] == '-') {
				if (i == 0 || a[i - 1] == '+' || a[i - 1] == '-' || a[i - 1] == '*' || a[i - 1] == '/') {
					idx = 6; // 단항 연산자 우선 순위
				}
				else {
					idx = 4; // 이항 연산자 우선 순위
				}
			}
			else if (a[i] == '/' || a[i] == '*') {
				idx = 5; // 곱셈, 나눗셈의 우선 순위
			}
			else {
				idx = 6; // 그 외 기타 연산자 우선 순위
			}

			while (S->t != NULL && P[idx] <= P[(S->t)->index]) {
				tmp = pop(S); // 현재 연산자의 우선 순위보다 높거나 같은 연산자를 스택에서 pop하여 출력
				if (tmp == '&' || tmp == '|') {
					printf("%c", tmp); // &&, || 연산자를 만나면 한 번 더 출력
				}
				printf("%c", tmp); // 다른 연산자는 한 번만 출력
			}
			push(S, s); // 현재 연산자를 스택에 푸시
			(S->t)->index = idx; // 현재 연산자의 우선 순위 설정
		}
		i++;
	}

	while (S->t != NULL) { // 스택이 비어있지 않은 경우 계속해서 pop하여 출력
		tmp = pop(S);
		if (tmp == '&' || tmp == '|') {
			printf("%c", tmp); // &&, || 연산자를 만나면 한 번 더 출력
		}
		printf("%c", tmp); // 다른 연산자는 한 번만 출력
	}
    freeStack(S); 
}

void freeStack(Stack *s) {
	free(s); 
}


int main(void) {

	char A[101];
	int n, i; 

	scanf("%d", &n); 

	for (i = 0; i < n; i++) {

		getchar(); 

		scanf("%s", A); 

		convert(A); 

		printf("\n"); 
        
	}

	return 0; 
}
