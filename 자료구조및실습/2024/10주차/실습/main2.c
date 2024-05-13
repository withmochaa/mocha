#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// 연결 리스트를 활용한 스택을 구현하기 위한 노드 구조체
typedef struct Node {
    int num; 
    struct Node* next; // 다음 노드를 가리키는 포인터
} Node;

// 스택을 관리하기 위한 구조체
typedef struct Stack {
    Node* t; // 스택의 맨 위 노드를 가리키는 포인터
} Stack;

// 함수 프로토타입 선언
void push(Stack* s, int c);
int pop(Stack* s);
void freeStack(Stack* s);
int evaluate(char a[]);
int doOperator(char op, int x, int y); 

// 스택에 데이터를 삽입하는 함수
void push(Stack* s, int c) {
    Node* p = (Node*)malloc(sizeof(Node)); 
    p->num = c; 
    p->next = s->t; 
    s->t = p; 
}

// 스택에서 데이터를 삭제하고 반환하는 함수
int pop(Stack* s) {
    if (s->t == NULL) {
        return -1; // 스택이 비어있을 경우 -1을 반환
    }

    Node* p = s->t; 
    int e = p->num; 
    s->t = p->next; 
    free(p); 
    return e; 
}

// 스택의 모든 노드를 삭제하고 메모리 해제하는 함수
void freeStack(Stack* s) {
    Node* temp;
    while (s->t != NULL) {
        temp = s->t; 
        s->t = temp->next; 
        free(temp); 
    }
    free(s); 
}

// 문자열로 표현된 수식을 계산하는 함수
int evaluate(char a[]) {
    Stack* S = (Stack*)malloc(sizeof(Stack)); 
    S->t = NULL; 
    int i = 0, x, y;

    while (a[i] != '\0') { 
        if ('0' <= a[i] && a[i] <= '9') {
            push(S, a[i] - '0'); 
        } else {
            y = pop(S); 
            x = pop(S); 
            push(S, doOperator(a[i], x, y)); 
        }
        i++;
    }

    int result = pop(S); // 최종 결과
    freeStack(S); 
    return result;
}

// 연산자에 따라 적절한 연산을 수행하는 함수
int doOperator(char op, int x, int y) {
    switch (op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
    }
    return 0;  // 기본 반환 값
}

// 메인 함수
int main(void) {
    char a[101]; 
    int n; 

    scanf("%d", &n); 
    while (n--) {
        scanf("%s", a); 
        printf("%d\n", evaluate(a)); // 수식 계산 결과 출력
    }
    return 0;
}
