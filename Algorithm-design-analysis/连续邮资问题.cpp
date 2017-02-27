/*
最多可以贴m张邮票，所以回溯时traceback选择了贴第几张邮票
count从1开始 
*/ 
#include<stdio.h>
int n,m; 
int a[100];
int count=1,sum=0;
int flag;
void traceback(int num)
{
	int i;
	if(flag)
		return ;
	if(num==m) {   
		if(sum==count) {
			flag=1;
		}
		return ;
	}
	for(i=0;i<=n;i++) { //一共有n种邮票可选,但是还可以不贴 
		sum+=a[i];
		traceback(num+1);
		sum-=a[i];
	}
}

int main()
{
	int i;
	scanf("%d%d",&n,&m);
	a[0]=0;
	for(i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	while(1) {
		flag=0;
		traceback(0);
		if(flag==0) //第一次贴不出满足的邮票，终止 
			break;
		count++;
	}	
	printf("%d\n",count);
	return 0;
}