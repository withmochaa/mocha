#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct time{
    int h;
    int m;
    int s;
};

int main(){
    struct time a, b, c;

    scanf("%d %d %d", &a.h, &a.m, &a.s);
    scanf("%d %d %d", &b.h, &b.m, &b.s);

    if (b.h - a.h == 0)
        c.h = 0;
    else
        c.h = b.h - a.h;
    if (b.m - a.m < 0){
        c.h--;
        b.m += 60;
        c.m = b.m - a.m;
    }
    else
        c.m = b.m - a.m;
    if (b.s - a.s < 0){
        c.m--;
        b.s += 60;
        c.s = b.s - a.s;
    }
    else
        c.s = b.s - a.s;
    printf("%d %d %d", c.h, c.m, c.s);
}