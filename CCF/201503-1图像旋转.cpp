#include<iostream>
#include<cstdio>
using namespace std;
int a[1001][1001];
int main()
{
	int m,n,i,j;
	while(~scanf("%d%d",&n,&m)) {
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				scanf("%d",&a[i][j]);
			}
		}
		for(i=m-1;i>=0;i--) {
			for(j=0;j<n;j++) {
				if(j==n-1)
					printf("%d\n",a[j][i]);
				else
					printf("%d ",a[j][i]);
			}
		}
	}
	return 0;
}
