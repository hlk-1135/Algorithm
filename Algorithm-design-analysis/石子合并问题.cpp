/*
m[i][j] = m{m[i][k] + m[k+1][j] + v(i,j)} i<=k<j
最后一次合并为v(i,j)，不管在什么位置合并，v(i,j)的值都是一样的 
总的得分等于m[i,k]的得分加上m[k+1,j]的得分再加上v(i,j). 
*/
#include<stdio.h>
#define N 100
int a[N]={0};

int set(int i,int j)
{
	return a[j]-a[i-1];
}

int Merge_Min(int n)
{
	int i,j,k,r,temp;
	int min[N][N]={0};//第i堆到第j堆的所有得分 
	for(r=2;r<=n;r++) { //2到n堆 
		for(i=1;i<=n-r+1;i++) { //左端点 
			j=i+r-1;//截止点 
			min[i][j]=min[i][i]+min[i+1][j];
			for(k=i+1;k<j;k++) {
				temp=min[i][k]+min[k+1][j];
				if(min[i][j]>temp)
					min[i][j]=temp;
			}
			min[i][j]+=set(i,j);
		}
	}
	n=(n+1)/2; 
	int best=min[1][n];
	for(i=2;i<n;i++)
        if(min[i][i+n-1] && min[i][i+n-1]<best)
            best=min[i][i+n-1];
    return best;
}

int Merge_Max(int n)
{
	int i,j,k,r,temp;
	int min[N][N]={0};
	for(r=2;r<=n;r++) { //2到n堆 
		for(i=1;i<=n-r+1;i++) { //左边 
			j=i+r-1;
			min[i][j]=min[i][i]+min[i+1][j];
			for(k=i+1;k<j;k++) {
				temp=min[i][k]+min[k+1][j];
				if(min[i][j]<temp)
					min[i][j]=temp;
			}
			min[i][j]+=set(i,j);
		}
	}
	n=(n+1)/2; 
	int best=min[1][n];
	for(i=2;i<n;i++)
        if(min[i][i+n-1] && min[i][i+n-1]>best)
            best=min[i][i+n-1];
    return best;
}


int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		a[n+i]=a[i];
	}
	for(i=2;i<=2*n;i++) {
		a[i]+=a[i-1]; //当前到i的所有 
	}
	printf("%d\n",Merge_Min(2*n));
	printf("%d\n",Merge_Max(2*n));
	return 0;
}