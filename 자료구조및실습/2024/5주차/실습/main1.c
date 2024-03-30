#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

// 노드 구조체 정의
typedef struct node
{
   int elem;//노드의 정수 요소
   struct node *prev;//이진 노드를 향하는 포인터
   struct node *next;//다음 노드를 향하는 포인터
}X;

X *InitList();//이중 연결리스트를 초기화 하는 함수

void add(X *H, int r, char e);//이중 연결리스트에 요소를 추가하는 함수
void delete(X *H, int r);//이중 연결리스트에 요소를 삭제하는 함수
char get(X *H, int r);// 이중 연결리스트에서 특정 위치의 요소를 가져오는 함수
void print(X *H);//이중 연결리스트를 출력하는 함수

int main(void){

   X *H;

   int n, i, m;

   char x1, x2;

   H = InitList();

   scanf("%d", &n);
   getchar();

   for (i = 0; i < n; i++){
      scanf("%c", &x1);
      getchar();
      if (x1 == 'A'){//추가할 위치와 요소 입력
         scanf("%d %c", &m, &x2);
         getchar();
         add(H, m, x2);
      }     
      else if (x1 == 'D'){//삭제 할 위치 입력
         scanf("%d", &m);
         getchar();
         delete(H, m);
      }
      else if (x1 == 'G')//가져올 위치 입력
      {
         scanf("%d", &m);
         x2 = get(H, m);
         if (x2 != NULL){
            printf("%c\n", x2);
            getchar();
         }
         else
            getchar();
      }
      else if (x1 == 'P'){//리스트 출력
        print(H);
      }
      else
         continue;

   }

   return 0;
}

X *InitList(){

   X *H, *T;

   H = (X *)malloc(sizeof(X));//헤드와 테일 노드에 메모리 할당
   T = (X *)malloc(sizeof(X));

   H->prev = NULL;//헤드와 테일 노드 초기화
   T->next = NULL;
   H->next = T;
   T->prev = H;

   return H;
}

void add(X *H, int r, char e){

   int i;

   X *newnode, *p, *pprev;

   p = H;

   newnode = (X *)malloc(sizeof(X));//헤드와 테일 노드에 메모리 할당
   newnode->elem = e;

   for (i = 0; i < r; i++){//지정 위치로 이동

      p = p->next;

      if (p == NULL){

         printf("invalid position\n");
         free(newnode);

         return;
      }
   }
    //
   pprev = p->prev;
   newnode->next = p;
   newnode->prev = pprev;
   pprev->next = newnode;
   p->prev = newnode;

   return;
}

void delete(X *H, int r){

   int i;
   X *p, *pprev, *pnext;
   p = H;

   for (i = 0; i < r; i++){
      p = p->next;//지정 위치로 이동
      if (p->next == NULL){
         printf("invalid position\n");
         return;
      }
   }

   pprev = p->prev;
   pnext = p->next;
   pprev->next = pnext;
   pnext->prev = pprev;
   free(p);

}

char get(X *H, int r){

   int i;
   X *p;
   p = H;

   for (i = 0; i < r; i++){
      p = p->next;
      if (p->next == NULL){
         printf("invalid position\n");
         return NULL;
      }
   }
   return p->elem;
}

void print(X *H){
   X *p;
   p = H->next;

   while (p->next != NULL){
      printf("%c", p->elem);//모든 노드의 요소 출력
      p = p->next;
   }

   printf("\n");

   return;
}