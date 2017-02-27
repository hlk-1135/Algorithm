#include<stdio.h>
int main()
{
    int arr[10];
    int j,n;
    scanf("%d",&n);
    for(int i=0;i<=9;i++)
    {
        arr[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        j=i;
        while(j)
        {
            arr[j%10]++;
            j/=10;
        }
    }
    for(int i=0;i<=9;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}
