/*
每次从中间往两边找相同的，统计个数。然后比较大小，更新 
*/ 
#include<stdio.h>
#include<algorithm>
#define N 100
using namespace std;
int a[N];
int temp=0,maxcount=0;

bool cmp(int m,int n)
{//sort函数的升序排序 
	return m<n;
}

void set(int left,int right)
{
	int i,j;
	int count=1;
	int mid=(left+right)/2; 
	for(i=mid-1;i>=left;i--) { //从中间往左边找相同的 
		if(a[i]==a[mid])
			count++;
		else
			break; 
	}
	for(j=mid+1;j<=right;j++) {//从中间往右边找相同的 
		if(a[j]==a[mid])
			count++;
		else
			break;
	}
	if(count>maxcount)
	{
		maxcount=count;
		temp=a[mid];//记录众数 
	}
	if(i-left>=maxcount)  //只有当左边数字的个数>=重数，左半部分才有可能存在 
		set(left,i);
	if(right-j>=maxcount)//只有当右边数字的个数>=重数，右半部分才有可能存在
		set(j,right);
}

int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	sort(a,a+n,cmp);
	for(i=0;i<n;i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
	set(0,n-1);
	printf("众数为：%d,重数为：%d",temp,maxcount);
}
/*
10
3 6 89 3 4 5 3 1 6 3
*/