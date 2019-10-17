#include<stdio.h>
#include <math.h>
void tower(int n,char source,char dest,char temp)
{
	printf("%d %c %c %c\n",n,source,dest,temp);
	if(n==1)
		printf("Move disk 1 from rod %c to rod %c\n",source,dest);
	else 
	{
		tower(n-1,source,temp,dest);
		printf("Move disk %d from rod %c to rod %c\n",n,source,dest);
		tower(n-1,temp,dest,source);
	}
}
void main()
{
	int n;
	printf("Enter number of disks:");
	scanf("%d",&n);
	tower(n,'A','C','B');
	printf("Number of moves:");
	n=pow(2,n)-1;
	printf("%d\n",n );
}