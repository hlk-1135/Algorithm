#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a[10001]; 
int main()
{
	int i,j;
	int n,mutex;
	while(scanf("%d",&n)!=EOF) {
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]);
		}
		int min=abs(a[0]-a[1]);
		for(i=0;i<n;i++) {
			for(j=i+1;j<n;j++) {
				mutex=abs(a[i]-a[j]);	
				if(mutex<min)
					min=mutex;
			}
		}
		printf("%d\n",min);
	}
	return 0;
} 
