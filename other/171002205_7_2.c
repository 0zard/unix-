#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	char pass[100];
	char buf[100];
	if(symlink("/home/sweetjiuce/Music/1/1.txt","4")!=0)
	{
		printf("链接文件错误\n");
		return 0;
	}
	if(readlink("/home/sweetjiuce/Music/4",pass,100)==-1)
	{
		printf("打开链接文件错误\n");
		return 0;

	}
	int a=open(pass,O_RDWR);
	read(a,buf,100);
	printf("链接文件的内容是  %s\n",pass);
	printf("文件内容是  %s\n",buf);
	return 0;

}
