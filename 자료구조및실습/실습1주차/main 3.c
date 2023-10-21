#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*실습 문제 1번


int sum(int n);

int main(void){

    int X;

    scanf("%d",&X);

    printf("%d",sum(X));

	
	return 0;
}

int sum(int n){

    int sum=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            sum+=j;
        }
    }



    return sum;
}

*/

/*
실습문제 2번

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

    for(int i=k;i<10;i++){
       if(A[k]<A[i]){
        int c;
        c=*(A+k);
        *(A+k)=*(A+i);
        *(A+i)=c;
       }

           

        }
}

// 실습 2 수정

/*
#include<stdio.h>

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

/*
 실습문제 3번


void swap(int *a,int *b);
int main(void){

    int N,*p,num[50],a,b;

    scanf("%d",&N);

    for(p=num;p<num+N;p++){
        scanf("%d",p);
    }

    scanf("%d %d",&a,&b);

    swap(num+a,num+b);

    for(p=num;p<num+N;p++){
        printf(" %d",*p);
    }

    return 0;
}

void swap(int *a,int *b){

    int c;
    
    c=*a;
    *a=*b;
    *b=c;

}



*/


// 실습문제 4

/*
int main(void){

    char A[101]={'\0'},*p;

    gets(A);

    int num=0;

    num=strlen(A);

   for(int i=0;i<num;i++){
        printf("%s\n",A+i);
        *(A+num+i)=*(A+i);
   }




    return 0;
}

*/

//4번 오답노트

/*int main(void){

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
}*/



// 실습문제 5번

/*
typedef struct{
    int hour;
    int minute;
    int sec;
    int sum;
}time;

int main(void){

    time A[2],*p=A;

    for(int i=0;i<2;i++){
        scanf("%d %d %d",&(p+i)->hour,&(p+i)->minute,&(p+i)->sec);
        (p+i)->sum=60*60*(p+i)->hour+(p+i)->minute*60+(p+i)->sec;
        //printf("%d\n",(p+i)->sum);
    }

    int hour,minute,sec,sum;

    sum=(p+1)->sum-(p)->sum;

    hour=sum/3600;

    sum=sum-hour*3600;

    minute=sum/60;

    sum=sum-minute*60;

    sec=sum;

    printf("%d %d %d",hour,minute,sec);



    return 0;
}


*/

// 6번


/*
typedef struct{

    char name[10];
    int sco;

}info;

int main(void){

    info A[5],*p=A;

    int sum=0;
    for(int i=0;i<5;i++){
        scanf("%s %d",&(p+i)->name,&(p+i)->sco);
        
        sum+=(p+i)->sco;

       // printf("%s %d\n",(p+i)->name,(p+i)->sco);
    }

   double ave;

   ave=sum/5.0;

    for(int i=0;i<5;i++){
        if(ave>=(p+i)->sco){
            printf("%s\n",(p+i)->name);
        }
    }


    return 0;
}


*/


// 7번


/*
int main(void){


    int N,*A,*B;

    scanf("%d",&N);

    A=(int*)malloc(N*sizeof(int));
    B=(int*)malloc(N*sizeof(int));

    if(A==NULL||B==NULL){
        return 0;
    }

    for(int i=0;i<N;i++){
        scanf("%d",A+i);
       // printf("%d",*(A+i));
    }

    for(int i=0;i<N;i++){
        scanf("%d",B+i);
    }

    int sum=0;

    for(int i=0;i<N;i++){
        sum=*(A+i)+*(B+N-1-i);

        printf(" %d",sum);
    }

    free(A);
    free(B);


    return 0;
}

*/
//7번
typedef struct{
    char name[7];
    int kor;
    int eng;
    int math;
    double ave;

}student;


int main(void){

    student* X;

    int N;

    scanf("%d",&N);

    X=(student*)malloc(N*sizeof(student));
    //printf("%d",sizeof(X));
    if(X==NULL){
        return 0;
    }

    for(int i=0;i<N;i++){
        scanf("%s %d %d %d",(X+i)->name,&(X+i)->kor,&(X+i)->eng,&(X+i)->math);
        (X+i)->ave=((X+i)->kor+(X+i)->eng+(X+i)->math)/3.0;
       // printf("%.1lf\n",(X+i)->ave);
    }
    
    for(int i=0;i<N;i++){
        int count_high=0,count_low=0,count_both=0;

        if((X+i)->kor>=90 || (X+i)->eng>=90 || (X+i)->math>=90){
            count_high=1;
        }
        if((X+i)->kor<70 || (X+i)->eng<70 || (X+i)->math<70){
            count_low=1;
        }

        if(count_high==1 && count_low==0){
            printf("%s %.1lf GREAT",(X+i)->name,(X+i)->ave);
        }
        else if(count_high==0 && count_low==1){
            printf("%s %.1lf BAD",(X+i)->name,(X+i)->ave);
        }
        else if(count_high==1 && count_low==1){
            printf("%s %.1lf GREAT BAD",(X+i)->name,(X+i)->ave);
        }
        printf("\n");
    }

    free(X);



    return 0;
}