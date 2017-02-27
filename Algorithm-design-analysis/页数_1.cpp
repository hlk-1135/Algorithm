#include<stdio.h>
#include<math.h>
int a[10]={0};

void number_count(int n)
{
	int high,low;
	int num=n;
	int len=log10(n);
	for(int i=0;i<=len;i++)
	{
		high=num/pow(10,len-i);//求出最高位的数字 
		low=num%(int)pow(10,len-i);//剩余的数 
		
		a[high]+=low+1;
		
		for(int j=0;j<high;j++)
		{
			a[j]+=pow(10,len-i);
			for(int k=0;k<10;k++)
				a[k]+=(len-i)*pow(10,len-i-1);
		} 
		num=low;			
	}
	for(int i=0;i<=len;i++)  //去掉多余的0 
        a[0]-=(int)pow(10,i);  
			
}
int main()
{
	int num;
	scanf("%d",&num);
	number_count(num);
	for(int i=0;i<10;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
