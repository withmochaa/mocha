#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) 

// 배열에서 최댓값을 찾는 함수
int find_max(int n, int arr[]);

int main(void){

    int n, max, arr[20];

    // 배열 크기 입력 받기
    scanf("%d", &n);

    // 배열 요소 입력 받기
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // 최댓값 찾기
    max = find_max(n - 1, arr);

    // 최댓값 출력
    printf("%d", max);

    return 0;
}

// 재귀적으로 배열에서 최댓값을 찾는 함수
int find_max(int n, int arr[]){
    int max;

    // 기저 사례: 배열의 첫 번째 요소일 때는 그대로 반환
    if(n == 0){
        return arr[n];
    }

    // n-1까지의 배열에서 최댓값을 찾음
    max = find_max(n - 1, arr);

    // 현재 요소와 비교하여 더 큰 값을 반환
    if(max < arr[n]){
        return arr[n];
    }
    else{
        return max;
    }
}
