#include<stdio.h>
int cap(char *s,int index)
{
	if(s[index]>=65&&s[index]<=90)
	  return index;
	else
		return(cap(s,index+1));
}
void main()
{
	char a[100],len;
	printf("Enter");
	scanf("%s",a);
	for(int i=0;a[i]!='\0';i++)
		len++;
	printf("%d",(cap(a,0))+1);
}