#include<stdio.h>
#include<string.h>
int combine(int m,int n)
{//排列组合求值 
	int sum1=1;
	int sum2=1;
	if(m>n)
		return 0;
	if(2*m>n)
		m=n-m;
	for(int i=1;i<=m;i++){
		sum1*=n-i+1;
		sum2*=i;
	}
	return sum1/sum2;
}
int count(char str[],int low)
{
	int sum=0;
	char high=str[0];
	int len=strlen(str);
	int temp=low;
	for(int k=1;k<=high-'a'-low;k++)
	{//长度和字符串相等的，在首字母之前的 
		sum+=combine(len-1,26-temp-k);
	}
	if(len>1)
	{
		sum+=count(&str[1],high-'a'+1);  //递归,长度减一 
	}	
	return sum;
}
int main()
{
	int n;
	printf("请输入字符串的个数:\n"); 
	scanf("%d",&n);
	while(n--){
		printf("请输入字符串："); 
		char str[10];
		scanf("%s",str);
		int sum=0;
		for(int i=1;i<strlen(str);i++){  //长度小于字符串长度的值 
			sum+=combine(i,26);
		}
		printf("该字符串的编码为：%d\n",sum+count(str,0)+1);
	}
}
