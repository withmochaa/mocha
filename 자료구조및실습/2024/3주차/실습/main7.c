#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)


int count(char *arr,int len, char ch);
int main(void){

    char arr[100];
    char ch;

    gets(arr);
    ch=getchar();

    printf("%d\n",count(arr,strlen(arr)-1,ch));




    return 0;
}

int count(char *arr,int len, char ch){
    if(len!=0){
        if(*(arr+strlen(arr)-1-len)==ch){
            return 1+count(arr,len-1,ch);
        }
        else{
            return 0+count(arr,len-1,ch);
        }
    }
    else{
        if(*(arr+strlen(arr)-1)==ch){
            return 1;
        }
        else{
            return 0;
        }
    }
}