#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define EMPTY_QUEUE -1

typedef struct {
    int front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue) { return (queue->size == queue->capacity); }

int isEmpty(Queue* queue) { return (queue->size == 0); }

void enqueue(Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) return EMPTY_QUEUE;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(Queue* queue) {
    if (isEmpty(queue)) return EMPTY_QUEUE;
    return queue->array[queue->front];
}

int rear(Queue* queue) {
    if (isEmpty(queue)) return EMPTY_QUEUE;
    return queue->array[queue->rear];
}

// 스택을 구현하기 위해 두 개의 큐를 사용합니다.
typedef struct {
    Queue* q1;
    Queue* q2;
    int size;
} Stack;

void initStack(Stack* stack, int capacity) {
    stack->q1 = createQueue(capacity);
    stack->q2 = createQueue(capacity);
    stack->size = 0;
}

void swapQueues(Queue** q1, Queue** q2) {
    Queue* temp = *q1;
    *q1 = *q2;
    *q2 = temp;
}

void push(Stack* stack, int item) {
    enqueue(stack->q1, item);
    stack->size++;
}

int pop(Stack* stack) {
    if (isEmpty(stack->q1)) return EMPTY_QUEUE;

    while (stack->q1->size != 1) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    int popped = dequeue(stack->q1);
    stack->size--;

    swapQueues(&stack->q1, &stack->q2);
    return popped;
}

int top(Stack* stack) {
    if (isEmpty(stack->q1)) return EMPTY_QUEUE;

    while (stack->q1->size != 1) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    int top = front(stack->q1);

    enqueue(stack->q2, dequeue(stack->q1));
    swapQueues(&stack->q1, &stack->q2);

    return top;
}

int main() {
    // 스택 초기화
    Stack s;
    initStack(&s, MAX);
    char command;
    int item;
    clock_t start, end;

    while (1) {
        start = clock();
        scanf(" %c", &command);
        switch (command) {
            case 'S':
                printf("%s (%d)", (isEmpty(s.q1) ? "Empty" : "Nonempty"), s.size);
                break;
            case 't':
                item = top(&s);
                if (item != EMPTY_QUEUE) {
                    printf("%d (%d)", item, s.size);
                }
                break;
            case 'P':
    // 난수 생성 로직을 추가
                for (int i = 0; i < 1000000; ++i) {
                    push(&s, rand() % 1000000); // 0부터 999999 사이의 난수 생성 및 푸시
                }
                printf("OK (%d)", s.size);
                break;
            case 'p':
                while (1) {
                    char line[1024];
                    if (!fgets(line, sizeof(line), stdin)) break;
                    char* token = strtok(line, " ");
                    while (token != NULL) {
                        int num;
                        if (sscanf(token, "%d", &num) == 1) {
                            push(&s, num);
                        } 
                        else {
                            break; // 숫자가 아닌 다른 것이 입력되면 중지
                        }
                        token = strtok(NULL, " ");
                        }
                        printf("OK (%d)", s.size);
                        break; // 한 번 처리 후 break로 루프 탈출
            }
                break;
            case 'o':
                item = pop(&s);
                if (item == EMPTY_QUEUE) {
                    printf("Empty Stack Exception!! (%d)", s.size);
                } else {
                    printf("%d (%d)", item, s.size);
                }
                break;
            case 'q':
                free(s.q1->array);
                free(s.q2->array);
                free(s.q1);
                free(s.q2);
                return 0;
        }
        end = clock();
        double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000; // 밀리초 단위로 변경
        printf(", cputime = %.8f\n", cpu_time_used);
    }
    return 0;
}