#include<stdlib.h>
#include<stdio.h>
void(int a[][100],int b[][100],int ra,int ca,int rb,int cb)
{
  int c[100][100],i,j,k;
  for(i=0;i<ra;i++)
  {
    for(j=0;j<cb;j++)
    {
      c[i][j]=0;
      for(k=0;k<rb;k++)
       c[i][j]+=(a[i][j]*b[j][k]);
    }
  }
  printf("Mat C is:\n");
  for(i=0;i<ra;i++)
  {
   for(j=0;j<cb;j++)
    printf("%d",c[i][j]);
   printf("\n");
  }
}
void main()
{
  int a[100][100],b[100][100],ra,rb,ca,cb,i,j;
  printf("Enter dimensions:");
  scanf("%d%d%d%d",&ra,&rb,&ca,&cb);
  if(ca==rb)
  {
    printf("Compatible\n");
    for(i=0;i<ra;i++)
    
  }
}
