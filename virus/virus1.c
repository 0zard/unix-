#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
#include <sys/file.h>
#include <pthread.h>
void ssrand(char *s)
{
	int i;
	for(i=0;i<5;i++)
	{
		s[i]=rand()%26+'a';
	}
	s[i]='.';
	s[i+1]='c';
	s[i+2]=0;
	
}
int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));
	pthread_rwlock_t rwlock;	
	char temp[100];	
	char source[100]="/home/sweetjiuce/test/";
	char gc[100]="gcc ";
  	while(1)
  	{
  		memset(source,0,100);
  		memset(gc,0,100);
  		strcpy(source,"/home/sweetjiuce/test/");
  		strcpy(gc,"gcc ");
	    //source[100]="/home/sweetjiuce/test/";
	    char string_rand[10];
	    ssrand(string_rand);
	    strcat(source,string_rand);
	   // gc[100]="gcc ";	
		strcat(gc,source);
	    FILE *fp=freopen(source,"r+",stdout); 
	    if(fp!=NULL)
	      continue;
	  	else
	  		break;
 	}
 	FILE *fp=freopen(source,"w+",stdout); 
    FILE *f=fopen("/home/sweetjiuce/num.txt","r+");
    while(flock(fileno(f),LOCK_EX | LOCK_NB)!=0);

    fgets(temp,100,f);  
    int num=atoi(temp); 	
    if(num==0)
    {
    	exit(0);
    }
    else
    {
   		num--;
   	}
   	flock(fileno(f),LOCK_UN);
    fclose(f);
    FILE *f1=fopen("/home/sweetjiuce/num.txt","w");
    while(flock(fileno(f),LOCK_EX | LOCK_NB)!=0);
    fprintf(f1, "%d", num);
    flock(fileno(f),LOCK_UN);
   	fclose(f1);
   	int pid=fork();
    char *str="#include <stdio.h>%c#include <sys/file.h>%c#include<pthread.h>%c#include <signal.h>%c\
    #include <sys/types.h>%c#include <string.h>%c#include <stdlib.h>%c#include <time.h>%c#include <unistd.h>%c\
    void ssrand(char *s){int i;for(i=0;i<5;i++){s[i]=rand()%26+'a';}s[i]='.';s[i+1]='c';s[i+2]=0;}%c\
    int main(int argc, char const *argv[])%c\
    {%cpthread_rwlock_t rwlock;srand((unsigned)time(NULL));char temp[100];char gc[100]=%cgcc %c;char source[100]=%c/home/sweetjiuce/test/%c;\
    while(1){memset(source,0,100);memset(gc,0,100);strcpy(source,%c/home/sweetjiuce/test/%c);char string_rand[10];ssrand(string_rand);\
   	strcat(source,string_rand);strcpy(gc,%cgcc %c);	strcat(gc,source);FILE *fp=freopen(source,%cr+%c,stdout);\
   	if(fp!=NULL)continue;else break;} 	FILE *fp=freopen(source,%cw+%c,stdout); \
	FILE *f=fopen(%c/home/sweetjiuce/num.txt%c,%cr+%c);while(flock(fileno(f),LOCK_EX | LOCK_NB)!=0);\
    fgets(temp,100,f);int num=atoi(temp);if(num==0){exit(0);%c}else{num--;}flock(fileno(f),LOCK_UN);fclose(f);\
    FILE *f1=fopen(%c/home/sweetjiuce/num.txt%c,%cw%c);while(flock(fileno(f),LOCK_EX | LOCK_NB)!=0);fprintf(f1, %c%cd%c, num);flock(fileno(f),LOCK_UN);\
    fclose(f1);int pid=fork();\
    char *str = %c%s%c;%c\
    printf(str,10,10,10,10,10,10,10,10,10,10,10,10,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,10,34,34,34,34,34,37,34,34,str,34,10,34,34,34,34,10,10);if(pid==0){system(gc);\
    execlp(%c./a.out%c, %c./a.out%c,(char*)0);}%c fclose(fp);return 0;%c}";
    
    printf(str,10,10,10,10,10,10,10,10,10,10,10,10,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,34,10,34,34,34,34,34,37,34,34,str,34,10,34,34,34,34,10,10);    
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
   	if(pid==0)
   	{
   		system(gc);
   		execlp("./a.out", "./a.out",(char*)0);
   	}



     // ASCII中，10为换行键，34为引号
    fclose(fp); 
    return 0;
}