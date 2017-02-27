#include<stdio.h>
#include<string.h> 
int main()
{
	char a[100];
	int i,j,k,n;
	while(scanf("%s%d",a,&n)!=EOF) {
		int len=strlen(a);
		for(i=1;i<=n;i++) {  //删除n个数字，循环n次 
			for(j=1;j<=len-i;j++) { //每次从头开始找降点 
				if(a[j]<a[j-1]) {
					for(k=j;k<=len-i;k++) { //找到降序点，覆盖删除 
						a[k-1]=a[k];
					}
					break;
				}
			}
		}
		//len长度的数字，删除n个，最后输出len-n个数字 
		for(i=0;i<(len-n);i++)
			printf("%c",a[i]);
		printf("\n"); 
	}
	return 0;
} 
