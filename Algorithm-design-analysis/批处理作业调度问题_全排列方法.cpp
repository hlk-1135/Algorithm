#include<stdio.h>
#define N 100
int n;
int a[N]={0},b[N]={0}; //作业在两台机器上的运行时间 
int c[N]={0},bestc[N]={0};
int f1=0,f2[N]; 
int count=0;
int best=1000000;

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void traceback(int num)
{
	int i;
	if(num>n) {
		if(count<best) { //更新最小时间和，最佳解决方案 
			best=count;
			for(i=1;i<=n;i++)
				bestc[i]=c[i];
		}
		return ;
	}
	for(i=num;i<=n;i++) {
		f1+=a[c[i]]; //第一台机器一直在运行
		f2[num]=(f2[num-1]>f1 ? f2[num-1] : f1) + b[c[i]];//关键代码(用数组标记,回溯时无需还原)
		count+=f2[num];//count只求第二台机器的时间和 
		swap(c[i],c[num]);//全排列进行交换 
		if(count<best)
			traceback(num+1);
		swap(c[i],c[num]);
		count-=f2[num];
		f1-=a[c[i]];
	}
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
	}
	for(i=1;i<=n;i++) { //全排列的初始化 
		c[i]=i;  
	}
	traceback(1);
	printf("%d\n",best);
	for(i=1;i<=n;i++) {
		printf("%d ",bestc[i]);
	}
	printf("\n");
	return 0;
}