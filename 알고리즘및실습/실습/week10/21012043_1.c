#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int i;
    struct node* next;
} node;

typedef struct vertices {
    struct node* L;
    int N;
} ver;

typedef struct edges {
    int v1, v2;
    int W;
} edg;

// 간선이 이미 존재하는지 확인하는 함수
int exist(edg E[], ver V[], int a, int b, int cnt);

// 간선을 제거하는 함수
void remove_edg(edg E[], ver V[], int tmp, int cnt);

// 간선을 생성하는 함수
void make_edg(edg E[], ver V[], int a, int b, int w, int cnt);

// 특정 정점과 연결된 간선 정보 출력 함수
void print(edg E[], ver V[], int a);

// 초기 그래프 설정 함수
void init(ver V[], edg E[]);

int main() {
    ver V[6];
    edg E[21] = { 0 };
    init(V, E);

    char order;
    int a, b, w;
    int cnt = 8, tmp;

    while (1) {
        scanf("%c", &order);
        if (order == 'a') {
            scanf("%d", &a);
            if (a < 1 || a > 6)
                printf("-1\n");
            else
                print(E, V, a);
        }
        else if (order == 'm') {
            scanf("%d %d %d", &a, &b, &w);
            if (a > b) {
                tmp = a;
                a = b;
                b = tmp;
            }

            if (a < 1 || a > 6 || b < 1 || b > 6) {
                printf("-1\n");
                getchar();
                continue;
            }

            tmp = exist(E, V, a, b, cnt);
            if (tmp) {
                if (w == 0) {
                    remove_edg(E, V, tmp - 1, cnt);
                    cnt--;
                }
                else {
                    E[tmp - 1].W = w;
                }
            }
            else {
                if (w == 0) {
                    printf("-1\n");
                    getchar();
                    continue;
                }
                make_edg(E, V, a, b, w, cnt);
                cnt++;
            }
        }
        else
            break;
        getchar();
    }

    // 그래프 메모리 해제 함수 호출
    Free(V);

    return 0;
}

// 간선이 이미 존재하는지 확인하는 함수
int exist(edg E[], ver V[], int a, int b, int cnt) {
    for (int i = 0; i < cnt; i++)
        if (V[E[i].v1].N == a && V[E[i].v2].N == b)
            return i + 1;
    return 0;
}

// 간선을 제거하는 함수
void remove_edg(edg E[], ver V[], int idx, int cnt) {
    edg e = E[idx];
    node* p, * q;

    p = V[e.v1].L;
    while (p) {
        q = p->next->next;
        if (p->next->i == idx) {
            free(p->next);
            p->next = q;
            break;
        }
        p = p->next;
    }

    if (e.v1 != e.v2) {
        p = V[e.v2].L;
        while (p) {
            q = p->next->next;
            if (p->next->i == idx) {
                free(p->next);
                p->next = q;
                break;
            }
            p = p->next;
        }
    }

    for (int i = 0; i < 6; i++) {
        p = V[i].L->next;
        while (p) {
            if (p->i > idx)
                p->i -= 1;
            p = p->next;
        }
    }

    for (int i = idx + 1; i < cnt; i++)
        E[i - 1] = E[i];
}

// 간선을 생성하는 함수
void make_edg(edg E[], ver V[], int a, int b, int w, int cnt) {
    ver A = V[a - 1], B = V[b - 1];
    node* p = A.L, * q = B.L;
    node* new1 = (node*)calloc(1, sizeof(node));
    new1->i = cnt;

    E[cnt].v1 = a - 1;
    E[cnt].v2 = b - 1;
    E[cnt].W = w;

    while (p->next)
        p = p->next;
    p->next = new1;

    if (a == b)
        return;

    node* new2 = (node*)calloc(1, sizeof(node));
    new2->i = cnt;

    while (q->next)
        q = q->next;
    q->next = new2;
}

// 특정 정점과 연결된 간선 정보 출력 함수
void print(edg E[], ver V[], int a) {
    int N[6], w[6], cnt = 0, tmp;
    node* p = V[a - 1].L->next;
    edg e;

    while (p != NULL) {
        e = E[p->i];
        tmp = V[e.v1].N;
        if (tmp == a)
            tmp = V[e.v2].N;

        N[cnt] = tmp;
        w[cnt] = e.W;
        p = p->next;
        cnt++;
    }

    for (int i = 0; i < cnt; i++)
        for (int j = i + 1; j < cnt; j++)
            if (N[i] > N[j]) {
                tmp = N[i];
                N[i] = N[j];
                N[j] = tmp;
                tmp = w[i];
                w[i] = w[j];
                w[j] = tmp;
            }

    for (int i = 0; i < cnt; i++)
        printf(" %d %d", N[i], w[i]);
    printf("\n");
}

// 초기 그래프 설정 함수
void init(ver V[], edg E[]) {
    for (int i = 0; i < 6; i++) {
        V[i].N = i + 1;
        V[i].L = (node*)calloc(1, sizeof(node));
    }

    // 초기 간선 정보 설정
    E[0].v1 = 0, E[0].v2 = 1, E[0].W = 1;
    E[1].v1 = 0, E[1].v2 = 2, E[1].W = 1;
    E[2].v1 = 0, E[2].v2 = 3, E[2].W = 1;
    E[3].v1 = 0, E[3].v2 = 5, E[3].W = 2;
    E[4].v1 = 1, E[4].v2 = 2, E[4].W = 1;
    E[5].v1 = 2, E[5].v2 = 4, E[5].W = 4;
    E[6].v1 = 4, E[6].v2 = 4, E[6].W = 4;
    E[7].v1 = 4, E[7].v2 = 5, E[7].W = 3;

    node* p;
    for (int i = 0; i < 8; i++) {
        p = V[E[i].v1].L;
        while (p->next != NULL)
            p = p->next;
        p->next = (node*)calloc(1, sizeof(node));
        p->next->i = i;

        if (E[i].v1 == E[i].v2)
            continue;

        p = V[E[i].v2].L;
        while (p->next != NULL)
            p = p->next;
        p->next = (node*)calloc(1, sizeof(node));
        p->next->i = i;
    }
}

// 그래프 메모리 해제 함수
void Free(ver V[]) {
    node* p, * q;
    int i;
    for (i = 0; i < 6; i++) {
        p = V[i].L;
        while (p) {
            q = p->next;
            free(p);
            p = q;
        }
    }
}
