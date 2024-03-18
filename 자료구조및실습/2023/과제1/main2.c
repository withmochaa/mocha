
/*
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


int put_array(int* arr, int pre_one, int* count);
int countOnesButSlow(int **X,int n);
int countOnes(int **X,int n);


int main(void) {

   LARGE_INTEGER start = { 0 }, end = { 0 }, diff = { 0 }, ticks = { 0 };
   int** ar = NULL, n, temp = 0, count = 0, slow_count = 0, fast_count = 0;

   QueryPerformanceFrequency(&ticks);

   n = 30000; //n is 30000 and fas_ver
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

   for (int i = 0; i < n; i++){
      free(ar[i]);
   }
   free(ar);

   n = 10000; // n is 10000 and fas_ver
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

   n = 20000; // n is 20000 and fast_ver
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

   n = 30000; // n is 30000 and slow_ver
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

   n = 10000; // n is 10000 and slow_ver
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

   n = 20000; // n is 20000 slow_ver
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

   printf("n is 20,000 and version is slow_ver %d %d %.15lfsec\n", count, slow_count, (double)diff.QuadPart / (double)ticks.QuadPart);

   for (int i = 0; i < n; i++) {
      free(ar[i]);
   }
   free(ar);



   return 0;
}



int put_array(int* arr, int pre_one, int* count) { 

   int min = pre_one * 0.9;
   int one = rand() % (pre_one - min + 1) + min;
   for (int i = 0; i < one; i++) {
      arr[i] = 1;
      *count=*count+1;
   }
   
   return one;
}

int countOnesButSlow(int **X,int n){

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(X[i][j]==1){
                count++;
            }
            else if(X[i][j]==0){
                break;
            }
        }
    }

   //printf("%d----------\n",count);
    return count;
}

int countOnes(int **X,int n){

    int i=0,j=0;
    int count=0;
    while(i<n){

        if(X[i][j]==1){
            j++;
            count++;
        }
        if(X[i][j]==0||j==n){
            i++;
            j=0;
        }

    }
     //printf("%d----------\n",count);
    return count;

}


*/

