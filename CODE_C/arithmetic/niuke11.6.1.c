#include<stdio.h>
#define N 1000000000
#define T 1000000
int main(void)
{
    int t,ans,n,m;
    scanf("%d",&t);
    int p[T];
    int cup[N];
    for(int k=1;k<=t;k++)
    {
        scanf(" %d%d",&n,&m);
        for(int i=2;i<=n;i++)
        {
            cup[1]=1;
            cup[i]=1;
            for(int j=i-1;j>=1;j--)
            {
                if(i%j==0&&(cup[i]<=cup[j]))cup[i]=cup[j]+1;
                if(cup[i]>m)
                {
                    p[k]=k-1;
                    goto A;
                }
            }
        }
        p[k]=k;
        A:;
    }
    ans=p[1];
    for(int i=2;i<=t;i++)
    {
        ans=ans^p[i];
    }
    printf("%d",ans);
    return 0;
}