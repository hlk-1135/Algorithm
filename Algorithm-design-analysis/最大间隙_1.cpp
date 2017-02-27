#include<stdio.h>
#include<malloc.h>
double max_gap(double a[],int n)
{
	double max=a[0];
	double min=a[0];
	for(int i=0;i<n;i++) {   //找出最大和最小两个元素 
		if(min>a[i])
			min=a[i];
		if(max<a[i])
			max=a[i];
	}
	double *low=new double[n-1];
	double *high=new double[n-1];
	int *count=new int[n-1];
	for(int i=0;i<n;i++) {
		count[i]=0;
		low[i]=max;
		high[i]=min;
	}
	for(int i=0;i<n;i++) {    //将数字分到桶中 
		int index=(int)((a[i]-min)/(max-min)*(n-1));
		if(high[index]<a[i])
			high[index]=a[i];
		if(low[index]>a[i])
			low[index]=a[i];
		count[index]++;
	}
    double max_gap=0;  
    double left=high[0];
    for(int i=1;i<n-1;i++) {    //找出最大差值 
        if(count[i]) {  
            double gap=low[i]-left;  
            if(gap>max_gap)  
                max_gap=gap;  
            left=high[i];  
        }  
    }
    printf("相邻两个数之间的最大差值为：%lf\n",max_gap);
}

int main()
{
	int i,n;
	scanf("%d",&n);
	double *a=(double *)malloc(n*sizeof(double));
	for(i=0;i<n;i++) {
		scanf("%lf",&a[i]);
	}
	max_gap(a,n);
} 
