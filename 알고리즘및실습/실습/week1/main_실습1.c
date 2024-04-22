#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//순위는 1부터 시작한다고 가정한다

typedef struct NODE {
    struct NODE *prev, *next;//이중 연결 리스트, 다음 노드의 주소를 저장할 포인터 선언
    char data;//데이터를 저장할 멤버 선언
}node;

typedef struct list {
    node *h, *t;//머리노드, 끝 노드 선언, 이 두 노드는 데이터를 저장하지 않음 
    int pos;
}list;


void init(list *ar){
    node *H, *T;

    H = (node *)malloc(sizeof(node));// 동적할당
    T = (node *)malloc(sizeof(node));
    
    ar->h = H;
    ar->t = T;

    H->prev = NULL;
    H->next = T;
    T->next = NULL;
    T->prev = H;   

    ar->pos = 2;
}

// 함수 정의
void add(list *L);
void delete(list *L);
void get(list *L);
void print(list *L);

int main(void){

    int n;
    scanf("%d\n", &n);
    char ch;
    
    list *X = (list *)malloc(sizeof(list)); //동적할당

    init(X);

    for (int i = 0;i < n ;i ++){
        scanf("%c", &ch);
        getchar();

        if(ch == 'A'){
            add(X);
        } 
        else if(ch == 'D'){
            delete(X);
        }
        else if(ch == 'G') {
            get(X);
        }
        else if(ch == 'P'){
            print(X);
        }
    }

    return 0;
}

void add(list* L) {
    
    int sco;
    char new;

    scanf("%d %c", &sco, &new);
    getchar();

    if ((L->pos) - 1 < sco) {
        printf("invalid position\n");
        return;
    }

    node* tmp = L->h;
    node *newnode;
    newnode = (node *)malloc(sizeof(node));

    newnode->data= new;

    for(int i = 0; i < sco; i++){
        tmp = tmp->next;
    }

    newnode->next = tmp;
    newnode->prev = tmp->prev;
    tmp->prev->next = newnode;
    tmp->prev = newnode;

    (L->pos)++;
    return;

}

void delete(list *L){

    int rank; //지울 번호 선언

    scanf("%d", &rank);
    getchar();
    
    if ((L->pos)-2 < rank){
        printf("invalid position\n");
        return;
    }
    
    node *tmp = L->h;

    for (int i = 0;i < rank; i ++){
        tmp = tmp->next;
    }//지우려는 노드의 위치를 tmp로 옮김
    
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;

    free(tmp); //free로 매모리 해제

    (L->pos)--; 
    return;
}   

void get(list *L){

    node *tmp = L->h;
    int sco;
    scanf("%d", &sco);
    getchar();

    if ((L->pos) - 2 <sco){
        printf("invalid position\n");
        return;
    }

    for(int i = 0;i < sco; i ++){
        tmp = tmp->next;
    }

    printf("%c\n", tmp->data);

    return;
}   

void print(list *L){
    node *tmp = L->h;

    for(int i = 0; i < (L->pos)-2; i++){
        tmp = tmp->next;
        printf("%c", tmp->data);
    }
    printf("\n");
    return;
}