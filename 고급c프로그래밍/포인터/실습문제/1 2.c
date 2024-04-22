#include<stdio.h>

int main(void){
    int x, y, z;
    int *px, *py, *pz, *tmp ; // tmp는 포인터이다


    px=&x;
    py=&y;
    pz=&z;

    scanf("%d %d %d",px,py,pz);

   tmp=px;
   px=pz;
   pz=py;
   py=tmp;

  
   printf("%d %d %d",*px,*py,*pz);

}
