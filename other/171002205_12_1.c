#include <stdio.h>
void function()
{
	printf("11\n");
}
int main(int argc, char const *argv[])
{
	function();
	(int *)function;
	function();
	return 0;
}