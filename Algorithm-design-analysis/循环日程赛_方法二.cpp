#include<stdio.h>
#define max 100
#define n 8 
int main()
{
	int i,j,k,p,q,index;
	k=1;              //每次处理的行数 
	index=1;          //处理第几行 
	int direction;   //控制方向 
	int a[max][max];
	for(i=0;i<n;i++) {   //初始化第一行 
		a[0][i]=i+1;
	}
	while(k<n) {
		direction=1;
		i=0; 
		while(i<n) { 
			for(p=index;p<index+k;p++) {  //控制行 
				for(q=i;q<i+k;q++) {   //控制列 
					a[p][q]=a[p-k][q+direction*k];
				}	
			}
			direction*=-1;
			i+=k;
		}
		index+=k;
		k*=2;
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++)
			printf("%3d",a[i][j]);
		putchar('\n');
	}
	return 0;
}
