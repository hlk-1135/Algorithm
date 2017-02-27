#include<stdio.h>
int main()
{
	int i,j;
	int n;
	scanf("%d",&n);
	int a[200];
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++) {
			if(a[j]>a[j+1]) {
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++) {
		if(i=0)
			printf("%d",a[i]);
		printf(" %d",a[i]);
	}
	printf("\n");
	return 0;
}