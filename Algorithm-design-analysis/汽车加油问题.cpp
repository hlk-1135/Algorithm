#include<stdio.h>
int main()
{
	int i,n,k;
	scanf("%d%d",&n,&k);
	int a[k+1];
	int count=0;
	int sum=0;
	for(i=0;i<=k;i++) {
		scanf("%d",&a[i]);
	}
	//第一种方法 
	for(i=0;i<k;i++) {
		sum+=a[i];
		if(n-sum<a[i+1]){
			sum=0;
			count++;
		}
	}
	//第二种方法 
//	for(i=0,sum=0;i<=k;i++) {
//		sum+=a[i];
//		if(sum>n) {
//			count++;
//			sum=a[i];
//		}
//	}
	printf("%d\n",count);
	return 0;
} 
