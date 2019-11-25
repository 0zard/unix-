#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	int fp=open("/home/sweetjiuce/unix/myfifo_",O_WRONLY | O_NONBLOCK);
	if(fp<0)
	{
		printf("open myfifo_ error\n");
		exit(0);
	}
	write(fp,"2",1);
	close(fp);
	int f2=open("/home/sweetjiuce/unix/myfifo_2",O_RDONLY | O_NONBLOCK );
	if(f2<0)
	{
		printf("open myfifo_2 error\n");
		exit(0);
	}
	char buf[4];
	read(f2,buf,4);
	if(buf[0]!='r')
		exit(0);
	//buf[4]='\0';
	printf("%s\n",buf);
	close(f2);
	return 0;
}