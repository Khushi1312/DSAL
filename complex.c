#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	double real;
	double img;
}complex;
void add(complex n1,complex n2)
{
	complex n3;
	n3.real=n1.real+n2.real;
	n3.img=n1.img+n2.img;
	printf("add :(%lf)+i(%lf)\n",n3.real,n3.img);
}
void sub(complex n1,complex n2)
{
	complex n3;
	n3.real=n1.real-n2.real;
	n3.img=n1.img-n2.img;
	printf("sub :(%lf)+i(%lf)\n",n3.real,n3.img);
}
void mult(complex n1,complex n2)
{
	complex n3;
	n3.real=(n1.real*n2.real)-(n1.img*n2.img);
	n3.img=(n1.real*n2.img)+(n1.img*n2.real);
	printf("mult :(%lf)+i(%lf)",n3.real,n3.img);
}
void main()
{
	complex n1,n2;
	printf("Enter real and imaginary part of n1:");
	scanf("%lf%lf",&n1.real,&n1.img);
	printf("Enter real and imaginary part of n2:");
	scanf("%lf%lf",&n2.real,&n2.img);
	add(n1,n2);
	sub(n1,n2);
	mult(n1,n2);
}
