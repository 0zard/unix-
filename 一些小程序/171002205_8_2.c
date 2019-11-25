#include <stdio.h>
#include <sys/resource.h>
int main(int argc, char const *argv[])
{
	struct rlimit r;

	getrlimit(RLIMIT_STACK, &r);
	printf("stack max: %ld\n",r.rlim_cur);
	getrlimit(RLIMIT_DATA, &r);
	printf("data max: %ld\n",r.rlim_cur);
	return 0;
}