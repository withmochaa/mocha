#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000002 // 스택의 최대 크기
#define TRUE 1
#define FALSE 0

// 큐 구조체 정의
typedef struct {
    int front;
    int rear;
    int data[MAX_SIZE];
} Queue;

// 큐 초기화 함수
void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

// 큐가 비어있는지 확인하는 함수
int isEmptyQueue(Queue *q) {
    return q->front == q->rear;
}

// 큐에 원소를 삽입하는 함수
void enqueue(Queue *q, int element) {
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = element;
}

// 큐에서 원소를 제거하고 반환하는 함수
int dequeue(Queue *q) {
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

// 스택 구현을 위한 큐 두 개 선언
Queue q1, q2;

// 스택이 비어있는지 확인하는 함수
int isEmpty() {
    return isEmptyQueue(&q1);
}

// 스택의 top에 있는 원소를 반환하는 함수
int top() {
    if (isEmpty()) {
        printf("Empty Stack Exception!! ");
        return -1;
    }
    return q1.data[q1.rear];
}

// 스택에 원소를 삽입하는 함수
void push(int element) {
    enqueue(&q2, element);
    while (!isEmptyQueue(&q1)) {
        enqueue(&q2, dequeue(&q1));
    }
    Queue temp = q1;
    q1 = q2;
    q2 = temp;
}

// 스택에서 원소를 제거하는 함수
int pop() {
    if (isEmpty()) {
        printf("Empty Stack Exception!! ");
        return -1;
    }
    return dequeue(&q1);
}

// 스택의 크기를 반환하는 함수
int size() {
    return (q1.rear - q1.front + MAX_SIZE) % MAX_SIZE;
}

// 메인 함수
int main() {
    char command;
    int n;
    srand(time(NULL)); // 난수 초기화

    initQueue(&q1);
    initQueue(&q2);

    while (1) {
        scanf(" %c", &command);

        switch (command) {
            case 'S':
                printf(isEmpty() ? "Empty (%d), " : "Nonempty (%d), ", size());
                break;
            case 't':
                printf("%d (%d), ", top(), size());
                break;
            case 'p':
                while (scanf("%d", &n) == 1) {
                    push(n);
                }
                printf("OK (%d), ", size());
                break;
            case 'P':
                for (int i = 0; i < 1000000; ++i) {
                    push(rand() % 90 + 10);
                }
                printf("OK (%d), ", size());
                break;
            case 'o':
                printf("%d (%d), ", pop(), size());
                break;
            case 'q':
                return 0;
        }
    }
}





