#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minDepth = 3;
int maxDepth = 5;

// 트리 노드의 구조체 정의
typedef struct node
{
    char *data;
    struct node *left, *right;
} node;

// 함수 정의
node *leftChild(node *root);
node *rightChild(node *root);
node *buildDecisionTree();
node *makeExternalNode();
node *makeInternalNode(int currentDepth);
int isInternal(node *root);
void runDecisionTree(node *root);
void processNode(node *root);
void freeTree(node *root);

int main()
{
    // 트리 생성
    node *root = buildDecisionTree();

    // 프로그램 시작
    printf("Tree complete. Now Running!!\n");

    // 상담 3회 진행
    for (int i = 0; i < 3; i++)
    {
        printf("Test run %d:\n", i + 1);
        runDecisionTree(root);
        printf("\n");
    }

    // 트리의 모든 노드를 해제
    freeTree(root);
    return 0;
}

// 의사결정 트리를 구축하는 함수
node *buildDecisionTree()
{
    printf("***Let's build a dichotomous QA system\n");
    return makeInternalNode(1); // 초기 깊이는 1로 설정
}

// 외부 노드 생성
node *makeExternalNode()
{
    // 새 노드와 그 안의 데이터에 메모리를 할당
    node *root = (node *)calloc(1, sizeof(node));
    root->data = (char *)malloc(100 * sizeof(char));

    // 최종 답변 입력
    printf("Enter decision:");
    scanf(" %[^\n]s", root->data);

    // 하위노드 NULL로 초기화
    root->left = root->right = NULL;
    return root;
}

// 내부 노드 생성
node *makeInternalNode(int currentDepth)
{
    // yes or no 저장하는 곳
    char answer[4];

    // 새 노드와 그 안의 데이터에 메모리를 할당
    node *root = (node *)calloc(1, sizeof(node));
    root->data = (char *)malloc(100 * sizeof(char));

    if (currentDepth < maxDepth + 1)
    {
        // 질문 입력
        printf("Enter question:");
        scanf(" %[^\n]s", root->data);

        // yes일때 질문
        printf("Question if yes to '%s'?", root->data);
        // 답변 받기
        scanf(" %s", answer);

        // 답변이 yes일때
        if ((currentDepth < maxDepth + 1 && strcmp(answer, "yes") == 0) || currentDepth < minDepth)
        {
            if (strcmp(answer, "yes") != 0 && currentDepth < minDepth)
            {
                printf("최소 3회의 문답으로 상담이 이루어져야 합니다. 계속 진행해주세요.\n");
            }

            root->left = makeInternalNode(currentDepth + 1); // 현재 깊이를 그대로 전달
        }
        else
        {
            if (currentDepth >= maxDepth)
            {
                printf("최대 5회의 문답으로 상담이 이루어져야 합니다. 마지막 결과를 적어주세요.\n");
            }
            root->left = makeExternalNode();
        }

        // no일때 질문
        printf("Question if no to '%s'?", root->data);
        // 답변 받기
        scanf(" %s", answer);

        // 답변이 yes일때
        if ((currentDepth < maxDepth + 1 && strcmp(answer, "yes") == 0) || currentDepth < minDepth)
        {
            if (strcmp(answer, "yes") != 0 && currentDepth < minDepth)
            {
                printf("최소 3회의 문답으로 상담이 이루어져야 합니다. 계속 진행해주세요.\n");
            }
            root->right = makeInternalNode(currentDepth + 1);
        }
        else
        {
            root->right = makeExternalNode();
        }
    }
    else
    {
        if (currentDepth >= maxDepth)
        {
            printf("최대 5회의 문답으로 상담이 이루어져야 합니다. 마지막 결과를 적어주세요.\n");
        }
        root = makeExternalNode();
    }

    return root;
}

// 트리 탐색 선언
void runDecisionTree(node *root)
{
    printf("***Please answer questions\n");
    processNode(root);
}

// 내부노드 인지 확인
int isInternal(node *root)
{
    return (root->left != NULL || root->right != NULL);
}

// 왼쪽 노드로 이동
node *leftChild(node *root)
{
    return root->left;
}

// 오른쪽 노드로 이동
node *rightChild(node *root)
{
    return root->right;
}

// 트리를 탐색하는 함수
void processNode(node *root)
{
    // yes or no 저장하는 곳
    char answer[4];

    // 데이터 출력하기
    printf("%s\n", root->data);

    // 내부 노드인 경우
    if (isInternal(root))
    {
        scanf(" %s", answer);
        if (strcmp(answer, "yes") == 0)
            processNode(leftChild(root));
        else
            processNode(rightChild(root));
    }
}

// 노드와 그 하위 노드를 재귀적으로 해제하는 함수
void freeTree(node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root->data);
    free(root);
}
// 3회 진행 예시
/*
1
yes
2
yes
4
no
8
no
9
yes
5
no
10
no
11
yes
3
yes
6
no
12
no
13
yes
7
no
14
no
15
*/

// 5회 진행 예시
/*
1
yes
2
yes
4
no
8
no
9
yes
5
no
10
no
11
yes
3
yes
6
no
12
no
13
yes
7
yes
14
yes
16
no
18
no
19
no
17
no
15
*/