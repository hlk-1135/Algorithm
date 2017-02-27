#include <stdio.h>
#include <string.h>
#define Max 1001
int main()
{
    char str1[Max],str2[Max];
    char str[Max]={0};
    int flag=0;
    int i,j,k,m,n,len;
    printf("请输入第一个数字:\n");
    scanf("%s",str1);
    printf("请输入第二个数字:\n");
    scanf("%s",str2);
    m=strlen(str1);
    n=strlen(str2);
    len=(m>n)?m:n;
    for(i=m-1,j=n-1,k=len-1;i>=0 && j>=0;i--,j--,k--) 
    {//将等长度的部分相加,剩下的部分单独处理 
        str[k]=((str1[i]-'0')+(str2[j]-'0')+flag)%10+'0';
        flag=((str1[i]-'0')+(str2[j]-'0')+flag)/10;
    }
    while(i>=0)
    {//如果str1的长度比str2的长度长,处理str1剩下的长度
        str[k]=((str1[i]-'0')+flag)%10+'0';
        flag=((str1[i]-'0')+flag)/10;
        i--;
        k--;
    }
    while(j>=0)
    {//如果str2的长度比str1的长度长,处理str2剩下的长度
        str[k]=((str2[j]-'0')+flag)%10+'0';
        flag=((str2[j]-'0')+flag)/10;
        j--;
        k--;
    }
    if(flag!=0)
    {//最高位进位值不为0时,长度加1 
        for(k=len;k>0;k--)
            str[k]=str[k-1];
        str[0]=flag+'0';
    }
    printf("%s\n",str);
}
