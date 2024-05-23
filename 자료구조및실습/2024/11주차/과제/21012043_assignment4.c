#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000002

typedef struct {
    int *items;
    int front, rear, capacity;
} Queue;

// Initialize queue
void initQueue(Queue *q, int capacity) {
    q->capacity = capacity;
    q->front = q->rear = -1;
    q->items = (int*)malloc(q->capacity * sizeof(int));
}

// Check if queue is full
int isFull(Queue *q) {
    return ((q->rear + 1) % q->capacity == q->front);
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Add element to queue
void enqueue(Queue *q, int item) {
    if (isFull(q)) return;
    if (isEmpty(q)) q->front = 0;
    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = item;
}

// Remove element from queue
int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    int item = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->capacity;
    }
    return item;
}
// Stack structure
typedef struct {
    Queue q1, q2;
    int topElement; 
} Stack; 

// Initialize stack
void initStack(Stack *s, int capacity) {
    initQueue(&s->q1, capacity);
    initQueue(&s->q2, capacity);
    s->topElement = -1; // 초기화
}

// Add element to stack
void push(Stack *s, int item) {
    enqueue(&s->q1, item);
    s->topElement = item; // 스택의 최상위 요소를 업데이트합니다.
}

int pop(Stack *s) {
    if (isEmpty(&s->q1)) return -1;

    while (s->q1.front != s->q1.rear) {
        // 스택의 최상위 요소를 업데이트합니다.
        s->topElement = s->q1.items[(s->q1.front + 1) % s->q1.capacity];
        enqueue(&s->q2, dequeue(&s->q1));
    }

    int popped = dequeue(&s->q1);

    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    if (isEmpty(&s->q1)) {
        s->topElement = -1; 
    }

    return popped;
}

// Return top element of stack
int top(Stack *s) {
    return s->topElement; 
}

// Check if stack is empty
int isEmptyStack(Stack *s) {
    return isEmpty(&s->q1);
}

// Return the size of the stack
int stackSize(Stack *s) {
    if (isEmptyStack(s)) return 0;
    if (s->q1.rear >= s->q1.front) {
        return s->q1.rear - s->q1.front + 1;
    } else {
        return s->q1.capacity - s->q1.front + s->q1.rear + 1;
    }
}

void pushMillion(Stack *s) {
    srand(time(0));
    for (int i = 0; i < MAX; i++) {
        push(s, (rand() % (99 - 10 + 1)) + 10);
    }
}



int main(void) {
    Stack s;
    initStack(&s, MAX);
    char command;
    int num;
    clock_t start, end;
    double cpu_time_used;

    while (1) {
        scanf(" %c", &command);

        switch (command) {
            case 'S':
                start = clock();
                if (isEmptyStack(&s)) printf("Empty (%d), ", stackSize(&s));
                else printf("Nonempty (%d), ", stackSize(&s));
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("cputime = %.10lf\n", cpu_time_used);
                break;
            case 't':
                start = clock();
                num = top(&s);
                if (num == -1) printf("Empty Stack Exception!! (%d), ", stackSize(&s));
                else printf("%d (%d), ", num, stackSize(&s));
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("cputime = %.10lf\n", cpu_time_used);
                break;
            case 'p':
                start = clock();
                while (scanf("%d", &num) == 1) {
                    push(&s, num);
                }
                printf("OK (%d), ", stackSize(&s));
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("cputime = %.10lf\n", cpu_time_used);
                break;
            case 'P':
                start = clock();
                pushMillion(&s);
                printf("OK (%d), ", stackSize(&s));
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("cputime = %.10lf\n", cpu_time_used);
                break;
            case 'o':
                start = clock();
                num = pop(&s);
                if (num == -1) printf("Empty Stack Exception!! (%d), ", stackSize(&s));
                else printf("%d (%d), ", num, stackSize(&s));
                end = clock();
                cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
                printf("cputime = %.10lf\n", cpu_time_used);
                break;
            case 'q':
                return 0;

        }
    }

    return 0;
}