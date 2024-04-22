#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)


int modulo(int *a,int *b) {
    
   while (*a >= *b) {//a가 b의 값보다 클 경우 반복문 진행
      *a = *a - *b;//a의 값을 a에서 b의 값을 뺀 것으로 반복
      if (*a < *b)//a가 b보다 작아지면 break
         break;
   }
   return *a;
} 


int main(void) {
   int a, b;//정수 a와 b를 선언

   scanf("%d %d", &a, &b);

   int min=modulo(&a, &b);//a와 b의 주소를 module함수에 전달하고 반환값을 min으로 받음
   printf("%d", min);

   return 0;
}