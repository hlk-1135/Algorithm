#include<stdio.h>
#define m 5   //m个顶点
#define n 4   //n种颜色
int a[5][5]={
0,1,1,1,0,
1,0,1,1,1,
1,1,0,1,0,
1,1,1,0,1,
0,1,0,1,0};

int color[m]={0};//存储m个顶点的着色选择，可以选择的颜色为1到n
int count=0;

bool ok(int num) 
{
	int i; 
	for(i=0;i<num;i++)  { //前num个与第num相邻的点中，不能有冲突的颜色 
		if(a[num][i]==1 && color[i]==color[num]) {
			return false;
		}			 
	}
	return true;
}

void traceback(int num)
{
	int i;
	if(num==m) {
		count++;
		for(i=0;i<m;i++)
			printf("%d ",color[i]);
		printf("\n");
		return;
	}
	for(i=1;i<=n;i++) {
		color[num]=i;
		if(ok(num))
			traceback(num+1);
		//color[num]=0   每次只查找前num个顶点中是否有冲突颜色，所以无需再赋为0			
	}
}

int main()
{
	int i,j;
	traceback(0);
	printf("%d\n",count);
	return 0;
}