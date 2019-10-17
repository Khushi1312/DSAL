#include<stdio.h>
#include<stdlib.h>
void main()
{
  int n,i,j,*p,*k;
  printf("Enter size of array:");
  scanf("%d",&n);
  p=(int*)calloc(n,sizeof(int));
  printf("Enter elements:");
  for(k=p;k<p+n;k++)
	  scanf("%d",k);
  i=1;
  printf("Original is:");
  for(k=p;k<p+n;k++)
    printf("%d ",*k);
  for(k=p;k<p+n/2;k++)
  {
    int temp=*k;
    *k=*(p+n-i);
    *(p+n-i)=temp;
    i++;
  }
  printf("Reverse is:");
  for(k=p;k<p+n;k++)
    printf("%d ",*k);
}
