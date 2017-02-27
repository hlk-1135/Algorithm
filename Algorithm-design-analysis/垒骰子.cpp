#include<stdio.h>
#include<math.h> 
#define N 100
#define n 2
#define m 1
int a[N][N]={0};
int flag[N][N]={0};
int sum=0;

bool peace(int x,int y)
{
	if(flag[(a[x][y]+3)%6][a[x-1][y]])
		return false;
	else
		return true;
}

void traceback(int x,int y)
{
	int i,j;
	for(i=1;i<=6;i++) {
		a[x][y]=i;
		if(peace(x,y)) {
			if(x==n) {
				sum++;
			}
			else {
				traceback(x+1,y);
			}
		}
		a[x][y]=0;
	}
}

int main()
{
	int i,j;
	flag[1][2]=1;
	flag[2][1]=1;
	traceback(1,1);
	int count=pow(4,n);
	sum*=count;
	printf("%d\n",sum);
	return 0;
} 