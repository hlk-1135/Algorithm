#include<stdio.h>
int a[100];
int count=0;
int set(int num)
{
    if(num==1 || num==2)
        return 1;
    for(int i=3;i<=num;i++)
        if(num%i==0)
            count+=set(num/i);
    return count;
}

int main()
{
    int num;
    printf("输入正整数:\n");
    scanf("%d",&num); 
    count=set(num);
    printf("一共有%d种分解方式\n",count);
    return 0;
} 
