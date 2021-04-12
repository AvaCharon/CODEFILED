#include <bits/stdc++.h>
using namespace std;

int n, m;
bool f[10005][10005];
bool vis[10005];
int ans[10005];
int cnt = 0;

void dfs(int k)
{
    vis[k] = 1;
    ans[cnt++] = k;
    for (int i = 1; i <= n; i++)
        if (!vis[i] && f[k][i])
            dfs(i);
    return;
}

void bfs(int k)
{
    vis[k] = 1;
    queue<int> q;
    q.push(k);
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            ans[cnt++] = q.front();
            for (int j = 1; j <= n; j++)
                if (!vis[j] && f[q.front()][j])
                {
                    vis[j] = 1;
                    q.push(j);
                }
            q.pop();
        }
    }
    return;
}

void putout(void)
{
    for (int i = 0; i < n; i++)
        cout << ans[i];
    cout << endl;
    return;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int p, q;
        cin >> p >> q;
        f[p][q] = 1;
    }
    dfs(1);
    putout();
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    bfs(1);
    putout();
    return 0;
}