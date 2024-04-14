#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable : 4996) // Visual Studio에서 경고 4996을 무시합니다.

typedef struct Node {
    int key;
    struct Node* lChild;
    struct Node* rChild;
    struct Node* parent;
} Node;

int TreeDelete(int k);
Node* TreeMinimum(Node* x);
void Print(Node* p);
void TreeInsert(int k);
Node* TreeSearch(Node* p, int k);
void Transplant(Node* T, Node* u, Node* v);

Node* root;

int main() {

    Node* p;
    char ch;
    int k, a, plag = 0;

    // 초기화: 루트 노드를 생성하고 트리의 루트를 가리키도록 설정합니다.
    root = (Node*)malloc(sizeof(Node));
    root->parent = NULL;
    root->lChild = NULL;
    root->rChild = NULL;

    while (1) {
        scanf("%c", &ch);

        if (ch == 'i') {
            scanf("%d", &k);
            if (plag == 0) {
                root->key = k; // 루트 노드의 값을 초기화합니다.
                plag = 1;
            }
            else {
                TreeInsert(k); // 새로운 노드를 삽입합니다.
            }
        }
        else if (ch == 'd') {
            scanf("%d", &k);
            a = TreeDelete(k); // 노드를 삭제하고 삭제한 노드의 값을 반환합니다.
            if (a == -1) {
                printf("X\n");
            }
            else {
                printf("%d\n", a);
            }
        }
        else if (ch == 's') {
            scanf("%d", &k);
            p = TreeSearch(root, k); // 값을 검색하고 해당 노드를 반환합니다.
            if (p == NULL) {
                printf("X\n");
            }
            else {
                printf("%d\n", p->key);
            }
        }
        else if (ch == 'p') {
            Print(root); // 전위 순회로 트리를 출력합니다.
            printf("\n");
        }
        else {
            break; // 입력이 'i', 'd', 's', 'p'가 아니면 반복문 종료합니다.
        }
        getchar(); // 입력 버퍼를 비웁니다.
    }

    return 0;
}

// 주어진 트리에서 특정 키를 검색하는 함수
Node* TreeSearch(Node* p, int k) {
    if (p == NULL || k == p->key) {
        return p;
    }
    if (k < p->key) {
        return TreeSearch(p->lChild, k);
    }
    return TreeSearch(p->rChild, k);
}

// 주어진 트리에 새로운 노드를 삽입하는 함수
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

// 주어진 트리를 전위 순회로 출력하는 함수
void Print(Node* p) {
    if (p != NULL) {
        printf(" %d", p->key);
        Print(p->lChild);
        Print(p->rChild);
    }
}

// 주어진 노드에서 최소값을 찾는 함수
Node* TreeMinimum(Node* x) {
    while (x->lChild != NULL) {
        x = x->lChild;
    }
    return x;
}

// 주어진 트리에서 노드를 삭제하는 함수
int TreeDelete(int k) {
    Node* z = TreeSearch(root, k); // 삭제할 노드를 찾습니다.
    Node* y = NULL;
    int e;

    if (z == NULL) {
        return -1; // 삭제할 노드가 없을 경우 -1을 반환합니다.
    }
    e = z->key; // 삭제한 노드의 값을 저장합니다.

    if (z->lChild == NULL) {
        Transplant(root, z, z->rChild); // 왼쪽 자식이 없는 경우
    }
    else if (z->rChild == NULL) {
        Transplant(root, z, z->lChild); // 오른쪽 자식이 없는 경우
    }
    else {
        y = TreeMinimum(z->rChild); // 오른쪽 서브트리에서 최소값을 찾습니다.
        if (y->parent != z) {
            Transplant(root, y, y->rChild);
            y->rChild = z->rChild;
            y->rChild->parent = y;
        }
        Transplant(root, z, y);
        y->lChild = z->lChild;
        y->lChild->parent = y;
    }
    return e; // 삭제한 노드의 값을 반환합니다.
}

// 두 노드를 교체하는 함수
void Transplant(Node* T, Node* u, Node* v) {
    if (u->parent == NULL) {
        root = v;
    }
    else if (u == u->parent->lChild) {
        u->parent->lChild = v;
    }
    else {
        u->parent->rChild = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}
