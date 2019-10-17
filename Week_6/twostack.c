#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct{
    int data[MAX];
    int top1;
    int top2;
}Stack;
void init(Stack *s)
{
    s->top1=-1;
    s->top2=MAX;
}
void push1(Stack *s,int x)
{
    s->top1=s->top1+1;
    s->data[s->top1]=x;
}
void push2(Stack *s,int x)
{
    s->top2=s->top2-1;
    s->data[s->top2]=x;
}
int pop1(Stack *s)
{
    int x;
    x=s->data[s->top1];
    s->top1-=1;
    return x;
}
int pop2(Stack *s)
{
    int x;
    x=s->data[s->top2];
    s->top2+=1;
    return x;
}
void display(Stack *s)
{
    printf("STACK 1:\n");
    for(int i=s->top1;i>-1;i--)
        printf("%d\t",s->data[i]);
    printf("\nSTACK 2:\n");
    for(int i=s->top2;i<MAX;i++)
        printf("%d\t",s->data[i]);
}
int main()
{
    Stack s1,*s;
    s=&s1;
    init(s);
    int m,l;
    while(1)
    {
        printf("1) pop1 2) pop2 3) push1 4) push2 5) Display 6) exit\n");
        scanf("%d",&m);
        switch(m)
        {
            case 1: l=pop1(s);
            printf("Popped %d\n",l);
            break;
            case 2: l=pop2(s);
            printf("Popped %d\n",l);
            break;
            case 3: scanf("%d",&l);
            push1(s,l);
            break;
            case 4: scanf("%d",&l);
            push2(s,l);
            break;
            case 5:display(s);
            printf("\n");
            break;
            case 6:exit(0);
        }
    }
}