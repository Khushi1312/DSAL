#include<stdio.h>
#include<stdlib.h>
#include <string.h>
typedef struct
{
    int top;
    char arr[1000];
}Stack;
int pop(Stack *s)
{
    if(s->top==-1)
        printf("Empty");
    else
    {
        s->top=s->top-1;
        return s->arr[(s->top)+1];
    }
}
void push(Stack *s,char ele)
{
    if(s->top==999)
        printf("Full");
    else
    {
        s->top=s->top+1;
        s->arr[s->top]=ele;
    }
}
void main()
{
    Stack *s,s1;
    int op1,op2,ans=0,ch;
    char str[100],*p;
    s=&s1;
    s->top=-1;
    printf("Enter prefix:");
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0,j=len-1;i<len/2;i++,j--)
    {
       char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    p=str;
    for(int i=0;str[i]!='\0';i++)
    {
        if(*p>='0'&&*p<='9')
           push(s,(*p-'0'));
        else if(*p=='+'||*p=='-'||*p=='*'||*p=='/')
        {
            op1=pop(s);
            op2=pop(s);
            if(*p=='+')
                ch=1;
            if(*p=='-')
                ch=2;
            if(*p=='*')
                ch=3;
            if(*p=='/')
                ch=4;
            switch(ch)
            {
            case 1:
                ans=op1+op2;
                push(s,ans);
                break;
            case 2:
                ans=op1-op2;
                push(s,ans);
                break;
            case 3:
                ans=op1*op2;
                push(s,ans);
                break;
            case 4:
                ans=op1/op2;
                push(s,ans);
                break;
            }
        }
        p++;
    }
    printf("Answer is %d\n",ans);
}