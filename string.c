#include<stdio.h>
#include <stdlib.h>
void main()
{
	char *s;
	s=(char*)calloc(3,sizeof(char));
	printf("Enter");
	for(int i=0;i<3;i++)
		scanf("%c",(s+i));
	for(int i=0;i<3;i++)
		printf("%c\n",*(s+i));
}