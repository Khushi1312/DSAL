#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int a[100];
	int f;
	int r;
}QUEUE;
void init(QUEUE *q)
{
	q->f=-1;
	q->r=-1;
}
void insertq(QUEUE *q, int x)
{
	if(q->r==99)
		printf("OVERFLOW\n");
	else
	{
		(q->r)++;
		q->a[q->r]=x;
		if(q->f==-1)
			q->f=0;
	}
}
int deleteq(QUEUE *q)
{
	int p;
	if(q->f>q->r)
		printf("UNDERFLOW\n");
	else if(q->f==q->r)
	{
		p=q->a[q->f];
		q->f=q->r=-1;
		return p;
	}
	else
		return q->a[(q->f)++];
	
}
void displayq(QUEUE *q)
{
	int i;
	printf("Queue:\n");
	if(q->f==-1 && q->r==-1)
		printf("Is empty\n");
	else
	{
		for(i=q->f; i<=q->r; i++)
			printf("%d\t", q->a[i]);
		printf("\n");
	}
}
int main()
{
	int ele, ch, x, i;
	QUEUE q, *q1;
	q1=&q;
	init(q1);
	printf("1.Insert queue elements\n2.Delete queue elements\n3.Display queue\n4.Search for a queue element\n");
	do
	{
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
			printf("Enter\n");
			scanf("%d", &x);
			insertq(q1,x);
			break;
			case 2:
			printf("Deleted =%d\n", deleteq(q1));
			break;
			case 3:
			displayq(q1);
			break;
			case 4:
			printf("Enter element to be searched for\n");
			scanf("%d", &ele);
			int front=q1->f;
			int rear=q1->r;
			int flag=0;
			for(i=front; i<=rear; i++)
			{
				int y=deleteq(q1);
				if(y==ele)
					flag++;
				insertq(q1,y);
			}
			if(!flag)
				printf("FALSE\n");
			else
				printf("TRUE\n");
			break;
			default:
			exit(0);
		}
	}while(ch==1||ch==2||ch==3||ch==4);
	return 0;
}