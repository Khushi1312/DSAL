#include <stdio.h>
int isPal(char *input,int l,int r)
{
	printf("%d %d\n",l,r);
	if(l>=r)
		return 1;
	else if(input[l]==input[r])
		return isPal(input,l+1,r-1);
	else
		return 0;
}
void main()
{
	char a[100];
	int i,len;
	printf("Enter a string:");
	scanf("%s",a);
	for(i=0;a[i]!='\0';i++)
		len++;
	if(isPal(a,0,len-1)==1)
		printf("String is Palindrome\n");
	else
		printf("String is not Palindrome\n");
}