#include<stdio.h>
int set(int n)
{//求n的阶乘 
    int sum=1;
    for(int i=2;i<=n;i++)
        sum*=i;
    return sum;
}
void reverse(int a[],int min,int n)
{//数组逆置 
	int i,j,temp;
	for(i=min,j=n-1;i<j;i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
void swap(int &a,int &b)
{//交换元素 
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void output(int a[],int n)
{//输出 
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	putchar('\n');
}
int num(int a[],int n)
{//求字典序的值 
    int count=0;
    int b[n];
    for(int i=0;i<n;i++)
    	b[i]=a[i];//保存数组，不修改原来数组的值，便于求下一个字典序 
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
		{
        	if(a[j]>a[i])
        		b[j]--;//对于a[i],检查a[i+1]到a[n-1]的值是否比a[i]大，如果是，则该值减1 
        }
        count+=set(n-i-1)*(b[i]-1);
    }
    return count;
}
void next(int a[],int n)
{//求出下一个字典序 
    int min,max;
    for(int i=n-1;i>=0;i--)
    {//找出升序截止点的数组下标 
    	if(a[i-1]<a[i])
    	{
	        min=i-1;
	        break;
    	}
    }
	for(int i=n-1;i>=0;i--)
	{//找出刚刚比a[min]大的数 
	    if(a[i]>a[min])
	    {
	        max=i;
	        break;
	    }
	}  
    swap(a[min],a[max]);
    reverse(a,min+1,n);//注意交换的是a[min+1]到a[n] 
    output(a,n);
}
int main()
{
    int n;
    printf("元素个数:\n");
    scanf("%d",&n);
    int *a=new int[n];
    printf("请输入当前字符排列：\n");
    for(int i=0;i<n;i++)
    	scanf("%d",&a[i]);
   	getchar();
    int count=num(a,n);
    printf("当前字符串字典序值为：%d\n",count);
    printf("下一字典序排列为：");
    next(a,n);
    return 0;
} 
