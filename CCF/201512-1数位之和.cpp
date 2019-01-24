#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	int sum;
	while(~scanf("%d",&n)) {
		sum=0;
		while(n) {
			sum+=n%10;
			n/=10;
		}
		printf("%d\n",sum);
	}
	return 0;
}
