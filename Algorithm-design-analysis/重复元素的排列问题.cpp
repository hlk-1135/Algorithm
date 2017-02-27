#include<stdio.h>
#include<string.h>
int count=0;
void swap(char &a,char &b)
{
	char temp;
	temp=a;
	a=b;
	b=temp;
}
int finish(char list[],int k,int i)
{//第i个元素是否在前面元素[k...i-1]中出现过
	if(i>k)
	{
		for(int j=k;j<i;j++)
			if(list[j]==list[i])
				return 0;	
	}
	return 1;
}
void perm(char list[],int k,int m)
{
	if(k==m)    //当只剩下一个元素时则输出 
	{
		count++;
		for(int i=0;i<=m;i++)
			printf("%c",list[i]);
		putchar('\n');
	}
	for(int i=k;i<=m;i++)  //还有多个元素待排列，递归产生排列
	{
		if(finish(list,k,i))
		{
			swap(list[k],list[i]);
			perm(list,k+1,m);
			swap(list[k],list[i]);
		}
	}		
}
int main()
{
	int i,n;
	printf("请输入元素个数:\n"); 
	scanf("%d",&n);
	printf("请输入待排列的元素:\n");
	getchar();
	char *a=new char[n];
	for(i=0;i<n;i++)
		scanf("%c",&a[i]);
	printf("所有不同排列为:\n");
	perm(a,0,n-1);
	printf("排列总数为：%d\n",count);
	return 0;
} 