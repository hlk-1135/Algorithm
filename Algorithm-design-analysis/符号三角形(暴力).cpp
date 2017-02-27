/*
二进制将第一行确定，再由a[i][j]=a[i-1][j]^a[i-1][j+1]依次确定每一行
无需单独统计0和1，sum一个值即可确定 
*/
#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,n,num,temp,max;
	int a[100][100]={0};
	int sum=0,count=0;
	scanf("%d",&n);
	max=n*(n+1)/2;
	if(max%2!=0) {
		printf("error!\n");
		return 0;
	}
	for(num=0;num<=pow(2,n);num++) {
		temp=num;
		sum=0;
		for(i=0;i<n;i++) { //先将第一行确定 
			a[0][i]=temp%2;
			temp/=2;
			sum+=a[0][i];
		}
		for(i=1;i<n;i++) {  //依次确定下面的每一行的第j列数字 
			for(j=0;j<n-i;j++) {
				a[i][j]=a[i-1][j]^a[i-1][j+1];
				sum+=a[i][j];
			}
			if(sum>max/2) { //如果大于一半，则不需要继续往下走 
				break;
			}
		}
		if(sum==max/2) {
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}