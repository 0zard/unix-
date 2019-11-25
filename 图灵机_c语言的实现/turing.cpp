#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>
#include<map>
#include<math.h>
#include<stdlib.h>
using namespace std;
void translate(map<string,string> &personnel,FILE *fp)
{
	char ch;
	char a[10];
	char b[10];
	while(1)
	{
		if(fgetc(fp)==':')
			break;
	}
	int i=0,j=0,k;
	while((ch=fgetc(fp))!='\n')
	{
		if(ch==','||ch==';')
		{
			a[i]='\0';
			i=0;
			j++;
			k=j;
			while(k--)
			{
				b[i]='0';
				i++;
			}
			b[i]='\0';
			personnel.insert(pair<string, string>(a,b)); 
			i=0;
			continue;
		}
		else
		{
			a[i]=ch;
			i++;
		}
	}
}
void None(map<string,string> &personnel,FILE *fp)
{
	int i=0;
	char ch;
	char a[10],b[10];
	while(1)
	{
		ch=fgetc(fp);
		if(ch==':')
		{
			break;
		}
		else
		{
			b[i]=ch;
			i++;
		}
			
		
	}
	b[i]='\0';
	i=0;
	while(1)
	{
		ch=fgetc(fp);
		if(ch==';')
		{
			break;
		}
		else
		{
			a[i]=ch;
			i++;
		}

	}
	a[i]='\0';
	personnel.insert(pair<string, string>(b,a));
}
int judge(map<string,string> sigma,string paper)
{
	map<string, string>::iterator iter;
	int flag=0;
	for(int i=0;i<paper.size();i++)
	{
		int j=0;
		for(iter = sigma.begin(); iter != sigma.end(); iter++)
		{
			
			if(paper[i]==iter->first[j])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			printf("输入纸袋符号有误，请重新输入\n");
			return 0;
		}
		flag=0;
	}
	return 1;
}
void Relu(map<string,string> &Delta,FILE *fp)
{
	char ch;
	while(1)
	{
		ch=fgetc(fp);
		if(ch==':')
			break;
	}
	
	int i=0,j=0;

	char a[10];
	char b[10];
	while(1)
	{
		i=0;
		ch=fgetc(fp);
		if(ch==';')
		{
			break;
		}
		while(1)
		{
			
			if(ch==')')
			{
				a[i]='\0';
				break;
			}
			else
			{
				if(ch=='('||ch==','||ch=='\n'||ch=='-'||ch=='>')
				{	
					ch=fgetc(fp);
					continue;
				}
				else
				{
					
					a[i]=ch;
					i++;
					ch=fgetc(fp);
				}
			}
		
	}
		
	i=0;
	ch=fgetc(fp);
	while(1)
	{
	
		if(ch==')')
		{
			b[i]='\0';
			break;
		}
		else
		{
			if(ch=='('||ch==','||ch=='-'||ch=='>')
			{	
				ch=fgetc(fp);
				continue;
			}
			else
			{
				
				b[i]=ch;
				i++;ch=fgetc(fp);
			}
		}
	
	}

	Delta.insert(pair<string, string>(a,b));
	}

	
}
int main()
{
	FILE *fp;
	char ch;
	string paper;
	map<string,string> Q;
	map<string,string> sigma;
	map<string,string> q0;
	map<string,string> Accept;
	map<string,string> Reject;
	map<string,string> Delta;
	if((fp = fopen("suc1.txt","rb" ))==NULL)
	{
		printf("打开文件错误\n");
		return 0;
	}

	translate(Q,fp);
	
	translate(sigma,fp);
	
	None(q0,fp);
	
	None(Accept,fp);
	
	None(Reject,fp);
	
	Relu(Delta,fp);	
	/*map<string, string>::iterator iter;
	 for(iter = Accept.begin(); iter != Accept.end(); iter++)  
    	cout<<iter->first<<' '<<iter->second<<endl;*/
	while(1)
	{
		cin>>paper;
		int i=judge(sigma,paper);
		if(!i)
		{
			continue;
		}
		else
		{
			char ar[20];
			char br[20];
			int f=0;
			int flag=1;
			int a=0;
			map<string, string>::iterator iter;
			iter=q0.begin();
			string s=iter->first;
			for(int c=0;c<s.size();c++)
			{
				br[f]=s[c];
				f++;
			}
			br[f]='\0';
			f=1;
			ar[0]='B';
			for(int c=0;c<paper.size();c++)
			{
				ar[f]=paper[c];
				f++;
			}
			
			for(int ff=f;ff<20;ff++)
			{
				ar[ff]='B';
			
			}
			while(1)
			{
				
				printf("此时图灵机的状态为：%s\n",br);
				for(int aa=0;aa<20;aa++)
				{
					if(ar[aa]=='x'||ar[aa]=='B')
					{
						continue;
					}
					printf("%c",ar[aa]);
				}
				printf("\n");
				int r;
				int v=0;
					int m=paper.size()-1;
					map<string, string>::iterator iter;
					iter=Accept.begin();
					for(r=0;r<strlen(br);r++)
					{
						
						if(br[r]!=iter->second[v])
						{
							break;
						}
						else
						{
							v++;
						}
					}
					if(r>=strlen(br))
					{
					
							break;
					}
				int e,q=0;
				
				for(iter = Delta.begin(); iter != Delta.end(); iter++)
				{
	
					for(e=1;e<iter->first.size()-1;e++)
					{
	
						if(iter->first[e]==br[e-1])
						{
					
							continue;
						}
						else
						{
							break;
						}
					}
					if(e>=iter->first.size()-1)
					{	
					
						if(iter->first[iter->first.size()-1]==ar[flag])
						{
							break;
						}
							
					}
				}
				f=2;
				for(e=iter->second.size()-1;e>=0;e--)
				{
					if(iter->second[e]=='L')
					{
						f=1;
						continue;
					}
				 	if(iter->second[e]=='R')
					{
						f=0;
						continue;
				
					}
					if(f==1||f==0)
					{
						if(iter->second[e]!='L'||iter->second[e]!='R')
						{
							ar[flag]=iter->second[e];
							if(f==1)
							{
								flag--;
								f=2;
						
								continue;
							}
							else if(f==0)
							{
								flag++;
								f=2;						
								continue;
							}
						}
					}
					else
					{
						map<string, string>::iterator it;
						it=Accept.begin();
						
						if(iter->second[e]==it->second[0]&&it->second.size()==1)
						{
							br[e]=iter->second[e];
							br[e+1]='\0';
						}
						else if(iter->second[e]!='B')
							br[e]=iter->second[e];
					}
				}
				
			}
		}
	}
	
	
	
/*	map<string, string>::iterator iter;
	 for(iter = Delta.begin(); iter != Delta.end(); iter++)  
    	cout<<iter->first<<' '<<iter->second<<endl;  */ 

    
}
