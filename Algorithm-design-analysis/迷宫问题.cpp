#include<stdio.h>
#define m 5
#define n 5
int dic[5][2]={0,0,-1,0,1,0,0,-1,0,1};//利用数组来更改4个方向 
int olddic=0,change=0;
int x0,x1,y0,y1;//起点和终点的坐标 
int max;  //最大变换次数
int flag=0;
char p[m][n]={
    '.','.','.','*','*',
    '*','.','*','*','.',
    '.','.','.','.','.',
    '.','.','.','.','.',
    '*','.','.','.','.'
};

int set(int x,int y) 
{//边界和障碍 
	if(x<0 || y<0 || x>=m || y>=n || p[x][y]=='*')
		return false;
	return true;
}

void traceback(int x,int y)
{
	int i,temp;
	if(flag)
		return ;
	if(change>max+1)
		return ;
	if(x==x1 && y==y1) { //到达终点 
		flag=1;
		return ;
	}
	for(i=1;i<=4;i++) { //for循环控制4个方向 
		x+=dic[i][0];
		y+=dic[i][1];
		temp=olddic; //记录一下原来的方向（方便还原方向） 
		//写程序时遇到的bug点 
		if(set(x,y)) {  //判断位置是否合理 
			if(i!=olddic) //和当前方向不同  
				change++;
			olddic=i;//更新方向 
			traceback(x,y);
			olddic=temp; 
			if(i!=olddic)
				change--;
		}		
		x-=dic[i][0];
		y-=dic[i][1];	
	}
}
int main()
{
	printf("输入最大变换次数和起点终点的坐标:\n");
	scanf("%d%d%d%d%d",&max,&x0,&y0,&x1,&y1); 
	traceback(x0,y0);
	if(flag==0)
		printf("No!\n");
	else
		printf("Yes!\n");
	return 0;
} 
