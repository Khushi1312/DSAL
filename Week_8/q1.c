#include <stdio.h>
#include <stdlib.h>
#define QUE_SIZE 5
int delete(int *f,int *r, int *q)
{
	if(*f>*r)
		return -1;
	return q[(*f)++];
}
void display(int f,int r,int q[])
{
	int i;
	if(f>r)
	{
		printf("EMPTY\n");
		return;
	}
	printf("QUEUE:\n");
	for (int i = f; i<=r; i++)
	{
		printf("%d\t",q[i]);
	}
	printf("\n");
}
void insert(int item, int q[],int *r)
{
	int j;
	if(*r==QUE_SIZE-1)
	{
		printf("FULL\n");
		return;
	}
	j=*r;
	while(j>=0&&item<q[j])
	{
		q[j+1]=q[j];
		j--;
	}
	q[j+1]=item;
	*r+=1;
}
void main()
{
	int choice,item,f,r,q[10];
	f=0;
	r=-1;
	for(;;)
	{
		printf("1)Insert 2)Delete 3)Display 4)Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter to insert:\n");
			scanf("%d",&item);
			insert(item,q,&r);
			break;
			case 2:
			item=delete(&f,&r,q);
			if(item==-1)
				printf("EMPTY\n");
			else
				printf("Deleted: %d\n",item );
			break;
			case 3:
			display(f,r,q);
			break;
			default:
			exit(0);
		}
	}
}