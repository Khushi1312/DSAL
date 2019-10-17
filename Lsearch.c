#include<stdlib.h>
#include<stdio.h>
int* Lsearch(int *a,int n, int f)
{
        int i;
	for(i=0;i<n;i++)
	{
	  if(a[i]==f)
		printf("Element %d found at pos %d\n",f,(i+1));
	}
	return (a+2);
}
int main()
{
	int i,*a,n,f;
	printf("Enter value of n:");
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
	printf("Enter elements");
	for(i=0;i<n;i++)
	{
           scanf("%d",(a+i));
	}	
	printf("Enter number to search:");
	scanf("%d",&f);
	printf("%d",*(Lsearch(a,n,f)));
	free(a);
	return 0;
}

