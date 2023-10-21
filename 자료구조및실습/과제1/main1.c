#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int countOnesButSlow(int **X,int n);
int countOnes(int **X,int n);

int main(void){

    int **A=NULL,N;

    scanf("%d",&N);
// 비트 행렬 A에 동적 할당
    A=(int**)malloc(N*sizeof(int*));

    for(int i=0;i<N;i++){
        A[i]=(int*)malloc(N*sizeof(int));
    }


    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&A[i][j]);
        }
    }

    int count_slow=0,count_fast=0;

    count_slow=countOnesButSlow(A,N);
    count_fast=countOnes(A,N);
    
    printf("%d\n",count_slow);
    printf("%d",count_fast);

    for(int i=0;i<N;i++){
        free(A[i]);
    }

    free(A);



    return 0;
}

int countOnesButSlow(int **X,int n){

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(X[i][j]==1){
                count++;
            }
            else if(X[i][j]==0){
                break;
            }
        }
    }

   
    return count;
}


int countOnes(int **X,int n){

    int i=0,j=0;
    int count=0;
    while(i<n){

        if(X[i][j]==1){
            j++;
            count++;
        }
        if(X[i][j]==0||j==n){
            i++;
            j=0;
        }

    }
     //printf("%d----------\n",count);
    return count;

}