#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int a[1001];
int main()
{
	int i,n;
	int max=0;
	while(~scanf("%d",&n)) {
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		for(i=1;i<n;i++) {
			int v=abs(a[i]-a[i-1]);
			if(v>max)
				max=v;
		}
		printf("%d\n",max);
	}
	return 0;
}
