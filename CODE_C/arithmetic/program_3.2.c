#include<stdio.h>
#include<string.h>
#define m 1010
int main(void)
{
    int n,k;
    int a[m];
    memset(a,0,sizeof(a));
    while (scanf("%d%d",&n,&k)&&k<=n&&n<=1000)
    {
        int i;
        for(i=1;i<=k;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(j%i==0)
                a[j]++;
            }
        }
        if(i>k)break;
    }
    for(int i=0;i<=n;i++)
    {
        if(a[i]%2==1&&i!=0)
        printf("%d ",i);
    }
    return 0;
}