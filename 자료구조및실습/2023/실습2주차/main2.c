#include<stdio.h>

int mostOnes(int A[100][100],int n);
int main(void){

    int N,A[100][100];

    scanf("%d",&N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&A[i][j]);
            //printf("%d ",A[i][j]);
        }
        //printf("\n");
    }

    int output=mostOnes(A,N);

    printf("%d ",output);


    return 0;
}

int mostOnes(int A[100][100],int n){

    //printf("%d",n);
    int max=0;
    int row=0;
    int count=0;
    for(int i=0,j=0;i<n;){

        if(A[i][j]==1){
            count++;
            j++;
        }
        else{
            //printf("%d\n",count);
            j=0;
            if(max<count){
                row=i;
                max=count;
            }
            count=0;
            i++;
        }

    
    }
    return row;
}