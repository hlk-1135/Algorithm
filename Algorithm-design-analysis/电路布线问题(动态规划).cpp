/*
1)当i=1时，size(i,j)={0, 当j<p(1)
					  {1, 当j>=p(1)
2)当i>1时，size(i,j)={size(i-1,j), 当j<p(i)
					{max{size(i-1,j),size(i-1,p(i)-1)+1},当j>=p(i)
10
8 7 4 2 5 1 9 3 10 6
*/
#include<stdio.h>
#define N 100 
int main()
{
	int i,j,n;
	int a[N],p[N][N];
	scanf("%d",&n);
	for(i=1;i<=n;i++) {//下标从1开始
		scanf("%d",&a[i]);
	}
	for(j=1;j<=n;j++) {
		if(j<a[1])
			p[1][j]=0;
		else
			p[1][j]=1;
	}
	for(i=2;i<=n;i++) {
		for(j=1;j<=n;j++) {
			if(j<a[i])//当j<c[i]的情形  
				p[i][j]=p[i-1][j];
			else
				p[i][j]=p[i-1][j]>p[i-1][a[i]-1]+1 ? p[i-1][j] : p[i-1][a[i]-1]+1;
		}
	}
	printf("%d\n",p[n][n]);
	return 0;
} 