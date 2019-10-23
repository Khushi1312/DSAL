#include <stdlib.h>
#include <stdio.h>
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
NODE create_BT()
{
	NODE temp;
	int ele;
	printf("Enter element(-1 for no data):\n");
	scanf("%d",&ele);
	if(ele==-1)
		return NULL;
	temp=getNode();
	temp->info=ele;
	printf("Enter left child of %d\n",ele);
	temp->lchild=create_BT();
	printf("Enter right child of %d\n",ele);
	temp->rchild=create_BT();
	return temp;
}
NODE copy(NODE root)
{
	NODE temp;
	if(root==NULL)
		return NULL;
	temp=getNode();
	temp->info=root->info;
	temp->lchild=copy(root->lchild);
	temp->rchild=copy(root->rchild);
}
int equal(NODE a, NODE b)
{
	if(a==NULL&&b==NULL) return 1;
	if(a!=NULL&&b==NULL) return 0;
	if(a==NULL&&b!=NULL) return 0;
	if(a->info!=b->info) return 0;
	if(a->info==b->info) return 1;
	return equal(a->lchild,b->lchild)&&equal(a->rchild,b->rchild);
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
void main()
{
	NODE root,a;
	root=create_BT();
	display(root,1);
	printf("\n");
	a=copy(root);
	display(a,1);
	if(equal(a,root))
		printf("EQUAL\n");
	else
		printf("NOT EQUAL\n");
}
