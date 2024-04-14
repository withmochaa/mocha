
/*

#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>

int* prefixAverages1(int *x, int n);
int* prefixAverages2(int *x, int n);

int main(void){

    LARGE_INTEGER start = { 0 }, end = { 0 }, diff = { 0 }, ticks = { 0 };
    int** ar = NULL, n, temp = 0;

    QueryPerformanceFrequency(&ticks);

    int n,i,j;,slow,fast;
    scanf("%d",&n);

    temp = n;
    count = 0;

    ar = (int**)calloc(n, sizeof(int*));

    for(i=0;i<n;i++){
        for(j=0;j<n<j++){
            ar[i][j]=rand()%10000 + 1;
        }

    QueryPerformanceCounter(&start);
    slow=prefixAverages1(ar, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("%.15lfms\n",(double)diff.QuadPart / (double)ticks.QuadPart);


    QueryPerformanceCounter(&start);
    fast=prefixAverages2(ar, n);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;

    printf("%.15lfms\n",(double)diff.QuadPart / (double)ticks.QuadPart);

    for (int i = 0; i < n; i++) {
      free(ar[i]);
   }

    free(ar);



    return 0;
}

int* prefixAverages1(int *x, int n) {
    int* y;
    y = (int*)malloc(n * sizeof(int));
    int i, j;

    // 각 위치의 접두사 평균 계산
    for (i = 0; i < n; i++) {
        double sum = 0;
        // 현재 위치까지의 합을 구함
        for (j = 0; j <= i; j++) {
            sum += x[j];
        }
        // 접두사 평균 계산 후 반올림하여 저장
        y[i] = (int)(sum / (i + 1) + 0.5);
    }
    return y;
}

// 주어진 배열의 접두사 평균을 계산하여 반환하는 함수 (방법 2) fast
int* prefixAverages2(int *x, int n) {
    int* y;
    y = (int*)malloc(n * sizeof(int));
    double sum = 0;
    int i;

    // 각 위치의 접두사 평균 계산
    for (i = 0; i < n; i++) {
        // 현재 위치까지의 합을 구함
        sum += x[i];
        // 접두사 평균 계산 후 반올림하여 저장
        y[i] = (int)(sum / (i + 1) + 0.5);
    }
    return y;
}

*/