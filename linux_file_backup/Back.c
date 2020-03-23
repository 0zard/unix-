#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
char L1[100];
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
void List(char *Lists,int depth,FILE *fp)
{
	struct dirent *dir;
	DIR *D;
	struct stat st;
	char L[100];
	//char L1[100];
	memset(L, 0, strlen(L));
	strcpy(L,Lists);
	L[strlen(Lists)]='\0';
	printf("%s\n",L);
	
	if((D=opendir(L))==NULL)
	{
		printf("opendir error\n");
		exit(0);
	}
	
	while (NULL != (dir = readdir(D)))
	{
		
		printf("%d\n",depth);
		if(strncmp(dir->d_name,".",1)==0)
			continue;
		char E[100];
		css(L,dir->d_name,E);
		if(dir->d_type==4)
		{			
			
			printf("%s\n",E);
			
			memset(L1, 0, strlen(L1));
			strcpy(L1,L);
			L1[strlen(L)]='\0';

			fputs(E,fp);
			fputs("\n",fp);
			char di[100];
		
			int result = stat(E,&st);
			if(result!=0)
			{
				printf("stat error 1 \n");
				exit(0);
			}

			
			
			sprintf(di,"%ld",dir->d_ino);
			
			fputs(di,fp);
			fputs("\n",fp);
			sprintf(di,"%ld",dir->d_off);
			
			fputs(di,fp);
			fputs("\n",fp);
			sprintf(di,"%d",dir->d_reclen);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%d",dir->d_type);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%s",dir->d_name);
			
			fputs(di,fp);
			fputs("\n",fp);
			sprintf(di,"%d",st.st_mode);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_ino);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_dev);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_rdev);
		
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_nlink);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%d",st.st_uid);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%d",st.st_gid);
		
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_size);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_atime);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_mtime);
		
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_ctime);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_blksize);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_blocks);
			
			fputs(di,fp);
			fputs("\n",fp);

	        
        	List(E, depth+1,fp);

        	 
		}
		else
		{
			char L2[100];\
			char E1[120];
			memset(L2, 0, strlen(L2));
			strcpy(L2,L1);
			printf("%s\n",L1);
			L2[strlen(L1)]='\0';
			
			FILE *f;
			char a1[120];
			f=fopen(E,"r");
			printf("%s\n",L2);
			if(f==NULL)
			{
				printf("opentxt error\n");
				return;
			}
			fgets(a1,100,f);
			fputs(E,fp);
			fputs("\n",fp);
			char di[100];
			int result = stat(L,&st);
			if(result!=0)
			{
				printf("stat error\n");
				return;
			}
			sprintf(di,"%d",st.st_mode);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_ino);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_dev);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_rdev);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_nlink);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%d",st.st_uid);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%d",st.st_gid);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_size);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_atime);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_mtime);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_ctime);
			
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_blksize);
		
			fputs(di,fp);fputs("\n",fp);
			sprintf(di,"%ld",st.st_blocks);
			
			fputs(di,fp);fputs("\n",fp);
			
			fputs(a1,fp);
			fputs("\n",fp);
		}

	}

}
int main(int argc, char const *argv[])
{
	FILE *fp;
	fp=fopen("/home/sweetjiuce/p.txt","wb");
	if(fp==NULL)
	{
		printf("file Backup.txt exit\n");
	}
	int depth =1;
	char a2[100]="/home/cc/sources";
	List(a2,depth,fp);
	return 0;
}