#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

int find(int k, int *h);
int insert(int k, int *h);
int getNextBucket(int v, int i);
int H(int x);

int M;

int main() {

	int k, *hash, i, n;
	char ch;

	scanf("%d %d", &M, &n);
	hash = (int*)malloc(sizeof(int)*M);

	for (i = 0; i < M; i++) {
		hash[i] = 0;
	}

	while (1) {
		getchar();
		scanf("%c", &ch);
		if (ch == 'i') {
			scanf("%d", &k);
			printf("%d\n", insert(k, hash));
		}
		else if (ch == 's') {
			scanf("%d", &k);
			if (find(k, hash) != -1) {
				printf("%d %d\n", find(k, hash), k);
			}
			else {
				printf("%d\n", find(k, hash));
			}
		}
		else {
			break;
		}

	}
	

	return 0;
}


int H(int x) {
	return x % M;
}

int getNextBucket(int v, int i) {
	return (v + i) % M;
}

int insert(int k, int *h) {
	int v = H(k), i = 0, b;
	while (i < M) {
		b = getNextBucket(v, i);
		if (*(h + b) == 0) {
			*(h + b) = k;
			return b;
		}
		else {
			printf("C");
			i++;
		}
	}
}

int find(int k, int *h) {
	int v = H(k), i = 0, b;
	while (i < M) {
		b = getNextBucket(v, i);
		if (*(h + b) == 0) {
			return  -1;
		}
		else if(k == *(h + b)) {
			return b;
		}
		else {
			i++;
		}
	}
	return -1;
}