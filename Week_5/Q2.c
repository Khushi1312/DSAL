#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int arr[1000];
	int top;
}Stack;
int isFull(int top)
{
	if(top == 999)
	{
		return 1;
	}
	return 0;
}
int isEmpty(int top)
{
	if(top == -1)
	{
		return 1;
	}
	return 0;
}
void push(Stack *s, char ele)
{
	if(isFull(s->top)==1)
	{
		printf("Overflow\n");
		exit(0);
	}
	else
	{
		s->top = s->top + 1;
		s->arr[s->top] = ele;
	}
}
void display(Stack *s)
{
	int i;
	for(i = 0; i <= s->top; i++)
	{
		printf("%d", s->arr[(s->top)-i]);
	}
	printf("\n");
}
void main()
{
	Stack *s,s1;
	s=&s1;
	s->top=-1;
	int n,i;
	printf("Enter decimal number:");
	scanf("%d",&n);
	while(n!=0&&n!=1)
	{
		i=n%2;
		push(s,i);
		n=n/2;
	}
	if(n==1)
		push(s,1);
	else
		push(s,0);
	printf("Number in Binary : ");
	display(s);
}
