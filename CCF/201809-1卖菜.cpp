#include<iostream>
#include<cstdio>
int a[10001];
using namespace std;
int main()
{
	int n;
	int i;
	while(scanf("%d",&n)!=EOF) {
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++) {
			if(i==0)
				printf("%d ",(a[0]+a[1])/2);
			else if(i==n-1)
				printf("%d\n",(a[i-1]+a[i])/2);
			else
				printf("%d ",(a[i-1]+a[i]+a[i+1])/3);
		}
	} 
	return 0;
} 
