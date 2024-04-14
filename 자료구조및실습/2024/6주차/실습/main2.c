#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// 다항식의 각 항을 표현하는 노드 구조체
typedef struct polynomial{

   int coef;
   int exp;
   struct polynomial *next;// 다음 항을 가리키는 포인터

}poly;

typedef struct listhead{// 다항식 리스트의 헤드를 가리키는 구조체

   poly *head;// 다항식의 첫 번째 항을 가리키는 포인터

}listhead;

// 리스트 초기화 함수
listhead* init(void){

   listhead* L;

   L = (listhead *)malloc(sizeof(listhead)); 

   L->head = NULL; // 초기화

   return L;
}

int addnode(listhead* L, int coef, int exp){// 다항식 리스트에 항을 추가하는 함수

   poly* newnode; 
   poly* p; 

   newnode = (poly *)malloc(sizeof(poly)); 
   newnode->coef = coef; 
   newnode->exp = exp; 
   newnode->next = NULL; 

   if(L->head == NULL){// 리스트가 비어있을 경우
      L->head = newnode;// 첫 번째 항으로 추가
      return;
   } 
   else{
      p = L->head; 
      while(p->next != NULL){// 마지막 항까지 이동
         p = p->next;
      } 
      p->next = newnode; // 새로운 항을 추가
   }
}

void addPoly(listhead* A, listhead* B, listhead* C){ // 두 다항식을 더하는 함수
    
   poly* pA = A->head; 
   poly* pB = B->head; 

   int sum; 

   while(pA && pB){ 

      if(pA->exp == pB->exp){ // 두 항의 지수가 같은 경우

         sum = pA->coef + pB->coef; // 계수를 더함

         if(sum != 0){// 결과가 0이 아닌 경우에만 항 추가
            addnode(C, sum, pA->exp); 
            pA=pA->next; 
            pB=pB->next;
         }
         else{
            pA=pA->next; 
            pB=pB->next;
         }
      } 
      else if(pA->exp > pB->exp){ // A의 항의 지수가 B보다 큰 경우
         addnode(C, pA->coef, pA->exp);// A의 항을 결과 다항식에 추가 
         pA=pA->next; 
      } 
      else{ // B의 항의 지수가 A보다 큰 경우
         addnode(C, pB->coef, pB->exp);// B의 항을 결과 다항식에 추가 
         pB=pB->next; 
      } 
   } 
   for( ; pA!=NULL; pA=pA->next){// 남은 항들을 결과 다항식에 추가
      addnode(C, pA->coef, pA->exp);
   } 
   for( ; pB!=NULL; pB=pB->next){ 
      addnode(C, pB->coef, pB->exp);
   }
}

void printPoly(listhead* L) {// 다항식 출력 함수

   poly* p = L->head; 

   for(;p;p=p->next){ 
      printf("%d %d ", p->coef, p->exp); 
   } 
}
int main(void){

   int N1, N2, coef, exp;
   listhead *A, *B, *C;
    // 리스트 초기화
   A = init();
   B = init();
   C = init();

   scanf("%d", &N1);

   for(int i=0;i<N1;i++){ // 첫 번째 다항식 입력 받기
      scanf("%d %d", &coef, &exp);
      addnode(A,coef,exp);
   }
   scanf("%d", &N2);
   for(int i=0;i<N2;i++){// 두 번째 다항식 입력 받기
      scanf("%d %d", &coef, &exp);
      addnode(B,coef,exp);
   }

   addPoly(A, B, C); // 두 다항식을 더하여 C에 저장
   printPoly(C);// 결과 다항식 출력
   printf("\n");


   return 0;
}