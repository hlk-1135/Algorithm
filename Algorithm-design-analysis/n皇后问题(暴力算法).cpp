#include<stdio.h>
#include<math.h> 
#define n 8
int main()
{
	int i,j,num,flag;
	int count=0;
	int a[n]={0};
	for(num=0;num<pow(n,n);num++) {
		int temp=num;
		for(i=0;i<n;i++) {
			a[i]=temp%n;
			temp/=n;
		}
		flag=1;
		for(i=0;i<n;i++) {
			for(j=i+1;j<n;j++) {
				if(a[i]==a[j] || abs(i-j)==abs(a[i]-a[j])) {//同一行或者斜线上 
					flag=0;
					break;
				}
			}
		}
		if(flag==1) { //将满足条件的输出 
			temp=num;
			for(i=0;i<n;i++) {
				a[i]=temp%n;
				temp/=n;
				printf("%d ",a[i]);
			}
			printf("\n"); 
			count++;
		}	 
	}
	printf("%d\n",count);
	return 0;
}
