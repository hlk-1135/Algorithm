#include<stdio.h>
int set(int n,int m)
{
	if(m==n || m==1)
		return 1;
	//1:把前n-1个元素分成m-1份，然后第n个元素单独放。
    //2:把前n-1个元素分成m份，然后第n个素分别插入到这m个集合中
	return set(n-1,m-1)+m*set(n-1,m);
}
int main()
{
	int m,n;
	int count=0;
	printf("请输入元素个数:\n"); 
	scanf("%d",&n);
	for(m=1;m<=n;m++)
	{
		count+=set(n,m);
	}
	printf("非空子集数为：%d\n",count);
}