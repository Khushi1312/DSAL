#include <stdio.h>
#include <string.h>

#define MAX 4

typedef struct
{
        char ar[MAX][100];
        int front;
        int rear;
}QUEUE;

void insertcqrear(QUEUE* q, char* string)
{
                q->rear = (q->rear + 1);
                strcpy(q->ar[q->rear],string);

                if(q->front == -1)
                        q->front = 0;
}
void insertcqfront(QUEUE* q, char* string)
{

                q->front = (q->front - 1);
                strcpy(q->ar[q->front],string);
}

char* deletecq(QUEUE* q)
{
        if(q->front == q->rear)
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

        for (int i = q->front; i != q->rear; i = (i+1)%MAX)
                {
                        printf("%s ", q->ar[i]);
                }
        printf("%s\n", q->ar[q->rear]);
}


int main()
{
        QUEUE q;
        q.front = -1;
        q.rear = -1;

        char string[100];
        int choice;

        printf("Choose one of the following:\n1.insertrear\n2.inserfront\n3.Delete\n4.Display\n-1.Quit\n");
        scanf("%d", &choice);

        while(choice != -1)
        {
                switch(choice)
                {
                        case 1:
                                printf("Enter the string to insert: ");
                                scanf("%s", string);
                                insertcqrear(&q, string);
                                break;
                        case 2:
                                printf("Enter the string to insert: ");
                                scanf("%s", string);
                                insertcqfront(&q, string);
                                break;
                        case 3:
                                deletecq(&q);
                                break;
                        case 4:
                                displaycq(&q);
                                break;
                        default:
                                break;
                }

                scanf("%d", &choice);
        }

        return 0;
}
