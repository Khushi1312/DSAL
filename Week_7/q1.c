#include <stdio.h>
#include <string.h>

#define MAX 4

typedef struct
{
        char ar[MAX][100];
        int front;
        int rear;
}QUEUE;

void insertcq(QUEUE* q, char* string)
{
        if((q->rear + 1)%MAX != q->front)
        {
                q->rear = (q->rear + 1)%MAX;
                strcpy(q->ar[q->rear],string);

                if(q->front == -1)
                        q->front = 0;
        }
        else
                printf("Queue is full!\n");
}

char* deletecq(QUEUE* q)
{
        if((q->front) == -1)
        {
                printf("Queue is empty!\n");
        }
        else if(q->front == q->rear)
        {
                int x = q->front;
                q->rear = q->front = -1;
                return q->ar[x];
        }
        else
        {
                return q->ar[(q->front)++];
        }
}

void displaycq(QUEUE* q)
{
        if((q->front) == -1)
        {
                printf("Queue is empty!\n");
        }
        else
        {
                for (int i = q->front; i != q->rear; i = (i+1)%MAX)
                {
                        printf("%s ", q->ar[i]);
                }
                printf("%s\n", q->ar[q->rear]);
        }
}


int main()
{
        QUEUE q;
        q.front = -1;
        q.rear = -1;

        char string[100];
        int ch;

        printf("Choose one of the following:\n1.Insert\n2.Delete\n3.Display\n-1.Quit\n");
        scanf("%d", &ch);

        while(ch != -1)
        {
               if(ch==1){
                                printf("Enter the string to insert: ");
                                scanf("%s", string);
                                insertcq(&q, string);}

                        if(ch==2){
                                deletecq(&q);}

                        if(ch==3){
                                displaycq(&q);
                        }


                scanf("%d", &ch);
        }

        return 0;
}