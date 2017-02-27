/*
F[k][x]表示机器B所花费时间的最小值
F[k][x]=Min{F[k-1][x]+b[k],F[k-1][x-a[k]]}
F[k-1][x]+b[k]表示第k个作业由机器B来处理
F[k-1][x-a[k]]表示第k个作业由机器A处理
6
2 5 7 10 5 2
3 8 4 11 3 4
*/
#include<stdio.h>
#define N 100
int main()
{
	int i,j,n;
	int sum=0;
	int a[N]={0},b[N]={0},t[N][N]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(j=0;j<n;j++) {
		scanf("%d",&b[j]);
	}
	for(i=1;i<=n;i++) {
		for(j=0;j<=sum;j++) {
			if(j<a[i-1]) //在这个时间段交给b处理 
                t[i][j]=t[i-1][j]+b[i-1];
            else if(t[i-1][j-a[i-1]]>t[i-1][j]+b[i-1])
                t[i][j]=t[i-1][j]+b[i-1];
            else
                t[i][j]=t[i-1][j-a[i-1]];
		}
	}
	int min=1000000;
	for(i=0;i<=sum;i++) {
		j=t[n][i]>i?t[n][i]:i;
		if(min>j) {
			min=j;
		}
	}
	printf("%d\n",min);
	return 0;
} 
