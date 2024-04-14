#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int H[100], n = 0; // 정수 배열 H와 배열의 길이를 나타내는 변수 n을 선언

// 함수 원형 선언
void inPlaceHeapSort();
void printArray();
void downHeap(int i);
void insertItem(int key);
void upHeap(int i);
void rBuildHeap(int i);
void buildHeap();

int main(void) {
    
    // 배열 크기 n을 입력받음
    scanf("%d", &n);

    // n개의 정수를 배열 H에 입력받음
    for (int i = 1; i <= n; i++) {
        scanf("%d", &H[i]);
    }

    // 힙 정렬을 수행하고 정렬된 배열을 출력
    inPlaceHeapSort();
    printArray();

    return 0;
}

void inPlaceHeapSort() {

    int temp, N = n;

    buildHeap(); // 최대 힙을 구성

    for (int i = n; i >= 2; i--) {
        temp = H[i]; // 가장 큰 요소와 맨 뒤 요소 교환
        H[i] = H[1];
        H[1] = temp;
        n--; // 힙 크기 줄임
        downHeap(1); // 힙 속성 복원
    }
    n = N; // 원래 크기로 복원
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
    downHeap(i); // 힙 속성 복원

    return;
}

void buildHeap() {

    for (int i = n / 2; i >= 1; i--)
        downHeap(i); // 모든 서브트리에 대해 힙 속성 복원

    return;
}

void downHeap(int i) {

    int left, right, bigger, temp;

    left = 2 * i;
    right = 2 * i + 1;

    bigger = left;

    if (left > n) return; // 리프 노드에 도달하면 반환

    if (right <= n) { // 오른쪽 자식 노드가 존재하는 경우
        if (H[right] > H[bigger]) { // 오른쪽 자식이 더 크다면
            bigger = right; // 오른쪽 자식으로 설정
        }
    }

    if (H[bigger] <= H[i]) return; // 자식보다 크다면 반환

    temp = H[bigger];
    H[bigger] = H[i];
    H[i] = temp;

    downHeap(bigger); // 큰 자식 노드로 재귀 호출
}

void insertItem(int key) {

    n += 1;
    H[n] = key;
    upHeap(n); // 힙 속성 복원
    return;
}

void upHeap(int i) {

    int temp;

    if (i == 1) return; // 루트에 도달하면 반환

    if (H[i] <= H[i / 2]) return; // 부모 노드보다 작거나 같으면 반환

    temp = H[i];
    H[i] = H[i / 2];
    H[i / 2] = temp;

    upHeap(i / 2); // 부모 노드로 재귀 호출
}
