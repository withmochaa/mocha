/*
#define no_init_all deprecated
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>


int put_array(int* arr, int pre_one, int* count);//배열에 1을 램덤으로 넣는 함수
int countOnesButSlow(int **X, int n);//느린 방법으로 1의 개수를 count
int countOnes(int **X, int n);//빠른 방법으로 1의 개수를 count


int main(void) {

   LARGE_INTEGER start = { 0 }, end = { 0 }, diff = { 0 }, ticks = { 0 };
   int** ar = NULL, n, temp = 0, count = 0, slow_count = 0, fast_count = 0;

   QueryPerformanceFrequency(&ticks);

   n = 30000; //n이 30000이고 빠른 버전
   temp = n;
   count = 0;
   ar = (int**)calloc(n, sizeof(int*));

   for (int i = 0; i < n; i++) {
      ar[i] = (int*)calloc(n, sizeof(int));
      temp = put_array(ar[i], temp, &count);
   }

   QueryPerformanceCounter(&start);
   fast_count = countOnes(ar, n);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;

   printf("n is 30,000 and version is fast_ver %d %d %.15lfsec\n", count, fast_count, (double)diff.QuadPart / (double)ticks.QuadPart);

   for (int i = 0; i < n; i++) {
      free(ar[i]);
   }
   free(ar);

   n = 10000; // n이 10000이고 빠른 버전일 때
   temp = n;
   count = 0;
   ar = (int**)calloc(n, sizeof(int*));

   for (int i = 0; i < n; i++) {
      ar[i] = (int*)calloc(n, sizeof(int));
      temp = put_array(ar[i], temp, &count);
   }

   QueryPerformanceCounter(&start);
   fast_count = countOnes(ar, n);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;

   printf("n is 10,000 and version is fast_ver %d %d %.15lfsec\n", count, fast_count, (double)diff.QuadPart / (double)ticks.QuadPart);

   for (int i = 0; i < n; i++) {
      free(ar[i]);
   }
   free(ar);

   n = 20000; // n이 20000이고 빠른 버전일 때
   temp = n;
   count = 0;
   ar = (int**)calloc(n, sizeof(int*));

   for (int i = 0; i < n; i++) {
      ar[i] = (int*)calloc(n, sizeof(int));
      temp = put_array(ar[i], temp, &count);
   }

   QueryPerformanceCounter(&start);
   fast_count = countOnes(ar, n);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;

   printf("n is 20,000 and version is fast_ver %d %d %.15lfsec\n", count, fast_count, (double)diff.QuadPart / (double)ticks.QuadPart);

   for (int i = 0; i < n; i++) {
      free(ar[i]);
   }
   free(ar);

   n = 30000; // n이 30000이고 느린 버전일 때
   temp = n;
   count = 0;
   ar = (int**)calloc(n, sizeof(int*));

   for (int i = 0; i < n; i++) {
      ar[i] = (int*)calloc(n, sizeof(int));
      temp = put_array(ar[i], temp, &count);
   }

   QueryPerformanceCounter(&start);
   slow_count = countOnesButSlow(ar, n);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;

   printf("n is 30,000 and version is slow_ver %d %d %.15lfsec\n", count, slow_count, (double)diff.QuadPart / (double)ticks.QuadPart);

   for (int i = 0; i < n; i++) {
      free(ar[i]);
   }
   free(ar);

   n = 10000; //n이 10000이고 느린 버전일 때
   temp = n;
   count = 0;
   ar = (int**)calloc(n, sizeof(int*));

   for (int i = 0; i < n; i++) {
      ar[i] = (int*)calloc(n, sizeof(int));
      temp = put_array(ar[i], temp, &count);
   }

   QueryPerformanceCounter(&start);
   slow_count = countOnesButSlow(ar, n);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;

   printf("n is 10,000 and version is slow_ver %d %d %.15lfsec\n", count, slow_count, (double)diff.QuadPart / (double)ticks.QuadPart);

   for (int i = 0; i < n; i++) {
      free(ar[i]);
   }
   free(ar);

   n = 20000; //n이 20000이고 느린 버전일 때
   count = 0;
   ar = (int**)calloc(n, sizeof(int*));

   for (int i = 0; i < n; i++) {
      ar[i] = (int*)calloc(n, sizeof(int));
      temp = put_array(ar[i], temp, &count);
   }

   QueryPerformanceCounter(&start);
   slow_count = countOnesButSlow(ar, n);
   QueryPerformanceCounter(&end);
   diff.QuadPart = end.QuadPart - start.QuadPart;

   printf("n is 20,000 and version is slow_ver %d %d %.15lfsec\n", count, slow_count, (double)diff.QuadPart / (double)ticks.QuadPart);

   for (int i = 0; i < n; i++) {
      free(ar[i]);
   }
   free(ar);



   return 0;
}



int put_array(int* arr, int pre_one, int* count) { //배열에 1을 램덤하게 넣는 함수

   int min = pre_one * 0.9;//최솟값 설정
   int one = rand() % (pre_one - min + 1) + min;//랜덤한 범위 내의 값을 구함

   for (int i = 0; i < one; i++) {//1을 랜덤 배치
      arr[i] = 1;
      *count = *count + 1;//1의 개수 증가
   }

   return one;
}

int countOnesButSlow(int **X, int n) {//느린 방법으로 1의 개수를 count하는 함수

   int count = 0;

   for (int i = 0; i < n; i++) {//배열을 돌면서 1의 개수 카운트
      for (int j = 0; j < n; j++) {
         if (X[i][j] == 1) {
            count++;
         }
         else if (X[i][j] == 0) {//0을 만나면 탐색중인 행의 계산 중단
            break;
         }
      }
   }

   //printf("%d----------\n",count);
   return count;
}

int countOnes(int **X, int n) {//빠른 방법으로 1을 count하는 함수

   int i = 0, j = 0;
   int count = 0;

   while (i < n) {//배열을 돌면서 1의 개수 count
      if (X[i][j] == 1) {
         j++;
         count++;
      }
      if (X[i][j] == 0 || j == n) {//행의 끝에 도착하거나 0을 만나면 다음 행으로 이동
         i++;
         j = 0;
      }

   }
   //printf("%d—————\n",count);
   return count;

}

*/
