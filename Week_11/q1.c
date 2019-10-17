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
void preorder(NODE root)
{
	if(root)
	{
		printf("%d ",root->info);
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void postorder(NODE root)
{
	if(root)
	{
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d ",root->info);
	}
}
void inorder(NODE root)
{
	if(root)
	{
		inorder(root->lchild);
		printf("%d ",root->info);
		inorder(root->rchild);
	}
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
void main()
{
	NODE root;
	root=create_BT();
	printf("INORDER TRAVERSAL\n");
	inorder(root);
	printf("\n");
	printf("PRERDER TRAVERSAL\n");
	preorder(root);
	printf("\n");
	printf("POSTORDER TRAVERSAL\n");
	postorder(root);
	printf("\n");
}

