#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int rollno;
	char name[26];
	float cgpa;
}student;
void swap(student *a,student *b)
{
	student c=*a;
	*a=*b;
	*b=c;
}
void main()
{
	int n,i,j,k;
	student *s;
	printf("Enter number of students:");
	scanf("%d",&n);
	s=(student *)calloc(n,sizeof(student));
	for(i=0;i<n;i++)
	{
		printf("Enter name, rno and cgpa:\n");
		scanf("%s",((s+i)->name));
		scanf("%d",&((s+i)->rollno));
		scanf("%f",&((s+i)->cgpa));
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(((s+j)->rollno)<((s+i)->rollno))
				swap((s+i),(s+j));
			else
				continue;
		}
	}
	printf("Sorted Record\n");
	for(i=0;i<n;i++)
	{
		printf("student %d:\n",i+1);
		printf("%s\n",((s+i)->name));
		printf("%d\n",((s+i)->rollno));
		printf("%f\n",((s+i)->cgpa));
	}
}
