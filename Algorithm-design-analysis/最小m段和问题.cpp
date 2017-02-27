/*
n个数字，分成m段，使这m段子序列的和的最大值达到最小
 
状态转移方程：s[i][j]=min{max{s[i][1]-s[k][1],s[k][j-1]}}
*/

#include<stdio.h>
#include<string.h>
int a[20];
int s[100][100];
int set(int n,int m)
{
	int i,j,k,temp,maxsum;
	for(i=1;i<=n;i++) {  //s[i][1]表示前i个数字分成1段的值,即前i个数字之和   
		s[i][1]=s[i-1][1]+a[i];
	}
	for(j=2;j<=m;j++) {    //从2开始,分割为m段 
		//将前i个数字分割成j段(最小需要j个数字,从i=j开始即可，无需从2开始)
		for(i=j;i<=n;i++) {
			temp=10000000;
			for(k=j;k<i;k++) {
				maxsum=(s[i][1]-s[k][1])>s[k][j-1]?(s[i][1]-s[k][1]):s[k][j-1];
				if(temp>maxsum) {
					temp=maxsum;
				}
			}
			s[i][j]=temp;
		}
	}
	return s[n][m];
}

int main()
{
	int i,j,n,m;
	scanf("%d%d",&n,&m);
	memset(s,0,sizeof(s));
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	memset(s,0,sizeof(s));
	printf("%d\n",set(n,m));
	return 0;
}