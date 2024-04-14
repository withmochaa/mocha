#include <stdio.h>
#include <stdlib.h>


// 실습 1번

/*
void swap(int* a,int* b);
void flip(int *start, int* end);
int main(void){


    int N,*A=NULL;

    scanf("%d",&N);
    
    int init_num=N;

    A=(int*)malloc(N*sizeof(int));

    if(A==NULL){
        return 0;
    }

    for(int i=0;i<N;i++){
        scanf("%d",A+i);
    }

    scanf("%d",&N);

    int a,b;

    for(int i=0;i<N;i++){
        scanf("%d %d",&a,&b);
        flip(A+a,A+b);
    }

    for(int i=0;i<init_num;i++){
        printf(" %d",*(A+i));
    }

    free(A);

    return 0;
}

void flip(int *start, int* end){

    int num=end-start+1;

    if(num%2==0){// reverse period is even
        for(int i=0;i<num/2;i++){
            swap(start+i,end-i);
        }
    }
    else{ // reverse period is odd
        for(int i=0;i<num/2;i++){
            swap(start+i,end-i);
        }
    }



}


void swap(int* a,int* b){

    int tmp;

    tmp=*a;
    *a=*b;
    *b=tmp;
}

*/

/*
//2번
int main(void){

   int N,*X=NULL,*Y;

   scanf("%d",&N);

   X=(int*)malloc(N*sizeof(int));

   if(X==NULL){
    return 0;
   }

    for(int i=0;i<N;i++){
        scanf("%d",X+i);
    }
    int N2;

    scanf("%d",&N2);

    Y=(int*)malloc(N2*sizeof(int));

    for(int i=0;i<N2;i++){
        scanf("%d",(Y+i));
    }

    int tmp=*(X+Y[0]);
    int c;
    
    for(int i=0;i<N2-1;i++){
        for(int i=0;i<N;i++){
        //printf(" %d",*(X+i));
    }
    //printf("\n");
    
        c=*(X+Y[i+1]);
        *(X+Y[i+1])=tmp;
        tmp=c;

    }

    for(int i=0;i<N;i++){
        printf(" %d",*(X+i));
    }

    free(X);
    free(Y);

    return 0;
}

*/

//3번


/*
int main(void){

    int N,**X=NULL;

    scanf("%d",&N);

    X=(int**)calloc(N,sizeof(int*));


    for(int i=0;i<N;i++){
        X[i]=(int*)calloc(N,sizeof(int));
    }

    int count=1;

    for(int i=0;i<N;i++){
        if(i%2==0){
            for(int j=0;j<N;j++){
                X[i][j]=count;
                count++;
            }
            count=count+N-1;
        }
        else{
            for(int j=0;j<N;j++){
                X[i][j]=count;
                count--;
            }
            count=count+N+1;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf(" %d",X[i][j]);
        }printf("\n");
    }


    for(int i=0;i<N;i++){
        free(X[i]);
    }

    free(X);


    return 0;
}

*/

//4번


/*
int main(void){

    int **X;        
    
    int N,M;

    scanf("%d %d",&N,&M);

    X=(int**)calloc(N,sizeof(int*));

    for(int i=0;i<N;i++){
        X[i]=(int*)calloc(M,sizeof(int));
    }
    int i,j;
    int step=1;


    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            X[i][j]=0;
        }
    }

    i=0,j=0,X[0][0]=1;
    

    for(step=2;step<=N*M;){
        
        while(j+1<M && X[i][j+1]==0){
            j++;
            X[i][j]=step;
            step++;
        }

        while(i+1<N && X[i+1][j]==0){
            i++;
            X[i][j]=step;
            step++;
        }

        while(j-1>=0 && X[i][j-1]==0){
            j--;
            X[i][j]=step;
            step++;
        }

        while(i-1>=0 && X[i-1][j]==0){
            i--;
            X[i][j]=step;
            step++;
        }
    }

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf(" %d",X[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<N;i++){
        free(X[i]);
    }

    free(X);

    return 0;
}


*/



/*
int main(void){

    int N=0,M=0,num,i=0,j=0,x=0,y=0;
    int **X=NULL;

    scanf("%d %d",&N,&M);

    X=(int**)calloc(N,sizeof(int*));

    for(i=0;i<N;i++){
        X[i]=(int*)calloc(M,sizeof(int));
    }

    for(num=1;num<=N*M;){
        i=y,j=x;

        while(1){

            X[i][j]=num;
            num++;

            if(i==N-1 || j==0){
                break;
            }
            else{
                i++;
                j--;
            }
        }
        if(x<M-1){
            x++;
        }
        else{
            y++;
        }
    }
    
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            printf(" %d",X[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<N;i++){
        free(X[i]);
    }

    free(X);


    return 0;
}


*/


int main(void){

    int N,X[50],num=0;
    while(1){

        scanf("%d",&N);

        if(N==0){
            break;
        }

    X[num]=N;
    num++;
    
    }
    int len=1,max=0,start=0,count=0;
    for(int i=0;i<num-1;i++){
        if(X[i]%2==0){
            count++;
        }
        if(X[i]%2==0 && X[i+1]%2==0){
            len++;
            start=i;
        }
        else{
            if(max<len){
                max=len;
            }
        }
    }

    if(count==0){
        printf("NO");
        return 0;
    }


    return 0;
}