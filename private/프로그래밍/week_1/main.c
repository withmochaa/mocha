#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main(void) {
   char ch;
   int a, b;
   printf("수식 입력:");
   scanf("%d %c %d", &a, &ch, &b);
   if (ch == '+') {
      printf("%d %c %d = %d", a, ch, b, a + b);
   }
   else if (ch == '-') {
      printf("%d %c %d = %d", a, ch, b, a - b);
   }
   else if (ch == '*') {
      printf("%d %c %d = %d", a, ch, b, a * b);
   }
   else if (ch == '/') {
      printf("%d %c %d = %d", a, ch, b, a / b);
   }
   else {
      printf("연산불가능");
   }
   return 0;
}