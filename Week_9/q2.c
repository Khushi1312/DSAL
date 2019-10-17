#include <stdlib.h>
#include <stdio.h>
#include "node.h"
int search(NODE first,int key)
{
	NODE cur;
	if(first==NULL)
		return 0;
	cur=first;
	while(cur!=NULL)
	{
		if(key==cur->data)
			return 1;
		cur=cur->link;
	}
	return 0;
}

NODE unionn(NODE first,NODE second)
{
	NODE a,third;
	int flag;
	a=first;
	third=NULL;
	while(a!=NULL)
	{
		third=insert_r(third,a->data);
		a=a->link;
	}
	a=second;
	while(a!=NULL)
	{
		flag=search(third,a->data);
		if(flag==0)
			third=insert_r(third,a->data);
		a=a->link;
	}
	return third;
}
NODE intersection(NODE first,NODE second)
{
	NODE a,b,third;
	int flag;
	a=first;
	b=second;
	third=NULL;
	while(a!=NULL)
	{
		flag=search(b,a->data);
		if(flag==1)
			third=insert_r(third,a->data);
		a=a->link;
	}
	return third;
}
int main()
{
	NODE first,second,third;
	int choice,item,i,n;
	printf("1)Create LL1 2)Create LL2 3)Union 4)Intersection 5)Exit\n");
	for(;;)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter no of nodes in list 1:");
				scanf("%d",&n);
				first=NULL;
				printf("Enter elements");
				for (int i = 0; i < n; i++)
				{
					scanf("%d",&item);
					first=insert_r(first,item);
				}
				break;
			case 2:
				printf("Enter no of nodes in list 2:");
				scanf("%d",&n);
				second=NULL;
				printf("Enter elements");
				for (int i = 0; i < n; i++)
				{
					scanf("%d",&item);
					second=insert_r(second,item);
				}
				break;
			case 3:
				printf("List 1:\n");
				display(first);
				printf("List 2:\n");
				display(second);
				printf("Union:\n");
				third=unionn(first,second);
				display(third);
				break;
			case 4:
				printf("List 1:\n");
				display(first);
				printf("List 2:\n");
				display(second);
				printf("Intersection:\n");
				third=intersection(first,second);
				display(third);
				break;
			default:
				return 0;
		}
	}
}