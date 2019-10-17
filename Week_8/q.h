#include<stdio.h>
#include<string.h>

#define MAX 100

typedef struct
{
	int item[100];
	int front;
	int rear;
}queue;

void init(queue *q)
{
	q->front=q->rear=-1;
}

void insertq(queue *q, int x)
{
	if(q->rear==MAX)
	{
		printf("overflow");
	}
	else
	{
		++q->rear;
		q->item[q->rear]=x;
		if(q->front==-1)
		{
			q->front=0;
		}
	}
}

int deleteq(queue *q)
{
	int x;
	if(q->front==-1)
	{
		printf("underflow");
	}
	else if(q->front==q->rear)
	{
		x=q->item[q->front];
		q->front=q->rear=-1;
		return x;
	}
	else
	{
		return q->item[q->front++];
	}
}

void displayq(queue q)
{
	int i;
	if(q.front==-1 && q.rear==-1)
	{
		printf("queue is empty");
	}
	else
	{
		printf("queue is:\n");
		for(i=q.front; i<=q.rear; i++)
		{
			printf("%d\n", q.item[i]);
		}
	}
}