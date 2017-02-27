/*
6
2 5 7 10 5 2
3 8 4 11 3 4
任务分配给两个机器，两个机器上找时间最大的，最后找最小的 
*/
#include<stdio.h>
#include<math.h>
#define N 100
int main()
{
	int i,j,n;
	int temp=0,time=1000000;
	int a[N]={0},b[N]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]); 
	for(i=0;i<=pow(2,n);i++) {
		int sum1=0,sum2=0,k=0;
		int num=i;
		for(j=0;j<n;j++) {
			if(num%2)
				sum1+=a[k];
			else
				sum2+=b[k];
			k++;
			num/=2;
		}
		temp=sum1>sum2?sum1:sum2;
		if(temp<time) {
			time=temp;
		}		
	}
	printf("%d\n",time);
	return 0;
}
