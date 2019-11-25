#include<stdio.h>
int main(){
	int q=1;
	int *p=&q;
	double e=1.8;
	double *r=&e;
	printf("%d\n",sizeof(p));
	printf("%d\n",sizeof(r));
	printf("%p\n",p);
	printf("%p\n",r);
	printf("%d\n",*p);
	printf("%f\n",*r);
	return 0; 
	
} 
