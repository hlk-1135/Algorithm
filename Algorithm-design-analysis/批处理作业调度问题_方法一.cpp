/*
该方法未使用全排列，还是用的我解回溯题目的通用解题思路 
虽然目前很多题用全排列都写过，但是总感觉对于全排列，并没有彻彻底底掌握
其精髓。 
*/
#include<stdio.h>
#define N 100
int n;
int a[N]={0},b[N]={0};
int c[N]={0},bestc[N]={0};
int flag[N]={0};//用一个数组标记已经使用过的数字，1表示已经使用，0表示未使用 
int f1=0,f2=0,count=0;//f2使用变量，而非数组 
int best=1000000;

void traceback(int num)
{
	int i;
	if(num>n) {
		if(count<best) {
			best=count;
			for(i=1;i<=n;i++)
				bestc[i]=c[i];
		}
		return ;
	}
	//与全排列不同的地方 
	for(i=1;i<=n;i++) { //一共有1--n种作业可供选择 
		if(flag[i]==0 && count<best) {
			flag[i]=1;
			f1+=a[i];
			/*全排列时用的一维数组f2[]，回溯时无需还原，现在使用普通的变量f2，要进行记录，
			类似迷宫问题的olddirection*/
			int old=f2;
			f2=(f2>f1 ? f2 : f1) + b[i];
			c[num]=i;
			count+=f2;
			traceback(num+1);
			count-=f2;
			//c[num]=i;无需还原 
			f2=old;
			f1-=a[i];
			flag[i]=0;
		}
	}
}

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d%d",&a[i],&b[i]);
	}
	traceback(1);
	printf("%d\n",best);
	for(i=1;i<=n;i++) {
		printf("%d ",bestc[i]);
	}
	printf("\n");
	return 0;
} 
