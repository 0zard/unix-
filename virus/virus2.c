#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>
int flag=0;

/*
判断信号的到来


 */
void Flag(int sig)
{
  flag=1;
}

/*

生成随机字母
 */
void random_number(char *s)
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

/*

每当有信号到来的时候。处理这个函数
 */
void SIG(int signo)
{
  if(signo == 1)
  {  
    while(1)
    {
      char out[100]="/home/cyz/test";
      char gc[100]="gcc ";
      char sourc[100]="/home/cyz/test/";
      char source[100]="/home/cyz/test/";
      char string_rand[10];
      random_number(string_rand);
      strcat(source,string_rand);
      FILE *fp=freopen(source,"r+",stdout);
      if(fp!=NULL)
        continue;
      else
      {    
        FILE *fp=freopen(source,"w+",stdout);
        strcat(gc,source);
        char *str="#include <stdio.h>%c#include <sys/types.h>%c#include <signal.h>%c#include <string.h>%c#include <stdlib.h>%c#include <time.h>%c#include <unistd.h>%c\
        int flag=0;void random_number(char *s){int i;for(i=0;i<5;i++){s[i]=rand()%26+'a';}s[i]='.';s[i+1]='c';s[i+2]=0;}%cvoid Flag(int sig){flag=1;}%c\
        void SIG(int signo){if(signo == 1){\
        while(1){char out[100]=%c/home/cyz/test%c;char sourc[100]=%c/home/cyz/test/%c;char gc[100]=%cgcc %c;char source[100]=%c/home/cyz/test/%c;\
        char string_rand[10];random_number(string_rand);strcat(source,string_rand);FILE *fp=freopen(source,%cr+%c,stdout); \
        if(fp!=NULL)continue;else {FILE *fp=freopen(source,%cw+%c,stdout);strcat(gc,source);char *str = %c%s%c;%c\
        printf(str,10,10,10,10,10,10,10,10,10,34,34,34,34,34,34,34,34,34,34,34,34,34,str,34,10,34,34,34,34,10,10,10,10,34,34,34,34,34,34,10,34,34,34,34,34,37,34,10,10);fclose(fp);\
        system(gc);execlp(%c./a.out%c, %c./a.out%c,(char*)0);break;%c}}}}%c\
        int main(int argc, char const *argv[])%c\
        {%cchar source[100]=%c/home/cyz/test/%c;srand((unsigned)time(NULL));char Te[100];\
        FILE *f=fopen(%c/home/cyz/num.txt%c,%cr+%c);\
        fgets(Te,100,f);int num=atoi(Te);if(num==0){exit(0);%c}else{num--;}fclose(f);\
        FILE *f1=fopen(%c/home/cyz/num.txt%c,%cw%c);fprintf(f1, %c%cd%c, num);\
        fclose(f1);int pid=fork();sigset_t set;sigemptyset(&set);sigprocmask(SIG_SETMASK,&set,NULL);signal(SIGINT,Flag);if(pid==0){while(flag!=1){pause();}SIG(1);}%creturn 0;%c}";   
        printf(str,10,10,10,10,10,10,10,10,10,34,34,34,34,34,34,34,34,34,34,34,34,34,str,34,10,34,34,34,34,10,10,10,10,34,34,34,34,34,34,10,34,34,34,34,34,37,34,10,10);
        fclose(fp);
        system(gc);
        //system("./a.out");
        if(execlp("./a.out", "./a.out",(char*)0)<0){printf("111");}
        break;
      }
    }
  }
}
int main(int argc, char const *argv[])
{
    
	  srand((unsigned)time(NULL));
    char Te[100];
   
    FILE *f=fopen("/home/cyz/num.txt","r+");
    fgets(Te,100,f);
    int num=atoi(Te);//将字符型转换成整形
    if(num==0)
    {
    	exit(0);
    }
    else
    {
   		num--;
   	}
    fclose(f);
    FILE *f1=fopen("/home/cyz/num.txt","w");   
    fprintf(f1, "%d", num);
   	fclose(f1);
    
    //int pid=0;
   	int pid=fork();
    sigset_t set;
    sigemptyset(&set);
    sigprocmask(SIG_SETMASK,&set,NULL);
    signal(SIGINT,Flag);
   	if(pid==0)
   	{
      while(flag!=1)
      {
        pause();
      }
      SIG(1);
   	}
    
    return 0;
}