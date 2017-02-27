/*
10 3
3 4
4 5
5 6
使用二维数组时，是从前往后构造，利用了前面的数据。
而现在使用一维数组，为了保证前面的数据不丢失，只能从后往前构造 
*/
#include<stdio.h>
#define N 100
int w[N],c[N];
int value[N]={0};//使用一维数组 
int main()
{
	int i,j,m,n;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&w[i],&c[i]);
	}
	for(i=1;i<=n;i++) { //一共有n个物体 
		for(j=m;j>=w[i];j--) { //从后往前构造  
			if(value[j]<value[j-w[i]]+c[i])
				value[j]=value[j-w[i]]+c[i];
		}
	}
	printf("%d\n",value[m]);
}