#include<stdio.h>
#include <string.h>
void rev(char *a,char *b,int index,int len)
{
	if(b[index+1]=='\0')
		printf("%s",b);
	else
	{
		b[index]=a[len];
		index+=1;
		len-=1;
		rev(a,b,index,len);
	}
}
void main()
{
	char a[100],b[100],len;
	printf("Enter");
	scanf("%s",a);
	for(int i=0;a[i]!='\0';i++)
		len++;
	
}