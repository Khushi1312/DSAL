#include<stdio.h>
#define MAX 100

typedef struct
{
	int data[MAX];
	int top;
}stack;

void initi(stack*s)
{
	s->top=-1;
}

int empty(stack *s)
{
	if(s->top==-1)
		return 1;
	return 0;
}

int full(stack*s)
{
	if(s->top==MAX-1)
		return 1;
	return 0;
}

void push(stack *s, int x)
{
	s->top=s->top+1;
	s->data[s->top]=x;
}

int pop(stack *s)
{
	int x;
	x=s->data[s->top];
	s->top=s->top-1;
	return x;
}

void display(stack *s)
{
	int x;
	for(x=0; x<=s->top; x++)
		printf("\n%d\t", s->data[x]);
}