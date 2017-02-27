//整体思想：先行再列
#include<stdio.h>
int m,n;
int count=0;
int a[100][100]; 

bool set(int row,int col)
{//检查第row行第col列上的该数字与该列上的数字是否冲突 
	int i;
	for(i=0;i<row;i++) {
		if(a[i][col]==a[row][col])
			return false; 
	}
	return true;
}

void traceback(int row,int col)
{
	int i,j,k,temp;
	for(i=col;i<n;i++) {   //处理列(在该行上进行全排列)
		temp=a[row][col];
		a[row][col]=a[row][i];
		a[row][i]=temp;
		if(set(row,col)) {
			//先判断行再判断列是4种可能，先列后行是3种 
			if(col==n-1) { //列处理完
				if(row==m-1) { //行处理完 
					count++;
					return ;
				} 
				else {
					traceback(row+1,0); //继续处理下一行 
				}
			}
			else {
				traceback(row,col+1); //继续处理下一列 
			}	
		} 
		temp=a[row][col];
		a[row][col]=a[row][i];
		a[row][i]=temp;
	}
}

int main()
{
	int i,j;
	scanf("%d%d",&m,&n);
	//矩阵初始化 
	for(i=0;i<m;i++) {
		for(j=0;j<n;j++){
			a[i][j]=j+1;
		}
	}	 
	traceback(0,0);
	printf("%d\n",count);
	return 0;
}