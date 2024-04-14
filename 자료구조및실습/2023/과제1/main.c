#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int countOnesButSlow(int X[100][100],int n);
int countOnes(int X[100][100],int n);
int main(void){

    int N,A[100][100];
//
    scanf("%d",&N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&A[i][j]);
        }
    }
    /*
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            //printf("%d ",A[i][j]);
        }
        //printf("\n");
    }
    */
    int count1=0,count2=0;

    count1=countOnesButSlow(A,N);
    printf("%d\n",count1);
    count2=countOnes(A,N);
    printf("%d",count2);





    return 0;
}


int countOnesButSlow(int X[100][100],int n){
    
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

int countOnes(int X[100][100],int n){
    
    int count=0,i=0,j=0;

    while(i<n){
        if(X[i][j]==1){
            count++;
            j++;
        }
        if(j==n||X[i][j]==0){
            i++;
            j=0;
        }
       
    }

    return count;
}



