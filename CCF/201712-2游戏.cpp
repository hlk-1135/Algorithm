#include<iostream>
#include<cstdio>
using namespace std;
int a[10001];
int main()
{
	int i,j,n,k,sum,count;
	bool flag;
	while(scanf("%d%d",&n,&k)!=EOF) {
		flag=true;
		count=0;
		sum=0;
		for(i=1;i<=n;i++) {
			a[i]=i;
		}
		while(flag) {
			for(i=1;i<=n;i++) {
				if(a[i]!=0) {
					sum++;
					if(sum%k==0 || sum%10==k) {
						a[i]=0;
						count++;
					}
				}
			}
			if(count==(n-1))
				flag=false;
		}
		for(i=1;i<=n;i++) {
			if(a[i]!=0)
				printf("%d\n",i);
		}
	}
	return 0;
}
