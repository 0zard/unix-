#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define LEN sizeof(struct Node)
#define LEN1 sizeof(struct Memory)
int _setMemo=1024;
int Flag=0;
typedef struct Memory
{
	char name[8];
	int adress;
	char space[1024];
	int m;
	struct Memory *next;
}Memory,*Mee;
typedef struct Node
{
	char name[10];
	char Type[8];
	int address;
	int length;
	struct Node *next;
}Node,*Nodee;
struct Node *Init()
{
	
	struct Node *L;
	L=(struct Node *)malloc(LEN);
	L->next=NULL;
	strcpy(L->name,"NULL");
	strcpy(L->Type,"NULL");
	L->address=0;
	L->length=0;
	return L;
}
struct Memory *init()
{
	struct Memory *M;
	M=(struct Memory *)malloc(LEN1);
	M->next=NULL;
	strcpy(M->name,"NULL");
	M->adress=0;
	return M;
}
struct Node *Search(struct Node *M,char *input)
{
	M=M->next;
	while(M)
	{
		if(strcmp(M->name,input)==0)
			break;
		M=M->next;
	}
	return M;
}
struct Memory *S(struct Memory *M,int me)
{
	M=M->next;
	while(M)
	{
		if(M->adress==me)
			break;
		M=M->next;
	}
	return M;
}
int search(struct Node *L,char *input)
{
	L=L->next;
	while(L)
	{
		if(strcmp(L->name,input)==0)
		{
		///	printf("%s",L->name);
		//	printf("%s\n",input);
			printf("变量名已存在!!!\n");
			printf("请重新输入!!!\n\n");
			
			return 1;
		}
		L=L->next;
	}
}
int Ex(struct Node *head,struct Node *L,char *input,char *exchange)
{
	int j=0,i;
	for(i=0;i<strlen(input)-2;i++)
	{
		
		if(input[i]==' ')
		{
				break;
		}
		
	}
	for(i=i+1;i<strlen(input)-1;i++)
	{
		
		if(input[i]=='[')
		{
			exchange[j]='\0';
			break;
		}
		else
		{
			exchange[j]=input[i];
			j++;
		}
	
	}

	return search(head,exchange);
}
int Ex1(struct Node *head,struct Node *L,char *input,char *exchange)
{
	int j=0,i;

	for(i=0;i<strlen(input)-1;i++)
	{
		
		if(input[i]==' ')
		{
				break;
		}
		
	}
	for(i=i+2;i<=strlen(input)-1;i++)
	{

			exchange[j]=input[i];
			j++;
	}
	exchange[j]='\0';
	return search(head,exchange);
}
int Ex2(struct Node *head,struct Node *L,char *input,char *exchange)
{
	int j=0,i;

	for(i=0;i<strlen(input)-1;i++)
	{
		
		if(input[i]==' ')
		{
				break;
		}
		
	}
	for(i=i+1;i<=strlen(input)-1;i++)
	{

			exchange[j]=input[i];
			j++;
	}
	exchange[j]='\0';
	return search(head,exchange);
}
int Num(char *input)
{
	int i=0,sum=0,j=0;
	for(i=0;i<strlen(input);i++)
	{
		if(input[i]>='0'&&input[i]<='9')
		{
			int a=input[i]-'0';
			sum=sum*pow(10,j)+a;
			j++;
		}
	}
	return sum;
}
int NUM(char *input)
{
	int i=0,sum=0,j=0;
	for(i=0;i<strlen(input);i++)
	{
		if(input[i]>='0'&&input[i]<='9')
		{
			int a=input[i]-'0';
			sum=sum*pow(10,j)+a;
			j++;
		}
		if(input[i]=='=')
		{
			break;
		}
	}
	return sum;
}
void show(struct Node *L,struct Memory *M)
{
	L=L->next;	
	printf("符号表：\n");
	while(L)
	{
		printf("变量名是：%s\n",L->name); 
		printf("变量%s的类型是：%s\n",L->name,L->Type);
		printf("变量的长度和地址是：%dB %d\n",L->length,L->address);
		L=L->next; 
	}
	printf("\n");
	M=M->next;
	printf("内存表：\n");
	while(M)
	{
		printf("变量名是：%s\n",M->name);
		printf("变量的地址是：%d\n",M->adress);
		M=M->next;
	}
	printf("\n");
}
void insert(struct Node *head,struct Node *L,struct Memory *M,char *input,char *in,int n)
{
	struct Node *List;
	struct Memory *Me;
	struct Node *Li;
	struct Memory *Me1;
	char exchange[20];
	
	List=(struct Node *)malloc(LEN);
	Me=(struct Memory *)malloc(LEN1);
	Li=(struct Node *)malloc(LEN);
	Me1=(struct Memory *)malloc(LEN1);
	
	Me->next=NULL;
	List->next=NULL;
	Li=L;
	
	Me1=M;
	int num=Num(input);
	
	int l=Ex(head,L,input,exchange);
	if(l==1)
	{
		Me->m=num;
		strcpy(List->name,exchange);
		strcpy(List->Type,in);
		List->length=0;
		List->address=L->address;
		Me->adress=Me->adress;
		strcpy(Me->name,exchange);
		Li->next=List;
		Li=List;
		Me1->next=Me;
		Me1=Me;
		
		return;
	}
	Me->m=num;
	strcpy(List->name,exchange);
	strcpy(List->Type,in);
	List->length=num;
	if(_setMemo-num<0)
	{
		return;
	}
	else
		_setMemo=_setMemo-num;
	if(num%2==1&&n==2)
	{
		
		List->address=L->address+num+1;
		
	}
	else if(num%2==0&n==2)
	{
		List->address=L->address+num;
	}
	else if(num%4==1||num%4==2||num%4==3&&n==4)
	{
		int ad=L->address;
	
		List->address=ad+4*num;	
		while(1)
		{
			if(List->address%4==0)
			{
				break;
			}
			else
			{
				List->address=List->address+2;
			}
		}
		
	}
	else if(num%4==0&&n==4)
	{
		List->address=L->address+num;
	}
	Me->adress=List->address;
	strcpy(Me->name,exchange);
	Li->next=List;
	Li=List;
	Me1->next=Me;
	Me1=Me;


}
void Oinsert(struct Node *head,struct Node *L,struct Memory *M,char *input,char *in)
{
	struct Node *List;
	struct Memory *Me;
	struct Node *Li;
	struct Memory *Me1;

	char exchange[20];
	List=(struct Node *)malloc(LEN);
	Me=(struct Memory *)malloc(LEN1);
	Li=(struct Node *)malloc(LEN);
	Me1=(struct Memory *)malloc(LEN1);	

	Me->next=NULL;
	List->next=NULL;
	Li=L;
	Me1=M;
	int l=Ex1(head,L,input,exchange);
	if(l==1)
	{
		strcpy(List->name,exchange);
		strcpy(List->Type,in);
		List->length=0;
		List->address=L->address;
		Me->adress=Me->adress;
		strcpy(Me->name,exchange);
		Li->next=List;
		Li=List;
		Me1->next=Me;
		Me1=Me;
		return;
		
	}
	strcpy(List->name,exchange);
	strcpy(List->Type,in);
	List->length=4;
	List->address=L->address+4;
	while(1)
	{
		if(List->address%4==0)
		{
			break;
		}
		else
		{
			List->address=List->address+2;
		}
	}
	Me->adress=List->address;
	strcpy(Me->name,exchange);
	Li->next=List;
	Li=List;
	Me1->next=Me;
	Me1=Me;
	
}
void insert0(struct Node *head,struct Node *L,struct Memory *M,char *input,char *in,int n)
{
	struct Node *List;
	struct Memory *Me;
	struct Node *Li;
	struct Memory *Me1;
	
	char exchange[20];
	List=(struct Node *)malloc(LEN);
	Me=(struct Memory *)malloc(LEN1);
	Li=(struct Node *)malloc(LEN);
	Me1=(struct Memory *)malloc(LEN1);
	Me->next=NULL;
	List->next=NULL;
	Li=L;
	Me1=M;
	int l=Ex2(head,L,input,exchange);	
	if(l==1)
	{
		strcpy(List->name,exchange);
		strcpy(List->Type,in);
		List->length=0;
		List->address=L->address;
		Me->adress=Me->adress;
		strcpy(Me->name,exchange);
		Li->next=List;
		Li=List;
		Me1->next=Me;
		Me1=Me;
		return;
	}
	strcpy(List->name,exchange);
	strcpy(List->Type,in);
	List->length=n;
	List->address=L->address+n;
	Me->adress=List->address;
	strcpy(Me->name,exchange);
	Li->next=List;
	Li=List;
	Me1->next=Me;
	Me1=Me;

	
}
void Valuee(struct Node *head,struct Memory *h,char *name_,char valuee,int n)
{

	struct Memory *Me;
	struct Node *L;
	Me=(struct Memory *)malloc(LEN1);
	L=(struct Node *)malloc(LEN);
	L=Search(head,name_);
	Me=S(h,L->address);
	
	if(n>=Me->m)
	{
		printf("数组下标过大\n");
		return;
	}
	Me->space[n]=valuee;
}
void VE(struct Node *head,struct Memory *h,char *name_,char *valuee)
{

	struct Memory *Me;
	struct Node *L,*L1;
	L=(struct Node *)malloc(LEN);
	L1=(struct Node *)malloc(LEN);
	Me=(struct Memory *)malloc(LEN1);
	struct Memory *M;
	M=(struct Memory *)malloc(LEN1);
	L=Search(head,name_);
	L1=Search(head,valuee);
	Me=S(h,L->address);
	M=S(h,L->address);
	strcpy(Me->space,M->space);	
}
void VEE(struct Node *head,struct Memory *h,char *name_,char *valuee)
{
	struct Memory *Me;
	struct Node *L;
	L=Search(head,name_);
	Me=S(h,L->address);
	strcpy(Me->space,valuee);
}
void vess(struct Node *head,struct Memory *h,char *name_,char *valuee)
{
	struct Memory *Me;
	struct Node *L,*L1;
//	Me=Search(head,name_);
	struct Memory *M;
	L=Search(head,valuee);
	L1=Search(head,name_);
	M=S(h,L->address);
	Me=S(h,L1->address);
	Me->space[0]=Me->space[0]+M->space[0]-'0';
}

void display(struct Memory *L,char *in,int num)
{
	L=L->next;
	int i;
	while(L)
	{
		
		if(strcmp(L->name,in)==0)
		{
			printf("%c\n",L->space[num]);
			break;
		}
		L=L->next; 
	}
}
int Checkinput(struct Node *head,struct  Memory *h,struct Node *L,struct  Memory *M,char *input)
{
	
	int Flag=0;
	char a[]={"char"};
	char shor[]={"short"};
	char inq[]={"int"};
	char floa[]={"float"};
	char chaxing[]={"char *"};
	char shortt[]={"short *"};
	char intt[]={"int *"};
	char floatt[]={"float *"};
	int flag=0,i=0,j;
	if(!flag)
	{
		for(i=0;i<4;i++)//char []
		{
			if(input[i]!=a[i])
					break;	
		}
		
		if(i>=4&&input[strlen(input)-1]==']')
		{
			
			flag=1;
			
			insert(head,L,M,input,a,2);
		
		}
		else if(i>=4&&input[i+1]=='*')
		{
			flag=1;
			Oinsert(head,L,M,input,a);
		}
		else if(i>=4&&input[strlen(input)-1]!=']')
		{
			flag=1;
			insert0(head,L,M,input,a,2);
		}
		
	}
	if(!flag)//shor[]
	{
		for(i=0;i<5;i++)
		{
			if(input[i]==shor[i])
				continue;
			else
				break;
		}
		if(i>=5&&input[strlen(input)-1]==']')
		{
			flag=1;
		
			insert(head,L,M,input,shor,2);
		}
		else if(i>=5&&input[i+1]=='*')
		{
			flag=1;
			Oinsert(head,L,M,input,shortt);
			
		}
		else if(i>=5&&input[strlen(input)-1]!=']')
		{
			flag=1;
			insert0(head,L,M,input,shortt,2);
		}
	
	}
	if(!flag)//inq[]
	{
		for(i=0;i<3;i++)
		{
			if(input[i]==inq[i])
				continue;
			else
				break;
		}
		if(i>=3&&input[strlen(input)-1]==']')
		{
		
			flag=1;
		
			insert(head,L,M,input,inq,4);
		}
		else if(i>=3&&input[i+1]=='*')
		{
			flag=1;
			Oinsert(head,L,M,input,intt);
		}
		else if(i>=3&&input[strlen(input)-1]!=']')
		{
			flag=1;
			insert0(head,L,M,input,inq,4);
		}
		
	}
	if(!flag)//floa[]
	{	
		for(i=0;i<5;i++)
		{
			if(input[i]==floa[i])
				continue;
			else
				break;
		}
		if(i>=5&&input[strlen(input)-1]==']')
		{
			flag=1;	
			insert(head,L,M,input,floa,4);
		}
		else if(i>=5&&input[i+1]=='*')
		{
			flag=1;
			Oinsert(head,L,M,input,floatt);
		}
		else if(i>=5&&input[strlen(input)-1]!=']')
		{
			flag=1;
			insert0(head,L,M,input,floa,4);
		}
	}
	if(!flag)
	{
		int y,x=0,num,k=0,fla=0,q=0;

		for(y=0;y<strlen(input);y++)
		{
			if(input[y]=='=')
			{
				fla=1;
				break;
			}
			if(input[y]=='+')
			{
				fla=2;
				break;
			}
		}
		if(fla==1)
		{
			int a=0;
			if(!a)
			{
				char name_[10];
				char valuee[10];
				for(y=0;y<strlen(input);y++)
				{
					name_[x]=input[y];
					if(input[y]=='[')
					{
						a=1; 
						name_[x]='\0';
						num=NUM(input);
						
						Valuee(head,h,name_,input[strlen(input)-1],num);
						break;
					}
					x++;
				}
			
			}
			if(!a)
			{
				char name_[10];
				char valuee[10];
				y=0,x=0,num=0,k=0,q=0;
				for(y=0;y<strlen(input);y++)
				{
				
					name_[x]=input[y];
					
					if(input[y]=='=')
					{
							name_[x]='\0';
							
							break;
					}
							x++;
				}
				for(y=0;y<strlen(input);y++)
				{
					if(input[y]=='&')
					{
						a=1;
						valuee[0]=input[y+1];
						valuee[y]='\0';	
						VE(head,h,name_,valuee);	
						break;
					}
				}
				
			}
			if(!a)
			{
				char name_[10];
				char valuee[10];
				y=0,x=0,num=0,k=0,q=0;
				for(y=0;y<strlen(input);y++)
				{
					name_[x]=input[y];
					if(input[y]=='=')
					{	
						name_[x]='\0';
						a=1;
						break;
					}
					x++;
				}
				
				for(y=0;y<strlen(input);y++)
				{
					if(input[y]=='=')
					{
						break;
					}
				}
				x=0;
				for(y=y+1;y<strlen(input);y++)
				{
					
					valuee[x]=input[y];
					x++;
				}
				valuee[x]='\0';	
				if(a)
				{
					VEE(head,h,name_,valuee);
				}
			}
			
		}
		else if(fla==0)
		{
			int l,c=0;
			char name_[10];
			int ne=Num(input);
			for(l=0;l<strlen(input);l++)
			{
				 name_[c]=input[l];
				 if(input[l]=='[')
				 {
				 	name_[c]='\0';
				 	break;
				 }
				 c++;
			}
			display(h,name_,ne);
			return 1;
		}
		else if(fla==2)
		{
			int l,c=0;
			char name_[10];
			char vae[10];
			for(y=0;y<strlen(input);y++)
				{
					name_[x]=input[y];
					if(input[y]=='+')
					{	
						name_[x]='\0';
					
						break;
					}
					x++;
				}
				vae[0]=input[y+1];
				vae[1]='\0';
				vess(head,h,name_,vae);
		}
		return 1;
	}
}
int main()
{
	struct Node *L,*p;
	L=Init();
	p=L;
	struct Memory *M,*h;
	
	M=init();
	h=M;

	while(1)
	{
		
		char input[20];
		gets(input);
	
		if(input[0]=='1')
		{
			return 0;
		}
		int i=0,flag=0;
		
		if(input[i]=='i'||input[i]=='f'||input[i]=='s'||input[i]=='c')
		{
			flag=1;
		}
		if(flag==0)
		{
			Checkinput(p,h,L,M,input);	
		}
		else
		{
			
			Checkinput(p,h,L,M,input);
			show(p,h);
	
			L=L->next;
			M=M->next;
	
			
		}
	}
}

