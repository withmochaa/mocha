#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) 



int main(void){

    int x, y, a, b, c, tmp, N[100]; 

    scanf("%d", &x); 

    for(int i=0; i<x; i++){ 
        scanf("%d", &N[i]);
    }

    scanf("%d", &y); // 반전할 구간의 개수를 입력 받음

    for(int i=0; i<y; i++){ // 반전할 구간들에 대한 반복문

        scanf("%d %d", &a, &b); // 반전할 구간의 시작 인덱스(a)와 길이(b)를 입력 받음

        c = b; // c에 반전할 구간의 끝 인덱스를 저장

        // 반전 구간의 시작부터 중간까지를 반전시키는 반복문
        for(int j=a; j<=(a+b)/2; j++){
            tmp = N[j]; // 임시 변수를 사용하여 요소를 교환
            N[j] = N[c]; // 반전할 구간의 끝부터 순차적으로 요소를 바꿔나감
            N[c] = tmp;
            c--; // 반전할 구간의 끝에서부터 한 칸씩 앞으로 이동
        }
    }
    
    // 출력
    for(int i=0; i<x; i++){
        printf(" %d", N[i]);
    }

    return 0; 
}