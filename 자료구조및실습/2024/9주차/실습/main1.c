#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


typedef struct Stack {
    char *Arry; 
    int t, Max; 
} Stack;

//함수 선언
void push(Stack *S, char c);
char pop(Stack *S);
char peek(Stack *S);
void duplicate(Stack *S);
void upRotate(Stack *S, int n);
void downRotate(Stack *S, int n);
void print(Stack *S);
void initStack(Stack *S, int max); 
void freeStack(Stack *S); 


// 스택 초기화 및 동적 메모리 할당
void initStack(Stack *S, int max) {
    S->Max = max;
    S->t = -1;
    S->Arry = (char*)malloc(S->Max * sizeof(char)); 
    if (S->Arry == NULL) { 
        printf("Memory allocation failed\n");
        exit(1); // 비정상 종료
    }
}

// 스택 메모리 해제
void freeStack(Stack *S) {
    free(S->Arry); // 할당된 메모리 해제
}

// 스택에 요소를 추가하는 함수
void push(Stack *S, char c) {
    if (S->t >= S->Max - 1) { // 스택이 가득 찼는지 확인
        printf("Stack FULL\n");
    } 
    else {
        S->Arry[++S->t] = c; // 스택에 요소를 추가하고 top 인덱스를 증가
    }
}

// 스택에서 요소를 제거하고 반환하는 함수
char pop(Stack *S) {
    if (S->t == -1) { // 스택이 비었는지 확인
        printf("Stack Empty\n");
        return '\0'; 
    } 
    else {
        return S->Arry[S->t--]; // 스택의 top 요소를 반환하고 top 인덱스를 감소
    }
}

// 스택의 top에 있는 요소를 확인하는 함수
char peek(Stack *S) {
    if (S->t == -1) { // 스택이 비었는지 확인
        printf("Stack Empty\n");
        return '\0'; 
    } 
    else {
        return S->Arry[S->t]; // 스택의 top 요소를 반환
    }
}

// 스택의 top에 있는 요소를 복제하여 추가하는 함수
void duplicate(Stack *S) {
    if (S->t == -1) { // 스택이 비었는지 확인
        printf("Stack Empty\n");
    } 
    else if (S->t >= S->Max - 1) { // 스택이 가득 찼는지 확인
        printf("Stack FULL\n");
    } 
    else {
        char ch = peek(S); // top 요소를 확인
        push(S, ch); // top 요소를 복제하여 추가
    }
}

// 스택의 상위 n개 요소를 위로 회전시키는 함수
void upRotate(Stack *S, int n) {
    if (n <= S->t + 1 && n > 0) { // 회전할 요소가 유효한지 확인
        char ch = S->Arry[S->t];
        for (int i = S->t; i > S->t - n; i--) {
            S->Arry[i] = S->Arry[i - 1];
        }
        S->Arry[S->t - n + 1] = ch;
    }
}

// 스택의 상위 n개 요소를 아래로 회전시키는 함수
void downRotate(Stack *S, int n) {
    if (n <= S->t + 1 && n > 0) { // 회전할 요소가 유효한지 확인
        char ch = S->Arry[S->t - n + 1];
        for (int i = S->t - n + 1; i < S->t; i++) {
            S->Arry[i] = S->Arry[i + 1];
        }
        S->Arry[S->t] = ch;
    }
}

// 스택의 모든 요소를 출력하는 함수
void print(Stack *S) {
    for (int i = S->t; i >= 0; i--) {
        printf("%c", S->Arry[i]);
    }
    printf("\n");
}

int main(void) {
    Stack s; 
    int i, num, n;
    char c, a[10];

    scanf("%d", &n);
    initStack(&s, n); // 스택 초기화 및 동적 메모리 할당
    scanf("%d", &num);

    for (i = 0; i < num; i++) {
        getchar(); 
        scanf("%s", a);
        if (strcmp("PUSH", a) == 0) {
            getchar(); 
            scanf("%c", &c);
            push(&s, c);
        }
        else if (strcmp("POP", a) == 0) {
            pop(&s);
        }
        else if (strcmp("PEEK", a) == 0) {
            if (s.t != -1) {
                c = peek(&s);
                printf("%c\n", c);
            }
        }
        else if (strcmp("DUP", a) == 0) {
            duplicate(&s);
        }
        else if (strcmp("UpR", a) == 0) {
            scanf("%d", &n);
            upRotate(&s, n);
        }
        else if (strcmp("DownR", a) == 0) {
            scanf("%d", &n);
            downRotate(&s, n);
        }
        else if (strcmp("PRINT", a) == 0) {
            print(&s);
        }
    }

    freeStack(&s); 

    return 0;
}