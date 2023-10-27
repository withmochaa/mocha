#include <stdio.h>

int main(void){

    int x=10,y=10,z=33;

    x+=1;
    y*=2;
    z%=10+20;

    printf("%d %d %d\n",x,y,z);
    printf("%d",!-3);
    return 0;
}