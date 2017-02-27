#include<stdio.h>
int set(int n,int m)
{
	if(m==n || m==1)
		return 1;
	return set(n-1,m-1)+m*set(n-1,m);
}
int main()
{
	int m,n;
	int count=0;
	scanf("%d%d",&n,&m);
	count=set(n,m);
	printf("%d\n",count);
}
