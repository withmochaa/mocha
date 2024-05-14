#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef struct Node {
	int elem;
	struct Node* next;
	struct Node* prev;
}Node;

typedef struct Deque {
	Node *front;
	Node *rear;
}Deque;
//define fnc
void add_front(Deque *d, int e);
void add_rear(Deque *d, int e);
int delete_front(Deque *d);
int delete_rear(Deque *d);
void print(Deque *d);
void free_deque(Deque *d);

// Adds an element at the front of the deque
void add_front(Deque *d, int e){

	Node *p;

	p = (Node*)malloc(sizeof(Node));
	p->elem = e;
	p->prev = NULL;

	if (d->front == NULL) {
		p->next = NULL;
		d->front = p;
		d->rear = p;
	}
	else {
		p->next = d->front;
		(d->front)->prev = p;
		d->front = p;
	}
}

// Adds an element at the rear of the deque
void add_rear(Deque *d, int e) {

	Node *p;

	p = (Node*)malloc(sizeof(Node));
	p->elem = e;
	p->next = NULL;

	if (d->front == NULL) {
		p->prev = NULL;
		d->front = p;
		d->rear = p;
	}
	else {
		(d->rear)->next = p;
		p->prev = d->rear;
		d->rear = p;
	}
}

// Deletes an element from the front of the deque
int delete_front(Deque *d) {

	int e;
	Node *p;

	if (d->front == NULL) {
		printf("underflow");
		return 0;
	}
	else {
		p = d->front;
		e = (d->front)->elem;
		if ((d->front)->next == NULL) {
			d->front = NULL;
			d->rear = NULL;
		}
		else {
			d->front = (d->front)->next;
			(d->front)->prev = NULL;
		}
		free(p);
		return e;
	}
}

// Deletes an element from the rear of the deque
int delete_rear(Deque *d) {

	int e;
	Node *p;

	if (d->front == NULL) {
		printf("underflow");
		return 0;
	}
	else {
		p = d->rear;
		e = (d->rear)->elem;
		if ((d->rear)->prev == NULL) {
			d->front = NULL;
			d->rear = NULL;
		}
		else {
			d->rear = (d->rear)->prev;
			(d->rear)->next = NULL;
		}
		free(p);
		return e;
	}
}

// Prints the elements of the deque
void print(Deque *d) {

	Node *p;
	p = d->front;

	while (p) {
		printf(" %d", p->elem);
		p = p->next;
	}
	printf("\n");
}

// Frees the memory allocated to the deque
void free_deque(Deque *d) {

	Node *current = d->front;

	while(current != NULL) {
		Node *temp = current;
		current = current->next;
		free(temp);
	}
}

int main(void) {

	int i, n, e, p;
	char ar[4]; 
	Deque *d;

	d = (Deque*)malloc(sizeof(Deque));
	d->front = NULL;
	d->rear = NULL;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", ar);
		if (strcmp("AF", ar) == 0) {
			scanf("%d", &e);
			add_front(d, e);
		}
		else if (strcmp("AR", ar) == 0) {
			scanf("%d", &e);
			add_rear(d, e);
		}
		else if (strcmp("DF", ar) == 0) {
			p = delete_front(d);
			if (p == 0) {
				free_deque(d);
				free(d);
				return 0;
			}
		}
		else if (strcmp("DR", ar) == 0) {
			p = delete_rear(d);
			if (p == 0) {
				free_deque(d);
				free(d); 
				return 0;
			}
		}
		else {
			print(d);
		}
	}

	// Free memory 
	free_deque(d);
	free(d);
	return 0;
}
