#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//NG & NE fix
#define NG 5
#define NE 4

//define function
void add(int e, int g);
void removeNode(int e, int g);
void traverseShareElements(int g);
void traverseShareGroups(int e);
void freeMemory();

//node sturcture define
typedef struct Node {
    int element;
    int group;
    struct Node* nextElement;
    struct Node* nextGroup;
} Node;

//global array define
Node* groups[NG] = {NULL};
Node* elements[NE] = {NULL};


// make new node function
Node* createNode(int e, int g) {

    Node* newNode = (Node*)malloc(sizeof(Node));//memory allocatyion

    newNode->element = e;
    newNode->group = g;

    newNode->nextElement = NULL;// reset pointer
    newNode->nextGroup = NULL;

    return newNode;
}

//add function

void add(int e, int g) {

    Node* newNode = createNode(e, g);

    newNode->nextGroup = groups[g];// insert into subscriber list
    groups[g] = newNode;// insert into coupon list

    newNode->nextElement = elements[e];
    elements[e] = newNode;

    printf("OK\n");//print success
}

//delete function
void removeNode(int e, int g) {

    Node **ptr, *temp = NULL;

    // delete into subscriber list
    for (ptr = &groups[g]; *ptr != NULL; ptr = &(*ptr)->nextGroup) {
        if ((*ptr)->element == e) {
            temp = *ptr;
            *ptr = (*ptr)->nextGroup;
            break;
        }
    }

    if (temp == NULL){
        return; // if no node shut down function
    }

    //delete into coupon list
    for (ptr = &elements[e]; *ptr != NULL; ptr = &(*ptr)->nextElement) {
        if ((*ptr)->group == g) {
            *ptr = (*ptr)->nextElement;
            free(temp);//free memory
            printf("OK\n");

            return;
        }
    }
}

//searching element function
void traverseShareElements(int g) {
    Node* temp = groups[g];

    if (!temp){
        printf("0"); // if no temp print 0
    }

    while (temp != NULL) {
        printf("%d ", temp->element + 1); 
        temp = temp->nextGroup;
    }

    printf("\n");
}

//searching group function
void traverseShareGroups(int e) {
    Node* temp = elements[e];

    if (!temp){
        printf("0");// if no temp print 0
    } 

    while (temp != NULL) {
        printf("%c ", temp->group + 'A'); // print groups nome
        temp = temp->nextElement;
    }
    
    printf("\n");
}

//free memory
void freeMemory() {
    Node *temp, *next;
    int i;

    // free group memory
    for (i = 0; i < NG; ++i) {
        temp = groups[i];
        while (temp != NULL) {
            next = temp->nextGroup;
            free(temp);
            temp = next;
        }
    }

    // free element memory
    for (i = 0; i < NE; ++i) {
        temp = elements[i];
        while (temp != NULL) {
            next = temp->nextElement;
            free(temp);
            temp = next;
        }
    }
}

int main(void){
    char command;
    int e, g;
    char groupName;
    int elementNum;

    while (scanf(" %c", &command) && command != 'q') {// if input is q stop
        switch (command) {
            case 'a':
                scanf("%d %c", &elementNum, &groupName);
                e = elementNum - 1;
                g = groupName - 'A';
                add(e, g);
                break;
            case 'r':
                scanf("%d %c", &elementNum, &groupName);
                e = elementNum - 1;
                g = groupName - 'A';
                removeNode(e, g);
                break;
            case 'e':
                scanf(" %c", &groupName);
                g = groupName - 'A';
                traverseShareElements(g);
                break;
            case 'g':
                scanf("%d", &elementNum);
                e = elementNum - 1;
                traverseShareGroups(e);
                break;
            case 'q':
                freeMemory();
                return 0;
        }
    }
}
