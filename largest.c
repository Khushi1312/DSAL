#include<stdio.h>
void seclarge(int a[],int n)
{
	int max=a[0],i,max2=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	for(i=1;i<n;i++)
	{
		if(a[i]>max2&&a[i]!=max)
			max2=a[i];
	}
	printf("Second largest is %d",max2);
}
void main()
{
	int a[100],i,n;
	printf("Enter size:");
	scanf("%d",&n);
	printf("enter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	seclarge(a,n);
}
