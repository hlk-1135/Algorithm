/*
1.对数组升序和降序 
2.对数据处理不采用覆盖，利用动态更改数组数据
for(m=0;m<n-1;m++)
	a[m+1]+=a[m];
例如：5  12  6  2
第一次排序：2,5,6,12； 2+5=7，  变为2,7,6,12    min=6
第二次排序：2,6,7,12;  6+7=13,  变为2,6,13,12   min=6+12=18
第三次排序：2,6,12,13, 12+13=25,变为2,6,12,25   min=18+24=42 
*/ 
#include<stdio.h>
#include<algorithm>
using namespace std;
int m;
int a[100]={0},b[100]={0};

int cmp(int a,int b)
{//降序 
	return a>b;
}
void min(int *a,int n)
{//最优情况 
	int min=0;
	for(m=0;m<n-1;m++) { //n个数，需要排序n-1次 
		sort(a+m,a+n);//升序 
		a[m+1]+=a[m];//更改数据 
		min+=a[m+1]-1;	
	}
	printf("min=%d\n",min);
}
void max(int *b,int n)
{//最差情况 
	int max=0;
	for(m=0;m<n-1;m++) {
		sort(b+m,b+n,cmp);//降序 
		b[m+1]+=b[m];
		max+=b[m+1]-1;	
	}
	printf("max=%d\n",max);
}
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	min(a,n);
	max(b,n);
	return 0;
}