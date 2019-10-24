#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
struct node
{
	int info;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node* NODE;

NODE getNode()
{
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	return x;
}

void display(NODE root, int level)
{
	int i;
	if(root==NULL)
		return;
	display(root->rchild, level+1);
	for(i=0; i<level; i++)
		printf(" ");
	printf("%d\n", root->info);
	display(root->lchild, level+1);
}
