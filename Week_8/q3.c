#include<stdio.h>
#include<string.h>
typedef struct
{
    char arr[1000];
    int f;
    int r;
}Queue ;
void insert(Queue *q,char ele)
{
    if(q->r==999)
    {
        printf("OVERFLOW!");
    }
    else
    {
        q->r+=1;
        q->arr[q->r]=ele;
    }
}
char deletef(Queue *q)
{
    if((q->f)>(q->r))
        return -1;
    return q->arr[(q->f)++];
}
char deleter(Queue *q)
{
    char ele;
    if((q->f)>(q->r))
        return -1;
    ele=q->arr[(q->r)--];
    if((q->f)>(q->r))
    {
        q->f=0;
        q->r=-1;
    }
    return ele;
}
void main()
{
    Queue q1,*q;
    q=&q1;
    q->f=0;
    q->r=-1;
    char str[26];
    int i,j,k,len=0,flag=0;
    printf("Enter string:");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    {
        len++;
        insert(q,str[i]);
    }
    for(i=0;i<len/2;i++)
    {
        j=deletef(q);
        k=deleter(q);
        if(j!=k)
        {
            flag=1;
            break;
        }

    }
    if(flag==1)
        printf("NOOO");
    else
        printf("YESSS");
}