#include<iostream>
#include<string.h>
#include<math.h>
#include<cstdio>
using namespace std;
int a[501];
int main()
{
	int n;
	int i,j,num;
	while(~scanf("%d",&n)) {
		num=0;
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++) {
			for(j=i+1;j<n;j++) {
				if(abs(a[i]) == abs(a[j]))
					num++;
			}
		}
		printf("%d\n",num);
	}
	return 0;
}
