#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char arr[20];
	int front1;
	int rear1;
	int front2;
	int rear2;
}Queue;

void inserteq(Queue *q, char ele, int no)
{
	if(no == 1)
	{
		if((q->rear1+1)%11 == q->front1)
		{
			printf("Queue 1 is full\n");
			return;
		}
		q->arr[q->rear1] = ele;
		q->rear1 += 1;
		q->rear1 = (q->rear1)%11;
	}
	if(no == 2)
	{
		if((q->rear2+1)%9 == q->front1)
		{
			printf("Queue 2 is full\n");
			return;
		}
		q->arr[q->rear2] = ele;
		q->rear2 += 1;
		q->rear2 = (q->rear2)%20;
		if(q->rear2 == 0)
			q->rear2 = 11;
	}
}

void deletecq(Queue *q, int no)
{
	if(no == 1)
	{
		if((q->front1)%11 == q->rear1)
		{
			printf("Queue is empty\n");
			q->front1 = 0;
			q->rear1 = 0;
			return;
		}
		q->front1 += 1;
		q->front1 = (q->front1)%11;
	}
	else
	{
		if((q->front2)%9 == q->rear2)
		{
			printf("Queue is empty\n");
			q->front2 = 11;
			q->rear2 = 11;
			return;
		}
		q->front2 += 1;
		q->front2 = (q->front2)%20;
		if((q->front2) == 0)
		{
			q->front2 = 11;
		}
	}
}

void display(Queue *q)
{
	printf("Queue 1:\n");
	if(q->front1< q->rear1)
	{
		for(int i = q->front1; i < q->rear1; i++)
		{
			printf("%c\t", q->arr[i]);
		}
	}
	else
	{
		for(int i = q->front1; i <= 10; i++)
		{
			printf("%c\t", q->arr[i]);
		}
		for(int i = 0; i < q->rear1; i++)
		{
			printf("%c\t", q->arr[i]);
		}
	}
	printf("\nQueue 2:\n");
	if (q->front2 < q->rear2)
	{
		for(int i = q->front2; i< q->rear2; i++)
		{
			printf("%c\t", q->arr[i]);
		}
	}
	else
	{
		for(int i = q->front2; i <= 19; i++)
		{
			printf("%c\t", q->arr[i]);
		}
		for(int i = 11; i < q->rear2; i++)
		{
			printf("%c\t", q->arr[i]);
		}
	}
}

int main()
{
	Queue *q;
	q = (Queue *)malloc(sizeof(Queue));
	q->rear1 = 0;
	q->front1 = 0;
	q->rear2 = 11;
	q->front2 = 11;
	printf("1. Queue 1, 2. Queue 2, 3. Exit\n");
	while(1)
	{
		int i;
		scanf("%d", &i);
		if(i == 3)
		{
			break;
		}
		printf("Use 1. to push, 2. to pop, 3. to display, 4. to change Queue\n");
		while(1)
		{
			int j;
			scanf("%d", &j);
			if(j == 1)
			{
				char ele;
				scanf(" %c", &ele);
				inserteq(q, ele, i);
			}
			else if(j == 2)
			{
				deletecq(q, i);
			}
			else if (j == 3)
			{
				display(q);
				printf("\n");
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}
