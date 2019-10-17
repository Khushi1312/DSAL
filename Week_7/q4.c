#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct
{
    char arr[MAX];
    int top;
}Stack;

int isEmpty(int top)
{
    if(top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(int top)
{
    if(top == 999)
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
    }
    else
    {
        s->top = s->top + 1;
        s->arr[s->top] = ele;
    }
}
int pop(Stack *s)
{
    if(!isEmpty(s->top))
    {
        s->top-=1;
        return s->arr[s->top+1];
    }
    else
        printf("EMPTY\n");
}
void display(Stack *s)
{
    printf("QUEUE:\n");
    for(int i=0;i<=s->top;i++)
        printf("%d ",s->arr[(s->top)-i] );
    printf("\n");
}
void main()
{
    Stack p,q,*s1,*s2;
    s1=&p;
    s1->top=-1;
    s2=&q;
    s2->top=-1;
    int ch,ele,ch1;
    for(;;)
    {
        printf("1) Insert 2) Delete 3) Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
         case 1:   
            for(;;)
            {
                printf("1) Enter 2) Change choice\n");
                scanf("%d",&ch1);
                if(ch1==1)
                {
                    scanf("%d",&ele);
                    push(s1,ele);
                }
                if(ch1==2)
                {
                    for(;!isEmpty(s1->top);)
                    push(s2,pop(s1));
                    break;
                }   
            }
            break;
            case 2:                            
                pop(s2);
                break;
            case 3:
                display(s2);
                break;
        
        }
    }
}