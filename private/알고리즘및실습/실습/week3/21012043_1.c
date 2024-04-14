#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996) // 경고 4996을 무시

void insertItem(int key); // 반환값이 없는 insertItem 함수 정의
int removeMax(); // 정수를 반환하는 removeMax 함수 정의
void upheap(int i); // 반환값이 없는 upheap 함수 정의
void downheap(int i); // 반환값이 없는 downheap 함수 정의
void printHeap(); // 반환값이 없는 printHeap 함수 정의

int H[100], n = 0;

int main(void) {

    int key;
    char ch;

    while (1) { // 조건이 True인 무한 루프 생성

        scanf("%c", &ch); // 문자를 입력 받음

        if (ch == 'i') {
            scanf("%d", &key);
            insertItem(key); // 입력 받은 문자가 'i'인 경우 insertItem 함수 호출
            printf("0\n");
        }
        else if (ch == 'd') {
            printf("%d\n", removeMax());
        }
        else if (ch == 'p') {
            printHeap();
        }
        else if (ch == 'q') { // 입력 받은 문자가 'q'일 때 무한 루프 탈출
            break;
        }
        getchar();
    }

    return 0;
}

void insertItem(int key) { // insertItem 함수 
    n += 1; // n 값을 호출될 때마다 1씩 증가
    H[n] = key; // key 값을 H[n]에 갱신
    upheap(n); // upheap 함수 호출
}

int removeMax() { // removeMax 함수

    int key;

    key = H[1]; // key 값 갱신
    H[1] = H[n];
    n -= 1;
    downheap(1); // downheap을 호출하는 이유는 downheap에서 i가 1로 항상 시작하기 때문

    return key; // 정수 key를 반환
}

void upheap(int i) { // upheap 함수

    int tmp;

    if (i == 1) { // 만약 i가 1이면 함수 종료
        return;
    }
    else if (H[i] <= H[i / 2]) { // 조건 만족 시 함수 종료
        return;
    }
    else { // H[i]값 갱신
        tmp = H[i];
        H[i] = H[i / 2];
        H[i / 2] = tmp;
    }
    upheap(i / 2); // upheap 함수 호출
}

void downheap(int i) { // downheap 함수 

    int left = 2 * i, right = 2 * i + 1, big, tmp; // 변수 선언 및 초기화

    if (left > n) { // 조건 만족 시 함수 종료
        return;
    }

    big = left;

    if (right <= n) {
        if (H[right] > H[big]) {
            big = right;
        }
    }

    if (H[i] >= H[big]) {
        return;
    }

    tmp = H[big]; // switch
    H[big] = H[i];
    H[i] = tmp;

    downheap(big);
}

void printHeap() { // printHeap 함수

    int i;

    for (i = 1; i <= n; i++) { // 출력
        printf(" %d", H[i]);
    }
    printf("\n");
}
