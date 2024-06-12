#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Up to 16 questions give up to 32 choices 16x2=32
#define MAX_QUESTIONS 16 // Maximum number of questions that can be handled, 
#define MAX_ANSWER_LEN 100 // Maximum length of answers and questions


typedef struct Node {
    char question[MAX_ANSWER_LEN]; // The question itself
    char yes_answer[MAX_ANSWER_LEN]; // Answer if the response is yes
    char no_answer[MAX_ANSWER_LEN]; // Answer if the response is no
    struct Node* yes_node; // Pointer to the next node if answer is yes
    struct Node* no_node; // Pointer to the next node if answer is no
} Node;

// Function to create a new node, initializes pointers to NULL
Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->yes_node = NULL;
    node->no_node = NULL;
    return node;
}

// Function to connect nodes based on their answers and questions
void connectNodes(Node** nodes, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        for (int j = 0; j < num_questions; j++) {
            if (strcmp(nodes[i]->yes_answer, nodes[j]->question) == 0) {
                nodes[i]->yes_node = nodes[j];
            }
            if (strcmp(nodes[i]->no_answer, nodes[j]->question) == 0) {
                nodes[i]->no_node = nodes[j];
            }
        }
    }
}

// Function to build the decision tree by inputting questions and answers
Node* buildDecisionTree() {
    Node* nodes[MAX_QUESTIONS];
    int num_questions;

    printf("Enter the number of questions (3 to 16): ");
    scanf("%d", &num_questions);
    while (num_questions < 3 || num_questions > 16) {
        printf("Invalid number of questions. Enter 3 to 16: ");
        scanf("%d", &num_questions);
    }

    for (int i = 0; i < num_questions; i++) {
        nodes[i] = createNode();

        printf("Enter question %d: ", i + 1);
        scanf(" %[^\n]s", nodes[i]->question);
        printf("Enter 'yes' answer: ");
        scanf(" %[^\n]s", nodes[i]->yes_answer);
        printf("Enter 'no' answer: ");
        scanf(" %[^\n]s", nodes[i]->no_answer);
    }

    connectNodes(nodes, num_questions);
    return nodes[0]; // Returns the root of the tree
}

// Function to run the decision tree, guiding the user through the questions
void runDecisionTree(Node* root) {
    Node* current = root;

    while (current != NULL) {
        char answer[MAX_ANSWER_LEN];
        printf("%s (y/n): ", current->question);
        scanf(" %s", answer);

        if (strcmp(answer, "y") == 0) {
            if (current->yes_node == NULL) {
                printf("Result: %s\n", current->yes_answer);
                return;
            }
            current = current->yes_node;
        } else if (strcmp(answer, "n") == 0) {
            if (current->no_node == NULL) {
                printf("Result: %s\n", current->no_answer);
                return;
            }
            current = current->no_node;
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
}

// Function to free all nodes in the tree to prevent memory leaks
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->yes_node);
    freeTree(root->no_node);
    free(root);
}

int main(void) {
    for (int i = 0; i < 3; i++) {
        printf("Consultation %d:\n", i + 1); 
        Node* root = buildDecisionTree(); // Build the decision tree
        printf("Tree complete. Now Running!!\n");
        runDecisionTree(root); // Run the decision tree
        freeTree(root); // Free the memory allocated for the tree
        printf("\n");
    }
    
    printf("Consultation End!\n"); // End 

    return 0;
}

