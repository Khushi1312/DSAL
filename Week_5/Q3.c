#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Stack.h"

char pop(Stack *s)
{
	if(isEmpty(s->top)==1)
	{
		printf("Empty\n");
	}
	else
	{
		s->top = s->top - 1;
		return s->arr[s->top + 1];
		
	}
}



void compare(Stack *s1, Stack *s2, int len)
{

	for(int i = 0; i < len; i++)
	{
		char p, q;
		p = pop(s1);
		q = pop(s2);
		if(p != q)
		{
			printf("Not a Palindrome\n");
			return;
		}
	}
	printf("Palindrome\n");
	return;
}

int main()
{
	Stack s1, s2;
	Stack *p1, *p2;
	p1 = &s1;
	p2 = &s2;
	p1->top = -1;
	p2->top = -1;
	char a[1000];
	printf("Enter String:\n");
	scanf("%s", a);
	int len = 0, i, j , k;
	for(i = 0; a[i] != '\0'; i++)
	{
		len++;
		push(p1, a[i]);
	}
	for(i = 1; i <= len/2; i++)
	{
		push(p2, pop(p1));
	}
	if(len%2 != 0)
	{
		char c = pop(p1);
	}
	compare(p1, p2, len/2);
}