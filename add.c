#include<stdio.h>
#include<stdlib.h>
double add(double *p,int n)
{
	double sum=0;
	for(double *i=p;i<=p+n;i++)
 	 sum+=*i;
	return sum;
}
void main()
{
	double *i,sum,*p;
	int n;
	printf("Enter size n:");
	scanf("%d",&n);
	p=(double*)calloc(n,sizeof(double));
	printf("Enter elements:");
	for(i=p;i<p+n;i++)
	  scanf("%lf",i);
	sum=add(p,n);
	printf("Sum is:%lf",sum);
}
