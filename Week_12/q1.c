#include <stdlib.h>
#include <stdio.h>
#include "BT.h"
int printAncestors(NODE root, int target)

{

	if (root == NULL)
		return 0;
	if (root->info == target)
		return 1;
	if ( printAncestors(root->lchild, target)||printAncestors(root->rchild, target) )
	{
		printf("%d ",root->info );
		return 1;
	}
	return 0;
}

NODE insert(NODE root,int item)
{
	NODE temp,cur,prev;
	temp=getNode();
	temp->info=item;
	temp->rchild=temp->lchild=NULL;
	if(root==NULL)
		return temp;
	prev=NULL;
	cur=root;
	while(cur!=NULL)
	{
		prev=cur;
		if(item<cur->info)
			cur=cur->lchild;
		else
			cur=cur->rchild;
	}
	if(item<prev->info)
		prev->lchild=temp;
	else
		prev->rchild=temp;
	return root;
}

NODE maxValueNode(NODE root)
{
	NODE cur=root;
	while (cur && cur->rchild!=NULL)
		cur=cur->rchild;
	return cur;
}

NODE deleteNode(NODE root, int key)
{
	if (root == NULL) 
		return root;
	if (key < root->info)
		root->lchild = deleteNode(root->lchild, key);
	else if (key > root->info)
		root->rchild = deleteNode(root->rchild, key);
	else
	{
		if (root->lchild == NULL)
		{ 
			NODE temp = root->rchild;
			free(root);
			return temp;
		}
		else if (root->rchild == NULL)
		{ 
			NODE temp = root->lchild;
			free(root);
			return temp;
		}
		NODE temp = maxValueNode(root->lchild);
		root->info = temp->info;
		root->lchild = deleteNode(root->lchild, temp->info);
	}	
return root;
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
void main()
{
	NODE root,cur;
	int choice,item;
	root=NULL;
	printf("1)INSERT 2)INORDER 3)DELETE 4)PRINT ANCESTORS\n");
	for(;;)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("ENTER ITEM\n");
			scanf("%d",&item);
			root=insert(root,item);
			break;
			case 2:
			printf("TREE\n");
			display(root,1);
			printf("\n");
			printf("INORDER\n");
			inorder(root);
			printf("\n");
			break;
			case 3:
			printf("ENTER ITERM TO DELETE\n");
			scanf("%d",&item);
			root=deleteNode(root,item);
			break;
			case 4:
			printf("ENTER ITEM\n");
			scanf("%d",&item);
			int a=printAncestors(root,item);
			break;
			default:
			exit(0);
		}
	}
}