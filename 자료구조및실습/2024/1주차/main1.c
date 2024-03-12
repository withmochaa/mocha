#include <stdio.h>
#include <stdlib.h>

int sum(int n);

int main(){
    int a;
    int total=0;
    scanf("%d",&a);
    for(int i=1; i<=a; i++){
        total+=sum(i);
    }
    printf("%d", total);
    return 0;
}
int sum(int n){
    int total=0;
    for(int i=1; i<=n; i++){
        total+=i;
    }
    return total;
}

