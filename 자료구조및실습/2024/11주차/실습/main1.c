#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// Define Queue structure
typedef struct Queue {
	int *q;     // Pointer  queue array
	int N;      // Size of the queue
	int front, rear; // Pointers to the front and rear of the queue
}Queue;

// Function declarations
int isEmpty(Queue *Q);
int isFull(Queue *Q);
int enqueue(Queue *Q, int e);
int dequeue(Queue *Q);
void print(Queue *Q);

// Checks if the queue is empty
int isEmpty(Queue *Q) {
	if ((Q->rear) % Q->N == Q->front) {
		return 1;
	}
	return 0;
}

// Checks if the queue is full
int isFull(Queue *Q) {
	if ((Q->rear + 1) % Q->N == Q->front) {
		return 1;
	}
	return 0;
}

// Inserts an element to the rear of the queue
int enqueue(Queue *Q, int e) {
	if (isFull(Q) == 1) {
		printf("overflow");
		print(Q);
		return 0;
	}
	else {
		Q->rear = (Q->rear + 1) % Q->N;
		Q->q[Q->rear] = e;
		return 1;
	}
}

// Removes an element from the front of the queue
int dequeue(Queue *Q) {
	int e;
	if (isEmpty(Q) == 1) {
		printf("underflow\n");
		return 0;
	}
	else {
		e = Q->q[Q->front + 1];
		Q->q[Q->front + 1] = 0;
		Q->front = (Q->front + 1) % Q->N;
		return e;
	}
}

// Prints the elements in the queue
void print(Queue *Q) {
	int i;
	for (i = 0; i < Q->N; i++) {
		printf(" %d", Q->q[i]);
	}
	printf("\n");
}


int main(void) {
    Queue *Q;
    int n, i, e, a;
    char ch;

   
    Q = (Queue*)malloc(sizeof(Queue));
    Q->front = 0;
    Q->rear = 0;

   
    scanf("%d", &Q->N);

    
    Q->q = (int *)malloc(sizeof(int)*Q->N);

   
    scanf("%d", &n);

   
    for (i = 0; i < Q->N; i++) {
        Q->q[i] = 0;
    }

    // Execute operations
    for (i = 0; i < n; i++) {
        getchar();
        scanf("%c", &ch);
        if (ch == 'I') {
            scanf("%d", &e);
            a = enqueue(Q, e);
            if (a == 0) {
                free(Q->q);
                free(Q);
                return 0;
            }
        }
        else if (ch == 'D') {
            a = dequeue(Q);
            if (a == 0) {
                free(Q->q);
                free(Q);
                return 0;
            }
        }
        else {
            print(Q);
        }
    }

   
    free(Q->q);
    free(Q);

    return 0;
}


