#include<stdio.h>
int a[100]={0};
int set(int n)
{
	if(a[n]>0)
		return a[n];   //不为0时，退出递归 
	else 
	{
		a[n]=1;
		for(int i=1;i<=n/2;i++) 
		{
			a[n]+=set(i);
			if(i>10 && (2*(i/10)<=i%10))  //如果是两位数，而且十位比个位的一半小，则产生重复元素
				a[n]-=a[i/10];
		}
		return a[n];
	}
}
int main()
{
	int n;
	printf("请输入一个自然数：\n");
	scanf("%d",&n);
	int count=set(n);
	printf("产生的半数集的个数为：%d\n",count);
} 
