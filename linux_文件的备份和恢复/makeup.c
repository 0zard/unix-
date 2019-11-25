#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>  
#include <unistd.h>
#include <fcntl.h>
void ssrand(char *s)
{
	int i;
	for(i=0;i<5;i++)
	{
		s[i]=rand()%26+'a';
	}
	s[i]='\0';

}
void Ssrand(char *s)
{
	int i;
	
	
	for(i=0;i<8;i++)
	{
	
			s[i]=rand()%26+'A';
	
		
	}
	s[i]='\0';
}
void Ssrand100(char *s)
{
	int i;
	
	for(i=0;i<100;i++)
	{
			s[i]=rand()%26+'a';	
	}
	s[i]='\0';
}
void css(char *a,char *b)
{
	int j=0,i;	
	a[strlen(a)]='/';	
	for(i=strlen(a);i<strlen(a)+strlen(b);i++)
	{		
		a[i]=b[j];
		j++;
	}	
	a[i]='\0';
}
int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
	struct dirent * p = NULL;
	DIR *dp;	
	if(mkdir("/home/cc/sources",S_IRUSR | S_IWUSR | S_IXUSR | S_IXGRP | S_IXOTH)==-1)
	{
		printf("sources exist\n");
	}
	dp=opendir("/home/cc/sources");
	
	if (dp==NULL)
	{
		printf("open sources error\n");
		return 0;
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			char R[100]="/home/cc/sources";
			DIR *dp1;
			char a[20];						
			char cc[100];						
			ssrand(a);			
			getcwd(cc,sizeof(cc));
			chdir(cc);
			css(R,a);	
			int flag=mkdir(R,S_IRUSR | S_IWUSR | S_IXUSR);
			chdir(R);			
			if(flag!=0)
			{
				printf("creat rand file error\n");
				return 0;					
			}
			for(int ab=0;ab<20;ab++)
			{
				char h[9];
				char r[100];				
				Ssrand(h);
				int t1=open(h,O_WRONLY | O_CREAT | O_TRUNC,S_IRUSR | S_IWUSR | S_IXUSR);
				if(t1<0)
				{
					printf("input txt error1\n");
					return 0;
				}
				Ssrand100(r);
				write(t1,r,100);
			}
			int ac=1;

			if(ac==2)
			{
				printf("openat rand file error\n");
				return 0;
			}
			else
			{
				char R1[100];
				strcpy(R1,R);
				for (int j = 0; j < 5; j++)
				{
					char sd[9];
					char b[9];
					char l[101];
					memset(R, 0, strlen(R));				
					chdir(R1);
					ssrand(sd);
					strcpy(R,R1);
					printf("%s\n",R);
					R[strlen(R1)]='\0';
					css(R,sd);
					printf("%s\n",R);									
					int c=mkdir(R,S_IRUSR | S_IWUSR | S_IXUSR);
					chdir(R);
					if(c!=0)
					{
						printf("creat rand file error 1\n");
						return 0;
					}
					for(int ss=0;ss<20;ss++)
					{
						Ssrand(b);
						int f=open(b,O_WRONLY | O_CREAT | O_TRUNC,S_IRUSR | S_IWUSR | S_IXUSR);
						if(f<0)
						{
							printf("open txt file error\n");
							return 0;
						}
						else
						{
							Ssrand100(l);
							write(f,l,101);					
						}
					}
				}
			}
		}		
	}
	return 0;
}