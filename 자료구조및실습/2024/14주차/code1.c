#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

// Define the node structure
typedef struct node {
    int value;
    struct node* leftChild, * rightChild;
} TreeNode;

// Function to create and initialize a new node
TreeNode* createNode() {
    return (TreeNode*)calloc(1, sizeof(TreeNode));
}

// Function to check if a node is an internal node
int isInternal(TreeNode* currentNode) {
    if (currentNode->leftChild == NULL && currentNode->rightChild == NULL){
        return 0;
    }
    return 1;
}

// Function to build the tree recursively
void buildTree(TreeNode* currentNode) {
    int nodeValue = 0, leftValue = 0, rightValue = 0;

    scanf("%d%d%d", &nodeValue, &leftValue, &rightValue);

    currentNode->value = nodeValue;

    if (leftValue != 0) {
        currentNode->leftChild = createNode();
        currentNode->leftChild->value = leftValue;
        buildTree(currentNode->leftChild);
    }

    if (rightValue != 0) {
        currentNode->rightChild = createNode();
        currentNode->rightChild->value = rightValue;
        buildTree(currentNode->rightChild);
    }

    if (leftValue == 0 && rightValue == 0) return;
}

// Preorder traversal function
void preorderTraversal(TreeNode *currentNode){

    if (currentNode == NULL) return;
    printf("%d ", currentNode->value);

    if (isInternal(currentNode)){
        preorderTraversal(currentNode->leftChild);
        preorderTraversal(currentNode->rightChild);
    }
}

// Function to free the memory allocated for the tree
void clearTree(TreeNode *currentNode){

    if (currentNode == NULL) return;

    clearTree(currentNode->leftChild);
    clearTree(currentNode->rightChild);
    free(currentNode);
}

// Function to search along a specific path
void searchPath(TreeNode* root, char* path) {

    TreeNode* current = root;

    for (char* c = path; c < path + strlen(path) + 1; c++) {
        printf(" %d", current->value);

        if (*c == 'R') current = current->rightChild;
        else if (*c == 'L') current = current->leftChild;
    }
    printf("\n");
    return;
}

int main(void) {

    int totalNodes, searches;  
    char pathQuery[100] = { 0 };

    TreeNode* root = createNode();

    scanf("%d", &totalNodes);

    buildTree(root);
    
    scanf("%d", &searches);

    for (int i = 0; i < searches; i++) {
        scanf("%s", pathQuery);
        searchPath(root, pathQuery);
    }

    clearTree(root);

    return 0;
}

