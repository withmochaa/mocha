#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 연결 이진 트리, 왼쪽 자식 링크, 노드 번호, 오른쪽 자식 링크로 구성됩니다.
// 자식이 없는 경우 링크는 0을 가리킵니다.
// 포인터 변수는 루트 노드에 대해서만 사용 가능하며, 트리는 루트를 통해서만 접근합니다.

// 노드 구조체 정의
typedef struct node {
    struct node *left, *right; // 왼쪽 자식 노드와 오른쪽 자식 노드를 가리키는 포인터
    int data; // 노드의 데이터 (노드 번호)
} node;

// 노드를 할당하고 초기화하는 함수
node *getnode() {
    return (node *)calloc(1, sizeof(node));
}

// 내부 노드인지 확인하는 함수
int isInternal(node *tree) {
    if (tree->left == NULL && tree->right == NULL) {
        return 0; // 자식 노드가 존재하지 않으면 0 반환
    } else {
        return 1; // 자식 노드가 존재하면 1 반환
    }
    return 1; // 자식 노드가 존재하면 1 반환
}

// 트리를 구성하는 함수
void tree_making(node *tree) {
    int num1, num2, num3;

    scanf("%d %d %d", &num1, &num2, &num3);
    tree->data = num1; // 노드 번호 n1에 저장, n2는 왼쪽 자식 노드, n3은 오른쪽 자식 노드

    if (num2 != 0) { // 왼쪽 자식 노드가 0이 아니라면
        tree->left = getnode();
        tree->left->data = num1;
        tree_making(tree->left);
    }
    if (num3 != 0) {
        tree->right = getnode();
        tree->right->data = num3;
        tree_making(tree->right);
    }
    if (num2 == 0) {
        if (num3 == 0) return;
    }
}

// 주어진 경로를 따라 트리를 탐색하고 결과를 출력하는 함수
void search(node *root, char *ar) {
    node *p = root;

    for (char *q = ar; q < ar + strlen(ar) + 1; q++) {
        printf(" %d", p->data);
        if (*q == 'R') {
            p = p->right;
        }
        if (*q == 'L') {
            p = p->left;
        }
    }
    printf("\n");
}

// 트리의 노드를 해제하는 함수
void node_free(node *v) {
    if (v == NULL) {
        return;
    }

    node_free(v->left);
    node_free(v->right);

    free(v);
}

int main(void) {
    int n, num;
    char arr[100]; // 탐색 길이를 저장할 배열, 최대 길이는 100으로 가정

    // 유효하지 않은 탐색 정보는 주어지지 않는다고 가정하고 진행합니다.

    node *root = getnode();

    scanf("%d", &n); // 노드 개수를 입력 받습니다
    tree_making(root);

    scanf("%d", &num); // 탐색 횟수를 입력 받습니다

    for (int i = 0; i < num; i++) {
        scanf("%s", arr);
        search(root, arr);
    }

    node_free(root); // 노드를 해제합니다
}
