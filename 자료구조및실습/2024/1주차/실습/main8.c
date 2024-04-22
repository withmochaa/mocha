#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    char name[7];
    int kor;
    int mat;
    int eng;
    double ave;
};
int main(){
    struct student *p;
    int n;
    scanf("%d", &n);
    p = (struct student*)malloc(sizeof(struct student)*n);
    for(int i=0; i<n; i++){
        scanf("%s %d %d %d", p[i].name, &p[i].kor, &p[i].mat, &p[i].eng);
        p[i].ave = (double)(p[i].kor + p[i].mat + p[i].eng)/3;
    }
    for(int i=0; i<n; i++){
        printf("%s %.1f", p[i].name, p[i].ave);
        if(p[i].kor>=90||p[i].mat>=90||p[i].eng>=90)
            printf(" GREAT");
        if(p[i].kor<70||p[i].mat<70||p[i].eng<70)
            printf(" BAD");
        printf("\n");
    }
    free(p);
    return 0;
}