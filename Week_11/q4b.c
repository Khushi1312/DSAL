#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "BT.h"
int equal(NODE r1, NODE r2)
{
	if(r1==NULL && r2==NULL)
		return 1;
	if(r1==NULL && r2!=NULL)
		return 0;
	if(r1!=NULL && r2==NULL)
		return 0;
	if(r1->info!=r2->info)
		return 0;
	if(r1->info==r2->info)
		return 1;
	return equal(r1->llink,r2->llink)&&equal(r1->rlink,r2->rlink);
}
void main()
{
	char t1[40], t2[40];
	NODE r1=NULL, r2=NULL;
	printf("Enter 'tree 1' expression\n");
	scanf("%s", t1);
	r1=create(t1);
	printf("Enter 'tree 2' expression\n");
	scanf("%s", t2);
	r2=create(t2);
	int res=equal(r1,r2);
	if(res==1)
		printf("The trees are equal\n");
	else
		printf("The trees aren't equal\n");
}