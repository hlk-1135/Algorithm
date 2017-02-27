#include<stdio.h>
int main()
{
	int i,j,k,m,n;
	int min;
	while(scanf("%d",&n)!=EOF) {
		int a[100][100]={0};
		for(i=1;i<n;i++) {
			for(j=i+1;j<=n;j++) {
				scanf("%d",&a[i][j]); 
			} 
		}
		for(m=2;m<=n;m++) {   //到第m个站点 
			for(i=1;i<=n-m+1;i++) {  //从每一个站点开始 
				j=m+i-1;   //r(i,j)的长度为j 
				for(k=i;k<=j;k++) {  //找出某一站k，使r(i,k)+r(k,j)最小 
					min=a[i][k]+a[k][j];
					if(a[i][j]>min) {
						a[i][j]=min;
					}
				} 
			}
		}
		printf("%d\n",a[1][n]);
		putchar('\n');
	} 
	return 0;
}