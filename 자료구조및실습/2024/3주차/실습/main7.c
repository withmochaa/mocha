#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996) 

// 문자열에서 특정 문자가 나타나는 횟수를 세는 함수
int count(char *arr, int len, char ch);

int main(void){
    char arr[100];
    char ch;

    // 사용자로부터 문자열과 찾을 문자 입력 받기
    gets(arr);
    ch = getchar();

    // 함수 호출하여 문자열에서 특정 문자가 나타나는 횟수 출력
    printf("%d\n", count(arr, strlen(arr) - 1, ch));

    return 0;
}

// 재귀적으로 문자열에서 특정 문자가 나타나는 횟수를 세는 함수
int count(char *arr, int len, char ch){
    if(len != 0){
        if(*(arr + strlen(arr) - 1 - len) == ch){
            // 현재 문자가 찾는 문자와 일치할 경우 1을 더하고 다음 문자로 이동
            return 1 + count(arr, len - 1, ch);
        }
        else{
            // 현재 문자가 찾는 문자와 일치하지 않을 경우 0을 더하고 다음 문자로 이동
            return 0 + count(arr, len - 1, ch);
        }
    }
    else{
        // 문자열의 마지막에 도달하면 해당 문자가 찾는 문자와 일치하는지 확인하여 반환
        if(*(arr + strlen(arr) - 1) == ch){
            return 1;
        }
        else{
            return 0;
        }
    }
}
