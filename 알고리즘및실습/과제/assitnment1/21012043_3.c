#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <Windows.h>

// 선택 정렬
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (i != min_index) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

// 삽입 정렬
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//reverse
void reverseSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main(void) {
    int n;
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* A = (int*)malloc(sizeof(int) * n);
    if (A == NULL) return -1;

    int* B = (int*)malloc(sizeof(int) * n);
    if (B == NULL) return -1;

    srand(time(NULL)); // 난수 생성기 초기화
    for (int i = 0; i < 5; i++) {
        // 배열 A와 B를 동일한 난수로 초기화
        for (int i = 0; i < n; i++) {
            int rand_num = rand();
            A[i] = rand_num;
            B[i] = rand_num;
        }

        //reverseSort(A, n);
        //reverseSort(B, n);

        // 선택 정렬에 대한 시간 측정
        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);
        // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
        selectionSort(A, n);
        QueryPerformanceCounter(&end);
        // 측정값으로부터 실행시간 계산
        diff.QuadPart = end.QuadPart - start.QuadPart;
        printf("Selection sort time: %f ms\n\n", ((double)diff.QuadPart * 1000 / (double)ticksPerSec.QuadPart));

        // 삽입 정렬에 대한 시간 측정;
        QueryPerformanceFrequency(&ticksPerSec);
        QueryPerformanceCounter(&start);
        // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입
        insertionSort(B, n);
        QueryPerformanceCounter(&end);
        // 측정값으로부터 실행시간 계산
        diff.QuadPart = end.QuadPart - start.QuadPart;
        printf("Insertion sort time: %f ms\n\n", ((double)diff.QuadPart * 1000 / (double)ticksPerSec.QuadPart));
    }
    // 메모리 해제
    free(A);
    free(B);

    return 0;
}