#include<stdio.h>
int a[100]={0};
int set(int n)           //方法一 
{
	if(a[n]>0)
		return a[n];   //不为0时，退出递归 
	else 
	{
		a[n]=1;
		for(int i=1;i<=n/2;i++) 
		{
			a[n]+=set(i);
		}
		return a[n];
	}
}
int set2(int n)            //方法二 
{
	if(n==1)
		return 1;
	return set2(n/2*2-1)+set2(n/2);
}
int main()
{
	int n;
	printf("请输入一个自然数：\n");
	scanf("%d",&n);
	int count=set(n);
	int count1=set2(n);
	printf("set(n)产生的半数集的个数为：%d\n",count);
	printf("set2(n)产生的半数集的个数为：%d\n",count1);
} 
