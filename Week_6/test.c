#include <stdio.h>
#include <string.h>
#include "Stack.h"
char* pop(Stack *s)
{
	s->top-=1;
	return s->arr[(s->top)+1];
}

void main()
{
	Stack s1,*s;
	s=&s1;
	s->top=-1;
	char temp;
	char str[]="abc def";
	char rev[10];
	int i,len=strlen(str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==' ')
			push(s,'+');
		else
			push(s,str[i]);
	}
	for(i=0;i<len;i++)
	{
		temp=pop(s);
		if(temp=='+')
			rev[i]=' ';
		else
			rev[i]=temp;
	}
	display(s);
}