/*
循环一遍，尽可能安排最多活动，只要时间不冲突，就在同一个会场
接下来再循环一遍，安排剩下的活动，又是一个会场 
....
直到所有活动都被安排
*/ 
#include<stdio.h>
struct node {
	int begin;
	int end;
	int flag;//标记该活动是否被安排，0表示未安排，1表示已安排 
};
int main()
{
	int i,j,n;
	node temp,t[100];
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d%d",&t[i].begin,&t[i].end);
		t[i].flag=0;
	}
	for(i=0;i<n-1;i++) {  //按照每个活动的结束时间进行升序排序 
		for(j=0;j<n-i-1;j++) {
			if(t[j].end>t[j+1].end) {
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
		}
	}
	int sum=0;//总共需要的会场数量 
	int count=0;//当前已经安排了的活动数量 
	while(n-count>0) {
		int cur=0;//当前时间 
		for(i=0;i<n;i++) { //将每一个活动的时间与当前时间进行比较 
			if(t[i].begin>cur && t[i].flag==0) { 
				t[i].flag=1;
				cur=t[i].end;
				count++;	
			} 
		}
		sum++;
	}
	printf("%d\n",sum);
	return 0;
}