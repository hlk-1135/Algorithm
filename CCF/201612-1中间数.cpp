#include<iostream>
#include<algorithm>
#include<cstdio>
int a[1001];
using namespace std;
int main()
{
	int i,j,k,n;
	int num1,num2;
	while(~scanf("%d",&n)) {
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		bool flag=false;
		for(i=0;i<n;i++) {
			num1=num2=0;
			for(j=0;j<i;j++) {
				if(a[j]<a[i])
					num1++;
			}
			for(k=i+1;k<n;k++) {
				if(a[k]>a[i])
					num2++;	
			}
			if(num1 == num2) {
				flag=true;
				printf("%d\n",a[i]);
				break;
			}
		}
		if(!flag)
			printf("-1\n");
	}
	return 0;
}
