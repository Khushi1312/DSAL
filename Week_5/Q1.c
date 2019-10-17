#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"

void pop(Stack *s)
{
	if(isEmpty(s->top)==1)
	{
		printf("Empty\n");
	}
	else
	{
		s->top = s->top - 1;
	}
}

void display(Stack *s)
{
	int i;
	for(i = 0; i <= s->top; i++)
	{
		printf("%c\n", s->arr[(s->top)-i]);
	}
}

int main()
{
	Stack s1;
	Stack *s;
	s = &s1;
	s->top = -1;
	printf("Enter Number of Queries\n");
	int q;
	scanf("%d", &q);
	int i;
	char k;

	for(i = 0; i < q; i++)
	{
		printf("Enter 1 to push, 2 to pop, 3 to display\n");
		int j;
		scanf("%d", &j);
		if(j == 1)
		{
			printf("Enter char\n");
			scanf(" %c", &k);
			push(s, k);
		}
		else if(j == 2)
		{
			pop(s);
		}
		else
		{
			display(s);
		}
	}
}