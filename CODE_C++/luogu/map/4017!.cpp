#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int n;
long m;
int coun;
int putout[N];
bool vis[N];
bool mapp[N][N];
int indergeree[N];

void topsort()
{
    int cnt = 0;
    while (cnt != n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!indergeree[i] && !vis[i])
            {
                putout[cnt]=i;
                cnt++;
                vis[i] = true;
                for (int j = 1; j <= n; j++)
                    if (mapp[i][j])
                        indergeree[j]--;
            }
        }
        coun++;
        if(coun==n||cnt==n)
        {
            cout<<cnt%80112002;
            return;
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        mapp[a][b] = true;
        indergeree[b]++;
    }
    topsort();
    return 0;
}