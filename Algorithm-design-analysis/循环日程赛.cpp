#include<stdio.h>
#define max 1000
int a[max][max];
void show_table(int sum) {
	printf("输出比赛日程:\n"); 
	for(int i=1;i<=sum;i++) {
		for(int j=1;j<=sum;j++) {
			printf("%3d",a[i][j]);
		}
		putchar('\n');
	}
}
void input_table(int k)
{
	int i,j;
	int n=1;
	for(i=1;i<=k;i++)
		n*=2;
	int sum=n;//将人数记录下来 
	for(int i=1;i<=n;i++)
		a[1][i]=i;    //设置日程表第一行
	int m=1;  //每次填充时的起始位置 
	for(int s=1;s<=k;s++) {  //总体分为k部分 
		n/=2;   //每一部分又分为n小块 
		for(int t=1;t<=n;t++) {  
			for(int i=m+1;i<=2*m;i++) {       //控制行 
				for(int j=m+1;j<=2*m;j++) {  //控制列 
					a[i][j+(t-1)*m*2]=a[i-m][j+(t-1)*m*2-m];//右下角等于左上角的值  
                    a[i][j+(t-1)*m*2-m]=a[i-m][j+(t-1)*m*2];//左下角等于右上角的值  
				}
			}
		}
		m*=2;
	}
	show_table(sum);
}
int main()
{
	int k;
	printf("请输入k的值:\n");
	scanf("%d",&k);
	input_table(k);
	return 0;
} 
