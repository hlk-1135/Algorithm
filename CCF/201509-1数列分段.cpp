#include<iostream>
#include<cstdio>
int a[1001];
int main()
{
	int i,n;
	int count;
	while(~scanf("%d",&n)) {
		count=1;
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		for(i=1;i<n;i++) {
			if(a[i]!=a[i-1])
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
