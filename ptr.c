#include <stdio.h>
#include<stdlib.h>
void main()
{
	int arr[100],*p,*i,n;
	printf("Enter size of array:");
	scanf("%d",&n);
	p=arr;
	printf("Enter array elements:\n");
	for(i=p;i<p+n;i++)
		scanf("%d",i);
	printf("Array forward is:\n");
	for(i=p;i<p+n;i++)
		printf("%d\n",*i);
	printf("Array backwards is:\n");
	for(i=p+n-1;i>=p;i--)
		printf("%d\n",*i);
}
