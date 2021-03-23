#include <bits/stdc++.h>
using namespace std;

/*
const int N=2005;

int vis[N];
int dis[N];
int mapp[N][N];
int n,m;
int ans[N];


void dijkstra(int s)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=mapp[s][i];
    }
    dis[s]=0;
    vis[s]=1;
    for(int i=1;i<n;i++)
    {
        int k;
        int minn=0x3f3f3f;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&(dis[j]<minn))
            {
                minn=dis[j];
                k=j;
            }
        }
        if(minn==0x3f3f3f)
            return;
        vis[k]=1;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&(dis[j]>(dis[k]+mapp[k][j])))
                dis[j]=dis[k]+mapp[k][j];
        }
    }
    return;
}


int main()
{
    cin>>n>>m;
    memset(mapp,0x3f3f3f,sizeof(mapp));
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        mapp[a][b]=mapp[b][a]=c;
    }
    dijkstra(1);
    for(int i=1;i<=n;i++)
    {
        ans[i]=dis[i];
    }
    memset(vis,0,sizeof(vis));
    dijkstra(n);
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]+dis[i];
        if(i!=n)cout<<" ";
    }
    return 0;
}

*/

//堆优化
const int Ni = 10000;
const int INF = 1 << 27;
struct node
{
    int x, d;
    node() {}
    node(int a, int b)
    {
        x = a;
        d = b;
    }
    bool operator<(const node &a) const
    {
        if (d == a.d)
            return x < a.x;
        else
            return d > a.d;
    }
};
vector<node> eg[Ni];
int dis[Ni], n;
void Dijkstra(int s)
{
    int i;
    for (i = 0; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0;
    //用优先队列优化
    priority_queue<node> q;
    q.push(node(s, dis[s]));
    while (!q.empty())
    {
        node x = q.top();
        q.pop();
        for (i = 0; i < eg[x.x].size(); i++)
        {
            node y = eg[x.x][i];
            if (dis[y.x] > x.d + y.d)
            {
                dis[y.x] = x.d + y.d;
                q.push(node(y.x, dis[y.x]));
            }
        }
    }
}
int main()
{
    int a, b, d, m;
    while (scanf("%d%d", &n, &m), n + m)
    {
        for (int i = 0; i <= n; i++)
            eg[i].clear();
        while (m--)
        {
            scanf("%d%d%d", &a, &b, &d);
            eg[a].push_back(node(b, d));
            eg[b].push_back(node(a, d));
        }
        Dijkstra(1);
        for (int i = 1; i <= n; i++)
            printf("%d\n", dis[i]);
    }
    return 0;
}
/* 
6 6 
1 2 2 
3 2 4 
1 4 5 
2 5 2 
3 6 3 
5 6 3 
*/
