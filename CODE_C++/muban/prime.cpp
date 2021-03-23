//线性筛素数
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    int ask[q];//所求素数标号
    for(int i=0;i<q;i++)
    {
        scanf("%d",&ask[i]);
    }
    int primes[n], cnt = 0; // 所有素数
    bool st[n];             // x是否被筛掉
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