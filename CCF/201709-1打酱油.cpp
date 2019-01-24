#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	int i,j,k;
	int num;
	while(scanf("%d",&n)!=EOF) {
		i=n/50;
		j=(n-50*i)/30;
		k=(n-50*i-30*j)/10;
		num=7*i+4*j+k;
		printf("%d\n",num);
	} 
	return 0;
} 
