#include<stdio.h>
int f(int n)
{
	static int i=1;
	int *p;
	printf("%d\n",i);
	p=&n;
	printf("%p\n",p);
	if(n==1||n==2)
		return 1;
	else
		return f(n-1)+f(n-2);
}
int main()
{
	int i=f(10);
	printf("%d",i);
	return 0;
}

