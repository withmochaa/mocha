#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {

    int key;
    struct Node* lChild;
    struct Node* rChild;
    struct Node* parent;

} Node;

// 특정 키를 삭제하는 함수
int TreeDelete(int k);

// 트리에서 가장 작은 노드를 찾는 함수
Node* TreeMinimum(Node* x);

// 트리를 출력하는 함수
void Print(Node* p);

// 새로운 노드를 삽입하는 함수
void TreeInsert(int k);

// 주어진 키를 검색하는 함수
Node* TreeSearch(Node* p, int k);

// 두 노드를 교체하는 함수
void Transplant(Node* T, Node* u, Node* v);

Node* root;

int main() {
    Node* p;
    char ch;
    int k, a, plag = 0;

    root = (Node*)malloc(sizeof(Node));
    root->parent = NULL;
    root->lChild = NULL;
    root->rChild = NULL;

    while (1) {
        scanf("%c", &ch);

        if (ch == 'i') {
            scanf("%d", &k);
            if (plag == 0) {
                root->key = k;
                plag = 1;
            }
            else {
                TreeInsert(k);
            }
        }
        else if (ch == 'd') {
            scanf("%d", &k);
            a = TreeDelete(k);
            if (a == -1) {
                printf("X\n");
            }
            else {
                printf("%d\n", a);
            }
        }
        else if (ch == 's') {
            scanf("%d", &k);
            p = TreeSearch(root, k);
            if (p == NULL) {
                printf("X\n");
            }
            else {
                printf("%d\n", p->key);
            }
        }
        else if (ch == 'p') {
            Print(root);
            printf("\n");
        }
        else {
            break;
        }
        getchar();
    }

    return 0;
}

// 트리에서 특정 키를 검색하는 함수
Node* TreeSearch(Node* p, int k) {
    if (p == NULL || k == p->key) {
        return p;
    }
    if (k < p->key) {
        return TreeSearch(p->lChild, k);
    }
    return TreeSearch(p->rChild, k);
}

// 새로운 노드를 삽입하는 함수
void TreeInsert(int k) {
    Node* new, *x, *y;

    new = (Node*)malloc(sizeof(Node));
    new->key = k;
    new->rChild = NULL;
    new->lChild = NULL;
    new->parent = NULL;

    x = root;
    y = NULL;
    while (x != NULL) {
        y = x;
        if (new->key < x->key) {
            x = x->lChild;
        }
        else {
            x = x->rChild;
        }
    }
    new->parent = y;
    if (y == NULL) {
        root = new;
    }
    else if (new->key < y->key) {
        y->lChild = new;
    }
    else {
        y->rChild = new;
    }
}

// 트리를 중위 순회하여 출력하는 함수
void Print(Node* p) {
    if (p != NULL) {
        printf(" %d", p->key);
        Print(p->lChild);
        Print(p->rChild);
    }
}

// 트리에서 가장 작은 노드를 찾는 함수
Node* TreeMinimum(Node* x) {
    while (x->lChild != NULL) {
        x = x->lChild;
    }
    return x;
}

// 특정 키를 삭제하는 함수
int TreeDelete(int k) {
    Node* z = TreeSearch(root, k);
    Node* y = NULL;
    int e;

    if (z == NULL) {
        return -1;
    }
    e = z->key;

    if (z->lChild == NULL) {
        Transplant(root, z, z->rChild);
    }
    else if (z->rChild == NULL) {
        Transplant(root, z, z->lChild);
    }
    else {
        y = TreeMinimum(z->rChild);
        if (y->parent != z) {
            Transplant(root, y, y->rChild);
            y->rChild = z->rChild;
            y->rChild->parent = y;
        }
        Transplant(root, z, y);
        y->lChild = z->lChild;
        y->lChild->parent = y;
    }
    return e;
}

//
