#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	int score=0;
	int count=0;//统计连续的2的个数 
	while(scanf("%d",&n) && n!=0) {
		if(n==1) {
			score++;
			count=0;//跳2中断，count置0 
		}
		else if(n==2){
			count++;
			score+=count*2;
		}	
	}
	printf("%d\n",score);
	return 0;
} 
