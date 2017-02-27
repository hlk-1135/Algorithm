/*
数字排列、填数字、拉丁矩阵、数独问题。
这种数字模式的题目，就是从头到尾填入范围内的数字，对该位置的数字进行判断是否符合条件。
可以说是 回溯版的暴力。而纯暴力是全部填完数字再进行判断。 
（二维时先行后列进行填入，判断时先判断列元素） 
*/ 
#include<stdio.h>
#define n 14
int a[n]={0};
int set(int num)
{//判断到当前位置是否已经使用过该数字 
	int i;
	for(i=0;i<num;i++) {
		if(a[i]==a[num])
			return false;
	}
	return true;
} 
void traceback(int num)
{
	int i,j;
	if(num==n) {
		for(i=0;i<n;i++) {
			printf("%d",a[i]);
		}
		printf("\n");
		return ;
	}
	if(a[num]==0) {
		for(i=1;i<7;i++) {
			a[num]=i;
			if(a[num+i+1]==0 && set(num)) {//判断是否满足条件 
				a[num+i+1]=i;//同时填入两个相同的数字 
				traceback(num+1);
				a[num+i+1]=0;
			}	
			a[num]=0;
		}
	}
	else
		traceback(num+1);
} 
int main()
{
	a[0]=7,a[1]=4,a[6]=4,a[8]=7;
	traceback(2);
	return 0;
} 