/*
10 3
3 4
4 5
5 6
value[i][j]=max{value[i-1][j-w[i]]+c[i],value[i-1][j]} 前i个物体放入容量为j的背包的最大价值
放入第i个物体：value[i-1][j-w[i]]+c[i]
不放入第i个物体：value[i-1][j]
*/
#include<stdio.h>
#define N 100
int w[N],c[N];
int value[N][N]={0};
int main()
{
	int i,j,m,n;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&w[i],&c[i]);
	}
	for(i=1;i<=n;i++) { //一共有n个物体 
		for(j=w[i];j<=m;j++) {  //为了能放入物理，最小容量从w[i]开始 
			int p=value[i-1][j-w[i]]+c[i];//放入第i个物体的价值 
			int q=value[i-1][j];  //不放入 
			value[i][j]=p>q ? p:q;
		}
	}
	printf("%d\n",value[n][m]);
}