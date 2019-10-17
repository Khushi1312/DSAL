#include <stdio.h>
#include <stdlib.h>
#include "node.h"
int main()
{
	NODE first;
	int choice,ele;
	first=NULL;
	printf("Enter 1)insert rear 2)delete front 3)display 4)exit\n");
	for(;;)
	{
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element to insert:");
				scanf("%d",&ele);
				first=insert_r(first,ele);
				break;
			case 2:
				first=delete_f(first);
				break;
			case 3:
				display(first);
				break;
			default:
				return 0;
		}		
	}
}