#include<stdio.h>

int main(void){
    
    char A[21];

    for(char*i=A;i<A+21;i++){
        scanf("%c",i);

        if(*i=='#'){
            for(char*j=i-1;j>=A;j--){
                printf("%c",*j);
            }
            return 0;
        }
         
        
    }

}