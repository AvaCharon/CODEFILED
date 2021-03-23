
/*
#include<bits/stdc++.h>
using namespace std;
#define maxn 1200
int f[maxn][maxn];
int a[maxn];
int n;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(f,0,sizeof(0));
    for(int i=1;i<=n;i++)
    {
        f[i][i]=a[i];
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=1;i<=n-len;i++)
        {
            int j=i+len-1;
            f[i][j]=2145483647;
            for(int k=i;k<j;k++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            }
        }
    }
    cout<<f[1][n]<<endl;
    return 0;
}
*/

/*
//区间dp
//f[i][j]=(f[i][j],f[i][k]+f[k+1][j])
#include <bits/stdc++.h>
using namespace std;
int n;
int f1[105][105]; //从j堆到i堆的最小得分
int f2[105][105]; //从j堆到i堆的最大得分
int a[105];
int sum[105];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for (int i = 1; i < n; i++)
    {
        f1[i][i] = f2[i][i] = 0;
        f1[n][n] = f2[n][n] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i < n; i++)
        {
            int j = i + len - 1;
            if (j > n)
                continue;
            f2[i][j] = 999999;
            for (int k = i ; k < j; k++)
            {
                f1[i][j] = max(f1[i][j], f1[i][k] + f1[k+1][j]+sum[j]-sum[i-1]);
                f2[i][j] = min(f2[i][j], f2[i][k] + f2[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    cout << f2[1][n] << endl
         << f1[1][n] << endl;
    return 0;
}
*/

//区间dp 考虑环形 第i次分数=得到前两堆的分数+本次相加时的分数
#include <bits/stdc++.h>
using namespace std;
int f1[210][210];
int f2[210][210];
int sum[210], a[210];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        sum[i] = sum[i - 1] + a[i];
        f1[i][i] = f2[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            int j = i + len - 1;
            if (j > 2 * n - 1)
                continue;
            f2[i][j] = 99999;
            for (int k = i; k < j; k++)
            {
                f1[i][j] = max(f1[i][j], f1[i][k] + f1[k + 1][j] + sum[j] - sum[i - 1]);
                f2[i][j] = min(f2[i][j], f2[i][k] + f2[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    int maxn=0,minn=999999;
    for(int i=1;i<=n;i++)
    {
        maxn=max(maxn,f1[i][i+n-1]);
        minn=min(minn,f2[i][i+n-1]);
    }
    cout << minn << endl
         << maxn << endl;
    return 0;
}
