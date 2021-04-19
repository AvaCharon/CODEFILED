#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int n, m;
int edge[N][N]; //数组(n^2)超内存时换为结构体(m)
int dis[N];
bool vis[N];
int ans;

priority_queue<int> pq[N];

//prim
void prim(int i)
{
    dis[i] = 0;
    vis[i] = true;
    int cnt = 1;
    int next = i;
    while (cnt != n)
    {
        int now = next;
        int minn = 0x3f3f3f;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] > edge[now][j])
            {
                dis[j] = edge[now][j];
            }
            if (!vis[j] && minn > dis[j])
            {
                minn = dis[j];
                next = j;
            }
        }
        if (minn == 0x3f3f3f)
        {
            cout << "orz";
            return;
        }
        vis[next] = true;
        ans += dis[next];
        cnt++;
    }
    return;
}

//kruskal
int fa[N]; //并查集
int find(int x)//合并路径优化
{
    while (x != fa[x])
        x = fa[x] = fa[fa[x]];
    return x;
}
void kruskal(int i)
{
    sort(edge, edge + edge.size());
    
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 0x3f3f3f;
        for (int j = 1; j <= n; j++)
            edge[i][j] = 0x3f3f3f;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = edge[b][a] = min(edge[b][a], c);
    }
    prim(1);
    cout << ans;
    return 0;
}