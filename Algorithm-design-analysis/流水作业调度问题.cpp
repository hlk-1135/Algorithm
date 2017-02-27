/*
1)先执行t[i,1]<t[i,2],保证M2上没有等待。选择第一个作业时，让M2选择第一次等待时间最少的,
即t[i,1]越小，越靠前执行;
2)执行t[i,1]>=t[i,2]时，要保证最后一个作业在M2上执行时间最短，所以按照减序排列 
*/
#include<stdio.h>
#include<string.h>
#include<algorithm> 
#define N 100
using namespace std;

struct node {
	int time;//执行时间 
	int index;//作业序号
	bool group;//1代表第一个机器，0代表第二个机器 
};

bool cmp(node a,node b)
{//升序排序 
	return a.time<b.time; 
}
int main()
{
	int i,j,k,n;
	int a[N]={0},b[N]={0};
	int best[N];//最优调度序列 
	node c[N];
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d%d",&a[i],&b[i]);
	}
	for(i=0;i<n;i++) {  //n个作业中，每个作业的最小加工时间 
		c[i].time=a[i]>b[i]?b[i]:a[i];
		c[i].index=i;
		c[i].group=a[i]<=b[i];
		
	}
	sort(c,c+n,cmp);//按照c[]中作业时间增序排序
	j=0,k=n-1;
	for(i=0;i<n;i++) {
		if(c[i].group) { //第一组，从i=0开始放入到best[]中 
			best[j++]=c[i].index;
		}
		else {
			best[k--]=c[i].index;
		}
	}
	j=a[best[0]];//最优调度序列下的消耗总时间 
	k=j+b[best[0]];
	for(i=1;i<n;i++) {
		j+=a[best[i]];
		k=j<k?(k+b[best[i]]):j+b[best[i]];//消耗总时间的最大值 
	}
	printf("%d\n",k);
	for(i=0;i<n;i++) {
		printf("%d ",best[i]+1); 
	}
	printf("\n");
	return 0;
} 