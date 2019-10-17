#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
struct node
{
	char info;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *NODE;
void display(NODE root, int level)
{
	int i;
	if(root==NULL)
		return;
	display(root->rlink, level+1);
	for(i=0; i<level; i++)
		printf(" ");
	printf("%c\n", root->info);
	display(root->llink, level+1);
}
NODE getnode()
{
	NODE x=(NODE)malloc(sizeof(struct node));
	if(x==NULL)
	{
		printf("Couldn't allocate memory\n");
		exit(0);
	}
	return x;
}
NODE create(char post[])
{
	NODE temp, st[20];
	int i,k;
	char sym;
	for(i=k=0; (sym=post[i])!='\0'; i++)
	{
		temp=getnode();
		temp->info=sym;
		temp->llink=temp->rlink=NULL;
		if(isalnum(sym))
			st[k++]=temp;
		else
		{
			temp->rlink=st[--k];
			temp->llink=st[--k];
			st[k++]=temp;
		}
	}
	return st[--k];
}