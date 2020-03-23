#include<stdio.h>
#include<stdlib.h>
int main()
{
	int j=0;
	while(1)
	{

		int *i=(int *)malloc(1024*1024);
		if(i!=NULL)
		{
			j++;
		}
		else
			break;
	}
	printf("%d\n",j);

}
