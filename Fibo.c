#include<stdio.h>
int fibo(int n)
{
	printf("n: %d\n",n);
	if(n==0||n==1)
	{
		//printf("n:%d\n",n);
		return n;
	}
	else
	{
		//printf("n:%d\n",n);
		return(fibo(n-1)+fibo(n-2));
	}
}
void main()
{
	int i,n;
	printf("Enter the value of n:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		printf("%d\n",fibo(i));
}