#include<stdio.h>
#include "stack.h"
#include "q.h"
int main()
{
	int i, n, a;
	queue q;
	init(&q);
	stack s;
	initi(&s);
	printf("enter no of elements");
	scanf("%d", &n);
	printf("Enter:");
	for(i=0; i<n; i++)
	{
		scanf("%d", &a);
		insertq(&q, a);
	}
	printf("ORi\n");
	displayq(q);
	for(i=0; i<n; i++)
	{
		push(&s, deleteq(&q));
	}
	for(i=0; i<n; i++)
	{
		insertq(&q, pop(&s));
	}
	printf("\n");
	displayq(q);

}