#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 100
char a[N],b[N];
int temp[N][N];
int main()
{
	int i,j,len_a,len_b;
	scanf("%s",a);
	scanf("%s",b);
	len_a=strlen(a);
	len_b=strlen(b);
	for(i=1;i<=len_a;i++) {
		for(j=1;j<=len_b;j++) {
			if(a[i-1]==b[j-1])
				temp[i][j]=temp[i-1][j-1]+1;	
			else
				temp[i][j]=temp[i-1][j]>temp[i][j-1]?temp[i-1][j]:temp[i][j-1];			
		}
	}
	printf("%d\n",temp[len_a][len_b]);
	return 0;
}