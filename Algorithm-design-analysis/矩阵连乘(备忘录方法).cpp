#include<stdio.h> 
#include<math.h>
#include<string.h>
#define Max 101

int a[Max][Max];
int b[Max][Max];
int c[Max];
int lookupChain(int i, int j);

int memoizedmatrixChain(int n)
{
    for(int i=1;i<=n;i++)
    	for(int j=i;j<=n;j++)
    		a[i][j]=0;
    return lookupChain(1,n);
}

int lookupChain(int i,int j)
{
    if(a[i][j]>0) 
		return a[i][j];
    if(i==j) 
		return 0;
    int m=lookupChain(i+1,j)+c[i-1]*c[i]*c[j];
    b[i][j]=i;
    for(int k=i+1;k<j;k++)
    {
        int temp=lookupChain(i,k)+lookupChain(k+1,j)+c[i-1]*c[k]*c[j];
        if(temp<m)
        {
            m=temp;
            b[i][j]=k;
        }
    }
    a[i][j]=m;
    return m;
}

int main()
{
    int i,n;
    printf("输入矩阵个数：\n");
    scanf("%d",&n);
    printf("输入每个矩阵的维数：\n");
    for(i=0;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    int min=memoizedmatrixChain(n);
    printf("最少乘次数为：%d\n",min);
    return 0;
}