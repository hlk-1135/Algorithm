/*
ABCBDAB
BDCABA
*/ 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
char a[N],b[N];
int p=0,q=0;

int fun(int m,int n)
{//ตÝน้ 
	if(m<0 || n<0)
		return 0;
	if(a[m]==b[n])
		return fun(m-1,n-1)+1;
	p=fun(m-1,n);
	q=fun(m,n-1);
	return p>q?p:q;
}

int main()
{
	int len_a,len_b;
	scanf("%s",a);
	scanf("%s",b);
	len_a=strlen(a);
	len_b=strlen(b);
	printf("%d\n",fun(len_a-1,len_b-1));
	return 0;
}
