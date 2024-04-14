#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {

    int key, height;
    struct Node* lChild;
    struct Node* rChild;
    struct Node* parent;

} Node;

struct Node *root;

// 노드가 내부 노드인지 검사
int isInternal(Node *T);

// 노드가 외부 노드인지 검사
int isExternal(Node *T);

// 외부 노드를 확장
void expandExternal(Node *w);

// 주어진 키를 검색하는 함수
Node* treeSearch(Node *w, int k);

// 높이를 업데이트하고 균형을 확인하는 함수
int updateHeight(Node *w);

// 노드가 균형인지 검사
int isBalanced(Node *w);

// 노드 재구성
Node* restructure(Node *x, Node *y, Node *z);

// 삽입 후 검색 및 수정 함수
void searchAndFixAfterInsertion(Node *w);

// 새로운 항목을 삽입하는 함수
void insertItem(Node *w, int k);

// 트리를 출력하는 함수
void Print(Node *w);

int main() {
    char ch;
    int k, value;

    root = (struct Node*)malloc(sizeof(struct Node));
    root->parent = NULL;
    root->lChild = NULL;
    root->rChild = NULL;

    while (1) {
        scanf("%c", &ch);

        if (ch == 'i') {
            scanf("%d", &k);
            insertItem(root, k);
        }
        else if (ch == 's') {
            scanf("%d", &k);
            if (treeSearch(root, k)->key != k) {
                printf("X\n");
            }
            else {
                printf("%d\n", treeSearch(root, k)->key);
            }
        }
        else if (ch == 'p') {
            Print(root);
            printf("\n");
        }
        else if (ch == 'q') {
            break;
        }
        getchar();
    }
    return 0;
}

// 내부 노드 여부 검사
int isInternal(Node *T) {
    if (T->lChild != NULL || T->rChild != NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// 외부 노드 여부 검사
int isExternal(Node *T) {
    if (T->lChild == NULL && T->rChild == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

// 외부 노드 확장
void expandExternal(Node *w) {
    Node *l = (Node*)malloc(sizeof(Node));
    Node *r = (Node*)malloc(sizeof(Node));

    l->lChild = NULL;
    l->rChild = NULL;
    l->parent = w;
    l->height = 0;

    r->lChild = NULL;
    r->rChild = NULL;
    r->parent = w;
    r->height = 0;

    w->lChild = l;
    w->rChild = r;
    w->height = 1;
}

// 주어진 키를 검색하는 함수
Node* treeSearch(Node *T, int k) {
    if (isExternal(T)) {
        return T;
    }

    if (k == T->key) {
        return T;
    }
    else if (k < T->key) {
        return treeSearch(T->lChild, k);
    }
    else {
        return treeSearch(T->rChild, k);
    }
}

// 새로운 항목을 삽입하는 함수
void insertItem(Node *T, int k) {
    Node *w = treeSearch(T, k);

    if (isInternal(w)) {
        return;
    }
    else {
        w->key = k;
        expandExternal(w);
        searchAndFixAfterInsertion(w);
    }
}

// 삽입 후 검색 및 수정 함수
void searchAndFixAfterInsertion(Node *w) {
    Node *x, *y, *z;

    w->lChild->height = 0;
    w->rChild->height = 0;
    w->height = 1;

    if (w->parent == NULL) {
        return;
    }

    z = w->parent;

    while (updateHeight(z) && isBalanced(z)) {
        if (z->parent == NULL) {
            return;
        }
        z = z->parent;
    }

    if (isBalanced(z)) {
        return;
    }

    if (z->lChild->height > z->rChild->height) {
        y = z->lChild;
    }
    else {
        y = z->rChild;
    }

    if (y->lChild->height > y->rChild->height) {
        x = y->lChild;
    }
    else {
        x = y->rChild;
    }

    restructure(x, y, z);
}

// 높이를 업데이트하고 균형을 확인하는 함수
int updateHeight(Node *w) {
    int h;

    if (w->lChild->height > w->rChild->height) {
        h = w->lChild->height + 1;
    }
    else {
        h = w->rChild->height + 1;
    }

    if (h != w->height) {
        w->height = h;
        return 1;
    }
    else {
        return 0;
    }
}

// 노드가 균형인지 검사
int isBalanced(Node *w) {
    int lh = w->lChild->height;
    int rh = w->rChild->height;
    if ((-1 <= lh - rh) && (lh - rh <= 1)) {
        return 1;
    }
    else {
        return 0;
    }
}

// 노드 재구성
Node* restructure(Node *x, Node *y, Node *z) {
    Node *a, *b, *c, *T0, *T1, *T2, *T3;

    if ((z->key < y->key) && (y->key < x->key)) {
        a = z;
        b = y;
        c = x;
        T0 = a->lChild;
        T1 = b->lChild;
        T2 = c->lChild;
        T3 = c->rChild;
    }
    else if ((x->key < y->key) && (y->key < z->key)) {
        a = x;
        b = y;
        c = z;
        T0 = a->lChild;
        T1 = a->rChild;
        T2 = b->rChild;
        T3 = c->rChild;
    }
    else if ((z->key < x->key) && (x->key < y->key)) {
        a = z;
        b = x;
        c = y;
        T0 = a->lChild;
        T1 = b->lChild;
        T2 = b->rChild;
        T3 = c->rChild;
    }
    else {
        a = y;
        b = x;
        c = z;
        T0 = a->lChild;
        T1 = b->lChild;
        T2 = b->rChild;
        T3 = c->rChild;
    }

    if (z->parent == NULL) {
        root = b;
        b->parent = NULL;
    }
    else if (z->parent->lChild == z) {
        z->parent->lChild = b;
        b->parent = z->parent;
    }
    else if (z->parent->rChild == z) {
        z->parent->rChild = b;
        b->parent = z->parent;
    }

    a->lChild = T0;
    T0->parent = a;
    a->rChild = T1;
    T1->parent = a;
    updateHeight(a);

    c->lChild = T2;
    T2->parent = c;
    c->rChild = T3;
    T3->parent = c;
    updateHeight(c);

    b->lChild = a;
    a->parent = b;
    b->rChild = c;
    c->parent = b;
    updateHeight(b);

    return b;
}

// 트리를 중위 순회하여 출력하는 함수
void Print(Node *w) {
    if (isExternal(w)) {
        return;
    }
    else {
        printf(" %d", w->key);
        Print(w->lChild);
        Print(w->rChild);
    }
}
