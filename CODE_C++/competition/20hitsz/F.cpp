#include<bits/stdc++.h>
using namespace std;

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