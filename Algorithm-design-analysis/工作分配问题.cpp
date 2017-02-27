//row代表人，给第i个工人安排第j个工作 
#include<stdio.h>
int a[100][100]={0};
int b[100]={0};
int n;
int sum=0;
int min=100000;
void traceback(int row)
{
	int i,j;
	if(sum>=min)  //只要sum>=min，直接中断，进行剪枝 
		return ;
	if(row==n) { 
		min=sum;
		return ;
	}
	for(j=0;j<n;j++) {
		if(b[j]==0) {  //利用一维数组来标记第j个工作是否被分配
			b[j]=1;
			sum+=a[row][j];
			traceback(row+1);
			b[j]=0;
			sum-=a[row][j];
		}
	}
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	traceback(0);
	printf("%d\n",min);
	return 0;
}