#include<stdio.h>
int main()
{
	int j,k,n,count;
	int index=0,sum=0;
	int i=2;
	int a[100]={0};
	a[2]=2;
	scanf("%d",&n);
	while(n-sum>=i) { //从2开始，对n进行分解 
		sum+=i;
		a[i]=i;
		i++;
		index++;
	} 
	//例如：19
	// 2，3，4，5   剩余5，全部加1，还剩1，最后一位加1即可。 
	int p=(n-sum)/index; //整体全部累加 
	int q=(n-sum)%index; //只从后往前，加最后剩余的 
	for(j=i-1;j>=2;j--) {
		a[j]+=p;
	}
	for(k=i-1;k>i-1-q;k--) {
		a[k]++;
	}
	for(j=2;j<index+2;j++) {
		printf("%d  ",a[j]);	
	} 
}