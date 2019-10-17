#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char arr[1000];
    int top;
}Stack;

int isEmpty(Stack *s)
{
    if(s->top==-1)
        return 1;
    return 0;
}

int isFull(Stack *s)
{
    if(s->top==999)
        return 1;
    return 0;
}

int pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Empty\n");
    }
    else
    {
        s->top = s->top - 1;
        return s->arr[(s->top)+1];
    }
}

void push(Stack *s, char ele)
{
    if(isFull(s))
    {
        printf("Overflow\n");

    }
    else
    {
        s->top = s->top + 1;
        s->arr[s->top] = ele;
    }
}
int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    return 0;
}
int isOperator(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        return 1;
    return 0;
}

int main()
{
    Stack s1,*s;
    s=&s1;
    s->top=-1;
    int i,j;
    char inf[100],pre[100];
    int len;
    printf("Enter infix:");
    scanf("%s",inf);
    len=strlen(inf);
    for(i=0,j=len-1;i<len/2;i++,j--)
    {
        char temp=inf[i];
        inf[i]=inf[j];
        inf[j]=temp;
    }
    //STEP1
    inf[len]='(';
    inf[len+1]='\0';
    push(s,')');
    //STEP2
    while(isEmpty(s)!=1)
    {
        for(i=0,j=0;i<strlen(inf);i++)
        {
            //STEP3
            if(isdigit(inf[i])||isalpha(inf[i]))
            {
                pre[j]=inf[i];
                j++;
            }
            //STEP4
            if(inf[i]==')')
                push(s,inf[i]);
            //STEP5
            if(isOperator(inf[i]))
            {
                while (getPriority(inf[i])< getPriority(s->arr[s->top]))
                       {
                           pre[j]=pop(s);
                           j++;
                       }
                push(s,inf[i]);
            }
            //STEP6
            if(inf[i]=='(')
            {
                while(s->arr[s->top]!=')')
                {
                    pre[j]=pop(s);
                        j++;
                }
                char ex=pop(s);
            }
        }
    }
    pre[j]='\0';
    len=strlen(pre);
    for(i=0,j=len-1;i<len/2;i++,j--)
    {
        char temp=pre[i];
        pre[i]=pre[j];
        pre[j]=temp;
    }
    printf("%s",pre);
}
