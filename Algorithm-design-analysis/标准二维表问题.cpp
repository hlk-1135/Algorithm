#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int count;
	scanf("%d",&n);
	int sum=2*n;
	for(int i=0;i<pow(2,sum);i++)
	{
		int num0=0,num1=0;
		int k=i;
		int flag=1;
		for(int j=0;j<sum;j++)
		{
			if(k%2)
				num1++;
			else
				num0++;
			k/=2;
			if(num1>num0)
			{
				flag=0;
				break;
			}
		}
		if(flag && num0==n)
			count++;
	}
	printf("二维表的个数为:%d\n",count);
	return 0;
}