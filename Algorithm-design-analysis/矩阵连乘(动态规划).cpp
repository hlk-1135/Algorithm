#include<stdio.h>
#include<string.h>
#define Num 101

int n;
int s[Num][Num],m[Num][Num],p[Num];

void traceback(int i,int j) 
{
	if(i==j)
		return;
	traceback(i,s[i][j]);     
	traceback(s[i][j]+1,j);
	printf("%d-%d，%d-%d\n",i,s[i][j],s[i][j]+1,j);
}

void set()
{
	int i,j,k,r,t;
	for(i=1;i<=n;i++) {
		m[i][i]=0;
	}
	for(r=2;r<=n;r++) {
		for(i=1;i<=n-r+1;i++) {
			j=r+i-1;
			m[i][j]=99999;
			s[i][j]=i; 
			for(k=i;k<j;k++){
            	t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(t<m[i][j]) {
                    m[i][j]=t;
                    s[i][j]=k;//记录加括号的位置 
                }
            }
		}
	}
}

int main()
{
	scanf("%d",&n); 
	for(int i=0;i<=n;i++) {
		scanf("%d",&p[i]);
	}
	set();
	printf("%d\n",m[1][n]);
	traceback(1,n);
	return 0;
}