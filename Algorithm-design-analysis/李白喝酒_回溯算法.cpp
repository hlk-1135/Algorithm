#include<stdio.h>
#define n 15
int count=0;
int drink=2;//初始酒的量 
int flower=0,store=0;
char c[20];
void traceback(int cur)
{
	int i;
	if(flower>10 || store>5)
		return ;
	if(cur==n) {
		//没必要再判断store==5 && flower==10
		if(drink==0 && c[n-1]=='b') {
			count++;
			for(i=0;i<n;i++) {
				printf("%c ",c[i]);
			}
			printf("\n");
		}
		return ;
	}
	//遇到店 
	c[cur]='a';
	store++;
	drink*=2;
	traceback(cur+1);
	store--;
	drink/=2;
	 
	c[cur]='b';
	flower++;
	drink-=1;
	traceback(cur+1);
	flower--;
	drink+=1;
} 
int main()
{
	traceback(0);
	printf("the result is %d\n",count);
	return 0;
}