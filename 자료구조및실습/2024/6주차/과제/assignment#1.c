#include <stdio.h>
#include <stdlib.h>

#define NG 5
#define NE 4

typedef struct Node {
    int element;
    int group;
    struct Node* nextElement;
    struct Node* nextGroup;
} Node;

Node* groups[NG] = {NULL};
Node* elements[NE] = {NULL};

Node* createNode(int e, int g) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->element = e;
    newNode->group = g;
    newNode->nextElement = NULL;
    newNode->nextGroup = NULL;
    return newNode;
}

void add(int e, int g) {
    Node* newNode = createNode(e, g);
    // 가입자 목록에 삽입
    newNode->nextGroup = groups[g];
    groups[g] = newNode;
    // 쿠폰 목록에 삽입
    newNode->nextElement = elements[e];
    elements[e] = newNode;

    printf("OK\n");
}

void removeNode(int e, int g) {
    Node **ptr, *temp = NULL;

    // 가입자 목록에서 삭제
    for (ptr = &groups[g]; *ptr != NULL; ptr = &(*ptr)->nextGroup) {
        if ((*ptr)->element == e) {
            temp = *ptr;
            *ptr = (*ptr)->nextGroup;
            break;
        }
    }

    if (temp == NULL) return; // 해당하는 노드가 없는 경우 바로 리턴

    // 쿠폰 목록에서 삭제
    for (ptr = &elements[e]; *ptr != NULL; ptr = &(*ptr)->nextElement) {
        if ((*ptr)->group == g) {
            *ptr = (*ptr)->nextElement;
            free(temp);
            printf("OK\n");
            return;
        }
    }
}

void traverseShareElements(int g) {
    Node* temp = groups[g];
    if (!temp) printf("0"); // 요소가 없을 경우 "0" 출력
    while (temp != NULL) {
        printf("%d ", temp->element + 1);
        temp = temp->nextGroup;
    }
    printf("\n");
}

void traverseShareGroups(int e) {
    Node* temp = elements[e];
    if (!temp) printf("0"); // 요소가 없을 경우 "0" 출력
    while (temp != NULL) {
        printf("%c ", temp->group + 'A');
        temp = temp->nextElement;
    }
    printf("\n");
}

int main() {
    char command;
    int e, g;
    char groupName;
    int elementNum;

    while (scanf(" %c", &command) && command != 'q') {
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
        }
    }
    return 0;
}
