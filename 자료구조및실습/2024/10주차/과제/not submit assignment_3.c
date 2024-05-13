#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000010// max stack size
#define RAND_RANGE 8999
#define RAND_MIN 1000

int *stack; 
int *minStack;//for minimum track
int top = -1;// random minimum 

// for add element to stack
int push(int element) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = element;
        if (top == 0 || element < minStack[top-1]) {
            minStack[top] = element;
        } 
        else {
            minStack[top] = minStack[top-1];
        }
        return 1; 
    } 
    else {
        return 0; 
    }
}

// add 1000000 element to stack
void pushMillion() {

    int toAdd = MAX_SIZE - (top + 1); 
    toAdd = toAdd > 1000000 ? 1000000 : toAdd; 

    for (int i = 0; i < toAdd; ++i) {
        int randNum = RAND_MIN + rand() % (RAND_RANGE + 1);
        stack[++top] = randNum;
        if (top == 0 || randNum < minStack[top-1]) {
            minStack[top] = randNum;
        } 
        else {
            minStack[top] = minStack[top-1];
        }
    }
}

// remove top of stack element and return
int pop() {
    if (top >= 0) {
        return stack[top--];
    } 
    else {
        return -1; 
    }
}

//remove 1000000 stack elements
void popMillion() {
    if (top < 0) return;

    top -= 1000000;
    if (top < -1) top = -1;
}

//find minimum in stack
int findMin() {
    if (top >= 0) {
        return minStack[top];
    } 
    else {
        return RAND_MIN + RAND_RANGE; 
    }
}


int main(void) {

    stack = (int *)malloc(MAX_SIZE * sizeof(int)); 
    minStack = (int *)malloc(MAX_SIZE * sizeof(int));//for find minimum
    if (stack == NULL || minStack == NULL) {
        printf("Memory allocate failed\n");
        return -1;
    }

    char command;
    int element, result;
    clock_t start, end;
    double cpuTimeUsed;

    srand(time(NULL)); 

    while (scanf(" %c", &command) != EOF) {
        start = clock();// start point
        switch (command) {
            case 'p':
                scanf("%d", &element);
                if (push(element)) {
                    printf("push %d (%d), ", element, top + 1);
                } else {
                    printf("Stack is already full.\n");
                }
                break;
            case 'P':
                pushMillion();
                printf("pushMillion (%d), ", top + 1); 
                break;
            case 'o':
                result = pop();
                if (result != -1) {
                    printf("pop %d (%d), ", result, top + 1);
                }
                break;
            case 'O':
                popMillion();
                printf("popMillion (%d), ", top + 1);
                break;
            case 'f':
                printf("min %d (%d), ", findMin(), top + 1);
                break;
            case 'q':
                free(stack);
                free(minStack);
                return 0; 
        }
        end = clock();//end point
        cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("cputime = %.12f\n", cpuTimeUsed);
    }
    return 0;
}