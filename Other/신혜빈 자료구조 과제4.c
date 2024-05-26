#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)
#include <time.h>

// 큐를 충분한 크기로 할당
int queueSize = 1000000;

int top = -1;

// 큐 구조체
typedef struct
{
    int *elem;
    int front;
    int rear;
} Queue;

// 스택 구조체(두 개의 큐 이용)
typedef struct
{
    Queue *Q1;
    Queue *Q2;
} Stack;

// 큐 초기화
void initQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    Q->elem = (int *)malloc(queueSize * sizeof(int));
}

// 스택 초기화
void initStack(Stack *stack)
{
    stack->Q1 = (Queue *)malloc(sizeof(Queue));
    stack->Q2 = (Queue *)malloc(sizeof(Queue));
    initQueue(stack->Q1);
    initQueue(stack->Q2);
}

// 스택이 비었는지 확인하는 함수
int isEmpty()
{
    return top == -1;
}

// 큐에 push하는 함수
void enqueue(Queue *Q, int value)
{
    Q->elem[Q->rear] = value;
    Q->rear++;
}

// 스택에 push하는 함수
void push(Stack *stack, int value)
{
    // 만약 Q2가 비어있는 경우 - Q1으로 값 넣기
    if (stack->Q2->front == stack->Q2->rear)
    {
        enqueue(stack->Q1, value);
    }
    // Q1이 비어있는 경우 - Q2로 값 넣기
    else
    {
        enqueue(stack->Q2, value);
    }
    // 스택의 top 1 증가
    top++;
}

// 스택에 push 100만번하는 함수
void pushMillion(Stack *stack)
{
    int value;
    for (int i = 0; i < 1000000; i++)
    {
        value = 10 + rand() % (90);
        push(stack, value);
    }
}

// 마지막 값 빼고 다른 큐로 옮기기
int dequeue(Stack *stack)
{
    // 만약 Q2가 비어있는 경우
    if (stack->Q2->front == stack->Q2->rear)
    {
        // 제일 마지막에 들어온 Q1 값 빼고 Q2로 값 옮기기
        while (stack->Q1->front < stack->Q1->rear - 1)
        {
            enqueue(stack->Q2, stack->Q1->elem[stack->Q1->front]);
            stack->Q1->front++;
        }
        // 마지막 값을 빼기
        int poppedValue = stack->Q1->elem[stack->Q1->front];
        stack->Q1->front++;
        return poppedValue;
    }
    // 만약 Q1이 비어있는 경우
    else
    {
        // 제일 마지막에 들어온 Q2 값 빼고 Q1로 값 옮기기
        while (stack->Q2->front < stack->Q2->rear - 1)
        {
            enqueue(stack->Q1, stack->Q2->elem[stack->Q2->front]);
            stack->Q2->front++;
        }
        // 마지막 값을 빼기
        int poppedValue = stack->Q2->elem[stack->Q2->front];
        stack->Q2->front++;
        return poppedValue;
    }
}

int ttop(Stack *stack)
{
    int value = dequeue(stack);
    
    if (stack->Q2->front == stack->Q2->rear)
    {
        enqueue(stack->Q1, value); 
    }
    else
    {
        enqueue(stack->Q2, value); 
    }
    return value;
}

int pop(Stack *stack)
{
    // 스택이 빈 경우
    if (top == -1)
    {
        printf("Empty Stack Exception!! ");
        return -10;
    }
    top--;
    return dequeue(stack);
}

int main()
{
    clock_t start, end;              // 시작시간, 끝나는 시간
    double cpuTimeUsed;              // 총 걸린 시간
    srand((unsigned int)time(NULL)); // 난수 발생을 위해 필요한 것들

    char command; // 명령어 초기화
    int value;
    // 스택 생성 및 초기화하기
    Stack stack;
    initStack(&stack);

    while (command != 'q')
    {
        // 시간재기 시작
        start = clock();
        // 명령어 스캔
        scanf(" %c", &command);
        getchar();

        // q가 나올 경우 - 종료
        if (command == 'q')
        {
            break;
        }
        // S가 나올 경우 - 스택이 비었는지 확인
        else if (command == 'S')
        {
            if (isEmpty())
                printf("Empty (0), ");
            else
                printf("Nonempty (%d), ", top + 1);
        }
        else if (command == 'p')
        {
            while (scanf("%d", &value) == 1)
            {
                push(&stack, value);
            }
            printf("OK (%d), ", top + 1);
        }
        else if (command == 'P')
        {
            pushMillion(&stack);
            printf("OK (%d), ", top + 1);
        }
        else if (command == 'o')
        {
            int popValue = pop(&stack);
            if (popValue == -10)
            {
                printf("(%d), ", top + 1);
            }
            else
            {
                printf("%d (%d), ", popValue, top + 1);
            }
        }
        else if (command == 't')
        {
            printf("%d (%d), ", ttop(&stack), top + 1);
        }
        // 시간재기 끝
        end = clock();
        // 걸린 시간 계산
        cpuTimeUsed = ((double)(end - start) / CLOCKS_PER_SEC);
        // 걸린 시간 출력
        printf("cputime = %.10lfms\n", cpuTimeUsed);
    }

    // 동적 할당 메모리 해제
    free(stack.Q1->elem);
    free(stack.Q2->elem);
    free(stack.Q1);
    free(stack.Q2);

    return 0;
}