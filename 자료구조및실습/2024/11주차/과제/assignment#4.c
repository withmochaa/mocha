#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000002

typedef struct {
    int *items; // Array for queue items
    int front, rear, size, capacity; // Front, rear, size, and capacity of the queue
} Queue;

// Initialize queue
void initQueue(Queue *q, int capacity) {
    q->capacity = capacity; // Set capacity
    q->front = q->size = 0; // Initialize front and size to 0
    q->rear = capacity - 1; // Set rear to the last index of capacity
    q->items = (int*)malloc(q->capacity * sizeof(int)); // Allocate memory for item array
}

// Check if queue is full
int isFull(Queue *q) { return (q->size == q->capacity); }

// Check if queue is empty
int isEmpty(Queue *q) { return (q->size == 0); }

// Add element to queue
void enqueue(Queue *q, int item) {
    if (isFull(q)) return; // If full, do not add
    q->rear = (q->rear + 1) % q->capacity; // Increment rear index cyclically
    q->items[q->rear] = item; // Add element
    q->size = q->size + 1; // Increase size by 1
}

// Remove element from queue
int dequeue(Queue *q) {
    if (isEmpty(q)) return -1; // If empty, return -1
    int item = q->items[q->front]; // Store front element
    q->front = (q->front + 1) % q->capacity; // Increment front index cyclically
    q->size = q->size - 1; // Decrease size by 1
    return item; // Return removed element
}

// Return front element of queue
int front(Queue *q) {
    if (isEmpty(q)) return -1; // If empty, return -1
    return q->items[q->front]; // Return front element
}

// Return rear element of queue
int rear(Queue *q) {
    if (isEmpty(q)) return -1; // If empty, return -1
    return q->items[q->rear]; // Return rear element
}

typedef struct {
    Queue q1, q2; // Use two queues
} Stack;

// Initialize stack
void initStack(Stack *s, int capacity) {
    initQueue(&s->q1, capacity); // Initialize first queue
    initQueue(&s->q2, capacity); // Initialize second queue
}

// Add element to stack
void push(Stack *s, int item) {
    enqueue(&s->q1, item); // Add element to first queue
}

int pop(Stack *s) {
    if(isEmpty(&s->q1)) return -1; // If first queue is empty, return -1
    
    while(s->q1.size != 1) {
        enqueue(&s->q2, dequeue(&s->q1)); // Move elements from first queue to second queue
    }
    
    int popped = dequeue(&s->q1); // Remove and return last element
    
    Queue temp = s->q1; // Swap queues
    s->q1 = s->q2;
    s->q2 = temp;
    
    return popped;
}

// Check if stack is empty
int isEmptyStack(Stack *s) {
    return isEmpty(&s->q1); // Check if first queue is empty
}

// Return top element of stack
int top(Stack *s) {
    if(isEmpty(&s->q1)) return -1; // If first queue is empty, return -1
    
    while(s->q1.size != 1) {
        enqueue(&s->q2, dequeue(&s->q1)); // Move elements from first queue to second queue
    }
    
    int top = front(&s->q1); // Check last element
    enqueue(&s->q2, dequeue(&s->q1)); // Move last element to second queue
    
    Queue temp = s->q1; // Swap queues
    s->q1 = s->q2;
    s->q2 = temp;
    
    return top;
}

void pushMillion(Stack *s) {
    srand(time(0)); // Initialize random numbers
    for(int i = 0; i < MAX; i++) {
        push(s, (rand() % (99 - 10 + 1)) + 10); // Add random numbers between 10 and 99
    }
}




int main(void) {
    Stack s;
    initStack(&s, MAX);
    char command;
    int num;
    clock_t start, end;
    double cpu_time_used;

    while(1) {
        scanf(" %c", &command);

        switch(command) {
            case 'S':
                start = clock();
                if(isEmptyStack(&s)) printf("Empty (%d), ", s.q1.size);
                else printf("Nonempty (%d), ", s.q1.size);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("cputime = %.10lf\n", cpu_time_used);
                break;
            case 't':
                start = clock();
                num = top(&s);
                if(num == -1) printf("Empty Stack Exception!! (%d), ", s.q1.size);
                else printf("%d (%d), ", num, s.q1.size);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("cputime = %.10lf\n", cpu_time_used);
                break;
            case 'p':
                start = clock();
                while(scanf("%d", &num) == 1) {
                    push(&s, num);
                }
                printf("OK (%d), ", s.q1.size);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("cputime = %.10lf\n", cpu_time_used);
                break;
            case 'P':
                start = clock();
                pushMillion(&s);
                printf("OK (%d), ", s.q1.size);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("cputime = %.10lf\n", cpu_time_used);
                break;
            case 'o':
                start = clock();
                num = pop(&s);
                if(num == -1) printf("Empty Stack Exception!! (%d), ", s.q1.size);
                else printf("%d (%d), ", num, s.q1.size);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("cputime = %.10lf\n", cpu_time_used);
                break;
            case 'q':
                return 0;
            default:
                printf("Invalid command\n");
                break;
        }
    }

    return 0;
}





