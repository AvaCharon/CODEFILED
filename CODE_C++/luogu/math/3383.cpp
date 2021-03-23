#include <bits/stdc++.h>
using namespace std;

/*
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    int f[n];
    memset(f,1,sizeof(f));
    for(int i=2,j=0;i<=n&&j<q;i++)
    {
        if(f[i])
        {
            if(j++<=q)printf("%d\n",i);
            int t=n/i;
            for(int k=i*i;k<=t;k*i)
            {
                f[k]=0;
            }
        }
    }
    return 0;
}*/

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int ask[q];
    for(int i=0;i<q;i++)
    {
        scanf("%d",&ask[i]);
    }
    int primes[n], cnt = 0; // primes[]存储所有素数
    bool st[n];             // st[x]存储x是否被筛掉
    memset(primes, 0, sizeof(primes));
    memset(st, false, sizeof(st));
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    for(int i=0;i<q;i++)
    {
        printf("%d\n",primes[ask[i]-1]);
    }
    return 0;
}

