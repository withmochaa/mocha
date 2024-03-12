#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    char name[9];
    int score;
};
int main(){
    struct student s[5];
    int avr=0;
    for(int i=0;i<5;i++){
        scanf("%s %d", s[i].name, &s[i].score);
        avr += s[i].score;
    }
    avr /= 5;
    for(int i=0;i<5;i++){
        if(avr>=s[i].score){
            printf("%s\n", s[i].name);
        }
    }
}