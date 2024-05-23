#include<stdio.h>		
#include<stdlib.h> 

// Define the structure for a tree node
typedef struct Tnode{
	int data; 
	struct Tnode *left; // Pointer to the left child
	struct Tnode *right; // Pointer to the right child
} Tnode;

int main(void){
	int n; // Variable to store user input
	
	Tnode *F1 = (Tnode*)malloc(sizeof(Tnode));
	Tnode *F2 = (Tnode*)malloc(sizeof(Tnode));
	Tnode *F3 = (Tnode*)malloc(sizeof(Tnode));
	Tnode *F4 = (Tnode*)malloc(sizeof(Tnode));
	Tnode *F5 = (Tnode*)malloc(sizeof(Tnode));
	Tnode *F6 = (Tnode*)malloc(sizeof(Tnode));
	Tnode *F7 = (Tnode*)malloc(sizeof(Tnode));
	Tnode *F8 = (Tnode*)malloc(sizeof(Tnode));

	// Initialize the nodes with data and children
	F7->data = 130;
	F7->left = NULL;
	F7->right = NULL;
	F8->data = 80;
	F8->left = NULL;
	F8->right = NULL;
	F6->data = 120;
	F6->left = F7;
	F6->right = F8;
	F3->data = 50;
	F3->left = NULL;
	F3->right = F6;
	F1->data = 20;
	F1->left = NULL;
	F1->right = F3;
	F4->data = 70;
	F4->left = NULL;
	F4->right = NULL;
	F5->data = 90;
	F5->left = NULL;
	F5->right = NULL;
	F2->data = 30;
	F2->left = F4;
	F2->right = F5;

	
	scanf("%d", &n);


	if (n == 1) {
		printf("%d %d %d", F1->data, F2->data, F3->data);
	}
	else if (n == 2) {
		printf("%d %d %d", F2->data, F4->data, F5->data);
	}
	else if (n == 3) {
		printf("%d %d", F3->data, F6->data);
	}
	else if (n == 4) {
		printf("%d", F4->data);
	}
	else if (n == 5) {
		printf("%d", F5->data);
	}
	else if (n == 6) {
		printf("%d %d %d", F6->data, F7->data, F8->data);
	}
	else if (n == 7) {
		printf("%d", F7->data);
	}
	else if (n == 8) {
		printf("%d", F8->data);
	}
	else {
		printf("-1");
	}
	
	// Free  memory
	free(F1);
	free(F2);
	free(F3);
	free(F4);
	free(F5);
	free(F6);
	free(F7);
	free(F8);

	return 0;
}
