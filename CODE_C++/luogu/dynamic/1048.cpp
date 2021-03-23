/*
#include<bits/stdc++.h>
using namespace std;
#define maxn 1200
int n,m;
int w[maxn],v[maxn];
int f[maxn][maxn];

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=0;i<=n;i++)
    {
        f[i][0]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=w[i];j<=m;j++)
        {
            f[i][j]=max(f[i-1][j],f[i-1][j-w[i]])+v[i];
            ans=max(ans,f[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/

/*
//f[i][j]=max(f[i-t[i]][j]+v[i],f[i][j-1])
#include<bits/stdc++.h>
using namespace std;
int t[110],v[110];//药品时间与价值
int f[1100][110];//拥有时间为i时采了前j个药物的最大价值
int T,m;

int main()
{
    cin>>T>>m;
    for(int j=1;j<=m;j++)
    {
        cin>>t[j]>>v[j];
    }
    for(int j=0;j<=m;j++)
    {
        for(int i=T;i>=0;i--)
        {
            if(i>=t[j])
            {
                f[i][j]=max(f[i][j-1],f[i-t[j]][j-1]+v[j]);
            }
            else
            {
                f[i][j]=f[i][j-1];
            }
        }
    }
    cout<<f[T][m]<<endl;
    return 0;
}

*/

//二维
#include <bits/stdc++.h>
using namespace std;
int f[105][1010];
int v[105], t[1010];
int n, m;

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j < t[i])
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = max(f[i - 1][j], f[i - 1][j - t[i]] + v[i]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}