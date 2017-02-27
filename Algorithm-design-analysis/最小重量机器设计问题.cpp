/*
该题traceback(num)中num代表的是第几个部件 
*/ 
#include<stdio.h>
int n,m,d; 
int value[100][100],weight[100][100];
int best[100]={0};//最佳选择方案
int min=1000000;//最小重量 
int b[100]={0};//当前的选择方案 
int cur_weight=0;//当前总重量 
int cur_value=0;//当前总价值 
void traceback(int num)
{
	int i;
	if(num==n) { 
		if(cur_weight<min) {
			min=cur_weight; //更新最小重量 
			for(i=0;i<n;i++)
				best[i]=b[i]+1;//更新最佳选择方案，数组从0开始，输出要加1	
		}
		return ;
	}
	for(i=0;i<m;i++) {
		b[num]=i;
		cur_weight+=weight[num][i];
		cur_value+=value[num][i];
		if(cur_weight<min && cur_value<=d) //等号必须加 
			traceback(num+1);
		cur_weight-=weight[num][i];
		cur_value-=value[num][i];
		b[num]=0;
	}
}

int main()
{
	int i,j;
	scanf("%d%d%d",&n,&m,&d);
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d",&value[i][j]);
		}
	}
	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			scanf("%d",&weight[i][j]);
		}
	}
	traceback(0);
	printf("the min weight is %d\n",min);
	for(i=0;i<n;i++) {
		printf("%d ",best[i]);
	}
	printf("\n");
	return 0;
} 