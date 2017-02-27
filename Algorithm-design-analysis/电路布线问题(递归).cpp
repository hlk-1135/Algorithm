#include<stdio.h>
#define N 100
int a[N];
int fun(int i,int j)
{
	if(i==0) {
		if(j>=a[i])
			return 	1;
		else
			return 0;
	}
	if(j<a[i])
		return fun(i-1,j);
	int m=fun(i-1,a[i]-1)+1;
	int n=fun(i-1,j);
	return m>n?m:n;
}
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	printf("%d\n",fun(n-1,n-1)); 
	return 0;
}
//7 6 3 1 4 0 8 2 9 5