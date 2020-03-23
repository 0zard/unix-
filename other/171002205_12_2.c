#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	int fi=mkfifo("/home/sweetjiuce/unix/myfifo_",0777);
	if(fi<0)
	{
		printf("make fifo error or file exist\n");
		//exit(0);
	}
	int fi1=mkfifo("/home/sweetjiuce/unix/myfifo_1",0777);
	if(fi1<0)
	{
		printf("make fifo1 error or file exist\n");
		//exit(0);
	}
	int fi2=mkfifo("/home/sweetjiuce/unix/myfifo_2",0777);
	if(fi2<0)
	{
		printf("make fifo2 error or file exist\n");
		//exit(0);
	}
	int fd=open("/home/sweetjiuce/unix/myfifo_",O_RDONLY);
	if(fd<0)
	{
		printf("open myfifo_ error\n");
		//exit(0);
	}
	char buf[10];
	while((read(fd,buf,10)!=-1))
	{
		if(strncmp(buf,"1",1)==0)
		{
			int f1=open("/home/sweetjiuce/unix/myfifo_1",O_WRONLY );
			if(f1<0)
			{
				printf("open myfifo1 error\n");
				exit(0);
			}
			write(f1,"read",4);
			//write(f1,"\0",1);
			close(f1);
		}
		else if(strncmp(buf,"2",1)==0)
		{
			int f2=open("/home/sweetjiuce/unix/myfifo_2",O_WRONLY);
			if(f2<0)
			{
				printf("open myfifo2 error\n");
				exit(0);
			}
			write(f2,"read",4);
			//write(f2,"\0",1);
			close(f2);
		}
		memset(buf,0,10);
	}
	return 0;
}