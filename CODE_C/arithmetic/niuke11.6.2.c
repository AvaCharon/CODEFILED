#include<stdio.h>
#define N 2000010
int main(void)
{
    int n,k,q;
    int ice[N];
    scanf("%d%d%d",&n,&k,&q);
    int yy[q];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ice[i]);
    }
    for(int j=1;j<=q;j++)
    {
        int x,y;
        yy[j]=1;
        scanf("%d%d",&x,&y);
        for(x=x+1;x<=y;x++)
        {
            if(ice[x]!=ice[x-1])yy[j]++;
        }
        if(yy[j]>=k)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}