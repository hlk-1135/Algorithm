#include<stdio.h>
int a[101];
void quicksort(int *a,int left,int right)
{
	int index,temp;
	if(left>=right)
		return ;
	
	index=a[left];  //index中存的就是基准数 
	int i=left;
	int j=right;
	while(i!=j)
	{
		while(a[j]>=index && i<j)
			j--;
			a[i]=a[j];
		while(a[i]<=index && i<j)
			i++;
			a[j]=a[i];
	}
	a[i]=index; //将基准数归位 
	quicksort(a,left,i-1);
	quicksort(a,i+1,right);
}
int main()
{
	int i,n;
	printf("请输入排序数字的个数:\n");
	scanf("%d",&n);
	printf("请输入待排序列:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	quicksort(a,0,n-1);
	printf("排序结果为:\n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	getchar();getchar();
	return 0;
}
