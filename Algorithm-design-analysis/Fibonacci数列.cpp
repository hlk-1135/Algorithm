#include<stdio.h>
int set(int n) 
{
	int a1=1,a2=1;
	int i,c;
	if(n==1 || n==2)
		return 1;
	if(n>2) {
		for(i=2;i<n;i++) {
			c=(a1+a2)%10007;
			a2=a1;
			a1=c;
		}
	}
	return c;
		 
} 
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",set(n));
	return 0;
}
