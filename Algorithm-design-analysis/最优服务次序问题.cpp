#include<stdio.h>
int main()
{
	int n;
	double sum=0;
	scanf("%d",&n);
	double a[n];
	for(int i=0;i<n;i++) {
		scanf("%lf",&a[i]);
	}
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
			{
				double temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
	for(int i=0;i<n;i++)
		printf("%.2lf ",a[i]);
	printf("\n");
	for(int i=1;i<n;i++) {
		a[i]+=a[i-1];
		sum+=a[i];
	}
	printf("%.2f\n",sum/n);
	return 0;
}
