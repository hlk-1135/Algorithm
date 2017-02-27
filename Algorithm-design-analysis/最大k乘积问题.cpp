/*构造出矩阵表，行从1--len，列从1--k 
1)  m(i,j)=w(1,i)；（当j=1时） 
2)  m(i,j)=max{m(k,j-1)*w(k+1,i),m(i,j)};  (2<j<=i)
    其中1<=k<i (即k从1开始一直到i-1中找最大值)
*/ 
#include<stdio.h>
#include<math.h>
#define N 100 
int max[N][N]={{0,0}};  //max[i][j]是前i位(1--i)分成j段所得的最大乘积
int w[N][N]={{0,0}}; // w[i][j]从第i位到第j位所组成的十进制数
int a[N]={0};
int main()
{
	int i,j,m,n,k,len;
	scanf("%d%d",&len,&m);
	scanf("%d",&n);
	for(i=len;i>0;i--) {
		a[i]=n%10;
		n/=10; 
	}
	for(i=1;i<=len;i++) { //先求出从第i位到第j位组成的十进制数
		w[i][i]=a[i];
		for(j=i+1;j<=len;j++) 
			w[i][j]=w[i][j-1]*10+a[j];
	}
	for(i=1;i<=len;i++) {  //分成1段，先将第一列构造出 
		max[i][1]=w[1][i];
	}
	for(i=2;i<=len;i++) { //从第二行开始，构造该行所在的每一个列元素 
		for(j=2;j<=i;j++) {  //前i个数字，最多分为2--i段 
			for(k=1;k<i;k++) {
				if(max[k][j-1]*w[k+1][i]>max[i][j])
					max[i][j]=max[k][j-1]*w[k+1][i];
			}
		}
	}
	for(i=1;i<=len;i++) {
		for(j=1;j<=m;j++) {
			printf("%7d",max[i][j]);
		}
		printf("\n");
	} 
	printf("%d\n",max[len][m]);
	return 0;
}
