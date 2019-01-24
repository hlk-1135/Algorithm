#include<iostream>
#include<algorithm>
#include<cstdio>
int a[1001];
using namespace std;
int main()
{
	int i,n;
	while(~scanf("%d",&n)) {
		for(i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		int mid=(n+1)/2;
		if(n%2) {
			if(a[mid]==a[mid-1] && a[mid]==a[mid+1])
				printf("%d\n",a[mid]);
			else if(a[mid]!=a[mid-1] && a[mid]!=a[mid+1])
				printf("%d\n",a[mid]);
			else
				printf("-1\n");
		} else { 
			//ÓÐÎÊÌâ125556
			if(a[mid]!=a[mid+1])
				printf("-1\n");
			else
				printf("%d\n",a[mid]);
		}
	}
	return 0;
}
