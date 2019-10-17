#include<stdio.h>
void copy(char str1[],char str2[],int index)
{
	printf("%d\n",index);
	if(str1[index]=='\0')
		printf("%s\n",str2 );
	else
	{
		str2[index]=str1[index];
		index+=1;
		copy(str1,str2,index);
	}
}
void main()
{
	char a[100],b[100];
	printf("Enter a string:");
	scanf("%s",a);
	copy(a,b,0);
	printf("String Copied!\n");
}