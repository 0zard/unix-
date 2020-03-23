#include<stdio.h>
int main(int argc,char **argv,char **env)
{
	int i=0;
	for(i=0;env[i]!=NULL;i++)
		printf("%s\n",env[i]);
}
