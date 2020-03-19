#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <ctype.h>
#include <dirent.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/un.h>

#include <sys/stat.h>
void depart(char *buff,char *cmd,char *new,char *contain)
{	
	int count;
	for(count=0;count<strlen(buff);count++)
			{
				if(buff[count]!=' ')
					cmd[count]=buff[count];
				else
					break;
			}
			cmd[count]='\0';
			int Ne=0,j;
			for(j=count+1;j<strlen(buff);j++)
			{
				if(buff[j]!=' ')
				{
					new[Ne]=buff[j];
					Ne++;
				}
				else
					break;

			}
			new[Ne]='\0';
			int C=0;
			for(int l=j+1;l<strlen(buff);l++)
			{
				if(buff[l]!=' ')
				{
					contain[C]=buff[l];
					C++;
				}
				else
					break;
			}
			contain[C]='\0';
}
int judge(char *st,char *filename)
{
	char cmd[50];
	char a[50];
	int i;
	for (i = 0; i < strlen(st); i++)
	{
		if(st[i]!=' ')
			cmd[i]=st[i];
		else
			break;
	}
	cmd[i]='\0';
	int a1=0;
	for(int j=i+1;j<strlen(st);j++)
	{
		a[a1]=st[j];
		a1++;
	}
	a[a1]='\0';

	strcpy(filename,a);
	//sscanf(p1+1,"%s%*s",mem_total);
	//sscanf(st,"%s%*s",cmd);
	//sscanf(st,"%*s%s",a);
	//printf("%s\n",cmd);
	//printf("%s\n",a);
	if(strncmp(cmd,"list",4)==0||strncmp(cmd,"List",4)==0)
	{
		
		return 1;
	}
	else if(strncmp(cmd,"hello",5)==0||strncmp(cmd,"Hello",5)==0)
	{
		return 0;
	}
	else if(strncmp(cmd,"put",3)==0||strncmp(cmd,"Put",3)==0)
	{
		return 3;
	}
	else if(strncmp(cmd,"get",3)==0||strncmp(cmd,"Get",3)==0)
		return 2;
	else
		return 4;
}
int main(int argc, char const *argv[])
{
	struct sockaddr_in their_addr;
	int sockfd,numbytes;
	while((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1);
	printf("get the sockfd\n");
	char buf[200];
	char filename[100];
	char buff[200];
	char contain[100];
	their_addr.sin_family = AF_INET;
	their_addr.sin_port=htons(8888);
	their_addr.sin_addr.s_addr = INADDR_ANY;
	//their_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	bzero(&(their_addr.sin_zero),8);

	while(connect(sockfd,(struct sockaddr*)&their_addr,sizeof(struct sockaddr))==-1);
	printf("get the server\n");
	
	while(1)
	{
		memset(buf,0,200);
		memset(buff,0,200);
		memset(contain,0,100);
		printf("please inter your request\n");
		ssize_t s= read(0,buf,sizeof(buf));
		int n;
		buf[s-1]='\0';

		n=judge(buf,filename);

		switch(n)
		{
			case 0://hello
			{												
				send(sockfd,buf,strlen(buf),0);
				break;
			}
			case 1://list
			{
				
				send(sockfd,buf,strlen(buf),0);
				break;
			}
			case 3://put
			{
				int fd=open(filename,O_RDWR);
				printf("%s\n",filename);
				
				if(fd<0)
				{
					printf("filename: %s input error \n",filename);
					send(sockfd,"hha",3,0);
				}
				else
				{
					read(fd,contain,200);
					int len=strlen(buf);
					buf[len]=' ';
					buf[len+1]='\0';
					strcat(buf,contain);
					buf[strlen(buf)+strlen(contain)]='\0';
					send(sockfd,buf,strlen(buf),0);
				}
				break;
			}
			case 2://get
			{
				send(sockfd,buf,strlen(buf),0);
				break;
				
			}
			default:
				send(sockfd,"hhaha",5,0);
				
				break;
				
		}

		//send(sockfd,buf,strlen(buf),0);



		
		
		ssize_t numb=recv(sockfd,buff,BUFSIZ,0);
		buff[numb]='\0';
		char new[100];
		char cmd[100];
		int count=0;
		if(strncmp(buff,"get",3)==0)
		{
			depart(buff,new,cmd,contain);
			printf("%s %s %s\n",new,cmd,contain);
			int fd=open(cmd,O_RDWR | O_CREAT);
			if(fd<0)
			{
				printf("creat file %s error\n",new);
			}
			else
			{
				write(fd,contain,strlen(contain));
			}
			printf("creat file %s done\n",new);
		}
		printf("received:\n");
		printf("%s\n",buff);
		
		
		printf("request done!\n");
		

		

	}
	return 0;
}