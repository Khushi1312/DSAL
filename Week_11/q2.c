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
void inorder(NODE root)
{
	NODE cur,s[20];
	int top=-1;
	if(root==NULL)
	{
		printf("EMPTY!!\n");
		return;
	}	
	cur=root;
	for(;;)
	{
		while(cur!=NULL)
		{
			s[++top]=cur;
			cur=cur->lchild;
		}
		if(top!=-1)
		{
			cur=s[top--];
			printf("%d ",cur->info);
			cur=cur->rchild;
		}
		else
			return;
	}
}
void postorder(NODE root)
{
	typedef struct
	{
		NODE addr;
		int flag;
	}Stack;
	NODE cur;
	Stack s[20];
	int top=-1;
	if(root==NULL)
	{
		printf("EMPTY!!\n");
		return;
	}
	cur=root;
	for(;;)
	{
		while(cur!=NULL)
		{
			top++;
			s[top].addr=cur;
			s[top].flag=1;
			cur=cur->lchild;
		}
		while(s[top].flag<0)
		{
			cur=s[top].addr;
			top--;
			printf("%d ",cur->info);
			if(top==-1)
				return;
		}
		cur=s[top].addr;
		cur=cur->rchild;
		s[top].flag=-1;
	}
}
void preorder(NODE root)
{
	NODE cur,s[20];
	int top=-1;
	if(root==NULL)
	{
		printf("EMPTY!!\n");
		return;
	}
	cur=root;
	for(;;)
	{
		while(cur!=NULL)
		{
			printf("%d ",cur->info );
			s[++top]=cur;
			cur=cur->lchild;
		}
		if(top!=-1)
		{
			cur=s[top--];
			cur=cur->rchild;
		}
		else
			return;
	}
}
void levelorder(NODE root)
{
	NODE q[10],cur;
	int f=0,r=-1;
	q[++r]=root;
	while(f<=r)
	{
		cur=q[f++];
		printf("%d ",cur->info );
		if(cur->lchild!=NULL)
			q[++r]=cur->lchild;
		if(cur->rchild!=NULL)
			q[++r]=cur->rchild;
	}
	printf("\n");
}
void main()
{
	NODE root;
	root=create_BT();
	printf("INORDER TRAVERSAL\n");
	inorder(root);
	printf("\n");
	printf("PREORDER TRAVERSAL\n");
	preorder(root);
	printf("\n");
	printf("POSTORDER TRAVERSAL\n");
	postorder(root);
	printf("\n");
	printf("LEVELORDER TRAVERSAL\n");
	levelorder(root);
	printf("\n");
}

