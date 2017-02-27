#include<stdio.h>
int main()
{
    int sum1,sum2;
    int sum3[100],sum4[100],sum5[100];
    int i=0;
    int j=0;
    int arr1[]={1,2,5,6,8,9,0};
    int arr2[]={1,2,5,9,8,6,0};
    for(int a=0;a<=5;a++){
        for(int b=0;b<=6;b++){
            for(int c=0;c<=6;c++){
                for(int d=0;d<=5;d++){
                    sum1=1000*arr1[a]+100*arr1[b]+10*arr1[c]+arr1[d];
                    sum2=1000*arr2[d]+100*arr2[c]+10*arr2[b]+arr2[a];
                    if(sum1-sum2>200 && sum1-sum2<300)
                    {
                        sum3[i]=sum1-sum2;//赔的钱数
                        sum5[i]=sum1;//赔的钱数的正确价格
                        i++;
                    }
                    if(sum2-sum1>800 && sum2-sum1<900)
                    {
                        sum4[j]=sum2-sum1;//赚的钱数
                        j++;
                    }
                }
            }
        }
    }
    for(int m=0;m<i;m++){
        for(int n=0;n<j;n++){
            if(sum4[n]-sum3[m]==558)
                printf("%d\n",sum5[m]);
        }
    }
    return 0;
}
