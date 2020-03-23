#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
int main()
{
	struct stat buf;
	struct stat buff;

	if(stat("/home/sweetjiuce/Music/1",&buf)!=0)
	{
		printf("文件打开失败\n");
	}
	printf("文件夹的所有者是：%u\n",buf.st_uid);
	printf("文件类型是：%u\n",buf.st_mode);
	stat("/home/sweetjiuce/Music/1/1.txt",&buff);
	printf("文件的所有者是：%u\n",buff.st_uid);
	printf("文件类型是：%u\n",buff.st_mode);

	printf("将文件和文件夹的所有者+1\n");
	buf.st_uid+=1;
	buff.st_uid+=1;
	printf("文件夹的所有者是：%u\n",buf.st_uid);
	printf("文件的所有者是：%u\n",buff.st_uid);
	if(chmod("/home/sweetjiuce/Music",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)==0)
	{
		printf("已修改文件夹权限为777\n");
	}
	if(chmod("/home/sweetjiuce/Music/1/1.txt",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)==0)
	{
		 printf("已修改文件权限为777\n");

	}
	return 0;
	
}
