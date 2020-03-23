#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include<fcntl.h>
#include <sys/time.h>
#include <string.h>
void css(char *a,char *b,char *d)
{
	int j=0,i,c;
	for(i=0;i<strlen(a);i++)
	{
		d[i]=a[i];
	}
	d[i]='\0';
	c=strlen(a);
	d[c]='/';
	d[c+1]='\0';
	for(i=c+1;i<c+strlen(b)+1;i++)
	{		
		d[i]=b[j];
		
		j++;
	}	
	d[i]='\0';
}
int cut(char *a,char *b,char *c,char *d)
{
	
	
	int i=0,j=0,k=0,e=0;
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='/')
		{
			j++;
			continue;
		}
	}
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]=='/')
		{
			k++;
		}
		if(k==4)
			break;

	}
	k=i+1;
	if(j>=4)
	{
		
		for(i=k;i<strlen(a);i++)
		{
		
			b[e]=a[i];
			if(e==4)
			{
				break;
			}
			e++;
		}
		b[e+1]='\0';
		if(j==4)
			return 1;
	}
	k=i+1;
	e=0;
	if(j>=5)
	{
		for(i=k;i<strlen(a);i++)
		{
			if(a[i]>='a'&&a[i]<='z')
			{
				
				c[e]=a[i];
				if(e==4)
				{
					break;
				}
				e++;
			}
			if(a[i]>='A'&&a[i]<='Z')
			{
				
				c[e]=a[i];
				if(e==7)
					break;
				e++;
			}

		}
		c[e+1]='\0';
		if(e==4&&j==5)
			return 2;
		if(e==7&&j==5)
			return 4;

	}
	k=i+2;
	e=0;
	if(j==6)
	{
		for(i=k;i<strlen(a);i++)
		{
			
			d[e]=a[i];
			if(e==7)
				break;
			e++;
		}

		d[e]='\0';
	
		return 3;
	}


}
int main(int argc, char const *argv[])
{
	char path[100];
	char patp[100];
	printf("input path\n");

	scanf("%s",path);
	css(path,"sources",patp);
	int fd=mkdir(patp,S_IRUSR | S_IWUSR | S_IXUSR | S_IXGRP | S_IXOTH);
	if(fd<0)
	{
		printf("mkdir error\n");
		return 0;
	}
	FILE *fp;
	fp=fopen("/home/sweetjiuce/p.txt","r");
	if(fp==NULL)
	{
		printf("open txt error\n");
		return 0;
	}
	while(!feof(fp))
	{
		char pa[100];
		fgets(pa,100,fp);
		if(pa[0]=='/')
		{
			struct dirent *dir;
			
			struct stat st;
			DIR *dir_ptr;
			
			char path1[10],path2[100],path3[100];
			char path4[200],path5[100],paa[100];
			int depth=cut(pa,path1,path2,path3);

			long int a;
			int b;
			
			switch(depth)
			{
				case 1:
					printf("sdsd\n");
					css(patp,path1,path3);
					dir_ptr=opendir(path3);
					//int af=dirfd(dir_ptr);
					printf("sdsd\n");
					if(dir_ptr==NULL)
					{
						int res=mkdir(path3,S_IRUSR | S_IWUSR | S_IXUSR | S_IXGRP | S_IXOTH);
						if(res<0)
						{
							printf("mkdir / error 1\n");
							exit(0);
						}
						
					}
					dir_ptr=opendir(path3);
					dir = readdir(dir_ptr);
				//	struct timespec times[2];
					stat(path3,&st);
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					//dir_ptr->d_ino=a;
					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					//dir_ptr->d_off=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					//dir_ptr->d_reclen=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
				//	dir_ptr->d_type=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);					
					//dir_ptr->d_name=path2;

					

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_mode=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_ino=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_dev=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_rdev=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_nlink=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_uid=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_gid=b;
					chown(path3,st.st_uid,st.st_gid);

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_size=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_atime=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					//times[0]=st.st_mtime;
					st.st_mtime=a;
				//	times[0]=st.st_mtime;
					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_ctime=a;	
					//times[1]=st.st_ctime;
					//futimens(af,times);

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_blksize=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_blocks=a;
					break;
				case 2:
					
					css(patp,path1,path3);
					css(path3,path2,path4);
					dir_ptr=opendir(path4);
					if(dir_ptr==NULL)
					{
						int res=mkdir(path4,S_IRUSR | S_IWUSR | S_IXUSR | S_IXGRP | S_IXOTH);
						if(res<0)
						{
							printf("mkdir / error\n");
							exit(0);
						}
						
					}
					dir_ptr=opendir(path4);
					int fg=dirfd(dir_ptr);
					dir = readdir(dir_ptr);
					//struct timespec times[2];
					stat(path4,&st);
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					//dir_ptr->d_ino=a;
					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					//dir_ptr->d_off=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					//dir_ptr->d_reclen=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					//dir_ptr->d_type=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);					
					//dir_ptr->d_name=path2;

					

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_mode=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_ino=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_dev=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_rdev=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_nlink=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_uid=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_gid=b;
					chown(path4,st.st_uid,st.st_gid);
					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_size=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_atime=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_mtime=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_ctime=a;
					//futimens(fg,times);
					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_blksize=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_blocks=a;
					break;
				case 3:
					
					css(patp,path1,path4);
					css(path4,path2,path5);
					
					css(path5,path3,paa);
					
					printf("%s\n",path3);
					printf("%s\n",paa);
					int p=open(paa,O_RDWR | O_CREAT,0777);
					if(p<0)
					{
						printf("open txt error 1\n");
						exit(0);
					}
					
					
					stat(paa,&st);
					//struct timespec times[2];

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_mode=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_ino=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_dev=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_rdev=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_nlink=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_uid=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_gid=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_size=a;
					chown(paa,st.st_uid,st.st_gid);
					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_atime=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_mtime=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_ctime=a;
					//futimens(p,times);
					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_blksize=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_blocks=a;
					break;
				case 4:
					
					css(patp,path1,path3);
					css(path3,path2,path5);
					

					int c=open(path5,O_RDWR | O_CREAT,0777);
					if(c<0)
					{
						printf("open txt error 2\n");
						exit(0);
					}
					
					long int a;
					int b;
					stat(path5,&st);
					//struct timespec times[2];

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_mode=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_ino=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_dev=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_rdev=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_nlink=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_uid=b;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%d",&b);
					st.st_gid=b;
					chown(path5,st.st_uid,st.st_gid);
					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_size=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_atime=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_mtime=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_ctime=a;
					//futimens(c,times);
					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_blksize=a;

					memset(path2,0,strlen(path2));
					fgets(path2,100,fp);
					sscanf(path2,"%ld",&a);
					st.st_blocks=a;
					break;

			}
		}
		else
		{

		}

	}

	return 0;
}