#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//실습 1번

/*
int modulo(int a,int b);

int main(void){

    int a,b;

    scanf("%d %d",&a,&b);

    int output;

    output=modulo(a,b);

    printf("%d",output);




    return 0;
}

int modulo(int a,int b){

    int sum=a;

    while(1){
        if(sum-b<0){
            break;
        }

        sum=sum-b;
        //printf("%d\n",sum);
    }

    return sum;

}

*/


//2 번


/*
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
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(A[i][j]==1){
                count++;
            }
            
    }
        if(max<count){
            row=i;
            max=count;
        }
    }
    return row;
}


*/
//실습 2번 실습 오답

/*
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

*/


/*

*/
//실습 3-1

/*
int* prefixAverages1(int* A,int n);
int* prefixAverages2(int* A,int n);

int main(void){
    
    int N,*X,*A,*B;

    scanf("%d",&N);

    X=(int*)malloc(N*sizeof(int));
    A=(int*)malloc(N*sizeof(int));
    B=(int*)malloc(N*sizeof(int));
    if(X==NULL||A==NULL||B==NULL){

        return 0;
    }
    
    for(int*i=X;i<X+N;i++){
        scanf("%d",i);
        //printf("%d ",*i);
    }
    A=prefixAverages1(X,N);
    B=prefixAverages2(X,N);
    
    for(int i=0;i<N;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
    
    for(int i=0;i<N;i++){
        printf("%d ",B[i]);
    }
    
    free(X);
    free(A);
    free(B);
    return 0;
}

int* prefixAverages1(int* A,int n){
    int *X;

    X=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=0;j<=i;j++){
            sum=sum+A[j];
        }
        X[i]=(int)((sum/(i+1))+0.5);
        //printf("%.0lf ",sum);
    }//printf("\n");

    return X;
}

int* prefixAverages2(int* A,int n){
    int *X;

    X=(int*)malloc(n*sizeof(int));
   double sum=0;
   for(int i=0;i<n;i++){
    X[i]=(int)((A[i]+sum)/(i+1)+0.5);
    sum=sum+A[i];
    //printf("%.0lf ",sum);
   }
   //printf("\n");

    return X;
}

*/
//실습 3-2


/*
int* prefixAverages1(int* A,int n);
int* prefixAverages2(int* A,int n);

int main(void){
    
    int N,*X,*A,*B;
    LARGE_INTEGER ticksPerSec; 
    LARGE_INTEGER start, end, diff;
    scanf("%d",&N);

    X=(int*)malloc(N*sizeof(int));
    A=(int*)malloc(N*sizeof(int));
    B=(int*)malloc(N*sizeof(int));
    if(X==NULL||A==NULL||B==NULL){

        return 0;
    }
    
    for(int*i=X;i<X+N;i++){
        *i=rand() % 10000 + 1;
        //printf("%d ",*i);
    }
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    A=prefixAverages1(X,N);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    

    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    B=prefixAverages2(X,N);
    QueryPerformanceCounter(&end);
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart));
    
    
    
    
    
    
    free(X);
    free(A);
    free(B);
    return 0;
}

int* prefixAverages1(int* A,int n){
    int *X;

    X=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        double sum=0;
        for(int j=0;j<=i;j++){
            sum=sum+A[j];
        }
        X[i]=(int)((sum/(i+1))+0.5);
        //printf("%.0lf ",sum);
    }//printf("\n");

    return X;
}

int* prefixAverages2(int* A,int n){
    int *X;

    X=(int*)malloc(n*sizeof(int));
   double sum=0;
   for(int i=0;i<n;i++){
    X[i]=(int)((A[i]+sum)/(i+1)+0.5);
    sum=sum+A[i];
    //printf("%.0lf ",sum);
   }
   //printf("\n");

    return X;
}



*/