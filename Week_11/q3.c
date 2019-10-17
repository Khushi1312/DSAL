#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include "BT.h"
float eval(NODE root)
{
	float num;
	switch(root->info)
	{
		case '+':
		return eval(root->llink)+eval(root->rlink);
		case '-':
		return eval(root->llink)-eval(root->rlink);
		case '*':
		return eval(root->llink)*eval(root->rlink);
		case '/':
		return eval(root->llink)/eval(root->rlink);
		case '^':
		return pow(eval(root->llink),eval(root->rlink));
		default:
		if(isalpha(root->info))
		{
			printf("%c = ",root->info);
			scanf("%f", &num);
			return num;
		}
		else
			return root->info-'0';
	}
}
void main()
{
	char post[40];
	float res;
	NODE root=NULL;
	printf("Enter postfix expression\n");
	scanf("%s", post);
	root=create(post);
	printf("The expression tree is:\n");
	display(root,1);
	res=eval(root);
	printf("Result=%f\n",res);
}