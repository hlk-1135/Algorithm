#include<stdio.h>
#define Max 10000
int main()
{   
	int result[Max]={0};
 	int len=1;    //初始位数为1 
 	int flag=0;    //进位的值
    result[0]=1;   //初始结果为1
    int num;
    printf("请输入一个数字:\n"); 
    scanf("%d",&num);
	for(int j=2;j<=num;j++) 
	{
		for(int i=0;i<len;i++)
		{
			int sum=result[i]*j+flag;  
            result[i]=sum%10;  
            flag=sum/10;  
        } 
        while(flag!=0)
		{//最高位进位值不为0时,更新位数 
            result[len]=flag%10;  
            len++;
            flag/=10;  
        }  
    }
	printf("%d的阶乘结果为:\n",num);
    for(int i=len-1;i>=0;i--)
		printf("%d",result[i]); 
 }
