#include<stdio.h>

int main(){
    char st[100];
    char temp;
    gets(st);
    printf("%s\n", st);
    for(int i=0;i<strlen(st)-1;i++){
        temp = st[0];
        for(int i=0;i<strlen(st);i++){
            if(st[i+1]!=NULL){
                st[i] = st[i+1];
            }
            else
                st[i] = temp;
        }
        printf("%s\n", st);
    }
}