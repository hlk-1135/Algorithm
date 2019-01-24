#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int a[1001];
int main()
{
	int i,j,n;
	int num;
	while(~scanf("%d",&n)) {
		num=0;
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++) {
			for(j=i+1;j<n;j++) {
				if(abs(a[i]-a[j])==1)
					num++;
			}
		}
		printf("%d\n",num);
	}
	return 0;
} 
