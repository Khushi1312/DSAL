#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int data;
	struct node *link;
};
typedef struct node* NODE;
NODE getnode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("OUT OF MEMORY\n");
		exit;
	}
	return x;
}
void display(NODE first)
{
	NODE cur;
	if(first==NULL)
	{
		printf("EMPTY!!\n");
		return;
	}
	else
	{
		printf("List Contents:\n");
		cur=first;
		while(cur!=NULL)
		{
			printf("%d ",cur->data);
			cur=cur->link;
		}
		printf("\n");
	}
}
NODE delete_f(NODE first)
{
	NODE temp;
	if(first==NULL)
	{
		printf("EMPTY!!\n");
	}
	else
	{
		temp=first;
		temp=temp->link;
		printf("Deleted: %d\n",first->data);
		free(first);
		return temp;
	}
}
NODE insert_r(NODE first, int ele)
{
	NODE new,cur;
	new=getnode();
	new->data=ele;
	new->link=NULL;
	if(first==NULL)
		return new;
	cur=first;
	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=new;
	return first;
}