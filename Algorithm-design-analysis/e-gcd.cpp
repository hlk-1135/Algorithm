#include<stdio.h>
int e_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int ans=e_gcd(b,a%b,x,y);
    int temp=x;
    x=y;
    y=temp-a/b*y;
    return ans;
}
int main()
{
    int a,b,x,y;
    scanf("%d%d",&a,&b);
    int c=e_gcd(a,b,x,y);
    printf("%d*%d+%d*%d=%d\n",a,x,b,y,c);
    return 0;
}
