#include <stdio.h>
#include <stdlib.h>
void func()
{ 
	printf("kill 1\n");
}
void func1()
{
	printf("kill 2\n");
}
int main(int argc, char const *argv[])   
{
	
	atexit(func);
	atexit(func);
	atexit(func1);

	return 0;
}