#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Definition tree node
typedef struct Tnode {
    int id;            // Node identifier
    int data;          // Node data
    struct Tnode *left;  // Pointer left child
    struct Tnode *right; // Pointer right child
} Tnode;

// Function prototypes
void find_id(Tnode **t, Tnode *tree, int ID);
int sum(Tnode *t);

int main(void) {
    
    Tnode *tree, F1, F2, F3, F4, F5, F6, F7, F8;
    int ID, S = 0;

    // Initialization of tree nodes
    F7.data = 130; F7.left = NULL; F7.right = NULL; F7.id = 7;
    F8.data = 80; F8.left = NULL; F8.right = NULL; F8.id = 8;
    F6.data = 120; F6.left = &F7; F6.right = &F8; F6.id = 6;
    F3.data = 50; F3.left = NULL; F3.right = &F6; F3.id = 3;
    F1.data = 20; F1.left = &F2; F1.right = &F3; F1.id = 1;
    F4.data = 70; F4.left = NULL; F4.right = NULL; F4.id = 4;
    F5.data = 90; F5.left = NULL; F5.right = NULL; F5.id = 5;
    F2.data = 30; F2.left = &F4; F2.right = &F5; F2.id = 2;
    tree = &F1;

  
    scanf("%d", &ID);

   
    Tnode* tmp = tree;
    find_id(&tmp, tree, ID);

    if (0 < ID && ID < 9) {
        S = sum(tmp);
        printf("%d", S);
    } else {
        printf("-1");
    }

    return 0;
}

// Function to find the node with a specific ID
void find_id(Tnode **t, Tnode *tree, int ID) {
    if (tree != NULL) {
        if (tree->id == ID) {
            *t = tree;
        }
        find_id(t, tree->left, ID);
        find_id(t, tree->right, ID);
    } else {
        return;
    }
}

// Function to calculate the sum of all nodes in the subtree
int sum(Tnode *t) {
    if (t != NULL) {
        return sum(t->left) + sum(t->right) + t->data;
    } else {
        return 0;
    }
}