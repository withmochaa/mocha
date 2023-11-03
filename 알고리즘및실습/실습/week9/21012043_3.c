#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)

void print(int *hash);
int find(int k, int *h);
int insert(int k, int *h);
int getNextBucket(int v, int i, int k);
int H(int x);
int H2(int x);

int M, q;

int main() {

	int k, *hash, i, n;
	char ch;

	scanf("%d %d %d", &M, &n, &q);
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
		else if (ch == 'p') {
			print(hash);
		}
		else {
			print(hash);
			break;
		}

	}
	

	return 0;
}


int H(int x) {
	return x % M;
}

int H2(int x) {
	return q - (x%q);
}


int getNextBucket(int v, int i, int k) {
	return (v + i * H2(k) % M) % M;
}

int insert(int k, int *h) {
	int v = H(k), i = 0, b;
	while (i < M) {
		b = getNextBucket(v, i, k);
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
		b = getNextBucket(v, i, k);
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

void print(int *hash) {
	int i;
	for (i = 0; i < M; i++) {
		printf(" %d", *(hash + i));
	}
	printf("\n");
}