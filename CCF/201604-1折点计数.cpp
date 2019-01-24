#include<iostream>
#include<cstdio>
using namespace std;
int a[1001];
int main()
{
	int i,n;
	int count;
	while(~scanf("%d",&n)) {
		count=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<n-1;i++) {
			if(((a[i]-a[i-1])>0 && (a[i]-a[i+1])>0) || 
			((a[i]-a[i-1])<0 && (a[i]-a[i+1])<0))
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
