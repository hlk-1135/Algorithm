/*
row代表行数，即台阶级数，step代表迈的步数。 
*/
#include<stdio.h>
#define n 39
int count=0;

void traceback(int row,int step)
{
	if(row>n)  //走的台阶级数大于n，终止 
		return ;
	if(row==n && step%2==0) { //走完n级并且步数为偶数则满足条件 
		count++;
		return ;
	}
	for(int i=1;i<=2;i++) {  //利用循环模拟每次迈一级台阶还是两级台阶 
		traceback(row+i,step+1);
	}
}

int main()
{
	traceback(0,0);
	printf("%d\n",count);
	return 0;
}