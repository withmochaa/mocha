#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int H[100], n = 0; // 정수 배열 H와 배열의 길이를 나타내는 변수 n을 전역 변수로 선언

// 함수 원형 선언
void inPlaceHeapSort();
void printArray();
void downHeap(int i);
void insertItem(int key);
void upHeap(int i);
void rBuildHeap(int i);
void buildHeap();

int main(void) {

    // 배열 크기 n 입력
    scanf("%d", &n);

    // n개의 정수를 배열 H에 입력
    for (int i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
    }

    // 힙 정렬을 수행하고 정렬된 배열 출력
    inPlaceHeapSort();
    printArray();

    return 0;
}

void inPlaceHeapSort() {

    int temp, N = n;

    buildHeap(); // 힙을 구성

    for (int i = n; i >= 2; i--) {
        temp = H[i];
        H[i] = H[1];
        H[1] = temp;
        n--;
        downHeap(1);
    }
    n = N;
}

void printArray() {

    // 정렬된 배열을 출력
    for (int i = 1; i <= n; i++) {
        printf("%d ", H[i]);
    }
    printf("\n");
}

void rBuildHeap(int i) {

    if (i > n) return;
    rBuildHeap(2 * i);
    rBuildHeap(2 * i + 1);
    downHeap(i);

    return;
}

void buildHeap() {

    for (int i = n / 2; i >= 1; i--)
        downHeap(i);

    return;
}

void downHeap(int i) {

    int left, right, bigger, temp;

    left = 2 * i;
    right = 2 * i + 1;

    bigger = left;

    if (left > n) return;

    if (right <= n) {
        if (H[right] > H[bigger]) {
            bigger = right;
        }
    }

    if (H[bigger] <= H[i]) return;

    temp = H[bigger];
    H[bigger] = H[i];
    H[i] = temp;

    downHeap(bigger);
}

void insertItem(int key) {

    n += 1;
    H[n] = key;
    upHeap(n);
    return;
}

void upHeap(int i) {

    int temp;

    if (i == 1) return;

    if (H[i] <= H[i / 2]) return;

    temp = H[i];
    H[i] = H[i / 2];
    H[i / 2] = temp;

    upHeap(i / 2);
}

