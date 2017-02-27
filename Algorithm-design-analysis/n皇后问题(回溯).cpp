#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define n 8

int row=0;
int a[10]={0};
int count=0;

int peace(int i)
{
	int j;
	for(j=0;j<i;j++) { //判断与前面的皇后是否冲突 
		if(a[i]==a[j] || abs(i-j)==abs(a[i]-a[j]))
			return 0;
	}
	return 1;
}

void traceback(int row)
{
	int i,j;
	if(row==n) {
		for(i=0;i<n;i++)
			printf("%2d",a[i]);
		printf("\n");
		count++;
	}
	for(j=0;j<n;j++) {
		a[row]=j; //为第row行上的皇后选择列 
		if(peace(row))
			traceback(row+1); 
	}
}

int main()
{
	int i;
	traceback(row);
	printf("%d\n",count);
	return 0;
}