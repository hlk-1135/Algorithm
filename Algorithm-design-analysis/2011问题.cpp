#include<stdio.h>
int main()
{
    int count=1;
    int j=1;
    while(j%2011!=0)
    {
        j=(j%2011)*10+1;
        count++;
    }
    printf("%d",count);
}