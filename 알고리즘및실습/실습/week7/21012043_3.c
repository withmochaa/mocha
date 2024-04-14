#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

// 이진 검색 트리 노드를 나타내는 구조체
typedef struct Node {
	int key, height;
	struct Node* lChild;
	struct Node* rChild;
	struct Node* parent;
} Node;

struct Node* root; // 루트 노드

// 노드가 내부 노드인지 검사
int isInternal(Node* T);
// 노드가 외부 노드인지 검사
int isExternal(Node* T);
// 외부 노드를 확장하여 내부 노드로 만듭니다.
void expandExternal(struct Node* w);
// 주어진 키를 가지는 노드를 트리에서 검색합니다.
Node* treeSearch(Node* w, int k);
// 노드의 높이를 업데이트합니다.
int updateHeight(struct Node* w);
// 노드가 균형잡혀 있는지 검사
int isBalanced(struct Node* w);
// 노드를 재구성하여 균형을 유지합니다.
Node* restructure(Node* x, Node* y, Node* z);
// 삽입 후에 균형을 유지하기 위한 작업 수행
void searchAndFixAfterInsertion(Node* w);
// 트리에 항목을 삽입합니다.
void insertItem(Node* w, int k);
// 트리를 출력합니다.
void Print(Node* w);
// 중위 후계자 노드를 찾습니다.
Node* inOrderSucc(Node* T);
// 외부 노드를 축소하여 제거합니다.
Node* reduceExternal(Node* z);
// 항목을 제거합니다.
int removeElement(Node* w, int k);
// 노드의 형제 노드를 찾습니다.
Node* sibling(Node* w);
// 제거 후 균형을 유지하기 위한 작업 수행
void searchAndFixAfterRemoval(Node* w);

int main() {
	char ch;
	int k, value;
	
	// 루트 노드 초기화
	root = (struct Node*)malloc(sizeof(struct Node));
	root->parent = NULL;
	root->lChild = NULL;
	root->rChild = NULL;

	while (1) {
		scanf("%c", &ch);

		if (ch == 'i') {
			scanf("%d", &k);
			insertItem(root, k);
			getchar();
		}
		else if (ch == 's') {
			scanf("%d", &k);
			if (treeSearch(root, k)->key != k) {
				printf("X\n");
			}
			else {
				printf("%d\n", treeSearch(root, k)->key);
			}
			getchar();
		}
		else if (ch == 'd') {
			scanf("%d", &k);
			value = removeElement(root, k);
			if (value == k) {
				printf("%d\n", value);
			}
			else {
				printf("X\n");
			}
			getchar();
		}
		else if (ch == 'p') {
			Print(root);
			printf("\n");
		}
		else if (ch == 'q') {
			break;
		}
	}
	return 0;
}

// 내부 노드 여부를 확인
int isInternal(Node* T) {
	if (T->lChild != NULL || T->rChild != NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

// 외부 노드 여부를 확인
int isExternal(Node* T) {
	if (T->lChild == NULL && T->rChild == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

// 외부 노드를 내부 노드로 확장
void expandExternal(Node* w) {
	Node* l = (Node*)malloc(sizeof(Node));
	Node* r = (Node*)malloc(sizeof(Node));

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

	return;
}

// 트리에서 키를 검색
Node* treeSearch(Node* T, int k) {
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

// 항목을 삽입
void insertItem(Node* T, int k) {
	Node* w = treeSearch(T, k);
	if (isInternal(w)) {
		return;
	}
	else {
		w->key = k;
		expandExternal(w);
		searchAndFixAfterInsertion(w);
	}
}

// 삽입 후 균형을 유지하기 위한 작업 수행
void searchAndFixAfterInsertion(Node* w) {
	Node* x, *y, *z;
	w->lChild->height = 0;
	w->rChild->height = 0;
	w->height = 1;
	if (w->parent == NULL) {
		return NULL;
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
	return;
}

// 노드의 높이를 업데이트
int updateHeight(struct Node* w) {
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

// 노드의 균형 여부를 확인
int isBalanced(Node* w) {
	int lh = w->lChild->height;
	int rh = w->rChild->height;
	if ((-1 <= lh - rh) && (lh - rh <= 1)) {
		return 1;
	}
	else {
		return 0;
	}
}

// 노드를 재구성하여 균형을 유지
Node* restructure(Node* x, Node* y, Node* z) {
	// (x < y < z) 또는 (z < y < x)일 때의 재구성
	Node* a, *b, *c, *T0, *T1, *T2, *T3;
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
	a->rChild = T1;
	T0->parent = a;
	T1->parent = a;
	updateHeight(a);
	c->lChild = T2;
	c->rChild = T3;
	T2->parent = c;
	T3->parent = c;
	updateHeight(c);
	b->lChild = a;
	a->parent = b;
	b->rChild = c;
	c->parent = b;
	updateHeight(b);
	return b;
}

// 트리를 중위 순회하며 출력
void Print(Node* w) {
	if (isExternal(w)) {
		return;
	}
	else {
		printf(" %d", w->key);
		Print(w->lChild);
		Print(w->rChild);
	}
}

// 제거 후 균형을 유지하기 위한 작업 수행
void searchAndFixAfterRemoval(Node* w) {
	Node* x, *y, *z, *b;
	if (w == NULL) {
		return;
	}
	z = w;
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
	else if (y->lChild->height < y->rChild->height) {
		x = y->rChild;
	}
	else {
		if (z->lChild == y) {
			x = y->lChild;
		}
		else if (z->rChild == y) {
			x = y->rChild;
		}
	}
	b = restructure(x, y, z);
	searchAndFixAfterRemoval(b->parent);
}

// 노드의 형제 노드를 찾음
Node* sibling(Node* w) {
	if (w->parent == NULL) {
		return NULL;
	}
	if (w->parent->lChild == w) {
		return w->parent->rChild;
	}
	else {
		return w->parent->lChild;
	}
}

// 항목을 제거
int removeElement(Node* w, int k) {
	Node* p = treeSearch(w, k);
	Node* z, *zs, *y;
	int e;
	if (isExternal(p)) {
		return -1;
	}
	e = p->key;
	z = p->lChild;
	if (!isExternal(z)) {
		z = p->rChild;
	}
	if (isExternal(z)) {
		zs = reduceExternal(z);
	}
	else {
		y = inOrderSucc(p);
		z = y->lChild;
		p->key = y->key;
		zs = reduceExternal(z);
	}
	searchAndFixAfterRemoval(zs->parent);
	return e;
}

// 외부 노드를 축소하여 제거
Node* reduceExternal(Node* z) {
	Node* p, *zs, *w;
	p = z->parent;
	zs = sibling(z);
	if (p->parent == NULL) {
		root = zs;
		zs->parent = NULL;
	}
	else {
		w = p->parent;
		zs->parent = w;
		if (p == w->lChild)
			w->lChild = zs;
		else if (p == w->rChild)
			w->rChild = zs;
	}
	free(z);
	free(p);
	return zs;
}

// 중위 후계자 노드를 찾음
Node* inOrderSucc(Node* T) {
	T = T->rChild;
	if (isExternal(T)) {
		return;
	}
	while (isInternal(T->lChild)) {
		T = T->lChild;
	}
	return T;
}
