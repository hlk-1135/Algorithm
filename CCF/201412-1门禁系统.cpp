#include<iostream>
#include<string.h>
#include<cstdio>
int a[1001];
int b[1001];
int main()
{
	int i,n;
	while(~scanf("%d",&n)) {
		for(i=1;i<=n;i++) {
			scanf("%d",&a[i]);
		}
		for(i=1;i<=1001;i++) {
			b[i]=1; 
		}
		for(i=1;i<=n;i++){
			if(i==n) {
				printf("%d\n",b[a[i]]);
				b[a[i]]++;
			}
			else {
				printf("%d ",b[a[i]]);
				b[a[i]]++;
			}
				
		}
	}
	return 0;
}
