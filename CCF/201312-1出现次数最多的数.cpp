#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int a[10001];
int main()
{
	int i,n,num,sum;
	int count=0;
	int max=0;
	while(~scanf("%d",&n)) {
		memset(a,0,10001);
		for(i=1;i<=n;i++) {
			scanf("%d",&num);
			a[num]++;
			if(num>max)
				max=num;
		}
		for(i=1;i<=max;i++) {
			if(a[i]!=0 && a[i]>count) {
				count=a[i];
				sum=i;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
} 
