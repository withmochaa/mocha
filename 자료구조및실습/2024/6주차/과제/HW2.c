#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define NUM_GROUPS 5
#define NUM_ELEMENTS 4

void addElementToGroup(int elementindex, int groupindex);
void removeElementFromGroup(int elementindex, int groupindex);
void traverseElementsByGroup(int groupindex);
void traverseGroupsByElement(int elementindex);

typedef struct Node {
    int elementindex;
    int groupindex;
    struct Node* nextElement;
    struct Node* nextGroup;
} Node;

Node* groups[NUM_GROUPS] = {NULL};
Node* elements[NUM_ELEMENTS] = {NULL};

Node* createNode(int elementindex, int groupindex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->elementindex = elementindex;
    newNode->groupindex = groupindex;
    newNode->nextElement = NULL;
    newNode->nextGroup = NULL;
    return newNode;
}

void addElementToGroup(int elementindex, int groupindex) {
    Node* newNode = createNode(elementindex, groupindex);
    newNode->nextGroup = groups[groupindex];
    groups[groupindex] = newNode;
    newNode->nextElement = elements[elementindex];
    elements[elementindex] = newNode;
    printf("OK\n");
}

void removeElementFromGroup(int elementindex, int groupindex) {
    Node **ptr, *currentNode = NULL;
    for (ptr = &groups[groupindex]; *ptr != NULL; ptr = &(*ptr)->nextGroup) {
        if ((*ptr)->elementindex == elementindex) {
            currentNode = *ptr;
            *ptr = (*ptr)->nextGroup;
            break;
        }
    }
    if (currentNode == NULL) return;

    for (ptr = &elements[elementindex]; *ptr != NULL; ptr = &(*ptr)->nextElement) {
        if ((*ptr)->groupindex == groupindex) {
            *ptr = (*ptr)->nextElement;
            free(currentNode);
            printf("OK\n");
            return;
        }
    }
}

void traverseElementsByGroup(int groupindex) {
    Node* currentNode = groups[groupindex];
    if (!currentNode) printf("0");

    while (currentNode != NULL) {
        printf("%d ", currentNode->elementindex + 1); 
        currentNode = currentNode->nextGroup;
    }
    printf("\n");
}

void traverseGroupsByElement(int elementindex) {
    Node* currentNode = elements[elementindex];
    if (!currentNode) printf("0");

    while (currentNode != NULL) {
        printf("%c ", currentNode->groupindex + 'A');
        currentNode = currentNode->nextElement;
    }
    printf("\n");
}

int main(void){
    char command;
    int elementNum, elementindex, groupindex;
    char groupName;

    while (scanf(" %c", &command) && command != 'q') {
        switch (command) {
            case 'a':
                scanf("%d %c", &elementNum, &groupName);
                elementindex = elementNum - 1;
                groupindex = groupName - 'A';
                addElementToGroup(elementindex, groupindex);
                break;
            case 'r':
                scanf("%d %c", &elementNum, &groupName);
                elementindex = elementNum - 1;
                groupindex = groupName - 'A';
                removeElementFromGroup(elementindex, groupindex);
                break;
            case 'e':
                scanf(" %c", &groupName);
                groupindex = groupName - 'A';
                traverseElementsByGroup(groupindex);
                break;
            case 'g':
                scanf("%d", &elementNum);
                elementindex = elementNum - 1;
                traverseGroupsByElement(elementindex);
                break;
            case 'q':
                return 0;
        }
    }
}
