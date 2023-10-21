#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
void ABC(int A[],int k);
int main(void){

    int num[10],*p,*q;


    for(p=num;p<num+10;p++){
        scanf("%d",p);
    }

    for(int i=0;i<10;i++){
        ABC(num,i);
    }
    


     for(p=num;p<num+10;p++){
        printf(" %d",*p);
    }


    return 0;
}

void ABC(int A[],int k){

    int max=A[k];
    int index=k;
    for(int i=k;i<10;i++){
       if(max<A[i]){
        max=A[i];
        index=i;
       }
    }
    int c=*(A+k); //시작 값
    *(A+k)=max;
    *(A+index)=c;

    
}

*/

int main(void){

    char A[101],*p;

    scanf("%s",A);

    int num=0;

    num=strlen(A);

    char tmp,tmp0;
   for(int i=0;i<num;i++){
        printf("%s\n",A);
        tmp0=A[0];
        for(int j=0;j<num-1;j++){
            tmp=A[j];
            A[j]=A[j+1];
            A[j+1]=tmp;
            //printf("%s\n",A);
        }
        //A[num-1]=tmp0;
   }




    return 0;
}