#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> // 시간을 이용한 난수 생성을 위한 헤더 파일
#pragma warning(disable:4996) // Visual Studio 컴파일러 경고를 무시

void inPlaceQuickSort(int L[], int s, int e);
int inPlacePartition(int L[], int s, int e, int k);
int findPivot(int L[], int s, int e);

int main()
{
    int n, *L, i;

    scanf("%d", &n);

    // 입력된 크기에 따라 동적 배열 할당
    L = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", L + i);
    }

    // 인플레이스 퀵소트 알고리즘 호출
    inPlaceQuickSort(L, 0, n - 1);

    // 정렬된 배열 출력
    for (i = 0; i < n; i++) {
        printf(" %d", L[i]);
    }

    // 동적 배열 메모리 해제
    free(L);

    return 0;
}

// 인플레이스 퀵소트 함수
void inPlaceQuickSort(int L[], int s, int e) {

    int pivot, a;

    // 범위의 시작 인덱스가 끝 인덱스보다 크거나 같으면 정렬할 필요가 없음
    if (s >= e) {
        return;
    }

    // 피벗 선택
    pivot = findPivot(L, s, e);
    
    // 피벗을 중심으로 분할하고, 피벗의 새 위치를 얻음
    a = inPlacePartition(L, s, e, pivot);
    
    // 피벗을 기준으로 왼쪽 부분과 오른쪽 부분을 재귀적으로 정렬
    inPlaceQuickSort(L, s, a - 1);
    inPlaceQuickSort(L, a + 1, e);
}

// 인플레이스 파티션 함수
int inPlacePartition(int L[], int s, int e, int k) {

    int pivot = L[k], tmp, j, i;

    // 선택한 피벗을 배열의 마지막 원소와 교환
    tmp = L[k];
    L[k] = L[e];
    L[e] = tmp;

    i = s;
    j = e - 1;

    // 피벗을 중심으로 작은 값은 왼쪽, 큰 값은 오른쪽으로 이동
    while (i <= j) {
        while (i <= j && L[i] <= pivot) {
            i++;
        }
        while (j >= i && L[j] >= pivot) {
            j--;
        }
        if (i < j) {
            tmp = L[i];
            L[i] = L[j];
            L[j] = tmp;
        }
    }

    // 피벗의 최종 위치를 찾아서 이동
    tmp = L[i];
    L[i] = L[e];
    L[e] = tmp;

    // 피벗의 새 위치 반환
    return i;
}

// 랜덤하게 피벗을 선택하는 함수
int findPivot(int L[], int s, int e) {
    int p;
    srand(time(NULL)); // 현재 시간을 시드로 사용하여 난수 생성
    p = rand() % (e + 1 - s) + s; // s부터 e까지의 난수 생성
    return p;
}
