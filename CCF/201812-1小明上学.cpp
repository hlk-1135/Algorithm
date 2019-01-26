#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int r,y,g,n;
	int i,k,t,total;
	while(~scanf("%d%d%d",&r,&y,&g)) {
		total=0;
		scanf("%d",&n);
		for(i=0;i<n;i++) {
			scanf("%d%d",&k,&t);
			if(k == 0 || k == 1)
				total+=t;
			else if(k==2)
				total+=(t+r); 
		}
		printf("%d\n",total); 
		return 0;
	}
}
