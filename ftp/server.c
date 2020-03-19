#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <ctype.h>
#include <dirent.h>
#include<arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <sys/stat.h>

/*


	creat socket bind port

*/

int creat_sock(char *ip,int port)
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0)
	{
		fprintf(stderr,"create socket error\n");
		exit(1);
	}
	struct sockaddr_in serv_addr;
	

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(ip);
	serv_addr.sin_port = htons(port);
	int struct_len=sizeof(struct sockaddr_in);
	
	while(bind(sockfd,(struct sockaddr *)&serv_addr,struct_len)==-1);
	printf("Bind success\n");
	while(listen(sockfd,20)==-1);
	printf("listening...\n");
	printf("Ready for accept,waitting...\n");
	return sockfd;
}


/*
	depart buff

*/

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



/*judge put get list hello
	return 0 1 2 3 4 

*/
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
			filename[a1]=st[j];
			a1++;
	}
	filename[a1]='\0';

	
	
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


/*
	print file list


*/
void LIST(char *list)
{
	char path[50];
	//char path[50];
	memset(list,0,100);
	getcwd(path,50);
	DIR *d=NULL;
	struct dirent *dp=NULL;
	struct stat st;

	if(!(d= opendir(path)))
	{
		printf("opendir[%s] error\n",path);
		exit(1);
	}
	while((dp=readdir(d))!=NULL)
	{
		if((!strncmp(dp->d_name,".",1)))
			continue;

		if(!S_ISDIR(st.st_mode))
		{
			strcat(list,dp->d_name);
			strcat(list," ");
		}
		else
		{
			strcat(list,dp->d_name);

			strcat(list,"/ ");

		}
	}
	strcat(list,"0");
}


/*

find filename in dir

*/
int FIND(char *filename)
{
	DIR *d=NULL;
	struct dirent *dp=NULL;
	char path[50];
	getcwd(path,50);
	int i;
	if(!(d= opendir(path)))
	{
		fprintf(stderr, "%s\n",path);
		exit(1);
	}
	while((dp=readdir(d))!=NULL)
	{

		for (i = 0; i < strlen(dp->d_name); ++i)
		{
			if(dp->d_name[i]==filename[i])
				continue;
			else
				break;
		}
		//fprintf(stderr, "%d\n",i);
		if(i>=strlen(dp->d_name))
		{

			return 1;
		}
	}
	return 0;
}



int main(int argc, char const *argv[])
{
	//char sock_file[]="/home/sweetjiuce/unix/socket";
	char *addr="127.0.0.1";
	char *port="8888";

	int sock=creat_sock(addr,atoi(port));
	char path[50];
	getcwd(path,50);


	while(1)
	{


		struct sockaddr_in clnt_addr;
		socklen_t clnt_addr_size = sizeof(clnt_addr);
		
		int clnt_sock = accept(sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
		int fk;
	if(fk=fork())
		exit(0);
	if(fk<0)
	{
		printf("error\n");
		exit(1);
	}

	else if(fk==0)
	{
		setsid();
		close(sock);
		if(fork()>0)
		{
			exit(0);
		}

		while(1)
		{

			char so_packet[200];
			ssize_t ss=recv(clnt_sock,so_packet,sizeof(so_packet),0);
			
			
			int flag;
			char str[100];
			char filename[20];
			so_packet[ss]='\0';
			flag=judge(so_packet,filename);

			//fprintf(stderr,"%s",filename);

			if(ss>0)
			{

				//so_packet[ss]='\0';
				//fprintf(stderr, "%s",so_packet);
			switch(flag)
			{
				case 0:
				{


					strcpy(str,"connect");
					
					send(clnt_sock,str,strlen(str),0);
					memset(str,0,100);
					break;
				}
				case 1:
					{


						char list[100];
						LIST(list);
						send(clnt_sock,list,strlen(list),0);
						
						break;
					}


				case 2://get packet
				{
					int n;
					char content[100];
					char newpath[100];
					strcpy(newpath,path);
					
					n=FIND(filename);
					if(n==0)
					{
						send(clnt_sock,"find file error",15,0);		

					}
					else
					{
						
						strcat(newpath,"/");
						strcat(newpath,filename);
						int fd=open(newpath,O_RDWR);
						
						if(fd<0)   /*open file error*/
						{							
							send(clnt_sock,"open file error",15,0);	
							break;					
						}
						read(fd,content,100);

						int l=strlen(content);

						content[l]='\0';

						int len=strlen(so_packet);

						so_packet[len]=' ';

						so_packet[len+1]='\0';

						strcat(so_packet,content);

						send(clnt_sock,so_packet,strlen(so_packet),0);

						printf("sended the packet done\n");
					}
					break;
				}


	
				case 3:
				{
					int n=FIND(filename);
					
					char FILA[100];
					char cmd[10];
					char content[100];
					if(n)
					{

						send(clnt_sock,"file existed in server!",25,0);					
					}
					else
					{

						//sscanf(so_packet,"%s %s %s",cmd,FILA,content);
						depart(so_packet,cmd,FILA,content);
					

						int fd=open(FILA,O_CREAT | O_WRONLY);
						if(fd<0)
						{
							fprintf(stderr, "creat %s error\n",filename);
							break;
						}
						
						content[strlen(content)]='\0';
						int err=write(fd,content,strlen(content));
						if(err<0)
						{
							printf("err\n");
							break;
						}
						send(clnt_sock,"finished!",9,0);

					}
					break;
				}
				default :
						send(clnt_sock,"cmd error",9,0);	
						break;			

			}
		}
		else if(ss==0)
		{
			printf("client exit\n");
			break;
		}
		else
		{
			printf("read\n");
			break;
		}
			
			
		//}

	}
	close(clnt_sock);
	exit(0);
}
chdir("/tmp");
umask(0);
}
	return 0;
}